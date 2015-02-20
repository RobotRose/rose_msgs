cmake_minimum_required(VERSION 2.8.3)
project(contact_sensor_msgs)

find_package(catkin REQUIRED
	COMPONENTS
	geometry_msgs 
	message_generation 
	std_msgs
)

# Add message files
add_message_files(DIRECTORY msg
	FILES
	bumper.msg
	bumpers.msg
 )

# Generate messages, services and actions
generate_messages(DEPENDENCIES 
	std_msgs 
	geometry_msgs)

catkin_package(
	INCLUDE_DIRS
	LIBRARIES 
	CATKIN_DEPENDS 
		message_generation 
		std_msgs 
		geometry_msgs 
	DEPENDS 
)
