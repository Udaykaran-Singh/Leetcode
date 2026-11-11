class Solution {
public:
    int canCompleteCircuit(vector<int>& gasFill, vector<int>& cost) {
        int startAt = 0, neg = 0, gas = 0;

        for(int i = 0; i < gasFill.size(); i++){
            if(gas < 0){
                neg += gas;
                gas = 0;
                startAt = i;
            }

            gas += gasFill[i] - cost[i];

            // cout<<gas<<" "<<neg<<" "<<startAt<<endl;
        }

        if(gas + neg < 0) return -1;

        return startAt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna