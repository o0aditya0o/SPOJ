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
vector<int> v[10001];
queue<int> q;
int level[10001];

vector<int>::iterator it;
void bfs(int x){
	level[x]=0;
	q.push(x);
	while(!q.empty()){
		int y=q.front();
		//cout<<"front "<<y<<endl;
		q.pop();
		it=v[y].begin();
		while(it!=v[y].end()){
			if(level[*it]==-1){
				level[*it]=level[y]+1;
				//cout<<"INSIDE : "<<*it<<" "<<level[*it]<<endl;
				q.push(*it);
			}
			it++;
		}
	}
}
int main(){
	int t;
	inp(t);
	while(t--){
	int n,a,b,maxx=-2,k;
	cin>>n;
	rep(i,n){
		cin>>a;		
		v[i+1].push_back(a);
	}
	for (int i = 0; i <= n; ++i)
	{
		level[i]=-1;
	}
	/*bfs(1);
	for(int i=1;i<=n;i++){
		//cout<<level[i]<<" ";
		if(maxx<level[i]){
			maxx=level[i];
			k=i;
		}
	}
	//cout<<endl<<k<<endl;
	for (int i = 0; i <= n; ++i)
	{
		level[i]=-1;
	}*/
	bfs(4);
	for(int i=1;i<=n;i++){
		//cout<<level[i]<<" ";
		if(maxx<level[i]){
			maxx=level[i];
			k=i;
		}
	}
	cout<<maxx+1<<endl;
 	}

	return 0;
}





