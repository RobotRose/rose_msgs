cmake_minimum_required(VERSION 2.8.3)
project(roscomm)

find_package(catkin REQUIRED 
	COMPONENTS 
	message_generation 
	geometry_msgs 
	std_msgs
)

add_message_files(FILES
	boollist.msg
	intlist.msg
	joint_state.msg
	rect.msg
	stringlist.msg
 )

add_service_files(FILES
	do_one_arm_autonomous.srv  
	toggle_customer_voice_capturer.srv
	do_two_arm_autonomous.srv  
	toggle_operator_cam.srv
	go_to_waypoint.srv         
	toggle_operator_voice_capturer.srv
	empty_service_message.srv
)

 generate_messages( DEPENDENCIES
	geometry_msgs
	std_msgs
 )

catkin_package(
	INCLUDE_DIRS include
	#  LIBRARIES roscomm
	CATKIN_DEPENDS message_runtime geometry_msgs std_msgs
	#  DEPENDS system_lib
)

include_directories( ${PROJECT_SOURCE_DIR}/include ${catkin_INCLUDE_DIRS} )

add_library(action_result_message ${PROJECT_SOURCE_DIR}/src/action_result_message.cpp )
target_link_libraries(action_result_message ${catkin_LIBRARIES})
add_dependencies(action_result_message ${PROJECT_NAME}_generate_messages_cpp)

add_library(parameter_request_message ${PROJECT_SOURCE_DIR}/src/parameter_request_message.cpp )
target_link_libraries(parameter_request_message ${catkin_LIBRARIES})
add_dependencies(parameter_request_message ${PROJECT_NAME}_generate_messages_cpp)