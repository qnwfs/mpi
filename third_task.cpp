#include <stdio.h>
#include <omp.h>
using namespace std;

int main()
{
    #ifdef _OPENMP
        printf("OpenMP is supported!\n");
    #endif
    printf("Posledovatelnaya oblast' 1 \n");
    int count, num;

    #pragma omp parallel
    {
        printf("Parallelnaya oblast' 1 \n");
        count = omp_get_num_threads();
        num = omp_get_thread_num();
        printf("Number of threads: %d \n Thread number: %d \n", count, num);
    }
    omp_set_num_threads(2);
    #pragma omp parallel num_threads(3)
    {
        printf("Parallelnaya oblast' 2 \n");
        count = omp_get_num_threads();
        num = omp_get_thread_num();
        printf("Number of threads: %d \n Thread number: %d \n", count, num);
    }
    #pragma omp parallel
    {
        printf("Parallelnaya oblast' 3 \n");
        count = omp_get_num_threads();
        num = omp_get_thread_num();
        printf("Number of threads: %d \n Thread number: %d \n", count, num);
    }
    printf("Posledovatelnaya oblast' 2 \n");
}