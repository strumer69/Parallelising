#include <mpi.h>
#include <iostream>
# include <sstream>

int main(int argc, char *argv[]) {
    // Initialize MPI
    MPI_Init(&argc, &argv); 

    //get the total number of tasks
    int num_tasks;
    MPI_Comm_size(MPI_COMM_WORLD, &num_tasks);

    //get the task id
    int task_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &task_id);
    

    // setup the string and print
    std::stringstream ss;
    ss << "printing from task" << task_id << '/' << num_tasks << '\n';
    std::cout << ss.str();

    MPI_Finalize(); // Finalize MPI
    return 0;
}