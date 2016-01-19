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
#define all(c) c.begin(),c.end() //eg sort(all(v));

 typedef long long ll;
 typedef vector<int> vi; 
 typedef vector< vi > vvi; 
 typedef pair< int,int > ii; 

#define sz(a) int((a).size())
#define clr(a) memset(a,0,sizeof(a))
#define ini(a) memset(a,-1,sizeof(a))

 //i/o
#define inp(n) scanf("%d",&n)
#define inpll(n) scanf("%lld",&n)
#define inp2(n,m) inp(n), inp(m)
#define ins(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define outll(n) printf("%lld\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define inc(n) scanf("%c",&n)


//cost
#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 100009
#define INF 999999999
#define mp make_pair
typedef long long ll;
typedef pair< pair<ll,ll>,ll > pairs;
int n,a[1001],dp[1001][1001];

ll mem(int low,int high){
	ll c,b;
	if(low>high)
		return 0;
	else if(!dp[low][high]){
		if(a[low+1]>=a[high])
			b=a[low]-a[low+1]+mem(low+2,high);
		else
			b=a[low]-a[high]+mem(low+1,high-1);
		if(a[low]>=a[high-1])
			c=a[high]-a[low]+mem(low+1,high-1);
		else
			c=a[high]-a[high-1]+mem(low,high-2);
		dp[low][high]=max(b,c);
	}
	return dp[low][high];
}

void init(){
	rep(i,n+1)
		rep(j,n+1)
			dp[i][j]=0;
}
int main(){
	int k=1;
	while(1){
		
		inp(n);
		init();
		if(n==0)
			break;
		rep(i,n)
			inp(a[i]);
		ll ans=mem(0,n-1);
		printf("In game %d, the greedy strategy might lose by as many as %lld points.\n",k,ans); 
		k++;
	}	

	return 0;
}
