//client
#include <stdio.h>
#include "mpi.h"
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char **argv)
{
    int rank, receive;
    string sending;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Request request;
    char port_name[MPI_MAX_PORT_NAME];
    MPI_Comm intercomm;
    strcpy(port_name, argv[1]);
    cout << "trying to connect server" << endl;
    MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "connected to server" << endl;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    cout << "Enter the string: " << endl;
    cin >> sending;
    MPI_Send(sending.c_str(), sending.length(), MPI_CHAR, 0, 0, intercomm);
    cout << "Client send to server: " << sending << endl;
    //MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &status);
    int received;
    MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &received, &status);
    while(1)
    {
        if(received == 1)
        {
            int l;
            MPI_Get_count(&status, MPI_CHAR, &l);
            char buf[l];
            //MPI_Irecv(&buf, l, MPI_CHAR, 0, 0, intercomm, &request);
            MPI_Recv(&buf, l, MPI_CHAR, 0, 0, intercomm, &status);
            string receiving(buf, l);
            cout << "Client received from server: " << receiving << endl;
        }
    }
    MPI_Comm_free(&intercomm);
    MPI_Close_port(port_name);

    MPI_Finalize();
    return 0;
}