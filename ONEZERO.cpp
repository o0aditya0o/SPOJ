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
int val[100001],par[100001];
int s[100001];
queue<int> q;
int level[100001];
int bfs(int n,int* val){
	level[1]=1;
	par[1]=-1;
	q.push(1);
	while(!q.empty()){
		int y=q.front();
		//cout<<y<<endl;
		q.pop();
		int c,d;
		c=(y*10)%n;
		d=(y*10+1)%n;
		if(c==0){
			*val=0;
			return y;
		}
		else if(d==0){
			*val=1;
			return y;
		}
		if(level[c]==-1){
			q.push(c);
			level[c]=0;
			par[c]=y;
		}
		if(level[d]==-1){
			q.push(d);
			level[d]=1;
			par[d]=y;
		}
	}
	return 0;
}

void generate(int x){
	int k=0;
	while(x!=-1){
		//cout<<x<<" "<<level[x]<<endl;
		s[k++]=level[x];
		x=par[x];
	}
	for(int i=k-1;i>=0;i--)
		printf("%d",s[i]);
}
int main(){
	int t;
	inp(t);
	while(t--){
		int n,val;
		inp(n);
		rep(i,n)
			{
				level[i]=-1;
				par[i]=-1;
			}
		while(!q.empty())
			q.pop();
		int x=bfs(n,&val);
		//cout<<x<<endl;
		generate(x);
		cout<<val<<endl;
	}
	return 0;
}
