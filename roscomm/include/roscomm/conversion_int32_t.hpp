/***********************************************************************************
* Copyright: Rose B.V. (2014)
*
* Revision History:
*	Author: Okke Hendriks
*	Date  : 2014/10/14
* 		- File created.
*
* Description:
*	description
* 
***********************************************************************************/

#ifndef CONVERSION_INT32_T_HPP
#define CONVERSION_INT32_T_HPP

#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "roscomm/conversion.hpp"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

namespace ros
{
	namespace conversion
	{
		template <>
		struct convert<int>
	    {
	    	TYPEDEF_CONVERT(int, std_msgs::Int32)

	    	convert()
			{}

			messageType get(const nativeType& native)
			{
				messageType message;
				message.data = native;
				return message;
			}

			nativeType get(const messageType& message)
			{
				return message.data;
			}
	    };


	    template <>
		struct special_convert<int, std_msgs::String>
	    {
	    	TYPEDEF_CONVERT(int, std_msgs::String)

	    	special_convert()
			{}

			messageType get(const nativeType& native)
			{
				messageType message;
				std::stringstream ss;
				ss << native;
				message.data = ss.str();
				return message;
			}

			nativeType get(const messageType& message)
			{
				return boost::lexical_cast<int>(message.data);
			}
	    };
	}; // namespace conversion
}; // namespace ros

#endif // CONVERSION_INT32_T_HPP 
