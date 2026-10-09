class Solution {
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int i, int m){
        // base case
        if(i == m){
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < m; j++){
            swap(nums[i], nums[j]);
            solve(nums, i+1, m);
            swap(nums[i], nums[j]);
        }

        return;

    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0, nums.size());
        return ans;
    }
};