# Dijkstra Algorithm Visualization

A visual implementation of Dijkstra's shortest path algorithm using C and SFML graphics library. This project demonstrates how the algorithm finds the optimal path between two points on a grid.

## Description

This project implements Dijkstra's algorithm to find the shortest path between a start point (S) and an end point (E) on a 10x10 grid. The visualization uses CSFML (C bindings for SFML) to display:

- **Grid nodes** as circular vertices
- **Connections** between adjacent nodes
- **Algorithm progression** in real-time, showing visited and unvisited nodes
- **Final path** highlighted once the algorithm completes

The algorithm explores nodes step-by-step with a 0.5-second interval between updates, making the pathfinding process easy to follow and understand.

## Dependencies

Before building, install the following:

- **CSFML** - C bindings for the Simple Fast Multimedia Library

  On Ubuntu/Debian:
  ```bash
  sudo apt-get install libcsfml-dev
  ```

- **GCC** - C compiler (usually pre-installed)

## Building

To build the project, use the provided Makefile:

```bash
# Build the project
make

# Run the executable
./dijkstra
```

### Build Targets

- `make all` - Build the project (default)
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Clean rebuild
- `make debug` - Build with debugging symbols (-g flag)

## How to Run

After building, simply run:

```bash
./dijkstra
```

A window will open showing the 10x10 grid. The algorithm will automatically start finding the shortest path from the start node (S) to the end node (E).

## Future Implementation

Planned features for future versions:

- **Interactive UI Links** - Click on nodes to set custom start and end points
- **File-based Map Loading** - Load custom grid maps from text files
  - Supports custom grid dimensions
  - Define obstacles, start points, and end points in map files
  - Parse map format to initialize the graph dynamically
- **Pause/Resume Controls** - Pause the algorithm to study specific steps
- **Speed Control** - Adjust animation speed for better visualization
- **Algorithm Statistics** - Display algorithm metrics (nodes visited, path length, execution time)
- **Obstacle Support** - Add walls and obstacles that block pathfinding

## Project Structure

```
dijkstrAlgorithm/
├── headers/
│   ├── dijkstra.h    # Algorithm and graph structures
│   └── ui.h          # UI and graphics functions
├── sources/
│   ├── algo.c        # Dijkstra algorithm implementation
│   ├── main.c        # Main program loop and visualization
│   ├── node.c        # Node and graph data structures
│   └── ui.c          # UI and rendering functions
├── Makefile
├── README.md
└── LICENSE
```

## Author

ELPEPITAUX PROJECT, 2026

