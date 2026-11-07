class Solution {
    vector<string> answer;
    string store = "";
    
    void solve(vector<vector<int>>& maze, vector<vector<int>>& visited, int m, int n, int i, int j){
        // base case
        if(i == m-1 && j == n-1){
            answer.push_back(store);
            return;
        }
        
        // down
        if((i+1 < m) && (!visited[i+1][j]) && (maze[i+1][j])){
            i++;
            visited[i][j] = 1;
            store.push_back('D');
            solve(maze, visited, m, n, i, j);
            store.pop_back();
            visited[i][j] = 0;
            i--;
        }
        // left
        if((j-1 >= 0) && (!visited[i][j-1]) && (maze[i][j-1])){
            j--;
            visited[i][j] = 1;
            store.push_back('L');
            solve(maze, visited, m, n, i, j);
            store.pop_back();
            visited[i][j] = 0;
            j++;
        }
        // right
        if((j+1 < n) && (!visited[i][j+1]) && (maze[i][j+1])){
            j++;
            visited[i][j] = 1;
            store.push_back('R');
            solve(maze, visited, m, n, i, j);
            store.pop_back();
            visited[i][j] = 0;
            j--;
        }
        // up
        if((i-1 >= 0) && (!visited[i-1][j]) && (maze[i-1][j])){
            i--;
            visited[i][j] = 1;
            store.push_back('U');
            solve(maze, visited, m, n, i, j);
            store.pop_back();
            visited[i][j] = 0;
            i++;
        }
    }
    
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        if(maze[0][0] == 0) return answer;
        
        
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[0][0] = 1;
        
        solve(maze, visited, m, n, 0, 0);
        
        return answer;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna