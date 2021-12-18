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

    if (world_rank == 0) {
        int arr1[14];
        int arr2[14];
        for(int i = 0; i < 14; i++)
        {
            arr1[i] = 1;
            arr2[i] = 1;
        }
        int k = 2;
        for(int i = 1; i < 8; i++)
        {
            MPI_Send(&arr1[i*k], k, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&arr1[i*k], k, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        /*MPI_Send(&arr1[0], 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[0], 1, MPI_INT, 1, 0, MPI_COMM_WORLD);//(&number, 1, MPI_INT, adress, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[1], 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[1], 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[2], 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[2], 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[3], 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[3], 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[4], 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[4], 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[5], 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[5], 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[6], 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[6], 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[7], 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[7], 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[8], 1, MPI_INT, 5, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[8], 1, MPI_INT, 5, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[9], 1, MPI_INT, 5, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[9], 1, MPI_INT, 5, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[10], 1, MPI_INT, 6, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[10], 1, MPI_INT, 6, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[11], 1, MPI_INT, 6, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[11], 1, MPI_INT, 6, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[12], 1, MPI_INT, 7, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[12], 1, MPI_INT, 7, 0, MPI_COMM_WORLD);
        MPI_Send(&arr1[13], 1, MPI_INT, 7, 0, MPI_COMM_WORLD);
        MPI_Send(&arr2[13], 1, MPI_INT, 7, 0, MPI_COMM_WORLD);*/
        int sum1, sum2, sum3, sum4, sum5, sum6, sum7;
        MPI_Recv(&sum1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum2, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum3, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum4, 1, MPI_INT, 4, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum5, 1, MPI_INT, 5, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum6, 1, MPI_INT, 6, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum7, 1, MPI_INT, 7, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Total sum: " << sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7;
    }
    if (world_rank == 1) {
        int a0, b0, a1, b1, sum;
        MPI_Recv(&a0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&a1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sum = a0*b0 + a1*b1;
        MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 2) {
        int a0, b0, a1, b1, sum;
        MPI_Recv(&a0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&a1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sum = a0*b0 + a1*b1;
        MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 3) {
        int a0, b0, a1, b1, sum;
        MPI_Recv(&a0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&a1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sum = a0*b0 + a1*b1;
        MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 4) {
        int a0, b0, a1, b1, sum;
        MPI_Recv(&a0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&a1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sum = a0*b0 + a1*b1;
        MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 5) {
        int a0, b0, a1, b1, sum;
        MPI_Recv(&a0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&a1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sum = a0*b0 + a1*b1;
        MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 6) {
        int a0, b0, a1, b1, sum;
        MPI_Recv(&a0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&a1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sum = a0*b0 + a1*b1;
        MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 7) {
        int a0, b0, a1, b1, sum;
        MPI_Recv(&a0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&a1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&b1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sum = a0*b0 + a1*b1;
        MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}
