#ifndef DEFINE_H
#define DEFINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float interieure;
	float exterieure;
} temp_t;

typedef struct{
	float previousV,newV;
	float valueP,valueD,valueI;
	float previousI,newI;
}SPID;

#endif