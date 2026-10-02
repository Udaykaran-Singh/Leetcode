class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<list<int>> buckets_for_digit(10);
        int ans = -1;

        for(int &i : nums){
            int max_digit = 0;
            int num = i;

            while(num){
                int digit = num%10;
                num /= 10;

                max_digit = max(max_digit, digit);
            }

            buckets_for_digit[max_digit].push_back(i);
        }

        // for(auto &[key, val] : buckets_for_digit){
        //     cout<<key<<": [";
        //     for(auto i: val) cout<<i<<", ";
        //     cout<<" ]"<<endl;
        // }cout<<endl;

        for(list<int> &val : buckets_for_digit){
            int secondLargestNumber = -1, LargestNumber = -1;

            for(int i : val){
                if(i <= LargestNumber && i > secondLargestNumber) secondLargestNumber = i;
                if(i > LargestNumber){
                    secondLargestNumber = LargestNumber;
                    LargestNumber = i;
                }
            }

            // cout<<LargestNumber<<".   "<<secondLargestNumber<<endl;

            if(secondLargestNumber != -1) ans = max(ans, LargestNumber + secondLargestNumber); 
        }

        return ans;
    }
};