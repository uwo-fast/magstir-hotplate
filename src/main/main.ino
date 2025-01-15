// UNTESTED CODE - FOR PLANNING PURPOSES ONLY

#include <LiquidCrystal_I2C.h> // LCD library for I2C LCD
#include <PID_v1.h>            // PID controller library for temperature regulation

// Pin Definitions
const int motorPin = 9;          // PWM pin for motor control
const int tempPin = A0;          // Analog pin for temperature sensor (e.g., LM35)
const int heatingElementPin = 6; // PWM pin for heating element control (e.g., SSR)

// LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address 0x27, 16 columns, 2 rows

// Motor control variables
int motorSpeed = 0;     // PWM value for motor speed
int motorRPM = 1000;    // Desired motor RPM (modifiable)
int motorMinRPM = 50;   // Minimum RPM
int motorMaxRPM = 2000; // Maximum RPM

// Temperature Control (PID setup)
double setpoint = 100.0; // Desired temperature in Celsius (modifiable)
double inputTemp = 0.0;  // Current temperature from sensor
double outputTemp = 0.0; // Output to control heating element

// PID variables
double Kp = 2.0, Ki = 5.0, Kd = 1.0; // PID constants
PID tempPID(&inputTemp, &outputTemp, &setpoint, Kp, Ki, Kd, DIRECT);

// Timers for non-blocking delays
unsigned long previousMillis = 0;
const long interval = 500; // Update interval (500ms)

// Setup code to initialize components
void setup()
{
    // Initialize LCD
    lcd.begin(16, 2);
    lcd.print("MagStir HotPlate");

    // Initialize motor pin
    pinMode(motorPin, OUTPUT);

    // Initialize heating element pin
    pinMode(heatingElementPin, OUTPUT);

    // Initialize PID controller
    tempPID.SetMode(AUTOMATIC);

    // Start serial communication for debugging
    Serial.begin(9600);
}

// Function to read temperature from sensor
float readTemperature()
{
    int rawValue = analogRead(tempPin);
    float voltage = rawValue * (5.0 / 1023.0);  // Convert to voltage
    float temperatureC = (voltage - 0.5) * 100; // Assuming LM35 temp sensor
    return temperatureC;
}

// Function to update the motor speed (non-blocking)
void updateMotorSpeed()
{
    motorSpeed = map(motorRPM, motorMinRPM, motorMaxRPM, 0, 255);
    analogWrite(motorPin, motorSpeed); // Control motor speed via PWM
}

// Function to update temperature control (PID loop)
void updateTemperatureControl()
{
    inputTemp = readTemperature();              // Get current temperature
    tempPID.Compute();                          // Run PID control loop
    analogWrite(heatingElementPin, outputTemp); // Control heating element (SSR)
}

// Main loop, runs periodically
void loop()
{
    unsigned long currentMillis = millis();

    // Check if it's time to update the motor and temperature control
    if (currentMillis - previousMillis >= interval)
    {
        // Save the last time we updated
        previousMillis = currentMillis;

        // Update motor speed
        updateMotorSpeed();

        // Update temperature control
        updateTemperatureControl();

        // Display current data on LCD
        lcd.setCursor(0, 1);
        lcd.print("Temp: ");
        lcd.print(inputTemp);
        lcd.print("C RPM: ");
        lcd.print(motorRPM);

        // Print debug info to Serial Monitor
        Serial.print("Temp: ");
        Serial.print(inputTemp);
        Serial.print(" RPM: ");
        Serial.println(motorRPM);
    }
}
