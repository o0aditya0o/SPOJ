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

char a[1001][1001];
int vis[1001][1001],n,m,t,k=1;
stack< pair<int,int> > s;
pair<int,int> p,q;

pair<int,int> valid(pair<int,int> p){
	if(a[p.X][p.Y]=='N'){
			q.X=p.X-1;
			q.Y=p.Y;
			return q;
	}
	if(a[p.X][p.Y]=='S'){
			q.X=p.X+1;
			q.Y=p.Y;
			return q;		
	}
	if(a[p.X][p.Y]=='E'){
			q.X=p.X;
			q.Y=p.Y+1;
			return q;
	}
	if(a[p.X][p.Y]=='W'){
			q.X=p.X;
			q.Y=p.Y-1;
			return q;
	}
}

void dfs(int x,int y){
	k++;
	vis[x][y]=k;
	p=MP(x,y);
	s.push(p);
	while(!s.empty()){
		p=s.top();
		s.pop();
		q=valid(p);
		if(!vis[q.X][q.Y])
			{
				s.push(q);
				vis[q.X][q.Y]=k;
			}
		else if(vis[q.X][q.Y]==k){
			t++;
		}
	}
}
int main(){
	inp2(n,m);
	rep(i,n){
		scanf("%s",a[i]);
	}
	rep(i,n){
		rep(j,m){
			if(!vis[i][j]){
				dfs(i,j);
			}
		}
	}
	cout<<t<<endl;
	return 0;
}
