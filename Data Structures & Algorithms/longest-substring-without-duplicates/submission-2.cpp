class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last; // last index where char appeared
        int left = 0;
        int ans = 0;

        for (int right = 0; right < (int)s.size(); ++right) {
            char c = s[right];
            if (last.find(c) != last.end()) {
                // move left past the previous occurrence if it's inside the window
                left = max(left, last[c] + 1);
            }
            last[c] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
