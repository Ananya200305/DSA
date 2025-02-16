class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        int m = n/4;
        int odd = (m+1)/2;
        int even = m - odd;

        int right = n - 1;
        int left = 0;
        long long total = 0;

        for(int i = 0; i < odd; i++){
            total += pizzas[right];
            right--;
            left+=3;
        }

        for(int i = 0 ; i < even; i++){
            int first = pizzas[right];
            right--;
            int second = pizzas[right];
            right--;
            total += second;
            left += 2;
        }
        return total;
    }
};
