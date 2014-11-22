#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

class segment_tree
{
	vector<LL> st;
	LL idt;
	int N, size;
	LL func(LL a, LL b)
	{
		return a+b;
	}
	LL getUtil(int ts, int te, int qs, int qe, int root)
	{
		if(qs==ts && qe==te)
			return st[root];
		int mid = (ts+te)/2;
		LL v1 = qs<=mid?getUtil(ts, mid, qs, min(qe, mid), 2*root):idt;
		LL v2 = qe>mid?getUtil(mid+1, te, max(qs, mid+1), qe, 2*root+1):idt;
		return func(v1, v2);
	}
	public:
	segment_tree(vector<LL> &v)
	{
		idt = 0;
		size = v.size();
		int level = ceil(log2(size));
		N = 1<<(level+1);
		st = vector<LL>(N, idt);
		for(int i=0; i<size; i++)
			st[N/2 + i] = v[i];
		for(int i=level-1; i>=0; i--)
			for(int j=(1<<i); j<(1<<(i+1)); j++)
				st[j] = func(st[2*j], st[2*j+1]);
	}
	void set(int pos, LL val)	//0-indexed
	{
		int ind = (N/2) + pos;
		st[ind] = val;
		for(ind/=2; ind>0; ind/=2)
			st[ind] = func(st[2*ind], st[2*ind+1]);
	}
	LL get(int start, int end)	//0-indexed
	{
		return getUtil(0, N/2 - 1, start, end, 1);
	}
};

int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n, q;
	char s[5];
	int ind, val;
	scanf("%d%d", &n, &q);
	VLL v(n);
	for(int i=0; i<n; i++)
		SLL(v[i]);
	segment_tree st(v);
	while(q--)
	{
		scanf("%s%d%d", s, &ind, &val);
		if(s[0] == 'S')
			printf("%lld\n", st.get(ind, val));
		else if(s[0] == 'G')
			st.set(ind, st.get(ind, ind)+val);
		else if(s[0] == 'T')
			st.set(ind, st.get(ind, ind)-val);
	}
	
	return 0;
}

