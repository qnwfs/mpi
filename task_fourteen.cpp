#include <iostream>
#include <mpi.h>
using namespace std;
int main(int argc, char **argv)
{
    int rank, size;
    string a = "a";
    double times[10];

    for(int i = 0; i < 10; i++)
    {
        times[i] = 0;
    }

    double time_start, time_finish;

        MPI_Init(&argc, &argv);
        time_start = MPI_Wtime();
        int world_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
        int world_size;
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

        if (world_rank == 0) {
            MPI_Send(&a , 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        } else if (world_rank == 1) {
            MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        time_finish = MPI_Wtime();
        MPI_Finalize();


}
