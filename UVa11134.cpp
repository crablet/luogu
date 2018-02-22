#include <iostream>
#include <array>
#include <algorithm>

constexpr int MaxN = 5000 + 5;
int n;

// 找到一个数组c[]，使得a[i] <= c[i] <= b[i] (0 <= i < n)
// 我懒得写出参数类型了所以弄了个template来偷懒
template <typename T>
bool Solve(const T &a, const T &b, T &c, int n) // 因为要修改c[]，所以这里是引用类型
{
    std::fill(c.begin(), c.begin() + n, -1);    // 将c[]初始化为全-1
    for (int Col = 1; Col <= n; ++Col)  // 遍历棋盘的第[1, n]列
    {
        // Rook是车的编号，MinB是能选的区间中最右边的点的最小值
        int Rook = -1, MinB = n + 1;
        for (int i = 0; i < n; ++i)
        {
            // 遍历每辆车的每个小区间：
            // 如果c[i]还没被安排点，因为任何两辆车不能在同一行或者同一列
            // 并且b[i]能在最右边的点的最小值的左边
            // 并且Col在左边的点的右边
            // 那就可以安排这第i辆车
            if (c[i] < 0 && b[i] < MinB && Col >= a[i])
            {
                Rook = i;       // 能安排第i辆车了
                MinB = b[i];    // 更新区间的最右边的点的最小值
            }
        }

        // 如果这一轮下来，Rook还是-1，即没被安排到车
        // 或者最左边的点跑得比最右边的点还要右
        // 那就说明并没有解
        if (Rook < 0 || Col > MinB)
        {
            return false;
        }

        // 给编号为Rook的车安排位置，安排在第Col列（行）
        c[Rook] = Col;
    }

    // 成功地安排好了位置
    return true;
}

int main()
{
    std::array<int, MaxN> x1{ 0 }, y1{ 0 }, x2{ 0 }, y2{ 0 }, x{ 0 }, y{ 0 };

    while (std::cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        }

        // 这是一个贪心题：
        // 注意和n皇后不同，因为没有对角线的限制
        // 所以可以将一个二维的问题分解成了两个一维的问题
        // 然后贪心地选取对后面的车影响最小的坐标
        if (Solve(x1, x2, x, n) && Solve(y1, y2, y, n))
        {
            for (int i = 0; i < n; ++i)
            {
                std::cout << x[i] << ' ' << y[i] << std::endl;
            }
        }
        else
        {
            std::puts("IMPOSSIBLE");
        }
    }

    return 0;
}