#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double threshold(double x) {
    return (x >= 0.5) ? 1.0 : 0.0;
}

int main() {
    vector<vector<double>> X = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };

    vector<double> y = {0, 1, 1, 0};

    double w11 = 0.1, w12 = -0.2;
    double w21 = 0.3, w22 = -0.1;
    double w01 = 0.1, w02 = -0.1;

    double v13 = 0.3, v23 = -0.4;
    double v0 = 0.2;

    double n = 0.1;

    cout << fixed << setprecision(4);

    for (int epoch = 0; epoch < 100000; epoch++) {
        double SSE = 0;

        double dw11 = 0, dw12 = 0;
        double dw21 = 0, dw22 = 0;
        double dw01 = 0, dw02 = 0;
        double dv13 = 0, dv23 = 0, dv0 = 0;

        for (int i = 0; i < X.size(); i++) {
            double a1 = w11 * X[i][0] + w21 * X[i][1] + w01;
            double a2 = w12 * X[i][0] + w22 * X[i][1] + w02;

            double z1 = sigmoid(a1);
            double z2 = sigmoid(a2);

            double a3 = v13 * z1 + v23 * z2 + v0;
            double y_hat = a3;

            double error = y[i] - y_hat;

            SSE += error * error;

            double delta1 = error * v13 * z1 * (1 - z1);
            double delta2 = error * v23 * z2 * (1 - z2);

            dw11 += delta1 * X[i][0];
            dw21 += delta1 * X[i][1];
            dw01 += delta1;

            dw12 += delta2 * X[i][0];
            dw22 += delta2 * X[i][1];
            dw02 += delta2;

            dv13 += error * z1;
            dv23 += error * z2;
            dv0 += error;
        }

        int N = X.size();

        w11 += n * dw11 / N;
        w12 += n * dw12 / N;
        w21 += n * dw21 / N;
        w22 += n * dw22 / N;

        w01 += n * dw01 / N;
        w02 += n * dw02 / N;

        v13 += n * dv13 / N;
        v23 += n * dv23 / N;
        v0 += n * dv0 / N;

        cout << "Epoch: " << epoch
             << " | SSE: " << SSE << '\n';

        if (SSE < 0.00000001)
            break;
    }

    cout << "\nFinal Weights:\n";

    cout << "w11: " << w11
         << ", w12: " << w12
         << ", w21: " << w21
         << ", w22: " << w22 << '\n';

    cout << "w01: " << w01
         << ", w02: " << w02 << '\n';

    cout << "\nFinal Output Weights:\n";

    cout << "v13: " << v13
         << ", v23: " << v23
         << ", v0: " << v0 << '\n';

    cout << "\nPredictions:\n";

    for (int i = 0; i < X.size(); i++) {
        double a1 = w11 * X[i][0] + w21 * X[i][1] + w01;
        double a2 = w12 * X[i][0] + w22 * X[i][1] + w02;

        double z1 = sigmoid(a1);
        double z2 = sigmoid(a2);

        double a3 = v13 * z1 + v23 * z2 + v0;

        double prediction = threshold(a3);

        cout << X[i][0] << " "
             << X[i][1] << " -> "
             << prediction << '\n';
    }

    return 0;
}