#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>

constexpr int MaxN = 1000 + 5;

// 存放点的信息的结构体(x, y)和相对角度Rad
struct Point
{
    int x, y;
    double Rad;
};

std::array<Point, MaxN> op, p;
std::array<int, MaxN> Color{ 0 };
int n;

// 利用向量叉积来计算向量OA是否在向量OB的左边，从而确定点A是否在点B的左边
// 若OA * OB >= 0，则点A在点B左侧或者OA和OB共线
// 若OA * OB < 0，则点A在点B的右侧
// 这是利用了叉积表达式中有一个sinx，从而可以确定左右
// 详见：https://www.cnblogs.com/rhythmic/p/5727057.html
bool IsLeft(const Point &A, const Point &B)
{
    return A.x * B.y - A.y * B.x >= 0;
}

int Solve()
{
    if (n <= 2)
    {
        return 2;
    }

    // 这是一道计算几何题：
    // 以O-p[i]作为分割线，以O-p[j]作为扫描线
    // 将要被扫描的点按极角排序
    // 看看有多少个点在O-p[i]左边
    // 然后旋转分割线，继续扫描
    int Ans = 0;    // 符合条件的黑点和白点的和，最后作为答案返回
    for (int i = 0; i < n; ++i) // 枚举基准点op[i]
    {
        int k = 0;  // 扫描线的编号
        for (int j = 0; j < n; ++j) // 连接op[i]和op[j]，以此作为扫描线
        {
            if (i != j) //确保不要选到同一个点
            {
                p[k].x = op[j].x - op[i].x; // 相当于delta x
                p[k].y = op[j].y - op[i].y; // 相当于delta y

                                            // 如果是黑点，那就把它变为白点，并且将坐标旋转180度
                if (Color[j])   // 这是为了方便计数，因为在右边的点可以涂黑然后变成在左边的白点
                {               // 最后我们只要选取在左边的白点即可
                    p[k].x = -p[k].x;
                    p[k].y = -p[k].y;
                }

                // 这里要注意std::atan和std::atan2不一样，std::atan2会更精确，因为考虑了更多的象限
                p[k].Rad = std::atan2(p[k].y, p[k].x);  // 算出倾斜角，初中的公式了

                ++k;    // 扫描线编号加一
            }
        }

        // 将点按极角排序，从小到大排
        std::sort(p.begin(), p.begin() + k, [](const Point &A, const Point &B)
        {
            return A.Rad < B.Rad;
        });

        int L = 0, R = 0, cnt = 2;
        while (L < k)   // 枚举每一个点
        {
            if (R == L) // 空区域，暂时先多算一个点，最后舍去
            {
                R = (R + 1) % k;
                ++cnt;
            }

            // 如果点L在点R的左边，那就加一，然后扫描线旋转
            // 注意这里的R的范围是[0, k)
            while (R != L && IsLeft(p[L], p[R]))
            {
                R = (R + 1) % k;
                ++cnt;
            }

            --cnt;  // 舍去多计入的一个点
            ++L;    // 旋转分割线

            Ans = std::max(Ans, cnt);   // 更新答案
        }
    }

    return Ans;
}

int main()
{
    while (std::cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cin >> op[i].x >> op[i].y >> Color[i];
        }

        std::cout << Solve() << std::endl;
    }

    return 0;
}