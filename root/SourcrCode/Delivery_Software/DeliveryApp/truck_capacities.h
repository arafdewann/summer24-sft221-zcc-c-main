#pragma once

/**
 * @brief Structure to hold truck capacity information.
 *
 * This structure contains details about a truck, including its unique identifier,
 * maximum load capacity, and current load.
 */
struct TruckCapacity {
    int truck_id;           /**< Unique identifier for the truck */
    float max_capacity;     /**< Maximum load capacity of the truck in kilograms */
    float current_load;     /**< Current load of the truck in kilograms */
    float current_volume;
};

/**
 * @brief Add a new truck capacity to the truck capacities array.
 *
 * @param trucks The array of truck capacities.
 * @param size The size of the truck capacities array.
 * @param new_truck The new truck capacity to add.
 * @return int 1 if the truck capacity was added successfully, 0 otherwise.
 */
int addTruck(struct TruckCapacity trucks[], int size, struct TruckCapacity new_truck);

/**
 * @brief Find a truck capacity by its ID.
 *
 * @param trucks The array of truck capacities.
 * @param size The size of the truck capacities array.
 * @param truck_id The ID of the truck capacity to find.
 * @return int The index of the found truck capacity, or -1 if not found.
 */
int findTruckByID(struct TruckCapacity trucks[], int size, int truck_id);
