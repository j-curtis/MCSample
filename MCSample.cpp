//This is C++ code for generation of a multivariate MC sample 
//Jonathan Curtis
//02/09/2016

#include "MCSample.h"


//This just generates a float in the given range, given an integer (randomly generated)
double MCSample::getRandomInRange(double d_lower,double d_upper){
	//We first compute rand/RANDMAX as a double 
	int i_rand = std::rand();

	double d_ratio = double(i_rand)/double(RAND_MAX);

	return d_lower + (d_upper - d_lower)*d_ratio;
}

//Constructor
MCSample::MCSample(int i_dim,double* pd_lower,double* pd_upper,double (*pF_func)(double*) ){
	//First we store the attributes 
	i_dimension = i_dim;	

	//Now we allocate the arrays for the sample space size 
	pd_lower_lim = new double[i_dimension];
	pd_upper_lim = new double[i_dimension];

	//And we fill them with the passed values 
	for(int i = 0; i < i_dim; i ++){
		pd_lower_lim[i] = pd_lower[i];
		pd_upper_lim[i] = pd_upper[i];
  	}

  	//Finally, we point to the function 
  	pF_pdf = pF_func;

  	//We also initialize the random number generator 
  	std::srand( std::time(NULL) );
}

//This function is the sampling function 
double ** MCSample::genSample(int i_num){
	//First we allocate the memory 
	double ** ppd_samples = new double[i_dimension][i_num];

	//This counts how many sample we have collected 
	int i_num_samples = 0;

	//We keep generating samples until we have reached the desired number 
	do{

		//ALLOCATE MEMORY
		double * pd_sample = new double[i_dimension];

		//RANDOMLY FILL COMPONENTS
		for(int i = 0; i < i_dimension; i++){
			pd_sample[i] = MCSample::getRandomInRange(pd_lower_lim[i],pd_upper_lim[i]);
		}

		//COMPUTE PDF OF SAMPLE
		double d_prob = (*pF_pdf)(pd_sample);

		//COMPUTE RANDOM THRESHOLD
		double d_threshold = MCSample::getRandomInRange(0.0,1.0);

		//ACCEPT WITH PROBABILITY PDF(SAMPLE)
		//We accept if d_prob>= d_threshold otherwise reject 
		if(d_prob <= d_threshold){ 

			//WE SAVE THE RESULT
			for(int i = 0; i < i_dimension; i++){
				ppd_samples[i_num_samples][i] = pd_sample[i];
			}

			//INCREMENT COUNT OF SAVED 
			i_num_samples++;
		}

		//FREE UP MEMORY
		delete [] pd_sample;
	}
	while(i_num_samples < i_num);

	//RETURN LIST OF SAMPLES
	return ppd_samples;≈
}










