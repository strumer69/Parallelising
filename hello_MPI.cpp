#include <mpi.h>
#include <iostream>
int main(){
    std::cout << "Hello MPI?" <<std::endl;
    MPI_Init(0,0);
    // part of code that you want to parallelize
    MPI_Finalize();
    return 0;
}