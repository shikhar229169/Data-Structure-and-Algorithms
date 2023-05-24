#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    class cmp {
    public: 
        bool operator()(int a, int b) {
            return a > b;
        }
    };

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> nums(nums1.size());
        for (int i=0; i<nums1.size(); i++) {
            nums[i] = {nums2[i], nums1[i]};
        }

        sort(nums.begin(), nums.end());

        priority_queue<int, vector<int>, cmp> q;

        long long sum = 0;
        
        for (int i=nums.size()-1; i>=(int)nums.size() - k; i--) {
            q.push(nums[i][1]);
            sum += nums[i][1];
        }

        long long ans = sum * nums[nums.size()-k][0];

        for (int i=nums.size()-k-1; i>=0; i--) {
            int currMin = q.top();
            
            ans = max(ans, (sum - currMin + nums[i][1]) * nums[i][0]);

            if (currMin < nums[i][1]) {
                sum -= currMin;
                sum += nums[i][1];
                q.pop();
                q.push(nums[i][1]);
            }
        }

        return ans;
    }
};


int main() {
    Solution my;
    vector<int> a = {4,2,3,1,1};
    vector<int> b = {7,5,10,9,6};
    int k = 1;
    cout<<my.maxScore(a, b, k);

    return 0;
}