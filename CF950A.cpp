// 这一题真的是入门难度无疑了
// 只要判断输入的数的奇偶性就好了
// 若是奇数，则后手赢；若是偶数，则先手赢
#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    if (n % 2 == 1)
    {
        std::puts("Ehab");
    }
    else
    {
        std::puts("Mahmoud");
    }

    return 0;
}