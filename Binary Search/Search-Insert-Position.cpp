#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (target > nums[mid]) {
                start = mid + 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                return mid;
            }
        }

        if (target < nums[end]) {
            return end;
        } else {
            return end + 1;
        }
    }
};


// Uncomment it to run it on your system
int main() {
    Solution myclass;
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 6;
    int result = myclass.searchInsert(nums, target);
    std::cout << result << std::endl;

    return 0;
}