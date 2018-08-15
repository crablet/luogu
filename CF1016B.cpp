// �Ƚϻ������ַ���ƥ����Ŀ
// Ԥ��������
// ��һ��KMPƥ��һ�Σ��ҳ�����ƥ�䵽����ʼ��
// �ڶ���ǰ׺����һ�飬�������ѯ��
#include <iostream>
#include <string>
#include <array>

std::array<int, 10000 + 5> f{ 0 }, Pos{ 0 }, Sum{ 0 };

int n, m, q;

void GetFail(const std::string &P)
{
    for (std::size_t i = 1; i < P.size(); ++i)
    {
        auto j = f[i];
        while (j && P[i] != P[j])
        {
            j = f[j];
        }
        f[i + 1] = P[i] == P[j] ? j + 1 : 0;
    }
}

void Find(const std::string &T, const std::string &P)
{
    GetFail(P);
    std::size_t j = 0;
    for (std::size_t i = 0; i < T.size(); ++i)
    {
        while (j && P[j] != T[i])
        {
            j = f[j];
        }
        if (P[j] == T[i])
        {
            ++j;
        }
        if (j == P.size())
        {
            Pos[i - P.size() + 2] = 1;  // KMP��һ������ͺ��ˣ����һ��ƥ�䵽����ʼ��
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m >> q;

    std::string T, P;
    std::cin >> T >> P;

    Find(T, P); // KMPԤ����һ��

    for (int i = 1; i <= n; ++i)    // ǰ׺����Ԥ����һ��
    {
        Sum[i] = Sum[i - 1] + Pos[i];
    }

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        if (r - l + 1 < m)  // �����ѯ��������һ������ѯ�����ݲ��£��϶����0
        {
            std::cout << 0 << std::endl;
        }
        else    // ����Ͱ���ǰ׺�������㣬ע���м�ӼӼ����Ĳ�Ҫ�ֶ������
        {
            std::cout << Sum[r - m + 1] - Sum[l - 1] << std::endl;
        }
    }

    return 0;
}