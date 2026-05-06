/*
** ELPEPITAUX PROJECT, 2026
** Dijkstra
** File description:
** dijkstra
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>

extern char g_map[10][10];

typedef struct pos_s {
    int x;
    int y;
} pos_t;

enum Visited {
    VISITED = 1,
    UNVISITED = 0
};

enum NodeType {
    START,
    END,
    NORMAL,
    FINAL_PATH
};

typedef struct node_s {
    pos_t pos;

    int distance;

    int nbr_nodes;
    struct node_s **nodes;

    enum Visited visited;

    struct node_s *parent;

    enum NodeType type;
} node_t;

node_t *create_node(pos_t pos);
void add_node(node_t *node, node_t *new_node);
node_t **create_graph(int width, int height);
node_t *find_node_by_char(node_t **graph, int width, int height, char target);
node_t *find_node_by_pos(node_t **graph, int width, int height, pos_t pos);
void dump_graph(node_t **graph, int width, int height);
void find_final_path(node_t *node);


void destroy_graph(node_t **graph, int width, int height);

node_t *dijkstra_algo(node_t **graph, node_t *node, node_t *end);