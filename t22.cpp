#include "mpi.h"
#include <cstdlib>
#include "iostream"
using namespace std;

int main(int argc, char **argv) {
    int size, rank, position, i;
    float a[10];
    char b[10], buf[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    for (i = 0; i < 10; i++) {
        a[i] = rank + 1.0;
        if (rank == 0) b[i] = 'a';
        else b[i] = 'b';
    }

    cout << "Value of a for rank: " << rank << " before unpacking is: " << a[0] << " Value of b before unpacking is: " << b[0] << endl;

    position = 0;

    if (rank == 0) {
        MPI_Pack(a, 10, MPI_FLOAT, buf, 100, &position, MPI_COMM_WORLD);
        MPI_Pack(b, 10, MPI_CHAR, buf, 100, &position, MPI_COMM_WORLD);
        MPI_Bcast(buf, 100, MPI_PACKED, 0, MPI_COMM_WORLD);
    } else {
        MPI_Bcast(buf, 100, MPI_PACKED, 0, MPI_COMM_WORLD);
        position = 0;
        MPI_Unpack(buf, 100, &position, a, 10, MPI_FLOAT, MPI_COMM_WORLD);
        MPI_Unpack(buf, 100, &position, b, 10, MPI_CHAR, MPI_COMM_WORLD);
    }
    cout << "Value of a for rank: " << rank << " after unpacking is: " << a[0] << " Value of b after unpacking is: " << b[0] << endl;
    MPI_Finalize();
}