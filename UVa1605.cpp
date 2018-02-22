#include <iostream>

// 因为输入的国家个数小于等于50，所以用大小写字母可以表示完全所有的国家
char Country(int i)
{
    if (i < 26) // 当i小于26时，输出大写字母
    {
        return 'A' + i;
    }
    else   // 当i大于等于26时，输出小写字母
    {
        return 'a' + i - 26;
    }
}

int main()
{
    int n;
    while (std::cin >> n)
    {
        std::printf("2 %d %d\n", n, n); // 表示有两层楼，每层楼都是n * n
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::putchar(Country(i));   // 第一层第i行全是国家i
            }
            std::putchar('\n');
        }

        std::putchar('\n');

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::putchar(Country(j));   // 第二层第j列全是国家j
            }
            std::putchar('\n');
        }
    }

    return 0;
}
//
//这里给出一组输出（输入的n为3）：
//AAA
//BBB
//CCC
//
//ABC
//ABC
//ABC
//
//可以发现，对于第二层的每一列，它都能与第一层的同一列的所有国家相邻，
//这样就完成了对这个做法的正确性的简单直观证明。