   #include "regulation.h"
	 
	float regulationTest(int regul,float csgn,float* tabT, int nT){
		float cmd=100.0;
      int i=0;
      for(i=0;i<nT;i++){
          cmd=regulation(regul,csgn,tabT[i]);
      }
      return cmd;
   }
    
	float regulation(int regul, float csgn, float valueTemp){
		float cmd=0.0;
		if(regul==1){
			// Régulation TOR 
			if(csgn>valueTemp){
				if(csgn<valueTemp){
					cmd=0.0;
				} else if (csgn>valueTemp){
					cmd=40.0;
				}
			}
		}else if(regul==2){
			// Régulation PID
			
		}
		return cmd;
	}
   