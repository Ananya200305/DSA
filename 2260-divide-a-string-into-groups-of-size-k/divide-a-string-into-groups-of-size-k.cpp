class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;

        for(int i = 0; i < s.size(); i=i+k){
            string st = "";
            int j = 0;
            while(j < k){
                if(i + j < s.size()){
                    st.push_back(s[i+j]);
                }else{
                    st.push_back(fill);
                }
                j++;
            }
            res.push_back(st);
        }

        return res;
    }
};