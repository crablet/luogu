// ˼·��
// ����������Щ�������ȶԸá��ַ�����������ɢ��
// Ȼ������Ī�ӣ����������������
#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>

constexpr int MaxN = 400000 + 5;
std::array<int, MaxN> s{ 0 }, q{ 0 }, d{ 0 }, Ans{ 0 }, Sum{ 0 }, cnt{ 0 };
// Sum[t]��ʾt��������ֵĴ���
// cnt[i]��ʾ������i�ε����м���
// Ans[i]��ʾ��i�ε�ѯ�ʵĴ�

int Read()
{
    int n = 0, k = 1;
    char ch = std::getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = std::getchar();
    }

    if (ch == '-')
    {
        k = -1;
        ch = std::getchar();
    }

    while (ch <= '9' && ch >= '0')
    {
        n = n * 10 + ch - '0';
        ch = std::getchar();
    }

    return n * k;
}

class Query
{
public:
    int x, y, id;

    Query() = default;
    Query(int x, int y, int id) :
        x(x), y(y), id(id)
    {
    }

    bool operator<(const Query &rhs) const noexcept
    {
        if (s[x] != s[rhs.x])   // ������ڲ�ͬ�ķֿ飬�ǾͰ��ֿ�Ĵ���������
        {
            return s[x] < s[rhs.x];
        }
        else // ���������ͬ�ķֿ飬�ǾͰ����Ҷ˵�Ĵ���������
        {
            return y < rhs.y;
        }
    }
};

std::array<Query, MaxN> Que;

int main()
{
    int n, m;
    n = Read();
    m = Read();

    int sqt = static_cast<int>(std::sqrt(n));
    for (int i = 1; i <= n; ++i)
    {
        int t;
        t = Read();
        q[i] = t;   // ��Ҫ������ȥ�ص�����
        d[i] = t;   // ԭ���飬��¼��ԭ�ⲻ�����������У�������Ŀ�еġ��ַ�����
        s[i] = i / sqt;   // �ֿ�
    }

    // �ȸ�q��������Ȼ���������ͬ��Ԫ�صĸ�����Size����Ϊ������ɢ����׼��
    std::sort(q.begin() + 1, q.begin() + n + 1);
    auto Size = std::unique(q.begin() + 1, q.begin() + n + 1) - (q.begin() + 1);
    for (int i = 1; i <= n; ++i)
    {
        // ��¼��ԭ������ÿ�����ǵڼ���ģ�Ҳ������ɢ����
        d[i] = std::lower_bound(q.begin() + 1, q.begin() + Size + 1, d[i]) - q.begin();
    }
    for (int i = 1; i <= m; ++i)
    {
        int l, r;
        l = Read();
        r = Read();
        Que[i] = std::move(Query(l, r, i));
    }
    std::sort(Que.begin() + 1, Que.begin() + m + 1);    // ��Ī��ǰҪ������

                                                        // ע��lһ��Ҫ��1��ʼ����������WA���Ĵ�!
    int l = 1, r = 0, Now = 1;
    cnt[0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        auto x = Que[i].x, y = Que[i].y;

        while (l > x)   // ��ǰl��ѯ�ʵ���˵���Ҳ�
        {
            --l;    // l��һ��
            auto &t = Sum[d[l]];    // t������d[l]���ֵĸ���
            --cnt[t];   // ����d[l]�ĸ��������˱仯����һ���е���
            if (Now == t)   // ���������ԭ�����������ͰѼ�������һ
            {
                ++Now;
            }

            ++t;    // ��ʱ��ſ��Ը�������d[l]�ĸ���
            ++cnt[t];
        }

        // �����Ҳ����Ī�ӵ���·��ͬ����
        while (r < y)
        {
            ++r;
            auto &t = Sum[d[r]];
            if (Now == t)
            {
                ++Now;
            }

            --cnt[t];
            ++t;
            ++cnt[t];
        }

        while (l < x)
        {
            auto &t = Sum[d[l]];
            --cnt[t];
            if (Now == t && cnt[t] == 0)    // ���û�б����Ҳ������ô������Ǽ������͵ü�һ��
            {
                --Now;
            }

            --t;
            ++cnt[t];
            ++l;
        }

        while (r > y)
        {
            auto &t = Sum[d[r]];
            --cnt[t];
            if (Now == t && cnt[t] == 0)
            {
                --Now;
            }

            --t;
            ++cnt[t];
            --r;
        }

        Ans[Que[i].id] = Now;
    }

    for (int i = 1; i <= m; ++i)
    {
        std::cout << -Ans[i] << std::endl;  // ��ĿҪ����������෴�����𱻿ӵ���
    }

    return 0;
}