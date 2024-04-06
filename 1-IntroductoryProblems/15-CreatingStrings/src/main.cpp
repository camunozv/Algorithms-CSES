#include <bits/stdc++.h>

using namespace std;

// just 4 fun
int binary_search_1(int value, vector<int> data);
int binary_search_2(int value, vector<int> data);
int main()
{

    ios::sync_with_stdio(NULL);
    cin.tie(0);

    return 0;
}

int binary_search_1(int value, vector<int> data)
{
    sort(data.begin(), data.end());
    int inferior = 0;
    int superior = data.size() - 1;

    int index = (superior + inferior) / 2;

    bool found = data[index] == value;

    while (inferior <= superior && !found)
    {
        if (value > data[index])
        {
            inferior = index + 1;
        }
        else if (value < data[index])
        {
            superior = index - 1;
        }
        found = data[index] == value;
        index /= 2;
    }

    return value == data[index] ? value : -1;
}

int binary_search_2(int value, vector<int> data)
{
    sort(data.begin(), data.end());

    int jump = 0;
    int n = data.size();

    for (int possible_jump = n / 2; possible_jump >= 1; possible_jump /= 2)
    {
        // Jump is only incremented if data is still in range.
        while (jump + possible_jump < n && data[jump + possible_jump] <= value)
        {
            jump += possible_jump;
        }
    }

    return value == data[jump] ? value : -1;
}