#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include "mapping.h"
#include "deliveries.h"
#include "routes.h"
#include "truck_capacities.h"
#include "function_specs.h"

#define MAX_TRUCKS 3
#define MAX_DELIVERIES 100
#define TRUCK_VOLUME 50 // Assuming each truck has a volume capacity of 50 cubic meters


int main(void)
{
    struct Map baseMap = populateMap();
    struct Route truckRoutes[MAX_TRUCKS] = { getBlueRoute(), getGreenRoute(), getYellowRoute() };
    struct TruckCapacity trucks[MAX_TRUCKS] = {
        {1, 2500.0f, 0.0f, 0.0f}, // Blue truck
        {2, 2500.0f, 0.0f, 0.0f}, // Green truck
        {3, 2500.0f, 0.0f, 0.0f}  // Yellow truck
    };

    printf("================\n");
    printf("Seneca Polytechnic Deliveries\n");
    printf("================\n");

    while (1) {
        int weight;
        int size;
        char destination[4] = { 0 };
        char input[100];

        printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        input[strcspn(input, "\n")] = 0;

        if (sscanf(input, "%d %d %3s", &weight, &size, destination) != 3) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if (weight == 0 && size == 0 && (destination[0] == 'x' || destination[0] == 'X')) {
            break;
        }

        // Validate input
        int row;
        char col;
        if (sscanf(destination, "%d%c", &row, &col) != 2 ||
            row < 1 || row > MAP_ROWS ||
            col < 'A' || col > 'Y') {
            printf("Invalid destination\n");
            continue;
        }

        if (size != 1 && size != 3 && size != 5) {
            printf("Invalid size\n");
            continue;
        }

        if (weight < 1 || weight > 2500) {
            printf("Invalid weight (must be 1-2500 Kg.)\n");
            continue;
        }

        struct Point dest = { row - 1, col - 'A' };
        struct Delivery shipment = { 0, {0}, weight, 0, size };  // Initializing destination as an array
        strncpy(shipment.destination, destination, sizeof(shipment.destination) - 1);
        shipment.destination[sizeof(shipment.destination) - 1] = '\0';  // Ensuring null-termination

        int bestTruck = findTruckForShipment(baseMap, trucks, MAX_TRUCKS, shipment);

        if (bestTruck == -1) {
            printf("Ships tomorrow\n");
        }
        else {
            trucks[bestTruck].current_load += weight;
            trucks[bestTruck].current_volume += size;

            const char* truckColors[] = { "BLUE", "GREEN", "YELLOW" };
            printf("Ship on %s LINE, ", truckColors[bestTruck]);

            struct Point closestPoint = findClosestPointOnRoute(&truckRoutes[bestTruck], dest);
            double diversionDistance = calculateDistance(closestPoint.row, closestPoint.col, dest.row, dest.col);

            if (diversionDistance > 0) {
                printf("divert: %.2f units\n", diversionDistance);
            }
            else {
                printf("no diversion\n");
            }
        }
    }

    printf("Thanks for shipping with Seneca Polytechnic!\n");

    return 0;
}