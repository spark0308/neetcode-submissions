class Solution {
public:
    struct euclideanCompare{
        bool operator()(const vector<int> &x, const vector<int> &y){
            float distX = sqrt((x[0] - 0)*(x[0] - 0) + (x[1] - 0)*(x[1] - 0));
            float distY = sqrt((y[0] - 0)*(y[0] - 0) + (y[1] - 0)*(y[1] - 0));

            return distX > distY;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, euclideanCompare> heap;

        for(auto x: points) heap.push(x);

        vector<vector<int>> ans;
        for(int i=0; i<k; i++){
            ans.push_back(heap.top());
            heap.pop();
        }

        return ans;
    }
};
