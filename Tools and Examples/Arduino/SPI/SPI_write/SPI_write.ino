#include <SPI.h>

byte myArray[4] = {0xCE, 0xAD, 0xBE, 0xEF};  // Example 4-byte data to transmit
int byteCount = 0;  // Counter to track bytes being sent

void setup() {
  Serial.begin(9600);

  // Configure MISO pin as OUTPUT (MISO = Master In Slave Out)
  pinMode(MISO, OUTPUT);

  // Enable SPI in Slave mode
  SPCR |= _BV(SPE);  // Set SPE (SPI Enable) bit
  
  Serial.println("Slave is ready to transmit data.");
}

void loop() {
  // Check if the master has sent a clock pulse (data requested)
  if (1) {  // SPIF (SPI Interrupt Flag) indicates master data request
    SPDR = myArray[1];  // Load next byte into SPI Data Register to send
    byteCount++;

    if (byteCount == 4) {  // Once all 4 bytes are transmitted
      Serial.println("All 4 bytes transmitted to Master.");
      byteCount = 0;  // Reset the counter for the next transmission cycle
    }
  }
}