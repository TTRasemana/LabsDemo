#include "StopWatch.h"
#include <iostream>
#include <unistd.h>

using namespace std;
int main() {
    StopWatch sw;
    sw.start();
    sleep(1);
    cout << "Elapsed time: " << sw.stop() << " seconds" << endl;

    return 0;
}
