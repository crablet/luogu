// ����һ�����ݷ�Χ����ֱ�ӱ���ģ���
// ��Ȼ���úܲ��ÿ�����Ϊ����ʱ���е㳤��873ms�������ǹ��˲��ǣ�������
// ���������ɣ������������Ļ��������Ѷȴ�š��ռ�-��
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using ll = long long;

ll Pri[100000 + 50], Num[100000 + 50];

ll Read()
{
    ll n = 0;
    char ch = std::getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = std::getchar();
    }

    while (ch <= '9' && ch >= '0')
    {
        n = n * 10 + ch - '0';
        ch = std::getchar();
    }

    return n;
}

int main()
{
    ll n, k, m;
    std::cin >> n >> k >> m;
    std::unordered_map<std::string, ll> Map;    // <��������, ���>
    std::string Str;
    for (ll i = 1; i <= n; ++i)
    {
        std::cin >> Str;
        Map[Str] = i;   // ����ÿ������ı��
    }

    for (ll i = 1; i <= n; ++i)
    {
        Pri[i] = Read();
    }

    for (ll i = 1; i <= k; ++i)
    {
        ll p, Min = 999999999 + 50;
        p = Read();
        for (ll i = 1; i <= p; ++i)
        {
            Num[i] = Read();
            if (Pri[Num[i]] < Min)  // ����ͬ���ʹ��ﵱ�л�����С���Ǹ��ļ۸�
            {
                Min = Pri[Num[i]];
            }
        }

        for (ll i = 1; i <= p; ++i)
        {
            Pri[Num[i]] = Min;  // Ȼ��ֻҪ��ͬ���͵Ĵ���Ļ���ȫ����Ϊ��С�ļ���
        }
    }

    ll Sum = 0; // ��Ϊͬ���͵Ĵ���ĵ�ǰ���Ѷ������С���ˣ�����ֱ�Ӳ�ѯĿǰ����ͺ���
    for (ll i = 1; i <= m; ++i)
    {
        std::cin >> Str;
        Sum += Pri[Map[Str]];
    }

    std::cout << Sum << std::endl;

    return 0;
}