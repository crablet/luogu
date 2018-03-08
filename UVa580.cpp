// �ã�������� - ��ȫ��� = Σ�����
// d[i]��ʾ��i��λ����L���������У���ǰ����Ҫ�ر�˵��
// �����d[i] = d[i - 1] + d[i - 2] + d[i - 3]
// Ȼ���ܵ������Ϊ2^n
// ����������
#include <iostream>
#include <array>

int main()
{
    std::array<int, 55> d{ 0 };
    d[1] = 2;   // U L
    d[2] = 4;   // UU LL UL LU
    d[3] = 7;   // LLU UUL ULL LLL LUU LUL ULU
    for (int i = 4; i < 55; ++i)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    int n;
    while (std::cin >> n && n)
    {
        std::cout << (1 << n) - d[n] << std::endl;
    }

    return 0;
}