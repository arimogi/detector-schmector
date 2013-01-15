//#include "distributions.hpp"
class Distribution;
class CRandomMersenne;

class DistributionGenerator {
	CRandomMersenne * gen;
	
	protected:
	double uniform();
	
	public:
	DistributionGenerator(int seed);
	virtual double rnd() = 0;
};

class TFMDistributionGenerator : public DistributionGenerator {
	Distribution * dist;
	
	public:
	TFMDistributionGenerator(Distribution * dist, int seed);
	virtual double rnd();
};

class UniformDistributionGenerator : public DistributionGenerator {
	double width, shift;
	
	public:
	UniformDistributionGenerator(double a, double b, int seed);
	virtual double rnd();
};

class DeltaDistributionGenerator : public DistributionGenerator {
	double mean;
	
	public:
	DeltaDistributionGenerator(double x);
	virtual double rnd();
};
