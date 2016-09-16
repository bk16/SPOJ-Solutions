#include <iostream>
#include <cstdio>
using namespace std;

void solve( int i,string s,int &ans,int max)
{
    if( i>= s.size())
        return;

    int num = 0 ;

    for( int j=i; j<s.size(); j++)
    {
        num = num + (s[j] -'0');
    }

    if( num >= max )
    {
        ans++;
        //cout << "added : " << s.substr(i) << endl;
        //cout << "max : " << max << endl;
    }

    for( int j=i; j<s.size(); j++)
    {
        int t = 0;
        for( int k=i; k<=j; k++)
        {
            t = t + (s[k] -'0');
        }

        //cout << "t : " << t << endl;
        //cout << "i: " << i << endl;
        //cout << "max loop: " << max << endl;

        if( t< max )
            continue;
        solve(j+1,s,ans,t);
    }

}

int main()
{
    //freopen("input.txt","r",stdin);
    int counter = 1;
    while( true )
    {
        string s;
        cin >> s;
        int ans = 0;

        if( s.size() == 3 && s[0] == 'b' && s[1] == 'y' && s[2] == 'e' )
            break;
        solve(0,s,ans,s[0]- '0');

        cout << counter++ << ". " << (ans) << endl;
    }
    return 0;
}
