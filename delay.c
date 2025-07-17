#include <stdio.h>

// Simple delay function (not accurate, just for example)
void delay(int ms) {
    // Loop to simulate a delay (e.g., 1ms delay)
    for (int i = 0; i < ms * 10000; i++) {
        // Empty loop for busy-waiting
    }
}

int main() {
    printf("Starting delay...\n");
    delay(10000);  // Delay for 1000ms (1 second)
    printf("Delay complete.\n");

    return 0;
}
