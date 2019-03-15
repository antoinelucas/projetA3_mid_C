clearvars
close all;
%% load trace.txt
filename = 'trace.txt';
if(exist(filename,'file')==0)
    error('erreur : absence du fichier trace.txt !');
end
 fid = fopen(filename,'r');
 mat = fscanf(fid,'%f \t %f \t %f \t %f\n');
 fclose(fid);   
 
 %% reshape data
 data=transpose(reshape(mat,4,length(mat)/4));
 time = data(:,1)/3600;
 power = data(:,2);
 Tout = data(:,3);
 Tin = data(:,4);
 
 %% plots
 figure(1);
 title('Régulation chauffage');
 yyaxis left
 plot(time,power,'-b','linewidth',2.0);
 xlabel('Temps [h]');
 ylabel('Puissance [%]');
 axis([time(1) time(end) 0 100])
 yyaxis right
 plot(time,Tin,'-r','linewidth',2.0);
 hold on;
 plot(time,Tout,'-g','linewidth',2.0);
 grid on;
  ylabel('Température [deg]');
 axis([time(1) time(end) 0 25])
 legend('Puissance chauffage','Température interieure','Température exterieure','Location','southoutside');