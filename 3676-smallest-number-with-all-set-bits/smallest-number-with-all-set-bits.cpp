class Solution {
public:
    bool allSet(int x){
        string res = "";
        while(x){
            int add = x % 2;
            res.append(to_string(add));
            x /= 2;
        }

        for(int i = 0; i < res.size(); i++){
            cout << " " << res[i] << endl;
            if(res[i] == '0'){
                return false;
            }
        }

        return true;
    }
    int smallestNumber(int n) {
        while(!allSet(n)){
            n++;
        }
        return n;
    }
};