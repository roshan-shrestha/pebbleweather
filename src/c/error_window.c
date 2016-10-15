#include <pebble.h>
#include "error_window.h"

Window *errorWindow;
Layer *errorGraphicsLayer;
char currentErrorText[1][20];

void error_window_show(char *errorText) {
	strncpy(currentErrorText[0], errorText, sizeof(currentErrorText[0]));
	if (errorGraphicsLayer) {
		layer_mark_dirty(errorGraphicsLayer);
	}
	window_stack_push(errorWindow, true);
}

void error_graphics_proc(Layer *layer, GContext *ctx) {
	
}

void error_window_load(Window *window) {
	
	Layer *window_layer = window_get_root_layer(window);
	errorGraphicsLayer = layer_create(GRect(0, 0, 144, 168));
	layer_set_update_proc(errorGraphicsLayer, error_graphics_proc);
	layer_add_child(window_layer, errorGraphicsLayer);
}

void error_window_unload(Window *window) {
	layer_destroy(errorGraphicsLayer);
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