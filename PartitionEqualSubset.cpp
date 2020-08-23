#include <iostream>
using namespace std;

bool partitionEqualSubset(vector<int> a, int sum, int n){
    bool dp[n][sum+1];

    for(int i=0; i<n; i++)
        dp[i][0] = true;

    for(int i=1; i<=sum; i++)
        dp[0][i] = false;

    dp[0][a[0]] = true;

    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++){
            if(j<a[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i]];
        }
    }
    return dp[n-1][sum];
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum&1)
        cout << "No\n";
    else
         if(partitionEqualSubset(a,sum/2,n))
            cout << "Yes\n";
         else
            cout << "No\n";

    return 0;
}
