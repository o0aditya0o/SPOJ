/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
 * Created By : Aditya Agarwal
 * IT, MNNIT-ALLAHABAD 
 * aditya.mnnit15@gmail.com
 _._._._._._._._._._._._._._._._._._._._._.*/


#include<bits/stdc++.h>
using namespace std;

#define MP make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define PER(i,a,b) for(int i=b;i>=a;i--)
#define X first
#define Y second

 //i/o
#define inp(n) scanf("%d",&n)
#define inpl(n) scanf("%lld",&n)
#define inp2(n,m) inp(n), inp(m)
#define inp2l(n,m) inpl(n), inpl(m)


//cost
#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 100009
#define INF 999999999
#define mp make_pair
typedef long long ll;
typedef pair< pair<ll,ll>,ll > pairs;
int n,dp[205][205][205],a[205];
int top_down(int high,int low,int curr){
	if(curr==n)
		return 0;
	int x=INF,y=INF,z=INF;
    	if(dp[high][low][curr]!=-1)
		return dp[high][low][curr];
	else{
		if(a[curr]<a[high]){
			x=top_down(curr,low,curr+1);
		}
		if(a[curr]>a[low]){
		    	y=top_down(high,curr,curr+1);
		}
		z=1+top_down(high,low,curr+1);
		dp[high][low][curr]=min(x,min(y,z));
		return dp[high][low][curr];
	}
}

int main(){
	while(1){
		inp(n);
		if(n==-1)
			break;
		rep(i,n){
			inp(a[i]);
		}
		rep(i,203){
			rep(j,203){
				rep(k,203){
					dp[i][j][k]=-1;
				}
			}
		}
		a[202]=INF;
		a[201]=0;
		int ans=top_down(202,201,0);
		cout<<ans<<endl;
	}
	return 0;
}
