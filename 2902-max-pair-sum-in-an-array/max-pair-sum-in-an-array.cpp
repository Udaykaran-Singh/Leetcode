class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int, list<int>> store;
        int ans = -1;

        for(int &i : nums){
            int maxi = 0;
            int num = i;

            while(num){
                int digit = num%10;
                num /= 10;

                maxi = max(maxi, digit);
            }

            store[maxi].push_back(i);
        }

        for(auto &[key, val] : store){
            cout<<key<<": [";
            for(auto i: val) cout<<i<<", ";
            cout<<" ]"<<endl;
        }cout<<endl;

        for(auto &[key, val] : store){
            int max2 = -1, max1 = -1;

            for(int i : val){
                if(i <= max1 && i > max2) max2 = i;
                if(i > max1){
                    max2 = max1;
                    max1 = i;
                }
            }

            cout<<max1<<".   "<<max2<<endl;

            if(max2 != -1) ans = max(ans, max1 + max2); 
        }

        return ans;
    }
};