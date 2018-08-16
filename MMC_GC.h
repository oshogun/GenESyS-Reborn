/*
 * MMC_GC Class: Implementation of MMC_IF by
 * Guilherme Cardoso, 2018.
 * For the INE5425 course, UFSC
 */

#pragma once 

#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include "MMC_if.h"

class MMC_GC: public MMC_if {

public:
	MMC_GC(RNG_Parameters param);
public: // probability distributions
	double random();
	double uniform(double min, double max);
	double exponential(double mean);
	double erlang(double mean, int M);
	double normal(double mean, double stddev);
	double gamma(double mean, double alpha);
	double beta(double alpha, double beta, double infLimit, double supLimit);
	double weibull(double alpha, double scale);
	double logNormal(double mean, double stddev);
	double triangular(double min, double mode, double max);
	double discrete(double value, double acumProb, ...);
public:
	void setRNGparameters(RNG_Parameters param);
	MMC_if::RNG_Parameters getRNGparameters() const;

private:
	MMC_if::RNG_Parameters rngParameters;
	const double CONSTANT_E = 2.71828182845904523536028747135266249775724709;
};
