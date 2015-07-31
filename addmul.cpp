
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

const int mod = 1e9 + 7;

class STLP
{
	vector<LL> st, ad, mul, v;
	LL idt;
	int N, size;
	void plusEqual(int old, int nw)
	{
		if(v[nw])
		{
			v[old] = v[nw];
			mul[old] = mul[nw];
			ad[old] = ad[nw];
			return;
		}
		mul[old] = (mul[old]*mul[nw])%mod;
		ad[old] = (ad[old]*mul[nw] + ad[nw])%mod;
	}
	LL getSum(int ts, int te, int root)	//Incorporate sr[root]
	{
		int cnt = te-ts+1;
		LL tmp = st[root];
		if(v[root]!=0)
			tmp = (cnt*v[root])%mod;
		return ((tmp*mul[root])%mod + (cnt*ad[root])%mod)%mod;
	}
	void modify(int ts, int te, int root)
	{
		st[root] = getSum(ts, te, root);
		if(root < N/2)
		{
			plusEqual(2*root, root);
			plusEqual(2*root + 1, root);
		}
		v[root] = 0;
		ad[root] = 0;
		mul[root] = 1;
	}
	LL getUtil(int ts, int te, int qs, int qe, int root)
	{
		modify(ts, te, root);
		if(qs==ts && qe==te)
			return st[root];
		int mid = (ts+te)/2;
		LL v1 = qs<=mid?getUtil(ts, mid, qs, min(qe, mid), 2*root):0;
		LL v2 = qe>mid?getUtil(mid+1, te, max(qs, mid+1), qe, 2*root+1):0;
		return (v1+v2)%mod;
	}
	LL addUtil(int ts, int te, int qs, int qe, int root, LL val)
	{
		if(qs==ts && qe==te)
		{
			ad[root] = (ad[root] + val)%mod;
			modify(ts, te, root);
			return st[root];
		}
		modify(ts, te, root);
		int mid = (ts+te)/2;
		LL v1 = qs<=mid?addUtil(ts, mid, qs, min(qe, mid), 2*root, val):getSum(ts, mid, 2*root);
		LL v2 = qe>mid?addUtil(mid+1, te, max(mid+1, qs), qe, 2*root+1, val):getSum(mid+1, te, 2*root+1);
		return st[root] = (v1 + v2)%mod;
	}
	LL mulUtil(int ts, int te, int qs, int qe, int root, LL val)
	{
		if(qs==ts && qe==te)
		{
			mul[root] = (mul[root] * val)%mod;
			ad[root] = (ad[root] * val)%mod;
			modify(ts, te, root);
			return st[root];
		}
		modify(ts, te, root);
		int mid = (ts+te)/2;
		LL v1 = qs<=mid?mulUtil(ts, mid, qs, min(qe, mid), 2*root, val):getSum(ts, mid, 2*root);
		LL v2 = qe>mid?mulUtil(mid+1, te, max(mid+1, qs), qe, 2*root+1, val):getSum(mid+1, te, 2*root+1);
		return st[root] = (v1 + v2)%mod;
	}
	LL vUtil(int ts, int te, int qs, int qe, int root, LL val)
	{
		if(qs==ts && qe==te)
		{
			mul[root] = 1;
			ad[root] = 0;
			v[root] = val;
			modify(ts, te, root);
			return st[root];
		}
		modify(ts, te, root);
		int mid = (ts+te)/2;
		LL v1 = qs<=mid?vUtil(ts, mid, qs, min(qe, mid), 2*root, val):getSum(ts, mid, 2*root);
		LL v2 = qe>mid?vUtil(mid+1, te, max(mid+1, qs), qe, 2*root+1, val):getSum(mid+1, te, 2*root+1);
		return st[root] = (v1 + v2)%mod;
	}
	public:
	STLP(vector<LL> &vec)
	{
		size = vec.size();
		int level = ceil(log2(size));
		N = 1<<(level+1);
		st = vector<LL>(N, 0);
		ad = vector<LL>(N, 0);
		mul = vector<LL>(N, 1);
		v = vector<LL>(N, 0);
		for(int i=0; i<size; i++)
			st[N/2 + i] = vec[i];
		for(int i=level-1; i>=0; i--)
			for(int j=(1<<i); j<(1<<(i+1)); j++)
				st[j] = (st[2*j] + st[2*j+1])%mod;
	}
	void add(int start, int end, LL val)	//0-indexed, inclusive
	{
		addUtil(0, N/2 - 1, start, end, 1, val);
	}
	void multiply(int start, int end, LL val)	//0-indexed, inclusive
	{
		mulUtil(0, N/2 - 1, start, end, 1, val);
	}
	void set(int start, int end, LL val)	//0-indexed, inclusive
	{
		vUtil(0, N/2 - 1, start, end, 1, val);
	}
	LL get(int start, int end)	//0-indexed, inclusive
	{
		return getUtil(0, N/2 - 1, start, end, 1);
	}
};



int main()
{
	int n, q;
	SI(n); SI(q);
	vector<LL> v(n);
	for(int i=0; i<n; i++)
		SLL(v[i]);
	STLP st(v);
	while(q--)
	{
		int ch, x, y, val;
		SI(ch); SI(x); SI(y);
		x--;
		y--;
		if(ch == 4)
		{
			printf("%lld\n", st.get(x, y));
			continue;
		}
		SI(val);
		if(ch == 1)
			st.add(x, y, val);
		else if(ch == 2)
			st.multiply(x, y, val);
		else if(ch == 3)
			st.set(x, y, val);
	}
	return 0;
}
