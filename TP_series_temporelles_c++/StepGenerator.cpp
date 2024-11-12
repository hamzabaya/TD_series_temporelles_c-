#include "StepGenerator.h"
#include <random>

StepGenerator::StepGenerator() {}

std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> series(size, 0.0);
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 100);
    std::bernoulli_distribution flip(0.5);

    for (int i = 1; i < size; ++i) {
        if (flip(generator)) {
            series[i] = series[i - 1];
        } else {
            series[i] = distribution(generator);
        }
    }
    return series;
}
