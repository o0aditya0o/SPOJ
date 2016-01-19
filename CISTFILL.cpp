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
int n;
ll base[50005],a[50005],b[50005],c[50005],v;

bool possible(ll height){
	ll volume=0;
	rep(i,n){
		if(a[i]+base[i]<=height)
			volume+=a[i]*b[i]*c[i];
		else if(base[i]<height)
			volume+=(height-base[i])*b[i]*c[i];
	}
	if(volume<v)
		return 0;
	return 1;
}




double binary_search(double low,double high){
	if(low==high)
		return low;
	else{
		double mid=(high-low)/2+low;
		if(possible(mid))
			return binary_search(low,mid);
		else
			return binary_search(mid+1,high);
	}
}
int main(){
	int k;
	inp(k);
	while(k--){
		inp(n);
		ll vol=0;
		ll maxb=-1,minb=INF;
		double ans;
		rep(i,n){
			inp2ll(base[i],a[i]);
			inp2ll(b[i],c[i]);
			vol+=(a[i]*b[i]*c[i]);
			maxb=max(maxb,base[i]+a[i]);
			minb=min(minb,base[i]);
		}
		inpll(v);
		if(v>vol)
		{
			printf("Overflow\n");
			continue;
		}
		else
		{
			ans=binary_search(minb,maxb);
		}
		printf("%.2f\n",ans);
	}

	return 0;
}
