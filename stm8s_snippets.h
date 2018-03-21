#ifndef _STM8S_SNIPPETS_H
#define _STM8S_SNIPPETS_H

/* 
GPIO Pin description:
PORT, PIN, MODE, DEFAULT_STATE
example:
#define LED B, GPIO_PIN_3, OUTPUT_PUSHPULL_2MHZ, RESET
...
GPIO_PIN_SETUP(LED); //configure GPIOB PIN3 as OUTPUT_PUSHPULL slow front, and set PIN to LOW  

GPIO_PIN_SET(LED) //set pin to HIGH

GPIO_PIN_RESET(LED) set pin to LOW

GPIO_PIN_TOGGLE(LED) // toggle PIN level

*/


#define GPIO_PIN_MODE_INPUT_FLOATING_WITHOUT_INTERRUPT(PORT, PIN, MODE, DEFAULT_STATE) \
  {									\
    GPIO##PORT->DDR &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR1 &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR2 &= ((uint8_t)(~(PIN)));				\
  }

#define GPIO_PIN_MODE_INPUT_PULLUP_WITHOUT_INTERRUPT(PORT, PIN, MODE, DEFAULT_STATE) \
  {									\
    GPIO##PORT->DDR &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR1 |= (PIN);						\
    GPIO##PORT->CR2 &= ((uint8_t)(~(PIN)));				\
  }

#define GPIO_PIN_MODE_INPUT_FLOATING_WITH_INTERRUPT(PORT, PIN, MODE, DEFAULT_STATE) \
  {									\
    GPIO##PORT->DDR &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR1 &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR2 |= (PIN);						\
  }

#define GPIO_PIN_MODE_INPUT_PULLUP_WITH_INTERRUPT(PORT, PIN, MODE, DEFAULT_STATE) \
  {									\
    GPIO##PORT->DDR &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR1 |= (PIN);						\
    GPIO##PORT->CR2 |= (PIN);						\
  }

#define GPIO_PIN_MODE_OUTPUT_OPENDRAIN_2MHZ(PORT, PIN, MODE, DEFAULT_STATE) \
  {									\
    GPIO##PORT->DDR |= (PIN);						\
    GPIO##PORT->CR1 &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR2 &= ((uint8_t)(~(PIN)));				\
  }

#define GPIO_PIN_MODE_OUTPUT_OPENDRAIN_10MHZ(PORT, PIN, MODE, DEFAULT_STATE) \
  {									\
    GPIO##PORT->DDR |= (PIN);						\
    GPIO##PORT->CR1 &= ((uint8_t)(~(PIN)));				\
    GPIO##PORT->CR2 |= (PIN);						\
  }

#define GPIO_PIN_MODE_OUTPUT_PUSHPULL_2MHZ(PORT, PIN, MODE, DEFAULT_STATE) \
  {									\
    GPIO##PORT->DDR |= (PIN);						\
    GPIO##PORT->CR1 |= (PIN);						\
    GPIO##PORT->CR2 &= ((uint8_t)(~(PIN)));				\
  }

#define GPIO_PIN_MODE_OUTPUT_PUSHPULL_10MHZ(PORT, PIN, MODE, DEFAULT_STATE) \
  {									\
    GPIO##PORT->DDR |= (PIN);						\
    GPIO##PORT->CR1 |= (PIN);						\
    GPIO##PORT->CR2 |= (PIN);						\
  }

#define GPIO_PIN_MODE(PORT, PIN, MODE, DEFAULT_STATE)		\
  {								\
    GPIO_PIN_MODE_##MODE(PORT, PIN, MODE, DEFAULT_STATE);	\
  }


#define _GPIO_PIN_SET_HIGH(PORT, PIN, MODE, DEFAULT_STATE)		\
  {								\
    GPIO##PORT->ODR |= (PIN);					\
  }

#define _GPIO_PIN_SET_LOW(PORT, PIN, MODE, DEFAULT_STATE)		\
  {								\
    GPIO##PORT->ODR &= ((uint8_t)(~(PIN)));			\
  }

#define _GPIO_PIN_LEVEL(PORT, PIN, MODE, DEFAULT_STATE)			\
  {									\
    _GPIO_PIN_SET_##DEFAULT_STATE(PORT, PIN, MODE, DEFAULT_STATE);	\
  }


#define _GPIO_PIN_SETUP(PORT, PIN, MODE, DEFAULT_STATE)	\
  {							\
    GPIO_PIN_MODE(PORT, PIN, MODE, DEFAULT_STATE);	\
    _GPIO_PIN_LEVEL(PORT, PIN, MODE, DEFAULT_STATE);	\
  }


#define _GPIO_PIN_TOGGLE(PORT, PIN, MODE, DEFAULT_STATE)	\
  {								\
    GPIO##PORT-> ODR ^= (PIN);					\
  }


#define GPIO_PIN_SETUP(PIN_DESCRIPTION) _GPIO_PIN_SETUP(PIN_DESCRIPTION);
#define GPIO_PIN_SET(PIN_DESCRIPTION) _GPIO_PIN_SET_HIGH(PIN_DESCRIPTION);
#define GPIO_PIN_RESET(PIN_DESCRIPTION) _GPIO_PIN_SET_LOW(PIN_DESCRIPTION);
#define GPIO_PIN_TOGGLE(PIN_DESCRIPTION) _GPIO_PIN_TOGGLE(PIN_DESCRIPTION);


#define HI_BYTE(WORD) ((uint8_t)(((WORD) >> 8) & 0xFF))
#define LO_BYTE(WORD) ((uint8_t)((WORD) & 0xFF))
#define SWAP_UINT16(WORD) ((WORD >> 8) | (WORD << 8))

/* BRR = Fmaster/Baud rate */
#define UART_DIV_BRR2(BRR) ((uint8_t)(((BRR >> 8) & 0xF0) | (BRR & 0x0F)))
#define UART_DIV_BRR1(BRR) ((uint8_t)(BRR >> 4)) 



#endif
