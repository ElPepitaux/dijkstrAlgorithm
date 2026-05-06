/*
** ELPEPITAUX PROJECT, 2026
** Dijkstra
** File description:
** ui
*/

#pragma once

#include "dijkstra.h"

#include <stdlib.h>

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#define sfGray (sfColor){128, 128, 128, 255}

typedef struct ui_s {
    sfRenderWindow *window;
    sfEvent event;
    int should_close;
} ui_t;

typedef struct graph_ui {
    sfCircleShape *vertex_shape;
} graph_ui;

ui_t *init_ui(void);
graph_ui *init_graph_ui(void);
void destroy_ui(ui_t *ui);
void destroy_graph_ui(graph_ui *gui);
void handle_events(ui_t *ui);
void draw_node(ui_t *ui, graph_ui *gui, node_t *node);
float get_delta_time(void);