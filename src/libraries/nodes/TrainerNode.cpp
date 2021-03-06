//#include "TrainerNode.h"

//TrainerNode::TrainerNode()
//{

//    descriptors2D=nh.subscribe<ocular::HandImage>("descriptors2D", 1, &TrainerNode::train2D_cb, this);
//    //    descriptors3D=nh.subscribe("3D descriptors",1,&train3D_cb, this);

//    event_sub=nh.subscribe<ocular::EventHandler>("event", 1, &TrainerNode::setEvent, this);

//    //    ROS_ERROR("ESTAMOS EN TRAINERNODE!!");

//    number_views=5; //the total number of views to be extracted of each object
//    number_views_it=0;

//    //Initialize new object to true so the algorithm starts learning a NEW object
//    alg2D.set_new_object(true);

//    //default mode: recognize
//    this->learn=false;


//}



//void TrainerNode::train2D_cb(const ocular::HandImageConstPtr & msg)
//{
//    if(learn)
//    {
//        //        std::cerr<<"LEARNING");

//        // take each view and train the algorithm with it, until the iterator is larger than the total number of views to be taken
//        if (number_views_it<number_views)
//        {
//            std::cerr<<"TRAINING VIEW "<< number_views_it<<std::endl;

//            alg2D.add_descriptors(msg);
//            number_views_it ++;

//        }
//        else if (number_views_it==number_views)
//        {
//            //when all the views have been taken, train the algorithm with them
//            alg2D.train2D();
//            //when the iterator is equal to the total number of views, reset the iterator
//            number_views_it=0;

//            alg2D.set_new_object(true);
//            //stop the learning until a new recognize - learn events happen
//            this->learn=false;

//            //stop the training, all the views have already been trained
//            std::cerr<<"TRAINING COMPLETED, PLEASE TAKE YOUR HAND CLOSER TO THE BODY TO START THE RECOGNITION"<<std::endl;

//        }
//        else
//            std::cerr<<"Iterator of number of views greater than the total number of views"<<std::endl;
//    }

//}

//void TrainerNode::train3D_cb()
//{

//}

//void TrainerNode::setEvent(const ocular::EventHandlerConstPtr & msg)
//{


//    if (msg->event=="learn")
//    {
//        //        ROS_ERROR ("LEARN EVENT RECEIVED");

//        if (msg->last_event=="recognize")   //If last event was recognize
//        {
//            this->learn=true;
//            //This is a new object to learn
//            alg2D.set_new_object(true);
//        }
//        else    //If last event was learn
//        {
//            alg2D.set_new_object(false);  //We are still learning views of the object
//        }

//    }
//    else if (msg->event=="recognize")   //If the event is recognize
//    {
//        //        ROS_ERROR ("RECOGNIZE EVENT RECEIVED");
//        this->learn=false;
//    }


//}
