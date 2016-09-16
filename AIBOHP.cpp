#include <iostream>
using namespace std;


int dp[6100][6100];

int min( int a,int b)
{
    if( a < b )
        return a;
    else
        return b;
}
int minimumInsertions( string A )
{

    int n = A.size();

    for( int gap = 0; gap<n; gap++)
    {
        for( int i=0,j=gap; j<n; j++,i++)
        {
            if( A[i] == A[j] )
            {
                dp[i][j] = ( i+1 <= j-1 ) ? dp[i+1][j-1] : 0;
            }
            else
            {
                int x = ( i+1 <= j ) ? dp[i+1][j] : 0 ;
                int y = ( i <= j-1 ) ? dp[i][j-1] : 0;
                dp[i][j] = min( 1 + x,1+ y );
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
    int t;
    cin >> t;

    while( t-- )
    {
        string A;
        cin >> A;
        int ans = minimumInsertions( A );

        cout  << ans << endl;
    }
    return 0;
}
