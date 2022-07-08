#include <stdio.h>
#include <stdbool.h>
#include "batteryChecker.h"
#include "test_batteryChecker.h"

/***********Global Variable Declaration***********/
bool	 batteryWarning;
char*  	 batteryParameterString[] = {"Temperature", "State_of_Charge", "Charge_Rate"};
/************************************************/

void  batteryParameterCheck(char* parameterString, int  parameterValue, int maxLimit, int minLimit)
{
	if(parameterValue < minLimit || parameterValue > maxLimit)
	{
		printf("%s out of range!\n",parameterString);
		batteryWarning = true;
	}
}

bool batteryIsOk(struct batteryParameter batteryParam)
{

	batteryWarning = false;

	batteryParameterCheck(batteryParameterString[0], batteryParam.temp, 	  TEMP_MAX_LIMIT, 	TEMP_MIN_LIMIT);
	batteryParameterCheck(batteryParameterString[1], batteryParam.soc, 	  SOC_MAX_LIMIT, 	SOC_MIN_LIMIT);
	batteryParameterCheck(batteryParameterString[2], batteryParam.chargeRate, CHARGERATE_MAX_LIMIT, CHARGERATE_MIN_LIMIT);
	if(batteryWarning)
	{
                printf("??????Battery not OK, Parameter\n temp =%f\nsoc = %f\n CR = %f\n?????????\n",batteryParam.temp,batteryParam.soc,batteryParam.chargeRate);
       		return false;
       	}
        printf("Battery looks COOL\n");
        return true;

}

int main()
{
	test_battery();
}
