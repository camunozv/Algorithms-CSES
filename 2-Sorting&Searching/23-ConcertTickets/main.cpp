#include <bits/stdc++.h>

using namespace std;

void assign_tickets(vector<pair<int, int>> &c, vector<int> &t);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tickets = 0;
    int customers = 0;

    cin >> tickets;
    cin >> customers;

    vector<int> tickets_price(tickets);
    vector<pair<int, int>> customers_price(customers);

    for (int i = 0; i < tickets; i++)
        cin >> tickets_price[i];

    for (int i = 0; i < customers; i++) {
        cin >> customers_price[i].first;
        customers_price[i].second = 0;
    }

    sort(tickets_price.begin(), tickets_price.end());

    vector<pair<int, int>> vec;

    pair<int, int> k;
    k.first = 1;
    k.second = 5;

    pair<int, int> k2;
    k2.first = 2;
    k2.second = 6;

    pair<int, int> k3;
    k3.first = 3;
    k3.second = 7;

    pair<int, int> k4;
    k4.first = 4;
    k4.second = 8;

    vector<pair<int, int>> v1;

    v1.push_back(k);
    v1.push_back(k2);
    v1.push_back(k3);
    v1.push_back(k4);

    pair<int, int> toSearch;
    toSearch.first = 4;
    toSearch.second = 16;
    auto p = lower_bound(v1.begin(), v1.end(), toSearch);

    // This is how we print pairs from an iterator.
    cout << p->first << " " << p->second << "\n";

    return 0;
}

void assign_tickets(vector<pair<int, int>> &c, vector<int> &t) {


}











