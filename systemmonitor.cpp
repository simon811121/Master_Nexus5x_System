#include "systemmonitor.h"
#include "function.h"

using namespace android;

int main(void) {

	char buffer[100];	

	printf("System Monitor Start!!\n");

	sprintf(buffer, "su -c echo userspace > %s/cpu4/cpufreq/scaling_governor", cpu_fs);
	//system(buffer);
	printf("---TEMP---\n");	
	printf("v\ti\tc\tt\n");
	for (int i = 0; i < 10; i++) {		
		printf("%d\t%d\t%d\t%d\t\n", get_battery(battery_voltage), get_battery(battery_current), get_battery(battery_capacity), get_battery(battery_temp));
		sleep(1);
	}
	return 0;
}
