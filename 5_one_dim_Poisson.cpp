#include <iostream>
#include <iomanip> // For formatted output

int main() {
    const int N = 11;    // Total number of points (including boundaries)
    const double h = 0.1;  // Grid spacing
    const double h2 = h * h; // h^2 value for convenience
    double u[N] = {0};  // Array to hold solution, initialized to zero

    // Boundary conditions
    u[0] = 0;
    u[N-1] = 0;

    // Gauss-Seidel iterations
    for (int iter = 1; iter <= 100; ++iter) {
        std::cout << "Iteration " << iter << ":\n";

        // Gauss-Seidel Update
        for (int i = 1; i < N-1; ++i) {
            u[i] = (u[i-1] + u[i+1] + h2) / 2.0;
        }

        // Display results for the current iteration
        for (int i = 0; i < N; ++i) {
            std::cout << "u[" << i << "] = " << std::fixed << std::setprecision(6) << u[i] << "\n";
        }
        std::cout << "-----------------------------------\n";
    }

    // Exact solution values for comparison
    std::cout << "Exact Solution:\n";
    for (int i = 0; i < N; ++i) {
        double x = i * h;
        double exact = x * (1 - x) / 2.0;
        std::cout << "u_exact[" << i << "] = " << std::fixed << std::setprecision(6) << exact << "\n";
    }

    return 0;
}

//g++ 5_one_dim_Poisson.cpp -o 5_one_dim_Poisson
//./5_one_dim_Poisson
