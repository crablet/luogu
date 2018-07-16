// 这是一个贪心题
// 每次都尽量走(i + j == n + 1)的点对，实在不行就走(i + j == n + 2)的
// 那么就有一半的边能取0，一半的边能取1，然后总共(n - 1)条边，答案便是(n - 1) / 2
#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    std::cout << (n - 1) / 2 << std::endl;

    return 0;
}