// ����yyf��һ�仰���⣺�ж�һ���ַ����ǲ��ǳ���'n'��������������Ǹ���һ��Ԫ����ĸ
#include <iostream>
#include <string>

bool OK(char c) // �ж���ĸc�Ƿ�ΪԪ����ĸ
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string Str;
    std::cin >> Str;

    // ����Ĭ������yyf��һ�仰���⣺�ж�һ���ַ����ǲ��ǳ���'n'��������������Ǹ���һ��Ԫ����ĸ
    for (std::size_t i = 0; i < Str.size(); ++i)
    {
        if (OK(Str[i])) // �����Ԫ����ĸ���򲻿���
        {
            continue;
        }
        else if (Str[i] == 'n') // ����Ǹ�����ĸ������'n'���򲻿���
        {
            continue;
        }
        else if (i != Str.size() - 1 && OK(Str[i + 1])) // ������Ҫ�ڸ��������һ��Ԫ����ĸ
        {
            continue;
        }
        else   // ��������ǰ���������˵������Berlanese
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;

    return 0;
}