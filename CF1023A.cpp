// �ַ���ģ����
// ���������е�"n > m + 1"���������Ϊ��һ���ַ������ȵڶ����ַ��������ǿ϶�����
// Ȼ�����е�û��'*'�������ֱ�������ַ���ƥ�伴��
// �����ҵ�'*'��λ�ã��Դ˷ָ��һ���ַ�������ǰ����ʹӺ���ǰȥƥ��ڶ����ַ���
// һ�������κ�ʧ�䣬�����"NO"���������"YES"
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    if (n > m + 1)  // ���г���
    {
        std::cout << "NO" << std::endl;

        return 0;
    }

    std::string Str1, Str2;
    std::cin >> Str1 >> Str2;

    auto Pos = Str1.find('*');
    if (Pos == std::string::npos)   // û��'*'�����
    {
        if (Str1 == Str2)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }
    else
    {
        auto p = static_cast<int>(Pos);
        for (int i = 0; i < p; ++i) // ��ǰ����ɨ
        {
            if (Str1[i] != Str2[i])
            {
                std::cout << "NO" << std::endl;

                return 0;
            }
        }
        for (int i = n - 1, j = m - 1; i > p; --i, --j) // �Ӻ���ǰɨ
        {
            if (Str1[i] != Str2[j])
            {
                std::cout << "NO" << std::endl;

                return 0;
            }
        }

        std::cout << "YES" << std::endl;
    }

    return 0;
}