#include <iostream>
#include "mpi.h"
using namespace std;

int main(int argc, char **argv)
{
    int rank, size, prev, next;
    int rbuf[2], sbuf[2];
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Request reqs[4];
    MPI_Status stats[4];
    prev = rank - 1;
    next = rank + 1;
    if(rank == 0) prev = size - 1;
    if(rank == size - 1) next = 0;
    MPI_Recv_init(&rbuf[0], 1, MPI_INT, prev, 5, MPI_COMM_WORLD, &reqs[0]);
    MPI_Recv_init(&rbuf[1], 1, MPI_INT, next, 6, MPI_COMM_WORLD, &reqs[1]);
    MPI_Send_init(&sbuf[0], 1, MPI_INT, prev, 6, MPI_COMM_WORLD, &reqs[2]);
    MPI_Send_init(&sbuf[1], 1, MPI_INT, next, 5, MPI_COMM_WORLD, &reqs[3]);
    for(int i = 0; i < 2; i++){
        sbuf[0] = i;
        sbuf[1] = i * 2;
        MPI_Startall(4, reqs);
        MPI_Waitall(4, reqs, stats);
        cout << "Number of current process is: " << rank << endl;
        cout << "From previous process I got: " << rbuf[0] << endl;
        cout << "From next process I got: " << rbuf[1] << endl;
//здесь мог быть ваш код
    }
    MPI_Request_free(&reqs[0]);
    MPI_Request_free(&reqs[1]);
    MPI_Request_free(&reqs[2]);
    MPI_Request_free(&reqs[3]);
    MPI_Finalize();
}