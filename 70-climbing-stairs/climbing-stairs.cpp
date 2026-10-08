class Solution {
private:
    int count = 0;

public:

    int solve(int n, vector<int>& ans){
        // base case
        if(n < 2){
            return ans[n];
        }

        if(ans[n] != -1){
            return ans[n];
        }

        // move 1 step
        int one = solve(n-1, ans);
        // move 2 steps
        int two = solve(n-2, ans);

        // update
        ans[n] = one + two;

        return ans[n];
    }

    int climbStairs(int n) {
        vector<int> ans(n+1, -1);
        ans[0] = 1;
        ans[1] = 1;

        

        return solve(n, ans);
    }
};