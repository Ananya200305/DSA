class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if(a <= 0 && b <= 0 && c <= 0){
            return "none";
        }
        
        if((a+b <= c) || (b+c <= a) || (a+c <= b)){
            return "none";
        }
        
        if(a==b && b==c){
            return "equilateral";
        }else if(a==b || b==c || a==c){
            return "isosceles";
        }else{
            return "scalene";
        }

        return "none";
    }
};