// �ҹ�����
// ͨ���۲����ǿ���ȷ�����������
// 1) k̫�󣬵���ȡ��������������(n, n - 1)���޷�����
// 2) k��nС����ʱ����ȡ����ֻ��k����Ϊ�Ͻ��k���޷�������
// 3) k��n�󵫲���̫�󣬴�ʱ����ȡ������k��n���з��̽���½缴��
#include <iostream>

using ll = long long;

int main()
{
    ll n, k;
    std::cin >> n >> k;
    if (n * 2 <= k) // k̫��
    {
        std::cout << 0 << std::endl;
    }
    else if (k <= n)    // k��nС
    {
        std::cout << (k - 1) / 2 << std::endl;
    }
    else    // k��n�󵫲���̫��
    {
        std::cout << (n * 2 + 1 - k) / 2 << std::endl;
    }

    return 0;
}