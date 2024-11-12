#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    std::vector<double> generateTimeSeries(int size) override;
};

#endif
