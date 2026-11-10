class CustomStack {
    int maxSize;
    vector<int> store;
    int i;

public:
    CustomStack(int maxSize) {
        this->i = 0;
        this->maxSize = maxSize;
        this->store.resize(maxSize, 0);
    }
    
    void push(int x) {
        if(i < maxSize) store[i++] = x;
        return;
    }
    
    int pop() {
        if(i > 0){
            return store[--i];
        }
        else return -1;
    }
    
    void increment(int k, int val) {
        for(int j = 0; j < k && j < i; j++){
            store[j] += val;
        }
        return;
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