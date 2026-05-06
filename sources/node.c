/*
** ELPEPITAUX PROJECT, 2026
** Dijkstra
** File description:
** node
*/

#include "dijkstra.h"

char g_map[10][10] = {
    {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
    {'0', '1', '1', '1', '1', '1', '1', '1', '1', '0'},
    {'0', '1', '0', '0', '0', '0', '0', '0', '1', '0'},
    {'0', '1', '0', '1', '1', '1', '1', '0', '1', '0'},
    {'0', '0', '0', '1', '0', '0', '1', '0', '1', 'E'},
    {'0', '1', '0', '1', '1', '1', '1', '0', '1', '0'},
    {'0', '1', '0', '0', '0', '0', '0', '0', '1', '0'},
    {'0', '1', '1', '1', '1', '1', '1', '1', '1', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '0', '1', '0'},
    {'S', '1', '1', '1', '1', '1', '1', '0', '0', '0'}
};

node_t *create_node(pos_t pos)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;
    node->pos = pos;
    node->distance = -1;
    node->nbr_nodes = 0;
    node->nodes = NULL;
    node->visited = UNVISITED;
    node->parent = NULL;
    if (g_map[pos.y][pos.x] == 'S')
        node->type = START;
    else if (g_map[pos.y][pos.x] == 'E')
        node->type = END;
    else
        node->type = NORMAL;
    return node;
}

void add_node(node_t *node, node_t *new_node)
{
    node->nodes = realloc(node->nodes,
        sizeof(node_t *) * (node->nbr_nodes + 1));

    if (!node->nodes)
        return;

    node->nodes[node->nbr_nodes] = new_node;
    node->nbr_nodes++;
}

node_t **create_graph(int width, int height)
{
    node_t **graph = calloc((width * height) + 1, sizeof(node_t *));
    if (!graph)
        return NULL;
    // création
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (g_map[y][x] != '1')
                graph[y * width + x] = create_node((pos_t){x, y});
            else
                graph[y * width + x] = NULL;
        }
    }

    // ajout des voisins
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            node_t *node = graph[y * width + x];
            if (!node)
                continue;
            if (y > 0 && graph[(y - 1) * width + x])
                add_node(node, graph[(y - 1) * width + x]); // haut
            if (y < height - 1 && graph[(y + 1) * width + x])
                add_node(node, graph[(y + 1) * width + x]); // bas
            if (x > 0 && graph[y * width + (x - 1)])
                add_node(node, graph[y * width + (x - 1)]); // gauche
            if (x < width - 1 && graph[y * width + (x + 1)])
                add_node(node, graph[y * width + (x + 1)]); // droite
        }
    }
    graph[width * height] = NULL; // Sentinel
    return graph;
}

void destroy_graph(node_t **graph, int width, int height)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            node_t *node = graph[y * width + x];
            if (node) {
                free(node->nodes);
                free(node);
            }
        }
    }
    free(graph);
}

void dump_graph(node_t **graph, int width, int height)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            node_t *node = graph[y * width + x];
            if (node) {
                printf("Node (y=%d, x=%d): ", node->pos.y, node->pos.x);
                for (int i = 0; i < node->nbr_nodes; i++) {
                    printf("(y=%d, x=%d) ", node->nodes[i]->pos.y, node->nodes[i]->pos.x);
                }
                printf("\n");
            }
        }
    }
}

node_t *find_node_by_char(node_t **graph, int width, int height, char target)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (g_map[y][x] == target)
                return graph[y * width + x];
        }
    }
    return NULL;
}

node_t *find_node_by_pos(node_t **graph, int width, int height, pos_t pos)
{
    if (pos.x < 0 || pos.x >= width || pos.y < 0 || pos.y >= height)
        return NULL;
    return graph[pos.y * width + pos.x];
}

void find_final_path(node_t *node)
{
    while (node) {
        printf("Final path node: (y=%d, x=%d)\n", node->pos.y, node->pos.x);
        node->type = FINAL_PATH;
        node = node->parent;
    }
}