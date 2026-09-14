class Solution {
    int randIndex(int l, int r){
        int len = r-l+1;
        return (rand()%len)+l;
    }

    float calculateEucDist(int x1, int y1){
        return sqrt((x1 - 0)*(x1 - 0) + (y1 - 0)*(y1 - 0));
    }

    int quickSearch(vector<vector<int>> &points, int l, int r, int k){
        int pivotIndex = randIndex(l, r);
        vector<int> pivot = points[pivotIndex];
        int p = l;
        swap(points[pivotIndex], points[r]);

        float pivotDis = calculateEucDist(pivot[0], pivot[1]);

        for(int i=l; i<r; i++){
            if(calculateEucDist(points[i][0], points[i][1]) < pivotDis){
                swap(points[p], points[i]);
                p++;
            }
        }
        swap(points[p], points[r]);

        if(p == k) return p;
        if(p > k) return quickSearch(points, l, p-1, k);
        
        return quickSearch(points, p+1, r, k);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue<vector<int>, vector<vector<int>>, euclideanCompare> heap;

        // for(auto x: points) heap.push(x);

        // vector<vector<int>> ans;
        // for(int i=0; i<k; i++){
        //     ans.push_back(heap.top());
        //     heap.pop();
        // }
        if(k >= points.size()) return points;
        quickSearch(points, 0, points.size() - 1, k);

        vector<vector<int>> ans;

        for(int i=0; i<k; i++) ans.push_back(points[i]);

        return ans;
    }
};
