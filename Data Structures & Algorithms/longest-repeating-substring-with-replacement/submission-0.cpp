class Solution {
public:
    int characterReplacement(string s, int k) {
         map<char, int> count;
         int ans = 0;
         int l = 0, maxf = 0;

         for(int r = 0; r < s.size(); r++){
            count[s[r]]++;
            if(count[s[r]] > maxf) maxf = count[s[r]];
            
            int winSize = r - l + 1;
            while(winSize - maxf > k){
                count[s[l]]--;
                l++;
                winSize = r - l + 1;
            }
            ans = max(ans, winSize);
         }
         return ans;
    }
};
