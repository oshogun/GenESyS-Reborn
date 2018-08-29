#include "MMC_GC.h"
#include <iostream>
#include <ctime>
#include <array>
#include <random> 

void printUniformDistribution(MMC_GC &mmc);
void printExponentialDistribution(MMC_GC &mmc);
void printErlangDistribution(MMC_GC &mmc);
void printNormalDistribution(MMC_GC &mmc);

int main()
{
	MMC_if::RNG_Parameters param;
	std::random_device rd;
	param.seed = rd();
	MMC_GC mmc(param);

	printNormalDistribution(mmc);
}


void printNormalDistribution(MMC_GC &mmc) 
{
	const int nrolls = 10000;
	const int nstars = 100;

	int p[11] = {};

	for (int i = 0; i < nrolls; ++i) {
		double number = mmc.normal(10.0, 2);
		// std::cout << number;
		if ((number >= 0) && number < 11) ++p[int(number)];
	}

	std::cout <<"Normal distribution for mean 5.0 and sigma 2.0\n";

	for (int i = 0; i < 11; ++i) {
		std::cout << i << "-" << i+1 << ": ";
		std::cout << std::string(p[i]*nstars/nrolls,'*');
		std::cout << "\n";
	}

	std::cout << "stdlib normal distribution\n";

	std::default_random_engine generator;
  	std::normal_distribution<double> distribution(5.0,2.0);


  	int q[11] = {};
	for (int i=0; i<nrolls; ++i) {
		double number = distribution(generator);
		if ((number>=0.0)&&(number<10.0)) ++q[int(number)];
	}
  	for (int i = 0; i < 11; ++i) {
		std::cout << i << "-" << i+1 << ": ";
		std::cout << std::string(q[i]*nstars/nrolls,'*');
		std::cout << "\n";
	}
}