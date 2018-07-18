// 这一题用双指针，设一头一尾的指针为l和r，然后这两根指针不停地往中间移动，遇到头尾之和分别相等时则记录一下
// 中间移动的过程中注意一下何时移动一根指针，何时两根指针同时移动就很容易AC了
#include <iostream>
#include <algorithm>
#include <array>

using ll = long long;

constexpr int MaxN = 200000 + 5;

std::array<int, MaxN> Arr{ 0 };

ll Ans = 0;

// 我们设DFS(l, r, sl, sr)为头指针指向Arr[l]，尾指针指向Arr[r]，此时头之和为sl，尾之和为sr
void DFS(int l, int r, ll sl, ll sr)
{
    if (sl == sr)   // 遇到头尾之和相等的情况
    {
        Ans = sl;   // 则记录一下目前的最大值（由于数列中所有数都是正数，可以保证每次遇到相等的情况都是目前为止的最优解）

        if (l < r)  // 两根指针还没有相遇，则它们还能同时向中间进一步
        {
            DFS(l + 1, r - 1, sl + Arr[l], sr + Arr[r]);
        }
    }
    else if (l > r) // 递归终点
    {
        return;
    }
    else if (sl < sr)   // 头之和比较小，所以移动头指针
    {
        DFS(l + 1, r, sl + Arr[l], sr);
    }
    else if (sl > sr)   // 尾之和比较小，所以移动尾指针
    {
        DFS(l, r - 1, sl, sr + Arr[r]);
    }
    else    // 不知道还有什么奇奇怪怪的情况反正剪掉就是了
    {
        return;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> Arr[i];
    }

    DFS(0, n - 1, 0, 0);    // 一头一尾开始搜，初始时头之和和尾之和都为0

    std::cout << Ans << std::endl;

    return 0;
}