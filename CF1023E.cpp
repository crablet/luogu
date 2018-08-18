// ������
#include <iostream>
#include <string>
#include <algorithm>

// ѯ�ʴ�(x, y)�ܷ񵽴�(n, m)
bool Ask(int x, int y, int n, int m)
{
    std::cout << "? " << x << ' ' << y << ' ' << n << ' ' << m << std::endl;
    std::fflush(stdout);

    std::string s;
    std::cin >> s;
    std::fflush(stdout);
    if (s.front() == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::fflush(stdout);

    std::string s1, s2;
    int x = 1, y = 1;   // ���ȴ�ǰ������
    for (int i = 0; i < n - 1; ++i)
    {
        if (y < n && Ask(x, y + 1, n, n))
        {
            ++y;
            s1.push_back('R');
        }
        else
        {
            ++x;
            s1.push_back('D');
        }
    }

    x = n;
    y = n;  // Ȼ���ٴӺ���ǰ��
    for (int i = 0; i < n - 1; ++i)
    {
        if (x > 1 && Ask(1, 1, x - 1, y))
        {
            --x;
            s2.push_back('D');
        }
        else
        {
            --y;
            s2.push_back('R');
        }
    }

    std::reverse(s2.begin(), s2.end()); // ���ڴӺ���ǰ���Ƿ������ģ�����Ҫ����ȥ
    std::cout << "! " << s1 + s2 << std::endl;

    return 0;
}