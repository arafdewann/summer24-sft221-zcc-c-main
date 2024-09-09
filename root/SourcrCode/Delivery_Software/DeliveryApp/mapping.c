#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "mapping.h"
#include "math.h"
#include "function_specs.h"

#define MAX_NODES 1000

struct Map populateMap()
{
    struct Map result = {
        {
            {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
            {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
            {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        },
        MAP_ROWS,
        MAP_COLS
    };
    return result;
}

int getNumRows(const struct Map* map)
{
    return map->numRows;
}

int getNumCols(const struct Map* map)
{
    return map->numCols;
}

void printMap(const struct Map* map, const int base1, const int alphaCols)
{
    //              01234567890123456
    //              1248F
    char sym[] = { " XB?G?.?Y?-?*?+?P" };
    int r, c, rowMax;

    rowMax = map->numRows + base1;

    printf("%4s", " ");
    for (c = 0; c < map->numCols; c++)
    {
        if (alphaCols) printf("%c", 'A' + c);
        else printf("%d", c % 10);
    }
    printf("\n");
    printf("%4s", " ");
    for (c = 0; c < map->numCols; c++)
    {
        printf("-");
    }
    printf("\n");

    for (r = base1; r < rowMax; r++)
    {
        printf("%3d|", r);
        for (c = 0; c < map->numCols; c++)
        {
            printf("%c", sym[map->squares[r - base1][c]]);
        }
        printf("\n");
    }
}

struct Route getBlueRoute()
{
    struct Route result = {
        {
            {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0},  // A1 to A5
            {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8}, {4, 9},  // A5 to J5
            {5, 9}, {6, 9}, {7, 9}, {8, 9}, {9, 9}, {10, 9},  // J5 to J11
            {10, 10}, {11, 10}, {12, 10}, {13, 10}, {14, 10}, {15, 10}, {16, 10}, {17, 10},  // J11 to K18
            {17, 11}, {17, 12}, {17, 13}, {17, 14}, {17, 15}, {17, 16}, {17, 17},
            {17, 18}, {17, 19}, {17, 20}, {17, 21}, {17, 22}, {17, 23}, {17, 24}  // K18 to Y18
        },
        42,
        BLUE
    };
    return result;
}

struct Route getGreenRoute()
{
    struct Route result = {
        {
            {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0},  // A1 to A5
            {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8}, {4, 9}, {4, 10}, {4, 11},  // A5 to L5
            {3, 11}, {2, 11}, {1, 11}, {0, 11},  // L5 to L1
            {0, 12}, {0, 13}, {0, 14}, {0, 15}, {0, 16}, {0, 17}, {0, 18}, {0, 19},  // L1 to T1
            {1, 19}, {2, 19}, {3, 19}, {4, 19}, {5, 19}, {6, 19}, {7, 19}, {8, 19},  // T1 to T10
            {9, 19}, {9, 20}, {9, 21}, {9, 22}, {9, 23}, {9, 24}  // T10 to Y10
        },
        42,
        GREEN
    };
    return result;
}

struct Route getYellowRoute()
{
    struct Route result = {
        {
            {0, 0}, {1, 0}, {2, 0}, {3, 0},  // A1 to A4
            {3, 1}, {3, 2}, {3, 3},  // A4 to D4
            {4, 3}, {5, 3}, {6, 3}, {7, 3}, {8, 3}, {9, 3},  // D4 to D10
            {9, 2}, {9, 1},  // D10 to B10
            {10, 1}, {11, 1}, {12, 1}, {13, 1}, {14, 1}, {15, 1}, {16, 1}, {17, 1}, {18, 1}, {19, 1},  // B10 to B20
            {19, 2}, {19, 3}, {19, 4}, {19, 5}, {19, 6}, {19, 7}, {19, 8}, {19, 9}, {19, 10},
            {19, 11}, {19, 12}, {19, 13}, {19, 14}, {19, 15}, {19, 16}, {19, 17}, {19, 18},
            {19, 19}, {19, 20}, {19, 21}, {19, 22}, {19, 23}, {19, 24}  // B20 to Y20
        },
        48,
        YELLOW
    };
    return result;
}

struct Map addRoute(const struct Map* map, const struct Route* route)
{
    int r, c;
    struct Map result = { {0}, 0 };

    for (r = 0; r < map->numRows; r++)
    {
        for (c = 0; c < map->numCols; c++)
        {
            result.squares[r][c] = map->squares[r][c];
        }
    }
    result.numRows = map->numRows;
    result.numCols = map->numCols;

    for (r = 0; r < route->numPoints; r++)
    {
        result.squares[route->points[r].row][route->points[r].col] += route->routeSymbol;
    }

