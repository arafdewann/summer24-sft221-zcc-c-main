#include <stdio.h>
#include <string.h>
#include "truck_capacities.h"

/**
 * @brief Add a new truck capacity to the truck capacities array.
 *
 * @param trucks The array of truck capacities.
 * @param size The size of the truck capacities array.
 * @param new_truck The new truck capacity to add.
 * @return int 1 if the truck capacity was added successfully, 0 otherwise.
 */
int addTruck(struct TruckCapacity trucks[], int size, struct TruckCapacity new_truck) {
    for (int i = 0; i < size; i++) {
        if (trucks[i].truck_id == 0) { // Assuming 0 means empty slot
            trucks[i] = new_truck;
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Find a truck capacity by its ID.
 *
 * @param trucks The array of truck capacities.
 * @param size The size of the truck capacities array.
 * @param truck_id The ID of the truck capacity to find.
 * @return struct Truck* Pointer to the found truck capacity, or NULL if not found.
 */
int findTruckByID(struct TruckCapacity trucks[], int size, int truck_id) {
    for (int i = 0; i < size; i++) {
        if (trucks[i].truck_id == truck_id) {
            return i;
        }
    }
    return -1;
}
