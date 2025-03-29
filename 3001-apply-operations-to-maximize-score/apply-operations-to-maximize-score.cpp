#define ll long long

class Solution {
public:

    ll mod = 1e9+7;

    ll getPower(ll n, ll p){
        ll res = 1;
        n = n%mod;

        while(p>0){
            if(p&1){
                res = (res*n)%mod; 
                p--;
            }
            n = (n*n)%mod; 
            p = p >> 1;
        }
        return res;
    }

    ll getPrimeScore(int n){
        ll count = 0;
        if(n%2==0){
            count++;
            while(n%2==0)n=n/2;
        }

        for(int i=3; i*i<=n; i=i+2){
            if(n%i==0){
                count++;
                while(n%i==0)n=n/i;
            }
        }

        if(n>2){
            count++;
        }
        return count;
    }

    int maximumScore(vector<int>& nums, int K) {
        int n = nums.size();
        vector<ll> primeScore(n);

        //getting the prime score for each number in nums
        for(int i=0; i<n; i++){
            primeScore[i] = getPrimeScore(nums[i]);
        }

        //preparing the left and right vectors
        vector<ll> left(n), right(n);
        stack<int> st;

        //updating the value in left vector
        left[0] = 0; st.push(0);
        for(int i=1; i<n; i++){
            ll currAns = i;
            while(!st.empty() && primeScore[i]>primeScore[st.top()]){
                currAns = min(currAns, left[st.top()]);
                st.pop();
            }
            st.push(i);
            left[i] = currAns;
        }

        //clearing the stack
        while(!st.empty()){st.pop();}

        //updating the value in right vectors
        right[n-1] = n-1; st.push(n-1);
        for(int i=n-2; i>=0; i--){
            ll currAns = i;
            while(!st.empty() && primeScore[i]>=primeScore[st.top()]){
                currAns = max(currAns, right[st.top()]);
                st.pop();
            }
            st.push(i);
            right[i] = currAns;
        }

        //preparing the max heap
        priority_queue<vector<ll>> pq;
        for(int i=0; i<n; i++){
            ll r=right[i]-i+1; ll l=i-left[i];
            ll total = r*(1+l);
            pq.push({(ll)nums[i], total});
        }

        ll ans = 1; ll k = K;
        while(k>0){
            ll x = pq.top()[0], y = pq.top()[1]; pq.pop();
            ans = (ans*getPower(x, min(k, y)))%mod;
            k = k-min(k, y);
        }

        ll res = ans%mod;
        return (int)res;
    }
};