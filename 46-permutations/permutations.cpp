class Solution {
    vector<vector<int>> ans;
    vector<int> store;

    void solve(vector<int>& nums){
        if(nums.size() == 0){
            ans.push_back(store);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            store.push_back(nums[i]);
            int temp = nums[i];
            nums.erase(nums.begin() + i);

            solve(nums);

            nums.insert(nums.begin() + i, temp);
            store.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums);
        return ans;
    }
};