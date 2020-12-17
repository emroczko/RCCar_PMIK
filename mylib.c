#include "mylib.h"

char buffer[50];
uint8_t timer_count = 0, buffer_index = 0;

//uint32_t echo1, echo2, delay;
//float dist1, dist2;



uint8_t string_compare(char array1[], char array2[], uint16_t length)
{
	 uint8_t comVAR=0, i;
	 for(i=0;i<length;i++)
	   	{
	   		  if(array1[i]==array2[i])
	   	  		  comVAR++;
	   	  	  else comVAR=0;
	   	}
	 if (comVAR==length)
		 	return 1;
	 else 	return 0;
}

void DistanceHandler(){
	//echo2 = HAL_TIM_ReadCapturedValue(&htim8, TIM_CHANNEL_2);
	//dist2 = echo2 / 58.0f;
	//__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1000);
	//if(dist2 > 1 ){

	//}
	//else{
	//	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	//}
}

void Message_handler()
{
	if(string_compare(buffer, "g", strlen("g")))
	{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, SET);
		HAL_UART_Transmit(&huart7, (uint8_t*)"Forward.\n", strlen("Forward.\n"), 500);
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 800);
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);

		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1000);
	}else
	if(string_compare(buffer, "b", strlen("b")))
	{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, SET);
		HAL_UART_Transmit(&huart7, (uint8_t*)"Backward.\n", strlen("Backward.\n"), 500);
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 800);

		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1000);
	}else
	if(string_compare(buffer, "s", strlen("s")))
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, RESET);
			HAL_UART_Transmit(&huart7, (uint8_t*)"Stop.\n", strlen("Stop.\n"), 500);
			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);

			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	}else
	if(string_compare(buffer, "t", strlen("t")))
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, SET);
			HAL_UART_Transmit(&huart7, (uint8_t*)"Forward left.\n", strlen("Forward left.\n"), 500);

			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 500);
	}else
	if(string_compare(buffer, "right", strlen("right")))
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, SET);
			HAL_UART_Transmit(&huart7, (uint8_t*)"Forward right.\n", strlen("Forward right.\n"), 500);

			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 1000);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 500);
	}else
	if(string_compare(buffer, "left", strlen("left")))
			{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, SET);
			HAL_UART_Transmit(&huart7, (uint8_t*)"Forward right.\n", strlen("Forward right.\n"), 500);

			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 1000);
			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 500);


	}else
	if(string_compare(buffer, "ledoff", strlen("ledoff")))
	{
		    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, SET);
			HAL_UART_Transmit(&huart7, (uint8_t*)"Led off.\n", strlen("Led off.\n"), 500);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);

	}else
	if(string_compare(buffer, "ledon", strlen("ledon")))
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, SET);
			HAL_UART_Transmit(&huart7, (uint8_t*)"Led on.\n", strlen("Led on.\n"), 500);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1000);
	}else
	{
		strcat(buffer, "\n");
		HAL_UART_Transmit(&huart7, (uint8_t*)buffer, strlen(buffer), 500);
	}

	memset(buffer, 0, sizeof(buffer));
	buffer_index = 0;
	timer_count = 0;
}
