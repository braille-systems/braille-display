%Octave compatible

function [J, grad] = lr_cost(theta, X, y, lambda)
%LR_COST - computes cost function for logistic regression
%X is design matrix
%y(i) is 1 if X(i) belongs to positive class, 0 - negative
%theta is a vector of regression's parameters
%lambda is a regularization parameter

m = length(y); % number of training examples

h = sigmoid(X* theta); %hypothesis

%compute cost function
J = -1./m  * sum(y .* log(h) + (1-y) .* log(1-h)); %not regularized
J = J + lambda / (2 * m) * sum(theta(2:end).^2); %add regularization term

%compute gradient
grad = 1./m .* X'*(h-y); %not regularized 
grad(2:end) = grad(2:end) + lambda / m .* theta(2:end);
end
