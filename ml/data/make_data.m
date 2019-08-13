%Octave compatible

%MAKE_DATA: provides data for training classifier
%of audio records of letters in Russian alphabet.
%Makes data (X, y) for ML algorithm
%and saves to file 'data.mat'
%along with constants 'm', 'n', 'num_labels'

%constants
m_single = 20; % number of training examples (for each label from 1 to num_labels)
n = 100; % number of features in the feature vector
num_labels = 2; % 2 labels <=> 2 letters
m = m_single * num_labels; %number of training examples (overall)

%create empty design matrix
X = zeros(m, n);
%create an array of actual answers
y = zeros(m, 1);

%for each label, add m training examples (m rows) to design matrix
for lbl = 1:num_labels,
  Xi = zeros(m_single,n);
  
  %plot the training data
  figure
  hold on
  title(["rus " num2str(lbl)]); %russian letter no. 'lbl'
  
  %read data from files and convert it using convert_example
  for i = 1:m_single,
    filename = ["raw/rus_" num2str(lbl) "/" num2str(i - 1) ".wav"] ;
    Xi(i, 1:end) = convert_example(filename,n)';
    plot(Xi(i, 1:end))
  endfor
  
  X((lbl-1)*m_single + 1:lbl*m_single, :) = Xi;
  
  %map corresponding values of 'y'
  y((lbl-1)*m_single + 1:lbl*m_single) = lbl;
endfor

%save data to output file 
save("data.mat", "X", "y", "m", "n", "num_labels");