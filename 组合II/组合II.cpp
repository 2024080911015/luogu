#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result; // 用于存储所有的解
        vector<int> ans; // 当前的组合
        sort(candidates.begin(), candidates.end()); // 排序，便于去重
        dfs(candidates, target, ans, result, 0); // 开始递归
        return result;
    }

    void dfs(vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& result, int start) {
        if (target == 0) { // 如果目标值为0，找到一个解
            result.push_back(ans);
            return;
        }
        if (target < 0) { // 如果目标值小于0，无解
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // 去重：跳过相同的数字
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // 选择当前数字
            ans.push_back(candidates[i]);

            // 递归：从下一个元素开始（不允许重复使用当前元素）
            dfs(candidates, target - candidates[i], ans, result, i + 1);

            // 回溯：撤销选择
            ans.pop_back();
        }
    }
};
