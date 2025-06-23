class Solution {
public:
    vector<int> convert(long long n, int k){
        if(n == 0) return {0};
        vector<int> res;
        while(n > 0){
            res.push_back(n%k);
            n = n / k;
        }
        return res;
    }

    bool isPalindrom(const vector<int>& n){
        int i = 0;
        int j = n.size() - 1;

        while(i <= j){
            if(n[i] != n[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    long long build(long long n, bool odd){
        long long x = n;
        if(odd){
            n = n/10;
        }
        while(n > 0){
            x = x * 10 + n % 10;
            n = n / 10;
        }
        return x; 
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int len = 1;

        while(n > 0){
            int mid = (len + 1)/2;

            long long low_num = (len == 1) ? 1 : pow(10, mid - 1);  
            long long high_num = pow(10, mid) - 1;

            for(long long i = low_num; i <= high_num; i++){
                long long pal_num;

                if(len % 2 == 0){
                    pal_num = build(i, false);
                }else{
                    pal_num = build(i,true);
                }

                vector<int> baseK = convert(pal_num, k);

                if(isPalindrom(baseK)){
                    sum += pal_num;
                    n--;
                    if(n == 0){
                        break;
                    }
                }
            }
            len++;
        }

        return sum;
    }
};
