#pragma once

#include "mapping.h"
#include "deliveries.h"
#include "truck_capacities.h"
#include "routes.h"

#define TRUCK_VOLUME 50 

/**
 * @brief Finds the best truck for a shipment.
 *
 * This function finds the best truck for a shipment by considering the load on the truck,
 * the size and weight of the shipment, and the route of the truck to try to place it on a truck
 * which goes closest to the destination. If no truck can take the shipment, it returns -1.
 *
 * @param map The map of the delivery area with buildings on it.
 * @param trucks An array of trucks including the route for each of the trucks.
 * @param numTrucks The number of trucks in the array of trucks.
 * @param shipment A data structure containing the size and weight of the shipment.
 * @return An integer representing the index of the truck in the trucks array on which the shipment should be placed.
 *         If no truck can take the shipment, then -1 is returned.
 */
int findTruckForShipment(struct Map map, struct TruckCapacity trucks[], int numTrucks, struct Delivery shipment);

/**
 * @brief Calculates the Euclidean distance between two points.
 *
 * This function calculates the Euclidean distance between two points (x1, y1) and (x2, y2)
 * on a 2D plane.
 *
 * @param x1 The X-coordinate of the first point.
 * @param y1 The Y-coordinate of the first point.
 * @param x2 The X-coordinate of the second point.
 * @param y2 The Y-coordinate of the second point.
 * @return The Euclidean distance between the two points.
 */
double calculateDistance(int x1, int y1, int x2, int y2);

/**
 * @brief Determines the route for a truck.
 *
 * This function determines the route for a truck based on the current map and the destination.
 * It uses a pathfinding algorithm to find the shortest path that avoids obstacles (buildings).
 *
 * @param map The map of the delivery area with buildings on it.
 * @param start The starting point of the truck.
 * @param destination The destination point for the delivery.
 * @return A DeliveryRoute structure representing the route from the starting point to the destination.
 */
struct DeliveryRoute determineTruckRoute(struct Map map, struct Point start, struct Point destination);

/**
 * @brief Calculates the load for a truck.
 *
 * This function calculates the current load of a truck based on the shipments
 * it carries.
 *
 * @param truck The truck for which the load is being calculated.
 * @return The current load of the truck in kilograms.
 */
float calculateTruckLoad(struct TruckCapacity truck);

