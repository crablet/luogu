// 这是一个模拟题
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int Sum = 0;    // 计算当前页数的和

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        Sum += a;   // 加上要写的页数
        std::cout << Sum / m << ' ';    // 计算当天要翻过的页数
        Sum %= m;   // 然后计算这一页已经用了多少
    }
    std::cout << std::endl;

    return 0;
}