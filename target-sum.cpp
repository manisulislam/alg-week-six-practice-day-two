class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int s= 0;
        for(int val: nums){
            s+=val;
        }
        cout<<s<<endl;
        if((s+target)%2==0 && (s+target)>=0){
            int s1= (s+target)/2;
            cout<<s1<<endl;
            int dp[n+1][s1+1];
            dp[0][0] = 1;
            for(int i=1; i<=s1; i++) dp[0][i]= 0;
            
            for(int i=1; i<=n;i++){
                for(int j=0; j<=s1; j++){
                    if(nums[i-1]<=j){
                        int op1= dp[i-1][j-nums[i-1]];
                        int op2= dp[i-1][j];
                        dp[i][j]= op1+op2;
                    }
                    else{
                        dp[i][j]= dp[i-1][j];
                    }
                }
            }
           return dp[n][s1];
            //else return 0;
        }
        else{
            return 0;
        }
    }
};