#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>a;
        vector<int>ans(nums1.size());
        vector<int>tem;
        unordered_map<int, int>hash;
        a.push(nums2[0]);
        for (int i = 0; i < nums1.size(); i++) {
            hash[nums1[i]] = -1;
        }
        for (int i = 1; i < nums2.size(); i++) {
            int k = 0;
            if (nums2[i]<a.top()) {
                a.push(nums2[i]);
            }
            else {
                while (!a.empty()&&nums2[i] > a.top()) {
                    hash[a.top()] = nums2[i];
                    a.pop();
                }
                a.push(nums2[i]);
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = hash[nums1[i]];
        }
        return ans;
    }
};