class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int prefix = 0;
        for(int i = 0 ; i < cardPoints.size() ; i++){
            prefix += cardPoints[i];
        }

        int ws = cardPoints.size() - k;  // window size to remove
        int wSum = 0;

        for(int i = 0; i < ws; i++){
            wSum += cardPoints[i];
        }

        int s = wSum;  // s = minimum window sum

        for(int r = ws; r < cardPoints.size(); r++){
            // Slide the window: add new element, remove leftmost one
            wSum += cardPoints[r] - cardPoints[r - ws];
            s = min(s, wSum);
        }

        return prefix - s;
    }
};
