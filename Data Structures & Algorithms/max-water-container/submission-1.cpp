class Solution {
public:
    int maxArea(vector<int>& heights) {
        //min(heights[i], heights[j])*(abs(i-j))
        int n = heights.size();
        int ans = 0;
        int i = 0;
        int j = n-1;
        while(i<j){
            int curr = min(heights[i], heights[j])*(abs(i-j));
            if(curr > ans) ans = curr;
            if(heights[i] > heights[j]) j--;
            else i++;
        }

        return ans;
    }
};
