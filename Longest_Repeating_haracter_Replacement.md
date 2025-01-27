__Longest_Repeating_Character_Replacement__

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

__Example 1:__
__Input:__  s = "ABAB", k = 2
__Output:__ 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

__Input:__ s = "AABABBA", k = 1
__Output:__ 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 
 __Constraints:__
1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
__Approach__:

##To solve this problem we can use two pointers and sliding window approach

##Algorithm:-

### Algorithm :

1. **Initialize Variables**:
   - Define two pointers, `l` (left) and `r` (right), to represent the sliding window.
   - Set `maxlen` to store the length of the longest valid substring.
   - Use `maxf` to track the maximum frequency of a single character in the current window.
   - Create a `hash` vector of size 26 (for uppercase letters 'A' to 'Z') initialized to 0, to store character frequencies.

2. **Iterate Over the String**:
   - Expand the sliding window by moving the `r` pointer from left to right.
   - For the character `s[r]`:
     1. Update its frequency in the `hash` vector.
     2. Update `maxf` to the maximum frequency of any character in the current window.

3. **Check Window Validity**:
   - Calculate the size of the current window as `r - l + 1`.
   - If the number of replacements required (`(r - l + 1) - maxf`) exceeds `k`, shrink the window:
     1. Decrement the frequency of `s[l]` in the `hash` vector.
     2. Move the `l` pointer to the right by 1.

4. **Update Maximum Length**:
   - After adjusting the window, calculate the valid window size and update `maxlen` to store the maximum length of the substring.

5. **Repeat Until the End of the String**:
   - Continue expanding and adjusting the window while iterating through the string with the `r` pointer.

6. **Return the Result**:
   - Return `maxlen` as the length of the longest valid substring.

---

### Pseudocode for the Algorithm:

```plaintext

function characterReplacement(s, k):
    initialize l = 0, r = 0
    initialize maxlen = 0
    initialize maxf = 0
    initialize hash = array of size 26 with all values 0

    while r < length of s:
        hash[s[r] - 'A'] += 1
        maxf = max(maxf, hash[s[r] - 'A'])

        window_size = r - l + 1
        if (window_size - maxf > k):
            hash[s[l] - 'A'] -= 1
            l += 1

        maxlen = max(maxlen, r - l + 1)
        r += 1

    return maxlen
```

This algorithm ensures an **O(n)** time complexity since both pointers traverse the string once. 
