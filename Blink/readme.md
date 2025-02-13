# LED Blinking

## Introduction

This project demonstrates two different LED blinking configurations using an Arduino:
1. **Active HIGH:** The LED turns ON when the signal is HIGH and OFF when the signal is LOW.
2. **Active LOW:** The LED turns ON when the signal is LOW and OFF when the signal is HIGH.

Understanding these concepts helps in designing circuits that work correctly with various electronic components and modules.

## Hardware Requirements

- **Arduino board** (e.g., Arduino Uno, Nano, etc.)
- **LED** (typically a 5mm LED with a forward voltage of ~2V)
- **Resistor** (to limit current through the LED)
- **Connecting wires** (to establish connections)
- **Breadboard** (optional, for easy prototyping)
- **USB cable** (for programming and power supply to the Arduino)

## Working Principle

The Arduino board has GPIO (General-Purpose Input/Output) pins that can be programmed to control external components such as LEDs, motors, and sensors. In this project, we use **digital pin 13** to control the LED in both active HIGH and active LOW configurations.

### 1. Active HIGH LED Blinking
- The LED turns **ON** when the output is set to **HIGH** (`digitalWrite(ledPin, HIGH)`).
- The LED turns **OFF** when the output is set to **LOW** (`digitalWrite(ledPin, LOW)`).
- Commonly used in most basic Arduino LED circuits.

### 2. Active LOW LED Blinking
- The LED turns **ON** when the output is set to **LOW** (`digitalWrite(ledPin, LOW)`).
- The LED turns **OFF** when the output is set to **HIGH** (`digitalWrite(ledPin, HIGH)`).
- Useful when using an **open-drain** or **common-anode** configuration.

## Resistor Calculation

To protect the LED and ensure safe operation, a current-limiting resistor is required. The resistor value is calculated using Ohm's Law:

**Formula:**
 R = (V_supply - V_LED) / I

Where:
- **V_supply** = 5V (Arduino GPIO output voltage)
- **V_LED** = 2V (Forward voltage drop of the LED)
- **I** = 10-20mA (Safe operating current range for the LED)

**Calculation:**

- For **10mA** current:  R = (5V - 2V)/0.01A = 300Ω
- For **20mA** current: R = (5V - 2V)/0.02A = 150Ω
- A **220Ω resistor** is commonly used, limiting the current to approximately 13.6mA.

## Circuit Diagrams

### Active HIGH Configuration
<img src="./Assets/image_high.gif" width="400" height="400">

1. Connect the **positive (longer) leg** of the LED to **pin 13** of the Arduino.
2. Connect a **220Ω resistor** in series with the **negative (shorter) leg** of the LED.
3. Connect the other end of the resistor to **GND (ground)** on the Arduino.
   
Try the simulation of this project online: [Wokwi Simulation](https://wokwi.com/projects/422324100418215937)

### Active LOW Configuration
<img src="./Assets/image_low.gif" width="400" height="400">

1. Connect the **negative (shorter) leg** of the LED to **pin 13** of the Arduino.
2. Connect a **220Ω resistor** in series with the **positive (longer) leg** of the LED.
3. Connect the other end of the resistor to **VCC (5V)** on the Arduino.

Try the simulation of this project online: [Wokwi Simulation](https://wokwi.com/projects/422745920995800065)

## Arduino Code

### Active HIGH LED Blinking
```cpp
#define ledPin 13  // Define the digital pin for the LED

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an OUTPUT
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn ON the LED
  delay(1000); // Wait for 1 second
  digitalWrite(ledPin, LOW); // Turn OFF the LED
  delay(1000); // Wait for 1 second
}
```

### Active LOW LED Blinking
```cpp
#define ledPin 13  // Define the digital pin for the LED

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an OUTPUT
}

void loop() {
  digitalWrite(ledPin, LOW); // Turn ON the LED
  delay(1000); // Wait for 1 second
  digitalWrite(ledPin, HIGH); // Turn OFF the LED
  delay(1000); // Wait for 1 second
}
```

## Explanation of Code

- **setup():** Runs once when the Arduino is powered on. It initializes pin 13 as an output.
- **loop():** Runs continuously:
  - In **Active HIGH mode**, the LED turns ON when the pin is HIGH and OFF when the pin is LOW.
  - In **Active LOW mode**, the LED turns ON when the pin is LOW and OFF when the pin is HIGH.

## Modifications and Experimentation

- **Changing Blink Speed:** Modify the delay values to increase or decrease the LED blinking rate.
- **Using Different Pins:** Instead of pin 13, try using other digital pins (e.g., pin 7, pin 8) and update the `#define ledPin` accordingly.

## Expected Output

- The LED will blink with a 1-second ON and 1-second OFF cycle indefinitely in both configurations.

## Troubleshooting

- **LED Not Blinking:** Check the connections, especially the resistor and polarity of the LED.
- **Dim LED:** Use a lower resistance (e.g., 150Ω) to allow more current flow.
- **Wrong Pin Used:** Ensure the correct pin number is defined in the code.

## Notes

- If using an external LED instead of the built-in LED on pin 13, ensure a **resistor** is used to avoid excessive current.
- The internal LED on the Arduino board is also connected to pin 13 and will blink in sync with an external LED in the active HIGH configuration, while in the active LOW configuration, it will behave oppositely.
- The same logic can be applied to control other output devices, such as buzzers or relays.

## Applications

- Basic electronics learning
- Microcontroller programming practice
- Visual indicators in automation projects
- Debugging aid for other Arduino projects

