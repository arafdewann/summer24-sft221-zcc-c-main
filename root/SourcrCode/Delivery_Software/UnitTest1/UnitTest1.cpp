#include "CppUnitTest.h"

// Use extern "C" to specify C linkage for the C headers
extern "C" {
#include "mapping.h"
#include "function_specs.h"
#include "deliveries.h"
#include "routes.h"
#include "truck_capacities.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestfindTruckForShipment_InvalidData)
        {
            struct Map map = populateMap();
            struct TruckCapacity trucks[2] = {
                {1, 1000.0, 100},
                {2, 1500.0, 200}
            };
            struct Delivery shipment = { 1, "Destination", 2000.0, 1 };

            int bestTruck = findTruckForShipment(map, trucks, 2, shipment);

            Assert::AreEqual(-1, bestTruck); // Expect no truck to accommodate
        }

        TEST_METHOD(TestcalculateDistance_ZeroCoordinates)
        {
            double distance = calculateDistance(0, 0, 0, 0);

            Assert::AreEqual(0.0, distance); // Expect distance to be 0
        }

        TEST_METHOD(TestcalculateDistance_LargeCoordinates)
        {
            double distance = calculateDistance(1000, 1000, -1000, -1000);

            Assert::AreEqual(2828.4271, distance, 0.0001); // Expect approx 2828.4271 with tolerance
        }

        TEST_METHOD(TestcalculateTruckLoad_PositiveValues)
        {
            struct TruckCapacity truck = { 1, 1000.0, 500.0 };

            float totalWeight = calculateTruckLoad(truck);

            Assert::AreEqual(500.0f, totalWeight);
        }

        TEST_METHOD(TestcalculateTruckLoad_ZeroValues)
        {
            struct TruckCapacity truck = { 1, 1000.0, 0.0 };

            float totalWeight = calculateTruckLoad(truck);

            Assert::AreEqual(0.0f, totalWeight);
        }
    };
}
