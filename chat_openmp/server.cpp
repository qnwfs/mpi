//server
#include <stdio.h>
#include "mpi.h"
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char **argv)
{
    int r;
    char name_this, name_opposite;
    MPI_Init(&argc, &argv);
    char port_name[MPI_MAX_PORT_NAME];
    MPI_Status status;
    MPI_Comm intercomm;
    cout << "Enter your name: ";
    cin >> name_this;
    cout << endl;
    int send_value = 13337;
    MPI_Open_port(MPI_INFO_NULL, port_name);
    cout << "Portname: " << port_name << endl;
    cout << "Waiting for the client....." << endl;
    MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "Server connected !" << endl;
    cout << "Server send to client: " << send_value << endl;
    MPI_Send(&send_value, 1, MPI_INT, 0, 0, intercomm);
    MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &status);
    int l;
    MPI_Get_count(&status, MPI_CHAR, &l);
    cout << "Size of message is: " << l;
    char buf[l];
    MPI_Recv(&buf, l, MPI_CHAR, 0, 0, intercomm, &status);
    string bla1(buf, l);
    cout << "Server received from client: " << bla1 << endl;
    MPI_Comm_free(&intercomm);
    MPI_Close_port(port_name);
    MPI_Finalize();
    return 0;
}


