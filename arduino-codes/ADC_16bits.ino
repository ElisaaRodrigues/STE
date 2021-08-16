//uint8_t analogRead16A0()
uint16_t analogRead16A0()
{
  register uint8_t adcsra ("r17"); // help register allocator
  uint8_t adch;
  uint8_t adcl;
  uint16_t leitura;
  
  asm volatile ( // start conversion
    "ldi r27, 0x00\n\t"
    "ldi r26, 0x7A\n\t" // X = lsADCSRA
    "ld %0, X\n\t" // read adcsra
    "ori %0, 0x40\n\t" // set ADSC bit
    "st X, %0\n\t"
    : "+r" (adcsra) :
  );
  do { // wait for completion
    asm volatile (
    "ld %0, X" : "=r" (adcsra) :
    );
  }while (adcsra & 0x40); // while ADSC bit == 1
  
  asm volatile ( // return 16-bit digital value
    "ldi r27, 0x00\n\t" 
    "ldi r26, 0x78\n\t" // X = lsADCL
    "ld %0, X" // read ADCL
    : "=r" (adcl) :
  );
  
  asm volatile ( // return 16-bit digital value
    "ldi r27, 0x00\n\t" 
    "ldi r26, 0x79\n\t" // X = lsADCH
    "ld %0, X" // read ADCH
    : "=r" (adch) :
  );
  leitura = (adch << 8) | adcl;
  return leitura;
}

void setup() {
  Serial.begin(9600);
  asm volatile ( // enable ADC pin A0 
    "ldi r27, 0x00\n\t"
    "ldi r26, 0x7A\n\t" // X = lsADCSRA
    "ldi r16, 0x84\n\t"
    "st X, r16\n\t" // 1. ADCSRA = 0x84
    "ldi r26, 0x7C\n\t" // X = lsADMUX
    "ldi r16, 0x40\n\t" //0x40 para 16 bits remove://0x60\n\t"
    "st X, r16\n\t" // 2. ADMUX = 0x40 / pin A0
  );
}

void loop() {
 // uint8_t inp = analogRead16A0(); // bare metal analogRead
  uint16_t inp = analogRead16A0(); // bare metal analogRead
  Serial.println(inp);
  delay(1000);
}
