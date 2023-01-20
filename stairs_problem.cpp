// let's solve the stairs problem

#include <bits/stdc++.h>
using namespace std;

int solve(int steps)
{
    // base case
    if (steps == 1)
    {
        return 1; // cuz there is one solution for the problem
    }
    if (steps == 2)
    {
        return 2; // there can be two ways of climbing the stairs
    }
    return solve(steps - 1) + solve(steps - 2);
}

int main()
{
    long long steps;
    cout << "enter the steps" << endl;
    cin >> steps;
    int ans = solve(steps);
    cout << ans << endl;
    return 0;
}
