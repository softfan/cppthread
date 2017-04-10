
#include "globalDefines.h"


typedef struct threadGlobalStructure {
    void *threadPointersArray[THREADS_DATA_TYPES_MAX];
    bool allTreadsGlobalShutdown;
} threadGlobal;

