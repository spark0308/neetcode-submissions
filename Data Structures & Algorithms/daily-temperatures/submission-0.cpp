class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result = vector<int>(temperatures.size());
        stack<pair<int, int>> st;

        for(int i = 0; i<temperatures.size(); i++)
        {
            int temp = temperatures[i];
            if(st.empty()) st.push({temp, i});
            else
            {
                pair<int, int> top = st.top();
                if(top.first > temp) st.push({temp, i});
                else{
                    while(!st.empty() && top.first < temp){
                        result[top.second] = i - top.second;
                        st.pop();
                        top = st.top();
                    }
                    st.push({temp, i});
                }
            }
        }

        return result;
    }
};
