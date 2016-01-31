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
vector<int>::iterator iv;
int indegree[105],print[105];
set<int> s;
set<int>::iterator it;

int main(){
	int count=0;
	int n,m,a,b,c;
	inp2(n,m);
	rep(i,m){
		inp2(a,b);
		indegree[a]=b;
		rep(i,b){
			inp(c);
			v[c].pb(a);
		}
	}

	while(count<n){
	REP(i,1,n){
		if(indegree[i]==0 && !print[i]){
			s.insert(i);
			}
		}		
		while(!s.empty()){
			it=s.begin();
			printf("%d ",*it);
			print[*it]=1;
			count++;
			iv=v[*it].begin();
			while(iv!=v[*it].end()){
				indegree[*iv]--;
				if(indegree[*iv]==0)
					s.insert(*iv);
				iv++;
			}
			s.erase(*it);			
		}
	}
	return 0;
}
