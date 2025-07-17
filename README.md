# Parallelising
1-in hell-world_1.cPP program you can measure the run time of your code through the termnal by : time ./your_code (a.out)

2- you also can add performance counter to your code:
by this method you can measure a special part of your code.
you can simply use (elapsed =end-start) where (start)
is the start of your critical section and the (end) is the related end.


**-hello_MPI**.cpp is the basic/simple strucure for parallelizing a typical code.
* for compiling use the following commands:
* compile: mpic++ hello_MPI.cpp -o hello ------ Run: mpirun --oversubscribe -np 4 ./hello

**2-sum.cpp** addsnumber from 1 to 10.
* to understand this part of code, simply test it once with (world_rank=0) and once with (world_rank=1). it will result in to range (1 to 5 ) and range (6 to 10)
*   int start = (world_rank * 10 / world_size) + 1;
*   int end = ((world_rank + 1) * 10 / world_size);

*   and the following line :
*       MPI_Reduce(&partial_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
*       partial_sum--> is the value, each proc wants to send (local result)
*       total_sum --> where the final result will be stored. (only valid on the root process)
*       1 -- > the number of elements to be send--> integr in this case (as next argument is MPI_INT)
*       MPI_SUM --> this tells the operation to be done is ADD , for values comming from all processors.
*       0 --> the rank of root process. (that will receive and process the whole results).
*       MPI_COMM_WORLD--> communicator which defines the group of processors participated in this reduction.

**3- tasks.cpp** -->  Understanding how multiple processes run in parallel.
* **Note**: The messages from different processes may appear in any order, since each process runs independently.
* MPI_Finalize() shuts down the MPI environment.

**4_squre_send_receive.cpp** --> send the square of the id form each task ID (example: received 9 from Rank 3 ) 
* MPI_STATUS_IGNORE -- > You say: "I don't care about who sent the message or how many items I received. Just give me the data."
* if you want to have status:
*  MPI_Status status; // Declare the variable BEFORE the function call
*  MPI_Recv(&recv , 1 , MPI_INT , i , 0 , MPI_COMM_WORLD , &status);

**5-one_dim_Poisson.cpp** --> is a simple One Dim Gause seidel iteration method to solve Poisson Equation. the results have been compared.




