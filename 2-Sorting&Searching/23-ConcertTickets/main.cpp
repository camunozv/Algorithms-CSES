#include <bits/stdc++.h>

using namespace std;

void assign_tickets(vector<int> &C, vector<int> &T);
void count_appearances (vector<int> &A, vector<int> &B);
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int tickets = 0;
    int customers = 0;

    cin >> tickets;
    cin >> customers;

    vector<int> tickets_price(tickets);
    vector<int> customers_price(customers);

    for (int i = 0; i < tickets; i++)
        cin >> tickets_price[i];

    for (int i = 0; i < customers; i++) {
        cin >> customers_price[i];
    }

    sort(tickets_price.begin(), tickets_price.end());

    vector<int> frequency;
    count_appearances(tickets_price, frequency);


    return 0;
}

void assign_tickets(vector<int> &C, vector<int> &T, vector<int> &F) {

    int n = C.size();
    int element = 0;
    for (int i = 0; i < n; i++){
        element = C[i];
        auto ticket_found = upper_bound(T.begin(), T.end(), element);
        ticket_found--;


    }
}

void count_appearances (vector<int> &A, vector<int> &B) {
    int n = A.size();
    int element = A[0];
    int count = 1;
    for (int i = 0; i < n; i++){
        if (A[i] == element) {
            count++;
        }else {
            B.push_back(count);
            element = A[i];
            count = 1;
        }
    }
}
