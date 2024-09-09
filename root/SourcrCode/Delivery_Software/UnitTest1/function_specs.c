#pragma once
#include "function_specs.h"
#include "math.h"
#include <string.h>

/**
 * @brief Finds the best truck for a shipment.
 */
int findTruckForShipment(struct Map map, struct TruckCapacity trucks[], int numTrucks, struct Delivery shipment) {
    // Placeholder implementation
    for (int i = 0; i < numTrucks; i++) {
        if (trucks[i].current_load + shipment.weight <= trucks[i].max_capacity) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Calculates the Euclidean distance between two points.
 */
double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((double)(x2 - x1), 2) + pow((double)(y2 - y1), 2));
}

/**
 * @brief Determines the route for a truck.
 */
struct DeliveryRoute determineTruckRoute(struct Map map, struct Point start, struct Point destination) {
    struct DeliveryRoute route;
    // Placeholder implementation for the route calculation
    route.route_id = 1; // Example route ID
    strcpy_s(route.start_location, sizeof(route.start_location), "Start");
    strcpy_s(route.end_location, sizeof(route.end_location), "End");
    route.distance = (float)calculateDistance(start.row, start.col, destination.row, destination.col);
    return route;
}

/**
 * @brief Calculates the load for a truck.
 */
float calculateTruckLoad(struct TruckCapacity truck) {
    return truck.current_load;
}
