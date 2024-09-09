#include <stdio.h>
#include <string.h>
#include "deliveries.h"

/**
 * @brief Add a new delivery to the delivery array.
 *
 * @param deliveries The array of deliveries.
 * @param size The size of the deliveries array.
 * @param new_delivery The new delivery to add.
 * @return int 1 if the delivery was added successfully, 0 otherwise.
 */
int addDelivery(struct Delivery deliveries[], int size, struct Delivery new_delivery) {
    for (int i = 0; i < size; i++) {
        if (deliveries[i].delivery_id == 0) { // Assuming 0 means empty slot
            deliveries[i] = new_delivery;
            return 1;
        }
    }
    return 0;
}


/**
 * @brief Find a delivery by its ID.
 *
 * @param deliveries The array of deliveries.
 * @param size The size of the deliveries array.
 * @param delivery_id The ID of the delivery to find.
 * @return struct Delivery* Pointer to the found delivery, or NULL if not found.
 */
int findDeliveryByID(struct Delivery deliveries[], int size, int delivery_id) {
    for (int i = 0; i < size; i++) {
        if (deliveries[i].delivery_id == delivery_id) {
            return i;
        }
    }
    return -1;
}
