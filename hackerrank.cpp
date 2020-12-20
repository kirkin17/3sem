#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        int sum[n];
        int val = 0;
        int a;
        for(int j = 0; j < n; j++)
        {
            cin >> a;
            val += a;
            sum[i] = val;
        }
        if(n == 1) cout << "YES\n";
        if(n == 2) cout << "NO\n";
        bool YES;
        for(int j = 1; j < n; j++)
        {
            if(sum[i - 1] == (sum[n - 1] - sum[i]))
            {
                cout << "YES\n";
                YES = false;
                break;
            }
        }
        if(YES) cout << "NO\n";
    }
}