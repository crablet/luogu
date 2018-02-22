#include <iostream>
#include <sstream>
#include <utility>
#include <array>
#include <algorithm>

// 该数组的容量
constexpr int MaxN = 30 + 5;

int n;  // 整个序列的长度
std::array<int, MaxN> a{ 0 };   // 序列的数组

// 翻转a[0...p]
void Flip(int p)
{
    for (int i = 0; i < p - i; ++i)
    {
        std::swap(a[i], a[p - i]);
    }

    std::cout << n - p << ' ';  // 按题意输出翻转的位置
}

int main()
{
    std::string s;
    while (std::getline(std::cin, s))
    {
        std::cout << s << std::endl;    // 因为不知道有多少个数，所以只能整行全部读入
                                        // 要注意输入时的数据是从上到下给出的，类似一个栈，这里很坑
        std::stringstream ss(s);
        n = 0;
        while (ss >> a[n])
        {
            ++n;
        }

        // 由于是按照从大到小的顺序处理，当处理第i大的煎饼时，
        // 是不会影响第1, 2, 3, ..., i - 1大的煎饼的，
        // 因为它们已经正确地被翻到了煎饼堆底部的i - 1个位置上了。
        for (int i = n - 1; i > 0; --i)
        {
            // 元素a[0..i]的最大元素的下标，这里第二个参数要加一是因为C++使用的是左闭合区间
            auto p = std::max_element(a.cbegin(), a.cbegin() + i + 1) - a.cbegin();
            if (p == i)
            {
                continue;   //表示该元素已经是最大的了
            }

            if (p > 0)  // 不需要执行Flip(0)， 因为Flip(0)相当于单独翻转a[0]，没有意义
            {
                Flip(p);    // 先把最大的元素翻到a[0]处
            }
            Flip(i);    // 处理完最大的，这下再翻转的时候，a[]的后面就已经有序了
                        // 这两步有点难理解，建议跟着调试一步一步看
        }

        std::cout << 0 << std::endl;    // 按题意，最后还要输出一个0
    }

    return 0;
}