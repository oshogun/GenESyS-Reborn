#include "MMC_GC.h"
#include <iostream>
#include <ctime>

void printUniformDistribution(MMC_GC &mmc);
void printExponentialDistribution(MMC_GC &mmc);
void printErlangDistribution(MMC_GC &mmc);

int main()
{
	MMC_if::RNG_Parameters param;
	param.seed = (unsigned) std::time(NULL);
	MMC_GC mmc(param);
	printUniformDistribution(mmc);
	printExponentialDistribution(mmc);
    printErlangDistribution(mmc);
}

void printUniformDistribution(MMC_GC &mmc)
{
	unsigned dist[100000];
	unsigned count[10] = {0,0,0,0,0,0,0,0,0};
	for(auto i = 0; i < 100000; i++) {
		dist[i] =(unsigned) mmc.uniform(0,10);
		count[dist[i]]++;
	}
	std::cout << "Uniform distribution:\n";
	for(auto i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ": " << count[i] << "\n";
	}
}

void printExponentialDistribution(MMC_GC &mmc)
{
	unsigned dist[100000];
	unsigned count[10] = {0,0,0,0,0,0,0,0,0};
	for(auto i = 0; i < 100000; i++) {
		dist[i] =(unsigned) mmc.exponential(9.5);
		count[dist[i]]++;
	}
	std::cout << "Exponential distribution:\n";
	for(auto i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ": " << count[i] << "\n";
	}
}

void printErlangDistribution(MMC_GC &mmc)
{
    unsigned dist[100000];
	unsigned count[10] = {0,0,0,0,0,0,0,0,0};
	for(auto i = 0; i < 100000; i++) {
		dist[i] =(unsigned) mmc.erlang(9.5, 2.0);
		count[dist[i]]++;
	}
	std::cout << "Erlang distribution:\n";
	for(auto i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ": " << count[i] << "\n";
	}
}
