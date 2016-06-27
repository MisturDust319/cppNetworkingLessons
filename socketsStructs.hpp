#ifndef SOCKETSTRUCTS_H
#define SOCKETSTRUCTS_H

//addrinfo
//	a struct to prep socket addr structs for use
//	also used to lookup host & service names
//	first thing called when making a connection
//	note that a call to getaddrinfo() can mostly fill
//	this out for you
struct addrinfo {
	int		ai_flags; 			//AI_PASSIVE, AI_CANONNAME, etc.
	int		ai_family;			//AF_INET (IPv4), AF_INET6 (IPv6), 
								//	AF_UNSPEC (agnostic)
	//used to set which version of IP protocol to use
	int		ai_socktype;		//SOCK_STREAM, SOCK_DGRAM
	//describes the socket type to be used (stream or datagram)
	
	size_t 	ai_addrlen;			//size of ai_addr in bytes
	struct 	sockaddr* ai_addr;	//struct sockaddr_in or _in6
	//holds details of IP addr structure
	char*	ai_canonname;		//full canonical hostname
	
	struct addrinfo* ai_next;	//linked list, next node
	//this points to one of several next elements
	//	usually you use 1st working element,
	//	but circumstances dictate how to choose
}
//sockaddr
//	holds socket info for many types of sockets
//	note that a pointer to sockaddr_in can be cast as a sockaddr
//	pointer, and vice versa
struct sockaddr {
	unsigned short sa_family;	//address family, AF_xxx
	//Used mainly to state either AF_INET (IPv4) OR AF_INET6 (IPv6)
	//	and occasionally other things
	char		   sa_data;		//14 bytes of protocol address
	//holds the destination addr & the port number for the socket
}

//sockaddr_in
//	a complimentary struct to sockaddr
//	the "_in" stands for internet, and this struct is used w/ IPv4
//	note that a pointer to sockaddr_in can be cast as a sockaddr
//	pointer, and vice versa
struct sockaddr_in {
	short int			sin_family;		//Address family, AF_INET
	//corresponds to sa_family in sockaddr, and must be set to AF_INET
	unsigned short int	sin_port;		//port number
	//must be in Network Byte Order (i.e. Big Endian)
	struct in_addr		sin_addr;		//Internet addr
	unsigned char		sin_zero[8];	//Same size as struct sockaddr
	//used to pad stucture to length of sockaddr. Init to 0s 
	//	using memset()
	//	(a function which copies n bytes of a const into mem)
}

//in_addr
//	a struct used for IPv4 only (in6_addr is for IPv6) meant to hold
//	an IP addr
//	this used to be a Union, not a struct
//	I believe it is a struct only for naming purposes,
//  to make it clear it's a IP addr as it only holds one member
struct in_addr {
	uint32_t s_addr; // that's a 32-bit int (4 bytes)
}

//The IPv6 versions of sockaddr_in and in_addr

//sockaddr_in6
//	a complimentary struct to sockaddr
//	the "_in" stands for internet, and this struct is used w/ IPv6
//	note that a pointer to sockaddr_in can be cast as a sockaddr
//	pointer, and vice versa
struct sockaddr_in6 {
	u_int16_t		sin6_family;	//address family, AF_INET6
	u_int16_t		sin6_port;		//port number, Network Byte Order
	u_int32_t		sin6_flowinfo;	//IPv6 flow information
	struct in6_addr	sin6_addr;		//IPv6 address
	u_int32_t		sin6_scope_id;	//Scope ID
}

//in_addr
//	a struct used for IPv6 only (in6_addr is for IPv6) meant to hold
//	an IP addr
//	this used to be a Union, not a struct
//	I believe it is a struct only for naming purposes,
//  to make it clear it's a IP addr, as it only holds one member
struct in6_addr {
	unsigned char	s_addr; // that's a 32-bit int (4 bytes)
}

#endif