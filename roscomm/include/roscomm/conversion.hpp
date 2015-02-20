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

#ifndef CONVERSION_HPP
#define CONVERSION_HPP

namespace ros
{
	namespace conversion
	{
		#define TYPEDEF_CONVERT(native, message)	\
			typedef native 		nativeType;			\
			typedef message 	messageType;

		template <typename nativeType>
		struct convert
	    {};

	    template <typename nativeType, typename converstionType>
		struct special_convert
	    {};
	}
}

#endif // CONVERSION_HPP 