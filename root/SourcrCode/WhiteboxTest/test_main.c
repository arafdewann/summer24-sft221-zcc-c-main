#include <stdio.h>
#include "mapping.h"

void test_main() {
    struct Map baseMap = populateMap();
    struct Route blueRoute = getBlueRoute();
    struct Map routeMap = addRoute(&baseMap, &blueRoute);

    // Here we assume that the first point of blueRoute is mapped correctly
    if (routeMap.grid[blueRoute.points[0].x][blueRoute.points[0].y] == 'X') {
        printf("Main function test passed!\n");
    } else {
        printf("Main function test failed!\n");
    }
}

int main() {
    test_main();
    return 0;
}
