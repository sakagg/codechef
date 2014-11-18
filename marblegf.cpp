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

class bit
{
	vector<LL> x;
	int size;
	public:
	bit(int sz)
	{
		size = sz;
		x.resize(sz+1);		//Note: 1-indexed
	}
	void add(int index, int value)
	{
		for(int i=index; i<=size; i+=(i&(-i)))
			x[i]+=value;
	}
	LL get(int index)
	{
		LL sum = 0;
		for(int i=index; i>0; i-=(i&(-i)))
			sum+=x[i];
		return sum;
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
	bit b(n);
	int num;
	for(int i=0; i<n; i++)
	{
		SI(num);
		b.add(i+1, num);
	}
	while(q--)
	{
		scanf("%s%d%d", s, &ind, &val);
		if(s[0] == 'S')
			printf("%lld\n", b.get(val+1)-b.get(ind));
		else if(s[0] == 'G')
			b.add(ind+1, val);
		else if(s[0] == 'T')
			b.add(ind+1, -val);
	}
	return 0;
}

