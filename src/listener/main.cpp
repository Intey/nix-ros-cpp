#include <iostream>
#include <algorithm>
#include <concepts>
#include <ros/ros.h>
#include <std_msgs/String.h>

template<class T>
concept IterToComparable = requires(T a, T b)
{
  {
    *a < *b
  }
  ->std::convertible_to<bool>;
};

// обратите внимание на IterToComparable вместо слова class
template<IterToComparable InputIt>
void
SortDefaultComparator(InputIt begin, InputIt end)
{
  std::sort(begin, end);
}

struct X
{
  auto operator<=>(const X&) const = default;
  int a;
};

int
concept_main()
{
  std::vector<X> v = { { 10 }, { 9 }, { 11 } };
  SortDefaultComparator(v.begin(), v.end());
  return 0;
}

/*
void
chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  //Печатаем сообщение
  ROS_INFO("There something on the line! [%s]", msg->data.c_str());
}

*/
int
main(int argc, char** argv)
{
  concept_main();
/*
  //Создаем узел listener
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  //указываем, что нужно слушать шину chatter, причем очередь сообщений у нас не
  //более 1000, при получении нового - вызываем метод chatterCallback
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  // spin начинает циклически вызывать наш callback до тех пор, пока ROS не
  // прекратит работу
  ros::spin();

*/
  std::cout << "done" << std::endl;
  return 0;
}
