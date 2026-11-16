class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size()<=k)return s;
        string ans="" , temp=s;
        int sum=-1,cnt=0;
        while(true){
            int n=temp.size();
            for(int i=0 ; i<n ;i++){
                if(cnt != k){
                    if(sum==-1)sum=temp[i]-'0';
                    else sum+=temp[i]-'0';
                    cnt++;
                }
                else{
                    ans+=to_string(sum);
                    sum=temp[i]-'0';
                    cnt=1;
                }
            }
            if(sum!=-1){
                ans+=to_string(sum);

            }
            if(ans.size()<=k)return ans;
            cnt=0;
            sum=-1;
            temp=ans;
            ans="";
        } 
        return ans;  
        }
};