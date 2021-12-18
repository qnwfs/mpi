#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    for(int size = 1; size < 1000001; size = size * 10)
    {
        double time_start, time_finish, total_time, r;
        int a[size];
        time_start = MPI_Wtime();
        for (int i = 0; i < 10; i++)
        {
            if (world_rank == 0)
            {
                MPI_Send(&a[0], size, MPI_INT, 1, 0, MPI_COMM_WORLD);
                MPI_Recv(&a[0], size, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
            else
            {
                MPI_Recv(&a[0], size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                MPI_Send(&a[0], size, MPI_INT, 0, 0, MPI_COMM_WORLD);
            }
        }
        time_finish = MPI_Wtime();
        if(world_rank == 0)
        {
            total_time = time_finish - time_start;
            r = (2*10*size*sizeof(int))/(total_time * 1024 * 1024);
            cout << "Capacity of two processes for message with length " << size << " is " << r << endl;
        }
    }
   MPI_Finalize();
}