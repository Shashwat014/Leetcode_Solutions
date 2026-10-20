class Solution {
public:
    int first(vector<int>& n, int t){
        int f=-1 , l=0 , r=n.size()-1;
        while(l<=r){
            int m = l+ (r-l)/2;
            if(n[m] == t){
                f=m;
                r=m-1;
            }
            else if(n[m] > t)r=m-1;
            else l=m+1;
        }
        return f;
    }
    int last(vector<int>& n, int t){
        int la=-1 , l=0 , r=n.size()-1;
        while(l<=r){
            int m = l+ (r-l)/2;
            if(n[m] == t){
                la=m;
                l=m+1;
            }
            else if(n[m] > t)r=m-1;
            else l=m+1;
        }
        return la;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target) , last(nums,target)};
    }
};