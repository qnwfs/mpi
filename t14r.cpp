#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    MPI_Status status;
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int const size = 10;
    int array[1000000];
    int x = 10;
    for (int i = 0; i < x; i++)
    {
        array[i] = 0;
    }
    if(world_rank == 0)
    {
        double time_start, time_finish, total_time, r;
        time_start = MPI_Wtime();
        for(int i = 0; i < 10; i++)
        {
            int get[x];
            MPI_Send(&array[0], x, MPI_INT, 1, 0, MPI_COMM_WORLD);
            MPI_Recv(&get[0], x, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        time_finish = MPI_Wtime();
        total_time = time_finish - time_start;
        r = (2*10*size)/total_time;
        cout<<"Capacity of two processes for message with length " << size << "is " << r;
    }
    else
    {
        int get[x];
        MPI_Recv(&get[0], x, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&get[0], x, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}