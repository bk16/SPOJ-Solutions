#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

int solve(int ar[],int n)
{
    vector<long long> lhs;
    vector<long long> rhs;

    for( int i=0; i<n; i++)
    {
        for( int j=0; j<n; j++)
        {
            for( int k=0; k<n; k++)
            {
                lhs.push_back(ar[i] * ar[j] + ar[k]);
            }
        }
    }

    for( int i=0; i<n; i++)
    {
        for( int j=0; j<n; j++)
        {
            //if( i == j )
              //  continue;

            for( int k=0; k<n; k++)
            {
                if(  ar[k] == 0)
                    continue;

                rhs.push_back((ar[i] + ar[j]) * ar[k]);
            }
        }
    }

    sort(lhs.begin(),lhs.end());
    sort(rhs.begin(),rhs.end());

    int i = 0;
    int j = 0;

    int count = 0;
    while( i<lhs.size() && j<rhs.size())
    {
        while( i<lhs.size() && lhs[i] < rhs[j] )
            i++;

        while( j<rhs.size() && rhs[j] < lhs[i] )
            j++;

        if( lhs[i] == rhs[j])
        {
            int t1 = 0;
            int t2 = 0;
            int v = lhs[i];
            while(  i<lhs.size() && lhs[i] == v )
            {
                i++;
                t1++;
            }

            while(  j<rhs.size() && rhs[j] == v )
            {
                j++;
                t2++;
            }

            count += t1*t2;
        }
    }

    return count;
}

int main()
{
    int n;
    scanf("%d",&n);

    int ar[n];
    for( int i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }

    int ans = solve( ar, n );

    cout << ans << endl;
    return 0;
}
