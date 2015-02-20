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

#ifndef CONVERSION_INT32_T_LIST_HPP
#define CONVERSION_INT32_T_LIST_HPP

#include "roscomm/conversion.hpp"
#include "roscomm/intlist.h"

namespace ros
{
	namespace conversion
	{
		template <>
		struct convert<std::vector<int>>
	    {
	    	TYPEDEF_CONVERT(std::vector<int>, roscomm::intlist)

	    	convert()
			{}

			messageType get(const nativeType& native)
			{
				messageType message;

				for(const auto& elem : native)
					message.values.push_back(elem);

				return message;
			}

			nativeType get(const messageType& message)
			{
				nativeType native;

				for(const auto& elem : message.values)
					native.push_back(elem);

				return native;
			}
	    };
	}; // namespace conversion
}; // namespace ros

#endif // CONVERSION_INT32_T_LIST_HPP 