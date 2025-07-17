#include <mpi.h>
#include <iostream>
# include <sstream> //for string stream formating

int main(int argc, char *argv[]) {
    // Initialize MPI
    MPI_Init(&argc, &argv); 

    //get the total number of tasks
    int num_tasks;
    MPI_Comm_size(MPI_COMM_WORLD, &num_tasks);

    //get the task id
    int task_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &task_id); //Each process gets a unique ID (task_id), starting from 0 up to num_tasks - 1.
    

    // setup the string and print
    //(Instead of printing directly, we build the message using a stringstream.)
    std::stringstream ss; // for building string efficiently
    ss << "printing from task" << task_id << '/' << num_tasks << '\n';
    std::cout << ss.str();

    MPI_Finalize(); // Finalize MPI
    return 0;
}
