#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
   /*first we calculate the total number of sub arrays with sun<=goal 
   then we subtract it with total no of sub arrays with sum<=goal-1 
   which gives us total count of sub arrays with sum=goal*/
    int atMost(vector<int>& nums, int goal) {
        int count = 0, left = 0, sum = 0;
        int right = 0;
        if (goal < 0) {
            return 0;
        }
        while (right < nums.size()) {
            sum += nums[right];
            
            // Shrink the window if the sum exceeds the goal
            while (sum > goal) {
                sum -= nums[left++];
            }
            
            count += right - left + 1;
            right++;  
        }
        return count;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    cout << "Test Case 1: " << solution.numSubarraysWithSum(nums1, goal1) << endl; // Expected output: 4

    // Test case 2
    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    cout << "Test Case 2: " << solution.numSubarraysWithSum(nums2, goal2) << endl; // Expected output: 15

    // Test case 3
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int goal3 = 3;
    cout << "Test Case 3: " << solution.numSubarraysWithSum(nums3, goal3) << endl; // Expected output: 3

    // Test case 4
    vector<int> nums4 = {1, 0, 1, 0, 1, 1, 0, 1};
    int goal4 = 4;
    cout << "Test Case 4: " << solution.numSubarraysWithSum(nums4, goal4) << endl; // Expected output: 6

    return 0;
}
//time complexity :O(N)
//space complexity :O(1)
