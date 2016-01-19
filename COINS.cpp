#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[100000001];
ll fun(ll n){
	if(n<12)
		return n;
	else
		return max(n,(fun(n/2)+fun(n/3)+fun(n/4)));
}
int main(){
	ll num,ans;
	while((scanf("%lld",&num))!=EOF){
		
		if(num<3)
			ans=num;
		else if(num<100000001)
		{
		for(int i=0;i<12;i++)
			dp[i]=i;
		for(ll i=12;i<=num;i++)
			{
			dp[i]=max(i,(dp[i/2]+dp[i/3]+dp[i/4]));
			//cout<<i<<" "<<dp[i]<<endl;
		}		
		ans=dp[num];
		}
		else{
			ans=fun(num);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
