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
    Point points[MAX_ROUTE];
};

struct Truck {
    Route route;
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

