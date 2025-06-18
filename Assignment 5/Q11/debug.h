#ifndef DEBUG_H

#define DEBUG_H

#include <stdio.h>

#ifdef DEBUG_MODE
    #define LOG(msg) printf("[DEBUG] %s:%d - %s\n", __FILE__, __LINE__, msg)

#else
    #define LOG(msg)

#endif

#endif