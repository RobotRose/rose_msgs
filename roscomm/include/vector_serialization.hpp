/***********************************************************************************
* Copyright: Rose B.V. (2014)
*
* Revision History:
*	Author: Okke Hendriks
*	Date  : 2014/10/14
* 		- File created.
*
* Description:
*	ROS serialization information for vectors of serializable types
* 
***********************************************************************************/

#ifndef VECTOR_SERIALIZATION_HPP
#define VECTOR_SERIALIZATION_HPP

namespace ros
{
	namespace serialization
	{
		template<typename U>
		struct Serializer< std::vector<U> >
		{
			template<typename Stream>
			inline static void write(Stream& stream, const std::vector<U>& vec)
			{
				for ( auto it = vec.begin() ; it != vec.end() ; it++ )
					ros::serialization::Serializer<U>::write(stream, *it);
			}

			template<typename Stream>
			inline static void read(Stream& stream, std::vector<U>& vec)
			{
				for ( auto it = vec.begin() ; it != vec.end() ; it++ )
					ros::serialization::Serializer<U>::read(stream, *it);
			}

			inline static uint32_t serializedLength(const std::vector<U>& vec)
			{
				uint32_t size = 4;
				for ( auto it = vec.begin() ; it != vec.end() ; it++ )
					size += ros::serialization::Serializer<U>::serializedLength(*it);
				return size;
			}
		};

	} // namespace serialization

	namespace message_traits
	{
		template<class T>
		struct MD5Sum< std::vector<T> >
		{
			static const char* value(){return ros::message_traits::template MD5Sum<T>::value();}
			static const char* value(const std::vector<T>& m) { return value(); }
		};

		template<class T>
		struct DataType<std::vector<T>>
		{
			static const char* value(){ return ros::message_traits::template DataType<T>::value(); }
			static const char* value(const std::vector<T>& m) { return value(); }
		};

		template<class T>
		struct Definition<std::vector<T>>
		{
			static const char* value(){ return ros::message_traits::template Definition<T>::value(); }
			static const char* value(const std::vector<T>& m){ return value(); }
		};
	} // namespace message_traits
	
	namespace service_traits
	{
		template<class T>
		struct MD5Sum<std::vector<T>>
		{
			static const char* value(){	return ros::message_traits::MD5Sum<std::vector<T>>::value(); }
			static const char* value(const std::vector<T>& m) { return value(); }
		};

		template<class T>
		struct DataType<std::vector<T>>
		{
			static const char* value(){ return ros::message_traits::DataType<std::vector<T>>::value(); }
			static const char* value(const std::vector<T>& m) { return value(); }
		};    
	} // namespace service_traits
} // namespace ros

#endif // VECTOR_SERIALIZATION_HPP 
