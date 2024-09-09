
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <iostream>

#define MAX_ROUTE 100
#define MAX_WEIGHT 1200
#define MAX_VOLUME 50

struct Point {
    int row;
    int col;
};

struct Route {
    struct Point points[MAX_ROUTE];
};

struct Truck {
    struct Route route;
    double cargoWeight;
    double cargoVolume;
};

struct Shipment {
    struct Point destination;
    int weight;
    int size;
};

struct Map {
    int numRows;
    int numCols;
    int** squares;
};

double calculateDistance(struct Point point1, struct Point point2) {
    double dRow = point1.row - point2.row;
    double dCol = point1.col - point2.col;
    return sqrt(dRow * dRow + dCol * dCol);
}

int getBestRoute(struct Route* routes[MAX_ROUTE], struct Shipment* shipment, int size) {
    int shortestDistance = INT_MAX;
    int bestRouteIndex = -1;
    for (int i = 0; i < size; i++) {
        double routeDistance = calculateDistance(routes[i]->points[0], shipment->destination);
        if (routeDistance < shortestDistance) {
            shortestDistance = (int)routeDistance;
            bestRouteIndex = i;
        }
    }
    return bestRouteIndex;
}

int findTruckForShipment(struct Map map, struct Truck trucks[], int numTrucks, struct Shipment shipment) {
    int bestTruckIndex = -1;
    double shortestDistance = INT_MAX;
    for (int i = 0; i < numTrucks; i++) {
        struct Point truckPosition = trucks[i].route.points[0];
        double truckDistance = calculateDistance(truckPosition, shipment.destination);
        if (truckDistance < shortestDistance && trucks[i].cargoWeight + shipment.weight <= MAX_WEIGHT && trucks[i].cargoVolume + shipment.size <= MAX_VOLUME) {
            shortestDistance = truckDistance;
            bestTruckIndex = i;
        }
    }
    return bestTruckIndex;
}

void test_calculateDistance() {
    struct Point p1 = {0, 0};
    struct Point p2 = {3, 4};
    double result = calculateDistance(p1, p2);
    if (result == 5.0) {
        printf("calculateDistance test case 1 passed!\n");
    } else {
        printf("calculateDistance test case 1 failed!\n");
    }

    p2 = (struct Point){6, 8};
    result = calculateDistance(p1, p2);
    if (result == 10.0) {
        printf("calculateDistance test case 2 passed!\n");
    } else {
        printf("calculateDistance test case 2 failed!\n");
    }

    p1 = (struct Point){-5, -5};
    p2 = (struct Point){5, 5};
    result = calculateDistance(p1, p2);
    if (result == sqrt(200)) {
        printf("calculateDistance test case 3 passed!\n");
    } else {
        printf("calculateDistance test case 3 failed!\n");
    }

    p1 = p2 = (struct Point){1, 1};
    result = calculateDistance(p1, p2);
    if (result == 0.0) {
        printf("calculateDistance test case 4 passed!\n");
    } else {
        printf("calculateDistance test case 4 failed!\n");
    }
}

void test_getBestRoute() {
    struct Route routes[MAX_ROUTE];
    struct Shipment shipment = {{5, 5}, 100, 10};

    routes[0].points[0] = (struct Point){0, 0};
    routes[1].points[0] = (struct Point){3, 4};
    routes[2].points[0] = (struct Point){6, 8};

    int result = getBestRoute(routes, &shipment, 3);
    if (result == 1) {
        printf("getBestRoute test case 1 passed!\n");
    } else {
        printf("getBestRoute test case 1 failed!\n");
    }

    shipment.destination = (struct Point){10, 10};
    result = getBestRoute(routes, &shipment, 3);
    if (result == 2) {
        printf("getBestRoute test case 2 passed!\n");
    } else {
        printf("getBestRoute test case 2 failed!\n");
    }
}

void test_findTruckForShipment() {
    struct Map map = {0}; // Dummy map for the sake of the test
    struct Truck trucks[2] = {
        {{0}, 500.0, 20.0},
        {{0}, 1000.0, 40.0}
    };
    struct Shipment shipment = {{1, 5}, 200, 10};

    int result = findTruckForShipment(map, trucks, 2, shipment);
    if (result == 0) {
        printf("findTruckForShipment test case 1 passed!\n");
    } else {
        printf("findTruckForShipment test case 1 failed!\n");
    }

    shipment.weight = 600;
    result = findTruckForShipment(map, trucks, 2, shipment);
    if (result == 1) {
        printf("findTruckForShipment test case 2 passed!\n");
    } else {
        printf("findTruckForShipment test case 2 failed!\n");
    }

    shipment.weight = 500;
    shipment.size = 35;
    result = findTruckForShipment(map, trucks, 2, shipment);
    if (result == 1) {
        printf("findTruckForShipment test case 3 passed!\n");
    } else {
        printf("findTruckForShipment test case 3 failed!\n");
    }

    shipment.weight = 800;
    shipment.size = 20;
    result = findTruckForShipment(map, trucks, 2, shipment);
    if (result == -1) {
        printf("findTruckForShipment test case 4 passed!\n");
    } else {
        printf("findTruckForShipment test case 4 failed!\n");
    }
}

int main() {
    test_calculateDistance();
    test_getBestRoute();
    test_findTruckForShipment();
    return 0;
}
