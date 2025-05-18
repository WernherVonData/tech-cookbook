
#include <plog/Init.h>
#include <plog/Log.h> // Include Plog
#include <plog/Appenders/ConsoleAppender.h>
#include <plog/Formatters/TxtFormatter.h>

#include "exampler.hpp"
#include "direct_approach.hpp"
#include "cpu_cache_approach.hpp"

int main()
{
    static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);
    lor::Exampler<lor::DirectApproach> direct_example("Direct demo");
    direct_example.run();
    lor::Exampler<lor::CpuCacheApproach> cpu_cache_example("CPU Cache Demo");
    cpu_cache_example.run();

    return 0;
}