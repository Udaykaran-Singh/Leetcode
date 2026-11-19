# [Min Heap Implementation](https://www.geeksforgeeks.org/problems/min-heap-implementation/1)
## Easy
Implement a class MinHeap that supports the following operations:push(x) –&nbsp;push element x into the heappop() – remove the top element from the heappeek() – return top element from the heap, if empty return -1size() - return the no of elements in the heap.There will be a sequence of queries queries[][]. The queries are represented in numeric form:1 x : call push(x)2: call pop()3: call peek()4: call size()The driver code will process the queries, call the corresponding functions, and print the outputs of peek(), size() operation.You only need to implement the above four functions.Examples :Input: queries[][] = [[1, 3], [1, 7], [3], [1, 2], [3]]
Output: [3, 2]
Explanation:
push(3): heap is [3]push(7): heap is [3, 7]peek(): return top element 3push(2): heap is [2, 3, 7]peek(): return top element 2Input: queries[][] = [[1, 4], [1, 8], [1, 7], [2], [3], [4]]
Output: [7, 2]
Explanation:
push(4): heap is [4]push(8): heap is [4, 8]push(7): heap is [4, 7, 8]pop(): remove top element 4, now heap is [7, 8]peek(): return top element 7size(): return no of elements in the heap