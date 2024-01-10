#include <catch2/catch_all.hpp>
#include "utils/FFTW_Convolver.hpp"
#include "utils/FFTW_Correlator.hpp"
#include "utils/dsp_operations.h"

TEST_CASE("FFTW_Correlator_test") {
  // Arrange
  arma::cx_dvec a = arma::randn<arma::cx_dvec>(100);
  arma::cx_dvec b = arma::randn<arma::cx_dvec>(100);
  arma::cx_dvec c = xcorr_grd(a, b);
  // Act
  FFTW_Correlator correlator = FFTW_Correlator(a.size(), b.size());
  arma::cx_dvec c_ = correlator.xcorr(a, b);
  // Assert
  REQUIRE(approx_equal(c, c_, "absdiff", 1e-6));
}

TEST_CASE("FFTW_Correlator_test_1") {
  // Arrange
  arma::cx_dvec a = arma::randn<arma::cx_dvec>(100);
  arma::cx_dvec b = arma::randn<arma::cx_dvec>(50);
  arma::cx_dvec c = xcorr_grd(a, b);
  // Act
  FFTW_Correlator correlator = FFTW_Correlator(a.size(), b.size());
  arma::cx_dvec c_ = correlator.xcorr(a, b);
  // Assert
  REQUIRE(approx_equal(c, c_, "absdiff", 1e-6));
}

TEST_CASE("FFTW_Correlator_test_2") {
  // Arrange
  arma::cx_dvec a = arma::randn<arma::cx_dvec>(50);
  arma::cx_dvec b = arma::randn<arma::cx_dvec>(100);
  arma::cx_dvec c = xcorr_grd(a, b);
  // Act
  FFTW_Correlator correlator = FFTW_Correlator(a.size(), b.size());
  arma::cx_dvec c_ = correlator.xcorr(a, b);
  // Assert
  REQUIRE(approx_equal(c, c_, "absdiff", 1e-6));
}
