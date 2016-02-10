//This tests the MCSample class 
//Jonathan Curtis
//02/09/2016

#include "MCSample.h"
#include <iostream>

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

	double * sample = sampler.genSample();

	std::cout<<"(";
	for(int j = 0; j < i_dim; j++){
		std::cout<<sample[j]<<",";
	}
	std::cout<<")"<<std::endl;

	delete [] sample;

	return 0;
}