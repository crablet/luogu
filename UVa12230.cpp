// �����贬��ʻ��ʱ��ΪT
// ��������ʱ��T1 = 0.5L * 0.5 / v
// �������һ�ʱ��T2 = (0.5L + L) * 0.5 / v
// �����ӣ�T3 = L / v
// ������ʱ��T = T1 + T2 + T3 = 2L / v
// Ȼ���ټ�����Ҫ���е�ʱ�伴��
#include <iostream>

int main()
{
    int n, D;
    int NO = 0;
    while (std::cin >> n >> D && D)
    {
        double Ans = 0;
        while (n--)
        {
            int p, L, v;
            std::cin >> p >> L >> v;
            D -= L; // �����Ͳ���Ҫ����
            Ans += 2.0 * L / v; // ����ʻʱ�����ѧ����
        }

        std::printf("Case %d: %.3lf\n\n", ++NO, Ans + D);
    }

    return 0;
}