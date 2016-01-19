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
#define inp2ll(n,m) inpll(n), inpll(m)
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
ll a[1234567];
ll n,c,maxx=-1,ans;

bool binary_search(ll x){
	/*if(low>high)
		return 0;
	ll mid=(low+high)/2;
	int remcow=c-1,j=1,prev=a[0];
	while(remcow && remstall>=remcow){
		while(!h[j] && j<=maxx){
			j++;
		}
		if(h[j]-prev>=mid){
			remcow--;
			prev=h[j];
		}
		remstall--;
		j++;
	}*/
	if(x==1)
		return 1;
	if(x==a[n-1]-a[0]+1)
		return 0;
	int j=1,remcow=c-1,prev=a[0];
	while(j<n)
	{
		if(a[j]-prev>=x){
			if(--remcow==0)
				return 1;
			prev=a[j];
		}
		j++;
	}
	return 0;
}
int main(){	
	int test;
	inp(test);
	while(test--){
	inp2ll(n,c);
	rep(i,n){
		inpll(a[i]);
	}
	sort(a,a+n);
	ll start=0,end=a[n-1]-a[0]+1,mid;
	while(end-start>1)
	{
  	mid=(end+start)>>1;
  	(binary_search(mid)?start:end)=mid;
	}
	cout<<start<<endl;
	}
	return 0;
}
