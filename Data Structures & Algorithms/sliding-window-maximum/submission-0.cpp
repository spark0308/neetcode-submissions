class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<int> elem;
        map<int, int> freq;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<k; i++){
            elem.insert(nums[i]);
            freq[nums[i]]++;
        }

        ans.push_back(*prev(elem.end()));

        for(int i=k; i<n; i++){
            freq[nums[i]]++;
            elem.insert(nums[i]);

            freq[nums[i-k]]--;
            if(freq[nums[i-k]] == 0) elem.erase(nums[i-k]);

            ans.push_back(*prev(elem.end()));
        }

        return ans;
    }
};
