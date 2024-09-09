#define _CRT_SECURE_NO_WARNINGS
#include "function_specs.h"
#include "math.h"
#include <string.h>
#include <float.h>
#include <stdio.h>
#include "routes.h"

/**
 * @brief Finds the best truck for a shipment.
 */
int findTruckForShipment(struct Map map, struct TruckCapacity trucks[], int numTrucks, struct Delivery shipment) {
    int bestTruck = -1;
    double shortestDistance = DBL_MAX;
    struct Point dest = { shipment.destination[0] - '1', shipment.destination[1] - 'A' };

    struct Route routes[3] = { getBlueRoute(), getGreenRoute(), getYellowRoute() };

    for (int i = 0; i < numTrucks; i++) {
        if (trucks[i].current_load + shipment.weight > trucks[i].max_capacity ||
            trucks[i].current_volume + shipment.size > TRUCK_VOLUME) {
            continue;
        }

        struct Point closestPoint = findClosestPointOnRoute(&routes[i], dest);
        double diversionDistance = calculateDistance(closestPoint.row, closestPoint.col, dest.row, dest.col);

        if (diversionDistance < shortestDistance) {
            shortestDistance = diversionDistance;
            bestTruck = i;
        }
    }

    return bestTruck;
}
/**
 * @brief Calculates the Euclidean distance between two points.
 */
double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/**
 * @brief Determines the route for a truck.
 */
struct DeliveryRoute determineTruckRoute(struct Map map, struct Point start, struct Point destination) {
    struct DeliveryRoute route;
    struct Route shortestRoute = shortestPath(&map, start, destination);

    route.route_id = 1; // Example route ID
    snprintf(route.start_location, sizeof(route.start_location), "%d%c", start.row + 1, start.col + 'A');
    snprintf(route.end_location, sizeof(route.end_location), "%d%c", destination.row + 1, destination.col + 'A');
    route.distance = 0;

    for (int i = 1; i < shortestRoute.numPoints; i++) {
        route.distance += (float)distance(&shortestRoute.points[i - 1], &shortestRoute.points[i]);
    }

    return route;
}

/**
 * @brief Calculates the load for a truck.
 */
float calculateTruckLoad(struct TruckCapacity truck) {
    return truck.current_load;
}

struct Point findClosestPointOnRoute(const struct Route* route, struct Point dest) {
    struct Point closestPoint = route->points[0];
    double minDistance = calculateDistance(closestPoint.row, closestPoint.col, dest.row, dest.col);

    for (int i = 1; i < route->numPoints; i++) {
        double distance = calculateDistance(route->points[i].row, route->points[i].col, dest.row, dest.col);
        if (distance < minDistance) {
            minDistance = distance;
            closestPoint = route->points[i];
        }
    }

    printf("Debug: Closest point to %d%c on route: %d%c (distance: %.2f)\n",
        dest.row + 1, dest.col + 'A',
        closestPoint.row + 1, closestPoint.col + 'A',
        minDistance);

    return closestPoint;
}

double calculateRouteDistance(const struct Route* route) {
    double totalDistance = 0;
    for (int i = 1; i < route->numPoints; i++) {
        totalDistance += calculateDistance(
            route->points[i - 1].row, route->points[i - 1].col,
            route->points[i].row, route->points[i].col
        );
    }
    return totalDistance;
}
