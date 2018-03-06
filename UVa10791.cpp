// ��һ���õ�����Ψһ�ֽ�ʽ
#include <iostream>
#include <cmath>

using ll = long long;

// ���n��������ܳ�������d������d��k�η�
int DivedeAll(int &n, int d)
{
    int x = 1;
    while (n % d == 0)
    {
        n /= d;
        x *= d;
    }

    return x;
}

ll Solve(int n)
{
    if (n == 1) // ע�����У�1 == 1 * 1
    {
        return 2;
    }

    ll Ans = 0; // ���Ĵ�
    int pf = 0; // �����ӵĸ���
    int m = static_cast<int>(std::sqrt(n)); // ��Ҫ����ѭ�����ΪҪ�޸�n��ֵ
    for (int i = 2; i <= m; ++i)
    {
        if (n % i == 0) // i��һ���µ�������
        {
            ++pf;
            Ans += DivedeAll(n, i);
        }
    }

    if (n > 1)  // ������������ʣ��ģ��ǾͰ���Ҳ����ȥ
    {
        ++pf;
        Ans += n;
    }
    if (pf <= 1)
    {
        ++Ans;  // ���n������Ǹ��������ǻ�Ҫ����1(n == 1 * n)
    }

    return Ans;
}

int main()
{
    int n, NO = 0;
    while (std::cin >> n && n)
    {
        std::cout << "Case " << ++NO << ": " << Solve(n) << std::endl;
    }

    return 0;
}