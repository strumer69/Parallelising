#include <mpi.h>
#include <iostream>
# include <sstream>

int main(int argc, char *argv[]) {
    // Initialize MPI
    MPI_Init(&argc, &argv); 

    //get the task id
    int task_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &task_id);

    //rank 0 coordinates the work
    if(task_id ==0){
        std::cout << "Im here ----------------"  <<'\n';

        //get the total number of tasks
        int num_tasks;
        MPI_Comm_size(MPI_COMM_WORLD, &num_tasks);

        //send an integer to each thread
        for (int i=1; i < num_tasks; i++){
            MPI_Send (&i,1 , MPI_INT , i, 0 , MPI_COMM_WORLD);
        }

        //Receive and integer back from each thread
        for (int i = 1; i <num_tasks; i++){
            int recv;
            MPI_Recv(&recv , 1 , MPI_INT , i , 0 , MPI_COMM_WORLD , MPI_STATUS_IGNORE);
            //You say: "I don't care about who sent the message or how many items I received. Just give me the data."

        

            //print the received value
            std::cout << "Received " << recv << " from --rank " << i <<'\n';
        }
    } else {
        //receive an integer from rank 0
          int recv;
          MPI_Recv( &recv ,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

          //Square the value
          recv *= recv;
          std::cout << "recv== " << recv  <<'\n';


         // send the squared value back to rank 0
         MPI_Send(&recv,1,MPI_INT,0,0,MPI_COMM_WORLD);
    }

    //finish our mpi work
    MPI_Finalize();
    return 0;
}
// mpirun --oversubscribe -np 4 ./name