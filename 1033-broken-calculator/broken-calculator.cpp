class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ops = 0;
        while(target > startValue){
            if(target % 2 == 0){
                target = target / 2;
                ops++;
            }else{
                target += 1;
                ops++;
            }
        }

        return ops + (startValue - target);
    }
};