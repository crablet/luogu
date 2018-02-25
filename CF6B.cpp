// 这道题就是一道标准的DFS题，各种套路都是很基础的
// 具体见代码
#include <iostream>
#include <string>
#include <vector>
#include <array>

std::vector<std::string> Map;   // 整张地图
std::array<bool, 26> Num{ 0 };  // 标记搜到过的桌子，这里类似桶排，就不用写判重了
std::array<int, 4> dx{ 0, 1, -1, 0 }, dy{ -1, 0, 0, 1 };
// 注意是四个方向而不是八个方向

int n, m;   // 宽和长
char p; // 总统桌的字母

void DFS(int x, int y)
{
    // 超出边界了就立即返回
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return;
    }
    else
    {
        if (Map[x][y] != '.')   // 如果有桌子
        {
            if (Map[x][y] == p) // 如果是总统桌
            {
                Map[x][y] = '.';    // 就标记一下已经搜过了

                for (int i = 0; i < 4; ++i) // 和总统桌连着的四个方向搜下去
                {
                    DFS(x + dx[i], y + dy[i]);
                }
            }
            else   // 如果是总统桌以外的桌子
            {
                Num[Map[x][y] - 'A'] = true;    // 就标记这个字母的桌子被搜到了
                Map[x][y] = '.';    // 标记一下已经被搜过了
            }
        }
    }
}

int main()
{
    std::cin >> n >> m >> p;
    std::string Str;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> Str;
        Map.push_back(Str);
    }

    int x, y;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (Map[i][j] == p) // 找总统桌的位置
            {
                x = i;
                y = j;
                goto Outside;   // 用goto跳出多重循环很方便的
            }
        }
    }

Outside:
    DFS(x, y);  // 从第一张总统桌的位置往下搜

    int Sum = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (Num[i])
        {
            ++Sum;  // 统计有多少张被搜到的桌子
        }
    }
    std::cout << Sum << std::endl;

    return 0;
}