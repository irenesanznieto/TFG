#include "algorithm3D.h"

Algorithm3D::Algorithm3D()
{
    //Initialize the matched_object_id to -1 until a match is found
    matched_object_id=-1;

    //Initialize object_number to 0 so if there are no previous templates, the first object has ID 0
    this->object_number=0;

    descriptors.resize(1);
}

Algorithm3D::~Algorithm3D()
{
    std::cerr<<std::endl<<"[LearnerRecognizer -- Algorithm3D]   SAVING TEMPLATES 3D: "<<std::endl<<std::flush;
    for (unsigned int i=0; i<descriptors.size(); i++)
    {
        if(descriptors[i].size()<this->number_views)
        {
            descriptors.erase(descriptors.begin()+i-1);
        }
        else
        {
            dataparser.save_template(descriptors[i],i);
            std::cerr<<"    template: "<<i<<" , number of views: "<<descriptors[i].size()<<std::endl<<std::flush;
        }
    }
    std::cerr<<std::endl<<std::flush;
}


void Algorithm3D::load_templates()
{
    if(dataparser.getNumberTemplates("3D")>1)
    {
        dataparser.getTemplates(number_views,this->descriptors);
        this->next_object();

        std::cerr<<std::endl<<"[LearnerRecognizer -- Algorithm3D]   LOADED "<<descriptors.size()-1<< " TEMPLATES 3D "<<std::endl<<std::endl<<std::flush;
    }
}

void Algorithm3D::next_object()
{
    descriptors.push_back(std::vector<sensor_msgs::PointCloud2> ());
    this->object_number=descriptors.size()-1;

}

void Algorithm3D::set_number_views (int number_views)
{
    this->number_views=number_views;
}


int Algorithm3D::add_descriptors(sensor_msgs::PointCloud2 msg)
{
    //    std::cerr<<"add descriptors 3D: data.empty?: "<<msg.data.empty()<<" object_number: "<<this->object_number<<" descriptors.size: "<<descriptors.size()<<std::endl<<std::flush;

    if(msg.data.empty())
        return -1;
    else if (!msg.data.empty())
    {
        descriptors[this->object_number].push_back(msg);
        return 0;
    }
}


int Algorithm3D::match(const sensor_msgs::PointCloud2ConstPtr & msg)
{

    //    PFH:
    pcl::PointCloud<pcl::PFHSignature125>::Ptr msg_pcl (new pcl::PointCloud<pcl::PFHSignature125> ());
    pcl::fromROSMsg(*msg, *msg_pcl);

    pcl::PointCloud<pcl::PFHSignature125>::Ptr cloud (new pcl::PointCloud<pcl::PFHSignature125> ());

    // Use a KdTree to search for the nearest matches in feature space
    pcl::KdTreeFLANN <pcl::PFHSignature125> descriptor_kdtree;


    //      VFH:
    //    pcl::PointCloud<pcl::VFHSignature308>::Ptr msg_pcl (new pcl::PointCloud<pcl::VFHSignature308> ());
    //    pcl::fromROSMsg(*msg, *msg_pcl);

    //    pcl::PointCloud<pcl::VFHSignature308>::Ptr cloud (new pcl::PointCloud<pcl::VFHSignature308> ());

    //    // Use a KdTree to search for the nearest matches in feature space
    //    pcl::KdTreeFLANN <pcl::VFHSignature308> descriptor_kdtree;


    descriptor_kdtree.setInputCloud (msg_pcl);

    std::vector<int> correspondences;


    std::vector<int> ratio;
    ratio.resize(descriptors.size()-1);


    // Find the index of the best match for each keypoint, and store it in "correspondences"
    const int k = 1;

    //    NEARESTKSEARCH!
    for(int obj_numb=0; obj_numb<descriptors.size()-1; obj_numb++)
    {

        std::vector<int> k_indices (k);
        std::vector<float> k_squared_distances (k);


        for (int i = 0; i < static_cast<int> (descriptors[obj_numb].size()); ++i)
        {
            pcl::fromROSMsg(descriptors[obj_numb][i], *cloud);
            descriptor_kdtree.nearestKSearch(*cloud, i, k, k_indices, k_squared_distances);
            correspondences.push_back(k_squared_distances[0]);
        }

        ratio[obj_numb]=std::distance(correspondences.begin(), std::max_element(correspondences.begin(), correspondences.end()));


    }

    if (ratio.size()>0)
        this->matched_object_id=std::distance(ratio.begin(),std::max_element(ratio.begin(), ratio.end()));

    else
        this->matched_object_id=-1;

    if(matched_object_id>0)
        std::cerr<<"ratio[max_elem]: "<<ratio[matched_object_id]<<std::endl;

    for (int k=0; k<ratio.size(); k++)
        std::cerr<<"ratio[]: "<<ratio[k]<<std::endl;

    std::cerr<<"ratio[matched_object_id]: "<<ratio[matched_object_id]<<std::endl;


    return matched_object_id;


}

int Algorithm3D::get_number_template()
{
    return this->object_number;
}
