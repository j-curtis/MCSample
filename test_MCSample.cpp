//This tests the MCSample class 
//Jonathan Curtis
//02/09/2016

#include "MCSample.h"
#include <iostream>
#include <cmath>

double pdf(double * r){
	//We randomly select from the r < 1

	if(r[0]*r[0] + r[1]*r[1] <= 1.0){
		return 1.0/(3.1415926);
	}
	else{ return 0;}
}

int main(){
	int i_dim = 2;
	double max[2] = {1.0,1.0};
	double min[2] = {-1.0,-1.0};

	//We create an MCSampler class 
	MCSample sampler(i_dim,min,max,&pdf);

	for(int i = 0; i < 10; i++){

		double * sample = sampler.genSample();
		double d_radius2 = 0.0;

		for(int j = 0; j < i_dim; j++){
			d_radius2 += sample[j]*sample[j];
		}

		std::cout<<"d_radius: "<<std::sqrt(d_radius2)<<", "<<sample[0]<<", "<<sample[1]<<std::endl;

		delete [] sample;

	}

	return 0;
}