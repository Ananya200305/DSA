class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottleDrunk = numBottles;       // already drank all initial bottles
        int emptyBottles = numBottles;      // all are empty now

        while (emptyBottles >= numExchange) {
            // exchange for 1 new full bottle
            emptyBottles -= numExchange;
            numExchange++;   // cost increases
            bottleDrunk++;   // drink the new bottle
            emptyBottles++;  // add the new empty bottle
        }

        return bottleDrunk;
    }
};
