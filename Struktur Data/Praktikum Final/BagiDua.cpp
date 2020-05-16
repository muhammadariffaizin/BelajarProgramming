#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

int findMin(int arr[], int n, int sum) 
{ 
    // bool dp[n+1][sum+1]; 
    bool** dp = new bool*[n+1];
    for(int i=0; i<n+1; i++) 
        dp[i] = new bool[sum+1];
  
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
  
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=sum; j++) { 
            dp[i][j] = dp[i-1][j]; 
  
            if (arr[i-1] <= j) 
                dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]]; 
        } 
    } 
   
    int diff = INT_MAX; 
      
    for (int j=sum/2; j>=0; j--) { 
        if (dp[n][j] == true) { 
            diff = sum-2*j; 
            break; 
        } 
    } 
    return diff; 
} 

int main() {
    int T, B_i, sum = 0, i=0;
    cin >> T;
    int arr[T];
    while(T--) {
        cin >> B_i;
        arr[i++]=B_i;
        sum += B_i;
    }
    int diff = findMin(arr, i, sum);
    if(diff%2 == 0) {
        cout << sum/2 + diff/2 << " " << sum/2 - diff/2 << endl;
    } else {
        cout << (sum/2 + diff/2) + 1 << " " << sum/2 - diff/2 << endl;
    }

    return 0;
}