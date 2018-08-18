// �������У���������ֱ��ģ�⼴��
#include <iostream>
#include <array>

int main()
{
    constexpr int MaxN = 100 + 10;
    std::array<bool, MaxN> s{ false };  // s[i]��ʾi������Ƿ񱻸���

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    while (n--)
    {
        int l, r;   // ��˵���Ҷ˵�
        std::cin >> l >> r;
        for (int i = l; i <= r; ++i)
        {
            s[i] = true;    // ֱ��ö������������ĵ�
        }
    }

    int Tol = 0;    // ��ʣ���ٸ���û������
    for (int i = 1; i <= m; ++i)
    {
        if (!s[i])
        {
            ++Tol;
        }
    }
    std::cout << Tol << std::endl;

    for (int i = 1; i <= m; ++i)
    {
        if (!s[i])
        {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}