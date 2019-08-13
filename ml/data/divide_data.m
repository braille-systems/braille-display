%Octave compatible

% separates (X,y) from 'data.mat' (made with 'make_data.m' script)
% into X_train, y_train (training set);
% X_cv, y_cv (cross-validation set);
% X_test, y_test (test set);
%and saves to data_separated.m

%constants
test_fraction = 0.6; % 60% for training set
cv_fraction = 0.2; % 20% for cross-validation set
%remainders - for test set

%loading X, y, n, m, num_labels
load("data.mat");

%randomly shuffle elements
xy = ([X y]);
xy = xy(randperm(size(x, 1)), :);
X = xy(:, 1:n);
y = xy(:, n+1);

%choose test set

