// �������ǿ��Թ۲쵽��x��ʵ�������������Ԫ��֮��û��̫������ռ䣬ÿ������֮�Ͷ�����x * n����
// Ȼ�������ٿ�d������d������֮�֣�����������ҪdΪ����ʱ��|i - j|������dΪ����ʱ��|i - j|����С
// ��dΪ����ʱ������ȡ�Ļ�׼��jӦ��Ϊ1����n������|i - j|�;�����
// ��dΪ����ʱ������ȡ�û�׼��jӦ��Ϊ(n / 2)������|i - j|�;���С
// ֤�����Բο����������ĵ���ҳ���ж�������������ϸ˵��
#include <iostream>
#include <iomanip>

using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll n, m;
    std::cin >> n >> m;

    ll Sum = 0, Min = (n / 2) * (n / 2 + 1) - (n % 2 ? 0 : n / 2), Max = n * (n - 1) / 2;
    while (m--)
    {
        ll x, d;
        std::cin >> x >> d;

        Sum += x * n;
        if (d > 0)
        {
            Sum += Max * d;
        }
        else
        {
            Sum += Min * d;
        }
    }
    std::cout << std::fixed << std::setprecision(15) << 1.0 * Sum / n << std::endl;

    return 0;
}