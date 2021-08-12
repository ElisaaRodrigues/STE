/*
 * External Interrupt INT0:
 * 
 *    Botão aciona a interrupção que troca estado do LED.
 *    > pino 2 (PD2) como entrada (BOTAO)
 *    > pino 13 (PB5) como saida (LED)
 *    > implementação sem utilizar as bibliotecas do Arduino
 *    
 *    DDRB – The Port B Data Direction Register
 *    > input (0) or output (1)
 *    
 *    DDRD – The Port D Data Direction Register
 *    > input (0) or output (1)
 *    
 *    PORTB – The Port B Data Register
 *    > write bits
 * 
 *    PINB – The Port B Input Pins Address
 *    > read bits
 *    
 *    EICRA - External Interrupt Control Register A
 *    > configure the interrupt detection control
 *    
 *    EIMSK - External Interrupt Mask Register
 *    > enable global independent interrupts
 *    
 *    SREG - AVR Status Register
 *    > enable global interrupts (and other)
 *    
*/

volatile byte *ddrb = (byte *) 0x24;
volatile byte *ddrd = (byte *) 0x2A;
volatile byte *portb = (byte *) 0x25;
volatile byte *pinb = (byte *) 0x23;
volatile byte *eicra = (byte *) 0x69;
volatile byte *eimsk = (byte *) 0x3D;
volatile byte *sreg = (byte *) 0x5F;

const byte PIN_13 = 0x20;
const byte PIN_2 = 0x08;
const byte EXT_INT0 = 0x01;
const byte GLOBAL_INT = 0x80;

 /* Configuration options for interrupt detection */
const byte CTR_REG_LOW = 0x00;
const byte CTR_REG_ANY = 0x01;
const byte CTR_REG_FALLING = 0x02;
const byte CTR_REG_RISING = 0x03;

/* Registering the interrupt handler */
ISR(INT0_vect) {
  Serial.print("interrupt");
  *portb ^= PIN_13; //LED change of state
}

void setup() {

  //  DDRB = xx1x xxxx
  // to set '1' : DDRB = DDRB | 0010 0000 (0x20)
  *ddrb |= PIN_13;
  
  //  DDRD = xxxx x0xx
  // to set '0' : DDRD = DDRD & 1111 1011 (0XFB == ~0x08)
  *ddrd &= ~PIN_2;


  *eicra |= CTR_REG_ANY;
  *eimsk |= EXT_INT0;
  *sreg  |= GLOBAL_INT;

  Serial.begin(9600);
  
}

void loop() {
  //empty
}
