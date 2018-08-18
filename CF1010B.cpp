// ���������p���У��ٶ���
#include <iostream>
#include <array>

int Ask(int p)
{
    std::cout << p << std::endl;
    std::fflush(stdout);

    int t;
    std::cin >> t;
    return t;
}

int main()
{
    constexpr int MaxN = 30 + 5;
    std::array<bool, MaxN> p{ false };

    int m, n;
    std::cin >> m >> n;
    for (int i = 1; i <= n; ++i)    // ��ѯ��n��1����p�����������
    {                               // ��Ϊ1����̵ľ��룬���Բ�������-1���֣����������-1����֤������ǼٵĴ�
        std::cout << 1 << std::endl;
        std::fflush(stdout);

        int t;
        std::cin >> t;
        if (t == -1)    // ������-1����֤���ǼٵĴ�
        {
            p[i] = false;
        }
        else if (t == 1)    // ����1�Ŷ�
        {
            p[i] = true;
        }
        else // ǡ��1���Ǵ�
        {
            return 0;
        }
    }

    int l = 2, r = m, Now = 1;
    while (l <= r)
    {
        auto m = (l + r) / 2;
        auto Ans = Ask(m);
        if (p[(Now - 1) % n + 1] == false)  // �����λ���᷵�ؼٵĴ𰸣����Ǿ͸���ȡ����
        {
            Ans = -Ans;
        }
        if (Ans == 0)
        {
            return 0;
        }
        else if (Ans < 0)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }

        ++Now;
    }

    return 0;
}