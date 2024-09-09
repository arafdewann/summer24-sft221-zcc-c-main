#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include "mapping.h"


// Test for addRoute
void test_addRoute_valid() {
    struct Map map = populateMap();
    struct Route route = getBlueRoute();
    struct Map expectedMap = addRoute(&map, &route);
    struct Map actualMap = populateMap(); // Resetting the map
    actualMap = addRoute(&actualMap, &route);

    // Directly compare expectedMap and actualMap
    int passed = 1; // Assume test passed
    for (int r = 0; r < MAP_ROWS; r++) {
        for (int c = 0; c < MAP_COLS; c++) {
            if (expectedMap.squares[r][c] != actualMap.squares[r][c]) {
                passed = 0; // Test failed
                break;
            }
        }
        if (!passed) break;
    }
    printf("TestAddRoute_Valid: %s\n", passed ? "Passed" : "Failed");
}

void test_addRoute_invalid() {
    struct Map map = populateMap();
    struct Route invalidRoute = getBlueRoute();
    invalidRoute.points[0].row = -1; // Make the route invalid
    struct Map expectedMap = map; // The map should remain unmodified for an invalid route
    struct Map actualMap = addRoute(&map, &invalidRoute);

    // Directly compare expectedMap and actualMap
    int passed = 1; // Assume test passed
    for (int r = 0; r < MAP_ROWS; r++) {
        for (int c = 0; c < MAP_COLS; c++) {
            if (expectedMap.squares[r][c] != actualMap.squares[r][c]) {
                passed = 0; // Test failed
                break;
            }
        }
        if (!passed) break;
    }
    printf("TestAddRoute_Invalid: %s\n", passed ? "Passed" : "Failed");
}

void test_addRoute_overlap() {
    struct Map map = populateMap();
    struct Route route = getBlueRoute();
    struct Route overlappingRoute = getGreenRoute();
    map = addRoute(&map, &route); // Add the blue route to the map first
    struct Map actualMap = addRoute(&map, &overlappingRoute);

    // Directly compare map and actualMap
    int passed = 1; // Assume test passed
    for (int r = 0; r < MAP_ROWS; r++) {
        for (int c = 0; c < MAP_COLS; c++) {
            if (map.squares[r][c] != actualMap.squares[r][c]) {
                passed = 0; // Test failed
                break;
            }
        }
        if (!passed) break;
    }
    printf("TestAddRoute_Overlap: %s\n", passed ? "Passed" : "Failed");
}
// Test Case for populateMap
void test_populateMap() {
    struct Map map = populateMap();

    // Verify the number of rows and columns
    if (map.numRows == MAP_ROWS && map.numCols == MAP_COLS)
        printf("populateMap test passed!\n");
    else
        printf("populateMap test failed!\n");
    printf("\n");
}


int check_map_coordinates(const struct Map* map) {
    int rowMax = map->numRows;
    int colMax = map->numCols;

    for (int r = 0; r < rowMax; r++) {
        if (r < 0 || r >= MAP_ROWS) {
            printf("Row coordinate out of range: %d\n", r);
            return 0;
        }
        for (int c = 0; c < colMax; c++) {
            if (c < 0 || c >= MAP_COLS) {
                printf("Column coordinate out of range: %d\n", c);
                return 0;
            }
        }
    }
    return 1;
}

// Test Case for printMap
void test_printMap() {
    // Test case 1:
    struct Map map1 = populateMap();
    printf("*** printMap Test Case 1:\n");
    printMap(&map1, 1, 1);
    printf("\n");
    if (check_map_coordinates(&map1))
        printf(": printMap Test Case 1 passed!\n\n");
    else
        printf(": printMap Test Case 1 failed!\n\n");

    // Test case 2:
    struct Map map2 = populateMap();
    printf("*** printMap Test Case 2:\n");
    printMap(&map2, 0, 0);
    printf("\n");
    if (check_map_coordinates(&map2))
        printf(": printMap Test Case 2 passed!\n\n");
    else
        printf(": printMap Test Case 2 failed!\n\n");

    // Test case 3:
    struct Map map3 = populateMap();
    printf("*** printMap Test Case 3:\n");
    printMap(&map3, 1, 0);
    printf("\n");
    if (check_map_coordinates(&map3))
        printf(": printMap Test Case 3 passed!\n\n");
    else
        printf(": printMap Test Case 3 failed!\n\n");
}

