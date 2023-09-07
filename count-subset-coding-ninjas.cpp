
int dp[1005][1005];
int count_subset(int n, vector<int>&arr, int k){
	if(n==0){
		if(k == 0){
			return 1;
		}
		else return 0;
	}

	if(dp[n][k] != -1) return dp[n][k];

	if(arr[n-1]<= k){
		int op1= count_subset(n-1, arr, k-arr[n-1]);
		int op2=  count_subset(n-1, arr, k);
		return dp[n][k] = op1 + op2;
	}
	else{
		return dp[n][k]= count_subset(n-1, arr, k);
	}
	
}



int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n= arr.size();
	for(int i=0; i<= n; i++){
		for(int j=0; j<=k; j++){
			dp[i][j]=-1;
		}

	}
	return count_subset(n, arr, k);
}
