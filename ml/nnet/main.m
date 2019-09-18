% Octave compatible

% MAIN.M 
% trains a 2-layer neural network (1 input + 1 hidden, not counting 1 output)
% using training data
% then computes optimal parameters using CV data
% then checks performance on test data

%load X, y, m, n, num_labels
load("../data/data.mat");
%load X_train, y_train, X_cv, y_cv, X_test, y_test
load("../data/data_split.mat");

input_layer_size  = n;  % input layer size <=> length of parameters vector
hidden_layer_size = 25;   % 25 hidden units

 