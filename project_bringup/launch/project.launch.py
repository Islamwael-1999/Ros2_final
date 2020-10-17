from launch import LaunchDescription
from launch_ros.actions import Node
def generate_launch_description():
    ld=LaunchDescription()
    cpp_move_node=Node(
        package="project_cpp",
        executable="cpp_move"
    )
    img_proc_node=Node(
        package="project",
        executable="img_proc"
    )
    ld.add_action(cpp_move_node)
    ld.add_action(img_proc_node)
    return ld