#include <iostream>
#include <algorithm>
using namespace std;

bool sorter(int a,int b)
{
    return a > b;
}

int solve( int n,int s,int ar[])
{
    sort(ar,ar+n,sorter);

    int count = 0;
    int boxes = 0;
    while( count < s)
    {
        count += ar[boxes];
        boxes++;
    }
    return boxes;
}

int main()
{
    int n,k,s;

    cin >> n >> k >> s;

    int ar[n];
    for( int i=0; i<n; i++)
        cin >> ar[i];

    int sc = k*s;

    int ans = solve(n,sc,ar);

    cout << ans << endl;
}
