// Source: Problems/solved/bonus.jpg
// Status: Solved
/* Note: Whenever the amount of sold tickets is not divisble by any number in the range [2; 10],
each employee will receive a bonus of 1000 VND.
Calculate the amount of bonus each employee recive for N tickets sold.
Solution: Not divisible by any number in the range [2; 10] <=> Not divisible by any prime number in the range [2; 10] <=> Not divisible by 2, 3, 5, 7.
Use Inclusion-Exclusion Principle to calculate the amount of numbers in the range [1; N] that are not divisible by 2, 3, 5, 7.
Time complexity O(1).

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 06/04/2026
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("bonus.inp", "r", stdin); freopen("bonus.out", "w", stdout);

    cin >> n;

    vector<ll> p = {2, 3, 5, 7};

    ll t = n + (n / (2 * 3 * 5 * 7));

    for (int i = 0; i < 4; ++i){
        t -= (n / p[i]);
        for (int j = i + 1; j < 4; ++j){
            t += (n / (p[i] * p[j]));
            for (int k = j + 1; k < 4; ++k){
                t -= (n / (p[i]*p[j]*p[k]));
            }
        }   
    }

    cout << t;
}