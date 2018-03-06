// ֱ�Ӱ����ֵ����С�����˳��ݹ�һ��һ����ö��
#include <iostream>
#include <string>
#include <array>

int k, cnt;
std::array<std::array<std::string, 6>, 2> p;
std::array<char, 9> Ans;

bool DFS(int Col)
{
    if (Col == 5)   // ��Ϊ�Ǵ�0��ʼ�ѵģ����Ա߽���4 + 1
    {
        if (++cnt == k) // ����ҵ���k����
        {
            for (int i = 0; i < Col; ++i)   // �ǾͰ����k�����
            {
                std::putchar(Ans[i]);
            }
            std::putchar('\n');
            return true;
        }

        return false;
    }

    std::array<std::array<bool, 26>, 2> Existed{ false };
    for (int i = 0; i < 2; ++i) // ��������ͼ
    {
        for (int j = 0; j < 6; ++j) // ����һ�г��ֵ�����ĸ���������
        {
            Existed[i][p[i][j][Col] - 'A'] = true;
        }
    }
    for (int i = 0; i < 26; ++i)    // �ݹ��ö��ÿһ����ĸ
    {
        if (Existed[0][i] && Existed[1][i]) // ��������ĸ������ͼ�е�ͬһ�ж�������
        {
            Ans[Col] = 'A' + i; // ���һ��
            if (DFS(Col + 1))   // ��������һ��
            {
                return true;
            }
        }
    }

    return false;   // ע��������������
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> k;
        for (int i = 0; i < 2; ++i) // ������ͼ����
        {
            for (int j = 0; j < 6; ++j)
            {
                std::cin >> p[i][j];
            }
        }

        cnt = 0;    // ��ǰ�ǵڼ������ֵ����ҵ�������
        if (!DFS(0))    // ����Ҳ����κ�һ�ֽ�������������"NO"
        {
            std::puts("NO");
        }
    }

    return 0;
}