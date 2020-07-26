#include "stdbool.h"
#include "gpio.h"
#include "stm32l4xx_hal_gpio.h"


bool IsButtonPushed(void)
{
  bool ret = false;
  //HAL_GPIO_ReadPin()  TODO Figure this out for tomorrow

  ret = true;  //simulate pushing the button
  return ret;
}
