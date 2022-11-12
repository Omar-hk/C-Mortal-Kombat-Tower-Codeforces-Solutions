#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int arr[110],brr[110];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
    int tt;
    cin>>tt;
    while(tt--)
    {
      int n;
      cin>>n;
      vector<int> a(n);
      for(int i = 0; i < n; i++)
      {
        cin>>a[i];
      }
      vector<int> frnd(n + 2);
      vector<int> us(n + 2);
      frnd[n] = us[n] = 0;  //to make all the list 0
      for(int i = n - 1; i >= 0; i--)
      {
      { // calculate frnd[i]
        frnd[i] = us[i + 1] + a[i];
        if(i + 2 <= n)
        {
          frnd[i] = min(frnd[i],us[i + 2] + a[i] + a[i + 1]);
        }
      }
      {
        // calculate us[i]
        us[i] = frnd[i + 1];
        if(i + 2  <= n) 
        {
          us[i] = min(us[i], frnd[i + 2]);
        }
      }
      }
      cout << frnd[0] << '\n';

    
    }
    
    return 0;
}
