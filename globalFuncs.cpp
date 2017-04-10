#include "globalDefines.h"
#include "globalStruct.h"
#include "globalFuncs.h"

#include "threadDB.h"
#include "threadNET.h"


void waits(int seconds) {
    boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}


void waitms(int mseconds) {
    boost::this_thread::sleep_for(boost::chrono::milliseconds {mseconds});
}


int globalTreadsInitData(threadGlobal *globalTread) {
    int result = 0;

    memset(globalTread, 0, sizeof(threadGlobal));

    globalTread->allTreadsGlobalShutdown = false;

    // 0. DB
    globalTread->threadPointersArray[THREADS_DATA_TYPE_DB] = new threadDB;

    // 1. NET
    globalTread->threadPointersArray[THREADS_DATA_TYPE_NET] = new threadNET;

    // init DB
    threadDB *pTmpDB = (threadDB *) globalTread->threadPointersArray[THREADS_DATA_TYPE_DB];
    pTmpDB->IP = new char[16];
    pTmpDB->SQL = std::string("DB Ready");
    pTmpDB->IP = (char *) "192.168.0.2";


    // init NET
    threadNET *pTmpNET = (threadNET *) globalTread->threadPointersArray[THREADS_DATA_TYPE_NET];
    pTmpNET->IP = new char[16];
    pTmpNET->str = std::string("Connection");
    pTmpNET->IP = (char *) "192.168.0.1";

    result = 1;

    return result;
}