#include <stdio.h>
#include "iostream"
#include "mpi.h"
using namespace std;

int main(int argc, char* argv[]){
    MPI_Init(&argc, &argv);
    int rank, n, i, message;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &n);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    cout << " our number of processes" << n;
    cout << " our number of ranks" << rank;
    int array[rank+n];
    for(int i = 0; i < rank; i++)
    {
        array[i] = i;
    }
    for(int i = 0; i < n; i++)
    {
        array[rank+i] = i;
    }
    if (rank == 0)
    {
        cout << "Hello from process " << rank << "\n";
        for (i=1; i<n; i++){
            MPI_Recv(&array, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            for(int i = 0; i < (rank+n); i++)
            {
                cout << array[i] << " ";
            }
            cout << "Hello from process " << message << endl;
        }
    }
    else MPI_Send(&array,1,MPI_INT,0,0,MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}

/* ВАРИАНТ No20
Рутовый процесс принимает последовательность целых чисел (рангов + общее число процессов) от
дочерних процессов, и осуществляет проверку на предмет, содержит ли последовательность хотя
бы два числа, кратных 3,5 и 7? */
