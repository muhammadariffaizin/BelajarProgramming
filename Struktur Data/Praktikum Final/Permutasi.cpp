#include <bits/stdc++.h> 
using namespace std; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define mod 1000000007 
vector<long long int> check;

int main() 
{ 
    long long int ans=1;
    ordered_set o_set; 
    int n;
    cin >> n;
    int j=n-1;
    long long int fact[n+5];
    fact[0]=1;
    for (int wow=1;wow<=n;wow++)
    {
        fact[wow]=(fact[wow-1] * wow) % mod;
        //cout << fact[wow] << " ";
    }
    for (int i=0;i<n;i++)
      {
          long long int in;
          cin >> in;
          o_set.insert(in);
          check.push_back(in);
    }
    for (int i=0;i<n;i++)
    {
        long long int order = o_set.order_of_key(check[i]);
        ans += (order * fact[j]);
        ans = ans % mod;
        j--;
        o_set.erase(check[i]);
    }
    cout << ans << endl;
    return 0; 
} 
