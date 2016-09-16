#include <iostream>
#include <cmath>
using namespace std;

int get(int n)
{
    int count = 0;
    while( n>1 && n%2 == 0 )
    {
        n =n/2;
        count++;
    }

    return count;
}
int main()
{
    int n;
    cin >> n;

    if( n <= 3 )
    {
        if( n == 1 )
            cout << "1" << endl;
        else if( n == 2 )
            cout << "2" << endl;
        else
            cout << "3" << endl;
    }
    else
    {
        long long table[n+1];
        table[1] = 1;
        table[2] = 2;
        table[3] = 3;

        for( int i=4;i<=n; i++)
            table[i] = 0;

        int i = 4;
        while( i<=n )
        {
            table[i] += 1 + table[i-1];

            if( i%2 == 0 )
            {
                int numoftwo = get(i);

                bool isPowOfTwo = false;
                int j = 2;

                while( j<14 )
                {
                    int k = pow(2,j);
                    if( k == i )
                    {
                        isPowOfTwo = true;
                        break;
                    }
                    else if( k > i )
                        break;

                    j++;
                }

                if( isPowOfTwo )
                {
                    table[i] += numoftwo/2;
                }
                else
                {
                    table[i] += numoftwo;
                }
            }
            i++;
        }
        cout << table[n] << endl;
    }
    return 0;
}
