class Solution {
public:
    int findClosest(int x, int y, int z) {

        if(abs(z - x) > abs(z - y)){
            return 2;
        }

        if(abs(z - y) > abs(z - x)){
            return 1;
        }

        if(abs(z-y) == abs(z-x)){
            return 0;
        }
        
        return -1;
    }
};