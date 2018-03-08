// 我们设船行驶的时间为T
// 当船往左划时，T1 = 0.5L * 0.5 / v
// 当船往右划时，T2 = (0.5L + L) * 0.5 / v
// 最后过河，T3 = L / v
// 所以总时间T = T1 + T2 + T3 = 2L / v
// 然后再加上需要步行的时间即可
#include <iostream>

int main()
{
    int n, D;
    int NO = 0;
    while (std::cin >> n >> D && D)
    {
        double Ans = 0;
        while (n--)
        {
            int p, L, v;
            std::cin >> p >> L >> v;
            D -= L; // 坐船就不需要步行
            Ans += 2.0 * L / v; // 船行驶时间的数学期望
        }

        std::printf("Case %d: %.3lf\n\n", ++NO, Ans + D);
    }

    return 0;
}