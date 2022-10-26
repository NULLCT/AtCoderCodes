#include <bits/stdc++.h>
using namespace std;

int H, W, A[50][50], ans, S[51][51];

int calc_sum(int x1, int y1, int x2, int y2)
{
    return S[x2 + 1][y2 + 1] + S[x1][y1] - S[x1][y2 + 1] - S[x2 + 1][y1];
}

int main()
{
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            S[i + 1][j + 1] = S[i][j + 1] + A[i][j];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            S[i + 1][j + 1] += S[i + 1][j];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int s = calc_sum(0, 0, i, j);
            vector<int> h, w;
            h.push_back(-1);
            w.push_back(-1);
            for (int k = 0; k < H; k++)
            {
                if (calc_sum(h.back() + 1, 0, k, j) == s)
                    h.push_back(k);
            }
            for (int k = 0; k < W; k++)
            {
                if (calc_sum(0, w.back() + 1, i, k) == s)
                    w.push_back(k);
            }
            if (h.back() != H - 1 || w.back() != W - 1)
                continue;
            bool f = true;
            for (int k = 0; k < h.size() - 1; k++)
            {
                for (int l = 0; l < w.size() - 1; l++)
                {
                    if (calc_sum(h[k] + 1, w[l] + 1, h[k + 1], w[l + 1]) != s)
                    {
                        f = false;
                    }
                }
            }
            if (f)
                ans++;
        }
    }
    cout << ans - 1 << endl;
}
