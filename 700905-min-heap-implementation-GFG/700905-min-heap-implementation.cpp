class MinHeap {
  private:
    // Initialize your data members
    vector<int> heap;
    
    void max_down(){
        int curr_index = 0;
        int n = size();
        
        while(curr_index < n){
            int left = 2*curr_index + 1;
            int right = 2*curr_index + 2;
            int swap_index = curr_index;
            
            if(left < n && heap[swap_index] > heap[left]){
                swap_index = left;
            }
            if(right < n && heap[swap_index] > heap[right]){
                swap_index = right;
            }
            
            if(swap_index == curr_index) return;
            
            swap(heap[curr_index], heap[swap_index]);
            curr_index = swap_index;
        }
        
    }
    
    void min_up(){
        int curr_index = heap.size() - 1;
        int parent_index = (curr_index - 1)/2;
        while(parent_index >= 0){
            if(heap[parent_index] > heap[curr_index]){
                swap(heap[parent_index], heap[curr_index]);
                curr_index = parent_index;
                parent_index = (curr_index - 1)/2;
            }
            else return;
        }
    }
    
  public:

    void push(int x) {
        // Insert x into the heap
        heap.push_back(x);
        min_up();
        
    }

    void pop() {
        // Remove the top (minimum) element
        if(heap.empty()) return;

        int i = heap.size() - 1;
        heap[0] = heap[i];
        heap.pop_back();
        
        max_down();
        
    }

    int peek() {
        // Return the top element or -1 if empty
        return heap.size() ? heap[0] : -1;
    }

    int size() {
        // Return the number of elements in the heap
        return heap.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna