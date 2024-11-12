#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>
#include <iostream>

class TimeSeriesGenerator {
protected:
    int seed;

public:
    TimeSeriesGenerator(); // Constructeur par défaut
    TimeSeriesGenerator(int seedVal); // Constructeur paramétré

    virtual ~TimeSeriesGenerator() = default;

    // Fonction virtuelle pure pour générer une série temporelle
    virtual std::vector<double> generateTimeSeries(int size) = 0;

    // Fonction statique pour imprimer la série temporelle
    static void printTimeSeries(const std::vector<double>& series);
};

#endif // TIMESERIESGENERATOR_H
