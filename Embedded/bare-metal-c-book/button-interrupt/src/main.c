#include "stm32f0xx.h"
#include "stm32f0xx_nucleo.h"

#define DOT 200
#define DASH 3*DOT
#define SIGN_PAUSE DOT
#define LETTER_PAUSE 3*DOT

const char* h = "****";
const char* e = "*";
const char* l = "*-**";
const char* o = "---";
const char* w = "*--";
const char* r = "*-*";
const char* d = "-**";

int current_index = 0;

void playCode(const char* code) {
	int code_length = strlen(code);
	for (int i = 0; i < code_length; ++i) {
		HAL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
		if (code[i] == '*') {
			HAL_Delay(DOT);
		} else if (code[i] == '-') {
			HAL_Delay(DASH);
		}
		HAL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
		HAL_Delay(SIGN_PAUSE);
	}
	HAL_Delay(LETTER_PAUSE);
}

void EXTI4_15_IRQHandler(void) {
	if (current_index < 9) {
		++current_index;
	} else {
		current_index = 0;
	}
	EXTI->PR |= USER_BUTTON_EXTI_LINE;
//	CLEAR_BIT(EXTI->PR, USER_BUTTON_EXTI_LINE);
}

void HAL_GPIO_EXTI_Callback(uint16_t pin) {
	if (current_index < 9) {
		++current_index;
	} else {
		current_index = 0;
	}
}

int main(void)
{
	HAL_Init();

	LED2_GPIO_CLK_ENABLE();
	GPIO_InitTypeDef gpio_led_pin;
	gpio_led_pin.Pin = LED2_PIN;
	gpio_led_pin.Pull = GPIO_PULLUP;
	gpio_led_pin.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_led_pin.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(LED2_GPIO_PORT, &gpio_led_pin);

	USER_BUTTON_GPIO_CLK_ENABLE();
	GPIO_InitTypeDef gpio_button_pin;
	gpio_button_pin.Pin = USER_BUTTON_PIN;
	gpio_button_pin.Pull = GPIO_NOPULL;
	gpio_button_pin.Mode = GPIO_MODE_IT_RISING;
	gpio_button_pin.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(USER_BUTTON_GPIO_PORT, &gpio_button_pin);

	const char* text[10] = {h,e,l,l,o,w,o,r,l,d};

//	EXTI->IMR |= USER_BUTTON_EXTI_LINE;
//	EXTI->RTSR |= USER_BUTTON_EXTI_LINE;
//	EXTI->FTSR &= ~USER_BUTTON_EXTI_LINE;

	HAL_NVIC_SetPriority(USER_BUTTON_EXTI_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USER_BUTTON_EXTI_IRQn);

	for(;;) {
		const char* current_code = text[current_index];
		playCode(current_code);
	}
}
