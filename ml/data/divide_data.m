%Octave compatible

% separates (X,y) from 'data.mat' (made with 'make_data.m' script)
% into X_train, y_train (training set);
% X_cv, y_cv (cross-validation set);
% X_test, y_test (test set);
%and saves to data_separated.m

%constants
train_fraction = 0.6; % 60% for training set
cv_fraction = 0.2; % 20% for cross-validation set
%remainders - for test set

%loading X, y, n, m, num_labels
load("data.mat");

%randomly shuffle elements
xy = ([X y]);
xy = xy(randperm(size(X, 1)), :);
X = xy(:, 1:n);
y = xy(:, n+1);

%choose train, cross-validation, test sets
%m is a number of all examples, m = size(X,1)
m_train = floor(m * train_fraction); %number of training examples
m_cv = floor(m * cv_fraction);
X_train = X(1:m_train, :);
y_train = y(1:m_train);
X_cv = X(m_train+1:m_train+m_cv, :);
y_cv = y(m_train+1:m_train+m_cv);
X_test = X(m_train+m_cv+1:end,:);
y_test = y(m_train+m_cv+1:end);

%save data to output file 
save("data_split.mat", "X_train", "y_train", "X_test", "y_test", "X_cv", "y_cv");



