// ¥�ϴ��е�������е㲻̫���
// �ҷ�һ������һ�����Ķ��ܿ���������
// ϣ���ܶԴ���а���
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <array>

// �������������ǱȽϴ�ģ��Ͽ����������
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
    static std::array<int, 100000> Book{ 0 };
    int n, k;
    n = Read();
    k = Read();

    // v����Ŵ𰸵���˵���Ҷ˵�
    // s����������
    // l����˵�
    // r���Ҷ˵�
    // Ans��������г���
    std::vector<std::pair<int, int>> v;
    std::multiset<int> s;
    int l = 0, Ans = 0;
    for (int r = 0; r < n; ++r)
    {
        Book[r] = Read();
        s.insert(Book[r]);  // ����std::multiset�����ҿ��ظ�������
        while (*s.crbegin() - *s.cbegin() > k)
        {
            // ������ļ�ȥ��С�ĳ���Χ�ˣ��ǾͲ�ͣ��ɾ����˵�
            // ֱ������ <= k Ϊֹ
            // ��������΢��һ����ȡ����ζ��
            s.erase(s.find(Book[l]));
            ++l;
        }

        if (r - l + 1 > Ans)    // ����õ���һ�����������У��Ǿ͸��´�
        {
            v.clear();
            Ans = r - l + 1;
            v.push_back({ l + 1, r + 1 });  // �Ҵ�0��ʼ��ģ�����Ҫ��һ
        }
        else if (r - l + 1 == Ans)  // ͬ������ҲҪ
        {
            v.push_back({ l + 1, r + 1 });
        }
    }

    std::cout << Ans << ' ' << v.size() << std::endl;
    for (const auto &r : v)
    {
        std::cout << r.first << ' ' << r.second << std::endl;
    }

    return 0;
}