#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {
    //omp_set_num_threads(16);
    #pragma omp parallel 
    {
        int myThreadID = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        printf("Hello from thread %d of %d\n", myThreadID, numThreads);
    }
    return 0;
}