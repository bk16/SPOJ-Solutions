#include <iostream>
#include <cstdio>

using namespace std;

long long solve(string s)
{
    if( s.size() == 1 )
        return 1;

    int dp[s.size() + 1];
    for( int i=0; i<=s.size(); i++)
        dp[i] = 0;

    dp[0] = 1;
    dp[1] = 1;

    int i = 2;
    while( i<=s.size() )
    {

        char a = s[i-2];
        char b = s[i-1];

        if( b > '0' )
           dp[i] += dp[i-1];

        int num = (a-'0') * 10 + (b-'0');

        if( num <= 26 && a!='0' )
            dp[i] += dp[i-2];

        i++;

    }
    return dp[s.size()];
}


int main()
{
    while( true )
    {
        string s;
        cin >> s;

        if( s.size() == 1 && s[0] == '0')
            break;

        long long ans = solve(s);
        cout <<ans << endl;
    }
    return 0;
}
