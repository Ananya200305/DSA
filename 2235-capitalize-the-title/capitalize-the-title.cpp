class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        int i = 0;

        while(i < n){
            while(i < n && title[i] == ' ') i++;
            int start = i;
            while(i < n && title[i] != ' ') i++;

            int len = i - start;

            if(len <= 2){
                for(int j = start; j < i; j++) title[j] = tolower(title[j]);
            }else{
                title[start] = toupper(title[start]);
                for(int j = start+1; j < i; j++) title[j] = tolower(title[j]);
            }
        }

        return title;
    }
};