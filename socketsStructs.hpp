
//addrinfo
//	a struct to prep socket addr structs for use
//	also used to lookup host & service names
//	first thing called when making a connection
//	note that a call to getaddrinfo() can mostly fill
//	this out for you
struct addrinfo {
	int		ai_flags; 			//AI_PASSIVE, AI_CANONNAME, etc.
	int		ai_family;			//AF_INET (IPv4), AF_INET6 (IPv6), AF_UNSPEC (agnostic)
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