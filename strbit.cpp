
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

class bit_range_update_get_value
{
    int size;
    vector<long long> x;
	public:
	bit_range_update_get_value(int sz) 
    {   
        size = sz; 
        x.resize(sz+1);
    }   
    void add(int index, int value)      //For Updating range(a,b,x) do add(b,x); add(a-1, -x);
    {   
        for(int i=index; i>0; i-=(i&(-i)))
            x[i]+=value;
    }   
    long long get(int index)        //Get Total sum of a specific index
    {   
        long long sum = 0;
        for(int i=index; i<=size; i+=(i&(-i)))
            sum+=x[i];
        return sum;
    }   
};

typedef bit_range_update_get_value BIT;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, k;
		SI(n); SI(k);
		char a[100100];
		scanf("%s", a);
		BIT b(n);
		int cnt = 0;
		for(int i=0; i<n; i++)
		{
			int val = b.get(i+1)%2;
			if(((val == 0)^(a[i] == 'R')) == 0)
			{
				cnt++;
				b.add(min(i+k, n), 1);
				b.add(i, -1);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
