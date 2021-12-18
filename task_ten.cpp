#include <stdio.h>
#include "iostream"
#include "mpi.h"
using namespace std;

int main(int argc, char* argv[]){
    MPI_Init(&argc, &argv);
    int rank, n, i, message;
    double time_start, time_finish;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &n);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    time_start = MPI_Wtime();
    /*int array[n+n];
    for(int i = 0; i < n; i++)
    {
        array[i] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        array[n - 1 + i] = i;
    }*/
    if (rank == 0)
    {
        int nb;
        int counter = 0;
        /*cout << "This is displayed by process with rank: " << rank << endl;*/

        for(int i = 0; i < n - 1; i++)
        {
            MPI_Recv(&nb, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            cout << nb << "\t";
            if((nb % 3 == 0) || (nb % 5 == 0) || (nb % 7 == 0)) counter++;
        }

        if(counter > 1)
        {
            cout << "True";
            time_finish = MPI_Wtime();
            cout << "Program exectuion time: " << time_finish - time_start << endl;
        }
        else
        {
            cout << "False";
            time_finish = MPI_Wtime();
            cout << "Program exectuion time: " << time_finish - time_start << endl;
        }
    }
    else {
        /*cout << "this is not rank zero, this is rank: " << rank << endl;*/
        MPI_Send(&rank,1,MPI_INT,0,0,MPI_COMM_WORLD);
    }
    /*time_finish = MPI_Wtime();*/
/*    cout << "Program exectuion time: " << time_finish - time_start << endl;*/
    MPI_Finalize();
    /*cout << "Program exectuion time: " << time_finish - time_start << endl;*/
    return 0;
}

/* ВАРИАНТ No20
Рутовый процесс принимает последовательность целых чисел (рангов + общее число процессов) от
дочерних процессов, и осуществляет проверку на предмет, содержит ли последовательность хотя
бы два числа, кратных 3,5 и 7? */
