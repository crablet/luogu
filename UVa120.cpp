#include <iostream>
#include <sstream>
#include <utility>
#include <array>
#include <algorithm>

// �����������
constexpr int MaxN = 30 + 5;

int n;  // �������еĳ���
std::array<int, MaxN> a{ 0 };   // ���е�����

// ��תa[0...p]
void Flip(int p)
{
    for (int i = 0; i < p - i; ++i)
    {
        std::swap(a[i], a[p - i]);
    }

    std::cout << n - p << ' ';  // �����������ת��λ��
}

int main()
{
    std::string s;
    while (std::getline(std::cin, s))
    {
        std::cout << s << std::endl;    // ��Ϊ��֪���ж��ٸ���������ֻ������ȫ������
                                        // Ҫע������ʱ�������Ǵ��ϵ��¸����ģ�����һ��ջ������ܿ�
        std::stringstream ss(s);
        n = 0;
        while (ss >> a[n])
        {
            ++n;
        }

        // �����ǰ��մӴ�С��˳�����������i��ļ��ʱ��
        // �ǲ���Ӱ���1, 2, 3, ..., i - 1��ļ���ģ�
        // ��Ϊ�����Ѿ���ȷ�ر������˼���ѵײ���i - 1��λ�����ˡ�
        for (int i = n - 1; i > 0; --i)
        {
            // Ԫ��a[0..i]�����Ԫ�ص��±꣬����ڶ�������Ҫ��һ����ΪC++ʹ�õ�����պ�����
            auto p = std::max_element(a.cbegin(), a.cbegin() + i + 1) - a.cbegin();
            if (p == i)
            {
                continue;   //��ʾ��Ԫ���Ѿ���������
            }

            if (p > 0)  // ����Ҫִ��Flip(0)�� ��ΪFlip(0)�൱�ڵ�����תa[0]��û������
            {
                Flip(p);    // �Ȱ�����Ԫ�ط���a[0]��
            }
            Flip(i);    // ���������ģ������ٷ�ת��ʱ��a[]�ĺ�����Ѿ�������
                        // �������е�����⣬������ŵ���һ��һ����
        }

        std::cout << 0 << std::endl;    // �����⣬���Ҫ���һ��0
    }

    return 0;
}