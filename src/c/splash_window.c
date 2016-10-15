#include <pebble.h>
#include "splash_window.h"

Window *splashWindow;

void splash_window_load(Window *window) {
  
}

void splash_window_unload(Window *window) {
  
}

void splash_window_create(){
  splashWindow = window_create();
  window_set_window_handlers(splashWindow, (WindowHandlers) {
    .load = splash_window_load,
    .unload = splash_window_unload
  });
}

void splash_window_destroy() {
  window_destroy(splashWindow);
}

Window *splash_window_get_window() {
  return splashWindow;
}