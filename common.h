#ifndef COMMON_H
#define COMMON_H

#ifdef __WIN32__
	#define CLEARSCREEN "cls"
#elif __linux__
	#define CLEARSCREEN "clear"
#endif

#endif