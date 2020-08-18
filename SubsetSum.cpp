#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;

    //Taking input
    cout << "Enter size of the array : ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements : ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int sum;
    cout << "Enter sum : ";
    cin >> sum;


    vector<vector<bool>> dp(n, vector<bool>(sum+1,false));

    dp[0][0] = true;
    dp[0][a[0]] = true;

    for(int i=1; i<n; i++){
        dp[i][0] = true;
    }

    //uncomment for initial matrix
    /*for(int i=0; i<n; i++){
        for(int j=0; j<=sum; j++){
            cout << dp[i][j] << " ";
        }
        cout<<endl;
    }
    cout<< "\n";*/

    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++){
            if(j<a[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i]];
            }
        }
    }

    //uncomment for final matrix
    /*for(int i=0; i<n; i++){
        for(int j=0; j<=sum; j++){
            cout << dp[i][j] << " ";
        }
        cout<<endl;
    }
    cout<< "\n";*/

    cout << dp[n-1][sum];

    return 0;
}
