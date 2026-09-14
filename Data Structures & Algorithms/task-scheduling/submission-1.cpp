class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto x: tasks) freq[x-'A']++;

        sort(freq.begin(), freq.end());

        int maxF = freq[25];

        int idle = (maxF - 1) * n;

        for(int i=24; i>=0; i--){
            idle -= min(freq[i], maxF-1);
        }

        return tasks.size() + max(0, idle);
    }
};
