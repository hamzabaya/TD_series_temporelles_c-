#include "KNN.h"
#include <algorithm>
#include <queue>

// Constructeur de KNN
KNN::KNN(int neighbors, const std::string& metric) : k(neighbors), distanceMetric(metric) {}

// Méthode de distance euclidienne
double KNN::euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2) const {
    double distance = 0.0;
    for (size_t i = 0; i < series1.size(); ++i) {
        distance += std::pow(series1[i] - series2[i], 2);
    }
    return std::sqrt(distance);
}

// Méthode de distance DTW (Dynamic Time Warping)
double KNN::dtwDistance(const std::vector<double>& series1, const std::vector<double>& series2) const {
    size_t n = series1.size();
    size_t m = series2.size();
    std::vector<std::vector<double>> dtw(n + 1, std::vector<double>(m + 1, std::numeric_limits<double>::infinity()));
    dtw[0][0] = 0.0;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            double cost = std::pow(series1[i - 1] - series2[j - 1], 2);
            dtw[i][j] = cost + std::min({ dtw[i - 1][j], dtw[i][j - 1], dtw[i - 1][j - 1] });
        }
    }
    return std::sqrt(dtw[n][m]);
}

// Prédiction de la classe la plus proche
int KNN::predict(const std::vector<double>& testSeries, const TimeSeriesDataset& trainData) {
    std::vector<std::pair<double, int>> distances;
    const auto& trainDataSeries = trainData.getData();
    const auto& trainLabels = trainData.getLabels();

    // Calcul de la distance pour chaque série d'entraînement
    for (size_t i = 0; i < trainDataSeries.size(); ++i) {
        double distance = (distanceMetric == "euclidean_distance")
            ? euclideanDistance(testSeries, trainDataSeries[i])
            : dtwDistance(testSeries, trainDataSeries[i]);
        distances.emplace_back(distance, trainLabels[i]);
    }

    // Tri des distances
    std::sort(distances.begin(), distances.end());

    // Trouver les k plus proches voisins
    std::vector<int> nearestLabels(k);
    for (int i = 0; i < k; ++i) {
        nearestLabels[i] = distances[i].second;
    }

    // Majorité des classes des k voisins
    std::vector<int> labelCount(3, 0);  // Supposons que les labels sont 0, 1, 2
    for (int label : nearestLabels) {
        labelCount[label]++;
    }
    return std::distance(labelCount.begin(), std::max_element(labelCount.begin(), labelCount.end()));
}

// Évaluation de l'algorithme KNN
double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const std::vector<int>& groundTruth) {
    int correct = 0;
    const auto& testDataSeries = testData.getData();

    for (size_t i = 0; i < testDataSeries.size(); ++i) {
        int predictedLabel = predict(testDataSeries[i], trainData);
        if (predictedLabel == groundTruth[i]) {
            correct++;
        }
    }

    return static_cast<double>(correct) / groundTruth.size();
}
