// 因为我们可以通过浪费掉一些"()"对来达到题目所说的要求，目前的目标就是如何去浪费
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    if (n == k) // 如果所需序列的长度和原序列相等，则直接输出，这里可以特判掉
    {
        std::cout << s << std::endl;
    }
    else
    {
        int Delta = n - k;  // 还需要浪费多少个"()"对

        std::string Ans;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')    // 遇到左括号直接用掉
            {
                Ans.push_back('(');
            }
            else    // 遇到右括号要分情况讨论
            {
                if (Delta != 0) // 还有要浪费的名额
                {
                    Ans.pop_back(); // 退掉一个括号
                    Delta -= 2;     // 因为浪费一次会少两个
                }
                else    // 没有要浪费的名额了，可以直接加入右括号了
                {
                    Ans.push_back(')');
                }
            }
        }
        std::cout << Ans << std::endl;
    }

    return 0;
}