// ��������õ�̰�ģ������¥�ϼ�λdalao˵��һ������Ϊ'1'�������⶯������'1'��һ�����Ա��ŵ�����ط����ַ�
// �������ȶԸ��ַ�������һ�飬��һ����Ҫͳ���ַ�'1'�ĸ����Լ����ַ������Ƿ����'2'
// Ȼ��������ѭ���µ�̰�Ĳ��ԣ�
// �Ը��ַ������б���������'0'�����'0'������'1'��������ֱ��������һ��'2'�����Ǿͽ����е�'1'�����Ȼ�������һ��'2'
// �ٽ��ţ���ǰ�Ѿ������е�'1'������ˣ�������'0'�����'0'������'1'������������'2'�����'2'
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string Str;
    std::cin >> Str;

    int One = 0, Zero = 0;
    bool HasTwo = false;
    for (const auto &c : Str)
    {
        if (c == '0')   // ͳ��'0'�ĸ���
        {
            ++Zero;
        }
        else if (c == '1')   // ͳ��'1'�ĸ���
        {
            ++One;
        }
        else if (c == '2')  // ͳ���Ƿ���'2'
        {
            HasTwo = true;
        }
    }

    if (!HasTwo)    // ���û��'2'����ô����������е�'0'����������е�'1'��Ȼ��ֱ���˳�����
    {
        for (int i = 0; i < Zero; ++i)
        {
            std::cout << 0;
        }
        for (int i = 0; i < One; ++i)
        {
            std::cout << 1;
        }
        std::cout << std::endl;

        return 0;
    }

    bool Met = false;   // ����Ƿ��һ������'2'
    for (const auto &c : Str)
    {
        if (c == '0')   // ����'0'�����
        {
            std::cout << 0;
        }
        else if (c == '1')  // ����'1'������
        {
            continue;
        }
        else if (c == '2')
        {
            if (!Met)   // ��һ������'2'����������е�'1'�������һ��'2'
            {
                Met = true;

                for (int i = 0; i < One; ++i)
                {
                    std::cout << 1;
                }
                std::cout << 2;
            }
            else       // ���ǵ�һ������'2'����ֱ�����'2'
            {
                std::cout << 2;
            }
        }
    }
    std::cout << std::endl;

    return 0;
}