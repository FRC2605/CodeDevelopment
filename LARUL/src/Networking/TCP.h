#ifndef LARUL_TCP_H
#define LARUL_TCP_H

/*
* TCP defines the tcp-related information used by all TCP classes.
*/

class TCP
{
public:
	
	typedef enum
	{
		
		kAddressType_IPV4 = 1,
		kAddressType_IPV6 = 2
		
	} AddressType;
	
private:
	
	TCP () {};
	
};

#endif
