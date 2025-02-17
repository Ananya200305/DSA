class Solution {
public:
    void tilesPossible(vector<int>&  alphabets , int& count){
        for(int i = 0; i < 26; i++){
            if(alphabets[i] > 0){
                alphabets[i]--;
                count++;

                tilesPossible(alphabets,count);

                alphabets[i]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> alphabets(26,0);
        for(int i = 0; i < tiles.size(); i++){
            alphabets[(tiles[i] - 'A')]++;
        }

        int count = 0;

        tilesPossible(alphabets,count);

        return count;
    }
};