#include <stdbool.h>

#define TEMP_MAX_LIMIT 45
#define TEMP_MIN_LIMIT 0
#define SOC_MAX_LIMIT 80
#define SOC_MIN_LIMIT 20
#define CHARGERATE_MAX_LIMIT 0.8
#define CHARGERATE_MIN_LIMIT 0

struct batteryParameter
{
        float temp;
        float soc;
        float chargeRate;
};

void batteryParameterCheck(char* parameterString, int  parameterValue, int maxLimit, int minLimit);
bool batteryIsOk(struct batteryParameter batteryParam);
