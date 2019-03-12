   #include "regulation.h"
	 
	float regulationTest(int regul,float csgn,float* tabT, int nT){
		temp_t temperature;
		float cmd=100.0;
		float origin=csgn-tabT[0];
      int i=0;
      for(i=0;i<nT;i++){
         cmd=regulation(regul,csgn,temperature.interieure);
			printf("%f\n",cmd);
      }
      return cmd;
   }
    
	float regulation(int regul, float csgn, float valueTemp){
		float cmd=0.0;
		if(regul==1){
			if(csgn>valueTemp){
				cmd=40.0;
			}else if(csgn<valueTemp){
				cmd=0.0;
			}
		}
		return cmd;
	}
   