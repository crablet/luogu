// 这一题只要构造一个合适的循环节即可，题中要求'c'的数量尽量小，我们可以尝试完全不使用'c'
// 在草稿纸上多试几遍就能找到属于你的循环节了，不唯一
// 我构造的循环节如下：abba abba abba ...
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int Length;
    std::cin >> Length;
    for (int i = 0; i < Length; ++i)
    {
        switch (i % 4)
        {
        case 0: case 3:
            std::cout << 'a';
            break;

        case 1: case 2:
            std::cout << 'b';
            break;

        default:
            break;
        }
    }
    std::cout << std::endl;

    return 0;
}