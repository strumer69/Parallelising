#include <mpi.h>
#include <iostream>


//Main function that takes command-line arguments. These are required for MPI initialization.
int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);  // Initializes the MPI environment. This must be called before any other MPI functions.

    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size); // Get total number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); // Get rank of the process

    std::cout << "Hello from process " << world_rank << " out of " << world_size << " processes\n";

    MPI_Finalize(); // Finalize MPI
    return 0;
}
