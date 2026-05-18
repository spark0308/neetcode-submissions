class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        // treat end as a height-0 sentinel to flush remaining bars
        int currHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && currHeight < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int leftBoundary = st.empty() ? -1 : st.top();
            int width = i - leftBoundary - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }

    return maxArea;
    }
};
