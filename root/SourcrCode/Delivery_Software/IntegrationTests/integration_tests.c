#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>  // Add this for fabs
#include "../DeliveryApp/routes.h"
#include "../DeliveryApp/deliveries.h"
#include "../DeliveryApp/truck_capacities.h"
#include "../DeliveryApp/mapping.h"
#include "../DeliveryApp/function_specs.h"

// Macro definitions
#define TEST(name) void test_##name()
#define RUN_TEST(name) printf("Running " #name "... "); \
                       test_##name(); \
                       printf("Passed\n")

#define EXPECT_EQ(a, b) assert((a) == (b))
#define EXPECT_GT(a, b) assert((a) > (b))
#define EXPECT_STREQ(a, b) assert(strcmp((a), (b)) == 0)
#define EXPECT_FLOAT_EQ(a, b) assert(fabs((a) - (b)) < 0.0001f)
#define EXPECT_NE(a, b) assert((a) != (b))

// Test findTruckForShipment with addTruck and addDelivery
TEST(FindTruckForShipmentWithAddedTruckAndDelivery) {
    struct Map map = populateMap();
    struct TruckCapacity trucks[5] = { 0 };
    struct Delivery deliveries[5] = { 0 };

    struct TruckCapacity newTruck = { 1, 1000.0f, 0.0f };
    addTruck(trucks, 5, newTruck);

    struct Delivery newDelivery = { 1, "Destination Address", 500.0f, 1 };
    addDelivery(deliveries, 5, newDelivery);

    int bestTruck = findTruckForShipment(map, trucks, 5, deliveries[0]);
    EXPECT_EQ(bestTruck, 0);
}

// Test calculateTruckLoad with addTruck
TEST(CalculateTruckLoadWithAddedTruck) {
    struct TruckCapacity trucks[1] = { 0 };
    struct TruckCapacity newTruck = { 1, 1000.0f, 500.0f };
    addTruck(trucks, 1, newTruck);

    float load = calculateTruckLoad(trucks[0]);
    EXPECT_FLOAT_EQ(load, 500.0f);
}

// Test findDeliveryByID with addDelivery
TEST(FindDeliveryByIDWithAddedDelivery) {
    struct Delivery deliveries[5] = { 0 };
    struct Delivery newDelivery = { 1, "Destination Address", 500.0f, 1 };
    addDelivery(deliveries, 5, newDelivery);

    int index = findDeliveryByID(deliveries, 5, 1);
    EXPECT_EQ(index, 0);
}

// Test determineTruckRoute with populateMap
TEST(DetermineTruckRouteWithPopulatedMap) {
    struct Map map = populateMap();
    struct Point start = { 0, 0 };
    struct Point destination = { 5, 5 };

    struct DeliveryRoute route = determineTruckRoute(map, start, destination);
    EXPECT_GT(route.distance, 0);
    EXPECT_STREQ(route.start_location, "Start");
    EXPECT_STREQ(route.end_location, "End");
}

// Test shortestPath with populateMap
TEST(ShortestPathWithPopulatedMap) {
    struct Map map = populateMap();
    struct Point start = { 0, 0 };
    struct Point destination = { 5, 5 };

    struct Route path = shortestPath(&map, start, destination);
    EXPECT_GT(path.numPoints, 0);
}

// Test addRoute with getBlueRoute
TEST(AddRouteWithBlueRoute) {
    struct Map baseMap = populateMap();
    struct Route blueRoute = getBlueRoute();
    struct Map routeMap = addRoute(&baseMap, &blueRoute);

    EXPECT_NE(routeMap.squares[0][0], baseMap.squares[0][0]);
}

// Test getPossibleMoves with populateMap
TEST(GetPossibleMovesWithPopulatedMap) {
    struct Map map = populateMap();
    struct Point current = { 1, 1 };
    struct Point backpath = { 0, 0 };

    struct Route possibleMoves = getPossibleMoves(&map, current, backpath);
    EXPECT_GT(possibleMoves.numPoints, 0);
}

int main() {
    printf("Running Integration Tests...\n");
    RUN_TEST(FindTruckForShipmentWithAddedTruckAndDelivery);
    RUN_TEST(DetermineTruckRouteWithPopulatedMap);
    RUN_TEST(CalculateTruckLoadWithAddedTruck);
    RUN_TEST(FindDeliveryByIDWithAddedDelivery);
    RUN_TEST(ShortestPathWithPopulatedMap);
    RUN_TEST(AddRouteWithBlueRoute);
    RUN_TEST(GetPossibleMovesWithPopulatedMap);
    printf("All Integration Tests passed!\n");
    return 0;
}