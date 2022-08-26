#ifndef ASSERT_H
#define ASSERT_H

#include <stdio.h>

#include "ColourConsts.h"

#define ASSERT(condition)                                                             \
        {                                                                             \
        if (!(condition))                                                             \
            fprintf(stderr, "%sError in '%s' in line %d in file %s in %s%s\n",        \
                    KRED, #condition, __LINE__, __FILE__, __PRETTY_FUNCTION__, KNRM); \
        }

#endif
