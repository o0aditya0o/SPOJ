/*
Insertion of N strings in a trie
*/
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

struct trie {
	int next[10];
	int flag;
}node[100001];

int allocated;

void insert(string s) {
	int current = 0;  //so root node is node[0]
	for(int i = 0; i < s.length(); i++) {
		if(node[current].next[s[i]-'0'] == 0) { //no link --> so allocate it
			node[current].next[s[i]-'0'] = allocated;
			current = allocated;
			allocated++;
		}
		else current = node[current].next[s[i]-'0'];  //already present --> so just update current

		//setting flag for last character of string
		if(i == s.length()-1) {
			node[current].flag = 1;
		}
	}
}

int exist(string s) {
	int current = node[0].next[s[0]-'0'];  //so root node is node[0]
	for(int i = 1; i < s.length(); i++) {
		if(node[current].flag == 1) { //no link --> so allocate it
			return 1;
		}
	 current = node[current].next[s[i]-'0']; 
	}
	return 0;
}

int main() {
	int test;
	inp(test);
	while(test--){
	int n,c=0;
	cin>>n;  //input number of strings
	string s[n+1];
	allocated = 1; //allocated to be started from 1

	memset(node, 0, sizeof node); //initialize node to 0 (each values in next[] array and flag will be 0 for each node)

	for(int i=0;i<n;i++) {
		cin>>s[i]; //input string one by one
		//cout<<s[i];
		insert(s[i]); //insert the string in trie and mark the end of this string by setting flag to 1 for last character's node
	}
	rep(i,n){
		//cout<<s[i]<<endl;
		//cout<<exist(s[i])<<endl;
		if(exist(s[i])){
			c++;
			break;
		}
	}
	if(c)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	}

	return 0;
}
