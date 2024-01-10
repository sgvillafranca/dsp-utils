#pragma once
#include "sigpack/sigpack.h"

class FFTW_Convolver {
public:
  // Constructor
  FFTW_Convolver() = default;
  FFTW_Convolver(unsigned int _X_N, unsigned int _Y_N);
  // Methods
  arma::cx_dvec conv(arma::cx_dvec &a, arma::cx_dvec &b);

private:
  arma::uword N;
  sp::FFTW FFT;
  arma::cx_dvec a_padding;
  arma::cx_dvec b_padding;
};
