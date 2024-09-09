#pragma once
/**
 * @brief Structure to hold delivery route information.
 *
 * This structure contains details about a delivery route, including its unique
 * identifier, start location, end location, and distance.
 */
struct DeliveryRoute {
    int route_id;           /**< Unique identifier for the route */
    char start_location[100]; /**< The starting location of the route */
    char end_location[100];   /**< The ending location of the route */
    float distance;         /**< Distance of the route in kilometers */
};

/**
 * @brief Add a new delivery route to the route array.
 *
 * @param routes The array of delivery routes.
 * @param size The size of the routes array.
 * @param new_route The new route to add.
 * @return int 1 if the route was added successfully, 0 otherwise.
 */
int addDeliveryRoute(struct DeliveryRoute routes[], int size, struct DeliveryRoute new_route);

/**
 * @brief Find a delivery route by its ID.
 *
 * @param routes The array of delivery routes.
 * @param size The size of the delivery routes array.
 * @param route_id The ID of the delivery route to find.
 * @return int The index of the found route, or -1 if not found.
 */
int findDeliveryRouteByID(struct DeliveryRoute routes[], int size, int route_id);
