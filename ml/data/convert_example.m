%Octave compatible
function x = convert_example(filename, n)
  %CONVERT_EXAMPLE: return an n*1 feature vector
  %which corresponds to the content of audio in 'filename'
  %TODO: idea1: cut that audio where lower than a certain threshold
  %TODO: idea2: use log(x) instead of x
  %TODO: idea3: apply mean normalization
  
  % read stereo sound into array n0*2, n0 is any original length of audio
  x_raw = audioread(filename);
  
  %apply Fourier transform
  x = fft(x_raw);
  
  %separate real and imaginary part
  x_re = real(x);
  x_im = imag(x);
  
  %reduce array length + stereo->mono
  pkg load image;
  x_re = imresize(x_re, [ceil(n / 2), 1]);
  x_im = imresize(x_im, [floor(n/2), 1]);
  
  % join back real and imaginary, but as separate elements
  x = [x_re; x_im];
endfunction
