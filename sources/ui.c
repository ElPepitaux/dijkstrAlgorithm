/*
** ELPEPITAUX PROJECT, 2026
** Dijkstra
** File description:
** ui
*/

#include "ui.h"

ui_t *init_ui(void)
{
    ui_t *ui = malloc(sizeof(ui_t));

    if (!ui)
        return NULL;
    ui->window = sfRenderWindow_create((sfVideoMode){800, 600, 32},
        "Dijkstra", sfClose, NULL);
    if (!ui->window) {
        free(ui);
        return NULL;
    }
    sfRenderWindow_setFramerateLimit(ui->window, 60);
    ui->should_close = 0;
    return ui;
}

graph_ui *init_graph_ui(void)
{
    graph_ui *gui = malloc(sizeof(graph_ui));

    if (!gui)
        return NULL;
    gui->vertex_shape = sfCircleShape_create();
    if (!gui->vertex_shape) {
        free(gui);
        return NULL;
    }
    sfCircleShape_setRadius(gui->vertex_shape, 10);
    sfCircleShape_setFillColor(gui->vertex_shape, sfBlue);
    return gui;
}

void destroy_ui(ui_t *ui)
{
    if (ui) {
        if (ui->window)
            sfRenderWindow_destroy(ui->window);
        free(ui);
    }
}

void destroy_graph_ui(graph_ui *gui)
{
    if (gui) {
        if (gui->vertex_shape)
            sfCircleShape_destroy(gui->vertex_shape);
        free(gui);
    }
}

void handle_events(ui_t *ui)
{
    while (sfRenderWindow_pollEvent(ui->window, &ui->event)) {
        if (ui->event.type == sfEvtClosed)
            ui->should_close = 1;
    }
}

void draw_node(ui_t *ui, graph_ui *gui, node_t *node)
{
    if (node->type == FINAL_PATH)
        sfCircleShape_setFillColor(gui->vertex_shape, sfRed);
    else if (node->visited == VISITED)
        sfCircleShape_setFillColor(gui->vertex_shape, sfGreen);
    else
        sfCircleShape_setFillColor(gui->vertex_shape, sfGray);
    sfCircleShape_setPosition(gui->vertex_shape, (sfVector2f){node->pos.x * 50, node->pos.y * 50});
    sfRenderWindow_drawCircleShape(ui->window, gui->vertex_shape, NULL);
}

float get_delta_time(void)
{
    static sfClock *clock = NULL;

    if (!clock)
        clock = sfClock_create();
    sfTime time = sfClock_restart(clock);
    return time.microseconds / 1000000.0f;
}