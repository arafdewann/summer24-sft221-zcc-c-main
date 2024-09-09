#include <stdio.h>
#include <string.h>
#include "routes.h"

/**
 * @brief Add a new delivery route to the delivery route array.
 *
 * @param routes The array of delivery routes.
 * @param size The size of the routes array.
 * @param new_route The new delivery route to add.
 * @return int 1 if the delivery route was added successfully, 0 otherwise.
 */
int addDeliveryRoute(struct DeliveryRoute routes[], int size, struct DeliveryRoute new_route) {
    for (int i = 0; i < size; i++) {
        if (routes[i].route_id == 0) { // Assuming 0 means empty slot
            routes[i] = new_route;
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Find a delivery route by its ID.
 *
 * @param routes The array of delivery routes.
 * @param size The size of the delivery routes array.
 * @param route_id The ID of the delivery route to find.
 * @return int The index of the found delivery route, or -1 if not found.
 */
int findDeliveryRouteByID(struct DeliveryRoute routes[], int size, int route_id) {
    for (int i = 0; i < size; i++) {
        if (routes[i].route_id == route_id) {
            return i;
        }
    }
    return -1;
}
