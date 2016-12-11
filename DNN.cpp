#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

class Neuron{
private : 
	float *a;  // input a1~ak 
	float *w;  // weight w1~wk
	float bias;
	float z;   // z = a1*w1 + a2*w2 + ..... ak*wk + bias  
	float output; // output = Activation function(z)
	int FunctionType; // Type of Activation function
	int UpperLayerNum; // k
public:	

	Neuron(int upperlayer_num , float UpperLayerInput[] , float b){ // constructor
		
		UpperLayerNum = upperlayer_num;
		// dynamic array
		a = new float[UpperLayerNum];
		w = new float[UpperLayerNum];
		
		// input assignment
		for(int i=0;i<UpperLayerNum;i++)
			a[i] = UpperLayerInput[i];
		
		// bias assignment
		bias = b;
		
		// First time Weight construct
		WeightConstruct();
		
	}
	
	void WeightConstruct(){  // First time using random value
		srand( (unsigned)time(NULL));
    	for(int i=0; i<UpperLayerNum ; i++)
        	w[i] = (float)rand() / (RAND_MAX+1.0);
	}
	
	void Compute(){
		
		// z = a1*w1 + a2*w2 + ..... ak*wk + bias  
		for(int i=0; i<UpperLayerNum ; i++)
			z += a[i]*w[i];
		z += bias;
		
		//output = Activation function(z)
		output = ActivationFunction(z);
	
	}
	
	float ActivationFunction(float zValue){
		return  1/(1+exp(-zValue));
	}
	
};


int main(){
	
}









