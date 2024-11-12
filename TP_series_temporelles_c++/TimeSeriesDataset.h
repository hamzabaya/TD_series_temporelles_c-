#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>

class TimeSeriesDataset {
    bool znormalize;
    bool isTrain;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    int maxLength;
public:
    TimeSeriesDataset(bool zNorm, bool train);
    void addTimeSeries(const std::vector<double>& series, int label);
    void normalizeSeries(std::vector<double>& series);
    const std::vector<std::vector<double>>& getData() const;
    const std::vector<int>& getLabels() const;
};

#endif
