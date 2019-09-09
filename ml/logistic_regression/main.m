%Octave compatible
%MAIN - computes parameters for One-VS-All logistic regression classifiers

%load X, y, m, n, num_labels
load("../data/data.mat");
%load X_train, y_train, X_cv, y_cv, X_test, y_test
load("../data/data_split.mat");

%add column of x_0^(i) to design matrices
m_train = size(X_train, 1);
m_cv = size(X_cv, 1);
X_train = [ones(m_train, 1) X_train];
X_cv = [ones(m_cv,1) X_cv];

%initialize lin. reg. parameters
all_theta = zeros(num_labels, n + 1);
initial_theta = zeros(n + 1, 1);

%run fmincg to optimize cost functions trying different regularization parameter lambda
options = optimset('GradObj', 'on', 'MaxIter', 50);
lambda_range = [0.001, 0.003, 0.1, 0.3, 1];
cv_cost = zeros(length(lambda_range), num_labels);
train_cost = zeros(length(lambda_range), num_labels);

for k = 1:length(lambda_range),
	lambda = lambda_range(k);
	for i = 1:num_labels,
		y_i = y_train == i;
		[theta_i] = fmincg(@(t)(lr_cost(t, X_train, y_i, lambda)), ...
		initial_theta, options);
		all_theta(i,:) = theta_i';
    
    %compute cross-validation cost, training cost
    y_icv = y_cv == i;
    cv_cost(k,i) = lr_cost(theta_i, X_cv, y_cv, 0);
    train_cost(k,i) = lr_cost(theta_i, X_train, y_train, 0);
	endfor
endfor

%plot cost function
figure
hold on
plot(cv_cost(:,1)')
plot(train_cost(:,1)')
legend('cv cost','train cost')





