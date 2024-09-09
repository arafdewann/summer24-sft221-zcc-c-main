#include <stdio.h>
#include "routes.h"

void test_route_struct() {
    struct Route route;
    route.route_id = 1;
    snprintf(route.start_location, sizeof(route.start_location), "Start Point");
    snprintf(route.end_location, sizeof(route.end_location), "End Point");
    route.distance = 12.5;

    if (route.route_id == 1 &&
        strcmp(route.start_location, "Start Point") == 0 &&
        strcmp(route.end_location, "End Point") == 0 &&
        route.distance == 12.5) {
        printf("Route struct test passed!\n");
    } else {
        printf("Route struct test failed!\n");
    }
}

int main() {
    test_route_struct();
    return 0;
}
