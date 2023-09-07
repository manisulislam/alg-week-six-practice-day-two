class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int s=0;
        for(int val: nums){
            s+=val;
        }
        
        if(s%2 == 0){
            int sum= s/2;
            bool dp[n+1][sum+1];
            dp[0][0] =true;
            for(int i=1; i<=sum; i++) dp[0][i]=false;
            
            for(int i=1; i<=n; i++){
                for(int j=0; j<=sum; j++){
                    if(nums[i-1]<= j){
                    bool op1= dp[i-1][j-nums[i-1]];
                    bool op2= dp[i-1][j];
                    dp[i][j]= op1 || op2;
    
                    }
                    else{
                        dp[i][j]= dp[i-1][j];
                    }
                 }
            }
            if(dp[n][sum]){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
        
    }
};