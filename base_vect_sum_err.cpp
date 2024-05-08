#include <omp.h>
#include <stdio.h>
#include <iostream>

#define N 12



int main() {
    int a[N]; 
    double start = 0.0;
    double end = 0.0;
    int i=0;
    for(i=0; i<N; i++) {
        a[i] = i; 
    } 
    omp_set_num_threads(4);
    start = omp_get_wtime();
    #pragma omp parallel for 
        for(i=0; i<N; i++) {
            a[i] += a[N-1-i]; 
            //printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
            printf("Il valore di a[i] è %d nella posizione %d\n", a[i], i);
        }   
    end = omp_get_wtime();
    std::cout << "Tempo di inizio: " << start << ", tempo di fine: " << end << ", deltat: " << (end-start) << std::endl;

    return 0;
}