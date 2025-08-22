class NumArray {
private:
    vector<int> tree;
    int n; 

    void buildTree(vector<int>& nums, int indexTree, int start, int end){
        if(start == end){
            tree[indexTree] = nums[start];
            return;
        }
        int mid = start + (end - start)/2;
        buildTree(nums, 2*indexTree+1, start, mid);
        buildTree(nums, 2*indexTree+2, mid+1, end);
        tree[indexTree] = tree[2*indexTree+1] + tree[2*indexTree+2];
    }

    void updateTree(int index, int val, int indexTree, int start, int end){
        if(start == end){
            tree[indexTree] = val;
            return;
        }

        int mid = start + (end - start)/2;

        if(index <= mid){
            updateTree(index, val, 2*indexTree+1, start, mid);
        }else{
            updateTree(index, val, 2*indexTree+2, mid+1, end);
        }

        tree[indexTree] = tree[2*indexTree+1] + tree[2*indexTree+2];
    }

    int queryTree(int indexTree, int left, int right, int start, int end){
        if(start > right || end < left){
            return 0;
        }
        if(start >= left && end <= right){
            return tree[indexTree];
        }
        int mid = start + (end - start)/2;
        int leftSum = queryTree(2*indexTree+1, left, right, start, mid);
        int rightSum = queryTree(2*indexTree+2, left, right, mid+1, end);

        return leftSum + rightSum;
    }
public:
    NumArray(vector<int>& nums) {
        if(!nums.empty()){
            n = nums.size();
            tree.resize(4*n);
            buildTree(nums, 0, 0, n-1);
        }
    }
    
    void update(int index, int val) {
        updateTree(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return queryTree(0, left, right, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */