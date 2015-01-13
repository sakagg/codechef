
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
	VLL v;
	int sum;
	node()
	{
		sum = 0;
		v = VLL(3);
	}
	node(int x)
	{
		x %= 3;
		sum = x;
		v = VLL(3);
		v[x] = 1;
	}
	void print_node()
	{
		print_array_v(v);
		cout<<sum<<endl;
	}
};

class segment_tree
{
	vector<node> st;
	node idt;
	int N, size;
	node func(node &a, node &b)
	{
		node tmp;
		tmp.sum = (a.sum + b.sum)%3;
		for(int i=0; i<3; i++)
		{
			tmp.v[i] += a.v[i];
			tmp.v[(i+a.sum)%3] += b.v[i];
		}
		return tmp;
	}
	node getUtil(int ts, int te, int qs, int qe, int root)
	{
		if(qs==ts && qe==te)
			return st[root];
		int mid = (ts+te)/2;
		node v1 = qs<=mid?getUtil(ts, mid, qs, min(qe, mid), 2*root):idt;
		node v2 = qe>mid?getUtil(mid+1, te, max(qs, mid+1), qe, 2*root+1):idt;
		return func(v1, v2);
	}
	public:
	segment_tree(char *v, int n)
	{
		size = n;
		int level = ceil(log2(size));
		N = 1<<(level+1);
		st = vector<node>(N);
		for(int i=0; i<size; i++)
			st[N/2 + i] = node(v[i]);
		for(int i=level-1; i>=0; i--)
			for(int j=(1<<i); j<(1<<(i+1)); j++)
				st[j] = func(st[2*j], st[2*j+1]);
	}
	void set(int pos, int val)	//0-indexed
	{
		int ind = (N/2) + pos;
		st[ind] = node(val);
		for(ind/=2; ind>0; ind/=2)
			st[ind] = func(st[2*ind], st[2*ind+1]);
	}
	node get(int start, int end)	//0-indexed
	{
		return getUtil(0, N/2 - 1, start, end, 1);
	}
};

int main()
{
	int n, m;
	SI(n); SI(m);
	char a[n];
	scanf("%s", a);
	segment_tree st(a, n);
	int q, x, y;
	while(m--)
	{
		SI(q); SI(x); SI(y);
		if(q==1)
		{
			st.set(x-1, y);
		}
		else if(q==2)
		{
			node tmp = st.get(x-1, y-1);
			LL ans = tmp.v[0];
			for(int i=0; i<3; i++)
				ans += (tmp.v[i]*(tmp.v[i]-1))/2;
			printf("%lld\n", ans);
		}
		else if(q==3)
		{
			node tmp = st.get(x-1, y-1);
			tmp.print_node();
		}
	}
	return 0;
}
