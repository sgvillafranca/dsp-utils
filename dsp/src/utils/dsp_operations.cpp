#include "utils/dsp_operations.h"

arma::cx_fvec xcorr_grd(const arma::cx_fvec &x, const arma::cx_fvec &y) {
  arma::cx_fvec r;
  if (x.n_elem == y.n_elem) {
    r = arma::conv(x, arma::conj(arma::reverse(y)));
  } else {
    // Shortest is zero-padded
    if (x.n_elem < y.n_elem) {
      arma::cx_fvec x_padded = arma::join_vert(x, arma::zeros<arma::cx_fvec>(y.n_elem - x.n_elem));
      r = arma::conv(x_padded, arma::conj(arma::reverse(y)));
    } else {
      arma::cx_fvec y_padded = arma::join_vert(y, arma::zeros<arma::cx_fvec>(x.n_elem - y.n_elem));
      r = arma::conv(x, arma::conj(arma::reverse(y_padded)));
    }
  }
  return r;
}
arma::cx_dvec xcorr_grd(const arma::cx_dvec &x, const arma::cx_dvec &y) {
  arma::cx_dvec r;
  if (x.n_elem == y.n_elem) {
    r = arma::conv(x, arma::conj(arma::reverse(y)));
  } else {
    // Shortest is zero-padded
    if (x.n_elem < y.n_elem) {
      arma::cx_dvec x_padded = arma::join_vert(x, arma::zeros<arma::cx_dvec>(y.n_elem - x.n_elem));
      r = arma::conv(x_padded, arma::conj(arma::reverse(y)));
    } else {
      arma::cx_dvec y_padded = arma::join_vert(y, arma::zeros<arma::cx_dvec>(x.n_elem - y.n_elem));
      r = arma::conv(x, arma::conj(arma::reverse(y_padded)));
    }
  }
  return r;
}
arma::fvec xcorr_grd(const arma::fvec &x, const arma::fvec &y) {
  arma::fvec r;
  if (x.n_elem == y.n_elem) {
    r = arma::conv(x, arma::reverse(y));
  } else {
    // Shortest is zero-padded
    if (x.n_elem < y.n_elem) {
      arma::fvec x_padded = arma::join_vert(x, arma::zeros<arma::fvec>(y.n_elem - x.n_elem));
      r = arma::conv(x_padded, arma::reverse(y));
    } else {
      arma::fvec y_padded = arma::join_vert(y, arma::zeros<arma::fvec>(x.n_elem - y.n_elem));
      r = arma::conv(x, arma::reverse(y_padded));
    }
  }
  return r;
}