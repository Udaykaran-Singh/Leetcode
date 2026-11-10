#include <vector>
#include <algorithm>

using namespace std;

class CustomStack {
    int maxSize;
    vector<int> store;
    vector<int> inc; 
    int i;           

public:
    CustomStack(int maxSize) {
        this->i = 0;
        this->maxSize = maxSize;
        this->store.resize(maxSize, 0);
        this->inc.resize(maxSize, 0);
    }
    
    void push(int x) {
        if (i < maxSize) {
            store[i] = x;
            inc[i] = 0;
            i++;
        }
    }
    
    int pop() {
        if (i <= 0) return -1;
        
        i--; 
        int res = store[i] + inc[i];
        
        if (i > 0) {
            inc[i - 1] += inc[i];
        }
        
        return res;
    }
    
    void increment(int k, int val) {
        int idx = min(k, i) - 1;
        
        if (idx >= 0) {
            inc[idx] += val;
        }
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna