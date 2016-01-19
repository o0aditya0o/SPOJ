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

vi v[2001];
vi:: iterator it;
int vis[2001],sex[2001];
bool susp=false;
stack<int> s;
void dfs(int x){	
		int c,q,y=x;
		for(int i=0;i<v[y].size();i++){
			c=v[y][i];
			if(!vis[c]){
				sex[c]=!sex[y];
				vis[c]=1;
				dfs(c);
				

			}
			else if(sex[c]==sex[y])
				susp=true;
		}
		
	
	

}
int main(){
	int t,n,m,a,b,count=1,x;
	inp(t);
	while(t--){
		inp2(n,m);
		REP(i,1,n){
			sex[i]=-1;
			vis[i]=0;
			v[i].clear();
		}
		x=-1;
		
		rep(i,m){
			inp2(a,b);
			v[a].pb(b);
			v[b].pb(a);
		}
		susp=false;
		REP(i,1,n){
			if(!vis[i]){
				vis[i]=1;
				sex[i]=0;
				dfs(i);
			}
			if(susp)
				break;
		}
		
		if(!susp)
			printf("Scenario #%d:\nNo suspicious bugs found!\n",count);
		else
			printf("Scenario #%d:\nSuspicious bugs found!\n",count);
		count++;
	}

	return 0;
}
