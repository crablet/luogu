// 看了各位大佬的题解，可能对于初学者来说还有点不太好懂
// 我想写一篇简明扼要的题解，希望能对大家理解此题有所帮助
// 首先这道题利用了二进制的特点
// 而一想到二进制，就会联想起位运算
// 然后移位操作又能很好地帮助我们取得一个二进制数中任意一位的1
// 这个1的位置即使2^n中的n
// 有了这个铺垫，这一题就很好做了
#include <iostream>

void Solve(int n)
{
    bool NotFirst = false;  // 因为第一次不需要输出+号，所以得特判一下
    for (int i = 15; i >= 0; --i)   // 这里是枚举2^i中的i
    {                               // 2^15为32768，足够表示20000以内的数了
        if (n & (1 << i))   // 检查n的二进制表示法中第i位是否为1，注意要从高到低位检查
        {
            if (NotFirst)
            {
                std::cout << '+';
            }
            NotFirst = true;    // 现在就不是第一次了

            if (i == 0) // 2^0的情况，依题意
            {
                std::cout << "2(0)";
            }
            else if (i == 1)    // 2^1的情况，依题意
            {
                std::cout << "2";
            }
            else   // 如果都不是，那就递归继续分解
            {
                std::cout << "2(";
                Solve(i);
                std::cout << ")";
            }
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    Solve(n);

    std::putchar('\n');

    return 0;
}