class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        stack<pair<int, int>> stck;
        int n = position.size();

        for(int i=0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        for(int i=0; i<n; i++){
            while(!stck.empty()){
                pair<int, int> top = stck.top();
                double u1 = cars[i].second;
                double u2 = top.second;
                double s1 = cars[i].first;
                double s2 = top.first;

                if(u1 >= u2)  break;
                else{
                    double meetingPoint = (double) ((u2 * (s2-s1)/(u1-u2)) + s2);
                    cout<<meetingPoint<<endl;
                    if(meetingPoint > target) break;
                    stck.pop();
                }
            }
            stck.push({cars[i].first, cars[i].second});
        }

        return stck.size();
    }
};
