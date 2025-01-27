
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxlen = 0, maxf = 0;
        vector<int> hash(26, 0);
        while (r < s.length()) {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);

            if ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            maxlen = max(maxlen, (r - l + 1));
            r++;
        }
        return maxlen;
    }
};


int main() {
    Solution solution;

    // Test case 1
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Longest substring length for input \"ABAB\" with k = 2: " 
         << solution.characterReplacement(s1, k1) << endl;

    // Test case 2
    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Longest substring length for input \"AABABBA\" with k = 1: " 
         << solution.characterReplacement(s2, k2) << endl;

    // Additional test case
    string s3 = "AAAA";
    int k3 = 2;
    cout << "Longest substring length for input \"AAAA\" with k = 2: " 
         << solution.characterReplacement(s3, k3) << endl;

    return 0;
}
