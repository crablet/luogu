#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>

constexpr int MaxN = 10000;

std::vector<int> Primes;
std::array<int, MaxN> e;

// d表示幂指数
void AddInteger(int n, int d)
{
    for (std::size_t i = 0; i < Primes.size(); ++i)
    {
        while (n % Primes[i] == 0)  // 用到了唯一分解定理
        {
            n /= Primes[i];
            e[i] += d;
        }

        if (n == 1) // 提前终止循环，节省时间
        {
            break;
        }
    }
}

// 表示把结果乘以(n!)^d
void AddFactorial(int n, int d)
{
    for (int i = 1; i <= n; ++i)
    {
        AddInteger(i, d);
    }
}

// 最传统的试商法判断质数
bool IsPrime(int n)
{
    for (int a = 2; a <= std::sqrt(n); ++a)
    {
        if (n % a == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    for (int i = 2; i <= 10000; ++i)    // 先处理出10000以内的质数
    {
        if (IsPrime(i))
        {
            Primes.push_back(i);
        }
    }

    int p, q, r, s;
    while (std::cin >> p >> q >> r >> s)
    {
        std::fill(e.begin(), e.end(), 0);   // 每次都要初始化一边
        AddFactorial(p, 1);
        AddFactorial(q, -1);
        AddFactorial(p - q, -1); // 以上三步重现了C(p, q) = p! / (q! (p - q)!)
        AddFactorial(r, -1);
        AddFactorial(s, 1);
        AddFactorial(r - s, 1);  // 以上三步重现了C(r, s) = r! / (s! (r - s)!)
                                 // 但要注意这里还要取一个倒数
        double Ans = 1.0;
        for (std::size_t i = 0; i < Primes.size(); ++i)
        {
            Ans *= std::pow(Primes[i], e[i]);
        }

        std::printf("%.5lf\n", Ans);
    }

    return 0;
}