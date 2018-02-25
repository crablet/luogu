// ��������һ����׼��DFS�⣬������·���Ǻܻ�����
// ���������
#include <iostream>
#include <string>
#include <vector>
#include <array>

std::vector<std::string> Map;   // ���ŵ�ͼ
std::array<bool, 26> Num{ 0 };  // ����ѵ��������ӣ���������Ͱ�ţ��Ͳ���д������
std::array<int, 4> dx{ 0, 1, -1, 0 }, dy{ -1, 0, 0, 1 };
// ע�����ĸ���������ǰ˸�����

int n, m;   // ��ͳ�
char p; // ��ͳ������ĸ

void DFS(int x, int y)
{
    // �����߽��˾���������
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return;
    }
    else
    {
        if (Map[x][y] != '.')   // ���������
        {
            if (Map[x][y] == p) // �������ͳ��
            {
                Map[x][y] = '.';    // �ͱ��һ���Ѿ��ѹ���

                for (int i = 0; i < 4; ++i) // ����ͳ�����ŵ��ĸ���������ȥ
                {
                    DFS(x + dx[i], y + dy[i]);
                }
            }
            else   // �������ͳ�����������
            {
                Num[Map[x][y] - 'A'] = true;    // �ͱ�������ĸ�����ӱ��ѵ���
                Map[x][y] = '.';    // ���һ���Ѿ����ѹ���
            }
        }
    }
}

int main()
{
    std::cin >> n >> m >> p;
    std::string Str;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> Str;
        Map.push_back(Str);
    }

    int x, y;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (Map[i][j] == p) // ����ͳ����λ��
            {
                x = i;
                y = j;
                goto Outside;   // ��goto��������ѭ���ܷ����
            }
        }
    }

Outside:
    DFS(x, y);  // �ӵ�һ����ͳ����λ��������

    int Sum = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (Num[i])
        {
            ++Sum;  // ͳ���ж����ű��ѵ�������
        }
    }
    std::cout << Sum << std::endl;

    return 0;
}