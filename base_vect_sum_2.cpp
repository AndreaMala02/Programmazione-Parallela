#include <omp.h>
#include <stdio.h>
#include <iostream>

#define N 1024



int main() {
    int a[N];
    int b[N];
    int c[N];  
    double start = 0.0;
    double end = 0.0;
    int i=0;
    for(i=0; i<N; i++) {
        a[i] = i;
        b[i] = i;           
    }
    //somp_set_num_threads(4);
    start = omp_get_wtime();
    #pragma omp parallel for 
        for(i=0; i<N; i++) {
            if((i+1)==N) {
                c[i] = a[i]*1 +b[i]*1; 
                //printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
            } 
            else {
                c[i] = a[i]*a[i+1] +b[i]*b[i+1]; 
                //printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
            } 
        }   
    end = omp_get_wtime();
    std::cout << "Tempo di inizio: " << start << ", tempo di fine: " << end << ", deltat: " << (end-start) << std::endl;
    return 0;
}