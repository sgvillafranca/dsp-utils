#pragma once

#include <armadillo>
#include <cmath>

enum BitOrder { right_msb,
  left_msb };

// Matlab twins
arma::cx_fvec xcorr_grd(const arma::cx_fvec &x, const arma::cx_fvec &y);
arma::cx_dvec xcorr_grd(const arma::cx_dvec &x, const arma::cx_dvec &y);
arma::fvec xcorr_grd(const arma::fvec &x, const arma::fvec &y);

// Common DSP procedures
arma::cx_fvec interpolationFreq_linear(const arma::cx_fvec &H_pilot, float Dy, const arma::uvec &freq_pos, short Nu);
arma::cx_fmat interpolationTemp_linear(const arma::cx_fvec &Hest_prev, const arma::cx_fvec &Hest_post, float Dx);
arma::cx_dvec interpolationFreq_linear(const arma::cx_dvec &H_pilot, double Dy, const arma::uvec &freq_pos, short Nu);
arma::cx_dmat interpolationTemp_linear(const arma::cx_dvec &Hest_prev, const arma::cx_dvec &Hest_post, double Dx);
void frequency_offset_correction(arma::cx_fvec &signal, float CFO_Hz, float fs);
void frequency_offset_correction(arma::cx_dvec &signal, double CFO_Hz, double fs);
void phase_offset_correction(arma::cx_fvec &signal, int CFO_phase, float CFO_Hz, float fs);
void phase_offset_correction(arma::cx_dvec &signal, int CFO_phase, double CFO_Hz, double fs);
arma::fvec nearest_interp_1d(const arma::fvec &xd, const arma::fvec &yd, const arma::fvec &xi);
arma::cx_fvec nearest_interp_1d(const arma::uvec &xd, const arma::cx_fvec &yd, const arma::uvec &xi);
arma::cx_dvec fftconv(arma::cx_dvec &a, arma::cx_dvec &b);

// Precission-related functions
float kahan_sum(const arma::fvec &fa);

// Debugging functions (related to float-point precision)
arma::fmat sum_grd(const arma::fmat &x);
arma::fvec log10_grd(const arma::fvec &x);
arma::dvec element_wise_product(const arma::dvec &x, const arma::dvec &y);
