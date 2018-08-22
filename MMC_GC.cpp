#include "MMC_GC.h"


// TODO: use a proprer RNG algorithm, using rand() as placeholder

MMC_GC::MMC_GC(RNG_Parameters param):rngParameters(param),
normalFlag(true), normalResult(0)
{
	unsigned long rngSeed = rngParameters.seed;
	std::srand(rngSeed);
}

// TODO: this is a PLACEHOLDER and must be replaced with a proper random.

double MMC_GC::random() 
{
	return (double)std::rand() / (double) RAND_MAX;
}

// TODO TEST
double MMC_GC::uniform(double min, double max)
{
	if (min < 0 || max < 0) {
		throw std::runtime_error("Incorrect parameters for MMC_GC::uniform");
	} else {
		return min + (max - min) * random(); 
	}
}

//TODO TEST
double MMC_GC::exponential(double mean)
{
	if (mean >= 0) {
		return mean * std::exp( (- mean) * random());
	} else {
		throw std::runtime_error("Incorrect parameters for MMC_GC::exponential");
	}
}
// TODO TEST
double MMC_GC::erlang(double mean, int M)
{
    if (mean < 0 || M <= 0) {
        throw std::runtime_error("Incorrect parameters for MMC_GC::erlang");  

    } else {
        double P = 1;
        for(auto i = 0; i < M; i++) {
            P*= random();
        }
        return (double) (mean / M) * (- std::log(P));
    }
}
// TODO TEST
double MMC_GC::normal(double mean, double stddev)
{
	if (mean <= 0 or stddev <= 0) {
        throw std::runtime_error("Incorrect parameters for MMC_GC::normal");
    } else {
    	double U1, U2, W, Y, result;
    	if (normalFlag) {
    		while (W >= 1) {
    			U1 = 2 * random() - 1;
    			U2 = 2 * random() - 1;
    			W = U1 * U1 + U2 * U2;
    		}
    		Y = std::sqrt((- 2 * std::log(W)) / W);
    		result = mean * U1 * Y * stddev;
    		normalResult = mean * U2 * Y * stddev;
    		normalFlag = false;
    	} else {
    		result = normalResult;
    		normalFlag = true;
    	}
    }
    return result;
}
// TODO
double MMC_GC::gamma(double mean, double alpha)
{
	return -1;
}
// TODO
double MMC_GC::beta(double alpha, double beta, double infLimit, double supLimit)
{
	return -1;
}
// TODO
double MMC_GC::weibull(double alpha, double scale)
{
	return -1;
}
// TODO
double MMC_GC::logNormal(double mean, double stddev)
{
	return -1;
}
// TODO
double MMC_GC::triangular(double min, double mode, double max)
{
	return -1;
}
// TODO
double MMC_GC::discrete(double value, double acumProb, ...)
{
	return -1;
}

void MMC_GC::setRNGparameters(RNG_Parameters param)
{
	rngParameters = param;
}

MMC_if::RNG_Parameters MMC_GC::getRNGparameters() const 
{
	return rngParameters;
}
