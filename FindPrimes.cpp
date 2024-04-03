#include <iostream>
#include <vector>
#include <chrono>

void sieveOfEratosthenes(int n)
{
    std::vector<bool> prime(n + 1, true);

    auto start = std::chrono::high_resolution_clock::now(); // Start time measurement

    for (int p = 2; p * p <= n; ++p)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();        // End time measurement
    std::chrono::duration<double> elapsed_seconds = end - start; // Calculate elapsed time

    std::cout << "Prime numbers up to " << n << " are:\n";
    for (int p = 2; p <= n; ++p)
        if (prime[p])
            std::cout << p << " ";
    std::cout << "\n\nExecution time: " << elapsed_seconds.count() << " seconds" << std::endl;

    std::cout << "Number entered by the user: " << n << std::endl;
}

int main()
{
    int limit;
    std::cout << "Enter the limit to find prime numbers up to: ";
    std::cin >> limit;

    sieveOfEratosthenes(limit);

    return 0;
}
