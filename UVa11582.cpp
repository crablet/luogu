// һ�������⣺
// �ᷢ����������ȡģ֮����ѭ����
// ��������ͨ���ҵ��Ǹ�ѭ������������
// Ȼ����Ϥһ�¡���ȡģ����ģ�廹��ģ�����һЩ��������
// ����������ע��
#include <iostream>
#include <array>

using ULL = unsigned long long;

constexpr int MaxN = 1000 + 5;

std::array<std::array<ULL, MaxN * 6>, MaxN> f{ 0 };
std::array<ULL, MaxN> Period{ 0 };

int PowMod(ULL a, ULL b, int n) // ����ȡģ����ģ�壬���a^b % n��ֵ
{
    if (!b)
    {
        return 1;
    }

    int k = PowMod(a, b / 2, n);
    k = k * k % n;

    if (b % 2)
    {
        k = k * a % n;
    }

    return k;
}

ULL Solve(ULL a, ULL b, int n)
{
    if (a == 0 || n == 1)
    {
        return 0;
    }

    // ���ù�ʽ��a^b % p = ((a % p)^b) % p 
    // �����ʽ�����ö���ʽ����չ����֤
    auto p = PowMod(a % Period[n], b, Period[n]);

    return f[n][p];
}

int main()
{
    for (int n = 2; n <= 1000; ++n) // ���ȴ���ø���n�������֮������
    {
        f[n][0] = 0;
        f[n][1] = 1;
        for (int i = 2; ; ++i)
        {
            f[n][i] = (f[n][i - 1] + f[n][i - 2]) % n;  // ��쳲��������е�ģ����
            if (f[n][i - 1] == 0 && f[n][i] == 1)   // �������ѭ����
            {
                Period[n] = i - 1;  // Period[n]��ʾ������nʱ���ڼ������ѭ��
                break;
            }
        }
    }

    ULL a, b;
    int n, T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> a >> b >> n;
        std::cout << Solve(a, b, n) << std::endl;
    }

    return 0;
}