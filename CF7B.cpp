// 这是一道模拟题，其中有一些小细节要注意
// 具体见代码和注释
#include <iostream>
#include <string>
#include <array>

int main()
{
    std::array<int, 100> Arr{ 0 };
    int t, m;
    std::cin >> t >> m;

    int id = 1; // 标记着最远的编号，从1开始
    std::string Command;
    while (t--)
    {
        std::cin >> Command;
        if (Command[0] == 'a')  // "alloc"
        {
            int p;
            std::cin >> p;

            int cnt = 0, idx = 0;
            bool OK = false;
            for (int i = 0; i < m; ++i)
            {
                if (!Arr[i])
                {
                    ++cnt;  // 去找有多少个连续的0
                }
                else
                {
                    cnt = 0;    // 中断了就清零重来
                    idx = i + 1;
                }

                if (cnt == p)   // 依题意，找到了第一个能存放p个单位的就立马跳出
                {
                    OK = true;
                    break;
                }
            }

            if (OK)
            {   // 从idx开始涂连续的p个
                for (int i = idx; i < idx + p; ++i)
                {
                    Arr[i] = id;
                }

                // 这里要加一了
                std::cout << id++ << std::endl;
            }
            else
            {
                std::puts("NULL");
            }
        }
        else if (Command[0] == 'e') // "erase"
        {
            int p;
            std::cin >> p;

            if (p > id || p <= 0)   // 删除最大标号以外的或者删除1以下的均为非法
            {
                std::puts("ILLEGAL_ERASE_ARGUMENT");
            }
            else
            {
                int f = false;
                int i;
                for (i = 0; i < m; ++i)
                {
                    if (Arr[i] == p)    // 去找要被删去的第一个数的下标
                    {
                        break;
                    }
                }

                while (Arr[i] == p)
                {
                    Arr[i] = 0; // 清零即是删除
                    ++i;
                    f = true;   // 标记删除操作被执行了
                }

                if (!f) // 如果这一次删除没有做任何操作，那么这个删除也是无效的
                {
                    std::puts("ILLEGAL_ERASE_ARGUMENT");
                }
            }
        }
        else   // "defragment"
        {
            int idx = 0;
            for (int i = 0; i < m; ++i)
            {
                if (Arr[i]) // 如果非零，则存放在前面
                {
                    Arr[idx++] = Arr[i];
                }
            }
            for (int i = idx; i < m; ++i)   // 后面那部分都是零
            {
                Arr[i] = 0;
            }
        }
    }

    return 0;
}