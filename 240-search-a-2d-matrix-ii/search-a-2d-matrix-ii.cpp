class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0 , h=matrix[0].size()-1;
        while(l<matrix.size() && h>=0){
            if(matrix[l][h]==target)return true;
            if(matrix[l][h]>target)h--;
            else l++;
        }
        return false;
    }
};