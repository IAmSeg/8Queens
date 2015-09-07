// Function to get current time
time_t timestamp(){
    time_t curTime; // calendar time
    return curTime = time(NULL); // get current calendar time
}

struct timeval detail_time;
gettimeofday(&detail_time, NULL);
detail_time.tv_usec / 1000; // milliseconds
detail_time.tv_usec; // microseconds