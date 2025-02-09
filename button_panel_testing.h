#ifndef __BUTTON_PANEL_TESTING_H
#define __BUTTON_PANEL_TESTING_H

#define RED_LED_PIN 2
#define YELLOW_LED_PIN 3
#define GREEN_LED_PIN 4
#define BLUE_LED_PIN 5

#define RED_BUTTON_PIN 8
#define YELLOW_BUTTON_PIN 9
#define GREEN_BUTTON_PIN 10
#define BLUE_BUTTON_PIN 11

enum COLOR_STATES {
  RED, YELLOW, GREEN, BLUE
};

byte button_states[4] = {LOW, LOW, LOW, LOW};
byte previous_button_states[4] = {LOW, LOW, LOW, LOW};

byte led_states[4] = {LOW, LOW, LOW, LOW};

unsigned long debounce_duration = 50; // in ms
unsigned long lastUpdateTime = 0;

void init_leds();
void init_buttons();

void update_button_states();
void update_led(enum COLOR_STATES state);

#endif