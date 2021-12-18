//client
#include <stdio.h>
#include "mpi.h"
#include "iostream"
#include "string.h"
using namespace std;

int main(int argc, char **argv) {
    int rank, receive;
    bool flag = true;
    string name_this;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Request request;
    char port_name[MPI_MAX_PORT_NAME];
    MPI_Comm intercomm;
    strcpy(port_name, argv[1]);
    cout << "trying to connect server" << endl;
    MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "connected to server" << endl;
    cout << "Enter your name: ";
    cin >> name_this;
    MPI_Send(name_this.c_str(), name_this.length(), MPI_CHAR, 0, 0, intercomm);
    MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &status);
    int l;
    MPI_Get_count(&status, MPI_CHAR, &l);
    char buf[l];
    MPI_Recv(&buf, l, MPI_CHAR, 0, 0, intercomm, &status);
    string name_opposite(buf, l);
    cout << "Value of name opposite is: " << name_opposite << endl;
    while(flag == true){
        cout << "We are in while ! ! !" << endl;
        int received = 0;
        string sending;
        cin >> sending;
        MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &received, &status);
        int length;
        MPI_Get_count(&status, MPI_CHAR, &length);
        cout << "Length of message received is: " << length << endl;
        char buf1[length];
        //MPI_Irecv(&buf1, length, MPI_CHAR, 0, 0, intercomm, &request);
        MPI_Recv(&buf1, l, MPI_CHAR, 0, 0, intercomm, &status);
        string message(buf1, length);
        cout << "Value of message is: " << message;
        if(message != "exit")
        {
            cout << name_opposite << ": " << message << endl;
        }
        else
        {
            flag = false;
        }
        MPI_Isend(sending.c_str(), sending.length(), MPI_CHAR, 0, 0, intercomm, &request);
    }
    MPI_Finalize();
    return 0;
}
