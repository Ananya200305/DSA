class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        for(int i = 0 ; i < nums.size(); i++){
            nums[i] = ((nums[i] % value)+value)% value;
            cout << nums[i] << endl;
        } 

        unordered_map<int , int> freq;

        for(int i = 0 ; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        int mex = 0;

        while(true){
            if(freq.find(mex%value) != freq.end() && freq[mex%value] != 0){
                freq[mex%value]--;
                mex++;
            }else{
                break;
            }
        }

        return mex;
    }
};