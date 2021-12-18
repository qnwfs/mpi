#include <cstdlib>
#include "iostream"
#include "mpi.h"
using namespace std;

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int matr1[500][500];
    int matr2[500][500];
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            matr1[i][j] = 1;
            matr2[i][j] = 1;
        }
    }
    MPI_Barrier(MPI_COMM_WORLD); //барьерная синхронизация процессов
//начало замера времени для каждого процесса
    double time_start = MPI_Wtime();
//перемножение матриц
    int matrf[500][500];
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            matrf[i][j] = 0;
            for (int k = 0; k < 500; k++)
                matrf[i][j] += matr1[i][k] * matr2[k][j];
        }
    }
//конец замера времени
    double time_finish = MPI_Wtime();
//вывод время выполнения перемножения матриц на каждом процессе
    cout << "Time of execution for process with number " << rank << " is: " << time_finish - time_start << endl;
    MPI_Finalize();
}