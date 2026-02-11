#include <iostream>
#include <chrono>

int main() {
    std::chrono::steady_clock::time_point t_start = std::chrono::steady_clock::now();

    size_t sum = 0;
    for (int i = 1; i <= 10000; i++)
        sum += i;

    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
    size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();

    std::cout << "La somme de 1 à 10000 est " << sum << std::endl;
    std::cout << "Et cela a pris " << duration << " microsecondes." << std::endl;

    return 0;
}
