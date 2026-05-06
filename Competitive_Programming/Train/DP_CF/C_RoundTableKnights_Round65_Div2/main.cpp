#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
vector<int> divs;
bool found = false;
bool valid;

void getDivisors(){
    for(int i = 1; i * i <= n; ++i){
        if(n % i == 0){
            if(i <= n / 3){
                divs.push_back(i);
            }
            if(n / i != i){
                if(n / i <= n / 3){
                    divs.push_back(n / i);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    getDivisors();
    for(int k : divs){
        for(int i = 0; i < k; ++i){
            valid = true;
            for(int j = i; j < n; j += k){
                if(a[j] == 0){
                    valid = false;
                    break;
                }
            }
            if(valid){
                found = true;
                break;
            }
        }
        if(found){
            break;
        }
    }
    if(found){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}