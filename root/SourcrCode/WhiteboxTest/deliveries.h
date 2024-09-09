#pragma once

/**
 * @brief Structure to hold delivery information.
 *
 * This structure contains details about a delivery, including its unique
 * identifier, destination address, weight, and priority level.
 */
struct Delivery {
    int delivery_id;        /**< Unique identifier for the delivery */
    char destination[100];  /**< The destination address for the delivery */
    float weight;           /**< Weight of the delivery package in kilograms */
    int priority;           /**< Priority of the delivery (1 for high, 2 for medium, 3 for low) */
};

/**
 * @brief Add a new delivery to the delivery array.
 *
 * @param deliveries The array of deliveries.
 * @param size The size of the deliveries array.
 * @param new_delivery The new delivery to add.
 * @return int 1 if the delivery was added successfully, 0 otherwise.
 */
int addDelivery(struct Delivery deliveries[], int size, struct Delivery new_delivery);

/**
 * @brief Find a delivery by its ID.
 *
 * @param deliveries The array of deliveries.
 * @param size The size of the deliveries array.
 * @param delivery_id The ID of the delivery to find.
 * @return int The index of the found delivery, or -1 if not found.
 */
int findDeliveryByID(struct Delivery deliveries[], int size, int delivery_id);
