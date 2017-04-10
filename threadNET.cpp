
#include "globalDefines.h"
#include "globalStruct.h"
#include "globalFuncs.h"

#include "threadNET.h"
#include "threadDB.h"


void thread_NET(threadGlobal *globalTread) {


    threadNET *p_NET = nullptr;
    threadDB *p_DB = nullptr;

    if (nullptr != globalTread) {
        p_NET = (threadNET *) globalTread->threadPointersArray[THREADS_DATA_TYPE_NET];
        p_DB = (threadDB *) globalTread->threadPointersArray[THREADS_DATA_TYPE_DB];   //Разыменнование структуры из массива структур
    }


    try {
        if (nullptr != p_NET)
            while (!globalTread->allTreadsGlobalShutdown) {


                waits(1);
                std::cout << p_NET->str.c_str() << '\n';

                for (int i = 0; i < 5; ++i) {
                    waits(1);
                    std::cout << i << '\n';
                }
                waitms(10);
                p_NET->str = "NETWORK Counter DONE, Generating SQL Select...";
                waitms(100);
                std::cout << p_NET->str.c_str() << '\n';
                if (nullptr != p_DB) {
                    p_DB->SQL = "SELECT * FROM table;";
                }

                waits(3);
                //Shutdown all threads
                globalTread->allTreadsGlobalShutdown = true;
            }

    }
    catch (boost::thread_interrupted &) {}
}
