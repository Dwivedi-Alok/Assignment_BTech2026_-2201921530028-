**Binary Subarrays With Sum**

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

**Example 1:**

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

**Constraints:**

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length

**Approach:**
we are using sliding window and two pointers

Certainly! Below is the **algorithm** and **pseudocode** for the given C++ solution.

### Algorithm:

1. **Main Function** (`numSubarraysWithSum`):
    - This function calculates the number of subarrays with exactly `goal` sum by using the concept of "at most `goal`" subarrays. The number of subarrays with sum exactly `goal` is the difference between the number of subarrays with sum at most `goal` and those with sum at most `goal - 1`.

2. **Helper Function** (`atMost`):
    - This function calculates the number of subarrays whose sum is **at most** `goal`. 
    - It uses a sliding window technique with two pointers (`left` and `right`).
    - Traverse the array with the `right` pointer, adding elements to the current sum.
    - If the sum exceeds the `goal`, move the `left` pointer to shrink the window until the sum is less than or equal to the goal.
    - The number of subarrays ending at `right` and having sum less than or equal to the goal is `(right - left + 1)`. Accumulate this count.

3. **Return the Difference**:
    - The function `numSubarraysWithSum` returns the difference between `atMost(nums, goal)` and `atMost(nums, goal - 1)`. This gives the number of subarrays with sum exactly equal to `goal`.

### Pseudocode:

```plaintext
Function numSubarraysWithSum(nums, goal):
    return atMost(nums, goal) - atMost(nums, goal - 1)

Function atMost(nums, goal):
    if goal < 0:
        return 0
    Initialize count = 0
    Initialize left = 0
    Initialize sum = 0

    for right = 0 to length of nums - 1:
        sum += nums[right]  // Add current element to the sum

        // Shrink the window if the sum exceeds the goal
        while sum > goal:
            sum -= nums[left]  // Remove element at 'left'
            left += 1          // Move the left pointer to the right

        // Count all valid subarrays ending at 'right'
        count += (right - left + 1)

    return count
```

### Explanation of Pseudocode:

1. **numSubarraysWithSum**:
   - It computes the number of subarrays that sum exactly to `goal` by calling `atMost(nums, goal)` and `atMost(nums, goal - 1)`, then subtracting them.
   - `atMost(nums, goal)` gives the number of subarrays with sum at most `goal`.
   - `atMost(nums, goal - 1)` gives the number of subarrays with sum at most `goal - 1`.
   - The difference between the two counts gives the number of subarrays with sum exactly `goal`.

2. **atMost**:
   - This function computes the number of subarrays whose sum is at most `goal`.
   - We use a sliding window approach with two pointers (`left` and `right`). 
   - We iterate over the array using the `right` pointer.
   - If the sum exceeds the goal, we move the `left` pointer to shrink the window until the sum is less than or equal to the goal.
   - For each position of `right`, we count the number of valid subarrays that end at `right` and start from any index between `left` and `right`.

### Time Complexity:
- **O(n)**: The sliding window mechanism ensures that each element is processed at most twice (once by the `right` pointer and possibly once by the `left` pointer). Thus, the time complexity is linear with respect to the number of elements in the array.

### Space Complexity:
- **O(1)**: The algorithm uses a constant amount of extra space for variables (`count`, `sum`, `left`, `right`).


