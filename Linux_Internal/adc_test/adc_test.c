/*********************************************************************************************
 * © 2022 PHYTEC EMBEDDED PVT LTD. - All Rights Reserved. Permission to use, modify, copy, and distribute
 * this source code, object code, or executable code (collectively, Software), is granted only
 * under the terms of a valid written license agreement with PHYTEC. Unauthorized copying
 * or other use of the Software is strictly prohibited.  Software is owned by and constitutes
 * the proprietary works, trade secrets, and copyrights of Embitel or its licensors.
 *
 * For further information, contact PHYTEC EMBEDDED Pvt Ltd.
 *********************************************************************************************/
/*********************************************************************************************/
/*      Application: adc_test.c
 *
 *      Brief: This application is to read the Analog data using ADC interface via /sys/fs entries
 *
 *      Author: PHYTEC EMBEDDED PVT LTD
 */
/*********************************************************************************************/



/***************************************
	     HEADER FILES
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include "adc.h"

/**************************************** 	     
		 MAIN
*****************************************/
int main(int argc, char **argv, char **envp)
{
	int digital_val;
	struct adc_config_t adc_desc;
	float analog_val;
	
	adc_desc.adc_mode = ONESHOT;
	adc_desc.capture  = 0;
	adc_desc.buff_length = 100;
	adc_desc.adc_channel = atoi(argv[1]);
	
	printf("\n   *** ADC TESTING UTILITY ***   \n");

	adc_init(&adc_desc);
	adc_set_channel(&adc_desc, adc_desc.adc_channel);

	while (1)
	{
		digital_val = adc_output(&adc_desc, adc_desc.adc_channel);
		analog_val = (digital_val * 0.805664062)/4095;

		printf("Digital Value on Channel %d = %d\n", adc_desc.adc_channel, digital_val);
		printf("Analog Value on Channel %d = %f\n", adc_desc.adc_channel, analog_val);
		sleep(4);
	}

	return 0;
}
