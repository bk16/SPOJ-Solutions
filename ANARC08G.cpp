
#include<iostream>
#include <cstdio>
using namespace std;

int main()
{	
	int n;
	int count = 0;

	do
	{
		scanf("%d",&n);
		if( n == 0 )
			break;
		
		count++;
		int ar[n];

		for( int i=0; i<n; i++)
			ar[i] = 0;

		long long sum = 0;
		long long ans = 0;
		int val;

		for( int i=0; i<n; i++)
		{
			for( int j=0; j<n; j++)
			{
				scanf("%d",&val);
				sum += val;
				if( val == 0 )
					continue;

				ar[i] = ar[i] - val;
				ar[j] = ar[j] + val;
			}
		}

		for( int i=0; i<n; i++)
		{
			if( ar[i] > 0 )
				ans += ar[i];

		}

		cout << count << ". " << sum << " " << ans << endl;
	}
	while( true );
	return 0;
}			









