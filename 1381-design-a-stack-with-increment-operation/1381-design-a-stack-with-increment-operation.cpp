class CustomStack {
    int maxSize;
    stack<int> st;

public:
    CustomStack(int n) {
        maxSize = n;
    }
    
    void push(int x) {
        if(st.size() < maxSize) st.push(x);

        return;
    }
    
    int pop() {
        if(!st.empty()){
            int temp = st.top();
            st.pop();

            return temp;
        }
        else return -1;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }

        while(!temp.empty()){
            if(k){
                st.push(temp.top() + val);
                k--;
            }
            else st.push(temp.top());
            
            temp.pop();
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