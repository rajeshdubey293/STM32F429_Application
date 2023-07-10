#include "../../TaskSchedular/Inc/main.h"


#define RTOS_APP 0    // Enable RTOS based application


static void Task1_Handler(void* parameters);
static void Task2_Handler(void* parameters);

I2C_HandleTypeDef hi2c1;
TIM_HandleTypeDef htim6;
UART_HandleTypeDef huart1;

uint32_t led1_Counter = 0;
uint32_t led2_Counter = 0;
uint32_t sc_Counter = 0;

char rx_Buffer;
char tempValue[10] = {0};

MPU6050_t MPU_Data = {0};

extern char LED1_ON_FLAG;
extern char LED2_ON_FLAG;

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	TIMER6_Init(&htim6);
	UART1_Init(&huart1);
	I2C1_Init(&hi2c1);

	MPU6050_Init(&hi2c1);

	GPIO_Init(RED_LED_PORT, RED_LED_PIN, OUTPUT);
	GPIO_Init(GREEN_LED_PORT, GREEN_LED_PIN, OUTPUT);

	TIMER_Start_IT(&htim6);
	UART_Interrupt_Start(&huart1, &rx_Buffer);

	Print_Msg("Welcome to STM32F429 Application Menu\r\n");
#if RTOS_APP // RTOS Based Application

	RTOS_Application();

#else // Non RTOS Based Application

	Non_RTOS_Application();

#endif
}

void SystemClock_Config(void)
{
	/*    Configure processor to run at full speed i.e 180Mhz */
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 4;
	RCC_OscInitStruct.PLL.PLLN = 180;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Activate the Over-Drive mode
	 */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
	{
		Error_Handler();
	}
}

void Error_Handler(void)
{
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{

	}

}

inline void RTOS_Application(void)
{
	TaskHandle_t task1_handler, task2_handler;
	BaseType_t status;

	status = xTaskCreate(Task1_Handler, "Task-1", 200, "Hello From Task-1", 2, &task1_handler);
	configASSERT(status == pdPASS);

	status = xTaskCreate(Task2_Handler, "Task-2", 200, "Hello From Task-2", 2, &task2_handler);
	configASSERT(status == pdPASS);

	vTaskStartScheduler(); // Start FreeRTOS Scheduler
}

inline void Non_RTOS_Application(void)
{
	/* Loop forever */
	for(;;)
	{
		if(SysTick_Get() > 0)
		{
			led1_Counter += SysTick_Get();
			led2_Counter += SysTick_Get();
			sc_Counter += SysTick_Get();
			SysTick_Set(0);
			if(LED1_ON_FLAG == 1)
			{
				LED1_ON_FLAG = 0;
				GPIO_Pin_Toggle(GPIOG, GPIO_PIN_13);
			}

			if(LED2_ON_FLAG == 1)
			{
				LED2_ON_FLAG = 0;
				GPIO_Pin_Toggle(GPIOG, GPIO_PIN_14);
			}
			if(sc_Counter >= 10)
			{
				sc_Counter = 0;
				SC_Process();
			}
		}
	}
}

void Task1_Handler(void* parameters)
{
	uint32_t counter = 0;
	/* Loop forever */
	for(;;)
	{
		Print_Msg("%s %d\r\n", (char*)parameters, counter++);
		GPIO_Pin_Toggle(GPIOG, GPIO_PIN_13);
		taskYIELD(); // context switching manually
	}
}
void Task2_Handler(void* parameters)
{
	uint32_t counter = 0;
	/* Loop forever */
	for(;;)
	{
		Print_Msg("%s %d\r\n", (char*)parameters, counter++);
		GPIO_Pin_Toggle(GPIOG, GPIO_PIN_14);
		taskYIELD(); // context switching manually
	}
}
