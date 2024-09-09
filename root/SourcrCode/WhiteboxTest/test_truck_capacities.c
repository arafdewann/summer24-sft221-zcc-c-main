#include <stdio.h>
#include "truck_capacities.h"

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
    test_truck_capacity_struct();
    return 0;
}
