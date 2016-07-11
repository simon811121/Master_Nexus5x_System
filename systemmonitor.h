#ifndef SYSTEMMONITOR_H
#define SYSTEMMONITOR_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#include <string.h>
#include <utils/threads.h>
#include <pthread.h>

#include <utils/Errors.h>
#include <utils/String16.h>

#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
 
#include <binder/BinderService.h>
#include <SurfaceFlinger.h>
#include <cutils/sched_policy.h>
#include <sys/syscall.h>

using namespace android;

//******************************//
//  PATH			//
//******************************//
#define cpu_fs "/sys/devices/system/cpu"
#define thermal_fs "/sys/devices/virtual/thermal"
#define battery_fs "/sys/class/power_supply/battery"

//******************************//
//  System Parameters		//
//******************************//
#define core_num 4
#define little_freq_level 9  
#define big_freq_level 13

//******************************//
//  Governor Variables		//
//******************************//
int little_FL[little_freq_level]={384000, 460800, 600000, 672000, 787200, 864000, 960000, 1248000, 1440000};
int big_FL[big_freq_level]={384000, 480000, 633600, 768000, 864000, 960000, 1248000, 1344000, 1440000, 1536000, 1632000, 1689600, 1824000};

//******************************//
//  CPU				//
//******************************//
int get_cpu_freq(int cpu);
void set_cpu_freq(int cpu, int freq);

//******************************//
//  Thermal			//
//******************************//
int get_cpu_temp(int cpu);	// cpu=7 for gpu, default for cpu0,1

//******************************//
//  Battery			//
//******************************//
enum {
	battery_voltage,
	battery_current,
	battery_capacity,
	battery_temp
};
int get_battery(int coef);

#endif
