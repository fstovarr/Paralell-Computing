#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ITERATIONS 2e09
#define NUM_THREADS 8

double ans[NUM_THREADS];

double calculatePi(int initIteration, int endIteration) {   
    int i = initIteration;
    double partialAns = 0;

    do {
        partialAns = partialAns + (double)(4.0 / ((i*2)+1));
        i++;
        partialAns = partialAns - (double)(4.0 / ((i*2)+1));
        i++;
    } while(i < endIteration);

    return partialAns;
}

int main()
{
    double step = ITERATIONS / NUM_THREADS;

    struct timeval after, before, result;
    gettimeofday(&before, NULL);
    // for (int i = 0; i < NUM_THREADS; ++i) 

    #pragma omp parallel num_threads(NUM_THREADS)
    {
        int ID = omp_get_thread_num();
        // printf("Thread %d running\n", ID);
        ans[ID] = calculatePi(ID * step, (ID + 1) * step);
    }

    double pi = 0.0;
    for (int i = 0; i < NUM_THREADS; i++)
        pi += ans[i];

    gettimeofday(&after, NULL);
    timersub(&after, &before, &result);
    printf("Pi: %2.12f \nTime elapsed: %ld.%06ld\n", pi, (long int) result.tv_sec, (long int) result.tv_usec);
}