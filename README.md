# Parallelising
1-in hell-world_1.cPP program you can measure the run time of your code through the termnal by : time ./your_code (a.out)

2- you also can add performance counter to your code:
by this method you can measure a special part of your code.
you can simply use (elapsed =end-start) where (start)
is the start of your critical section and the (end) is the related end.


3- the hello_MPI.cpp is the basic/simple strucure for parallelizing a typical code.
* for compiling use the following commands:
* compile: mpic++ hello_MPI.cpp -o hello ------ Run: mpirun --oversubscribe -np 4 ./hello

4- the 2-sum.cpp addsnumber from 1 to 10.
* to understand this part of code, simply test it once with (world_rank=0) and once with (world_rank=1). it will result in to range (1 to 5 ) and range (6 to 10)
*   int start = (world_rank * 10 / world_size) + 1;
*   int end = ((world_rank + 1) * 10 / world_size);
