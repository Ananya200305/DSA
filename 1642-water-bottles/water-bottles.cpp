class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;

        while(numBottles > 1){
            int rem = numBottles % numExchange;
            numBottles = numBottles / numExchange;
            res += numBottles;
            cout << numBottles << endl;
            cout << " " << rem << endl;
            
            if(rem != 0){
                numBottles = numBottles + rem;
                if(numBottles < numExchange) break;
                cout << "  " << numBottles << endl;
            }
        }

        return res;
    }
};