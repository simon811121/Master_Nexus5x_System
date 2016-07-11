#ifndef FUNCTION_H
#define FUNCTION_H

#include "systemmonitor.h"

using namespace android;

//******************************//
//  CPU				//
//******************************//
int get_cpu_freq(int cpu) {
	char buffer[100];
	FILE *cpu_f;
	
	sprintf(buffer,"%s/cpu%d/cpufreq/cpuinfo_cur_freq",cpu_fs,cpu);	
	cpu_f = fopen(buffer,"r");
	if(cpu_f) {
		fgets(buffer,100,cpu_f);
		int f = atoi(buffer);
		fclose(cpu_f);
		return f;
	} else {
		return 0;
	}
}

void set_cpu_freq(int cpu, int freq) {
	char buffer[100];
	FILE *cpu_f;

	sprintf(buffer,"%s/cpu%d/cpufreq/scaling_setspeed",cpu_fs,cpu);	
	cpu_f = fopen(buffer,"w");
	if(cpu_f) {
		fprintf(cpu_f,"%d",freq);
		fclose(cpu_f);
		return;
	} else {
		return;
	}
}

//******************************//
//  Thermal			//
//******************************//
int get_cpu_temp(int cpu) {	// cpu=7 for gpu, default for cpu0,1
	char buffer[100];
	FILE *cpu_f;
	int zone = 0;	

	switch (cpu) {
		case 2:	//cpu2
			zone = 9;
		case 3:	//cpu3
			zone = 10;
		case 4:	//cpu4
			zone = 13;
		case 5:	//cpu5
			zone = 14;
		case 7:	//gpu
			zone = 12;
		default://cpu0,1
			zone = 8;
	}	

	sprintf(buffer,"%s/thermal_zone%d/temp",thermal_fs, zone);	
	cpu_f = fopen(buffer,"r");
	if(cpu_f) {
		fgets(buffer,100,cpu_f);
		int f = atoi(buffer);
		fclose(cpu_f);
		return f;
	} else {
		return 0;
	}
}

//******************************//
//  Battery			//
//******************************//
int get_battery(int coef) {
	char s[100];
	FILE *bat;
	
	switch (coef){
		case battery_voltage:
			sprintf(s,"%s/voltage_now",battery_fs);
			break;
		case battery_current:
			sprintf(s,"%s/current_now",battery_fs);
			break;
		case battery_capacity:
			sprintf(s,"%s/capacity",battery_fs);
			break;
		case battery_temp:
			sprintf(s,"%s/temp",battery_fs);	
			break;
		default:
			sprintf(s,"%s/temp",battery_fs);		
	}	
	bat = fopen(s,"r");
	if(bat) {
		fgets(s,100,bat);
		int f = atoi(s);
		fclose(bat);
		return f;
	} else {
		return -1;
	}
}

#endif
