// ��һ��ĸ���ϸ�Ľ��ͻ��ǵÿ�����P242
// ������ֻ�Ǹ�������һ�ְ�����˼·��ʵ�ֲ��Ҹ����꾡��ע��
// ϣ���ܶԴ�������һ����һ���İ���
#include <iostream>
#include <array>
#include <set>

constexpr int MaxN = 200000 + 5;

int n;
std::array<int, MaxN> a{ 0 }, f{ 0 }, g{ 0 };

struct Pair
{
    int a, g;

    Pair() = default;
    Pair(int a, int g) :
        a(a), g(g)
    {
    }

    // ���Ǹ�std::set�õģ�������a������������
    // ��������std::set�������������������
    bool operator<(const Pair &r) const noexcept
    {
        return a < r.a;
    }
};

// ��һ���������ϴ󣬻���������Ͽ��
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
    T = Read();
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            a[i] = Read();
        }

        // ���ԭ���г���Ϊһ�������������г���Ҳֻ����һ
        if (n == 1)
        {
            std::puts("1");
            continue;
        }

        // g[i]Ϊ�Ե�i��Ԫ�ؽ�β���L���г���
        g[0] = 1;
        for (int i = 1; i < n; ++i) // ���Ҫ������
        {
            if (a[i - 1] < a[i])    // ��������ܵ���
            {
                g[i] = g[i - 1] + 1;    // �Ǿ�����һ�������ټ�һ�������ڶ�̬�滮
            }
            else
            {
                g[i] = 1;   // ����������β������������ֻ�������Լ�
            }
        }

        // f[i]Ϊ�Ե�i��Ԫ�ؿ�ͷ���L���г���
        f[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i)    //���Ҫ������
        {
            if (a[i] < a[i + 1])    // ��������ܵ���
            {
                f[i] = f[i + 1] + 1;    // �Ǿ�����һ�������ټ�һ�������ڶ�̬�滮
            }
            else
            {
                f[i] = 1;   // ����������β������������ֻ�������Լ�
            }
        }

        std::set<Pair> s;
        s.insert(Pair(a[0], g[0]));
        int Ans = 1;    // ����������������һ��Ԫ��
        for (int i = 1; i < n; ++i) // ��ÿһ������ö��
        {
            Pair c(a[i], g[i]);
            auto it = s.lower_bound(c); // �ҵ��׸���С��c��Ԫ�ص�λ��
            bool Keep = true;
            if (it != s.begin())    // ȷ���������Լ��󲻻�Խ��
            {
                auto Last = *(--it);
                auto Len = f[i] + Last.g;   // ��a[j]��βa[i]��ͷ�ĵ��������еĳ���
                Ans = std::max(Ans, Len);   // ���´�

                if (c.g <= Last.g)  // ����Ǳ�������ˣ��Ͳ�Ӧ�ñ�����
                {
                    Keep = false;
                }
            }

            if (Keep)
            {
                s.erase(c);
                s.insert(c);    // ����һ��c��λ��

                it = ++s.find(c);
                while (it != s.end() && it->a > c.a && it->g <= c.g)
                {
                    // ɾ����Щ���ֱ�c��ģ�������֮��β�ĵ�������ȴ��c�̵�
                    s.erase(it++);
                }
            }
        }

        std::cout << Ans << std::endl;
    }

    return 0;
}