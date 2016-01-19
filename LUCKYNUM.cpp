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
#define pairs pair< pair<int,int>,int>
typedef long long ll;

int val[100001],par[100001];
int s[100001];
queue<pairs> q;
int level[100001];
pairs bfs(int n){
	pairs z=MP(MP(-1,-1),-1);
	q.push(MP(MP(1,0),6%n));
	q.push(MP(MP(0,1),8%n));
	while(!q.empty()){
		pairs y=q.front();
		
		//cout<<y<<endl;
		q.pop();
		if(y.X.X+y.X.Y>1000)
			return z=MP(MP(-1,-1),-1);
		if(y.Y==0){
				z.X.X=y.X.X;
				z.X.Y=y.X.Y;
				z.Y=0;
				return z;
			}
		else
			q.push(MP(MP(y.X.X+1,y.X.Y),(y.Y*10+6)%n));
		if(y.X.X==0){			
			if(y.Y==0){
				z.X.X=y.X.X;
				z.X.Y=y.X.Y;
				z.Y=0;
				return z;
			}
			else
				q.push(MP(MP(y.X.X,y.X.Y+1),(y.Y*10+8)%n));
		}
	}

	return z;
}

int main(){
	int t;
	inp(t);
	while(t--){
		int n,val;
		inp(n);
		while(!q.empty())
			q.pop();
		pairs x=bfs(n);
		if(x.X.X==-1)
			cout<<-1<<endl;
		else
		{
			rep(i,x.X.Y)
				cout<<8;
			rep(i,x.X.X)
				cout<<6;
			cout<<endl;
		}
		
	}
	return 0;
}
