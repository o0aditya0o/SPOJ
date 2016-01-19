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
int ques[1000][1000],ans[183][183],level[1000][1000],n,m;
queue<pair <int,int> > q;
pair <int,int> p;
void bfs(int x,int y){
	level[x][y]=0;
	q.push(MP(x,y));
	while(!q.empty()){
		p=q.front();
		q.pop();
		int c=p.X,d=p.Y;
		if(c+1<n && ques[c+1][d]==0)
			{
				if(level[c+1][d]>level[c][d]+1)
					{
						level[c+1][d]=level[c][d]+1;
						q.push(MP(c+1,d));
					}
					
			}
		if(c-1>=0 && ques[c-1][d]==0)
			{
				if(level[c-1][d]>level[c][d]+1)
					{	
					level[c-1][d]=level[c][d]+1;
					q.push(MP(c-1,d));
					}
			}
		if(d+1<m && ques[c][d+1]==0)
			{
				if(level[c][d+1]>level[c][d]+1)
					{
					level[c][d+1]=level[c][d]+1;
					q.push(MP(c,d+1));
					}
			}
		if(d-1>=0 && ques[c][d-1]==0)
			{
				if(level[c][d-1]>level[c][d]+1)
					{
					level[c][d-1]=level[c][d]+1;
					q.push(MP(c,d-1));
					}
			}
	}


}
int main(){
	int t;
	inp(t);
	while(t--){
		inp2(n,m);
		rep(i,n){
			rep(j,m){
				scanf("%1d",&ques[i][j]);				
				level[i][j]=INF;
			}
		}
		
		rep(i,n){
			rep(j,m){
				if(ques[i][j]==1)
					bfs(i,j);
			}
		}
		rep(i,n){
			cout<<level[i][0];
			REP(j,1,m-1){
				cout<<" "<<level[i][j];
			}
			cout<<endl;
		}
	}

	return 0;
}

