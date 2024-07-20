#include <iostream>
#include <cstdlib>
using namespace std;
#include <chrono>



int main(){
    
    auto start = std::chrono::high_resolution_clock::now();


    // call_to_some_other_function()// code to be profiled
    std::cout<<"hello world of profiling"<<std::endl;


    auto end =std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed =end-start;
    std::cout<<"critical section executed in: "<< elapsed.count()<< " seconds\n";
    return 0;

}