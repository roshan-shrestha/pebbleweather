#include <pebble.h>
#include "splash_window.h"

int main() {
  app_event_loop();
  
  splash_window_create();
  window_stack_push(splash_window_get_window(), true);
  app_event_loop();
}