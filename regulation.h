	#include "define.h" 

	#define KP 1
	#define KI 0.1
	#define KD 0.1

	typedef struct{
		float previousV,newV;
		float valueP,valueD,valueI;
		float previousI,newI;
	}SPID;

	float regulationTest(int regul,float csgn,float* tabT, int nT);
	float regulation(int regul, float csgn, float valueTemp,SPID * pid,int i);

