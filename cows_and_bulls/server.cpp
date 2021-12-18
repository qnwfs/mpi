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
    int to_opponent, to_guess, my_guess, his_guess;
    bool flag = false;
    char port_name[MPI_MAX_PORT_NAME];
    MPI_Status status;
    MPI_Comm intercomm;
    cout << "Enter the number your opponent should guess: ";
    cin >> to_opponent;
    cout << endl;
    MPI_Open_port(MPI_INFO_NULL, port_name);
    cout << "Portname: " << port_name << endl;
    cout << "Waiting for the client....." << endl;
    MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "Server connected !" << endl;
    cout << "Server send to client: " << name_this << endl;
    MPI_Send(&to_opponent, 1, MPI_INT, 0, 0, intercomm);
    int temp_to_opponent = to_opponent;
    int length_of_my;
    while(temp_to_opponent > 0)
    {
        cout << "I am in while" << endl;
        int b = temp_to_opponent % 10;
        length_of_my += 1;
        temp_to_opponent = temp_to_opponent / 10;
    }
    int arr1[length_of_my];
    temp_to_opponent = to_opponent;
    for(int i = 0; i < length_of_my; i++)
    {
        arr1[i] = temp_to_opponent % 10;
        temp_to_opponent = temp_to_opponent / 10;
    }

    MPI_Recv(&to_guess, 1, MPI_INT, 0, 0, intercomm, &status);
    cout << "Your guess is: ";
    cin >> my_guess;
    MPI_Send(&my_guess, 1, MPI_INT, 0, 0, intercomm);
    while(flag == false)
    {
        int temp = to_opponent;
        int cows = 0;
        int bulls = 0;
        MPI_Recv(&his_guess, 1, MPI_INT, 0, 0, intercomm, &status);
        int his_guess_temp = his_guess;
        int length = 0;
        while(his_guess_temp > 0)
        {
            cout << "I am in while" << endl;
            int b = his_guess_temp % 10;
            length += 1;
            his_guess_temp = his_guess_temp / 10;
        }
        int arr[length];
        his_guess_temp = his_guess;
        for(int i = 0; i < length; i++)
        {
            arr[i] = his_guess_temp % 10;
            his_guess_temp = his_guess_temp / 10;
        }
        for(int i = 0; i < length; i++)
        {
            for(int j = 0; j < length; j++)
            {
                if(arr[i] == arr1[j]){
                    cows += 1;
                }
            }
            if(arr[i] == arr1[i]){
                bulls += 1;
            }
        }
        cout << "Number of bulls is: " << bulls << endl;
        cout << "Number of cows is" << cows << endl;
    }
    /*MPI_Send(&to_opponent, 1, MPI_INT, 0, 0, intercomm);
    MPI_Recv(&to_guess, 1, MPI_INT, 0, 0, intercomm, &status);*/
    cout << "Server received from client: " << to_guess << endl;
    MPI_Comm_free(&intercomm);
    MPI_Close_port(port_name);
    MPI_Finalize();
    return 0;
}