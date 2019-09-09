%Octave compatible
%MAIN - computes parameters for One-VS-All logistic regression classifiers

%load X, y, m, n, num_labels
load("../data/data.mat");
%load X_train, y_train, X_cv, y_cv, X_test, y_test
load("../data/data_split.mat");

%add column of x_0^(i) to design matrices
m_train = size(X_train, 1);
m_cv = size(X_cv, 1);
m_test = size(X_test, 1);
X_train = [ones(m_train, 1) X_train];
X_cv = [ones(m_cv,1) X_cv];
X_test = [ones(m_test,1) X_test];

%initialize lin. reg. parameters
all_theta = zeros(num_labels, n + 1);
initial_theta = zeros(n + 1, 1);

%run fmincg to optimize cost functions trying different regularization parameter lambda
options = optimset('GradObj', 'on', 'MaxIter', 50);
lambda_range = [0.001, 0.003, 0.1, 0.3, 1, 3, 10, 30, 100, 300, 1000];
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
    cv_cost(k,i) = lr_cost(theta_i, X_cv, y_icv, 0);
    train_cost(k,i) = lr_cost(theta_i, X_train, y_i, 0);
	endfor
endfor

%plot cost function
figure
hold on
plot(cv_cost(:,1)')
plot(train_cost(:,1)')
legend('cv cost','train cost')
xticks(1:length(lambda_range));
xticklabels(lambda_range);
xlabel('lambda');
ylabel('cost');

%find lambda: cv_cost(:,label_idx)->min(lambda)
%(find best parameters for detecting letter no. label_idx)
label_idx = 1;
[val, lambda_idx] = min(cv_cost(:,label_idx));
lambda = lambda_range(lambda_idx);

%test performance on letter no. label_idx with found lambda
y_vs_all = y_train == label_idx;
theta = fmincg(@(t)(lr_cost(t, X_train, y_vs_all, lambda)), ...
		initial_theta, options);
		
h = sigmoid(X_test * theta);
predictions = round(h)
y_test_vs_all = y_test == 1





