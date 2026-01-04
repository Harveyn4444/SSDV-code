#include <wiringPi.h>
#include <iostream>
#include <chrono>
#include <thread>

constexpr int LED_PIN1 = 16;
constexpr int LED_PIN2 = 20;
constexpr int LED_PIN3 = 21;

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int main(int argc, char * argv[]){
    //Initialise wiringPi and check if it succeeds
    // if (wiringPiSetup() == -1){
    if (wiringPiSetupGpio() == -1){
        cerr << "FAILED to initialise wiringPi" << endl;
        return 1;
    }

    pinMode(LED_PIN1, OUTPUT); //Set the LED pin to output
    pinMode(LED_PIN2, OUTPUT); //Set the LED pin to output
    pinMode(LED_PIN3, OUTPUT); //Set the LED pin to output

    cout << "Blinking LED connected to GPIO pin" << LED_PIN1 << endl;
    cout << "Blinking LED connected to GPIO pin" << LED_PIN2 << endl;
    cout << "Blinking LED connected to GPIO pin" << LED_PIN3 << endl;
    
    while(true){
        digitalWrite(LED_PIN1, HIGH);
        digitalWrite(LED_PIN2, HIGH);
        digitalWrite(LED_PIN3, HIGH);
        sleep_for(milliseconds(500));

        digitalWrite(LED_PIN1, LOW);
        digitalWrite(LED_PIN2, LOW);
        digitalWrite(LED_PIN3, LOW);
        sleep_for(milliseconds(500));

        // LED1
        digitalWrite(LED_PIN1, HIGH);
        sleep_for(milliseconds(500));
        digitalWrite(LED_PIN1, LOW);
        sleep_for(milliseconds(500));

        // LED2
        digitalWrite(LED_PIN2, HIGH);
        sleep_for(milliseconds(500));
        digitalWrite(LED_PIN2, LOW);
        sleep_for(milliseconds(500));

        // LED3
        digitalWrite(LED_PIN3, HIGH);
        sleep_for(milliseconds(500));
        digitalWrite(LED_PIN3, LOW);
        sleep_for(milliseconds(500));

    }
    return 0;
}
