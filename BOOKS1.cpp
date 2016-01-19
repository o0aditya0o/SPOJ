/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
 * Created By : Aditya Agarwal
 * IT, MNNIT-ALLAHABAD 
 * aditya.mnnit15@gmail.com
 _._._._._._._._._._._._._._._._._._._._._.*/


#include<bits/stdc++.h>
using namespace std;

#define MP make_pair
#define pb push_back
#define rep(i,n) for(long long i=0;i<n;i++)
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
#define out(n) printf("%lld ",n)
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
ll a[501],n,k;
ll func(ll x){
	ll nop=k;
	ll temp_sum=0;
	for(ll j=n-1;j>=0 ;j--){
		if(a[j]>x)
			return -1;
		temp_sum+=a[j];
		//cout<<temp_sum<<"  temp sum inside "<<j<<endl;
		if(temp_sum>x){
			--nop;
			//cout<<nop<<" inside "<<endl;
			temp_sum=a[j];
		}
	}
	return nop;
}
ll binary_search(ll low,ll high){
	ll mid=low+(high-low)/2;
	if(high-low<2)
		{
			//cout<<high<<"  HIGH  "<<low<<"   LOW   "<<endl;
			if(func(low)>=1)
				return low;
			else
				return high;
		}

	ll nop=func(mid);
	//cout<<high<<"  HIGH  "<<low<<"   LOW   "<<nop<<"   NOP  "<<endl;
	/*int nop=k;
	for(int j=n-1;j>=0 && j+1>=nop){
		sum+=a[j];
		if(sum>x){
			--nop;
			sum=a[j];
		}
	}*/

	if(nop>0)
		return binary_search(low,mid);
	else 
		return binary_search(mid+1,high);
}


int main(){
	int test;
	ll sum,x;
	inp(test);
	while(test--){
		inp2ll(n,k);
		sum=0;
		rep(i,n){
			inpll(a[i]);
			sum+=a[i];
		}
		//cout<<sum<<endl;
		ll p[501],g=0,people=k,pp=binary_search(1,sum);
		//cout<<pp<<endl;
		//cout<<func(11)<<endl;
		ll temp_sum=0;
		for(ll j=n-1;j>=0;j--){

			temp_sum+=a[j];
			if(!(temp_sum<=pp && j>=people-1)){
				p[g++]=j;
				temp_sum=a[j];
				people--;
			}
		}
		g--;
		rep(i,n){
			out(a[i]);
			if(i==p[g] && g>=0){
				printf("/ ");
				g--;
			}
		}
		printf("\n");
	}

	return 0;
}
