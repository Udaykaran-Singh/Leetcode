class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& store, int i, int n){
        if(i == n){
            ans.push_back(store);
            return;
        }

        // don't add
        solve(nums, ans, store, i+1, n);

        // add
        store.push_back(nums[i]);
        solve(nums, ans, store, i+1, n);
        // backtrace
        store.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> store;
        solve(nums, ans, store, 0, nums.size());
        return ans;
    }
};