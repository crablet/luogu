// 首先我们可以观察到，x其实对于整个数组的元素之和没有太大调整空间，每次数组之和都加上x * n即可
// 然后我们再看d，由于d有正负之分，所以我们想要d为正的时候|i - j|尽量大，d为负的时候|i - j|尽量小
// 当d为正的时候，我们取的基准点j应该为1或者n，这样|i - j|就尽量大
// 当d为负的时候，我们取得基准点j应该为(n / 2)，这样|i - j|就尽量小
// 证明可以参考刘汝佳蓝书的第六页，有对于这个问题的详细说明
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