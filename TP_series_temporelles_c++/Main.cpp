#include "GaussianGenerator.h"
#include "SinWaveGenerator.h"
#include "StepGenerator.h"
#include "TimeSeriesDataset.h"
#include "KNN.h"
#include <iostream>

int main() {
    TimeSeriesDataset trainData(false, true), testData(false, false);
    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;

    trainData.addTimeSeries(gsg.generateTimeSeries(11), 0);
    trainData.addTimeSeries(gsg.generateTimeSeries(11), 0);
    trainData.addTimeSeries(swg.generateTimeSeries(11), 1);
    trainData.addTimeSeries(swg.generateTimeSeries(11), 1);
    trainData.addTimeSeries(stg.generateTimeSeries(11), 2);
    trainData.addTimeSeries(stg.generateTimeSeries(11), 2);

    std::vector<int> ground_truth;
    testData.addTimeSeries(gsg.generateTimeSeries(11), -1);
    ground_truth.push_back(0);
    testData.addTimeSeries(swg.generateTimeSeries(11), -1);
    ground_truth.push_back(1);
    testData.addTimeSeries(stg.generateTimeSeries(11), -1);
    ground_truth.push_back(2);

    KNN knn_1(1, "dtw");
    std::cout << knn_1.evaluate(trainData, testData, ground_truth) << std::endl;

    KNN knn_2(2, "euclidean_distance");
    std::cout << knn_2.evaluate(trainData, testData, ground_truth) << std::endl;

    KNN knn_3(3, "euclidean_distance");
    std::cout << knn_3.evaluate(trainData, testData, ground_truth) << std::endl;

    return 0;
}
