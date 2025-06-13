class Solution {
public:
    using ll = long long;
    vector<ll> bit1, bit2;
    int n;

    void update(vector<ll>& bit, int i, ll val) {
        for (++i; i <= n; i += (i & -i))
            bit[i] += val;
    }

    ll query(const vector<ll>& bit, int i) {
        ll res = 0;
        for (++i; i > 0; i -= (i & -i))
            res += bit[i];
        return res;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i;
        for (int i = 0; i < n; ++i)
            nums1[i] = pos[nums1[i]];

        bit1.assign(n + 2, 0);
        bit2.assign(n + 2, 0);
        ll ans = 0;

        for (int i = n - 1; i >= 0; --i) {
            int x = nums1[i];
            ll val = query(bit1, n - 1) - query(bit1, x);
            ll trip = query(bit2, n - 1) - query(bit2, x);
            ans += trip;
            update(bit2, x, val);
            update(bit1, x, 1);
        }

        return ans;
    }
};