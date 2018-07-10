// 数据范围太小了，两重循环都直接过，就是按顺序挨个判断一遍是否出现就行了
#include <iostream>
#include <array>

int main()
{
    std::array<int, 10 + 5> A{ 0 }, B{ 0 };

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> A[i];
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> B[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (A[i] == B[j])
            {
                std::cout << A[i] << ' ';
            }
        }
    }
    std::cout << std::endl;

    return 0;
}