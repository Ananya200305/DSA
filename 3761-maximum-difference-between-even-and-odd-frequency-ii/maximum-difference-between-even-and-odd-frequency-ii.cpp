class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;

        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) continue;

                vector<int> best(4, INT_MAX); // for each parity status (00, 01, 10, 11)
                int cntA = 0, cntB = 0;
                int prevA = 0, prevB = 0;
                int l = -1;

                for (int r = 0; r < n; ++r) {
                    cntA += (s[r] == a);
                    cntB += (s[r] == b);

                    while (r - l >= k && (cntA - prevA) > 0 && (cntB - prevB) > 0) {
                        int status = ((prevA % 2) << 1) | (prevB % 2);
                        best[status] = min(best[status], prevA - prevB);

                        ++l;
                        prevA += (s[l] == a);
                        prevB += (s[l] == b);
                    }

                    int status = ((cntA % 2) << 1) | (cntB % 2);
                    int oppositeStatus = status ^ 2; // flip only the 'a' bit
                    if (best[oppositeStatus] != INT_MAX) {
                        ans = max(ans, cntA - cntB - best[oppositeStatus]);
                    }
                }
            }
        }

        return (ans == INT_MIN) ? -1 : ans;
    }
};