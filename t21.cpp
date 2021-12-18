#include "mpi.h"
#include <cstdlib>
#include "iostream"
using namespace std;

int main(int argc, char **argv)
{
    int rank, size, rank1;
    MPI_Init(&argc, &argv);
    MPI_Comm comm_revs;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_split(MPI_COMM_WORLD, rank % 2, size-rank,&comm_revs);
    MPI_Comm_rank(comm_revs, &rank1);
    cout << "Rank with value: " << rank << "Became rank1 with value: " << rank1 << endl;
    MPI_Comm_free(&comm_revs);
    MPI_Finalize();
}