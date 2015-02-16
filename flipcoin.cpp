
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

struct node
{
	int count;
	int heads;
	bool flip;
};

class segment_tree
{
	vector<node> st;
	int N, size;
	void upUtil(int ts, int te, int qs, int qe, int root)
	{
		if(qs==qe && ts==te)
			st[root].flip = !st[root].flip;
		int mid = (ts+te)/2;
		if(qs<=mid)
			upUtil(ts, mid, qs, min(qe, mid), 2*root);
		if(qe>mid)
			upUtil(mid+1, te, max(qs, mid+1), qe, 2*root+1);
	}
	int getUtil(int ts, int te, int qs, int qe, int root)
	{
		if(qs==qe && ts==te)
			return st[root].cnt;
	public:
	segment_tree(int n)
	{
		size = n;
		int level = ceil(log2(size));
		N = 1<<(level+1);
		st = vector<PI>(N);
	}
	void update(int start, int end)
	{
		

int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	return 0;
}
