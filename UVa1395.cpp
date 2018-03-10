// ���Ȱ�Ȩֵ�ѱߴ�С��������
// Ȼ�����ǲ��ϵ��򲢲鼯��������µı�
// һ��ʼ����ı�ΪL��������ı�ΪR
// ����Krushal��ֱ�����б߶���ͨ��Ϊֹ
// Ȼ�����d[R] - d[L]�����´𰸣�L��ǰ�ƽ�
// �ٰ�R����ΪL���ظ�����Ĺ���ֱ���ߵ���
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

constexpr int MaxN = 100 + 10;
constexpr int INF = 999999999;

int n, m;   // n����ĸ���   m���ߵĸ���
std::array<int, MaxN> p{ 0 };

// ���鼯�Ĳ��Ҳ���
int Find(int x)
{
    if (p[x] == x)
    {
        return x;
    }
    else
    {
        return p[x] = Find(p[x]);
    }
}

// ���
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

class Edge
{
public:
    int u, v, d;

    Edge() = default;
    Edge(int u, int v, int d) : // ��u��v��һ��ȨֵΪd�������
        u(u), v(v), d(d)
    {
    }
};

std::vector<Edge> e;

int Solve()
{
    // ���Ȱѱ߰�Ȩֵ��С��������
    std::sort(e.begin(), e.end(), [](const Edge &a, const Edge &b)
    {
        return a.d < b.d;
    });

    int Ans = INF;
    for (int L = 0; L < m; ++L)
    {
        for (int i = 1; i <= n; ++i)
        {
            p[i] = i;   // ��ʼ�����鼯
        }

        auto cnt = n;
        for (int R = L; R < m; ++R)
        {
            auto u = Find(e[R].u);
            auto v = Find(e[R].v);
            if (u != v) // �������һ��������
            {
                p[u] = v;   // �Ǿͼ��벢�鼯
                --cnt;
                if (cnt == 1)   // ����Ѿ���ͨ�ˣ��Ǿ͸���һ�´𰸣������˳�ѭ��
                {
                    Ans = std::min(Ans, e[R].d - e[L].d);
                    break;
                }
            }
        }
    }

    return (Ans == INF ? -1 : Ans);
}

int main()
{
    while (std::cin >> n >> m && n)
    {
        e.clear();
        for (int i = 0; i < m; ++i)
        {
            int u, v, d;
            u = Read();
            v = Read();
            d = Read();
            e.emplace_back(u, v, d);
        }

        std::cout << Solve() << std::endl;
    }

    return 0;
}