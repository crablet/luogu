// ����һ��̰����
// ÿ�ζ�������(i + j == n + 1)�ĵ�ԣ�ʵ�ڲ��о���(i + j == n + 2)��
// ��ô����һ��ı���ȡ0��һ��ı���ȡ1��Ȼ���ܹ�(n - 1)���ߣ��𰸱���(n - 1) / 2
#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    std::cout << (n - 1) / 2 << std::endl;

    return 0;
}