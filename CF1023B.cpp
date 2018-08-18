// 找规律题
// 通过观察我们可以确定有三种情况
// 1) k太大，导致取数列中最大的两个(n, n - 1)都无法满足
// 2) k比n小，此时决定取法的只有k，因为上界比k大，无法够得着
// 3) k比n大但不会太大，此时决定取法的是k和n，列方程解出下界即可
#include <iostream>

using ll = long long;

int main()
{
    ll n, k;
    std::cin >> n >> k;
    if (n * 2 <= k) // k太大
    {
        std::cout << 0 << std::endl;
    }
    else if (k <= n)    // k比n小
    {
        std::cout << (k - 1) / 2 << std::endl;
    }
    else    // k比n大但不会太大
    {
        std::cout << (n * 2 + 1 - k) / 2 << std::endl;
    }

    return 0;
}