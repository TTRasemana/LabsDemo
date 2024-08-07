#ifndef STOPWATCH_H
#define STOPWATCH_H



#define STOPWATCH_H

class StopWatch {
private:
    double start_time;
    double end_time;
public:
    StopWatch();
    void start();
    double stop();
    // returns the amount of time in seconds that has passed since the process (i.e. your program) started executing
    double getProcessTime();
};

#endif
