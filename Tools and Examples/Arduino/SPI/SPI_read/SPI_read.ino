#include <SPI.h>

byte myArray[4];  // Array to hold the received 4 bytes
int byteCount = 0;  // Counter for received bytes

void setup() {
  Serial.begin(9600);
  
  // Configure MISO pin as OUTPUT (MISO = Master In Slave Out)
  pinMode(MISO, OUTPUT);
  
  // Enable SPI in Slave mode
  SPCR |= _BV(SPE);  // Set SPE (SPI Enable) bit
}

void loop() {
  // Check if data has been received in SPI data register
  if (SPSR & _BV(SPIF)) {  // SPIF (SPI Interrupt Flag) indicates data received
    myArray[byteCount] = SPDR;  // Read the received byte from SPI Data Register
    byteCount++;

    if (byteCount == 4) {  // Once 4 bytes are received
      // Combine the 4 bytes into a 32-bit integer
      uint32_t receivedData = ((uint32_t)myArray[0] << 24) |
                              ((uint32_t)myArray[1] << 16) |
                              ((uint32_t)myArray[2] << 8) |
                              (uint32_t)myArray[3];

      // Print the received 32-bit data
      Serial.print("Received 32-bit data item from Master: ");
      Serial.println(receivedData, HEX);  // Print in hexadecimal format
      
      byteCount = 0;  // Reset byte counter for the next transaction
    }
  }
}