    return result;
}

void addPtToRoute(struct Route* route, struct Point pt)
{
    route->points[route->numPoints++] = pt;
}

void addPointToRoute(struct Route* route, const int row, const int col)
{
    struct Point pt = { row, col };
    addPtToRoute(route, pt);
}

void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis)
{
    struct Point pt = { row, col };
    if (notThis.row != row || notThis.col != col) addPtToRoute(route, pt);
}

double distance(const struct Point* p1, const struct Point* p2)
{
    int deltaRow = p2->row - p1->row;
    int deltaCol = p2->col - p1->col;

    return sqrt((double)(deltaRow * deltaRow + deltaCol * deltaCol));
}

struct Node {
    struct Point pos;
    double f, g, h;
    struct Node* parent;
};

int compareNodes(const void* a, const void* b) {
    return ((struct Node*)a)->f < ((struct Node*)b)->f ? -1 : 1;
}

double heuristic(struct Point a, struct Point b) {
    return calculateDistance(a.row, a.col, b.row, b.col);
}

struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest) {
    struct Route result = { {0}, 0, DIVERSION };
    struct Node* openSet = malloc(MAX_NODES * sizeof(struct Node));
    struct Node* closedSet = malloc(MAX_NODES * sizeof(struct Node));
    int openCount = 0, closedCount = 0;

    openSet[openCount++] = (struct Node){ start, 0, 0, heuristic(start, dest), NULL };

    while (openCount > 0) {
        qsort(openSet, openCount, sizeof(struct Node), compareNodes);
        struct Node current = openSet[--openCount];

        if (current.pos.row == dest.row && current.pos.col == dest.col) {
            // Reconstructing the path
            struct Node* path = &current;
            int pathLength = 0;
            while (path) {
                result.points[pathLength++] = path->pos;
                path = path->parent;
            }
            result.numPoints = pathLength;

            // Reverses the path
            for (int i = 0; i < pathLength / 2; i++) {
                struct Point temp = result.points[i];
                result.points[i] = result.points[pathLength - 1 - i];
                result.points[pathLength - 1 - i] = temp;
            }

            free(openSet);
            free(closedSet);
            return result;
        }

        closedSet[closedCount++] = current;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;

                struct Point neighbor = { current.pos.row + dx, current.pos.col + dy };

                if (neighbor.row < 0 || neighbor.row >= map->numRows ||
                    neighbor.col < 0 || neighbor.col >= map->numCols ||
                    map->squares[neighbor.row][neighbor.col] == 1) continue;

                double tentative_g = current.g + 1;

                int skip = 0;
                for (int i = 0; i < closedCount; i++) {
                    if (closedSet[i].pos.row == neighbor.row && closedSet[i].pos.col == neighbor.col) {
                        skip = 1;
                        break;
                    }
                }
                if (skip) continue;

                int found = 0;
                for (int i = 0; i < openCount; i++) {
                    if (openSet[i].pos.row == neighbor.row && openSet[i].pos.col == neighbor.col) {
                        found = 1;
                        if (tentative_g < openSet[i].g) {
                            openSet[i].g = tentative_g;
                            openSet[i].f = openSet[i].g + openSet[i].h;
                            openSet[i].parent = &closedSet[closedCount - 1];
                        }
                        break;
                    }
                }

                if (!found) {
                    openSet[openCount++] = (struct Node){
                        neighbor,
                        tentative_g + heuristic(neighbor, dest),
                        tentative_g,
                        heuristic(neighbor, dest),
                        &closedSet[closedCount - 1]
                    };
                }
            }
        }
    }

    free(openSet);
    free(closedSet);
    return result;  // Return empty route if no path found
}

struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath)
{
    struct Route result = { {0,0}, 0, DIVERSION };

    if (p1.row > 0)
    {
        if (map->squares[p1.row - 1][p1.col] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col, backpath);	// square above
        if (p1.col > 0 && map->squares[p1.row - 1][p1.col - 1] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col - 1, backpath);	// top left
        if (p1.col < (map->numCols - 1) && map->squares[p1.row - 1][p1.col + 1] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col + 1, backpath);	// top right
    }
    if (p1.col > 0 && map->squares[p1.row][p1.col - 1] != 1)addPointToRouteIfNot(&result, p1.row, p1.col - 1, backpath);	// left
    if (p1.col < (map->numCols - 1) && map->squares[p1.row][p1.col + 1] != 1)addPointToRouteIfNot(&result, p1.row, p1.col + 1, backpath);	// right
    if (p1.row < (map->numRows - 1))
    {
        if (map->squares[p1.row + 1][p1.col] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col, backpath);	// square below
        if (p1.col > 0 && map->squares[p1.row + 1][p1.col - 1] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col - 1, backpath);	// bot left
        if (p1.col < (map->numCols - 1) && map->squares[p1.row + 1][p1.col + 1] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col + 1, backpath);	// top right
    }

    return result;
}

int eqPt(const struct Point p1, const struct Point p2)
{
    return p1.row == p2.row && p1.col == p2.col;
}

int getClosestPoint(const struct Route* route, const struct Point pt)
{
    int i, closestIdx = -1;
    double closestDist = 999999.99, dist;

    for (i = 0; i < route->numPoints; i++)
    {
        dist = distance(&pt, &route->points[i]);
        if (dist < closestDist)
        {
            closestDist = dist;
            closestIdx = i;
        }
    }
    return closestIdx;
}


