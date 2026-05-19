class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high =  (m*n) - 1;

        while(low<=high){
            int mid = (high-low)/2 + low;
            int i = mid/n;
            int j = mid%n;

            if(matrix[i][j] == target) return true;

            if(matrix[i][j] < target) low = mid + 1;

            if(matrix[i][j] > target) high = mid - 1;
        }

        return false;
    }
};
