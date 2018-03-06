// 直接按照字典序从小到大的顺序递归一个一个地枚举
#include <iostream>
#include <string>
#include <array>

int k, cnt;
std::array<std::array<std::string, 6>, 2> p;
std::array<char, 9> Ans;

bool DFS(int Col)
{
    if (Col == 5)   // 因为是从0开始搜的，所以边界是4 + 1
    {
        if (++cnt == k) // 如果找到了k个了
        {
            for (int i = 0; i < Col; ++i)   // 那就把这第k个输出
            {
                std::putchar(Ans[i]);
            }
            std::putchar('\n');
            return true;
        }

        return false;
    }

    std::array<std::array<bool, 26>, 2> Existed{ false };
    for (int i = 0; i < 2; ++i) // 遍历两个图
    {
        for (int j = 0; j < 6; ++j) // 把这一列出现到的字母都标记起来
        {
            Existed[i][p[i][j][Col] - 'A'] = true;
        }
    }
    for (int i = 0; i < 26; ++i)    // 递归地枚举每一个字母
    {
        if (Existed[0][i] && Existed[1][i]) // 如果这个字母在两张图中的同一列都出现了
        {
            Ans[Col] = 'A' + i; // 标记一下
            if (DFS(Col + 1))   // 继续搜下一列
            {
                return true;
            }
        }
    }

    return false;   // 注意最后这个不能少
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> k;
        for (int i = 0; i < 2; ++i) // 把两个图读入
        {
            for (int j = 0; j < 6; ++j)
            {
                std::cin >> p[i][j];
            }
        }

        cnt = 0;    // 当前是第几个按字典序找到的密码
        if (!DFS(0))    // 如果找不到任何一种解决方案，再输出"NO"
        {
            std::puts("NO");
        }
    }

    return 0;
}