#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>

constexpr int MaxN = 10000;

std::vector<int> Primes;
std::array<int, MaxN> e;

// d��ʾ��ָ��
void AddInteger(int n, int d)
{
    for (std::size_t i = 0; i < Primes.size(); ++i)
    {
        while (n % Primes[i] == 0)  // �õ���Ψһ�ֽⶨ��
        {
            n /= Primes[i];
            e[i] += d;
        }

        if (n == 1) // ��ǰ��ֹѭ������ʡʱ��
        {
            break;
        }
    }
}

// ��ʾ�ѽ������(n!)^d
void AddFactorial(int n, int d)
{
    for (int i = 1; i <= n; ++i)
    {
        AddInteger(i, d);
    }
}

// �ͳ�����̷��ж�����
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
    for (int i = 2; i <= 10000; ++i)    // �ȴ����10000���ڵ�����
    {
        if (IsPrime(i))
        {
            Primes.push_back(i);
        }
    }

    int p, q, r, s;
    while (std::cin >> p >> q >> r >> s)
    {
        std::fill(e.begin(), e.end(), 0);   // ÿ�ζ�Ҫ��ʼ��һ��
        AddFactorial(p, 1);
        AddFactorial(q, -1);
        AddFactorial(p - q, -1); // ��������������C(p, q) = p! / (q! (p - q)!)
        AddFactorial(r, -1);
        AddFactorial(s, 1);
        AddFactorial(r - s, 1);  // ��������������C(r, s) = r! / (s! (r - s)!)
                                 // ��Ҫע�����ﻹҪȡһ������
        double Ans = 1.0;
        for (std::size_t i = 0; i < Primes.size(); ++i)
        {
            Ans *= std::pow(Primes[i], e[i]);
        }

        std::printf("%.5lf\n", Ans);
    }

    return 0;
}