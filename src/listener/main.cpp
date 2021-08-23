#include <ros/ros.h>
#include <std_msgs/String.h>

void
chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  //Печатаем сообщение
  ROS_INFO("There something on the line! [%s]", msg->data.c_str());
}

int
main(int argc, char** argv)
{
  //Создаем узел listener
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  //указываем, что нужно слушать шину chatter, причем очередь сообщений у нас не
  //более 1000, при получении нового - вызываем метод chatterCallback
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  // spin начинает циклически вызывать наш callback до тех пор, пока ROS не
  // прекратит работу
  ros::spin();

  return 0;
}
