#ifndef _GPIO_MACRO_H
#define _GPIO_MACRO_H

#define SET_PIN_HIGH(PORT, PIN) { GPIO##PORT->ODR |= (1<<PIN); }
#define SET_PIN_LOW(PORT, PIN) { GPIO##PORT->ODR &= (uint8_t)(~(1<<PIN)); }
#define SET_PIN(PORT, PIN, LEVEL) { SET_PIN_##LEVEL(PORT, PIN); }

#endif
