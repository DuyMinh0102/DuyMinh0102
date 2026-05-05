// Source: Problems/solved/bai2.jpg
// Status: Solved
/* Note: you have M candies and N people.
Distribute the candies so that every has at least one candy, the amount of candies a person have is distinct,
the difference between the one with most candy and the one with least is minimize
Solution: The minimum amount of candies to distribute is 1 + 2 + ... + N = N * (N + 1) / 2 (*), 
if M < N * (N + 1) / 2 then the answer is -1
If cannot written in (*) form, the remaining is distributed to the last person.
Time complexity: O(1).

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 06/04/2026
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("bai2.inp", "r", stdin); freopen("bai2.out", "w", stdout);

    cin >> n >> m;

    int incre = 0;
    ll st = 1, sum = n * (n + 1) / 2;
    if (sum > m) cout << -1;
    m -= sum;
    st += m / n;
    m -= (n * (m / n));

    if (m > 0) ++incre;

    cout << st << ' ' << n + st - 1 + incre;
}