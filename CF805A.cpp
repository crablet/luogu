// 这一题其实特别水，我一开始就是被样例吓到了，其实再仔细读题会发现如果有多个答案，那就随意输出一个
// 我们都知道一个>=2的整数要么是奇数要么是偶数，所以2这个因子占的比例是最高的
// 但是有个例外，就是[质数，质数]的情况，而且区间长度为1，那么就直接输出端点即可，否则就输出2
#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << (a == b ? a : 2) << std::endl;

    return 0;
}