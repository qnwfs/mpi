#include <iostream>
#include <mpi.h>
using namespace std;
/*MPI_Send(&arr[i], 6
MPI_Send(&arr[i*k], k)
MPI_Send(arr, k)*/
int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int array_size = 1000000;
    int k = array_size / (world_size-1);

    if (world_rank == 0) {
        int sum = 0;
        int arr1[array_size];
        int arr2[array_size];
        for(int i = 0; i < array_size; i++)
        {
            arr1[i] = 1;
            arr2[i] = 1;
        }
        for(int i = 1; i < world_size; i++)
        {
            MPI_Send(&arr1[(i-1)*k], k, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&arr2[(i-1)*k], k, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        for(int i = 1; i < world_size; i++)
        {
            int sum1;
            MPI_Recv(&sum1, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            sum += sum1;
        }
        cout << "Total sum: " << sum;
    } else
    {
        int arr1[k], arr2[k], tsum;
        tsum = 0;
        MPI_Recv(&arr1, k, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&arr2, k, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for(int i = 0; i < k; i++)
        {
            tsum += arr1[0]*arr2[0];
        }
        MPI_Send(&tsum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}
