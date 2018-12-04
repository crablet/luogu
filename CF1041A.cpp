// ����Ȼ�����һ�鼴��
#include <iostream>
#include <algorithm>
#include <array>

using ll = long long;

int main()
{
    constexpr auto MaxN = 1000 + 5;
    std::array<int, MaxN> Arr{ 0 };

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> Arr[i];
    }
    std::sort(Arr.begin(), Arr.begin() + n);

    ll Sum = 0;
    for (int i = 1; i < n; ++i)
    {
        if (Arr[i] - Arr[i - 1] != 1)   // �ҵ������������֣�������һ�����ͼ��������м�ȱ�ٵ���Щ
        {
            Sum += Arr[i] - Arr[i - 1] - 1;
        }
    }
    std::cout << Sum << std::endl;

    return 0;
}