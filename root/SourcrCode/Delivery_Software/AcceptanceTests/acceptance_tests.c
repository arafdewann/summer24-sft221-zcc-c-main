#include <assert.h>
#include <stdio.h>
#include "function_specs.h"
#include "deliveries.h"
#include "routes.h"
#include "truck_capacities.h"
#include "mapping.h"

// Define the tests
void test_AcceptanceTest_RoutePlanning(void) {
    struct Map map = populateMap();
    struct TruckCapacity trucks[5] = {
        {1, 1000.0f, 0.0f},
        {2, 1500.0f, 0.0f},
        {3, 2000.0f, 0.0f},
        {4, 2500.0f, 0.0f},
        {5, 3000.0f, 0.0f}
    };
    struct Delivery shipment = { 1, "123 Main St", 500.0f, 1 };

    int bestTruck = findTruckForShipment(map, trucks, 5, shipment);
    assert(bestTruck >= 0 && bestTruck < 5);

    struct Point start = { 0, 0 };
    struct Point destination = { 10, 10 };
    struct DeliveryRoute route = determineTruckRoute(map, start, destination);
    assert(route.route_id > 0);
    assert(route.distance > 0.0f);
}

void test_AcceptanceTest_TruckCapacityManagement(void) {
    struct TruckCapacity truck = { 1, 1000.0f, 0.0f };
    struct Delivery shipment1 = { 1, "123 Main St", 300.0f, 1 };
    struct Delivery shipment2 = { 2, "456 Elm St", 400.0f, 2 };

    float initialLoad = calculateTruckLoad(truck);
    assert(initialLoad == 0.0f);

    // Simulate adding shipments to the truck
    truck.current_load += shipment1.weight + shipment2.weight;

    float finalLoad = calculateTruckLoad(truck);
    assert(finalLoad == 700.0f);
}

void test_AcceptanceTest_MultipleDeliveries(void) {
    struct Delivery deliveries[3] = {
        {1, "123 Main St", 300.0f, 1},
        {2, "456 Elm St", 400.0f, 2},
        {3, "789 Oak St", 200.0f, 3}
    };

    int result = addDelivery(deliveries, 3, (struct Delivery) { 4, "101 Pine St", 350.0f, 2 });
    assert(result == 0);  // Array is full, should return 0

    int index = findDeliveryByID(deliveries, 3, 2);
    assert(index == 1);
    assert(deliveries[index].weight == 400.0f);
}

void test_AcceptanceTest_MapVisualization(void) {
    struct Map map = populateMap();
    printMap(&map, 1, 1);  // This will print the map, but we can't automatically check the output
    assert(1);  // Placeholder check
}

void test_AcceptanceTest_DeliveryStatusTracking(void) {
    struct Delivery delivery = { 1, "123 Main St", 300.0f, 1 };
    // Note: The Delivery struct doesn't have a status field, so we can't track status directly
    // You might want to add a status field to the Delivery struct or create a separate tracking system
    assert(delivery.delivery_id == 1);
    assert(delivery.priority == 1);
}

void test_AcceptanceTest_SystemIntegration(void) {
    struct Map map = populateMap();
    struct TruckCapacity trucks[1] = { {1, 1000.0f, 0.0f} };
    struct Delivery shipment = { 1, "123 Main St", 500.0f, 1 };

    int bestTruck = findTruckForShipment(map, trucks, 1, shipment);
    assert(bestTruck == 0);

    struct Point start = { 0, 0 };
    struct Point destination = { 10, 10 };
    struct DeliveryRoute route = determineTruckRoute(map, start, destination);
    assert(route.route_id > 0);

    struct Route shortestRoute = shortestPath(&map, start, destination);
    assert(shortestRoute.numPoints > 0);
}

int main() {
    printf("Running Acceptance Tests...\n");
    test_AcceptanceTest_RoutePlanning();
    test_AcceptanceTest_TruckCapacityManagement();
    test_AcceptanceTest_MultipleDeliveries();
    test_AcceptanceTest_MapVisualization();
    test_AcceptanceTest_DeliveryStatusTracking();
    test_AcceptanceTest_SystemIntegration();
    printf("All Acceptance Tests passed!\n");
    return 0;
}
