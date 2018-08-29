#include "MMC_GC.h"

MMC_GC::MMC_GC(RNG_Parameters param):rngParameters(param),
normalFlag(false), normalResult(0.0)
{
    srand(time(NULL));
}

/**
 *      /brief C++ implementation of Marsaglia's Xorshift* algorithm.
 *
 * C++ implementation of Marsaglia's Xorshift* algorithm, 
 * which is based on a series of bitwise xor and shift operations,
 * plus an invertible multiplication by the magic number 
 * 0x2545F4914F6CDD1D. This algorithm only fails the MatrixRank 
 * test of BigCrush.
 * The disatvantage is that the multiplication operation is slow. 
 * Another disatvantage is that the seed must be a nonzero value.
 * The original C algorithm for xorShift64Star can be found at
 * http://www.jstatsoft.org/v08/i14/paper
 * 
 *      /param state the current seed of the algorithm
 *      /return the generated number
**/
unsigned long MMC_GC::xorShift64Star(unsigned long & state)
{   
    assert(state != 0); // seed must be a nonzero value
    unsigned long x = state; 
    x ^= x >> 12; // first xorshift
    x ^= x << 25; // second xorshift
    x ^= x >> 27; // third xorshift

    state = x;
    return x * 0x2545F4914F6CDD1D; // invertible multiplication
    
}


double MMC_GC::random() 
{
	return std::rand() * (1.0 / RAND_MAX);
}

// TODO TEST
double MMC_GC::uniform(double min, double max)
{
	assert(min >= 0 && max >= 0);
	return min + (max - min) * random();       
}

//TODO TEST
double MMC_GC::exponential(double mean)
{
	assert(mean >= 0);
	return mean * std::exp( (- mean) * random());
}
// TODO TEST
double MMC_GC::erlang(double mean, int M)
{
    assert(!(mean < 0 || M <= 0));
    
    double P = 1;
    for(auto i = 0; i < M; i++) {
        P*= random();
    }
    return (double) (mean / M) * (- std::log(P));
}

// Normal distribution using the Box-Muller transform
double MMC_GC::normal(double mean, double stddev)
{   
    assert(mean > 0 && stddev > 0);
     double result, u1, u2, w, y;
    if (normalFlag) {
        do {
            u1 = 2 * random()  - 1.0;
            u2 = 2 * random()  - 1.0;
            w = u1 * u1 + u2 * u2;
        } while (w >= 1.0);
        y = sqrt((-2 * log(w)) / 2);
        result = mean * u1 * y * stddev;
        normalResult = mean * u2 * y * stddev;
        normalFlag = false;
    } else {
        result = normalResult;
        normalFlag = true;
    }
    return result;
}



double MMC_GC::gamma(double mean, double alpha)
{
    
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
