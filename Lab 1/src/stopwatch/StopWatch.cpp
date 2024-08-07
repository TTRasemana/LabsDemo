#include "StopWatch.h"
#include <ctime>

// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing
double StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}

StopWatch::StopWatch() : start_time(0) {}

void StopWatch::start() {
    start_time = getProcessTime();
}

double StopWatch::stop() {
    return  end_time=getProcessTime() - start_time;
}