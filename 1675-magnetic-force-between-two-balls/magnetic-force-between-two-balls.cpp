class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mid){
        int ballCnt = 1;
        int lastVal = position[0];

        for(int i = 0; i < position.size(); i++){
            if(position[i] - lastVal >= mid){
                ballCnt++;
                lastVal = position[i];
            }
            if(ballCnt >= m) return true;
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int i = 0, j = position[position.size() - 1];
        while(i < j){
            int mid = i + (j-i)/2;
            if(isPossible(position, m, mid)){
                i = mid + 1;
            }else{
                j = mid;
            }
        }

        return i-1;
    }
};