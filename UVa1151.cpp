// ��һ�⿼������С������
// ����Ľ��ͻ��ǿ�����P358�ȽϺ�
// ��ֻ�Ǵ���İ��˹�������дһ��ע�͹���Ҳο�
// ϣ���ܶԴ�������һ���ṩһ���İ���
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

constexpr int MaxN = 1000 + 10;
constexpr int MaxQ = 8;

int n;
std::array<int, MaxN> x{ 0 }, y{ 0 }, p{ 0 };
std::array<int, MaxQ> Cost{ 0 };
std::array<std::vector<int>, MaxQ> SubN;

int Find(int x)
{
    return p[x] != x ? p[x] = Find(p[x]) : x;
}

class Edge
{
public:
    int u, v, d;

    Edge() = default;
    Edge(int u, int v, int d) :
        u(u), v(v), d(d)
    {
    }
};

// cnt����ʣ���ٸ���û����ͨ
// e���ߵļ���
// Used���Ѿ���ͨ�ı�
template <typename T>
int MST(int cnt, const T &e, T &Used)
{
    if (cnt == 1)
    {
        return 0;
    }

    int Ans = 0;
    Used.clear();
    for (std::size_t i = 0; i < e.size(); ++i)  // Kruskal
    {
        int u = Find(e[i].u), v = Find(e[i].v);
        if (u != v)
        {
            p[u] = v;
            Ans += e[i].d;
            Used.push_back(e[i]);   // �ڵ�һ�ε���Kruskalʱ��Used��������������

            if (--cnt == 1)
            {
                break;
            }
        }
    }

    return Ans;
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

int main()
{
    int T;
    std::cin >> T;  // ��T������
    while (T--)
    {
        int q;
        n = Read(); // ��n����
        q = Read(); // ��q���ײ�
        for (int i = 0; i < q; ++i)
        {
            int cnt;    // ����ײ�����cnt����
            cnt = Read();
            Cost[i] = Read();   // ���ײ͵Ļ���

            SubN[i].clear();    // ��Ϊ�ж������ݣ�����Ҫ�ǵ����
            while (cnt--)
            {
                int u;
                u = Read();
                SubN[i].push_back(u - 1);   // ��¼�ײ�i�����ı�
            }
        }
        for (int i = 0; i < n; ++i) // ��¼ÿ�����(x, y)����
        {
            x[i] = Read();
            y[i] = Read();
        }

        std::vector<Edge> e;
        for (int i = 0; i < n; ++i) // ��������ͼ�ĵ����Ϣ
        {
            for (int j = i + 1; j < n; ++j)
            {
                int c = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                e.emplace_back(i, j, c);
            }
        }

        // ����ΪKruskal��׼��
        std::sort(e.begin(), e.end(), [](const Edge &a, const Edge &b)
        {
            return a.d < b.d;
        });

        for (int i = 0; i < n; ++i)
        {
            p[i] = i;
        }
        std::vector<Edge> Need; // ����С����������ʲô��
        int Ans = MST(n, e, Need);  // ��ûʹ���ײ�֮ǰ����һ����С������
        for (int Mask = 0; Mask < (1 << q); ++Mask) // ö��ÿ���ײ͵�ʹ�����
        {                                           // ������λ����Ŀ�����ȥ��һ��״ѹ
            for (int i = 0; i < n; ++i) // ÿ�ζ����³�ʼ��һ�β��鼯
            {
                p[i] = i;
            }

            int cnt = n, c = 0;
            for (int i = 0; i < q; ++i)
            {
                if (Mask & (1 << i))    // �����ò���i�ײ�
                {
                    c += Cost[i];   // c���ܾ���
                    for (std::size_t j = 1; j < SubN[i].size(); ++j)
                    {
                        // �Ѹ��ײ��еı߶�������������
                        int u = Find(SubN[i][j]), v = Find(SubN[i][0]);
                        if (u != v)
                        {
                            p[u] = v;
                            --cnt;
                        }
                    }
                }
            }

            std::vector<Edge> Dummy;    // ûʲô�õı���
            Ans = std::min(Ans, c + MST(cnt, Need, Dummy));
        }

        std::cout << Ans << std::endl;
        if (T)
        {
            std::putchar('\n');
        }
    }

    return 0;
}