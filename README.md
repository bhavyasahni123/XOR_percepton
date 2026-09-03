# XOR Neural Network

C++ implementation of a **2:2:1 feedforward neural network** trained from scratch to learn the XOR logic gate using batch gradient descent and backpropagation.

## Method

* **Architecture:** 2:2:1
* **Hidden activation:** Sigmoid
* **Output activation:** Linear
* **Loss function:** Sum of Squared Errors (SSE)
* **Learning method:** Batch gradient descent
* **Learning rate:** \(n=0.1\)
* **Stopping criterion:** \(SSE < 10^{-8}\)
* **Output threshold:** \(0.5\)

For each training sample, the network performs forward propagation through the hidden layer and linear output layer. Errors are accumulated across the complete batch, gradients are averaged, and weights are updated once per epoch.

The output threshold is applied only after training for binary classification.

## Dataset

| \(x_1\) | \(x_2\) | Target |
| ------: | ------: | -----: |
|       0 |       0 |      0 |
|       0 |       1 |      1 |
|       1 |       0 |      1 |
|       1 |       1 |      0 |

## Results

The trained network produces the XOR mapping:

| Input | Target | Prediction |
| ----- | -----: | ---------: |
| (0,0) |      0 |          0 |
| (0,1) |      1 |          1 |
| (1,0) |      1 |          1 |
| (1,1) |      0 |          0 |

**Classification accuracy: 100%**

## Technologies

* C++
* STL `vector`
* Backpropagation
* Batch Gradient Descent
* Sigmoid Activation
* SSE Loss
