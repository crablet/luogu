// ��һ��ʮ�ֱ���������ö��
#include <iostream>
#include <array>

constexpr int MaxN = 100 * 2 + 5;
constexpr int M = 10001;

int T;
std::array<int, MaxN> x{ 0 };

void Solve()
{
    for (int a = 0; a < M; ++a) // ö��a
    {
        for (int b = 0; b < M; ++b) // ö��b
        {
            bool OK = true;
            for (int i = 2; i <= T * 2; i += 2)
            {
                x[i] = (a * x[i - 1] + b) % M;
                // ������a��b��ʹ����������ƹ�ϵ���Ǿ�һֱ������ȥ
                // �����������������������
                if (i + 1 <= T * 2 && x[i + 1] != (a * x[i] + b) % M)
                {
                    OK = false;
                    break;
                }
            }

            if (OK) // ����ҵ�����һ��a��b�ˣ������⣬�Ǿ��˳�
            {
                return;
            }
        }
    }
}

int main()
{
    while (std::cin >> T)
    {
        for (int i = 1; i <= T * 2 - 1; i += 2) // �����������
        {
            std::cin >> x[i];
        }
        Solve();
        for (int i = 2; i <= T * 2; i += 2) // ���ż�����
        {
            std::cout << x[i] << std::endl;
        }
    }

    return 0;
}