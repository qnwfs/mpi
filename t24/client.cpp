//client
#include <stdio.h>
#include "mpi.h"
#include "iostream"
using namespace std;

int main(int argc, char **argv)
{
    int rank, receive;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    char port_name[MPI_MAX_PORT_NAME];
    MPI_Comm intercomm;
    strcpy(port_name, argv[1]);
    cout << "trying to connect server" << endl;
    MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "connected to server" << endl;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Send(&rank, 1, MPI_INT, 0, 0, intercomm);
    cout << "Client send value of its rank, which equals: " << rank << endl;
    MPI_Recv(&receive, 1, MPI_INT, 0, 0, intercomm, &status);
    cout << "Client received from server value: " << receive << endl;

    MPI_Finalize();
    return 0;
}