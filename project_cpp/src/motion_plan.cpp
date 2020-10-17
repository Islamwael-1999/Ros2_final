#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"
#include <string.h>
class motion_plan : public rclcpp::Node
{
public:
    motion_plan() : Node("motion_plan")
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::String>("GATE_POSITION", 10,
        std::bind(&motion_plan::callback, this, std::placeholders::_1));
        publisher_ = this->create_publisher<example_interfaces::msg::String>("DIRECTION",10);
        RCLCPP_INFO(this->get_logger(), "motion planner initiated");
    }

private:





    void publishpos()
    {
        auto msg_publish =example_interfaces::msg::String();
        msg_publish.data = std::string(position);
        publisher_ -> publish(msg_publish);

    }


    void callback(const example_interfaces::msg::String::SharedPtr msg)
    {
       int  pos=stoi(msg->data);
       std::string up = "UP";
       std::string ahead = "AHEAD";
       std::string down = "DOWN";
       std::string left = " LEFT";
       std::string forward = " FORWARD";
       std::string right = " RIGHT";
         if (pos == 0)
            position="no gate detected";
        else{
            if (int((pos-1)/3)==0)
                position = up;
            else if (int((pos-1)/3) == 1)
                position = ahead;
            else if (int((pos-1)/3)==2)
                position = down;
            if ((pos-1) % 3 == 0)
                position =position + left;
            else if ((pos-1)%3==1)
                 position =position + forward;
            else if ((pos-1)%3==2)
                 position =position + right;
        }
        publishpos();
       //RCLCPP_INFO(this->get_logger(), "%s",msg->data.c_str());
   }
   std::string position;
   rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;
   rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<motion_plan>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}