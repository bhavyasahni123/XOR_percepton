# XOR Neural Network in C++

A 2–2–1 feedforward neural network implemented from scratch in C++ to learn the XOR logic gate using sigmoid activation, backpropagation, and batch gradient descent.

## Network Architecture

The network consists of three layers:

- **Input layer:** 2 neurons
- **Hidden layer:** 2 neurons with sigmoid activation
- **Output layer:** 1 neuron with linear activation

The hidden layer introduces nonlinearity, allowing the network to learn the XOR mapping, which cannot be represented by a single linear decision boundary.

## Training Configuration

| Parameter | Value |
|---|---|
| Architecture | 2–2–1 |
| Hidden activation | Sigmoid |
| Output activation | Linear |
| Loss function | Sum of Squared Errors (SSE) |
| Learning method | Batch gradient descent |
| Learning rate | 0.1 |
| Stopping criterion | SSE less than 10<sup>−8</sup> |
| Classification threshold | 0.5 |

## Dataset

The network is trained on all four possible binary input combinations of the XOR logic gate.

| Input 1 | Input 2 | Target |
|---:|---:|---:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

The target is 1 when the two inputs differ and 0 when they are equal.

## Forward Propagation

Forward propagation passes the inputs through the hidden layer and then the output layer to generate a prediction.

### 1. Hidden Layer

Each hidden neuron calculates a weighted sum of the inputs and adds its bias.

**Weighted sum for hidden neuron j:**

<p align="center">
  <strong>a<sub>j</sub> = w<sub>1j</sub>x<sub>1</sub> + w<sub>2j</sub>x<sub>2</sub> + b<sub>j</sub></strong>
</p>

The sigmoid activation function transforms the weighted sum:

<p align="center">
  <strong>z<sub>j</sub> = 1 / (1 + e<sup>−a<sub>j</sub></sup>)</strong>
</p>

Here:

- x<sub>1</sub> and x<sub>2</sub> are the input values.
- w<sub>ij</sub> represents an input-to-hidden weight.
- b<sub>j</sub> is the hidden neuron's bias.
- z<sub>j</sub> is the activated output of hidden neuron j.

### 2. Output Layer

The output neuron combines the hidden-layer activations using a linear function:

<p align="center">
  <strong>y = v<sub>1</sub>z<sub>1</sub> + v<sub>2</sub>z<sub>2</sub> + b</strong>
</p>

Here, v<sub>1</sub> and v<sub>2</sub> are the hidden-to-output weights, b is the output bias, and y is the predicted output.

## Error Calculation

For training sample i, the prediction error is the target minus the predicted output:

<p align="center">
  <strong>e<sub>i</sub> = t<sub>i</sub> − y<sub>i</sub></strong>
</p>

The Sum of Squared Errors (SSE) measures the total squared prediction error across the four training samples:

<p align="center">
  <strong>SSE = Σ (t<sub>i</sub> − y<sub>i</sub>)<sup>2</sup></strong>
</p>

The summation covers i = 1, 2, 3, 4.

Training stops when the following condition is satisfied:

<p align="center">
  <strong>SSE &lt; 10<sup>−8</sup></strong>
</p>

## Backpropagation

Backpropagation calculates how the prediction error contributes to the weights and biases throughout the network.

The derivative of the sigmoid activation function is:

<p align="center">
  <strong>σ′(a<sub>j</sub>) = z<sub>j</sub>(1 − z<sub>j</sub>)</strong>
</p>

The output error is propagated backward through the output weights to calculate the hidden-layer error contributions. These contributions are then used to calculate the weight and bias updates.

## Batch Gradient Descent

The network processes all four training samples before updating its parameters.

The training procedure is:

1. Perform forward propagation for each sample.
2. Calculate the prediction errors and accumulate SSE.
3. Calculate the output-layer and hidden-layer gradient contributions.
4. Accumulate the contributions across the batch.
5. Average the accumulated contributions.
6. Update the weights and biases using the learning rate.
7. Repeat until the stopping criterion is met.

Using the error convention e<sub>i</sub> = t<sub>i</sub> − y<sub>i</sub>, the batch update for a parameter w is:

<p align="center">
  <strong>w<sub>new</sub> = w<sub>old</sub> + (n / N) Σ Δw<sub>i</sub></strong>
</p>

Here:

- n is the learning rate, set to 0.1.
- N is the batch size, set to 4.
- Δw<sub>i</sub> is the update contribution from sample i.
- The summation covers all N training samples.

The same update principle applies to weights and biases. The additive form assumes the update contributions are calculated using the target-minus-prediction error convention.

## Results

The expected XOR mapping is:

| Input | Target |
|---|---:|
| (0, 0) | 0 |
| (0, 1) | 1 |
| (1, 0) | 1 |
| (1, 1) | 0 |

The continuous output is converted into a binary prediction using a threshold of 0.5:

<p align="center">
  <strong>Predicted class = 1, if y ≥ 0.5</strong>
  <br/>
  <strong>Predicted class = 0, if y &lt; 0.5</strong>
</p>

Classification accuracy is calculated as:

<p align="center">
  <strong>Accuracy = (Correct Predictions / Total Predictions) × 100%</strong>
</p>

A 100% classification accuracy result requires all four samples to be classified correctly. The actual program output should be used to confirm this result.

## Technologies Used

- **C++** — Neural network implementation.
- **STL `vector`** — Data storage and manipulation.
- **Sigmoid activation** — Nonlinear hidden-layer transformation.
- **Backpropagation** — Gradient calculation.
- **Batch gradient descent** — Weight and bias optimization.
- **Sum of Squared Errors** — Training error measurement.

## Key Concepts Demonstrated

- Feedforward neural network architecture.
- Learning a nonlinear Boolean function.
- Forward propagation and activation functions.
- Backpropagation through a hidden layer.
- Batch gradient accumulation and parameter updates.
- Error-based stopping criteria.
- Threshold-based binary classification.

## Conclusion

This project implements a small feedforward neural network in C++ to learn the XOR logic gate. It demonstrates how nonlinear activation, backpropagation, and batch gradient descent can be used to learn a nonlinear input-output relationship without relying on an external machine learning framework.
