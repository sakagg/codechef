#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

struct Floor
{
	long long tx;
	int cx;
};

bool compar(Floor a, Floor b)
{
	return a.cx < b.cx;
}

int main()
{
	long long n, m, tcost=0;
	int h;
	cin>>n>>m>>h;
	Floor all[100000];
	for(int i=0; i<h; i++)
		scanf("%lld%d", &(all[i].tx), &(all[i].cx));
	sort(all, all+h, compar);
	long long tot = n*m;
	for(int i=0; i<h; i++)
	{
//		cout<<all[i].tx<<" "<<all[i].cx<<endl;
		if(all[i].tx < tot)
		{
			tot-=all[i].tx;
			tcost+=all[i].tx*all[i].cx;
		}
		else
		{
			tcost+=tot*all[i].cx;
			tot=0;
			break;
		}
	}
	if(tot)
		cout<<"Impossible\n";
	else
		cout<<tcost<<endl;
	return 0;
}
