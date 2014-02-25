#include "dataparser.h"

DataParser::DataParser()
{
    algorithms_2D_path="../data/algorithms/2D/";
    algorithms_3D_path="../data/algorithms/3D/";
    templates_path="../data/templates/";
    temp_path="../data/temp/temp.txt";
}

std::vector <std::string> DataParser::get_file_names (std::string path)
{
    std::string sys_command="ls "+path +"> "+temp_path;
    system(sys_command.c_str());

    std::ifstream file(temp_path.c_str());
    std::string dummy;
    std::vector <std::string> templates;

    while (file.good())
    {
        getline(file,dummy);
        templates.push_back(dummy);
    }
    file.close();


    std::string remove_temp_files="rm "+temp_path;

    system(remove_temp_files.c_str());

    templates.erase(templates.end());

    return templates;
}


void DataParser::save_template_2D()
{
    //If it is a new object, we want to create a new object position in the vector
    int object_number=descriptors.size();

    //If it is not a new object, we want to add the descriptors to the last object:
    if (new_object!=true)
        object_number-=1;

    //NAME CODE:
    std::stringstream filename;
    filename <<"../data/templates/"<<object_number<<"/";

    std::stringstream command;
    command<<"mkdir "<<filename;

    if (new_object==true)
        system(command.str().c_str());

    for (unsigned int i=0; i<descriptors.size(); i++)
    {
        filename<<"view_"<< i<<"_d.yml";
        cv::FileStorage fs(filename.str(), cv::FileStorage::WRITE);
        fs <<"descriptors"<< descriptors[object_number][i];

    }
}



void DataParser::save_algorithm_2D()
{
    //If it is a new object, we want to create a new object position in the vector
    int object_number=descriptors.size();

    //If it is not a new object, we want to add the descriptors to the last object:
    if (new_object!=true)
        object_number-=1;

    std::stringstream filename;
    filename<<algorithms_2D_path<<object_number<<".yml";

    cv::FileStorage fs(filename.str(), cv::FileStorage::WRITE);
    //    alg2D[object_number].write(fs);
    //    fs<<"algorithm"<<object_number<<alg2D[object_number];
    alg2D[object_number].write(fs);


}


void DataParser::load_algorithms_2D(std::string path)
{
    //path = "../data/algorithms/2D/";
    std::vector <std::string> algorithms=Trainer::get_file_names(path);
    //    cv::FlannBasedMatcher trial;
    std::string name_algorithm;

    for (unsigned int i=0; i<algorithms.size(); i++)
    {
        cv::FileStorage fr(algorithms[i], cv::FileStorage::READ);
        cv::FileNode fn;
        fn.fs=*fr;
        alg2D[i].read(fn);

    }
}


cv::Mat DataParser::load_descriptor (std::string filename)
{
    cv::FileStorage fr (filename, cv::FileStorage::READ);
    cv::Mat descriptor;
    fr["descriptors"]>>descriptor;

    return descriptor;
}


std::vector<std::vector<cv::Mat> > DataParser:: getTemplates ()
{
    std::vector<std::string> number_of_objects_folders=this->get_file_names(templates_path);
    int total_objects=number_of_objects_folders.size();

    std::stringstream path;

    std::vector<std::vector<cv::Mat> >descriptors;
    descriptors.resize(total_objects);

    for (int object_number=0;object_number<total_objects; object_number++ )
    {
        path.str(std::string());
        path<<templates_path<<object_number<<"/";
        std::vector <std::string> templates=get_file_names(path.str());

        //extract the information from the yml files
        for (unsigned int i=0; i<templates.size(); i++)
        {
            descriptors[object_number].push_back(load_descriptor(templates[i]));
            //            temp_keyp.push_back(load_keypoint(keyp_t[i]));
        }
    }

    return descriptors;
}


