
#include <stdio.h>
#include <assert.h>
#include "deliveries.h"

void test_addDelivery() {
    struct Delivery deliveries[5] = {0};  // Initialize an empty deliveries array
    struct Delivery new_delivery = {1, "123 Main St", 5.0};  // Example delivery

    // Test adding a delivery to an empty array
    assert(addDelivery(deliveries, 5, new_delivery) == 1);
    assert(deliveries[0].delivery_id == 1);

    // Test adding a delivery when there is no space
    struct Delivery new_delivery2 = {2, "456 Elm St", 10.0};
    for (int i = 0; i < 5; i++) {
        addDelivery(deliveries, 5, new_delivery);  // Fill up the array
    }
    assert(addDelivery(deliveries, 5, new_delivery2) == 0);

    printf("All addDelivery tests passed!\n");
}

void test_findDeliveryByID() {
    struct Delivery deliveries[5] = {{1, "123 Main St", 5.0}, {2, "456 Elm St", 10.0}};

    // Test finding an existing delivery
    assert(findDeliveryByID(deliveries, 5, 1) == 0);
    assert(findDeliveryByID(deliveries, 5, 2) == 1);

    // Test searching for a non-existent delivery
    assert(findDeliveryByID(deliveries, 5, 3) == -1);

    printf("All findDeliveryByID tests passed!\n");
}

int main() {
    test_addDelivery();
    test_findDeliveryByID();
    return 0;
}
