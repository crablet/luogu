#include <iostream>
#include <array>
#include <algorithm>

constexpr int MaxN = 5000 + 5;
int n;

// �ҵ�һ������c[]��ʹ��a[i] <= c[i] <= b[i] (0 <= i < n)
// ������д����������������Ū�˸�template��͵��
template <typename T>
bool Solve(const T &a, const T &b, T &c, int n) // ��ΪҪ�޸�c[]��������������������
{
    std::fill(c.begin(), c.begin() + n, -1);    // ��c[]��ʼ��Ϊȫ-1
    for (int Col = 1; Col <= n; ++Col)  // �������̵ĵ�[1, n]��
    {
        // Rook�ǳ��ı�ţ�MinB����ѡ�����������ұߵĵ����Сֵ
        int Rook = -1, MinB = n + 1;
        for (int i = 0; i < n; ++i)
        {
            // ����ÿ������ÿ��С���䣺
            // ���c[i]��û�����ŵ㣬��Ϊ�κ�������������ͬһ�л���ͬһ��
            // ����b[i]�������ұߵĵ����Сֵ�����
            // ����Col����ߵĵ���ұ�
            // �ǾͿ��԰������i����
            if (c[i] < 0 && b[i] < MinB && Col >= a[i])
            {
                Rook = i;       // �ܰ��ŵ�i������
                MinB = b[i];    // ������������ұߵĵ����Сֵ
            }
        }

        // �����һ��������Rook����-1����û�����ŵ���
        // ��������ߵĵ��ܵñ����ұߵĵ㻹Ҫ��
        // �Ǿ�˵����û�н�
        if (Rook < 0 || Col > MinB)
        {
            return false;
        }

        // �����ΪRook�ĳ�����λ�ã������ڵ�Col�У��У�
        c[Rook] = Col;
    }

    // �ɹ��ذ��ź���λ��
    return true;
}

int main()
{
    std::array<int, MaxN> x1{ 0 }, y1{ 0 }, x2{ 0 }, y2{ 0 }, x{ 0 }, y{ 0 };

    while (std::cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        }

        // ����һ��̰���⣺
        // ע���n�ʺ�ͬ����Ϊû�жԽ��ߵ�����
        // ���Կ��Խ�һ����ά������ֽ��������һά������
        // Ȼ��̰�ĵ�ѡȡ�Ժ���ĳ�Ӱ����С������
        if (Solve(x1, x2, x, n) && Solve(y1, y2, y, n))
        {
            for (int i = 0; i < n; ++i)
            {
                std::cout << x[i] << ' ' << y[i] << std::endl;
            }
        }
        else
        {
            std::puts("IMPOSSIBLE");
        }
    }

    return 0;
}