// ���ü�������һ���֪�������״̬��Ȼ���磺bbb...bbaa...a
// ������������ַ������������һ��'a'����ô�Ϳ�һ����֮ǰ�м���'b'���𰸾ͼ��ϼ�����ͬʱ'b'������Ҫ����
// �������һ��'b'����ô'b'�������ͼ�һ��ͬʱ�𰸱��ֲ���
// ��Ϊ��'a'ֱ�����ڵ�'b'����������Ҫ���滻��"bba"�Ĵ�����Ȼ��ÿ��������Щ�滻֮��'b'�ĸ����ᷭ��
// ���Ҫע��ȡģ
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    constexpr int MOD = 1000000000 + 7;

    int Ans = 0, b = 0;

    std::string Str;
    std::cin >> Str;
    for (auto Iter = Str.crbegin(); Iter != Str.crend(); ++Iter)
    {
        if (*Iter == 'a')
        {
            Ans = (Ans + b) % MOD;
            b = b * 2 % MOD;
        }
        else if (*Iter == 'b')
        {
            ++b;
        }
    }
    std::cout << Ans << std::endl;

    return 0;
}