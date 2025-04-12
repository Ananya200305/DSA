class Solution {
public:
    long long ans = 0;
    set<map<int,int>> vis;

    long long vectorToNumber(vector<int>& num){
        long long ans = 0;
        for(int digit : num){
            ans = ans * 10 + digit;
        }
        return ans;
    }

    long long fact(int n){
        long long ans = 1;
        for(int i = 2; i <= n; i++){
            ans *= i;
        }
        return ans;
    }

    long long Total_permutation(map<int, int>& freq, int n){
        long long totalPermutation = fact(n);
        for(auto& i : freq){
            totalPermutation /= fact(i.second);
        }
        return totalPermutation;
    }

    long long PermutationStartingWithZero(map<int, int>& freq, int n){
        if(freq.find(0) == freq.end() || freq[0] == 0){
            return 0;
        }
        freq[0]--;
        long long permutationWithZero = fact(n - 1);
        for(auto& i : freq){
            permutationWithZero /= fact(i.second);
        }
        freq[0]++; // restore the state
        return permutationWithZero;
    }

    long long calc(map<int, int>& freq, int n){
        return Total_permutation(freq, n) - PermutationStartingWithZero(freq, n);
    }

    void generatePalindrome(vector<int>& num, int left, int right, int n, int k){
        if(left > right){
            long long pali = vectorToNumber(num);
            if(pali % k == 0){
                map<int , int > m;
                for(auto digit : num){
                    m[digit]++;
                }
                if(vis.find(m) == vis.end()){
                    ans += calc(m, n);
                    vis.insert(m);
                }
            }
            return;
        }

        for(int digit = (left == 0) ? 1 : 0; digit <= 9; digit++){
            num[left] = num[right] = digit;
            generatePalindrome(num, left + 1, right - 1, n, k);
        }
    }

    long long countGoodIntegers(int n, int k) {
        vector<int> num(n, 0);
        generatePalindrome(num, 0, n - 1, n, k);
        return ans;
    }
};
