/*
** ELPEPITAUX PROJECT, 2026
** Dijkstra
** File description:
** main
*/

#include "dijkstra.h"
#include "ui.h"


node_t *update_dijkstra(node_t **graph, node_t *current, node_t *end, float delta_time)
{
    static float timer = 0;
    timer += delta_time;
    if (timer < 0.5f)
        return current;
    timer = 0;
    if (current == end) {
        find_final_path(end);
        return current;
    }
    return dijkstra_algo(graph, current, end);
}

int main(void)
{
    ui_t *ui = init_ui();
    graph_ui *gui = init_graph_ui();
    node_t **graph = create_graph(10, 10);
    dump_graph(graph, 10, 10);
    node_t *node = find_node_by_char(graph, 10, 10, 'S');
    node_t *end = find_node_by_char(graph, 10, 10, 'E');

    while (!ui->should_close) {
        float delta_time = get_delta_time();
        handle_events(ui);
        sfRenderWindow_clear(ui->window, sfBlack);

        node = update_dijkstra(graph, node, end, delta_time);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (graph[i + j * 10] != NULL)
                    draw_node(ui, gui, graph[i + j * 10]);
            }
        }
        sfRenderWindow_display(ui->window);
    }
    destroy_graph(graph, 10, 10);
    destroy_ui(ui);
    destroy_graph_ui(gui);
    return 0;
}
