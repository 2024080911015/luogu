#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result; // ���ڴ洢���еĽ�
        vector<int> ans; // ��ǰ�����
        sort(candidates.begin(), candidates.end()); // ���򣬱���ȥ��
        dfs(candidates, target, ans, result, 0); // ��ʼ�ݹ�
        return result;
    }

    void dfs(vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& result, int start) {
        if (target == 0) { // ���Ŀ��ֵΪ0���ҵ�һ����
            result.push_back(ans);
            return;
        }
        if (target < 0) { // ���Ŀ��ֵС��0���޽�
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // ȥ�أ�������ͬ������
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // ѡ��ǰ����
            ans.push_back(candidates[i]);

            // �ݹ飺����һ��Ԫ�ؿ�ʼ���������ظ�ʹ�õ�ǰԪ�أ�
            dfs(candidates, target - candidates[i], ans, result, i + 1);

            // ���ݣ�����ѡ��
            ans.pop_back();
        }
    }
};
