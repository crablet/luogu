// ��һ��ĸ���ϸ�Ľ��ͻ��ǵÿ�����P243
// ������ֻ�Ǹ�������һ�ְ�����˼·��ʵ�ֲ��Ҹ����꾡��ע��
// ϣ���ܶԴ�������һ����һ���İ���
#include <iostream>
#include <array>
#include <string>

constexpr int MaxN = 100000 + 5;
std::array<int, MaxN> Sum{ 0 }, p{ 0 };

// �Ƚ�k-p2p1��k-p4p3��б�ʴ�С
// ���˳˷�����Ϊ��������ˣ���һ���μ���
int CompareAverage(int x1, int x2, int x3, int x4)
{
    return (Sum[x2] - Sum[x1 - 1]) * (x4 - x3 + 1)
        - (Sum[x4] - Sum[x3 - 1]) * (x2 - x1 + 1);
}

int main()
{
    int n, L, T;
    std::string s;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> L >> s;

        // ����s[i]��ǰ׺��
        Sum[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            Sum[i] = Sum[i - 1] + s[i - 1] - '0';
        }

        // p[i..j)����˵�����У�����һ����������
        int AnsL = 1, AnsR = L;
        int i = 0, j = 0;   // i�Ƕ�ͷ��j�Ƕ�β
        for (int t = L; t <= n; ++t)    // ��t��Ϊ�߶ε��Ҷ˵�
        {
            // ɾ�����е���͹�㣺
            // ȡ����β�����㣬�Ƚ����Ǻ�t - L��б�ʴ�С
            // ������͹�͵�����βԪ�أ�ά��������
            while (j - i > 1 && CompareAverage(p[j - 2], t - L, p[j - 1], t - L) >= 0)
            {
                --j;
            }
            p[j++] = t - L + 1; // ��ӣ�ͬʱ��β��һ

                                // i���߶���˵����p[]�е��±�
                                // ���p[i]-p[i + 1]-t��͹����p[i]����p[i + 1]��
                                // �Ǿ͵�����ͷ
            while (j - i > 1 && CompareAverage(p[i], t, p[i + 1], t) <= 0)
            {
                ++i;
            }

            // ���б�ʸ������б����ͬ�������С
            // �͸��´�
            int c = CompareAverage(p[i], t, AnsL, AnsR);
            if (c > 0 || c == 0 && t - p[i] < AnsR - AnsL)
            {
                AnsL = p[i];
                AnsR = t;
            }
        }

        std::cout << AnsL << ' ' << AnsR << std::endl;
    }

    return 0;
}