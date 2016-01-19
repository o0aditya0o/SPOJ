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
vector<int> v[105];

void topo(int n,int vis[],stack<int> &s){	
	vis[n]=1;
	vector<int>::iterator it;
	it=v[n].begin();
	while(it!=v[n].end()){
		if(!vis[*it]){
			topo(*it,vis,s);
		}

		it++;
	}

	s.push(n);
	
}
int main(){
	int vis[105]={0};
	stack<int> s;
	int n,m,a,b,c;
	inp2(n,m);
	rep(i,m){
		inp2(a,b);
		rep(i,b){
			inp(c);
			v[c].pb(a);
		}
	}
	/*REP(i,1,n){
		cout<<i<<" - > ";
		it=v[i].begin();
		while(it!=v[i].end()){
			cout<<*it<<" ";
			it++;
		}
		cout<<endl;
	}*/
	for(int i=1;i<=1;i++){
		if(!vis[i]){
			topo(i,vis,s);
		}
	}
	while(!s.empty()){
		printf("%d ",s.top());
		s.pop();
	}


	return 0;
}
