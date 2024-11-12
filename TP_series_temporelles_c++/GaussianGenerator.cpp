#include "GaussianGenerator.h"
#include <cmath>
#include <random>

GaussianGenerator::GaussianGenerator(double m, double s) : mean(m), stddev(s) {}

std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> series(size);
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(mean, stddev);

    for (int i = 0; i < size; ++i) {
        series[i] = distribution(generator);
    }
    return series;
}
