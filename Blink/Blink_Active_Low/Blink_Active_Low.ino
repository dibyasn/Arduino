/*
 * Blink LED Program (Active LOW Configuration)
 * 
 * This program blinks an LED connected to pin 13 of the Arduino board.
 * The LED will turn ON for 1 second and then turn OFF for 1 second in a loop.
 * 
 * This approach is useful when using:
 * - Common anode LEDs (where multiple LEDs share a common positive voltage).
 * - Circuits where logic inversion is required (e.g., using open-drain outputs).
 * 
 * Hardware Requirements:
 * - Arduino board (5V logic)
 * - LED (typically a 5mm LED with a forward voltage of ~2V)
 * - Resistor (calculated to limit current through the LED)
 * 
 * Resistor Calculation:
 * - The Arduino GPIO outputs 5V when set HIGH.
 * - A standard red LED has a forward voltage drop of approximately 2V.
 * - The desired current for safe operation is around 10-20mA.
 * - Using Ohm’s Law: R = (V_supply - V_LED) / I
 *   - R = (5V - 2V) / 0.01A (for 10mA) = 300Ω
 *   - R = (5V - 2V) / 0.02A (for 20mA) = 150Ω
 * - A 220Ω resistor is a good balance, limiting current to around 13.6mA.
 * 
 * Author: Dibyaranjan
 * Wokwi Simulation: https://wokwi.com/projects/422745920995800065
 */

 #define ledPin 13  // Define the digital pin number where the LED cathode is connected

 // The setup function runs once when the board is powered on or reset
 void setup() {
   pinMode(ledPin, OUTPUT); // Set the LED pin as an OUTPUT
 }
 
 // The loop function runs continuously after setup
 void loop() {
   digitalWrite(ledPin, LOW);  // Turn ON the LED (Active LOW Configuration)
   delay(1000);                // Wait for 1 second
   
   digitalWrite(ledPin, HIGH); // Turn OFF the LED
   delay(1000);                // Wait for 1 second
 }
 