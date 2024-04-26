#include <bits/stdc++.h>

using namespace std;

int apartments_assign(stack<int> &m, stack<int> &n, int k);
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int m = 0;
    int k = 0;

    cin >> n;
    cin >> m;
    cin >> k;

    vector<int> applicants(n);
    for(int i = 0; i < n; i++){
        cin >> applicants[i];
    }

    vector<int> apartments(m);
    for(int i = 0; i < m; i++){
        cin >> apartments[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    stack<int> applicants_stack;
    stack<int> apartments_stack;

    for(auto a: applicants){
        applicants_stack.push(a);
    }

    for(auto b: apartments){
        apartments_stack.push(b);
    }

    int assigned_people = apartments_assign(apartments_stack, applicants_stack, k);
    cout << assigned_people << "\n";
    return 0;
}

int apartments_assign(stack<int> &m, stack<int> &n, int k){
    int assigned = 0;
    while(!m.empty() && !n.empty()){
        if (m.top() == n.top() || ((n.top() >= (m.top() - k)) && (n.top() <= (m.top() + k)))){
            m.pop();
            n.pop();
            assigned++;
        } else if (m.top() < (n.top() - k)) {
            n.pop();
        } else {
            m.pop();
        }
    }
    return assigned;
}