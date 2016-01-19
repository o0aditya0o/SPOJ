#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int test,n,x=1;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		int a[n+1],dp[n+1],ans;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(n==0)
			ans=0;
		else if(n==1)
			ans=a[0];
		else
			{
			dp[0]=a[0];
			dp[1]=max(a[0],a[1]);
			for(int i=2;i<n;i++)
				dp[i]=max((a[i]+dp[i-2]),dp[i-1]);
			ans=dp[n-1];
			}
		printf("Case %d: %d\n",x,ans);
		x++;
	}
	return 0;
}
