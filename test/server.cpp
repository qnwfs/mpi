//server
#include <stdio.h>
#include "mpi.h"
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char **argv)
{
    int r;
    string sending;
    MPI_Init(&argc, &argv);
    char port_name[MPI_MAX_PORT_NAME];
    MPI_Status status;
    MPI_Request request;
    MPI_Comm intercomm;
    MPI_Open_port(MPI_INFO_NULL, port_name);
    cout << "Portname: " << port_name << endl;
    cout << "Waiting for the client....." << endl;
    MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "Server connected !" << endl;
    cout << "Enter the string: " << endl;
    cin >> sending;
    MPI_Send(sending.c_str(), sending.length(), MPI_CHAR, 0, 0, intercomm);
    cout << "Server send to client: " << sending << endl;
    //MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &status);
    int received;
    MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &received, &status);
    while(1) {
        if (received == 1) {
            int l;
            MPI_Get_count(&status, MPI_CHAR, &l);
            char buf[l];
            //MPI_Irecv(&buf, l, MPI_CHAR, 0, 0, intercomm, &request);
            MPI_Recv(&buf, l, MPI_CHAR, 0, 0, intercomm, &status);
            string receiving(buf, l);
            cout << "Server received from client: " << receiving << endl;
        }
    }
    MPI_Comm_free(&intercomm);
    MPI_Close_port(port_name);

    MPI_Finalize();
    return 0;
}

