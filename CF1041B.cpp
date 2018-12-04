// ע��x / yҪ��Լ�֣�Ȼ���һ��ȡ��Сֵ�ͺ���
#include <iostream>
#include <algorithm>

using ll = long long;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ll a, b, x, y;
    std::cin >> a >> b >> x >> y;

    auto r = gcd(x, y);
    x /= r;
    y /= r;

    std::cout << std::min(a / x, b / y) << std::endl;

    return 0;
}