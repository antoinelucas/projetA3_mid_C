   #include "regulation.h"
	 
	float regulationTest(int regul,float csgn,float* tabT, int nT){
		float cmd=100.0;
		float origin=csgn-tabT[0];
      int i=0;
      for(i=0;i<nT;i++){
         cmd=regulation(regul,csgn,tabT[i],i,origin);
      }
      return cmd;
   }
    
	float regulation(int regul, float csgn, float valueTemp,int time,float origin){
		float cmd,valueP,valueI,valueD,PID=0.0;
		float function=origin-(time/10);
		float Dfunction=-(1/10);
		float Ifunction=origin*time-((time^2)/10);
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
			valueP=KP*function;
			valueI=KI*Ifunction;
			valueD=KD*Dfunction;
			PID= valueP + valueI + valueD;
		}
		return cmd;
	}
   