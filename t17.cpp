#include <iostream>
#include "mpi.h"
using namespace std;

int main(int argc, char **argv)
{
    int rank, size, prev, next;
    int buf[2];
    int sendbuf = 1337;
    int recvbuf = 1338;
    MPI_Init(&argc,&argv);
    MPI_Request reqs[4];
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    prev = rank - 1;
    next = rank + 1;
    if(rank==0) prev = size - 1;
    if(rank==size - 1) next = 0;
    MPI_Sendrecv(&rank, 1, MPI_INT, next, 5, &buf[0], 1, MPI_INT, prev, 5, MPI_COMM_WORLD, &status);
    MPI_Sendrecv(&rank, 1, MPI_INT, prev, 6, &buf[1], 1, MPI_INT, next, 6, MPI_COMM_WORLD, &status);
   /* MPI_Irecv(&buf[0], 1, MPI_INT, prev, 5, MPI_COMM_WORLD, &reqs[0]);
    MPI_Irecv(&buf[1], 1, MPI_INT, next, 6, MPI_COMM_WORLD, &reqs[1]);
    MPI_Isend(&rank, 1, MPI_INT, prev, 6, MPI_COMM_WORLD, &reqs[2]);
    MPI_Isend(&rank, 1, MPI_INT, next, 5, MPI_COMM_WORLD, &reqs[3]);
    MPI_Waitall(4, reqs, stats);*/
    /*Здесь необходимо вывести на экран номер текущего процесса, и что он получает от предыдущего иследующего процессов.*/
    cout << "Number of current process is: " << rank << endl;
    cout << "From previous process I got: " << buf[0] << endl;
    cout << "From next process I got: " << buf[1] << endl;
    MPI_Finalize();
}