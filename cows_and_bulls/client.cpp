//client
#include <stdio.h>
#include "mpi.h"
#include "iostream"
#include "string.h"
using namespace std;

int main(int argc, char **argv) {
    int rank, receive, to_opponent, to_guess, my_guess, his_guess;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    char port_name[MPI_MAX_PORT_NAME];
    MPI_Comm intercomm;
    strcpy(port_name, argv[1]);
    cout << "trying to connect server" << endl;
    MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "connected to server" << endl;
    cout << "Enter the number your opponent need to guess: ";
    cin >> to_opponent;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Send(&to_opponent, 1, MPI_INT, 0, 0, intercomm);
    MPI_Recv(&to_guess, 1, MPI_INT, 0, 0, intercomm, &status);
    while (1)
    {
        cout << "Your guess is: ";
        cin >> my_guess;
        MPI_Send(&my_guess, 1, MPI_INT, 0, 0, intercomm);
    }
    //cout << "Client received from server value: " << to_guess << endl;

    MPI_Finalize();
    return 0;
}