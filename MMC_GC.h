/*
 * MMC_GC Class: Implementation of MMC_IF by
 * Guilherme Cardoso, 2018.
 * For the INE5425 course, UFSC
 */

#pragma once 

#include <cmath>
#include <cstdlib>
#include <cassert>
#include <limits>
#include <array>
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
	unsigned long xorShift64Star(unsigned long & state);
	double gammaJonk(double alpha);

private:
	bool normalFlag;
	double normalResult;
	MMC_if::RNG_Parameters rngParameters;
	const double CONSTANT_E = 2.71828182845904523536028747135266249775724709;
	const double CONSTANT_PI = 3.1415926535897932384626433832795028841971;  
	// const std::array<double, 8> = {{ 676.5203681218851
	//     ,-1259.1392167224028
	//     ,771.32342877765313
	//     ,-176.61502916214059
	//     ,12.507343278686905
	//     ,-0.13857109526572012
	//     ,9.9843695780195716e-6
	//     ,1.5056327351493116e-7
	// }};
};
