//server
#include <stdio.h>
#include "mpi.h"
#include "iostream"
using namespace std;

int main(int argc, char **argv)
{
    int r;
    MPI_Init(&argc, &argv);
    char port_name[MPI_MAX_PORT_NAME];
    MPI_Status status;
    MPI_Comm intercomm;
    int send_value = 13337;
    MPI_Open_port(MPI_INFO_NULL, port_name);
    cout << "Portname: " << port_name << endl;
    cout << "Waiting for the client....." << endl;
    MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "Server connected !" << endl;
    cout << "Server send to client: " << send_value << endl;
    MPI_Send(&send_value, 1, MPI_INT, 0, 0, intercomm);
    cout << "Server received from client: " << r << endl;
    MPI_Recv(&r, 1, MPI_INT, 0, 0, intercomm, &status);
    MPI_Comm_free(&intercomm);
    MPI_Close_port(port_name);
    MPI_Finalize();
    return 0;
}

