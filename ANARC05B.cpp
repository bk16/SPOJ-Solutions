#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long max(long long a,long long b)
{
    if( a> b )
        return a;
    return b;
}
long long solve( int ar1[], int n1, int ar2[], int n2)
{

    vector<long long> sum1(n1);
    vector<long long> sum2(n2);

    sum1[0] = ar1[0];
    sum2[0] = ar2[0];

    for( int i=1; i<n1; i++)
    {
        sum1[i] = sum1[i-1] + ar1[i];
        //cout << sum1[i] << " ";
    }
    //cout << endl;

    for( int i=1; i<n2; i++)
    {
        sum2[i] = sum2[i-1] + ar2[i];
        //cout << sum2[i] << " ";
    }
    //cout << endl;

    vector<int> v1;
    vector<int> v2;

    int i = 0;
    int j = 0;

    while( i<n1 && j<n2)
    {
        while( i<n1 && ar1[i] < ar2[j] )
            i++;

        while( j<n2 && ar2[j] < ar1[i] )
            j++;

        if( i<n1 && j<n2 && ar1[i] == ar2[j])
        {
            //cout << "i :" << i << "j : " << j << endl;
            v1.push_back(i);
            v2.push_back(j);

            i++;
            j++;
        }
    }

    if( v1.size() == 0 )
    {
        if( sum1[n1-1] > sum2[n2-1])
            return sum1[n1-1];
        return sum2[n2-1];
    }

    /*cout << "v1 " << endl;
    for( i=0; i<v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    cout << "v2 " << endl;
    for( i=0; i<v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;*/

    long long t1[v1.size() + 1];
    long long t2[v2.size() + 1];

    t1[0] = sum1[ v1[0]];
    t2[0] = sum2[ v2[0]];

    i=1;
    while( i<v1.size() )
    {
        t1[i] = max( t1[i-1], t2[i-1] ) + (sum1[v1[i]] - sum1[v1[i-1]]);
        t2[i] = max( t2[i-1], t1[i-1] ) + (sum2[v2[i]] - sum2[v2[i-1]]);
        i++;
    }

    //t1[ v1.size() ] = t1[ v1.size() - 1] + (sum1[n1-1] - sum1[v1[v1.size() - 1]]);
    //t2[ v2.size() ] = t2[ v2.size() - 1] + (sum2[n2-1] - sum2[v2[v2.size() - 1]]);

    t1[ v1.size() ] = max( t1[v1.size()-1], t2[v1.size()-1] ) + (sum1[n1-1] - sum1[v1[v1.size() - 1]]);
    t2[ v2.size() ] = max( t2[v1.size()-1], t1[v1.size()-1] ) + (sum2[n2-1] - sum2[v2[v2.size() - 1]]);

    /*cout << "t1 " << endl;
    for( i=0; i<v1.size()+1; i++)
        cout << t1[i] << " ";
    cout << endl;

    cout << "t2 " << endl;
    for( i=0; i<v2.size()+1; i++)
        cout << t2[i] << " ";
    cout << endl;*/

    return max( t1[ v1.size() ], t2[ v2.size() ]);
}

int main()
{
    //freopen("input.txt","r",stdin);
    while( true )
    {
        int n1;
        int n2;

        scanf("%d",&n1);

        if( n1 == 0 )
            break;
        int ar1[n1];

        for( int i=0; i<n1; i++)
            scanf("%d",&ar1[i]);

        scanf("%d",&n2);
        int ar2[n2];

        for( int i=0; i<n2; i++)
            scanf("%d",&ar2[i]);

        long long ans = solve( ar1,n1,ar2,n2);

        printf("%lld\n",ans);
    }

    return 0;
}
