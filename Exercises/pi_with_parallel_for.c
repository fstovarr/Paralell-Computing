// -D DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ITERATIONS 2e09
#define NUM_THREADS 8
#define PAD 8

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
    double ans[NUM_THREADS * PAD];
    int max = ITERATIONS;

    struct timeval after, before, result;

    gettimeofday(&before, NULL);

    for (int i = 0; i < NUM_THREADS * PAD; i++)
        ans[i] = 0;

    double pi = 0.0;
    #pragma omp parallel num_threads(NUM_THREADS)
    {
        double local_pi = 0.0;
        #pragma omp for 
        for (int i=0; i<max; i++) {
            if(i % 2) local_pi -= (4.0 / ((i * 2 + 1)));
            else local_pi += (4.0 / ((i * 2 + 1)));       
        }

        #pragma omp critical (l3)
        pi += local_pi;
    }

    gettimeofday(&after, NULL);
    timersub(&after, &before, &result);
    printf("Pi: %2.12f\nTime elapsed: %ld.%06ld\n", pi, (long int) result.tv_sec, (long int) result.tv_usec);
}