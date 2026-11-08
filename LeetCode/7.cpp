
class Solution {
public:
    void solve(int r, int c, vector<vector<int>>& maze,
               int n, string path, vector<string>& ans,
               vector<vector<int>>& visited) {

        if (r == n - 1 && c == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[r][c] = 1;

        if (r + 1 < n && maze[r + 1][c] == 1 &&
            !visited[r + 1][c]) {
            solve(r + 1, c, maze, n, path + 'D', ans, visited);
        }

        if (c - 1 >= 0 && maze[r][c - 1] == 1 &&
            !visited[r][c - 1]) {
            solve(r, c - 1, maze, n, path + 'L', ans, visited);
        }

        if (c + 1 < n && maze[r][c + 1] == 1 &&
            !visited[r][c + 1]) {
            solve(r, c + 1, maze, n, path + 'R', ans, visited);
        }

        if (r - 1 >= 0 && maze[r - 1][c] == 1 &&
            !visited[r - 1][c]) {
            solve(r - 1, c, maze, n, path + 'U', ans, visited);
        }

        visited[r][c] = 0;
    }

    vector<string> findPath(vector<vector<int>>& maze) {
        int n = maze.size();

        vector<string> ans;

        if (n == 0 || maze[0][0] == 0 ||
            maze[n - 1][n - 1] == 0) {
            return ans;
        }

        vector<vector<int>> visited(n, vector<int>(n, 0));

        solve(0, 0, maze, n, "", ans, visited);

        return ans;
    }
};
