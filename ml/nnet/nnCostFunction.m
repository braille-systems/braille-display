% Octave compatible
% NNCOSTFUNCTION.M computes cost function and gradients for 2-layer neural network.
% Calculates J(X,y, Theta1, Theta2, lambda), dJ/d(Theta1_ij), dJ/d(Theta2_ij).
% Theta1 & Theta2 matrices are given in a single vector (nn_params)
% (single vector is convenient for optimization alg-m), and must be reshaped

function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
								  
% reshape nn_params (vector) into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));
				 
m = size(X, 1); % number of training examples

% make hypothesis (forward propagation)
X = [ones(m, 1), X]; % add bias terms to design matrix (<=> activations of 1st layer)
z2 = X * Theta1';
A2 = sigmoid(z2); % activations of second layer
m2 = size(A2, 1);
A2 = [ones(m2, 1), A2]; % add bias terms to activations of 2nd layer
z3 = A2 * Theta2';
A3 = sigmoid(z3); % activations of output layer <=> hypothesis (m x 10)

% unroll y (training output) from values in {1...num_labels} into logical arrays
range = 1:num_labels; % 1 2 3 ... 10
col = ones(size(y)); %[1 1 ... 1]'
Y = range .* col == y; %([1 ... 10; 1 ... 10; ...] == y) - logical matrix

% compute non-regularized cost function
J = Y .* log(A3) + (1 - Y) .* log(1 - A3);
J = - 1 / m * sum(sum(J));

% regularize cost function
Th1 = Theta1(:, 2:end); %exclude bias terms
Th2 = Theta2(:, 2:end);
J = J + lambda / (2 * m) * (sum(sum(Th1 .^ 2)) + sum(sum(Th2.^ 2)));

% calculate errors of node j in layer l (backpropagation)
for i = 1:m,
  a3 = A3(i,:)';
  a2 = A2(i, :)';
  a1 = X(i, :)';
  y = Y(i, :)';
  delta_3 = a3 - y;
  delta_2 = (Theta2' * delta_3) .* a2 .* (1 - a2);
  delta_2 = delta_2(2:end); %exclude bias term
  Theta2_grad = Theta2_grad + delta_3 * a2';
  Theta1_grad = Theta1_grad + delta_2 * a1';
endfor

Theta1_grad = Theta1_grad ./ m;
Theta2_grad = Theta2_grad ./ m;

% add regularization term to gradients
Theta1_grad(:, 2:end) = Theta1_grad(:, 2:end) + lambda ./ m .* Theta1(:, 2:end);
Theta2_grad(:, 2:end) = Theta2_grad(:, 2:end) + lambda ./ m .* Theta2(:, 2:end);

% unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];
