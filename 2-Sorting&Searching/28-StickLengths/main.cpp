#include <bits/stdc++.h>

typedef long long int llint;

using namespace std;

llint calculate_cost(llint common_length, vector<llint> &stick_arr);

llint find_max(vector<llint> &stick_arr);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<llint> stick_lengths(n);

    for (int i = 0; i < n; i++) {
        cin >> stick_lengths[i];
    }

    llint longest_stick = find_max(stick_lengths);
    llint initial_cost = calculate_cost(longest_stick, stick_lengths);
    llint new_cost = 0;

    do {
        new_cost = calculate_cost(longest_stick / 2, stick_lengths);
        if (new_cost < initial_cost) {
            initial_cost = new_cost;
            longest_stick /= 2;
        } else {
            longest_stick /= 4;
        }

    } while (longest_stick >= 1);

    cout << initial_cost << "\n";
    return 0;
}

llint calculate_cost(llint common_length, vector<llint> &stick_arr) {

    llint total_cost = 0;
    int n = stick_arr.size();
    for (int i = 0; i < n; i++) {
        total_cost += abs(stick_arr[i] - common_length);
    }

    return total_cost;
}

llint find_max(vector<llint> &stick_arr) {
    llint max_element = stick_arr[0];
    int n = stick_arr.size();
    for (int i = 1; i < n; i++) {
        if (stick_arr[i] > max_element) {
            max_element = stick_arr[i];
        }
    }
    return max_element;
}