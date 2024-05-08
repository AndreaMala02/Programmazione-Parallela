#include <omp.h>
#include <stdio.h>
#define N 10

int main() {
    int a[N];
    int b[N];
    int c[N];  
    int i=0;
    for(i=0; i<N; i++) {
        a[i] = i;
        b[i] = i;           
    }
    omp_set_num_threads(4);
    #pragma omp parallel for 
        for(i=0; i<N; i++) {
            c[i] = a[i]+b[i]; 
            printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
        }   
    return 0;
}