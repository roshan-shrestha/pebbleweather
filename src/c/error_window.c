#include <pebble.h>
#include "error_window.h"

Window *errorWindow;

void error_window_load(Window *window) {
	
	Layer *window_layer = window_get_root_layer(window);
}

void error_window_unload(Window *window) {
}

void error_window_create(){
  errorWindow = window_create();
  window_set_window_handlers(errorWindow, (WindowHandlers) {
    .load = error_window_load,
    .unload = error_window_unload
  });
}

void error_window_destroy() {
  window_destroy(errorWindow);
}

Window *error_window_get_window() {
  return errorWindow;
}