#include<bits/stdc++.h>

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

int main()
{
    int t;
    SI(t);
    while(t--)
    {
        int n, k;
        SI(n); SI(k);
        LL a[30];
        LL sum = 0;
        LL mx = 0;
		for(int i=0; i<n; i++)
        {
            scanf("%lld", a+i);
            sum += a[i];
            mx = max(mx, a[i]);
        }
        LL num = sum/k;
        if(n < k || sum%k != 0 || mx > num)
        {
            printf("no\n");
            continue;
        }
        sort(a, a+n);
		reverse(a, a+n);
        vector<LL> v;
        v.pb(0);
        for(int i=0; i<n; i++)
        {
        	int sz = v.size();
        	for(int j=0; j<sz; j++)
        		v.pb(v[j]+a[i]);
        }
		int done = 0;
		for(int i=0; i<v.size(); i++)
			if(v[i]==num && ((done&i) == 0))
				done |= i;
		int left = (1<<n) - 1 - done;
		sum = 0;
		for(int i=0; i<n; i++)
			if(left&(1<<i))
				sum += a[i];
        if(sum == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
