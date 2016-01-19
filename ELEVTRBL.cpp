/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\
 * Created By : Aditya Agarwal             |
 * IT, MNNIT-ALLAHABAD                     |
 * aditya.mnnit15@gmail.com                |
 _._._._._._._._._._._._._._._._._._._._._*/


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
int visited[1000001];
queue<int> q;
int main(){
	int f,s,g,u,d;
	scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
	if(s==g)
		printf("0\n");
	else
	{
		visited[s]=1;
		q.push(s);
		while(!q.empty()){
			int y=q.front();
			q.pop();
			if(y+u<=f && visited[y+u]==0){
				visited[y+u]=visited[y]+1;
				q.push(y+u);
			}
			if(y-d>=1 && visited[y-d]==0){
				visited[y-d]=visited[y]+1;
				q.push(y-d);
			}
		}
		if(visited[g]!=0){
			printf("%d\n",visited[g]-1);
		}
		else
			printf("use the stairs\n");

	}


	return 0;
}
