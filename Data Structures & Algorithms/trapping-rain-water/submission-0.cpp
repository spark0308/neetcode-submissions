class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> waterContains = vector<int>(n, 0);
        int i = 0; 
        int j = 1;
        for(;j<n; j++){
            if(height[i] <= height[j]) i = j;
            else{
                waterContains[j] = height[i] - height[j];
            }
        }
        int ans = 0;
        for(int x =0; x<=i; x++) ans += waterContains[x];

        int reference = waterContains[n-1];
        for(int x=n-2; x>i;x--){
            if(reference > waterContains[x] ) reference = waterContains[x];
            else ans += (waterContains[x] - reference);
        }

        return ans;
    }
};
