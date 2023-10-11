#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL *createVector(LL a, LL b, LL c);
LL *sumVectors(LL a[], LL b[]);
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    LL testCases;
    cin >> testCases;

    LL *vector1 = NULL;
    LL *vector2 = NULL;
    LL *result = NULL;
    
    while (testCases > 0)
    {
        pair<LL, LL> testCase;

        cin >> testCase.first;
        cin >> testCase.second;

        vector1 = createVector(1, 2, testCase.first);
        vector2 = createVector(-4, -2, (-2 * testCase.second));

        result = sumVectors(vector1, vector2);

        delete vector1;
        delete vector2;
        delete result;
        testCases--;
    }

    vector1 = NULL;
    vector2 = NULL;
    result = NULL;

    return 0;
}

LL *createVector(LL a, LL b, LL c)
{
    LL *vector = new LL[3];
    vector[0] = a;
    vector[1] = b;
    vector[2] = c;
    return vector;
}

LL *sumVectors(LL a[], LL b[])
{
    LL *result = new LL[3];
    result[0] = a[0] + b[0];
    result[1] = a[1] + b[1];
    result[2] = a[2] + b[2];
    return result;
}
