#ifndef gpio_macro_h
#define gpio_macro_h

/* GPIO Port input */
#define PIN_CONF_INPUT_FLOATING_WITOUT_INTERRUPT(PORT, PIN)	\
  {								\
    GPIO##PORT->DDR &= (uint8_t)(~(1 << PIN));			\
    GPIO##PORT->CR1 &= (uint8_t)(~(1 << PIN));			\
    GPIO##PORT->CR2 &= (uint8_t)(~(1 << PIN));			\
  }

#define PIN_CONF_INPUT_PULLUP_WITHOUT_INTERRUPT(PORT, PIN)	\
  {								\
    GPIO##PORT->DDR &= (uint8_t)(~(1 << PIN));			\
    GPIO##PORT->CR1 |= (1 << PIN);				\
    GPIO##PORT->CR2 &= (uint8_t)(~(1 << PIN));			\
  }

#define PIN_CONF_INPUT_FLOATING_WITH_INTERRUPT(PORT, PIN)	\
  {								\
    GPIO##PORT->DDR &= (uint8_t)(~(1 << PIN));			\
    GPIO##PORT->CR1 &= (uint8_t)(~(1 << PIN));			\
    GPIO##PORT->CR2 |= (1 << PIN);				\
  }

#define PIN_CONF_INPUT_PULLUP_WITH_INTERRUPT(PORT, PIN)	\
  {							\
    GPIO##PORT->DDR &= (uint8_t)(~(1 << PIN));		\
    GPIO##PORT->CR1 |= (1 << PIN);			\
    GPIO##PORT->CR2 |= (1 << PIN);			\
  }

/* GPIO Port output */
#define PIN_CONF_OUTPUT_OPEN_DRAIN_2MHZ(PORT, PIN)	\
  {						\
    GPIO##PORT->DDR |= (1 << PIN);		\
    GPIO##PORT->CR1 &= (uint8_t)(~(1 << PIN));	\
    GPIO##PORT->CR2 &= (uint8_t)(~(1 << PIN));	\
  }
    
#define PIN_CONF_OUTPUT_OPEN_DRAIN_10MHZ(PORT, PIN)	\
  {							\
    GPIO##PORT->DDR |= (1 << PIN);			\
    GPIO##PORT->CR1 &= (uint8_t)(~(1 << PIN));		\
    GPIO##PORT->CR2 |= (1 << PIN);			\
  }

#define PIN_CONF_OUTPUT_PUSH_PULL_2MHZ(PORT, PIN)	\
  {						\
    GPIO##PORT->DDR |= (1 << PIN);		\
    GPIO##PORT->CR1 |= (1 << PIN);		\
    GPIO##PORT->CR2 &= (uint8_t)(~(1 << PIN));	\
  }

#define PIN_CONF_OUTPUT_PUSH_PULL_10MHZ(PORT, PIN)	\
  {							\
    GPIO##PORT->DDR |= (1 << PIN);			\
    GPIO##PORT->CR1 |= (1 << PIN);			\
    GPIO##PORT->CR2 |= (1 << PIN);			\
  }


#define SET_PIN_HIGH(PORT, PIN) { GPIO##PORT->ODR |= (1<<PIN); }
#define SET_PIN_LOW(PORT, PIN) { GPIO##PORT->ODR &= (uint8_t)(~(1<<PIN)); }
#define SET_PIN(PORT, PIN, LEVEL) { SET_PIN_##LEVEL(PORT, PIN); }

#endif
