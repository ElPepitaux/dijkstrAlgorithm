/*
** ELPEPITAUX PROJECT, 2026
** Dijkstra
** File description:
** algo
*/

#include "dijkstra.h"

node_t *dijkstra_algo(node_t **graph, node_t *node, node_t *end)
{
    (void)end;
    node_t *current = node;

    current->visited = VISITED;
    for (int j = 0; j < current->nbr_nodes; j++) {
        node_t *neighbor = current->nodes[j];
        if (neighbor->visited == UNVISITED) {
            int new_distance = current->distance + 1;
            if (neighbor->distance == -1 || new_distance < neighbor->distance) {
                neighbor->distance = new_distance;
                neighbor->parent = current;
            }
        }
    }
    node_t *next_node = NULL;
    for (int k = 0; k < (10 * 10); k++) {
        node_t *node = graph[k];
        if (node && node->visited == UNVISITED && node->distance != -1) {
            if (!next_node || node->distance < next_node->distance) {
                next_node = node;
            }
        }
    }
    printf("Current: (y=%d, x=%d), Next: (y=%d, x=%d)\n",
        current->pos.y, current->pos.x,
        next_node ? next_node->pos.y : -1, next_node ? next_node->pos.x : -1);

    return next_node;
}