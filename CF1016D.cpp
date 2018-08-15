// һ�������⣬������ʱ��û��Ū������ȥ����ô�ⷽ����ȥ�ˣ���ʱ��Ӧ������ʵʵ���Զ��빹������
// ���ȣ������������ʣ����������ÿ��Ԫ�ض���������ߣ���ô�������Ϳ϶�Ϊ0
// Ȼ�����ǾͿ��Կ��Զ������ˣ�
// ���ȣ��������һ�к����һ�е�Ԫ�ض���Ϊ0
// ���ţ��������½������һ��Ԫ�أ����໹û����ֵ�ĵط���Ԫ�ض���Ϊ��һ�У��У�������
// ���½ǵ��Ǹ�Ԫ��Ҳ����ͨ�����������Ƴ���
#include <iostream>
#include <array>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    constexpr int MaxN = 100 + 5;
    std::array<int, MaxN> a{ 0 }, b{ 0 };

    int n, m, Ans = 0;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        Ans ^= a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
        Ans ^= b[i];
    }

    if (Ans != 0)   // ����һ������Ԫ���������֮��Ľ���ǲ���0��������֤���޽�
    {
        std::cout << "NO" << std::endl;
    }
    else
    {
        std::cout << "YES" << std::endl;

        Ans = b[m - 1]; // �ȴ�һ�����һ�е����ͣ�Ϊ���Ƴ����½ǵ��Ǹ�Ԫ��

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < m - 1; ++j)
            {
                std::cout << 0 << ' ';  // �������һ�к����һ�У�����ط�����0
            }
            std::cout << a[i] << std::endl; // ���һ�е�Ԫ��

            Ans ^= a[i];    // �������һ�е������Ƴ����½��Ǹ�Ԫ��
        }

        for (int i = 0; i < m - 1; ++i)
        {
            std::cout << b[i] << ' ';   // ���һ�е�Ԫ��
        }
        std::cout << Ans << std::endl;  // ���½ǵ�Ԫ��
    }

    return 0;
}