
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
LL fastPow(LL a, LL pw, LL mod)
{
	LL ans = 1;
	while(pw)
	{
		if(pw&1)
			ans = (ans*a)%mod;
		a = (a*a)%mod;
		pw >>= 1;
	}
	return ans;
}

const int mx = 1e6+5;
const int mod = 1e6+3;
LL fact[1000100];
LL ifact[1000100];

LL C(LL n, LL r, LL mod)
{
	if(r>n)
		return 0;
	return (((fact[n]*ifact[r])%mod)*ifact[n-r])%mod;
}

int main()
{
	fact[0] = fact[1] = 1;
	for(int i=2; i<mx; i++)
		fact[i] = (fact[i-1]*i)%mod;
	ifact[0] = ifact[1] = 1;
	for(int i=2; i<mx; i++)
		ifact[i] = (ifact[i-1]*fastPow(i, mod-2, mod))%mod;
	int T;
	scanf("%d", &T);
	while(T--)
	{
		LL n, l, r;
		cin>>n>>l>>r;
		LL num = r-l+1+n;
		LL den = n;
		LL ans = C(num%mod, den%mod, mod)*C(num/mod, den/mod, mod) - 1;
		if(ans < 0)
			ans += mod;
		cout<<ans%mod<<endl;
	}
	//general formula - (n+r-1Cr)
	//In this case - (r-l+nCn) = (r-l+nCr-l)
	//Final formula(after summation) - r-l+1+nCn
	return 0;
}
