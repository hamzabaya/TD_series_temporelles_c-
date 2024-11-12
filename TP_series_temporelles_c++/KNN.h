#ifndef KNN_H
#define KNN_H

#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include "TimeSeriesDataset.h"

class KNN {
    int k;
    std::string distanceMetric;

    // Méthodes de distance
    double euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2) const;
    double dtwDistance(const std::vector<double>& series1, const std::vector<double>& series2) const;

public:
    KNN(int neighbors, const std::string& metric);
    int predict(const std::vector<double>& testSeries, const TimeSeriesDataset& trainData);
    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const std::vector<int>& groundTruth);
};

#endif
