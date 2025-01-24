#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>a;
        vector<int>ans(nums1.size());
        vector<int>found(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
           auto it= find(nums2.begin(), nums2.end(), nums1[i]);
            while(it!=nums2.end()) {
                if (*it > nums1[i]) {
                    ans[i] = *it;
                    found[i] = 1;
                    break;
                }
                if (found[i] == 0) {
                    ans[i] = -1;
                }
                it++;
            }
        }
        return ans;
    }
};
int main()
{

}