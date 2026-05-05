// Source: Problems/solved/muanha.jpg
// Status: Solved
/* 
Note: Given an array of n positive intergers and a parameter k = 0 or k = 1.
Form a subset sum by choosing a combination of any elements.
Count the subset with the most amount of elements, sum must be prime.
if k = 1 you can remove on element from the original array, so you don't have to count it.
Solution: precompute all values of primes, then use bitset to perform a knapsack.

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 23/03/2026
*/
#include <bits/stdc++.h>
using namespace std;
int n, k, a[105];
bool prime[100005];

void sang(){
    prime[0] = prime[1] = true;

    for (int i = 2; i * i <= 100000; ++i){
        if (!prime[i]){
            for (int j = i * i; j <= 100000; j += i){
                prime[j] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("muanha.inp", "r", stdin); freopen("muanha.out", "w", stdout);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int sum = 0;
            for (int l = 0; l < i; ++l){

            }
        }
    }
}