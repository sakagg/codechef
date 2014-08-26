#include<iostream>
#include<cstdio>

using namespace std;

char *binary(int num, int size)
{
	if(num>>size)
		num = num-(1<<size);
	static char str[200010];
	str[size] = 0;
	for(int i=size-1; i>-1; i--)
	{
		str[i] = (num&1) + '0';
		num >>= 1;
	}
	return str;
}	
	
int main()
{
	int num1 = 0, num2 = 0;
	int n, save;
	cin>>n;
	getchar();
	save = n;
	char c;
	while((c=getchar())!='\n')
	{
//		cout<<c;
		if(c>='0' && c<='9')
		{
			n = (c-'0')>>2;
			num1 = (num1<<2) + n;
			num2 = (num2<<2) + (c-'0')-(n<<2);
		}
		else if(c>='A' && c<='F')
		{
			n=(c-55)>>2;
			num1 = (num1<<2) + n;
			num2 = (num2<<2) + (c-55)-(n<<2);
		}
//		cout<<num1<<" "<<num2<<"\t";
	}
	n = num1+num2;
	printf("%s\n", binary(n, 2*save));
}

