#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0; // number of tickets
    int m = 0; // number of customers

    cin >> n;
    cin >> m;

    vector<int> ticket_price(n);
    for (int i = 0; i < n; i++)
        cin >> ticket_price[i];

    vector<int> customers_price(m);
    for (int i = 0; i < m; i++)
        cin >> customers_price[i];

    sort(ticket_price.begin(), ticket_price.end());

    vector<int> customers_with_ticket(m);

    int customer_price = 0;
    for (int i = 0; i < m; i++)
    {
        customer_price = customers_price[i];
        auto max_price_pointer = upper_bound(ticket_price.begin(), ticket_price.end(), customer_price);

        if (max_price_pointer != ticket_price.end())
        {
            max_price_pointer--;
            customers_with_ticket[i] = *(max_price_pointer);
        } else {
            customers_with_ticket[i] = -1;
        }
    }

    for (auto x: customers_with_ticket)
    {
        cout << x << "\n";
    }

    // This algorithm doesn't works bce i wasnt taking into account that the accurate price doesnt necessarily
    // has to be the closest one to the max price the customer is willing to pay. That is why upper_bound doesnt
    // function.
    
    return 0;
}