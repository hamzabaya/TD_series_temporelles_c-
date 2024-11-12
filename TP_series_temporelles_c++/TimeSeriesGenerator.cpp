#include "TimeSeriesGenerator.h"

// Constructeur par défaut
TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

// Constructeur paramétré
TimeSeriesGenerator::TimeSeriesGenerator(int seedVal) : seed(seedVal) {}

// Fonction pour imprimer la série temporelle
void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& series) {
    for (double value : series) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
