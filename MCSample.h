//This is C++ code for generation of a multivariate MC sample 
//Jonathan Curtis
//02/09/2016

#include <cstdlib>
#include <ctime>
#include <math>
#include <fstream>
#include <iostream>

//We use an object oriented approach
#ifndef MCSAMPLE_H
#define MCSAMPLE_H


//Variable naming convention
//i_uniqueID -> Integer
//d_uniqueID -> Double 
//pd_uniqueID -> Pointer to/array of doubles
//ppd_uniqueID -> pointer to/array of pointer to/array of doubles
//pF_uniqueID -> Function pointer 


class MCSample{
protected:
	int i_dimension;	//The dimension of the sample space 
	double * pd_lower_lim;	//Lower limit of the sample space (one for each dimension)
	double * pd_upper_lim;	//Upper limit of the sample space (one for each dimension)

	double (*pF_pdf)(double *);	//This is a pointer to a function that will be the pdf 
									//It accepts an array of doubles (the vector) and returns the probability 
public:

	static double getRandomInRange(double d_lower,double d_upper);	//A static member function for generating random doubles in a given range

	MCSample(int i_dim,double* pd_lower,double* pd_upper,double (*pF_func)(double*) );	//This is the constructor 
	
	double ** genSample(int i_num);	//Generates a list of i_num sampled vectors 
									//Returns an array of arrays (the first index indexes the sampled vector, the second is for the vector index)
};
#endif