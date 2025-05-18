
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
    PLOGI << "Mini asteroids are starting";
    lor::Exampler<lor::DirectApproach> direct_example("Direct demo");
    direct_example.run();
    return 0;
}