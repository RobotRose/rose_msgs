cmake_minimum_required(VERSION 2.8.3)
project(rose_base_msgs)

find_package(catkin REQUIRED COMPONENTS
		actionlib_msgs 
		geometry_msgs 
		message_generation
		roscomm
		std_msgs 
	)

# Generate messages in the 'msg' folder
add_message_files( FILES
  battery_state.msg
  bumpers_state.msg
  lift_command.msg
  lift_state.msg
  wheelunit_states.msg
)

# Generate actions in the 'action' folder
add_action_files( FILES
  	cmd_velocity.action
  	wheelunit_states.action
)

generate_messages(DEPENDENCIES 
	actionlib_msgs 
	geometry_msgs 
	roscomm
	std_msgs 
	)

catkin_package(
 INCLUDE_DIRS 
 LIBRARIES 
 CATKIN_DEPENDS 
	actionlib_msgs 
	geometry_msgs 
	message_generation
	roscomm
	std_msgs 
 DEPENDS 
)
