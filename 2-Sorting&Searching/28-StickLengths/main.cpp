#include <bits/stdc++.h>

typedef long long int llint;

using namespace std;

llint calculate_cost(llint common_length, vector<llint> &stick_arr);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<llint> stick_lengths(n);

    for (int i = 0; i < n; i++) {
        cin >> stick_lengths[i];
    }

    sort(stick_lengths.begin(), stick_lengths.end());

    int mid = n / 2;

    llint minimum_cost = calculate_cost(stick_lengths[mid], stick_lengths);

    cout << minimum_cost << "\n";
    return 0;
}

llint calculate_cost(llint common_length, vector<llint> &stick_arr) {

    llint total_cost = 0;
    unsigned long int n = stick_arr.size();
    for (unsigned long int i = 0; i < n; i++) {
        total_cost += abs(stick_arr[i] - common_length);
    }

    return total_cost;
}

/*

// This code I found is for further learning.
 ll cost(ll arr[],ll n,ll x){
    ll ans=0;
    for(int i=0 ; i<n ; i++)
    ans += abs(arr[i]-x);
    return ans;
}

int main(){

    ll n,i,high=-1,low=0,mid,ans=mx6;
    cin>>n;

    ll arr[n];

    for(i=0 ; i<n ; i++){
        cin>>arr[i];
        high = max(high,arr[i]);
    }

    while(low<=high){
        mid = (high+low)/2;
        ll md = cost(arr,n,mid);
        ans = min(ans,md);
        if(cost(arr,n,mid+1)<md)
        low = mid+1;
        else
        high = mid-1;
    }
    cout<<ans;
    return 0;
}
*/