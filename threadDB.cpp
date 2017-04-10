
#include "globalDefines.h"
#include "globalStruct.h"
#include "globalFuncs.h"

#include "threadNET.h"
#include "threadDB.h"


void thread_DB(threadGlobal *globalTread) {


    threadNET *p_NET = nullptr;
    threadDB *p_DB = nullptr;

    if (nullptr != globalTread) {
        p_NET = (threadNET *) globalTread->threadPointersArray[THREADS_DATA_TYPE_NET];
        p_DB = (threadDB *) globalTread->threadPointersArray[THREADS_DATA_TYPE_DB];
    }


    try {
        if (nullptr != p_DB)
            while (!globalTread->allTreadsGlobalShutdown) {


                waits(1);
                std::cout << p_DB->SQL.c_str() << '\n';

                for (int i = 0; i < 5; ++i) {
                    waits(1);
                    std::cout << i << '\n';
                }
                waitms(1000);
                if (nullptr != p_NET) {
                    p_NET->str = "SQL Select received";
                    std::cout << p_DB->SQL.c_str() << '\n';
                }
                p_DB->SQL = "SQL Done.";
                waitms(2000);
                std::cout << p_DB->SQL.c_str() << '\n';
                waits(5);
            }

    }
    catch (boost::thread_interrupted &) {}
}
