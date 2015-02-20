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

#ifndef CONVERSION_BOOL_HPP
#define CONVERSION_BOOL_HPP

#include "roscomm/conversion.hpp"
#include "std_msgs/Bool.h"

namespace ros
{
	namespace conversion
	{
		template <>
		struct convert<bool>
	    {
	    	TYPEDEF_CONVERT(bool, std_msgs::Bool)

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
	}; // namespace conversion
}; // namespace ros


#endif // CONVERSION_BOOL_HPP 
