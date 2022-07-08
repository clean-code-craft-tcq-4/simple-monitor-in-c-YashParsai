#include "batteryChecker.h"

float DummyInputParam[6][3] = { {20,70,0.2},{50,60,0.7},{30,60,1},{20,30,2},{50,10,1},{30,45,6} };

void test_battery(void)
{
        int i;
	struct batteryParameter batteryParam;
        
	for(i=0;i<5;i++)
        {
                batteryParam.temp = DummyInputParam[i][0];
                batteryParam.soc = DummyInputParam[i][1];
                batteryParam.chargeRate = DummyInputParam[i][2];
                assert(batteryIsOk(batteryParam));
        }

}
