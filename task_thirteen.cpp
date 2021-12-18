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

    int array_size = 7;
    int number1[array_size];
    int number2[array_size];

    int w = array_size / 7;

    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    int sum5 = 0;
    int sum6 = 0;
    int sum7 = 0;

    for(int i = 0; i < array_size; i++)
    {
        number1[i] = 1;
        number2[i] = 1;
    }

    int d1;
    int u1;
    int d2;
    int u2;
    int d3;
    int u3;
    int d4;
    int u4;
    int d5;
    int u5;
    int d6;
    int u6;

    if (world_rank == 0) {
        int d1 = w;
        int u1 = 2 * w;
        int d2 = u1;
        int u2 = u1 +w ;
        int d3 = u2;
        int u3 = u2 + w;
        int d4 = u3;
        int u4 = u3 + w;
        int d5 = u4;
        int u5 = u4 + w;
        int d6 = u5;
        int u6 = u5 + w;
        MPI_Send(&w, 1, MPI_INT, 1, 0, MPI_COMM_WORLD); //(&number, 1, MPI_INT, adress, 0, MPI_COMM_WORLD);
        MPI_Send(&d1, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        MPI_Send(&u1, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        MPI_Send(&d2, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        MPI_Send(&u2, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        MPI_Send(&d3, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
        MPI_Send(&u3, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
        MPI_Send(&d4, 1, MPI_INT, 5, 0, MPI_COMM_WORLD);
        MPI_Send(&u4, 1, MPI_INT, 5, 0, MPI_COMM_WORLD);
        MPI_Send(&d5, 1, MPI_INT, 6, 0, MPI_COMM_WORLD);
        MPI_Send(&u5, 1, MPI_INT, 6, 0, MPI_COMM_WORLD);
        MPI_Send(&d6, 1, MPI_INT, 7, 0, MPI_COMM_WORLD);
        MPI_Send(&u6, 1, MPI_INT, 7, 0, MPI_COMM_WORLD);
        //cout << "Total before: " << sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7;
        MPI_Recv(&sum1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum2, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum3, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum4, 1, MPI_INT, 4, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum5, 1, MPI_INT, 5, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum6, 1, MPI_INT, 6, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sum7, 1, MPI_INT, 7, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Total after: " << sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7;
    }
    if (world_rank == 1) {
        MPI_Recv(&w, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for(int i = 0; i < w; i++)
        {
            sum1 += number1[i] * number2[i];
        }
        //cout << "Process one made sum of 4 elements" << sum1;
        MPI_Send(&sum1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 2) {
        MPI_Recv(&d1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&u1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for(int i = d1; i < u1; i++)
        {
            sum2 += number1[i] * number2[i];
        }
        //cout << "Process two made sum of 4 elements" << sum2;
        MPI_Send(&sum2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 3) {
        MPI_Recv(&d2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&u2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for(int i = d2; i < u2; i++)
        {
            sum3 += number1[i] * number2[i];
        }
        //cout << "Process three made sum of 4 elements" << sum3;
        MPI_Send(&sum3, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 4) {
        MPI_Recv(&d3, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&u3, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for(int i = d3; i < u3; i++)
        {
            sum4 += number1[i] * number2[i];
        }
        //cout << "Process four made sum of 4 elements" << sum4;
        MPI_Send(&sum4, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 5) {
        MPI_Recv(&d4, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&u4, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for(int i = d4; i < u4; i++)
        {
            sum5 += number1[i] * number2[i];
        }
        //cout << "Process five made sum of 4 elements" << sum5;
        MPI_Send(&sum5, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 6) {
        MPI_Recv(&d5, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&u5, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for(int i = d5; i < u5; i++)
        {
            sum6 += number1[i] * number2[i];
        }
        //cout << "Process six made sum of 4 elements" << sum6;
        MPI_Send(&sum6, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (world_rank == 7) {
        MPI_Recv(&d6, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&u6, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for(int i = d6; i < u6; i++)
        {
            sum7 += number1[i] * number2[i];
        }
        //cout << "Process seven made sum of 4 elements" << sum7;
        MPI_Send(&sum7, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}