#include <stdio.h>
#include <string.h>
#include "deliveries.h"
#include "mapping.h"
#include "routes.h"
#include "truck_capacities.h"
#include <math.h>

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
    if (result == 14.14) {
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
}

void test_delivery_struct() {
    struct Delivery delivery;
    delivery.delivery_id = 1;
    snprintf(delivery.destination, sizeof(delivery.destination), "1234 Test St");
    delivery.weight = 10.5;
    delivery.priority = 1;

    if (delivery.delivery_id == 1 &&
        strcmp(delivery.destination, "1234 Test St") == 0 &&
        delivery.weight == 10.5 &&
        delivery.priority == 1) {
        printf("Delivery struct test passed!\n");
    } else {
        printf("Delivery struct test failed!\n");
    }
}

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

void test_truck_capacity_struct() {
    struct TruckCapacity truck;
    truck.truck_id = 1;
    truck.max_capacity = 1500.0;
    truck.current_load = 500.0;

    if (truck.truck_id == 1 &&
        truck.max_capacity == 1500.0 &&
        truck.current_load == 500.0) {
        printf("TruckCapacity struct test passed!\n");
    } else {
        printf("TruckCapacity struct test failed!\n");
    }
}

int main() {
    test_calculateDistance();
    test_findTruckForShipment();
    test_delivery_struct();
    test_route_struct();
    test_truck_capacity_struct();
    return 0;
}
