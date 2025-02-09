#include "button_panel_testing.h"

void setup() {
  init_leds();
  init_buttons();
}

void loop() {
  update_button_states();
  
  update_led(RED);
  update_led(YELLOW);
  update_led(GREEN);
  update_led(BLUE);
}

void init_leds() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void init_buttons() {
  pinMode(RED_BUTTON_PIN, INPUT);
  pinMode(YELLOW_BUTTON_PIN, INPUT);
  pinMode(GREEN_BUTTON_PIN, INPUT);
  pinMode(BLUE_BUTTON_PIN, INPUT);
}

void update_button_states() {
  button_states[RED] = digitalRead(RED_BUTTON_PIN);
  button_states[YELLOW] = digitalRead(YELLOW_BUTTON_PIN);
  button_states[GREEN] = digitalRead(GREEN_BUTTON_PIN);
  button_states[BLUE] = digitalRead(BLUE_BUTTON_PIN);
}

void update_led(enum COLOR_STATES state) {
  if (millis() - last_update_time > debounce_duration) {
    byte button_state = button_states[state];

    if (button_state != previous_button_states[state]) {
      last_update_time = millis();
      previous_button_states[state] = button_state;

      if (button_state == LOW) {
        led_states[state] = led_states[state] == HIGH ? LOW : HIGH;

        digitalWrite(state + 2, led_states[state]); // this is cursed
      }
    }
  }
}
