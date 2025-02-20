class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result = "";
        for(int i = 0; i < nums.size(); i++){
            char current = nums[i][i];
            if(current == '0'){
                result.push_back('1');
            }else{
                result.push_back('0');
            }
        }
        return result;
    }
};