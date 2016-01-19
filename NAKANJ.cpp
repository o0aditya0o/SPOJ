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
queue< pair<int,int> > q;
pair<int,int> p;
int level[8][8];
vector<int>::iterator it;
void bfs(int x,int y){
	level[x][y]=1;
	q.push(MP(x,y));
	while(!q.empty()){
		p=q.front();
		//cout<<"front "<<p.first<<" "<<p.second<<endl;
		q.pop();
		int a=p.first,b=p.second;
		if(a+2<8 && b+1<8 && !level[a+2][b+1]){
			level[a+2][b+1]=level[a][b]+1;
			q.push(MP(a+2,b+1));
		}
		if(a+2<8 && b-1>=0 && !level[a+2][b-1]){
			level[a+2][b-1]=level[a][b]+1;
			q.push(MP(a+2,b-1));
		}
		if(a-2>=0 && b+1<8 && !level[a-2][b+1]){
			level[a-2][b+1]=level[a][b]+1;
			q.push(MP(a-2,b+1));
		}
		if(a-2>=0 && b-1>=0 && !level[a-2][b-1]){
			level[a-2][b-1]=level[a][b]+1;
			q.push(MP(a-2,b-1));
		}
		if(a+1<8 && b+2<8 && !level[a+1][b+2]){
			level[a+1][b+2]=level[a][b]+1;
			q.push(MP(a+1,b+2));
		}
		if(a+1<8 && b-2>=0 && !level[a+1][b-2]){
			level[a+1][b-2]=level[a][b]+1;
			q.push(MP(a+1,b-2));
		}
		if(a-1>=0 && b+2<8 && !level[a-1][b+2]){
			level[a-1][b+2]=level[a][b]+1;
			q.push(MP(a-1,b+2));
		}
		if(a-1>=0 && b-2>=0 && !level[a-1][b-2]){
			level[a-1][b-2]=level[a][b]+1;
			q.push(MP(a-1,b-2));
		}

	}
}
int main(){
	int test;
	inp(test);
	//cout<<test<<endl;
	while(test--){
		rep(i,8){
			rep(j,8){
				level[i][j]=0;
			}
		}
		char s[2],b[2];
		char c=getchar();
		s[0]=getchar();
		//cout<<s[0]<<endl;
		s[1]=getchar();
		//cout<<s[1]<<endl;
		c=getchar();
		b[0]=getchar();
		//cout<<b[0]<<endl;
		b[1]=getchar();
		//cout<<b[1]<<endl;
		
		bfs(s[0]-'a',s[1]-'1');
		printf("%d\n",level[b[0]-'a'][b[1]-'1']-1);
	}

	return 0;
}
