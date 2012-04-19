#ifndef _HILARIS_GLOBAL_H_
#define _HILARIS_GLOBAL_H_

#include "Hilaris.h"

Hilaris& getHilaris()
{
    static Hilaris hilaris;
    return hilaris;
}

#endif
