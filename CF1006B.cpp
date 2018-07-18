// 首先，我们能观察到这一题要求的最大获利就是数列前k大的数之和
// 通过排序，我们能找出前k大的数
// 然后，我们把这前k大的数的位置找出来，用它们来作为隔板分割数列
// 注意头尾的操作，开头记个0，尾部记个n
#include <iostream>
#include <vector>
#include <algorithm>

class Pair
{
public:
    int Key, Pos;   // 记在Pos位上的数为Key

    Pair() = default;
    Pair(int k, int p)
        : Key(k), Pos(p)
    {
    }

    bool operator<(const Pair &rhs) const noexcept
    {
        return Key > rhs.Key || (Key == rhs.Key && Pos < rhs.Pos);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<Pair> Vec(n);
    for (int i = 0; i < n; ++i)
    {
        int t;
        std::cin >> t;
        Vec[i] = Pair(t, i + 1);
    }
    std::sort(Vec.begin(), Vec.end());

    int Ans = 0;    // 前k大的数之和
    for (int i = 0; i < k; ++i)
    {
        Ans += Vec[i].Key;
    }
    std::cout << Ans << std::endl;

    std::vector<int> Arr(k);
    for (int i = 0; i < k; ++i)
    {
        Arr[i] = Vec[i].Pos;
    }
    std::sort(Arr.begin(), Arr.end());

    int Last = 0;   // 开头记个0
    for (int i = 0; i < k - 1; ++i)
    {
        std::cout << Arr[i] - Last << ' ';  // 中间的直接两两相减即可
        Last = Arr[i];
    }
    std::cout << n - Last << std::endl; // 尾部记个n

    return 0;
}