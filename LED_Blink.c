#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Simulate hardware registers
unsigned char PORT_LED = 0;
unsigned char PORT_BUTTON = 0;

// LED bit positions
#define RED_LED    0x01
#define YELLOW_LED 0x02
#define GREEN_LED  0x04

// State machine states
typedef enum {
    STATE_RED,
    STATE_GREEN,
    STATE_YELLOW
} traffic_state_t;

// Global variables
traffic_state_t current_state = STATE_RED;
int state_timer = 0;
int button_pressed = 0;

// Function prototypes
void update_leds(void);
void simulate_button_press(void);
void traffic_light_controller(void);
void delay_simulation(int ms);

int main() {
    printf("Traffic Light Controller Simulation\n");
    printf("===================================\n");

    srand(time(NULL));

    // Simulate 20 traffic light cycles
    for(int cycle = 0; cycle < 200; cycle++) {
        // Simulate random button press
        if(rand() % 20 == 0) {
            button_pressed = 1;
            printf("Button pressed!\n");
        }

        traffic_light_controller();
        update_leds();
        delay_simulation(100);
        state_timer++;
    }

    return 0;
}

void traffic_light_controller(void) {
    switch(current_state) {
        case STATE_RED:
            PORT_LED = RED_LED;
            if(state_timer >= 50) {  // 5 seconds
                current_state = STATE_GREEN;
                state_timer = 0;
            }
            break;

        case STATE_GREEN:
            PORT_LED = GREEN_LED;
            if(state_timer >= 40 || button_pressed) {  // 4 seconds or button
                current_state = STATE_YELLOW;
                state_timer = 0;
                button_pressed = 0;
            }
            break;

        case STATE_YELLOW:
            PORT_LED = YELLOW_LED;
            if(state_timer >= 20) {  // 2 seconds
                current_state = STATE_RED;
                state_timer = 0;
            }
            break;
    }
}

void update_leds(void) {
    static int last_led_state = -1;

    if(PORT_LED != last_led_state) {
        printf("LEDs: ");
        if(PORT_LED & RED_LED) printf("RED ");
        if(PORT_LED & YELLOW_LED) printf("YELLOW ");
        if(PORT_LED & GREEN_LED) printf("GREEN ");
        printf("(Timer: %d)\n", state_timer);
        last_led_state = PORT_LED;
    }
}

void delay_simulation(int ms) {
    // Simple delay simulation
    for(volatile int i = 0; i < ms * 1000; i++);
}
