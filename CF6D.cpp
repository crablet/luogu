// ��������������ƺ�����̫��
// ���Բ���DPҲ����
// ֱ����DFSҲ���ᳬʱ
// ��������Ƚϱ������������뵽
// ���忴����
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

int n, a, b;
std::array<int, 100> h{ 0 };
std::vector<int> Vec, Temp;

int Ans = INT_MAX;

int Read()
{
    int n = 0, k = 1;
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
        ch = getchar();

    if (ch == '-')
    {
        k = -1;
        ch = getchar();
    }

    while (ch <= '9' && ch >= '0')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }

    return n * k;
}

// DFS(Now, Sum)��ʾ��
// �ܴ��ǰNow - 1����������Ҫ���ٴ�Sum��
void DFS(int Now, int Sum)
{
    if (Sum >= Ans) // ��֦
    {
        return;
    }

    if (Now == n - 1)   // �����ˣ���Ϊ���һ���˲���ֱ�Ӵ�ֻ�ܱ���Ӵ�
    {
        if (h[n - 1] < 0)   // ������һ��Ҳ�������ˣ��ǾͿ��Ը��´�
        {
            Ans = Sum;
            Vec = Temp;
        }

        return;
    }

    // �����ȡ�϶��ܴ������һ���ķ�������DFS
    for (int i = 0;
        i <= std::max({ (h[Now - 1] / b), (h[Now] / a), (h[Now + 1] / b) }) + 1;
        ++i)
    {
        if (h[Now - 1] - b * i < 0) // ����ܴ������ߵ���һ������������DFS��Ҫ��
        {
            h[Now - 1] -= b * i;    // �Ǿ���һ���ͷŹ���
            h[Now] -= a * i;        // ע�⣬�����˶�������
            h[Now + 1] -= b * i;
            for (int t = 0; t < i; ++t)
            {
                Temp.push_back(Now + 1);
            }

            DFS(Now + 1, Sum + i);  // ��������һ��

            h[Now - 1] += b * i;    // ����
            h[Now] += a * i;
            h[Now + 1] += b * i;
            for (int t = 0; t < i; ++t)
            {
                Temp.pop_back();
            }
        }
    }

    return;
}

int main()
{
    n = Read();
    a = Read();
    b = Read();
    for (int i = 0; i < n; ++i)
    {
        h[i] = Read();
    }

    // ���Ǵ�0��ʼ��ţ�ע���һ�������һ���˲���ֱ�Ӵ�
    DFS(1, 0);

    std::cout << Ans << std::endl;
    for (const auto &r : Vec)
    {
        std::cout << r << ' ';
    }
    std::putchar('\n');

    return 0;
}