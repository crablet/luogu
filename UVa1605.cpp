#include <iostream>

// ��Ϊ����Ĺ��Ҹ���С�ڵ���50�������ô�Сд��ĸ���Ա�ʾ��ȫ���еĹ���
char Country(int i)
{
    if (i < 26) // ��iС��26ʱ�������д��ĸ
    {
        return 'A' + i;
    }
    else   // ��i���ڵ���26ʱ�����Сд��ĸ
    {
        return 'a' + i - 26;
    }
}

int main()
{
    int n;
    while (std::cin >> n)
    {
        std::printf("2 %d %d\n", n, n); // ��ʾ������¥��ÿ��¥����n * n
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::putchar(Country(i));   // ��һ���i��ȫ�ǹ���i
            }
            std::putchar('\n');
        }

        std::putchar('\n');

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::putchar(Country(j));   // �ڶ����j��ȫ�ǹ���j
            }
            std::putchar('\n');
        }
    }

    return 0;
}
//
//�������һ������������nΪ3����
//AAA
//BBB
//CCC
//
//ABC
//ABC
//ABC
//
//���Է��֣����ڵڶ����ÿһ�У����������һ���ͬһ�е����й������ڣ�
//����������˶������������ȷ�Եļ�ֱ��֤����