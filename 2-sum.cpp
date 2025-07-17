#include <mpi.h>
#include <iostream>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);  // Initialize MPI

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); // Get rank of the process
    MPI_Comm_size(MPI_COMM_WORLD, &world_size); // Get total number of processes

    // Define the range of numbers
    int start = (world_rank * 10 / world_size) + 1;
    int end = ((world_rank + 1) * 10 / world_size);

    // Each process computes its partial sum
    int partial_sum = 0;
    for (int i = start; i <= end; ++i) {
        partial_sum += i;
    }

    std::cout << "Process " << world_rank << " computed partial sum = " << partial_sum << "\n";

    // Reduce all partial sums into the total sum
    int total_sum = 0;
    MPI_Reduce(&partial_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Only rank 0 prints the final result
    if (world_rank == 0) {
        std::cout << "Total sum from 1 to 10 = " << total_sum << "\n";
    }

    MPI_Finalize();  // Finalize MPI
    return 0;
}
//mpic++ 2-sum.cpp -o sum
// mpirun --oversubscribe -np 4 ./sum