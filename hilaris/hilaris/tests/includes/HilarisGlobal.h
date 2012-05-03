#ifndef _HILARIS_GLOBAL_H_
#define _HILARIS_GLOBAL_H_

#include "Hilaris.h"

Hilaris& getHilaris()
{
    static Hilaris hilaris;
    
    hilaris.setFileLogLevel(Debug::NONE);
    hilaris.setConsoleLogLevel(Debug::NONE);
    
    return hilaris;
}

#endif
