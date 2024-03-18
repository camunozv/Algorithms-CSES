#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // There are n applicants
    // There are m appartments
    // Task: assign an appartment to as much as applicants as possible
    // each applicant has a desired appartment size, and they accept one which has a size that is within a range "k"
    // an applicant only accepts an apartment if its size is within the range w-k, w+k

    int n = 0; // number of applicants
    cin >> n;

    int m = 0; // amount of apartments
    cin >> m;

    int k = 0; // maximum allowed distance
    cin >> k;

    vector<int> desired_size(n);
    for (int i = 0; i < n; i++)
    {
        cin >> desired_size[i];
        desired_size[i] -= k;
    }

    vector<int> apartment_size(m);
    for (int i = 0; i < m; i++)
    {
        cin >> apartment_size[i];
    }

    // sort(desired_size.begin(), desired_size.end()); // O(nlogn)
    sort(apartment_size.begin(), apartment_size.end()); // O(mlogm)
    
    int assigned = 0;


    for (int i = 0; i < desired_size.size(); i++)
    {
        auto apartemnt = lower_bound(desired_size.begin(), desired_size.end(), desired_size[i]);

        if (apartemnt == desired_size.end())
        {
            desired_size[i] += (2 * k);
            apartemnt = lower_bound(desired_size.begin(), desired_size.end(), desired_size[i]);

            if (apartemnt == desired_size.end())
            {
                continue;
            }
            else
            {
                assigned += 1;
            }
        } else 
        {
            assigned += 1;
        }
    }

    cout << assigned << "\n";

    // pending to program my own binary search
    return 0;
}