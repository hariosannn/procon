#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
ll inf=1e17;

vector<int> Eratosthenes( const int N )
{
    vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    vector<int> P;
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}

int main()
{
    int N;
    cin >> N;
    cout << Eratosthenes( N ).size() << endl;
    for( const auto &x: Eratosthenes( N ) )
    {
        //cout << x << " ";
    }
    return 0;
}