// ö��ÿ������������
// Ȼ���ÿ�����Լ������ĸ��ʼ�������
// �����ܵĿ��ܵĸ�������������
#include <iostream>
#include <array>
#include <bitset>
#include <algorithm>

constexpr int MaxN = 20 + 5;
int n, r;   // һ����n���ˣ�r�����˶���
std::bitset<MaxN> Buy;  // ��ǵ�i����������
std::array<double, MaxN> P{ 0 }, Sum{ 0 };
// P[i]��ʾ��i���������ĸ��ʣ�Sum[i]��ʾ��i���������ĸ���֮��

// d���������
// c��������ȥ���˲�Ʒ
// prob������
void DFS(int d, int c, double prob)
{
    // ����Ѿ�����r������������û�������˲�̫���˶��ϲ�����
    if (c > r || d - c > n - r)
    {
        return;
    }

    if (d == n) // ������n���ˣ���0��ʼ�ѵģ�
    {
        Sum[n] += prob; // Sum[n]��ʾSum[i(0 .. n - 1)]֮��
        for (int i = 0; i < n; ++i)
        {
            if (Buy[i]) // �����i���������ˣ��Ǿͼ�¼��������ʣ�Ȼ��Ӻ�
            {
                Sum[i] += prob;
            }
        }

        return;
    }

    Buy[d] = false;
    DFS(d + 1, c, prob * (1 - P[d]));   // ��d���˲���
    Buy[d] = true;
    DFS(d + 1, c + 1, prob * P[d]);     // ��d������
}

int main()
{
    int NO = 0;
    while (std::cin >> n >> r && n)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cin >> P[i];
        }
        std::fill(Sum.begin(), Sum.end(), 0);

        DFS(0, 0, 1.0);

        std::cout << "Case " << ++NO << ":" << std::endl;
        for (int i = 0; i < n; ++i)
        {
            std::printf("%.6lf\n", Sum[i] / Sum[n]);
        }
    }

    return 0;
}