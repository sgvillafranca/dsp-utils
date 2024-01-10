#include "FFTW_Correlator.hpp"

// Constructor
FFTW_Correlator::FFTW_Correlator(unsigned int _A_N, unsigned int _B_N) {
  if (_A_N < _B_N) {
    N = _B_N + _A_N + (_B_N - _A_N) - 1;
  } else {
    N = 2 * _A_N - 1;
  }
  N_A = _A_N;
  N_B = _B_N;
  FFT = sp::FFTW(N, FFTW_ESTIMATE);
}

arma::cx_dvec FFTW_Correlator::xcorr(const arma::cx_dvec &a, const arma::cx_dvec &b) {
  arma::cx_dvec a_;
  arma::cx_dvec b_;
  if (a.n_elem < b.n_elem) {
    a_ = arma::join_vert(arma::zeros<arma::cx_dvec>(N_B - 1), a, arma::zeros<arma::cx_dvec>(N_B - N_A));
    b_ = arma::join_vert(b, arma::zeros<arma::cx_dvec>(N_B - 1));
  } else {
    a_ = arma::join_vert(arma::zeros<arma::cx_dvec>(N_A - 1), a);
    b_ = arma::join_vert(b, arma::zeros<arma::cx_dvec>(N_A - N_B + N_A - 1));
  }
  arma::cx_dvec A = FFT.fft_cx(a_);
  arma::cx_dvec B = FFT.fft_cx(b_);
  arma::cx_dvec C = A % arma::conj(B);
  return FFT.ifft_cx(C);
}