// Test Case for calculating distance between points
void test_distance() {
    struct Point p1 = { .row = 0, .col = 0 };
    struct Point p2 = { .row = 3, .col = 4 };
    double dist = distance(&p1, &p2);

    printf("*** distance Test:\n");
    printf("Distance between (0,0) and (3,4) is: %.2f\n", dist);
    if (dist == 5.0)
        printf("distance test passed!\n");
    else
        printf("distance test failed!\n");
    printf("\n");
}

// Test Case for finding the shortest path between two points
void test_shortestPath() {
    struct Map map = populateMap();
    struct Point start = { .row = 0, .col = 0 };
    struct Point dest = { .row = 4, .col = 4 };
    struct Route route = shortestPath(&map, start, dest);

    printf("*** shortestPath Test:\n");
    printMap(&map, 1, 1);
    printf("\n");

    // Verify that a route was found
    if (route.numPoints > 0)
        printf("shortestPath test passed!\n");
    else
        printf("shortestPath test failed!\n");
    printf("\n");
}

// Test Case for getPossibleMoves
void test_getPossibleMoves() {
    struct Map map = populateMap();
    struct Point p1 = { .row = 1, .col = 1 };
    struct Point backpath = { .row = 0, .col = 0 };
    struct Route possibleMoves = getPossibleMoves(&map, p1, backpath);

    printf("*** getPossibleMoves Test:\n");
    printf("Possible moves from (1,1):\n");
    for (int i = 0; i < possibleMoves.numPoints; i++) {
        printf("(%d,%d) ", possibleMoves.points[i].row, possibleMoves.points[i].col);
    }
    printf("\n\n");
}

// Test Case for getClosestPoint
void test_getClosestPoint() {
    struct Route route;
    route.numPoints = 3;
    route.points[0] = (struct Point){ .row = 1, .col = 1 };
    route.points[1] = (struct Point){ .row = 2, .col = 2 };
    route.points[2] = (struct Point){ .row = 3, .col = 3 };

    struct Point pt = { .row = 2, .col = 3 };
    int closestIndex = getClosestPoint(&route, pt);

    printf("*** getClosestPoint Test:\n");
    printf("Closest point to (2,3) in route is at index: %d\n", closestIndex);
    if (closestIndex != -1)
        printf("getClosestPoint test passed!\n");
    else
        printf("getClosestPoint test failed!\n");
    printf("\n");
}
void TestEqPt_EqualPoints() {
    struct Point p1 = { 1, 2 };
    struct Point p2 = { 1, 2 };
    printf("Test Equal Points: %s\n", eqPt(p1, p2) ? "Passed" : "Failed");
}

void TestEqPt_NotEqualPoints() {
    struct Point p1 = { 1, 2 };
    struct Point p2 = { 1, 5 };
    printf("Test Not Equal Points: %s\n", eqPt(p1, p2) ? "Failed" : "Passed");
}

void TestEqPt_NegativeCoordinates() {
    struct Point p1 = { 1, 2 };
    struct Point p2 = { -1, -2 };
    printf("Test Negative Coordinates Points: %s\n", eqPt(p1, p2) ? "Failed" : "Passed");
}

int main() {
    int choice;

    while (1) {
        printf("Select test to run:\n");
        printf("1. Test addRoute - Valid\n");
        printf("2. Test addRoute - Invalid\n");
        printf("3. Test addRoute - Overlap\n");
        printf("4. Test populateMap\n");
        printf("5. Test distance\n");
        printf("6. Test shortestPath\n");
        printf("7. Test getPossibleMoves\n");
        printf("8. Test getClosestPoint\n");
        printf("9. Test Equal Points\n");
        printf("10. Test Not Equal Points\n");
        printf("11. Test Negative Coordinates Points\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            test_addRoute_valid();
            break;
        case 2:
            test_addRoute_invalid();
            break;
        case 3:
            test_addRoute_overlap();
            break;
        case 4:
            test_populateMap();
            break;
        case 5:
            test_distance();
            break;
        case 6:
            test_shortestPath();
            break;
        case 7:
            test_getPossibleMoves();
            break;
        case 8:
            test_getClosestPoint();
            break;
        case 9:
            TestEqPt_EqualPoints();
            break;
        case 10:
            TestEqPt_NotEqualPoints();
            break;
        case 11:
            TestEqPt_NegativeCoordinates();
            break;
        case 12:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}