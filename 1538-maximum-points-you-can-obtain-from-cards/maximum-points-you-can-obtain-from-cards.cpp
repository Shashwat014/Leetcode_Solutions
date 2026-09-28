class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // aage ke char sum then ek ek km krte jao aur piche se addkrte jao aur sath hi maxsum variable me max sum store kro
        int lsum=0;
        for(int i=0 ; i<k ;i++){
            lsum+=cardPoints[i];
        }
        int maxsum=lsum;
        int rindex=cardPoints.size()-1;
        int rsum=0;
        for(int i=k-1 ; i>=0 ; i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rindex--];
            maxsum=max(maxsum , lsum+rsum);
        }
        return maxsum;
    }
};