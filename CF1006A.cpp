// 直接找规律：发现每次先处理奇数再处理偶数，所以奇数由奇->偶->奇，偶数由偶->奇
// 因此奇数不变，偶数减一既是答案
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--)
    {
        int n;
        std::cin >> n;
        std::cout << (n & 1 ? n : n - 1) << ' ';
    }
    std::cout << std::endl;

    return 0;
}