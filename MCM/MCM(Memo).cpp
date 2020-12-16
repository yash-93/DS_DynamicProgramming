#include <bits/stdc++.h>
using namespace std;

int **memo;

int MCM(vector<int> arr, int i, int j){
    if(i>=j) return 0;

    if(memo[i][j] != -1)
        return memo[i][j];

    int min = INT_MAX;

    for(int k=i; k<j; k++){
        int tempMinMul = MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];

        if(tempMinMul < min) min = tempMinMul;
    }
    return memo[i][j] = min;
}

int main(){
    int n; cin >> n;
    memo = new int*[n];
    for(int i=0; i<n; i++){
        memo[i] = new int[n];
        memset(memo[i],-1,sizeof(int)*n);
    }

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << MCM(arr,1,n-1);

    return 0;
}
