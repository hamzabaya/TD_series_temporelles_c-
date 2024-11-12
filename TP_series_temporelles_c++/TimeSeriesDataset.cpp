#include "TimeSeriesDataset.h"
#include <cmath>

TimeSeriesDataset::TimeSeriesDataset(bool zNorm, bool train) : znormalize(zNorm), isTrain(train) {}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    std::vector<double> normalizedSeries = series;
    if (znormalize) normalizeSeries(normalizedSeries);
    data.push_back(normalizedSeries);
    labels.push_back(label);
}

void TimeSeriesDataset::normalizeSeries(std::vector<double>& series) {
    double mean = 0.0;
    for (double val : series) mean += val;
    mean /= series.size();

    double variance = 0.0;
    for (double val : series) variance += (val - mean) * (val - mean);
    variance /= series.size();
    double stddev = sqrt(variance);

    for (double &val : series) val = (val - mean) / stddev;
}

const std::vector<std::vector<double>>& TimeSeriesDataset::getData() const { return data; }
const std::vector<int>& TimeSeriesDataset::getLabels() const { return labels; }
