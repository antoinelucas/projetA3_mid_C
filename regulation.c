   #include "regulation.h"
	 
	float regulationTest(int regul,float csgn,float* tabT, int nT){
		float cmd=100.0;
		float origin=csgn-tabT[0];
      int i=0;
      for(i=0;i<nT;i++){
         cmd=regulation(regul,csgn,temp_t.interieure);
      }
      return cmd;
   }
    
	float regulation(int regul, float csgn, float valueTemp){
		if(regul==1){
			if(csgn>valueTemp){

			}
		}else if(regul==2){
		}
	}
   