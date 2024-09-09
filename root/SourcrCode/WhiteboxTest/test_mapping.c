#include <stdio.h>
#include "mapping.h"

void test_populateMap() {
    struct Map map = populateMap();
    // Assuming the map is populated with some default values, we can check some cells
    if (map.grid[0][0] == 0 && map.grid[1][1] == 1) {
        printf("populateMap test passed!\n");
    } else {
        printf("populateMap test failed!\n");
    }
}

void test_getBlueRoute() {
    struct Route blueRoute = getBlueRoute();
    // Assuming the blue route starts from some known point
    if (blueRoute.points[0].x == 0 && blueRoute.points[0].y == 0) {
        printf("getBlueRoute test passed!\n");
    } else {
        printf("getBlueRoute test failed!\n");
    }
}

void test_addRoute() {
    struct Map map = populateMap();
    struct Route route = getBlueRoute();
    struct Map updatedMap = addRoute(&map, &route);

    // Assuming the first point of the route is added to the map correctly
    if (updatedMap.grid[route.points[0].x][route.points[0].y] == 'X') {
        printf("addRoute test passed!\n");
    } else {
        printf("addRoute test failed!\n");
    }
}

int main() {
    test_populateMap();
    test_getBlueRoute();
    test_addRoute();
    return 0;
}
