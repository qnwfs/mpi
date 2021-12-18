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
    int size = 1;
    /*for(int size = 1; size < 5; size++)
    {*/
    double time_start, time_finish, total_time, r;
    int a[size];
    time_start = MPI_Wtime();
    for(int k = 0; k < size; k++)
    {
        a[k] = 1;
    }

        if (world_rank == 0)
        {
            for(int i = 0; i <10; i++)
            {
                int get[size];
                MPI_Send(&a[0], size, MPI_INT, 1, 0, MPI_COMM_WORLD);
                MPI_Recv(&get[0], size, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
            time_finish = MPI_Wtime();
            total_time = time_finish - time_start;
            r = (2 * 10 * size) / total_time;
            cout << "Capacity of two processes for message with length " << size << "is " << r;

        }
        else {
            int get[size];
            MPI_Recv(&get[0], size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Send(&get[0], size, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }

    /*time_finish = MPI_Wtime();
    total_time = time_finish - time_start;
    r = (2*10*size)/total_time;
    cout<<"Capacity of two processes for message with length " << size << "is " << r;*/
    //}
    MPI_Finalize();

}