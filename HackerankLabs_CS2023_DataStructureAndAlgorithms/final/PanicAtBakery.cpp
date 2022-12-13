#include <bits/stdc++.h>

using namespace std;

int max_profit(vector<vector<int>> buns, int G)
{
    if (G <= 0 || buns.empty())
        return 0;
    int max_p = 0;
    while (!buns.empty())
    {
        vector<int> bun = buns.back();
        buns.pop_back();
        while (bun[0] > -1)
        {
            if (G - bun[0] * bun[1] >= 0)
                max_p = max(max_p, bun[0] * bun[2] + max_profit(buns, G - bun[0] * bun[1]));
            bun[0] = bun[0] - 1;
        }
    }
    return max_p;
}

int main()
{
    int G, n;

    cin >> G >> n;
    vector<vector<int>> buns; 
    for (int i = 0; i < n; i++)
    {
        int g, x, y, z;
        cin >> g >> x >> y >> z;
        buns.push_back({g / x, y, z});
    }

    cout << max_profit(buns, G) << endl;
    return 0;
}