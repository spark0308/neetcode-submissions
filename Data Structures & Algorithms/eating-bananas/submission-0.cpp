class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for(auto x: piles) maxPile = max(maxPile, x);
        cout<<maxPile<<endl;
        int ans = maxPile;
        int low = 1;
        int high = maxPile;
        while(low<=high){
            int mid = (high-low)/2 + low;
            int hours = 0;
            for(auto x: piles) hours = hours + ceil((double)x/(double)mid);
            cout<<mid<<" "<<hours<<endl;
            if(hours > h) low = mid + 1;
            else
            {
                ans = min(mid, ans);
                high = mid - 1;
            }
        }

        return ans;
    }
};
