#include "globalDefines.h"
#include "globalStruct.h"
#include "globalFuncs.h"

#include "threadDB.h"
#include "threadNET.h"

threadGlobal globalTreads;

int main(void) {

    if (globalTreadsInitData(&globalTreads)) {

        boost::thread tDB = boost::thread(boost::bind(thread_DB, &globalTreads));
        boost::thread tNET = boost::thread(boost::bind(thread_NET, &globalTreads));

        //interupt in 20 sec, if threads does'nt complete work
        waits(20);

        tDB.interrupt();
        tNET.interrupt();

        tDB.join();
        tNET.join();
    }

    return 0;
}