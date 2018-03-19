#ifndef _GPIO_MACRO_H
#define _GPIO_MACRO_H

#define GPIO_PIN_MODE_INPUT_FLOATING_WITHOUT_INTERRUPT(PORT, PIN)	\
  {									\
   GPIO##PORT->DDR &= ((uint8_t)(~(PIN)));				\
   GPIO##PORT->CR1 &= ((uint8_t)(~(PIN)));				\
   GPIO##PORT->CR2 &= ((uint8_t)(~(PIN)));				\
   }

#define GPIO_PIN_MODE_INPUT_PULLUP_WITHOUT_INTERRUPT(PORT, PIN)		\
  {									\
    GPIO##PORT->DDR &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR1 |= (PIN);						\
    GPIO##PORT->CR2 &= ((uint8_t)(~(PIN)));				\
  }

#define GPIO_PIN_MODE_INPUT_FLOATING_WITH_INTERRUPT(PORT, PIN)		\
  {									\
    GPIO##PORT->DDR &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR1 &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR2 |= (PIN);						\
  }

#define GPIO_PIN_MODE_INPUT_PULLUP_WITH_INTERRUPT(PORT, PIN)	\
  {								\
    GPIO##PORT->DDR &= ((uint8_t)(~(PIN)));			\
    GPIO##PORT->CR1 |= (PIN);					\
    GPIO##PORT->CR2 |= (PIN);					\
  }

#define GPIO_PIN_MODE_OUTPUT_OPENDRAIN_2MHZ(PORT, PIN)	\
  {							\
    GPIO##PORT->DDR |= (PIN);				\
    GPIO##PORT->CR1 &= ((uint8_t)(~(PIN)));		\
    GPIO##PORT->CR2 &= ((uint8_t)(~(PIN)));		\
  }

#define GPIO_PIN_MODE_OUTPUT_OPENDRAIN_10MHZ(PORT, PIN) \
  {							\
    GPIO##PORT->DDR |= (PIN);				\
    GPIO##PORT->CR1 &= ((uint8_t)(~(PIN)));		\
    GPIO##PORT->CR2 |= (PIN);				\
  }

#define GPIO_PIN_MODE_OUTPUT_PUSHPULL_2MHZ(PORT, PIN)	\
  {							\
    GPIO##PORT->DDR |= (PIN);				\
    GPIO##PORT->CR1 |= (PIN);				\
    GPIO##PORT->CR2 &= ((uint8_t)(~(PIN)));		\
  }

#define GPIO_PIN_MODE_OUTPUT_PUSHPULL_10MHZ(PORT, PIN)	\
  {							\
    GPIO##PORT->DDR |= (PIN);				\
    GPIO##PORT->CR1 |= (PIN);				\
    GPIO##PORT->CR2 |= (PIN);				\
  }

#define GPIO_PIN_MODE(MODE, PORT, PIN)		\
  {						\
    GPIO_PIN_MODE_##MODE(PORT, PIN);		\
  }


#define SET_PIN_HIGH(PORT, PIN)			\
  {						\
    GPIO##PORT->ODR |= (PIN);			\
  }

#define SET_PIN_LOW(PORT, PIN)			\
  {						\
    GPIO##PORT->ODR &= ((uint8_t)(~(PIN)));	\
  }


#define SET_PIN(PORT, PIN, LEVEL)		\
  {						\
    SET_PIN_##LEVEL(PORT, PIN);			\
  }

#define HI_BYTE(WORD) ((uint8_t)(((WORD) >> 8) & 0xFF))
#define LO_BYTE(WORD) ((uint8_t)((WORD) & 0xFF))
#define SWAP_UINT16(WORD) ((WORD >> 8) | (WORD << 8))

#define UART_DIV_BRR2(WORD) ((uint8_t)(((WORD >> 8) & 0xF0) | (WORD & 0x0F)))
#define UART_DIV_BRR1(WORD) ((uint8_t)(WORD >> 4)) 


#endif
