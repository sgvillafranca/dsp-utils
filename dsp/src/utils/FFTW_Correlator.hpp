#pragma once
#include "sigpack/sigpack.h"

class FFTW_Correlator {
public:
  // Constructor
  FFTW_Correlator() = default;
  FFTW_Correlator(unsigned int _X_N, unsigned int _Y_N);
  // Methods
  arma::cx_dvec xcorr(const arma::cx_dvec &a, const arma::cx_dvec &b);

private:
  arma::uword N;
  arma::uword N_A;
  arma::uword N_B;
  sp::FFTW FFT;
};
