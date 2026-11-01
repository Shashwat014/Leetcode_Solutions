class Solution {
public:
    // bool find(vector<int>&arr , int t){
    //     int l=0 , h=arr.size()-1;
    //     while(l<=h){
    //         int m= (l+h)/2;
    //         if(arr[m]==t)return true;
    //         else if(arr[m]<t)l=m+1;
    //         else h=m-1;
    //     }
    //     return false;
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int n=matrix.size() , m=matrix[0].size();
        // for(int i=0 ; i<n ; i++){
        //     if(matrix[i][m -1] >= target  ){
        //         return find(matrix[i] , target);
        //     }
        //     else continue;
        // }
        // return false;


        int n=matrix.size() , m=matrix[0].size();
        int l=0 , h=n*m-1;
        while(l<=h){
            int mid=(l+h)/2;
            int r=mid/m;
            int c=mid%m;
            if(matrix[r][c]==target)return true;
            if(matrix[r][c]<target)l=mid+1;
            else h=mid-1;
        }
        return false;
        }
};