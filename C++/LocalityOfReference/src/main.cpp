#include <iostream>

#include "exampler.hpp"
#include "direct_approach.hpp"
#include "cpu_cache_approach.hpp"

int main()
{
    std::cout << "Running with updating each object separately";
    lor::Exampler<lor::DirectApproach> direct_example("Direct demo");
    direct_example.run();

    std::getchar();
    return 0;
}