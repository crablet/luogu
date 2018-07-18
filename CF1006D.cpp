// ��һ��Ҫ����ַ���a����һ���ַ����������޸ģ�ע�⿴�⣬��������WA�˼��飩
// �������ǽ�a��b�ַ����е�ÿ���ַ����飬һͷһβ��Ϊһ��
// ����˵�����ǽ�{a(i), a(l - i - 1), b(i), b(l - i - 1)}�ϲ���һ��
// Ȼ��ͳ��ÿһ���в�ͬ���ַ��ĸ�����ͨ���Բ�ͬ�ַ��������з������۵ó���
#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int l;
    std::cin >> l;

    std::string Str1, Str2;
    std::cin >> Str1 >> Str2;

    int Ans = 0;
    for (int i = 0; i < l / 2; ++i)
    {
        std::unordered_map<char, int> Map;
        ++Map[Str1[i]];
        ++Map[Str2[i]];
        ++Map[Str1[l - i - 1]];
        ++Map[Str2[l - i - 1]];

        if (Map.size() == 2)    // ���ֻ�������ַ���ͬ
        {
            if (Map[Str1[i]] != 2)  // �ǾͿ�������һ���ַ��ĸ����ǲ���2��������ǵĻ���֤��һ���ַ���3��һ���ַ���1������Ҫ����һ���ַ�
            {
                ++Ans;
            }
        }
        else if (Map.size() == 3)   // ����������ַ���ͬ
        {
            if (Str1[i] == Str1[l - i - 1]) // ����a�ַ���ͷβ�Ƿ���ȣ��ǵĻ���ôb�ַ�����ͷβ�����޸ģ�����2
            {
                Ans += 2;
            }
            else   // ���a�ַ���ͷβ����ȣ���ôb�ַ���ֻ��Ҫ�޸�һ���ַ�����
            {
                ++Ans;
            }
        }
        else if (Map.size() == 4)   // ����ĸ��ַ�������ȣ��Ǿ͵������ַ������޸ģ��ĳ����ĶԳƵ���ʽ
        {
            Ans += 2;
        }
    }

    if (l & 1)  // ����ַ����ĳ�������������ô�м��һ���ַ���Ҫ������ó�����һ�£���Ϊ�鲻���ĸ��ַ�һ����
    {
        if (Str1[l / 2] != Str2[l / 2]) // ����ȣ������ٵ���һ���ַ�
        {
            ++Ans;
        }
    }

    std::cout << Ans << std::endl;

    return 0;
}