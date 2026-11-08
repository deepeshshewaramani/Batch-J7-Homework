class Solution {
public:
    void solve(vector<int>& nums, vector<int>& current,
               vector<vector<int>>& ans, vector<bool>& visited) {

        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (!visited[i]) {

                visited[i] = true;
                current.push_back(nums[i]);

                solve(nums, current, ans, visited);

                current.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> visited(nums.size(), false);

        solve(nums, current, ans, visited);

        return ans;
    }
};
