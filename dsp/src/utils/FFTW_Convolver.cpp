#include "FFTW_Convolver.hpp"

// Constructor
FFTW_Convolver::FFTW_Convolver(unsigned int _A_N, unsigned int _B_N) {
  N = _A_N + _B_N - 1;
  FFT = sp::FFTW(N, FFTW_ESTIMATE);
  a_padding = arma::zeros<arma::cx_dvec>(_B_N);
  b_padding = arma::zeros<arma::cx_dvec>(_A_N);
}

// Methods
arma::cx_dvec FFTW_Convolver::conv(arma::cx_dvec &a, arma::cx_dvec &b) {

  a = arma::join_vert(a, a_padding);
  b = arma::join_vert(b, b_padding);

  arma::cx_dvec A = FFT.fft_cx(a);
  arma::cx_dvec B = FFT.fft_cx(b);
  arma::cx_dvec C = A % B;

  return FFT.ifft_cx(C);
}