// ̰���⣬���Ƚ��ַ�������С��������Ȼ���ǰ����ȡ�ַ���ֻҪ�����������ַ��Ϳ���ȡ
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::string Str;
    std::cin >> Str;

    std::sort(Str.begin(), Str.end());

    int Ans = Str[0] - 'a' + 1; // ͷ�ַ��϶�����ȡ����ȡһ������
    --k;

    if (k == 0)
    {
        std::cout << Ans << std::endl;
    }
    else
    {
        auto Pre = Str[0];  // ��¼��һ��ȡ�õ��ַ�
        for (int i = 1; i < n; ++i)
        {
            if (Str[i] - Pre > 1)   // �����������ȡ
            {
                Ans += Str[i] - 'a' + 1;
                Pre = Str[i];

                if (--k == 0)
                {
                    std::cout << Ans << std::endl;

                    return 0;
                }
            }
        }

        std::cout << -1 << std::endl;
    }

    return 0;
}