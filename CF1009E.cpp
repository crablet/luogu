// ²Î¿¼×ÊÁÏ£º
// https://blog.csdn.net/luyehao1/article/details/81080860
// https://blog.csdn.net/u010746456/article/details/81057082
#include <iostream>
#include <array>

using ll = long long;

constexpr ll MaxN = 1000000 + 10;
constexpr ll Mod = 998244353;

ll n;

std::array<ll, MaxN> a{ 0 }, Pow{ 1 };

void Init()
{
    for (int i = 1; i <= n; ++i)
    {
        Pow[i] = Pow[i - 1] * 2 % Mod;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    Init();

    ll Ans = 0;
    for (ll i = 1; i <= n; ++i)
    {
        auto Cost = (Pow[n - i] + (n - i) * Pow[n - i - 1] % Mod) % Mod;
        Ans = (Ans + a[i] * Cost) % Mod;
    }
    std::cout << Ans << std::endl;

    return 0;
}