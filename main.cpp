//#include <iostream>
//#include <string>
//#include <array>
//#include <unordered_map>
//
//constexpr int MaxN = 24;
//
//int BitCount(int x)
//{
//    return x == 0 ? 0 : BitCount(x >> 1) + (x & 1);
//}
//
//int main()
//{
//    int n;
//    while (std::cin >> n && n)
//    {
//        std::array<int, MaxN> A{ 0 };
//        std::string s;
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> s;
//            for (const auto &c : s)
//            {
//                A[i] ^= (1 << (c - 'A'));
//            }
//        }
//
//        std::unordered_map<int, int> Table;
//        int n1 = n / 2, n2 = n - n1;
//        for (int i = 0; i < (1 << n1); ++i)
//        {
//            int x = 0;
//            for (int j = 0; j < n1; ++j)
//            {
//                if (i & (1 << j))
//                {
//                    x ^= A[j];
//                }
//            }
//
//            if (!Table.count(x) || BitCount(Table[x]) < BitCount(i))
//            {
//                Table[x] = i;
//            }
//        }
//
//        int Ans = 0;
//        for (int i = 0; i < (1 << n2); ++i)
//        {
//            int x = 0;
//            for (int j = 0; j < n2; ++j)
//            {
//                if (i & (1 << j))
//                {
//                    x ^= A[n1 + j];
//                }
//            }
//
//            if (Table.count(x) && BitCount(Ans) < BitCount(Table[x]) + BitCount(i))
//            {
//                Ans = (i << n1) ^ Table[x];
//            }
//        }
//
//        std::cout << BitCount(Ans) << std::endl;
//        for (int i = 0; i < n; ++i)
//        {
//            if (Ans & (1 << i))
//            {
//                std::cout << i + 1 << ' ';
//            }
//        }
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    std::array<int, 30000 + 5> W{ 0 }, V{ 0 }, F{ 0 };
//    
//    int N, m;
//    std::cin >> N >> m;
//    for (int i = 0; i < m; ++i)
//    {
//        std::cin >> W[i] >> V[i];
//        V[i] *= W[i];
//    }
//
//    for (int i = 0; i < m; ++i)
//    {
//        for (int j = N; j >= W[i]; --j)
//        {
//            F[j] = std::max(F[j], F[j - W[i]] + V[i]);
//        }
//    }
//
//    std::cout << F[N] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int a[1000000] = { 0 };
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        int Max = -99999999;
//        int n;
//        std::cin >> n;
//
//        if (n == 1)
//        {
//            int t;
//            std::cin >> t;
//            std::cout << 1 << std::endl;
//            continue;
//        }
//
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> a[i];
//            if (a[i] > Max)
//            {
//                Max = a[i];
//            }
//        }
//
//        int t = 1;
//        while (Max /= 2)
//        {
//            ++t;
//        }
//
//        int Sum = 1;
//        for (int i = 0; i < t; ++i)
//        {
//            int Zero = 0;
//            int One = 0;
//            for (int j = 0; j < n; ++j)
//            {
//                if ((a[j] & (1 << i)) == 0)
//                {
//                    ++Zero;
//                }
//                else
//                {
//                    ++One;
//                }
//
//                if (One >= 1)
//                {
//                    Sum *= 2;
//                    break;
//                }
//            }
//        }
//
//        std::cout << Sum - n << std::endl;
//    }
//
//    return 0;
//}
//#include <cctype>
//
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
////std::array<ll, 100000> Arr{ 0 }, Brr{ 0 };
//ll Arr[100000], Brr[100000];
//
//struct Node
//{
//    ll Val, LazyTag;
//};
//
//int N, Q;
//
//int k;
//
////std::array<Node, 400000> SegTree1, SegTree2;
//Node SegTree1[400000], SegTree2[400000];
//
//constexpr int lson(int x) { return x << 1; }
//constexpr int rson(int x) { return x << 1 | 1; }
//
//template <typename T>
//void Build2(int Root, const T &Arr, int Start, int End)
//{
//    SegTree2[Root].LazyTag = 0;
//
//    if (Start == End)
//    {
//        SegTree2[Root].Val = Arr[Start];
//    }
//    else
//    {
//        int Mid = (Start + End) >> 1;
//        Build2(lson(Root), Arr, Start, Mid);
//        Build2(rson(Root), Arr, Mid + 1, End);
//        SegTree2[Root].Val = SegTree2[lson(Root)].Val + SegTree2[rson(Root)].Val;
//    }
//}
//
//void PushDown2(int Root, int Start, int End)
//{
//    if (SegTree2[Root].LazyTag != 0)
//    {
//        SegTree2[lson(Root)].LazyTag += SegTree2[Root].LazyTag;
//        SegTree2[rson(Root)].LazyTag += SegTree2[Root].LazyTag;
//
//        int Mid = (Start + End) >> 1;
//        SegTree2[lson(Root)].Val += SegTree2[Root].LazyTag * (Mid - Start + 1);
//        SegTree2[rson(Root)].Val += SegTree2[Root].LazyTag * (End - Mid);
//
//        SegTree2[Root].LazyTag = 0;
//    }
//}
//
//ll Query2(int Root, int NStart, int NEnd, int QStart, int QEnd)
//{
//    if (QStart > NEnd || QEnd < NStart)
//    {
//        return 0;
//    }
//    else if (QStart <= NStart && QEnd >= NEnd)
//    {
//        return SegTree2[Root].Val;
//    }
//
//    PushDown2(Root, NStart, NEnd);
//
//    int Mid = (NStart + NEnd) >> 1;
//    return Query2(lson(Root), NStart, Mid, QStart, QEnd)
//        + Query2(rson(Root), Mid + 1, NEnd, QStart, QEnd);
//}
//
//void Update2(int Root, int NStart, int Nend, int UStart, int UEnd, int AddVal)
//{
//    if (UStart > Nend || UEnd < NStart)
//    {
//        return;
//    }
//    else if (UStart <= NStart && UEnd >= Nend)
//    {
//        SegTree2[Root].LazyTag += AddVal;
//        SegTree2[Root].Val += AddVal * (Nend - NStart + 1);
//        return;
//    }
//
//    PushDown2(Root, NStart, Nend);
//
//    int Mid = (NStart + Nend) >> 1;
//
//    Update2(lson(Root), NStart, Mid, UStart, UEnd, AddVal);
//    Update2(rson(Root), Mid + 1, Nend, UStart, UEnd, AddVal);
//
//    SegTree2[Root].Val = SegTree2[lson(Root)].Val + SegTree2[rson(Root)].Val;
//}
//
//template <typename T>
//void Build1(int Root, const T &Arr, int Start, int End)
//{
//    SegTree1[Root].LazyTag = 0;
//
//    if (Start == End)
//    {
//        SegTree1[Root].Val = Arr[Start];
//    }
//    else
//    {
//        int Mid = (Start + End) >> 1;
//        Build1(lson(Root), Arr, Start, Mid);
//        Build1(rson(Root), Arr, Mid + 1, End);
//        SegTree1[Root].Val = SegTree1[lson(Root)].Val + SegTree1[rson(Root)].Val;
//    }
//}
//
//void PushDown1(int Root, int Start, int End)
//{
//    if (SegTree1[Root].LazyTag != 0)
//    {
//        SegTree1[lson(Root)].LazyTag += SegTree1[Root].LazyTag;
//        SegTree1[rson(Root)].LazyTag += SegTree1[Root].LazyTag;
//
//        int Mid = (Start + End) >> 1;
//        SegTree1[lson(Root)].Val += SegTree1[Root].LazyTag * (Mid - Start + 1);
//        SegTree1[rson(Root)].Val += SegTree1[Root].LazyTag * (End - Mid);
//
//        SegTree1[Root].LazyTag = 0;
//    }
//}
//
//ll Query1(int Root, int NStart, int NEnd, int QStart, int QEnd)
//{
//    if (QStart > NEnd || QEnd < NStart)
//    {
//        return 0;
//    }
//    else if (QStart <= NStart && QEnd >= NEnd)
//    {
//        return SegTree1[Root].Val;
//    }
//
//    PushDown1(Root, NStart, NEnd);
//
//    int Mid = (NStart + NEnd) >> 1;
//    return Query1(lson(Root), NStart, Mid, QStart, QEnd)
//        + Query1(rson(Root), Mid + 1, NEnd, QStart, QEnd);
//}
//
//void Update1(int Root, int NStart, int Nend, int UStart, int UEnd, int AddVal)
//{
//    if (UStart > Nend || UEnd < NStart)
//    {
//        return;
//    }
//    else if (UStart <= NStart && UEnd >= Nend)
//    {
//        SegTree1[Root].LazyTag += AddVal;
//        SegTree1[Root].Val += AddVal * (Nend - NStart + 1);
//        return;
//    }
//
//    PushDown1(Root, NStart, Nend);
//
//    int Mid = (NStart + Nend) >> 1;
//
//    Update1(lson(Root), NStart, Mid, UStart, UEnd, AddVal);
//    Update1(rson(Root), Mid + 1, Nend, UStart, UEnd, AddVal);
//
//    SegTree1[Root].Val = SegTree1[lson(Root)].Val + SegTree1[rson(Root)].Val;
//}
//
//int Read()
//{
//    int n = 0;//, k = 1;
//    char ch = std::getchar();
//    while (!std::isdigit(ch))
//    {
//        ch = std::getchar();
//    }
//
//    while (std::isdigit(ch))
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n;// * k;
//}
//
//int main()
//{
//    N = Read();
//    Q = Read();
//
//    for (register int i = 1; i <= N; ++i)
//    {
//        Arr[i] = Read();
//    }
//
//    Build1(1, Arr, 1, N);
//    Build2(1, Brr, 1, N);
//
//    while (Q--)
//    {
//        register int Command;
//        Command = Read();
//        if (Command == 3)
//        {
//            register int l, r;
//            l = Read();
//            r = Read();
//            std::cout << Query2(1, 1, N, l, r) << std::endl;
//        }
//        else if (Command == 1)
//        {
//            register int l, r, x;
//            l = Read();
//            r = Read();
//            x = Read();
//            Update1(1, 1, N, l, r, x);
//        }
//        else if (Command == 2)
//        {
//            register int l, r, b;
//            l = Read();
//            r = Read();
//            k = Read();
//            b = Read();
//            //ll times = Query1(1, 1, N, l, r);
//            for (register int i = l; i <= r; ++i)
//            {
//                Update2(1, 1, N, i, i, k * Query1(1, 1, N, i, i) + b);
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//ll Arr[400000] = { 0 }, Brr[400000] = { 0 };
////std::array<ll, 100000> Arr{ 0 }, Brr{ 0 };
//
//struct Node
//{
//    ll Val, LazyTag;
//};
//
//int N, Q;
//
//int k;
//
//Node SegTree1[400000], SegTree2[400000];
////std::array<Node, 400000> SegTree1, SegTree2;
//
//template <typename T>
//void Build2(int Root, const T &Arr, int Start, int End)
//{
//    SegTree2[Root].LazyTag = 0;
//
//    if (Start == End)
//    {
//        SegTree2[Root].Val = Arr[Start];
//    }
//    else
//    {
//        int Mid = (Start + End) / 2;
//        Build2(Root * 2, Arr, Start, Mid);
//        Build2(Root * 2 + 1, Arr, Mid + 1, End);
//        SegTree2[Root].Val = SegTree2[Root * 2].Val + SegTree2[Root * 2 + 1].Val;
//    }
//}
//
//void PushDown2(int Root, int Start, int End)
//{
//    if (SegTree2[Root].LazyTag != 0)
//    {
//        SegTree2[Root * 2].LazyTag += SegTree2[Root].LazyTag;
//        SegTree2[Root * 2 + 1].LazyTag += SegTree2[Root].LazyTag;
//
//        int Mid = (Start + End) / 2;
//        SegTree2[Root * 2].Val += SegTree2[Root].LazyTag * (Mid - Start + 1);
//        SegTree2[Root * 2 + 1].Val += SegTree2[Root].LazyTag * (End - Mid);
//
//        SegTree2[Root].LazyTag = 0;
//    }
//}
//
//ll Query2(int Root, int NStart, int NEnd, int QStart, int QEnd)
//{
//    if (QStart > NEnd || QEnd < NStart)
//    {
//        return 0;
//    }
//    else if (QStart <= NStart && QEnd >= NEnd)
//    {
//        return SegTree2[Root].Val;
//    }
//
//    PushDown2(Root, NStart, NEnd);
//
//    int Mid = (NStart + NEnd) / 2;
//    return Query2(Root * 2, NStart, Mid, QStart, QEnd)
//        + Query2(Root * 2 + 1, Mid + 1, NEnd, QStart, QEnd);
//}
//
//void Update2(int Root, int NStart, int Nend, int UStart, int UEnd, int AddVal)
//{
//    if (UStart > Nend || UEnd < NStart)
//    {
//        return;
//    }
//    else if (UStart <= NStart && UEnd >= Nend)
//    {
//        SegTree2[Root].LazyTag += AddVal;
//        SegTree2[Root].Val += AddVal * (Nend - NStart + 1);
//        return;
//    }
//
//    PushDown2(Root, NStart, Nend);
//
//    int Mid = (NStart + Nend) / 2;
//
//    Update2(Root * 2, NStart, Mid, UStart, UEnd, AddVal);
//    Update2(Root * 2 + 1, Mid + 1, Nend, UStart, UEnd, AddVal);
//
//    SegTree2[Root].Val = SegTree2[Root * 2].Val + SegTree2[Root * 2 + 1].Val;
//}
//
//
//template <typename T>
//void Build1(int Root, const T &Arr, int Start, int End)
//{
//    SegTree1[Root].LazyTag = 0;
//
//    if (Start == End)
//    {
//        SegTree1[Root].Val = Arr[Start];
//    }
//    else
//    {
//        int Mid = (Start + End) / 2;
//        Build1(Root * 2, Arr, Start, Mid);
//        Build1(Root * 2 + 1, Arr, Mid + 1, End);
//        SegTree1[Root].Val = SegTree1[Root * 2].Val + SegTree1[Root * 2 + 1].Val;
//    }
//}
//
//void PushDown1(int Root, int Start, int End)
//{
//    if (SegTree1[Root].LazyTag != 0)
//    {
//        SegTree1[Root * 2].LazyTag += SegTree1[Root].LazyTag;
//        SegTree1[Root * 2 + 1].LazyTag += SegTree1[Root].LazyTag;
//
//        int Mid = (Start + End) / 2;
//        SegTree1[Root * 2].Val += SegTree1[Root].LazyTag * (Mid - Start + 1);
//        SegTree1[Root * 2 + 1].Val += SegTree1[Root].LazyTag * (End - Mid);
//
//        SegTree1[Root].LazyTag = 0;
//    }
//}
//
//ll Query1(int Root, int NStart, int NEnd, int QStart, int QEnd)
//{
//    if (QStart > NEnd || QEnd < NStart)
//    {
//        return 0;
//    }
//    else if (QStart <= NStart && QEnd >= NEnd)
//    {
//        return SegTree1[Root].Val;
//    }
//
//    PushDown1(Root, NStart, NEnd);
//
//    int Mid = (NStart + NEnd) / 2;
//    return Query1(Root * 2, NStart, Mid, QStart, QEnd)
//        + Query1(Root * 2 + 1, Mid + 1, NEnd, QStart, QEnd);
//}
//
//void Update1(int Root, int NStart, int Nend, int UStart, int UEnd, int AddVal)
//{
//    if (UStart > Nend || UEnd < NStart)
//    {
//        return;
//    }
//    else if (UStart <= NStart && UEnd >= Nend)
//    {
//        SegTree1[Root].LazyTag += AddVal;
//        SegTree1[Root].Val += AddVal * (Nend - NStart + 1);
//        return;
//    }
//
//    PushDown1(Root, NStart, Nend);
//
//    int Mid = (NStart + Nend) / 2;
//
//    Update1(Root * 2, NStart, Mid, UStart, UEnd, AddVal);
//    Update1(Root * 2 + 1, Mid + 1, Nend, UStart, UEnd, AddVal);
//
//    SegTree1[Root].Val = SegTree1[Root * 2].Val + SegTree1[Root * 2 + 1].Val;
//}
//
//int Read()
//{
//    int n = 0;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n;
//}
//
//int main()
//{
//    N = Read();
//    Q = Read();
//
//    for (int i = 1; i <= N; ++i)
//    {
//        Arr[i] = Read();
//    }
//
//    Build1(1, Arr, 1, N);
//    Build2(1, Brr, 1, N);
//
//    while (Q--)
//    {
//        int Command;
//        Command = Read();
//        if (Command == 3)
//        {
//            int l, r;
//            l = Read();
//            r = Read();
//            std::cout << Query2(1, 1, N, l, r) << std::endl;
//        }
//        else if (Command == 1)
//        {
//            int l, r, x;
//            l = Read();
//            r = Read();
//            x = Read();
//            Update1(1, 1, N, l, r, x);
//        }
//        else if (Command == 2)
//        {
//            int l, r, b;
//            l = Read();
//            r = Read();
//            k = Read();
//            b = Read();
//            for (int i = l; i <= r; ++i)
//            {
//                Update2(1, 1, N, i, i, k * Query1(1, 1, N, i, i) + b);
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//std::string Str;
//
//int n;
//
//int main()
//{
//    std::cin >> Str;
//    std::cin >> n;
//    while (n--)
//    {
//        std::string reg;
//        std::cin >> reg;
//        
//        int Tol = 0;
//        for (std::size_t i = 0; i < reg.size(); ++i)
//        {
//            if (reg[i] == '?')
//            {
//                ++Tol;
//            }
//        }
//
//        for (int t = 1; t < (1 << Tol); ++t)
//        {
//            for (int j = 0; j < Tol; ++j)
//            {
//                std::string Reg;
//                if (t & (1 << j))
//                {
//                    int q = 0;
//                    for (std::size_t i = 0; i < reg.size() - 1; ++i)
//                    {
//                        if (reg[i] != '?' && reg[i + 1] != '?')
//                        {
//                            Reg.push_back(reg[i]);
//                        }
//                        else if (reg[i + 1] == '?' && (q + 1) == (t && (1 << j)))
//                        {
//                            ++q;
//                            Reg.push_back(reg[i]);
//                            ++i;
//                        }
//                        else if (reg[i + 1] == '?' && (q + 1) != (t && (1 << j)))
//                        {
//                            ++q;
//                            ++i;
//                        }
//                    }
//                }
//
//                std::cout << Reg << std::endl;
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//ll Arr[400000] = { 0 }, Brr[400000] = { 0 };
////std::array<ll, 100000> Arr{ 0 }, Brr{ 0 };
//
//struct Node
//{
//    ll Val, LazyTag;
//};
//
//int N, Q;
//
//int k;
//
//Node SegTree1[400000], SegTree2[400000];
////std::array<Node, 400000> SegTree1, SegTree2;
//
//template <typename T>
//void Build2(int Root, const T &Arr, int Start, int End)
//{
//    SegTree2[Root].LazyTag = 0;
//
//    if (Start == End)
//    {
//        SegTree2[Root].Val = Arr[Start];
//    }
//    else
//    {
//        int Mid = (Start + End) / 2;
//        Build2(Root * 2, Arr, Start, Mid);
//        Build2(Root * 2 + 1, Arr, Mid + 1, End);
//        SegTree2[Root].Val = SegTree2[Root * 2].Val + SegTree2[Root * 2 + 1].Val;
//    }
//}
//
//void PushDown2(int Root, int Start, int End)
//{
//    if (SegTree2[Root].LazyTag != 0)
//    {
//        SegTree2[Root * 2].LazyTag += SegTree2[Root].LazyTag;
//        SegTree2[Root * 2 + 1].LazyTag += SegTree2[Root].LazyTag;
//
//        int Mid = (Start + End) / 2;
//        SegTree2[Root * 2].Val += SegTree2[Root].LazyTag * (Mid - Start + 1);
//        SegTree2[Root * 2 + 1].Val += SegTree2[Root].LazyTag * (End - Mid);
//
//        SegTree2[Root].LazyTag = 0;
//    }
//}
//
//ll Query2(int Root, int NStart, int NEnd, int QStart, int QEnd)
//{
//    if (QStart > NEnd || QEnd < NStart)
//    {
//        return 0;
//    }
//    else if (QStart <= NStart && QEnd >= NEnd)
//    {
//        return SegTree2[Root].Val;
//    }
//
//    PushDown2(Root, NStart, NEnd);
//
//    int Mid = (NStart + NEnd) / 2;
//    return Query2(Root * 2, NStart, Mid, QStart, QEnd)
//        + Query2(Root * 2 + 1, Mid + 1, NEnd, QStart, QEnd);
//}
//
//void Update2(int Root, int NStart, int Nend, int UStart, int UEnd, int AddVal)
//{
//    if (UStart > Nend || UEnd < NStart)
//    {
//        return;
//    }
//    else if (UStart <= NStart && UEnd >= Nend)
//    {
//        SegTree2[Root].LazyTag += AddVal;
//        SegTree2[Root].Val += AddVal * (Nend - NStart + 1);
//        return;
//    }
//
//    PushDown2(Root, NStart, Nend);
//
//    int Mid = (NStart + Nend) / 2;
//
//    Update2(Root * 2, NStart, Mid, UStart, UEnd, AddVal);
//    Update2(Root * 2 + 1, Mid + 1, Nend, UStart, UEnd, AddVal);
//
//    SegTree2[Root].Val = SegTree2[Root * 2].Val + SegTree2[Root * 2 + 1].Val;
//}
//
//
//template <typename T>
//void Build1(int Root, const T &Arr, int Start, int End)
//{
//    SegTree1[Root].LazyTag = 0;
//
//    if (Start == End)
//    {
//        SegTree1[Root].Val = Arr[Start];
//    }
//    else
//    {
//        int Mid = (Start + End) / 2;
//        Build1(Root * 2, Arr, Start, Mid);
//        Build1(Root * 2 + 1, Arr, Mid + 1, End);
//        SegTree1[Root].Val = SegTree1[Root * 2].Val + SegTree1[Root * 2 + 1].Val;
//    }
//}
//
//void PushDown1(int Root, int Start, int End)
//{
//    if (SegTree1[Root].LazyTag != 0)
//    {
//        SegTree1[Root * 2].LazyTag += SegTree1[Root].LazyTag;
//        SegTree1[Root * 2 + 1].LazyTag += SegTree1[Root].LazyTag;
//
//        int Mid = (Start + End) / 2;
//        SegTree1[Root * 2].Val += SegTree1[Root].LazyTag * (Mid - Start + 1);
//        SegTree1[Root * 2 + 1].Val += SegTree1[Root].LazyTag * (End - Mid);
//
//        SegTree1[Root].LazyTag = 0;
//    }
//}
//
//ll Query1(int Root, int NStart, int NEnd, int QStart, int QEnd)
//{
//    if (QStart > NEnd || QEnd < NStart)
//    {
//        return 0;
//    }
//    else if (QStart <= NStart && QEnd >= NEnd)
//    {
//        return SegTree1[Root].Val;
//    }
//
//    PushDown1(Root, NStart, NEnd);
//
//    int Mid = (NStart + NEnd) / 2;
//    return Query1(Root * 2, NStart, Mid, QStart, QEnd)
//        + Query1(Root * 2 + 1, Mid + 1, NEnd, QStart, QEnd);
//}
//
//void Update1(int Root, int NStart, int Nend, int UStart, int UEnd, int AddVal)
//{
//    if (UStart > Nend || UEnd < NStart)
//    {
//        return;
//    }
//    else if (UStart <= NStart && UEnd >= Nend)
//    {
//        SegTree1[Root].LazyTag += AddVal;
//        SegTree1[Root].Val += AddVal * (Nend - NStart + 1);
//        return;
//    }
//
//    PushDown1(Root, NStart, Nend);
//
//    int Mid = (NStart + Nend) / 2;
//
//    Update1(Root * 2, NStart, Mid, UStart, UEnd, AddVal);
//    Update1(Root * 2 + 1, Mid + 1, Nend, UStart, UEnd, AddVal);
//
//    SegTree1[Root].Val = SegTree1[Root * 2].Val + SegTree1[Root * 2 + 1].Val;
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    N = Read();
//    Q = Read();
//
//    for (int i = 1; i <= N; ++i)
//    {
//        Arr[i] = Read();
//    }
//
//    Build1(1, Arr, 1, N);
//    Build2(1, Brr, 1, N);
//
//    while (Q--)
//    {
//        int Command;
//        Command = Read();
//        if (Command == 3)
//        {
//            int l, r;
//            l = Read();
//            r = Read();
//            std::cout << Query2(1, 1, N, l, r) << std::endl;
//        }
//        else if (Command == 1)
//        {
//            int l, r, x;
//            l = Read();
//            r = Read();
//            x = Read();
//            Update1(1, 1, N, l, r, x);
//        }
//        else if (Command == 2)
//        {
//            int l, r, b;
//            l = Read();
//            r = Read();
//            k = Read();
//            b = Read();
//            for (int i = l; i <= r; ++i)
//            {
//                Update2(1, 1, N, i, i, k * Query1(1, 1, N, i, i) + b);
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//
//constexpr int MaxN = 1000 + 5;
//
//std::array<std::string, MaxN> Map;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int H, W;
//    H = Read();
//    W = Read();
//    for (int i = 0; i < H; ++i)
//    {
//        std::cin >> Map[i];
//    }
//
//    int T;
//    T = Read();
//    while (T--)
//    {
//        int l1, r1, l2, r2, l3, r3, l4, r4;
//        l1 = Read();
//        r1 = Read();
//        l2 = Read();
//        r2 = Read();
//        l3 = Read();
//        r3 = Read();
//        l4 = Read();
//        r4 = Read();
//        //std::cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3 >> l4 >> r4;
//        //--l1;
//        //--l2;
//        //--r1;
//        //--r2;
//        //--l3;
//        //--l4;
//        //--r3;
//        //--r4;
//        
//        int Ans = 0;
//        for (int x1 = l1; x1 <= l2; ++x1)
//        {
//            for (int x2 = r1; x2 <= r2; ++x2)
//            {
//                if (Map[x1][x2] != Map[x1 + l3 - l1][x2 + r3 - r1])
//                {
//                    ++Ans;
//                }
//            }
//        }
//
//        if (Ans == 0)
//        {
//            std::puts("Perfect");
//        }
//        else if (Ans == 1)
//        {
//            std::puts("One difference");
//        }
//        else
//        {
//            std::puts("Wrong");
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_set>
//#include <array>
//
//std::array<int, 100> Arr{ 0 };
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        int n;
//        std::cin >> n;
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> Arr[i];
//        }
//
//        std::unordered_set<int> s;
//        s.insert(0);
//        for (int i = 0; i < n - 1; ++i)
//        {
//            for (int j = i + 1; j < n; ++j)
//            {
//                s.insert(Arr[i] ^ Arr[j]);
//            }
//        }
//
//        std::cout << s.size() - n << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//constexpr int Mod = 1000000007;
//int stirling(int, int);
//int main()
//{
//    int n;
//    std::cin >> n;
//    cout << stirling(n + 3, n - 1) % Mod << endl;
//    return 0;
//}
//int stirling(int i, int j)
//{
//    if ((j == i) || (j == 1))
//    {
//        return 1;
//    }
//    else if (j == 2)
//    {
//        return (int)(pow(2, (i - 1) * 1.0) - 1) % Mod;
//    }
//    else
//    {
//        return (stirling(i - 1, j - 1) % Mod + j * stirling(i - 1, j) % Mod);
//    }
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//int main()
//{
//    cout << "请输入两个整数n和k: ";
//    int n, k;
//    cin >> n >> k;
//    int array[100][100];
//    int i, j;
//    for (i = 0, j = 0; i < 100; i++, j++)
//    {
//        array[i][j] = 1;
//    }
//    for (j = 0; j < 100; j++)
//    {
//        array[0][j] = 1;
//    }
//
//
//    for (i = 1; i < 100; i++)
//    {
//        for (j = i + 1; j < 100; j++)
//        {
//            array[i][j] = (i + 1) * array[i][j - 1] + array[i - 1][j - 1];
//        }
//    }
//    cout << "这组数将会有 " << array[k - 1][n - 1] << " 种划分方式" << endl;
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <array>
//
//int main()
//{
//    std::string Str;
//    std::cin >> Str;
//
//    int Len = 0;
//    std::array<int, 28> Arr{ 0 };
//    for (int i = 0; i < 26; ++i)
//    {
//        std::cin >> Arr[i];
//        Len += Arr[i];
//    }
//
//    if (Len == 0 || Len > Str.size())
//    {
//        std::puts("No");
//        return 0;
//    }
//
//    for (std::size_t i = 0; i <= Str.size() - Len; ++i)
//    {
//        std::array<int, 28> Brr{ 0 };
//        for (int j = i; j < i + Len; ++j)
//        {
//            ++Brr[Str[j] - 'a'];
//        }
//
//        if (Arr == Brr)
//        {
//            std::puts("Yes");
//            return 0;
//        }
//    }
//
//    std::puts("No");
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        std::string Num;
//        std::cin >> Num;
//        if (Num.size() < 10)
//        {
//            std::cout << Num << std::endl;
//        }
//        else if (Num >= 10 && Num <= 99)
//        {
//            std::cout << Num + Num / 10 + Num % 10 << std::endl;
//        }
//        else if (Num >= 100 && Num <= 999)
//        {
//            int n = 3, Last = 0;
//            for (int i = 0; i < (1 << n); ++i)
//            {
//                for (int j = 0; j < n; ++j)
//                {
//
//                }
//            }
//        }
//    }
//}
//#include <iostream>
//#include <string>
//#include <array>
//
//int main()
//{
//    std::string Str;
//    std::cin >> Str;
//
//    int Len = 0;
//    std::array<int, 28> Arr{ 0 };
//    for (int i = 0; i < 26; ++i)
//    {
//        std::cin >> Arr[i];
//        Len += Arr[i];
//    }
//
//    for (std::size_t i = 0; i < Str.size() - Len; ++i)
//    {
//        std::array<int, 28> Brr{ 0 };
//        for (int j = i; j < i + Len; ++j)
//        {
//            ++Brr[Str[j] - 'a'];
//        }
//
//        if (Arr == Brr)
//        {
//            std::puts("Yes");
//            return 0;
//        }
//    }
//
//    std::puts("No");
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <array>
//
//constexpr int MaxN = 100000 + 5;
//
//std::array<std::array<char, 28>, MaxN> Arr{ 0 }, Brr{ 0 };
//
//int main()
//{
//    std::string Str;
//    for (std::size_t i = 0; i < Str.size(); ++i)
//    {
//        ++Arr[Str[i]][i + 1];
//    }
//    for (std::size_t i = 0; i < Str.size(); ++i)
//    {
//        Brr[Str[i]][i + 1] = Brr[Str[i]][i] + Arr[Str[i]][i + 1];
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        int n;
//        std::cin >> n;
//        std::printf("%d\n", (int)std::ceil(std::log2(n)));
//    }
//
//    return 0;
//}
//#include <iostream>
//
//constexpr int Mod = 1000000007;
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    int Sum = 0;
//    for (int x1 = 1; x1 <= n; ++x1)
//    {
//        for (int x2 = x1; x2 <= n; ++x2)
//        {
//            for (int x3 = x2; x3 <= n; ++x3)
//            {
//                for (int x4 = x3; x4 <= n; ++x4)
//                {
//                    Sum = (n - x1)(n - x2)(n - x3)(n - x4);
//                }
//            }
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include <climits>
//
//std::array<int, 1 << 17> Data{ 0 };
//
//int n = 10000;
//
//int Mod;
//
//void Init(int n_)
//{
//    n = 1;
//    while (n < n_)
//    {
//        n *= 2;
//    }
//
//    for (int i = 0; i < 2 * n - 1; ++i)
//    {
//        Data[i] = INT_MAX;
//    }
//}
//
//void Update(int k, int a)
//{
//    k += n - 1;
//    Data[k] = a % Mod;
//    while (k > 0)
//    {
//        k = (k - 1) / 2;
//        Data[k] = std::min(Data[k * 2 + 1], Data[k * 2 + 2]) % Mod;
//    }
//}
//
//int Query(int a, int b, int k, int l, int r)
//{
//    if (r <= a || b <= l)
//    {
//        return INT_MAX;
//    }
//
//    if (a <= l && r <= b)
//    {
//        return Data[k] % Mod;
//    }
//    else
//    {
//        return std::min(Query(a, b, k * 2 + 1, l, (l + r) / 2),
//                        Query(a, b, k * 2 + 2, (l + r) / 2, r)) % Mod;
//    }
//}
//
//int main()
//{
//    int M;
//    std::cin >> M >> Mod;
//
//    int Len = 0;
//    int Last = 0;
//    while (M--)
//    {
//        char c;
//        int Num;
//        std::cin >> c >> Num;
//        if (c == 'A')
//        {
//            Update(++Len, (Num + Last) % Mod);
//        }
//        else
//        {
//            Last = Query(Len - Num, Len, 0, 0, n);
//            std::cout << Last << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//constexpr int MaxN = 400000 + 5;
//
//using ll = long long;
//
//ll Read()
//{
//    ll n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//struct tree
//{
//public:
//    ll Val, LazyTagAdd, LazyTagMul;
//};
//
//std::array<tree, MaxN> Tree;
//std::array<ll, MaxN> Arr{ 0 };
//
//ll Mod;
//
//void Build(ll Root, ll l, ll r)
//{
//    Tree[Root].LazyTagAdd = 0;
//    Tree[Root].LazyTagMul = 1;
//
//    if (l == r)
//    {
//        Tree[Root].Val = Arr[l];
//    }
//    else
//    {
//        auto Mid = (l + r) / 2;
//        Build(Root * 2, l, Mid);
//        Build(Root * 2 + 1, Mid + 1, r);
//        Tree[Root].Val = Tree[Root * 2].Val + Tree[Root * 2 + 1].Val;
//    }
//
//    Tree[Root].Val %= Mod;
//}
//
//void PushDown(ll Root, ll l, ll r)
//{
//    auto Mid = (l + r) / 2;
//
//    Tree[Root * 2].Val = (Tree[Root * 2].Val * Tree[Root].LazyTagMul
//        + Tree[Root].LazyTagAdd * (Mid - l + 1)) % Mod;
//    Tree[Root * 2 + 1].Val = (Tree[Root * 2 + 1].Val * Tree[Root].LazyTagMul
//        + Tree[Root].LazyTagAdd * (r - Mid)) % Mod;
//
//    Tree[Root * 2].LazyTagMul = (Tree[Root * 2].LazyTagMul * Tree[Root].LazyTagMul) % Mod;
//    Tree[Root * 2 + 1].LazyTagMul = (Tree[Root * 2 + 1].LazyTagMul * Tree[Root].LazyTagMul) % Mod;
//    Tree[Root * 2].LazyTagAdd = (Tree[Root * 2].LazyTagAdd * Tree[Root].LazyTagMul + Tree[Root].LazyTagAdd) % Mod;
//    Tree[Root * 2 + 1].LazyTagAdd = (Tree[Root * 2 + 1].LazyTagAdd * Tree[Root].LazyTagMul + Tree[Root].LazyTagAdd) % Mod;
//
//    Tree[Root].LazyTagAdd = 0;
//    Tree[Root].LazyTagMul = 1;
//}
//
//void UpdateMul(ll Root, ll l, ll r, ll rl, ll rr, ll k)
//{
//    if (l > rr || rl > r)
//    {
//        return;
//    }
//
//    if (rl <= l && rr >= r)
//    {
//        Tree[Root].Val = (Tree[Root].Val * k) % Mod;
//        Tree[Root].LazyTagMul = (Tree[Root].LazyTagMul * k) % Mod;
//        Tree[Root].LazyTagAdd = (Tree[Root].LazyTagAdd * k) % Mod;
//
//        return;
//    }
//
//    PushDown(Root, l, r);
//    auto Mid = (l + r) / 2;
//    UpdateMul(Root * 2, l, Mid, rl, rr, k);
//    UpdateMul(Root * 2 + 1, Mid + 1, r, rl, rr, k);
//    Tree[Root].Val = (Tree[Root * 2].Val + Tree[Root * 2 + 1].Val) % Mod;
//}
//
//void UpdateAdd(ll Root, ll l, ll r, ll rl, ll rr, ll k)
//{
//    if (rr < l || rl > r)
//    {
//        return;
//    }
//
//    if (rl <= l && rr >= r)
//    {
//        Tree[Root].LazyTagAdd = (Tree[Root].LazyTagAdd + k) % Mod;
//        Tree[Root].Val = (Tree[Root].Val + k * (r - l + 1)) % Mod;
//
//        return;
//    }
//
//    PushDown(Root, l, r);
//    auto Mid = (l + r) / 2;
//    UpdateAdd(Root * 2, l, Mid, rl, rr, k);
//    UpdateAdd(Root * 2 + 1, Mid + 1, r, rl, rr, k);
//    Tree[Root].Val = (Tree[Root * 2].Val + Tree[Root * 2 + 1].Val) % Mod;
//}
//
//ll Query(ll Root, ll l, ll r, ll rl, ll rr)
//{
//    if (rr < l || rl > r)
//    {
//        return 0;
//    }
//
//    if (rl <= l && r <= rr)
//    {
//        return Tree[Root].Val;
//    }
//
//    PushDown(Root, l, r);
//    auto Mid = (l + r) / 2;
//    return (Query(Root * 2, l, Mid, rl, rr) + Query(Root * 2 + 1, Mid + 1, r, rl, rr)) % Mod;
//}
//
//int main()
//{
//    ll N;
//    std::cin >> N >> Mod;
//    for (ll i = 1; i <= N; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//    Build(1, 1, N);
//
//    ll M;
//    std::cin >> M;
//    while (M--)
//    {
//        ll Command;
//        std::cin >> Command;
//        ll l, r, k;
//        if (Command == 1)
//        {
//            std::cin >> l >> r >> k;
//            UpdateMul(1, 1, N, l, r, k);
//        }
//        else if (Command == 2)
//        {
//            std::cin >> l >> r >> k;
//            UpdateAdd(1, 1, N, l, r, k);
//        }
//        else
//        {
//            std::cin >> l >> r;
//            std::cout << Query(1, 1, N, l, r) << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//constexpr int MaxN = 400000 + 5;
//
//using ll = long long;
//
//ll Read()
//{
//    ll n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//struct tree
//{
//public:
//    ll Val, LazyTagAdd, LazyTagMul;
//};
//
//std::array<tree, MaxN> Tree;
//std::array<ll, MaxN> Arr{ 0 };
//
//ll Mod;
//
//void Build(ll Root, ll l, ll r)
//{
//    Tree[Root].LazyTagAdd = 0;
//    Tree[Root].LazyTagMul = 1;
//
//    if (l == r)
//    {
//        Tree[Root].Val = Arr[l];
//    }
//    else
//    {
//        auto Mid = (l + r) / 2;
//        Build(Root * 2, l, Mid);
//        Build(Root * 2 + 1, Mid + 1, r);
//        Tree[Root].Val = Tree[Root * 2].Val + Tree[Root * 2 + 1].Val;
//    }
//
//    Tree[Root].Val %= Mod;
//}
//
//void PushDown(ll Root, ll l, ll r)
//{
//    auto Mid = (l + r) / 2;
//
//    Tree[Root * 2].Val = (Tree[Root * 2].Val * Tree[Root].LazyTagMul
//                        + Tree[Root].LazyTagAdd * (Mid - l + 1)) % Mod;
//    Tree[Root * 2 + 1].Val = (Tree[Root * 2 + 1].Val * Tree[Root].LazyTagMul
//                            + Tree[Root].LazyTagAdd * (r - Mid)) % Mod;
//
//    Tree[Root * 2].LazyTagMul = (Tree[Root * 2].LazyTagMul * Tree[Root].LazyTagMul) % Mod;
//    Tree[Root * 2 + 1].LazyTagMul = (Tree[Root * 2 + 1].LazyTagMul * Tree[Root].LazyTagMul) % Mod;
//    Tree[Root * 2].LazyTagAdd = (Tree[Root * 2].LazyTagAdd * Tree[Root].LazyTagMul + Tree[Root].LazyTagAdd) % Mod;
//    Tree[Root * 2 + 1].LazyTagAdd = (Tree[Root * 2 + 1].LazyTagAdd * Tree[Root].LazyTagMul + Tree[Root].LazyTagAdd) % Mod;
//
//    Tree[Root].LazyTagAdd = 0;
//    Tree[Root].LazyTagMul = 1;
//}
//
//void UpdateMul(ll Root, ll l, ll r, ll rl, ll rr, ll k)
//{
//    if (l > rr || rl > r)
//    {
//        return;
//    }
//
//    if (rl <= l && rr >= r)
//    {
//        Tree[Root].Val = (Tree[Root].Val * k) % Mod;
//        Tree[Root].LazyTagMul = (Tree[Root].LazyTagMul * k) % Mod;
//        Tree[Root].LazyTagAdd = (Tree[Root].LazyTagAdd * k) % Mod;
//
//        return;
//    }
//
//    PushDown(Root, l, r);
//    auto Mid = (l + r) / 2;
//    UpdateMul(Root * 2, l, Mid, rl, rr, k);
//    UpdateMul(Root * 2 + 1, Mid + 1, r, rl, rr, k);
//    Tree[Root].Val = (Tree[Root * 2].Val + Tree[Root * 2 + 1].Val) % Mod;
//}
//
//void UpdateAdd(ll Root, ll l, ll r, ll rl, ll rr, ll k)
//{
//    if (rr < l || rl > r)
//    {
//        return;
//    }
//
//    if (rl <= l && rr >= r)
//    {
//        Tree[Root].LazyTagAdd = (Tree[Root].LazyTagAdd + k) % Mod;
//        Tree[Root].Val = (Tree[Root].Val + k * (r - l + 1)) % Mod;
//
//        return;
//    }
//
//    PushDown(Root, l, r);
//    auto Mid = (l + r) / 2;
//    UpdateAdd(Root * 2, l, Mid, rl, rr, k);
//    UpdateAdd(Root * 2 + 1, Mid + 1, r, rl, rr, k);
//    Tree[Root].Val = (Tree[Root * 2].Val + Tree[Root * 2 + 1].Val) % Mod;
//}
//
//ll Query(ll Root, ll l, ll r, ll rl, ll rr)
//{
//    if (rr < l || rl > r)
//    {
//        return 0;
//    }
//
//    if (rl <= l && r <= rr)
//    {
//        return Tree[Root].Val;
//    }
//
//    PushDown(Root, l, r);
//    auto Mid = (l + r) / 2;
//    return (Query(Root * 2, l, Mid, rl, rr) + Query(Root * 2 + 1, Mid + 1, r, rl, rr)) % Mod;
//}
//
//int main()
//{
//    ll N, M;
//    std::cin >> N >> M >> Mod;
//    for (ll i = 1; i <= N; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//
//    Build(1, 1, N);
//    while (M--)
//    {
//        ll Command;
//        std::cin >> Command;
//        ll l, r, k;
//        if (Command == 1)
//        {
//            std::cin >> l >> r >> k;
//            UpdateMul(1, 1, N, l, r, k);
//        }
//        else if (Command == 2)
//        {
//            std::cin >> l >> r >> k;
//            UpdateAdd(1, 1, N, l, r, k);
//        }
//        else
//        {
//            std::cin >> l >> r;
//            std::cout << Query(1, 1, N, l, r) << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string Str;
//    std::cin >> Str;
//    Str.back() = '5';
//    std::cout << Str << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//using ll = long long;
//
//ll n, Next;
//
//bool Check(ll t)
//{
//    ll s = 0;
//    Next = t;
//    ll T = t;
//    while (T > 0)
//    {
//        s = s * n + T % n;
//        T /= n;
//    }
//
//    Next += s;
//
//    return s == t;
//}
//
//int Turn(char c)
//{
//    if (c >= '0' && c <= '9')
//    {
//        return c - '0';
//    }
//    else
//    {
//        return c - 'A' + 10;
//    }
//}
//
//int main()
//{
//    std::string Str;
//    std::cin >> n >> Str;
//
//    ll s = 0;
//    for (std::size_t i = 0; i < Str.size(); ++i)
//    {
//        s = s * n + Turn(Str[i]);
//    }
//    int Step = 0;
//    while (Step < 30)
//    {
//        if (Check(s))
//        {
//            std::cout << "STEP=" << Step << std::endl;
//            return 0;
//        }
//        else
//        {
//            s = Next;
//            ++Step;
//        }
//    }
//
//    std::puts("Impossible!");
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using ll = long long;
//
//constexpr int MaxN = 30;
//const ll INF = 1LL << 60;
//
//ll S[MaxN][MaxN][MaxN];
//
//void Expand(int i, int &b0, int &b1, int &b2)
//{
//    b0 = i & 1;
//    i >>= 1;
//    b1 = i & 1;
//    i >>= 1;
//    b2 = i & 1;
//}
//
//int Sign(int b0, int b1, int b2)
//{
//    return (b0 + b1 + b2) % 2 == 1 ? 1 : -1;
//}
//
//ll Sum(int x1, int x2, int y1, int y2, int z1, int z2)
//{
//    auto dx = x2 - x1 + 1, dy = y2 - y1 + 1, dz = z2 - z1 + 1;
//    ll s = 0;
//    for (int i = 0; i < (1 << 3); ++i)
//    {
//        int b0, b1, b2;
//        Expand(i, b0, b1, b2);
//        s -= S[x2 - b0 * dx][y2 - b1 * dy][z2 - b2 * dz] * Sign(b0, b1, b2);
//    }
//
//    return s;
//}
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        int a, b, c;
//        std::cin >> a >> b >> c;
//
//        std::memset(S, 0, sizeof(S));
//        for (int x = 1; x <= a; ++x)
//        {
//            for (int y = 1; y <= b; ++y)
//            {
//                for (int z = 1; z <= c; ++z)
//                {
//                    std::cin >> S[x][y][z];
//                }
//            }
//        }
//
//        int b0, b1, b2;
//        for (int x = 1; x <= a; ++x)
//        {
//            for (int y = 1; y <= b; ++y)
//            {
//                for (int z = 1; z <= c; ++z)
//                {
//                    for (int i = 1; i < (1 << 3); ++i)
//                    {
//                        Expand(i, b0, b1, b2);
//                        S[x][y][z] += S[x - b0][y - b1][z - b2] * Sign(b0, b1, b2);
//                    }
//                }
//            }
//        }
//
//        ll Ans = -INF;
//        for (int x1 = 1; x1 <= a; ++x1)
//        {
//            for (int x2 = x1; x2 <= a; ++x2)
//            {
//                for (int y1 = 1; y1 <= b; ++y1)
//                {
//                    for (int y2 = y1; y2 <= b; ++y2)
//                    {
//                        ll M = 0;
//                        for (int z = 1; z <= c; ++z)
//                        {
//                            auto s = Sum(x1, x2, y1, y2, 1, z);
//                            Ans = std::max(Ans, s - M);
//                            M = std::min(M, s);
//                        }
//                    }
//                }
//            }
//        }
//
//        std::cout << Ans << std::endl;
//        if (T)
//        {
//            std::putchar('\n');
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//struct Point
//{
//    int x, y;
//
//    Point() = default;
//    Point(int x, int y) :
//        x(x), y(y)
//    {
//    }
//};
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    
//    std::vector<Point> P;
//    for (int i = 0; i < n; ++i)
//    {
//        int x, y;
//        std::cin >> x >> y;
//        if (x > y)
//        {
//            std::swap(x, y);
//        }
//
//        P.emplace_back(x, y);
//    }
//
//    std::sort(P.begin(), P.end(), [](const Point &a, const Point &b)
//    {
//        return a.y < b.y;
//    });
//
//    int Ans = 1;
//    int Last = P[0].y;
//    for (int i = 1; i < n; ++i)
//    {
//        if (P[i].x >= Last)
//        {
//            ++Ans;
//            Last = P[i].y;
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//struct Contest
//{
//    int x, y;
//
//    Contest() = default;
//    Contest(int x, int y) :
//        x(x), y(y)
//    {
//    }
//};
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n;
//    n = Read();
//
//    std::vector<Contest> C;
//    for (int i = 0; i < n; ++i)
//    {
//        int x, y;
//        x = Read();
//        y = Read();
//        C.emplace_back(x, y);
//    }
//
//    std::sort(C.begin(), C.end(), [](const Contest &a, const Contest &b)
//    {
//        return a.y < b.y;
//    });
//
//    int Last = C[0].y;
//    int Ans = 1;
//    for (int i = 1; i < n; ++i)
//    {
//        if (C[i].x >= Last)
//        {
//            ++Ans;
//            Last = C[i].y;
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//constexpr int MaxN = 100 + 10;
//
//struct Point
//{
//    int x, y;
//
//    bool operator<(const Point &rhs) const noexcept
//    {
//        return x < rhs.x;
//    }
//};
//
//std::array<Point, MaxN> P;
//std::array<int, MaxN> y{ 0 }, On{ 0 }, On2{ 0 }, Left{ 0 };
//
//int n, m;
//
//int Solve()
//{
//    std::sort(P.begin(), P.begin() + n);
//    std::sort(y.begin(), y.begin() + n);
//    m = std::unique(y.begin(), y.begin() + n) - y.begin();
//    if (m <= 2)
//    {
//        return n;
//    }
//
//    int Ans = 0;
//    for (int a = 0; a < m; ++a)
//    {
//        for (int b = a + 1; b < m; ++b)
//        {
//            auto Ymin = y[a], Ymax = y[b];
//            int k = 0;
//            for (int i = 0; i < n; ++i)
//            {
//                if (i == 0 || P[i].x != P[i - 1].x)
//                {
//                    ++k;
//                    On[k] = On2[k] = 0;
//                    Left[k] = k == 0 ? 0 : Left[k - 1] + On2[k - 1] - On[k - 1];
//                }
//
//                if (P[i].y > Ymin && P[i].y < Ymax)
//                {
//                    ++On[k];
//                }
//                if (P[i].y >= Ymin && P[i].y <= Ymax)
//                {
//                    ++On2[k];
//                }
//            }
//
//            if (k <= 2)
//            {
//                return n;
//            }
//
//            int M = 0;
//            for (int j = 1; j <= k; ++j)
//            {
//                Ans = std::max(Ans, Left[j] + On2[j] + M);
//                M = std::max(M, On[j] - Left[j]);
//            }
//        }
//    }
//
//    return Ans;
//}
//
//int main()
//{
//    int NO = 0;
//    while (std::cin >> n && n)
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> P[i].x >> P[i].y;
//            y[i] = P[i].y;
//        }
//
//        std::cout << "Case " << ++NO << ": " << Solve() << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//constexpr int MaxN = 1000;
//
//std::array<std::array<int, MaxN>, MaxN> Mat{ 0 }, Up{ 0 }, Left{ 0 }, Right{ 0 };
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        int m, n;
//        std::cin >> m >> n;
//        for (int i = 0; i < m; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                auto ch = std::getchar();
//                while (ch != 'F' && ch != 'R')
//                {
//                    ch = std::getchar();
//                }
//
//                Mat[i][j] = ch == 'F' ? 0 : 1;
//            }
//        }
//
//        int Ans = 0;
//        for (int i = 0; i < m; ++i)
//        {
//            int lo = -1, ro = n;
//            for (int j = 0; j < n; ++j)
//            {
//                if (Mat[i][j] == 1)
//                {
//                    Up[i][j] = Left[i][j] = 0;
//                    lo = j;
//                }
//                else
//                {
//                    Up[i][j] = i == 0 ? 1 : Up[i - 1][j] + 1;
//                    Left[i][j] = i == 0 ? lo + 1 : std::max(Left[i - 1][j], lo + 1);
//                }
//            }
//
//            for (int j = n - 1; j >= 0; --j)
//            {
//                if (Mat[i][j] == 1)
//                {
//                    Right[i][j] = n;
//                    ro = j;
//                }
//                else
//                {
//                    Right[i][j] = i == 0 ? ro - 1 : std::min(Right[i - 1][j], ro - 1);
//                    Ans = std::max(Ans, Up[i][j] * (Right[i][j] - Left[i][j] + 1));
//                }
//            }
//        }
//
//        std::cout << Ans * 3 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//#include <algorithm>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    std::array<std::string, 20> Str;
//    std::string t;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> t;
//        Str[i] = t;
//    }
//
//    std::sort(Str.begin(), Str.begin() + n, [](const std::string &a, const std::string &b)
//    {
//        return a + b > b + a;
//    });
//
//    for (int i = 0; i < n; ++i)
//    {
//        std::cout << Str[i];
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<int, 21> A{ 0, 1, 1, 2 }, X{ 0 };
//
//    int a, n, m, x;
//    std::cin >> a >> n >> m >> x;
//    for (int i = 4; i <= n; ++i)
//    {
//        A[i] = A[i - 1] + A[i - 2] - 1;
//        X[i] = X[i - 1] + X[i - 2] + 1;
//    }
//
//    int xx = (m - A[n - 1] * a) / X[n - 1];
//    std::cout << a * A[x] + xx * X[x] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int GCD(int a, int b)
//{
//    if (b == 0)
//    {
//        return a;
//    }
//    else
//    {
//        return GCD(b, a % b);
//    }
//}
//
//int main()
//{
//    int x, y;
//    std::cin >> x >> y;
//
//    int Ans = 0;
//    for (int a = 2; a <= std::sqrt(x * y); ++a)
//    {
//        if (x * y % a == 0 && GCD(a, x * y / a) == x)
//        {
//            ++Ans;
//        }
//    }
//
//    std::cout << Ans * 2 << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int GCD(int a, int b)
//{
//    if (b == 0)
//    {
//        return a;
//    }
//    else
//    {
//        return GCD(b, a % b);
//    }
//}
//
//int main()
//{
//    int x, y;
//    std::cin >> x >> y;
//
//    int Ans = 0;
//    for (int a = 2; a <= y; ++a)
//    {
//        for (int b = a + 1; b <= y; ++b)
//        {
//            auto t = GCD(a, b);
//            if (t == x && a * b / t == y)
//            {
//                ++Ans;
//            }
//        }
//    }
//
//    std::cout << Ans * 2 << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    const double PI = std::acos(-1.0);
//    double r;
//    std::cin >> r;
//    std::printf("%.6lf\n", PI * r * r);
//    std::printf("%.6lf\n", 2.0 * r * r);
//
//    return 0;
//}

//// 思路：
//// 由于数据有些大，所以先对该“字符串”进行离散化
//// 然后套用莫队，求出区间众数即可
//#include <iostream>
//#include <array>
//#include <cmath>
//#include <algorithm>
//
//constexpr int MaxN = 400000 + 5;
//std::array<int, MaxN> s{ 0 }, q{ 0 }, d{ 0 }, Ans{ 0 }, Sum{ 0 }, cnt{ 0 };
//// Sum[t]表示t这个数出现的次数
//// cnt[i]表示出现了i次的数有几个
//// Ans[i]表示第i次的询问的答案
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//class Query
//{
//public:
//    int x, y, id;
//
//    Query() = default;
//    Query(int x, int y, int id) :
//        x(x), y(y), id(id)
//    {
//    }
//
//    bool operator<(const Query &rhs) const noexcept
//    {
//        if (s[x] != s[rhs.x])   // 如果处于不同的分块，那就按分块的次序来排列
//        {
//            return s[x] < s[rhs.x];
//        }
//        else // 如果处于相同的分块，那就按照右端点的次序来排列
//        {
//            return y < rhs.y;
//        }
//    }
//};
//
//std::array<Query, MaxN> Que;
//
//int main()
//{
//    int n, m;
//    n = Read();
//    m = Read();
//
//    int sqt = static_cast<int>(std::sqrt(n));
//    for (int i = 1; i <= n; ++i)
//    {
//        int t;
//        t = Read();
//        q[i] = t;   // 将要被排序去重的数组
//        d[i] = t;   // 原数组，记录下原封不动的数字序列，就是题目中的“字符串”
//        s[i] = i / sqt;   // 分块
//    }
//
//    // 先给q数组排序，然后求出不相同的元素的个数（Size），为后面离散化做准备
//    std::sort(q.begin() + 1, q.begin() + n + 1);
//    auto Size = std::unique(q.begin() + 1, q.begin() + n + 1) - (q.begin() + 1);
//    for (int i = 1; i <= n; ++i)
//    {
//        // 记录下原数组中每个数是第几大的，也就是离散化了
//        d[i] = std::lower_bound(q.begin() + 1, q.begin() + Size + 1, d[i]) - q.begin();
//    }
//    for (int i = 1; i <= m; ++i)
//    {
//        int l, r;
//        l = Read();
//        r = Read();
//        Que[i] = std::move(Query(l, r, i));
//    }
//    std::sort(Que.begin() + 1, Que.begin() + m + 1);    // 用莫队前要先排序
//
//    // 注意l一定要从1开始，我在这里WA了四次!
//    int l = 1, r = 0, Now = 1;
//    cnt[0] = 1;
//    for (int i = 1; i <= m; ++i)
//    {
//        auto x = Que[i].x, y = Que[i].y;
//
//        while (l > x)   // 当前l在询问的左端点的右侧
//        {
//            --l;    // l退一步
//            auto &t = Sum[d[l]];    // t：数字d[l]出现的个数
//            --cnt[t];   // 数字d[l]的个数发生了变化，这一句有点绕
//            if (Now == t)   // 如果遇到了原来的众数，就把计数器加一
//            {
//                ++Now;
//            }
//
//            ++t;    // 这时候才可以更新数字d[l]的个数
//            ++cnt[t];
//        }
//
//        // 后面的也还是莫队的套路，同理了
//        while (r < y)
//        {
//            ++r;
//            auto &t = Sum[d[r]];
//            if (Now == t)
//            {
//                ++Now;
//            }
//
//            --cnt[t];
//            ++t;
//            ++cnt[t];
//        }
//
//        while (l < x)
//        {
//            auto &t = Sum[d[l]];
//            --cnt[t];
//            if (Now == t && cnt[t] == 0)    // 如果没有别的数也能有那么多个，那计数器就得减一了
//            {
//                --Now;
//            }
//
//            --t;
//            ++cnt[t];
//            ++l;
//        }
//
//        while (r > y)
//        {
//            auto &t = Sum[d[r]];
//            --cnt[t];
//            if (Now == t && cnt[t] == 0)
//            {
//                --Now;
//            }
//
//            --t;
//            ++cnt[t];
//            --r;
//        }
//
//        Ans[Que[i].id] = Now;
//    }
//
//    for (int i = 1; i <= m; ++i)
//    {
//        std::cout << -Ans[i] << std::endl;  // 题目要求输出的是相反数，别被坑到了
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <utility>
//#include <algorithm>
//
//constexpr int MaxN = 400000 + 5;
//constexpr int e = 10;
//
//class Query
//{
//public:
//    int Left, Right, ID, Pos;
//
//    Query() = default;
//    Query(int l, int r, int id, int p) :
//        Left(l), Right(r), ID(id), Pos(p)
//    {
//    }
//
//    bool operator<(const Query &rhs) const noexcept
//    {
//        if (Pos == rhs.Pos)
//        {
//            return Right < rhs.Right;
//        }
//        else
//        {
//            return Pos < rhs.Pos;
//        }
//    }
//};
//
//int main()
//{
//    int n, m;
//    std::cin >> n >> m;
//
//    static std::array<std::pair<int, int>, 500> k;
//    for (int i = 1; i <= n; ++i)
//    {
//        std::cin >> k[i].first;
//        k[i].second = i;
//    }
//    std::sort(k.begin() + 1, k.begin() + n + 1);
//
//    static std::array<int, MaxN> b{ 0 };
//    for (int i = 1, j = 0; i <= n; ++i)
//    {
//        if (i == 1 || k[i].first != k[i - 1].first)
//        {
//            ++j;
//        }
//
//        b[k[i].second] = j;
//    }
//
//    static std::array<Query, MaxN> a;
//    int s = static_cast<int>(std::sqrt(m));
//    for (int i = 1; i <= m; ++i)
//    {
//        int l, r;
//        std::cin >> l >> r;
//        a[i] = std::move(Query(l, r, i, l / s));
//    }
//    std::sort(a.begin() + 1, a.begin() + m + 1);
//
//    int Left = 1, Right = 0, MaxNum = b[a[1].Left], Ans = 0;
//    static std::array<int, MaxN> Res{ 0 }, cnt{ 0 }, num{ 0 };
//    for (int i = 1; i <= m; ++i)
//    {
//        while (Left > a[i].Left)
//        {
//            --Left;
//            --cnt[num[b[Left]] + e];
//            ++cnt[num[b[Left]] + 1 + e];
//
//            if (Ans == num[b[Left]])
//            {
//                ++Ans;
//            }
//
//            ++num[b[Left]];
//        }
//
//        while (Right < a[i].Right)
//        {
//            ++Right;
//            --cnt[num[Right]];
//            ++cnt[num[Right] + 1];
//
//            if (Ans == num[b[Right]])
//            {
//                ++Ans;
//            }
//
//            ++num[b[Right]];
//        }
//
//        while (Left < a[i].Left)
//        {
//            if (Ans == num[b[Left]] && cnt[b[Left]] == 1)
//            {
//                --Ans;
//            }
//
//            --cnt[num[b[Left]] + e];
//            ++cnt[num[b[Left]] + 1 + e];
//            --num[b[Left]];
//
//            ++Left;
//        }
//
//        while (Right > a[i].Right)
//        {
//            if (Ans == num[b[Right]] && cnt[b[Right] + e] == 1)
//            {
//                --Ans;
//            }
//
//            --cnt[num[b[Right]] + e];
//            ++cnt[num[b[Right]] + 1 + e];
//            --num[b[Right]];
//
//            --Right;
//        }
//
//        Res[a[i].ID] = -Ans;
//    }
//
//    for (int i = 1; i <= m; ++i)
//    {
//        std::cout << Res[i] << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//constexpr int MaxN = 100000 + 5;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    static std::array<int, MaxN> A{ 0 }, B{ 0 };
//    int n, S;
//    while (std::cin >> n >> S)
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            A[i] = Read();
//        }
//        for (int i = 1; i <= n; ++i)
//        {
//            B[i] = B[i - 1] + A[i];
//        }
//
//        int Ans = n + 1;
//        int i = 1;
//        for (int j = 1; j <= n; ++j)
//        {
//            if (B[i - 1] > B[j] - S)
//            {
//                continue;
//            }
//            while (B[i] <= B[j] - S)
//            {
//                ++i;
//            }
//
//            Ans = std::min(Ans, j - i + 1);
//        }
//
//        std::cout << (Ans == n + 1 ? 0 : Ans) << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_set>
//
//int main()
//{
//    std::unordered_set<int> s;
//    for (int i = 0; i < 10; ++i)
//    {
//        int n;
//        std::cin >> n;
//        s.insert(n % 42);
//    }
//
//    std::cout << s.size() << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <utility>
//#include <array>
//
//constexpr int MaxN = 100000 + 5;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//void Update(int x, int a, int w, double &L, double &R)
//{
//    if (a == 0)
//    {
//        if (x <= 0 || x >= w)
//        {
//            R = L - 1;
//        }
//    }
//    else if (a > 0)
//    {
//        L = std::max(L, -1.0 * x / a);
//        R = std::min(R, 1.0 * (w - x) / a);
//    }
//    else
//    {
//        L = std::max(L, 1.0 * (w - x) / a);
//        R = std::min(R, -1.0 * x / a);
//    }
//}
//
//class Event
//{
//public:
//    double x;
//    int Type;
//
//    Event() = default;
//    Event(double x, int t) :
//        x(x), Type(t)
//    {
//    }
//
//    bool operator<(const Event &rhs) const noexcept
//    {
//        return x < rhs.x || (x == rhs.x && Type > rhs.Type);
//    }
//};
//
//std::array<Event, MaxN * 2> Events;
//
//int main()
//{
//    int T;
//    T = Read();
//    while (T--)
//    {
//        int w, h, n, e = 0;
//        w = Read();
//        h = Read();
//        n = Read();
//        for (int i = 0; i < n; ++i)
//        {
//            int x, y, a, b;
//            x = Read();
//            y = Read();
//            a = Read();
//            b = Read();
//
//            double L = 0, R = 1e10;
//            Update(x, a, w, L, R);
//            Update(y, b, h, L, R);
//            if (L < R)
//            {
//                Events[e++] = std::move(Event(L, 0));
//                Events[e++] = std::move(Event(R, 1));
//            }
//        }
//
//        std::sort(Events.begin(), Events.begin() + e);
//        int cnt = 0, Ans = 0;
//        for (int i = 0; i < e; ++i)
//        {
//            if (Events[i].Type == 0)
//            {
//                Ans = std::max(Ans, ++cnt);
//            }
//            else
//            {
//                --cnt;
//            }
//        }
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    int i = 0, Sum = 0;
//    while (Sum < n)
//    {
//        ++i;
//        Sum += i;
//    }
//
//    int p = Sum - n + 1;
//    int q = i + n - Sum;
//    if (i % 2 == 1)
//    {
//        std::cout << p << '/' << q << std::endl;
//    }
//    else
//    {
//        std::cout << q << '/' << p << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include <utility>
//
//constexpr int MaxN = 1000000 + 5;
//constexpr int MaxM = 1000000 + 5;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//class Query
//{
//public:
//    int Left, Right, ID, Pos;
//
//    Query() = default;
//    Query(int Left, int Right, int ID, int Pos) :
//        Left(Left), Right(Right), ID(ID), Pos(Pos)
//    {
//    }
//
//    bool operator<(const Query &rhs) const noexcept
//    {
//        if (Pos == rhs.Pos)
//        {
//            return Right < rhs.Right;
//        }
//        else
//        {
//            return Pos < rhs.Pos;
//        }
//    }
//};
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    static std::array<int, MaxN> Num;
//    for (int i = 1; i <= n; ++i)
//    {
//        Num[i] = Read();
//    }
//
//    int m;
//    std::cin >> m;
//    int s = static_cast<int>(std::sqrt(m));
//    static std::array<Query, MaxM> a;
//    for (int i = 1; i <= m; ++i)
//    {
//        int l, r;
//        l = Read();
//        r = Read();
//        a[i] = std::move(Query(l, r, i, l / s));
//    }
//    std::sort(a.begin() + 1, a.begin() + m + 1);
//
//    int Left = 1, Right = 0, Ans = 0;
//    static std::array<int, MaxM> Res{ 0 }, cnt{ 0 };
//    for (int i = 1; i <= m; ++i)
//    {
//        while (Left > a[i].Left)
//        {
//            --Left;
//            ++cnt[Num[Left]];
//            if (cnt[Num[Left]] == 1)
//            {
//                ++Ans;
//            }
//        }
//
//        while (Right < a[i].Right)
//        {
//            ++Right;
//            ++cnt[Num[Right]];
//            if (cnt[Num[Right]] == 1)
//            {
//                ++Ans;
//            }
//        }
//
//        while (Left < a[i].Left)
//        {
//            --cnt[Num[Left]];
//            if (cnt[Num[Left]] == 0)
//            {
//                --Ans;
//            }
//            ++Left;
//        }
//
//        while (Right > a[i].Right)
//        {
//            --cnt[Num[Right]];
//            if (cnt[Num[Right]] == 0)
//            {
//                --Ans;
//            }
//            --Right;
//        }
//
//        Res[a[i].ID] = Ans;
//    }
//
//    for (int i = 1; i <= m; ++i)
//    {
//        std::cout << Res[i] << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <utility>
//#include <algorithm>
//
//constexpr int MaxN = 50000 + 5;
//
//class Query
//{
//public:
//    int Left, Right, ID, Pos;
//
//    Query() = default;
//    Query(int l, int r, int id, int pos) :
//        Left(l), Right(r), ID(id), Pos(pos)
//    {
//    }
//
//    bool operator<(const Query &rhs) const noexcept
//    {
//        if (Pos == rhs.Pos)
//        {
//            return Right < rhs.Right;
//        }
//        else
//        {
//            return Pos < rhs.Pos;
//        }
//    }
//};
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n, m, k;
//    n = Read();
//    m = Read();
//    k = Read();
//
//    static std::array<int, MaxN> Num;
//    for (int i = 1; i <= n; ++i)
//    {
//        Num[i] = Read();
//    }
//
//    int s = std::sqrt(n);
//    static std::array<Query, MaxN> a;
//    for (int i = 1; i <= m; ++i)
//    {
//        int l, r;
//        l = Read();
//        r = Read();
//        a[i] = std::move(Query(l, r, i, l / s));
//    }
//    std::sort(a.begin() + 1, a.begin() + m + 1);
//
//    static std::array<int, MaxN> cnt{ 0 }, Res;
//    int Left = 1, Right = 0, Ans = 0;
//    for (int i = 1; i <= m; ++i)
//    {
//        while (Left > a[i].Left)
//        {
//            --Left;
//            ++cnt[Num[Left]];
//            Ans += 2 * cnt[Num[Left]] - 1;
//        }
//
//        while (Right < a[i].Right)
//        {
//            ++Right;
//            ++cnt[Num[Right]];
//            Ans += 2 * cnt[Num[Right]] - 1;
//        }
//
//        while (Left < a[i].Left)
//        {
//            --cnt[Num[Left]];
//            Ans -= 2 * cnt[Num[Left]] + 1;
//            ++Left;
//        }
//
//        while (Right > a[i].Right)
//        {
//            --cnt[Num[Right]];
//            Ans -= 2 * cnt[Num[Right]] + 1;
//            --Right;
//        }
//
//        Res[a[i].ID] = Ans;
//    }
//
//    for (int i = 1; i <= m; ++i)
//    {
//        std::cout << Res[i] << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//ll Buf[101];
//
//ll Next(ll n, ll k)
//{
//    if (k == 0)
//    {
//        return 0;
//    }
//
//    ll k2 = k * k;
//    int L = 0;
//    while (k2 > 0)
//    {
//        Buf[L++] = k2 % 10;
//        k2 /= 10;
//    }
//
//    if (n > L)
//    {
//        n = L;
//    }
//
//    ll Ans = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        Ans = Ans * 10 + Buf[--L];
//    }
//
//    return Ans;
//}
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        ll n, k;
//        std::cin >> n >> k;
//
//        ll Ans = k;
//        int k1 = k, k2 = k;
//        do
//        {
//            k1 = Next(n, k1);
//            
//            k2 = Next(n, k2);
//            if (k2 > Ans)
//            {
//                Ans = k2;
//            }
//            k2 = Next(n, k2);
//            if (k2 > Ans)
//            {
//                Ans = k2;
//            }
//        } while (k1 != k2);
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_set>
//#include <string>
//#include <sstream>
//
//using ll = long long;
//
//ll Buf[100];
//
//ll Next(ll n, ll k)
//{
//    if (k == 0)
//    {
//        return 0;
//    }
//
//    ll k2 = k * k;
//    int L = 0;
//    while (k2 > 0)
//    {
//        Buf[L++] = k2 % 10;
//        k2 /= 10;
//    }
//
//    if (n > L)
//    {
//        n = L;
//    }
//
//    ll Ans = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        Ans = Ans * 10 + Buf[--L];
//    }
//
//    return Ans;
//}
//
////ll Next(ll n, ll k)
////{
////    std::stringstream ss;
////    ss << k * k;
////    auto s = ss.str();
////    if (s.size() > n)
////    {
////        s = s.substr(0, n);
////    }
////
////    return std::stoll(s);
////}
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        ll n, k;
//        std::cin >> n >> k;
//        std::unordered_set<ll> s;
//        auto Ans = k;
//        while (!s.count(k))
//        {
//            s.insert(k);
//            if (k > Ans)
//            {
//                Ans = k;
//            }
//
//            k = Next(n, k);
//        }
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 100000> A;
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        int n;
//        std::cin >> n;
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> A[i];
//        }
//
//        int Ans = A[0] - A[1];
//        int Pre = A[0];
//        for (int j = 1; j < n; ++j)
//        {
//            Ans = std::max(Ans, Pre - A[j]);
//            Pre = std::max(A[j], Pre);
//        }
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        int n;
//        std::cin >> n;
//        int Pre = 0;
//        int Ans;
//        int a, b;
//        std::cin >> a >> b;
//        Pre = a;
//        Ans = a - b;
//        for (int i = 2; i < n; ++i)
//        {
//            int t;
//            std::cin >> t;
//            if (Pre - t > Ans)
//            {
//                Ans = Pre - t;
//                Pre = std::max(Pre, t);
//            }
//        }
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n;
//    while (std::cin >> n && n)
//    {
//        std::array<int, 101> c{ 0 };
//        for (int i = 0; i < n; ++i)
//        {
//            int k;
//            k = Read();
//            ++c[k];
//        }
//
//        bool First = true;
//        for (int i = 1; i <= 100; ++i)
//        {
//            for (int j = 0; j < c[i]; ++j)
//            {
//                if (First)
//                {
//                    std::cout << i;
//                    First = false;
//                }
//                else
//                {
//                    std::cout << ' ' << i;
//                }
//            }
//        }
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <queue>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    constexpr int MaxN = 1500 + 5;
//    constexpr int MaxM = 50000 + 5;
//    static std::array<std::array<int, MaxN>, MaxN> Map{ 0 };
//    std::array<int, MaxM> d{ 0 };
//    std::fill(d.begin() + 2, d.end(), -1);
//    
//    int n, m;
//    std::cin >> n >> m;
//    for (int i = 0; i < m; ++i)
//    {
//        int a, b, v;
//        a = Read();
//        b = Read();
//        v = Read();
//        Map[a][b] = std::max(Map[a][b], v);
//    }
//    
//    std::queue<int> q;
//    q.push(1);
//    while (!q.empty())
//    {
//        auto t = q.front();
//        q.pop();
//        for (int i = 1; i <= n; ++i)
//        {
//            if (Map[t][i] != 0 && d[i] < d[t] + Map[t][i])
//            {
//                d[i] = d[t] + Map[t][i];
//                q.push(i);
//            }
//        }
//    }
//
//    std::cout << d[n] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int a, b;
//    std::cin >> a >> b;
//    a = a + b;
//    b = a - b;
//    a = a - b;
//    std::cout << a << ' ' << b << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//int main()
//{
//    int a, b, c;
//    std::cin >> a >> b >> c;
//    if (a > b)
//    {
//        std::swap(a, b);
//    }
//    if (a > c)
//    {
//        std::swap(a, c);
//    }
//    if (b > c)
//    {
//        std::swap(b, c);
//    }
//
//    std::cout << a << ' ' << b << ' ' << c << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//constexpr int MaxN = 100000 + 10;
//int n;
//std::array<int, MaxN> r{ 0 }, Left{ 0 }, Right{ 0 };
//
//bool Test(int p)
//{
//    auto x = r[1], y = p - r[1];
//    Left[1] = x;
//    Right[1] = 0;
//    for (int i = 2; i <= n; ++i)
//    {
//        if (i % 2 == 1)
//        {
//            Right[i] = std::min(y - Right[i - 1], r[i]);
//            Left[i] = r[i] - Right[i];
//        }
//        else
//        {
//            Left[i] = std::min(x - Left[i - 1], r[i]);
//            Right[i] = r[i] - Left[i];
//        }
//    }
//
//    return Left[n] == 0;
//}
//
//int main()
//{
//    while (std::cin >> n && n)
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            std::cin >> r[i];
//        }
//
//        if (n == 1)
//        {
//            std::cout << r[1] << std::endl;
//            continue;
//        }
//        r[n + 1] = r[1];
//
//        int L = 0, R = 0;
//        for (int i = 1; i <= n; ++i)
//        {
//            L = std::max(L, r[i] + r[i + 1]);
//        }
//        if (n % 2 == 1)
//        {
//            for (int i = 1; i <= n; ++i)
//            {
//                R = std::max(R, r[i] * 3);
//            }
//
//            while (L < R)
//            {
//                auto M = L + (R - L) / 2;
//                if (Test(M))
//                {
//                    R = M;
//                }
//                else
//                {
//                    L = M + 1;
//                }
//            }
//        }
//
//        std::cout << L << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    for (int i = 1; i <= 9; ++i)
//    {
//        for (int j = 1; j <= 9 - i + 1; ++j)
//        {
//            std::cout << i << '*' << j << '=' << j * i << ' ';
//        }
//
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= n - i; ++j)
//        {
//            std::putchar(' ');
//        }
//        for (int k = 1; k <= 2 * i - 1; ++k)
//        {
//            std::putchar('*');
//        }
//
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = n - 1; j >= i; --j)
//        {
//            std::putchar('*');
//        }
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    for (int i = 1; i <= 9; ++i)
//    {
//        for (int j = 1; j <= i; ++j)
//        {
//            std::cout << j << " * " << i << " = " << j * i << ' ';
//        }
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    double Sum = 0.0;
//    double Flag = 1.0;
//    for (int i = 1; i <= 10; ++i)
//    {
//        Sum += Flag / i;
//        Flag = -Flag;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int main()
//{
//    std::array<int, 3> a;
//    for (int i = 0; i < 3; ++i)
//    {
//        std::cin >> a[i];
//    }
//    std::sort(a.begin(), a.end());
//
//    for (auto &r : a)
//    {
//        std::cout << r << ' ';
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//void Print(int Left, int Right, const std::string &Tree)
//{
//    if (Left < Right)
//    {
//        int Mid = (Left + Right) / 2;
//        Print(Left, Mid, Tree);
//        Print(Mid + 1, Right, Tree);
//    }
//
//    int Zero = 0, One = 0;
//    for (int i = Left; i <= Right; ++i)
//    {
//        if (Tree[i - 1] == '0')
//        {
//            ++Zero;
//        }
//        else
//        {
//            ++One;
//        }
//    }
//
//    if (Zero == 0 && One > 0)
//    {
//        std::putchar('I');
//    }
//    else if (Zero > 0 && One == 0)
//    {
//        std::putchar('B');
//    }
//    else
//    {
//        std::putchar('F');
//    }
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    std::string Tree;
//    std::cin >> Tree;
//    
//    Print(1, 1 << n, Tree);
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    using stu = int*;
//    int a = 1024;
//    stu p = &a;
//    std::cout << *p << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//#include <vector>
//
//constexpr int MaxN = 1000 + 10;
//int n, s, k;
//std::array<int, MaxN> fa;
//std::array<bool, MaxN> Covered{ false };
//std::array<std::vector<int>, MaxN> gr, Nodes;
//
//void DFS(int u, int f, int d)
//{
//    fa[u] = f;
//    auto nc = gr[u].size();
//    if (nc == 1 && d > k)
//    {
//        Nodes[d].push_back(u);
//    }
//
//    for (std::size_t i = 0; i < nc; ++i)
//    {
//        auto v = gr[u][i];
//        if (v != f)
//        {
//            DFS(v, u, d + 1);
//        }
//    }
//}
//
//void DFS2(int u, int f, int d)
//{
//    Covered[u] = true;
//    auto nc = gr[u].size();
//    for (std::size_t i = 0; i < nc; ++i)
//    {
//        auto v = gr[u][i];
//        if (v != f && d < k)
//        {
//            DFS2(v, u, d + 1);
//        }
//    }
//}
//
//int Solve()
//{
//    int Ans = 0;
//    std::fill(Covered.begin(), Covered.end(), false);
//    for (int d = n - 1; d > k; --d)
//    {
//        for (std::size_t i = 0; i < Nodes[d].size(); ++i)
//        {
//            auto u = Nodes[d][i];
//            if (Covered[u])
//            {
//                continue;
//            }
//
//            auto v = u;
//            for (int j = 0; j < k; ++j)
//            {
//                v = fa[v];
//            }
//
//            DFS2(v, -1, 0);
//            ++Ans;
//        }
//    }
//
//    return Ans;
//}
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> n >> s >> k;
//        for (int i = 1; i <= n; ++i)
//        {
//            gr[i].clear();
//            Nodes[i].clear();
//        }
//
//        for (int i = 0; i < n - 1; ++i)
//        {
//            int a, b;
//            std::cin >> a >> b;
//            gr[a].push_back(b);
//            gr[b].push_back(a);
//        }
//
//        DFS(s, -1, 0);
//        std::cout << Solve() << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//
//int main()
//{
//    constexpr int MaxN = 10 + 5;
//    std::array<std::string, MaxN> Grid;
//
//    int T;
//    std::cin >> T;
//    for (int NO = 1; NO <= T; ++NO)
//    {
//        int n;
//        std::cin >> n;
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> Grid[i];
//        }
//
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                if (Grid[i][j] == '.')
//                {
//                    for (char ch = 'A'; ch <= 'Z'; ++ch)
//                    {
//                        bool OK = true;
//                        if (i > 0 && Grid[i - 1][j] == ch)
//                        {
//                            OK = false;
//                        }
//                        if (i < n - 1 && Grid[i + 1][j] == ch)
//                        {
//                            OK = false;
//                        }
//                        if (j > 0 && Grid[i][j - 1] == ch)
//                        {
//                            OK = false;
//                        }
//                        if (j < n - 1 && Grid[i][j + 1] == ch)
//                        {
//                            OK = false;
//                        }
//
//                        if (OK)
//                        {
//                            Grid[i][j] = ch;
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//
//        std::cout << "Case " << NO << ":\n";
//        for (int i = 0; i < n; ++i)
//        {
//            std::cout << Grid[i] << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cmath>
//#include <algorithm>
//
//const double PI = std::acos(-1.0);
//constexpr int MaxN = 10000 + 5;
//constexpr double EPS = 1e-5;
//
//int n, f;
//std::array<double, MaxN> A;
//
//bool OK(double Area)
//{
//    int Sum = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        Sum += static_cast<int>(A[i] / Area);
//    }
//
//    return Sum >= f + 1;
//}
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> n >> f;
//        double MaxA = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            int r;
//            std::cin >> r;
//            A[i] = PI * r * r;
//            MaxA = std::max(MaxA, A[i]);
//        }
//        
//        double L = 0, R = MaxA;
//        while (R - L > EPS)
//        {
//            auto M = (L + R) / 2;
//            if (OK(M))
//            {
//                L = M;
//            }
//            else
//            {
//                R = M;
//            }
//        }
//
//        std::printf("%.5lf\n", L);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//class num
//{
//public:
//    int a, c, l, r;
//
//    num() = default;
//    num(int a, int c, int l, int r) :
//        a(a), c(c), l(l), r(r)
//    {
//    }
//};
//
//int main()
//{
//    int a, c, l, r;
//    int N, S;
//    std::cin >> N >> S;
//    std::vector<num> Num;
//    int Sum = 0;
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> a >> c >> l >> r;
//        Num.emplace_back(a, c, l, r);
//        Sum += a;
//    }
//    std::sort(Num.begin(), Num.end(), [](const num &a, const num &b) 
//    {
//        return a.c < b.c;
//    });
//
//    int Cost = 0;
//    bool OK = false;
//    for (const auto &r : Num)
//    {
//        if (Sum == S)
//        {
//            OK = true;
//            break;
//        }
//        else if (Sum < S)
//        {
//            int Delta = r.r - r.a;
//            if (Delta < S - Sum)
//            {
//                Sum += Delta;
//                Cost += r.c * Delta;
//            }
//            else if (Delta >= S - Sum)
//            {
//                Cost += r.c * (S - Sum);
//                OK = true;
//                break;
//            }
//        }
//        else
//        {
//            int Delta = r.a - r.l;
//            if (Delta < Sum - S)
//            {
//                Sum -= Delta;
//                Cost += r.c * Delta;
//            }
//            else if (Delta >= Sum - S)
//            {
//                Cost += r.c * (Sum - S);
//                OK = true;
//                break;
//            }
//        }
//    }
//
//    if (OK)
//    {
//        std::cout << Cost << std::endl;
//    }
//    else
//    {
//        std::puts("impossible");
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <sstream>
//
//using ll = long long;
//
//int main()
//{
//    std::string Str;
//    std::getline(std::cin, Str);
//    std::stringstream ss(Str);
//
//    ll Sum = 0, n;
//    while (ss >> n)
//    {
//        Sum += n;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//int main()
//{
//    ll Sum = 0, n;
//    while (std::cin >> n)
//    {
//        Sum += n;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int a, b;
//    std::cin >> a >> b;
//    std::cout << a + b << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//
//struct tree
//{
//    char Root, Left, Right;
//};
//
//std::array<tree, 30> Tree;
//
//int n;
//
//void Print(char t)
//{
//    if (t == '*')
//    {
//        return;
//    }
//    else
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            if (Tree[i].Root == t)
//            {
//                std::putchar(t);
//                Print(Tree[i].Left);
//                Print(Tree[i].Right);
//            }
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> n;
//    
//    std::string Str;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Str;
//        Tree[i].Root = Str[0];
//        Tree[i].Left = Str[1];
//        Tree[i].Right = Str[2];
//    }
//
//    Print(Tree[0].Root);
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <unordered_map>
//#include <vector>
//#include <algorithm>
//#include <array>
//
//int cnt;
//std::unordered_map<std::string, int> id;
//int ID(const std::string &s)
//{
//    if (!id.count(s))
//    {
//        id[s] = cnt++;
//    }
//
//    return id[s];
//}
//
//constexpr int MaxN = 1000 + 5;
//
//class Component
//{
//public:
//    int Price;
//    int Quality;
//
//    Component() = default;
//    Component(int Price, int Quality) :
//        Price(Price), Quality(Quality)
//    {
//    }
//};
//
//int b;
//std::array<std::vector<Component>, MaxN> Comp;
//bool OK(int q)
//{
//    int Sum = 0;
//    for (int i = 0; i < cnt; ++i)
//    {
//        int Cheapest = b + 1;
//        for (const auto &r : Comp[i])
//        {
//            if (r.Quality >= q)
//            {
//                Cheapest = std::min(Cheapest, r.Price);
//            }
//        }
//
//        if (Cheapest == b + 1)
//        {
//            return false;
//        }
//
//        Sum += Cheapest;
//        if (Sum > b)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        int n;
//        std::cin >> n >> b;
//        for (int i = 0; i < n; ++i)
//        {
//            Comp[i].clear();
//        }
//        cnt = 0;
//        id.clear();
//
//        int MaxQ = 0;
//        std::string Type, Name;
//        for (int i = 0; i < n; ++i)
//        {
//            int p, q;
//            std::cin >> Type >> Name >> p >> q;
//            MaxQ = std::max(MaxQ, q);
//            Comp[ID(Type)].emplace_back(p, q);
//        }
//
//        int L = 0, R = MaxQ;
//        while (L < R)
//        {
//            int M = L + (R - L + 1) / 2;
//            if (OK(M))
//            {
//                L = M;
//            }
//            else
//            {
//                R = M - 1;
//            }
//        }
//
//        std::cout << L << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//template <typename T>
//ll f(const T &P, int i, int Final)
//{
//    if (i == 0)
//    {
//        return 0;
//    }
//    else if (P[i] == Final)
//    {
//        return f(P, i - 1, Final);
//    }
//    else
//    {
//        return f(P, i - 1, 6 - P[i] - Final) + (1LL << (i - 1));
//    }
//}
//
//int main()
//{
//    constexpr int MaxN = 60 + 5;
//    int n;
//    std::array<int, MaxN> Start{ 0 }, Finish{ 0 };
//    int NO = 0;
//    while (std::cin >> n && n)
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            std::cin >> Start[i];
//        }
//        for (int i = 1; i <= n; ++i)
//        {
//            std::cin >> Finish[i];
//        }
//
//        int k = n;
//        while (k >= 1 && Start[k] == Finish[k])
//        {
//            --k;
//        }
//
//        ll Ans = 0;
//        if (k >= 1)
//        {
//            int Other = 6 - Start[k] - Finish[k];
//            Ans = f(Start, k - 1, Other) + f(Finish, k - 1, Other) + 1;
//        }
//    
//        std::cout << "Case " << ++NO << ": " << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n, m;
//    std::cin >> n >> m;
//    int a[100000], b[100000];
//    for (int i = 1; i <= n; ++i)
//    {
//        a[i] = Read();
//    }
//    for (int i = 1; i <= m; ++i)
//    {
//        b[i] = Read();
//    }
//
//    int top1 = 1, top2 = 1;
//    int cnt1 = a[1], cnt2 = b[1];
//    int cnt = 0;
//    while (1)
//    {
//        if (cnt1 == cnt2)
//        {
//            ++cnt;
//            if (top1 == n || top2 == m)
//            {
//                break;
//            }
//
//            cnt1 = a[++top1];
//            cnt2 = b[++top2];
//        }
//        else if (cnt1 < cnt2)
//        {
//            cnt1 += a[++top1];
//        }
//        else
//        {
//            cnt2 += b[++top2];
//        }
//    }
//
//    std::cout << cnt << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//int main()
//{
//    int a, b, c;
//    std::cin >> a >> b >> c;
//    int Temp = std::abs(a - b);
//    if (Temp <= c)
//    {
//        std::cout << 2 * std::max(a, b) + (c - Temp) / 2 * 2 << std::endl;
//    }
//    else
//    {
//        std::cout << 2 * std::min(a, b) + c * 2 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int f(int n)
//{
//    if (n == 1)
//    {
//        return 1;
//    }
//    else
//    {
//        return f(n / 2) + 1;
//    }
//}
//
//int main()
//{
//    int n;
//    while (std::cin >> n)
//    {
//        std::cout << f(n) << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <array>
//
//std::array<std::string, 34> mahjong
//{ 
//    "1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
//    "1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
//    "1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
//    "DONG", "NAN", "XI", "BEI", 
//    "ZHONG", "FA", "BAI"
//};
//
//int Convert(const std::string &s)
//{
//    for (int i = 0; i < 34; ++i)
//    {
//        if (mahjong[i] == s)
//        {
//            return i;
//        }
//    }
//
//    return -1;
//}
//
//std::array<int, 34> c{ 0 };
//bool Search(int Dep)
//{
//    for (int i = 0; i < 34; ++i)
//    {
//        if (c[i] >= 3)
//        {
//            if (Dep == 3)
//            {
//                return true;
//            }
//
//            c[i] -= 3;
//            if (Search(Dep + 1))
//            {
//                return true;
//            }
//            c[i] += 3;
//        }
//    }
//
//    for (int i = 0; i <= 24; ++i)
//    {
//        if (i % 9 <= 6 && c[i] >= 1 && c[i + 1] >= 1 && c[i + 2] >= 1)
//        {
//            if (Dep == 3)
//            {
//                return true;
//            }
//
//            --c[i];
//            --c[i + 1];
//            --c[i + 2];
//            if (Search(Dep + 1))
//            {
//                return true;
//            }
//            ++c[i];
//            ++c[i + 1];
//            ++c[i + 2];
//        }
//    }
//
//    return false;
//}
//
//bool Check()
//{
//    for (int i = 0; i < 34; ++i)
//    {
//        if (c[i] >= 2)
//        {
//            c[i] -= 2;
//            if (Search(0))
//            {
//                return true;
//            }
//            c[i] += 2;
//        }
//    }
//
//    return false;
//}
//
//int main()
//{
//    int NO = 0;
//    std::string s;
//    while (std::cin >> s && s[0] != '0')
//    {
//        std::cout << "Case " << ++NO << ":";
//
//        std::array<int, 15> mj{ 0 };
//        mj[0] = Convert(s);
//        for (int i = 1; i < 13; ++i)
//        {
//            std::cin >> s;
//            mj[i] = Convert(s);
//        }
//
//        bool OK = false;
//        for (int i = 0; i < 34; ++i)
//        {
//            std::fill(c.begin(), c.end(), 0);
//            for (int j = 0; j < 13; ++j)
//            {
//                ++c[mj[j]];
//            }
//
//            if (c[i] < 4)
//            {
//                ++c[i];
//                if (Check())
//                {
//                    OK = true;
//                    std::cout << " " << mahjong[i];
//                }
//                --c[i];
//            }
//        }
//
//        if (!OK)
//        {
//            std::cout << " Not ready";
//        }
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//constexpr int MaxN = 200000;
//
//int n, m, cnt = 0;
//
//struct edge
//{
//    int t, Next;
//};
//std::array<edge, MaxN + 5> Edge;
//
//std::array<int, MaxN> Head{ 0 }, Col{ 0 };
//std::array<bool, MaxN> Used{ false };
//std::array<int, 2> Sum{ 0 };
//
//void Add(int a, int b)
//{
//    ++cnt;
//    Edge[cnt].t = b;
//    Edge[cnt].Next = Head[a];
//    Head[a] = cnt;
//}
//
//bool DFS(int Node, int Color)
//{
//    if (Used[Node])
//    {
//        if (Col[Node] == Color)
//        {
//            return true;
//        }
//
//        return false;
//    }
//
//    Used[Node] = true;
//    Col[Node] = Color;
//    ++Sum[Color];
//
//    bool OK = true;
//    for (int i = Head[Node]; i && OK; i = Edge[i].Next)
//    {
//        OK = OK && DFS(Edge[i].t, !Color);
//    }
//
//    return OK;
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    n = Read();
//    m = Read();
//    for (int i = 0; i < m; ++i)
//    {
//        int a, b;
//        a = Read();
//        b = Read();
//        Add(a, b);
//        Add(b, a);
//    }
//
//    int Ans = 0;
//    for (int i = 1; i <= n; ++i)
//    {
//        if (!Used[i])
//        {
//            Sum[0] = Sum[1] = 0;
//            if (!DFS(i, 0))
//            {
//                std::puts("Impossible");
//                goto Outside;
//            }
//
//            Ans += std::min(Sum[0], Sum[1]);
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//Outside:
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//std::array<int, 200000 + 5> p{ 0 }, d{ 0 };
//
//int Find(int x)
//{
//    if (p[x] == x)
//    {
//        return x;
//    }
//    else
//    {
//        auto Last = p[x];
//        p[x] = Find(p[x]);
//        d[x] += d[Last];
//
//        return p[x];
//    }
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    for (int i = 1; i <= n; ++i)
//    {
//        p[i] = i;
//    }
//
//    int Ans = 1 << 28;
//    for (int i = 1; i <= n; ++i)
//    {
//        int t;
//        t = Read();
//        auto x = Find(i);
//        auto y = Find(t);
//        if (x != y)
//        {
//            p[x] = y;
//            d[i] = d[t] + 1;
//        }
//        else
//        {
//            Ans = std::min(Ans, d[i] + d[t] + 1);
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//constexpr int MaxN = 4;
//int n, Ans, Dice[MaxN][6];
//
//int Dice24[24][6] = 
//{
//{ 2, 1, 5, 0, 4, 3 },
//{ 2, 0, 1, 4, 5, 3 },
//{ 2, 4, 0, 5, 1, 3 },
//{ 2, 5, 4, 1, 0, 3 },
//{ 4, 2, 5, 0, 3, 1 },
//{ 5, 2, 1, 4, 3, 0 },
//{ 1, 2, 0, 5, 3, 4 },
//{ 0, 2, 4, 1, 3, 5 },
//{ 0, 1, 2, 3, 4, 5 },
//{ 4, 0, 2, 3, 5, 1 },
//{ 5, 4, 2, 3, 1, 0 },
//{ 1, 5, 2, 3, 0, 4 },
//{ 5, 1, 3, 2, 4, 0 },
//{ 1, 0, 3, 2, 5, 4 },
//{ 0, 4, 3, 2, 1, 5 },
//{ 4, 5, 3, 2, 0, 1 },
//{ 1, 3, 5, 0, 2, 4 },
//{ 0, 3, 1, 4, 2, 5 },
//{ 4, 3, 0, 5, 2, 1 },
//{ 5, 3, 4, 1, 2, 0 },
//{ 3, 4, 5, 0, 1, 2 },
//{ 3, 5, 1, 4, 0, 2 },
//{ 3, 1, 0, 5, 4, 2 },
//{ 3, 0, 4, 1, 5, 2 },
//};
//
//std::vector<std::string> Names;
//int ID(const std::string &Name)
//{
//    for (std::size_t i = 0; i < Names.size(); ++i)
//    {
//        if (Names[i] == Name)
//        {
//            return i;
//        }
//    }
//
//    Names.push_back(Name);
//    return Names.size() - 1;
//}
//
//int r[MaxN], Color[MaxN][6];
//
//void Check()
//{
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < 6; ++j)
//        {
//            Color[i][Dice24[r[i]][j]] = Dice[i][j];
//        }
//    }
//
//    int Tot = 0;
//    for (int j = 0; j < 6; ++j)
//    {
//        int cnt[MaxN * 6];
//        std::memset(cnt, 0, sizeof(cnt));
//        int MaxFace = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            MaxFace = std::max(MaxFace, ++cnt[Color[i][j]]);
//        }
//
//        Tot += n - MaxFace;
//    }
//
//    Ans = std::min(Ans, Tot);
//}
//
//void DFS(int d)
//{
//    if (d == n)
//    {
//        Check();
//    }
//    else
//    {
//        for (int i = 0; i < 24; ++i)
//        {
//            r[d] = i;
//            DFS(d + 1);
//        }
//    }
//}
//
//int main()
//{
//    while (std::cin >> n && n)
//    {
//        Names.clear();
//        std::string Name;
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < 6; ++j)
//            {
//                std::cin >> Name;
//                Dice[i][j] = ID(Name);
//            }
//        }
//
//        Ans = n * 6;
//        r[0] = 0;
//        DFS(1);
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//
//int Left[] = { 4, 0, 2, 3, 5, 1 };
//int Up[] = { 2, 1, 5, 0, 4, 3 };
//
//void Rot(int *T, int *p)
//{
//    int q[6];
//    std::memcpy(q, p, sizeof(q));
//    for (int i = 0; i < 6; ++i)
//    {
//        p[i] = T[q[i]];
//    }
//}
//
//void EnumeratePermutations()
//{
//    int p0[] = { 0, 1, 2, 3, 4, 5 };
//    std::printf("int dice[24][6] = {\n");
//    for (int i = 0; i < 6; ++i)
//    {
//        int p[6];
//        std::memcpy(p, p0, sizeof(p0));
//        if (i == 0)
//        {
//            Rot(Up, p);
//        }
//        if (i == 1)
//        {
//            Rot(Left, p);
//            Rot(Up, p);
//        }
//        if (i == 3)
//        {
//            Rot(Up, p);
//            Rot(Up, p);
//        }
//        if (i == 4)
//        {
//            Rot(Left, p);
//            Rot(Left, p);
//            Rot(Left, p);
//            Rot(Up, p);
//        }
//        if (i == 5)
//        {
//            Rot(Left, p);
//            Rot(Left, p);
//            Rot(Up, p);
//        }
//
//        for (int j = 0; j < 4; ++j)
//        {
//            std::printf("{ %d, %d, %d, %d, %d, %d }, \n", p[0], p[1], p[2], p[3], p[4], p[5]);
//            Rot(Left, p);
//        }
//    }
//
//    std::puts("};");
//}
//
//int main()
//{
//    EnumeratePermutations();
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using ll = __int128;
//
//ll f[100][100] = { 0 };
//ll Num[100] = { 0 }, p[100] = { 0 };
//
//int n, m;
//
//ll DP(int L, int R)
//{
//    if (f[L][R])
//    {
//        return f[L][R];
//    }
//
//    if (R > L)
//    {
//        return f[L][R] = std::max(Num[L] * p[m - R + L] + DP(L + 1, R),
//                           Num[R] * p[m - R + L] + DP(L, R - 1));
//    }
//    else
//    {
//        return f[L][R] = Num[L] * p[m];
//    }
//}
//
//void Print(ll x)
//{
//    if (!x)
//    {
//        return;
//    }
//    else if (x)
//    {
//        Print(x / 10);
//    }
//
//    std::putchar(x % 10 + '0');
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    n = Read();
//    m = Read();
//
//    p[0] = 1;
//    for (int i = 1; i <= m; ++i)
//    {
//        p[i] = 2 * p[i - 1];
//    }
//
//    ll Ans = 0;
//    for (int i = 1; i <= n; ++i)
//    {
//        std::memset(f, 0, sizeof(f));
//        for (int j = 1; j <= m; ++j)
//        {
//            Num[j] = Read();
//        }
//
//        Ans += DP(1, m);
//    }
//
//    if (Ans == 0)
//    {
//        std::cout << 0 << std::endl;
//    }
//    else
//    {
//        Print(Ans);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//constexpr int MaxN = 20;
//constexpr int INF = 999999999;
//
//int n;
//std::array<std::array<int, MaxN>, MaxN> A{ 0 }, B{ 0 };
//
//int Check(int s)
//{
//    for (auto &rr : B)
//    {
//        for (auto &r : rr)
//        {
//            r = 0;
//        }
//    }
//
//    for (int c = 0; c < n; ++c)
//    {
//        if (s & (1 << c))
//        {
//            B[0][c] = 1;
//        }
//        else if (A[0][c] == 1)
//        {
//            return INF;
//        }
//    }
//
//    for (int r = 1; r < n; ++r)
//    {
//        for (int c = 0; c < n; ++c)
//        {
//            int Sum = 0;
//            if (r > 1)
//            {
//                Sum += B[r - 2][c];
//            }
//            if (c > 0)
//            {
//                Sum += B[r - 1][c - 1];
//            }
//            if (c < n - 1)
//            {
//                Sum += B[r - 1][c + 1];
//            }
//
//            B[r][c] = Sum % 2;
//            if (A[r][c] == 1 && B[r][c] == 0)
//            {
//                return INF;
//            }
//        }
//    }
//
//    int cnt = 0;
//    for (int r = 0; r < n; ++r)
//    {
//        for (int c = 0; c < n; ++c)
//        {
//            if (A[r][c] != B[r][c])
//            {
//                ++cnt;
//            }
//        }
//    }
//
//    return cnt;
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int T;
//    T = Read();
//    for (int NO = 1; NO <= T; ++NO)
//    {
//        n = Read();
//        for (int r = 0; r < n; ++r)
//        {
//            for (int c = 0; c < n; ++c)
//            {
//                A[r][c] = Read();
//            }
//        }
//
//        int Ans = INF;
//        for (int s = 0; s < (1 << n); ++s)
//        {
//            Ans = std::min(Ans, Check(s));
//        }
//        if (Ans == INF)
//        {
//            Ans = -1;
//        }
//
//        std::cout << "Case " << NO << ": " << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include <vector>
//
//int n, m;
//std::array<int, 10000 + 5> p{ 0 };
//
//class Edge
//{
//public:
//    int u, v, d;
//
//    Edge() = default;
//    Edge(int u, int v, int d) :
//        u(u), v(v), d(d)
//    {
//    }
//};
//
//std::vector<Edge> e;
//
//int Find(int x)
//{
//    if (p[x] == x)
//    {
//        return x;
//    }
//    else
//    {
//        return p[x] = Find(p[x]);
//    }
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = std::getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//    {
//        ch = std::getchar();
//    }
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = std::getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = std::getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    n = Read();
//    m = Read();
//    for (int i = 0; i < n; ++i)
//    {
//        p[i] = i;
//    }
//
//    for (int i = 0; i < m; ++i)
//    {
//        int u, v, d;
//        u = Read();
//        v = Read();
//        d = Read();
//        e.emplace_back(u, v, d);
//    }
//
//    std::sort(e.begin(), e.end(), [](const Edge &a, const Edge &b)
//    {
//        return a.d < b.d;
//    });
//
//    int cnt = n;
//    for (int i = 0; i < m; ++i)
//    {
//        auto u = Find(e[i].u);
//        auto v = Find(e[i].v);
//        if (u != v)
//        {
//            p[u] = v;
//            --cnt;
//
//            if (cnt == 1)
//            {
//                std::cout << n - 1 << ' ' << e[i].d << std::endl;
//                break;
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//constexpr int MaxN = 10;
//int n;
//std::array<std::array<std::array<char, MaxN>, MaxN>, MaxN> Pos, View;
//
//char ReadChar()
//{
//    char ch;
//    while (1)
//    {
//        ch = std::getchar();
//        if ((ch >= 'A' && ch <= 'Z') || ch == '.')
//        {
//            return ch;
//        }
//    }
//}
//
//void Get(int k, int i, int j, int len, int &x, int &y, int &z)
//{
//    if (k == 0)
//    {
//        x = len;
//        y = j;
//        z = i;
//    }
//    else if (k == 1)
//    {
//        x = n - 1 - j;
//        y = len;
//        z = i;
//    }
//    else if (k == 2)
//    {
//        x = n - 1 - len;
//        y = n - 1 - j;
//        z = i;
//    }
//    else if (k == 3)
//    {
//        x = j;
//        y = n - 1 - len;
//        z = i;
//    }
//    else if (k == 4)
//    {
//        x = n - 1 - i;
//        y = j;
//        z = len;
//    }
//    else
//    {
//        x = i;
//        y = j;
//        z = n - 1 - len;
//    }
//}
//
//int main()
//{
//    while (std::cin >> n && n)
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            for (int k = 0; k < 6; ++k)
//            {
//                for (int j = 0; j < n; ++j)
//                {
//                    View[k][i][j] = ReadChar();
//                }
//            }
//        }
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                for (int k = 0; k < n; ++k)
//                {
//                    Pos[i][j][k] = '#';
//                }
//            }
//        }
//
//        for (int k = 0; k < 6; ++k)
//        {
//            for (int i = 0; i < n; ++i)
//            {
//                for (int j = 0; j < n; ++j)
//                {
//                    if (View[k][i][j] == '.')
//                    {
//                        for (int p = 0; p < n; ++p)
//                        {
//                            int x, y, z;
//                            Get(k, i, j, p, x, y, z);
//                            Pos[x][y][z] = '.';
//                        }
//                    }
//                }
//            }
//        }
//
//        while (1)
//        {
//            bool Done = true;
//            for (int k = 0; k < 6; ++k)
//            {
//                for (int i = 0; i < n; ++i)
//                {
//                    for (int j = 0; j < n; ++j)
//                    {
//                        if (View[k][i][j] != '.')
//                        {
//                            for (int p = 0; p < n; ++p)
//                            {
//                                int x, y, z;
//                                Get(k, i, j, p, x, y, z);
//                                if (Pos[x][y][z] == '.')
//                                {
//                                    continue;
//                                }
//                                if (Pos[x][y][z] == '#')
//                                {
//                                    Pos[x][y][z] = View[k][i][j];
//                                    break;
//                                }
//
//                                if (Pos[x][y][z] == View[k][i][j])
//                                {
//                                    break;
//                                }
//
//                                Pos[x][y][z] = '.';
//                                Done = false;
//                            }
//                        }
//                    }
//                }
//            }
//
//            if (Done)
//            {
//                break;
//            }
//        }
//
//        int Ans = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                for (int k = 0; k < n; ++k)
//                {
//                    if (Pos[i][j][k] != '.')
//                    {
//                        ++Ans;
//                    }
//                }
//            }
//        }
//
//        std::cout << "Maximum weight: " << Ans << " gram(s)" << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <utility>
//#include <algorithm>
//#include <array>
//
//constexpr int MaxN = 10000 + 5;
//
//class Ant
//{
//public:
//    int id, p, d;
//
//    Ant() = default;
//    Ant(int id, int p, int d) :
//        id(id), p(p), d(d)
//    {
//    }
//};
//std::array<Ant, MaxN> Before, After;
//
//constexpr char *DirName[10] = { const_cast<char*>("L"), 
//                                const_cast<char*>("Turning"), 
//                                const_cast<char*>("R") };
//std::array<int, MaxN> Order;
//
//int main()
//{
//    int K;
//    std::cin >> K;
//    for (int NO = 1; NO <= K; ++NO)
//    {
//        std::cout << "Case #" << NO << ":\n";
//
//        int L, T, n;
//        std::cin >> L >> T >> n;
//
//        for (int i = 0; i < n; ++i)
//        {
//            int p, d;
//            char c;
//            std::cin >> p >> c;
//            d = (c == 'L' ? -1 : 1);
//            Before[i] = std::move(Ant(i, p, d));
//            After[i] = std::move(Ant(0, p + T * d, d));
//        }
//
//        std::sort(Before.begin(), Before.begin() + n, [](const Ant &a, const Ant &b) 
//        {
//            return a.p < b.p;
//        });
//        for (int i = 0; i < n; ++i)
//        {
//            Order[Before[i].id] = i;
//        }
//
//        std::sort(After.begin(), After.begin() + n, [](const Ant &a, const Ant &b)
//        {
//            return a.p < b.p;
//        });
//        for (int i = 0; i < n - 1; ++i)
//        {
//            if (After[i].p == After[i + 1].p)
//            {
//                After[i].d = After[i + 1].d = 0;
//            }
//        }
//
//        for (int i = 0; i < n; ++i)
//        {
//            int a = Order[i];
//            if (After[a].p < 0 || After[a].p > L)
//            {
//                std::cout << "Fell off" << std::endl;
//            }
//            else
//            {
//                std::cout << After[a].p << ' ' << DirName[After[a].d + 1] << std::endl;
//            }
//        }
//
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    int n, m;
//    while (std::cin >> n >> m)
//    {
//        double Ans = 0.0;
//        for (int i = 0; i < n; ++i)
//        {
//            double Pos = static_cast<double>(i) / n * (n + m);
//            Ans += std::abs(Pos - std::floor(Pos + 0.5)) / (n + m);
//        }
//
//        std::printf("%.4lf\n", Ans * 10000);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//using ll = long long;
//
//constexpr int MaxN = 1000000 + 10;
//
//std::array<ll, MaxN> A{ 0 }, C{ 0 };
//ll Tot, M;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n;
//    while (std::cin >> n)
//    {
//        Tot = 0;
//        for (int i = 1; i <= n; ++i)
//        {
//            A[i] = Read();
//            Tot += A[i];
//        }
//
//        M = Tot / n;
//        C[0] = 0;
//        for (int i = 1; i < n; ++i)
//        {
//            C[i] = C[i - 1] + A[i] - M;
//        }
//        std::sort(C.begin(), C.begin() + n);
//
//        ll x1 = C[n / 2], Ans = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            Ans += std::abs(x1 - C[i]);
//        }
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//struct Job
//{
//    int j, b;
//
//    Job() = default;
//    Job(int j, int b) :
//        j(j), b(b)
//    {
//    }
//};
//
//int main()
//{
//    int n, NO = 0;
//    while (std::cin >> n && n)
//    {
//        int b, j;
//        std::vector<Job> v;
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> b >> j;
//            v.emplace_back(j, b);
//        }
//
//        std::sort(v.begin(), v.end(), [](const Job &a, const Job &b)
//        {
//            return a.j > b.j;
//        });
//
//        int s = 0, Ans = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            s += v[i].b;
//            Ans = std::max(Ans, s + v[i].j);
//        }
//
//        std::cout << "Case " << ++NO << ": " << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    int n, m;
//    while (std::cin >> n >> m && n)
//    {
//        std::array<int, 50000> A{ 0 }, B{ 0 };
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> A[i];
//        }
//        for (int i = 0; i < m; ++i)
//        {
//            std::cin >> B[i];
//        }
//
//        std::sort(A.begin(), A.begin() + n);
//        std::sort(B.begin(), B.begin() + m);
//        int Cur = 0, Cost = 0;
//        for (int i = 0; i < m; ++i)
//        {
//            if (B[i] >= A[Cur])
//            {
//                Cost += B[i];
//                ++Cur;
//
//                if (Cur == n)
//                {
//                    break;
//                }
//            }
//        }
//
//        if (Cur < n)
//        {
//            std::cout << "Loowater is doomed!" << std::endl;
//        }
//        else
//        {
//            std::cout << Cost << std::endl;
//        }
//    }
//
//    return 0;
//}
//// 看了各位大佬的题解，可能对于初学者来说还有点不太好懂
//// 我想写一篇简明扼要的题解，希望能对大家理解此题有所帮助
//// 首先这道题利用了二进制的特点
//// 而一想到二进制，就会联想起位运算
//// 然后移位操作又能很好地帮助我们取得一个二进制数中任意一位的1
//// 这个1的位置即使2^n中的n
//// 有了这个铺垫，这一题就很好做了
//#include <iostream>
//
//void Solve(int n)
//{
//    bool NotFirst = false;  // 因为第一次不需要输出+号，所以得特判一下
//    for (int i = 15; i >= 0; --i)   // 这里是枚举2^i中的i
//    {                               // 2^15为32768，足够表示20000以内的数了
//        if (n & (1 << i))   // 检查n的二进制表示法中第i位是否为1，注意要从高到低位检查
//        {
//            if (NotFirst)
//            {
//                std::cout << '+';
//            }
//            NotFirst = true;    // 现在就不是第一次了
//
//            if (i == 0) // 2^0的情况，依题意
//            {
//                std::cout << "2(0)";
//            }
//            else if (i == 1)    // 2^1的情况，依题意
//            {
//                std::cout << "2";
//            }
//            else   // 如果都不是，那就递归继续分解
//            {
//                std::cout << "2(";
//                Solve(i);
//                std::cout << ")";
//            }
//        }
//    }
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    Solve(n);
//
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//constexpr int MaxN = 100 + 5;
//constexpr int INF = 999999999;
//
//int main()
//{
//    std::array<std::array<int, MaxN>, MaxN> d{ 0 };
//
//    int n, m, t, NO = 0;
//    while (std::cin >> n >> m >> t && n)
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            d[i][i] = 0;
//            for (int j = i + 1; j < n; ++j)
//            {
//                d[i][j] = d[j][i] = INF;
//            }
//        }
//
//        int u, v, w;
//        for (int i = 0; i < m; ++i)
//        {
//            std::cin >> u >> v >> w;
//            --u;
//            --v;
//
//            d[u][v] = d[v][u] = w;
//        }
//
//        for (int k = 0; k < n; ++k)
//        {
//            for (int i = 0; i < n; ++i)
//            {
//                for (int j = 0; j < n; ++j)
//                {
//                    if (d[i][k] < INF && d[k][j] < INF)
//                    {
//                        d[i][j] = std::min(d[i][j], std::max(d[i][k], d[k][j]));
//                    }
//                }
//            }
//        }
//
//        if (NO)
//        {
//            std::putchar('\n');
//        }
//        std::cout << "Case #" << ++NO << std::endl;
//
//        while (t--)
//        {
//            std::cin >> u >> v;
//            --u;
//            --v;
//            if (d[u][v] == INF)
//            {
//                std::puts("no path");
//            }
//            else
//            {
//                std::cout << d[u][v] << std::endl;
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//#include <vector>
//
//std::vector<std::string> Names;
//int ID(const std::string &s)
//{
//    for (std::size_t i = 0; i < Names.size(); ++i)
//    {
//        if (Names[i] == s)
//        {
//            return i;
//        }
//    }
//
//    Names.push_back(s);
//    return Names.size() - 1;
//}
//
//constexpr int MaxN = 25 + 5;
//int n, m;
//std::array<bool, MaxN> Vis{ false };
//std::array<std::array<bool, MaxN>, MaxN> d{ false };
//
//void DFS(int u)
//{
//    Vis[u] = true;
//    for (int v = 0; v < n; ++v)
//    {
//        if (!Vis[v] && d[u][v] && d[v][u])
//        {
//            std::cout << ", " << Names[v];
//            DFS(v);
//        }
//    }
//}
//
//int main()
//{
//    int NO = 0;
//    while (std::cin >> n >> m && n)
//    {
//        Names.clear();
//        for (auto &rr : d)
//        {
//            for (auto &r : rr)
//            {
//                r = false;
//            }
//        }
//        for (int i = 0; i < n; ++i)
//        {
//            d[i][i] = true;
//        }
//
//        std::string s1, s2;
//        while (m--)
//        {
//            std::cin >> s1 >> s2;
//            d[ID(s1)][ID(s2)] = true;
//        }
//
//        for (int k = 0; k < n; ++k)
//        {
//            for (int i = 0; i < n; ++i)
//            {
//                for (int j = 0; j < n; ++j)
//                {
//                    d[i][j] |= d[i][k] && d[k][j];
//                }
//            }
//        }
//
//        if (NO > 0)
//        {
//            std::putchar('\n');
//        }
//        std::cout << "Calling circles for data set " << ++NO << ":\n";
//
//        for (auto &r : Vis)
//        {
//            r = false;
//        }
//        for (int i = 0; i < n; ++i)
//        {
//            if (!Vis[i])
//            {
//                std::cout << Names[i];
//                DFS(i);
//                std::putchar('\n');
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n;
//    n = Read();
//
//    static int DP[1 << 20][21], Map[1 << 5][1 << 5];
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            Map[i][j] = Read();
//        }
//    }
//
//    std::memset(DP, (1 << 6) - 1, sizeof(DP));
//    DP[1][0] = 0;
//    for (int i = 0; i < (1 << n) - 1; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            if (((1 << j) & i) == 0)
//            {
//                for (int k = 0; k < n; ++k)
//                {
//                    if ((1 << k) & i)
//                    {
//                        DP[(1 << j) | i][j] = std::min(DP[(1 << j) | i][j],
//                                                       DP[i][k] + Map[k][j]);
//                    }
//                }
//            }
//        }
//    }
//
//    int Ans = 2146483647;
//    for (int i = 1; i < n; ++i)
//    {
//        Ans = std::min(Ans, DP[(1 << n) - 1][i] + Map[i][0]);
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//// 这一题考的是最小生成树
//// 具体的解释还是看紫书P358比较好
//// 我只是代码的搬运工，并且写一点注释供大家参考
//// 希望能对大家理解这一题提供一点点的帮助
//#include <iostream>
//#include <algorithm>
//#include <array>
//#include <vector>
//
//constexpr int MaxN = 1000 + 10;
//constexpr int MaxQ = 8;
//
//int n;
//std::array<int, MaxN> x{ 0 }, y{ 0 }, p{ 0 };
//std::array<int, MaxQ> Cost{ 0 };
//std::array<std::vector<int>, MaxQ> SubN;
//
//int Find(int x)
//{
//    return p[x] != x ? p[x] = Find(p[x]) : x;
//}
//
//class Edge
//{
//public:
//    int u, v, d;
//
//    Edge() = default;
//    Edge(int u, int v, int d) :
//        u(u), v(v), d(d)
//    {
//    }
//};
//
//// cnt：还剩多少个点没有联通
//// e：边的集合
//// Used：已经联通的边
//template <typename T>
//int MST(int cnt, const T &e, T &Used)
//{
//    if (cnt == 1)
//    {
//        return 0;
//    }
//
//    int Ans = 0;
//    Used.clear();
//    for (std::size_t i = 0; i < e.size(); ++i)  // Kruskal
//    {
//        int u = Find(e[i].u), v = Find(e[i].v);
//        if (u != v)
//        {
//            p[u] = v;
//            Ans += e[i].d;
//            Used.push_back(e[i]);   // 在第一次调用Kruskal时，Used被用来求生成树
//
//            if (--cnt == 1)
//            {
//                break;
//            }
//        }
//    }
//
//    return Ans;
//}
//
//// 快读
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int T;
//    std::cin >> T;  // 共T组数据
//    while (T--)
//    {
//        int q;
//        n = Read(); // 有n条边
//        q = Read(); // 有q种套餐
//        for (int i = 0; i < q; ++i)
//        {
//            int cnt;    // 这个套餐能连cnt个点
//            cnt = Read();
//            Cost[i] = Read();   // 该套餐的花费
//
//            SubN[i].clear();    // 因为有多组数据，所以要记得清空
//            while (cnt--)
//            {
//                int u;
//                u = Read();
//                SubN[i].push_back(u - 1);   // 记录套餐i能连的边
//            }
//        }
//        for (int i = 0; i < n; ++i) // 记录每个点的(x, y)坐标
//        {
//            x[i] = Read();
//            y[i] = Read();
//        }
//
//        std::vector<Edge> e;
//        for (int i = 0; i < n; ++i) // 生成整张图的点边信息
//        {
//            for (int j = i + 1; j < n; ++j)
//            {
//                int c = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
//                e.emplace_back(i, j, c);
//            }
//        }
//        
//        // 排序，为Kruskal做准备
//        std::sort(e.begin(), e.end(), [](const Edge &a, const Edge &b)
//        {
//            return a.d < b.d;
//        });
//
//        for (int i = 0; i < n; ++i)
//        {
//            p[i] = i;
//        }
//        std::vector<Edge> Need; // 求最小生成树里有什么边
//        int Ans = MST(n, e, Need);  // 在没使用套餐之前先求一次最小生成树
//        for (int Mask = 0; Mask < (1 << q); ++Mask) // 枚举每个套餐的使用情况
//        {                                           // 看不懂位运算的可以先去看一下状压
//            for (int i = 0; i < n; ++i) // 每次都重新初始化一次并查集
//            {
//                p[i] = i;
//            }
//
//            int cnt = n, c = 0;
//            for (int i = 0; i < q; ++i)
//            {
//                if (Mask & (1 << i))    // 检验用不用i套餐
//                {
//                    c += Cost[i];   // c是总经费
//                    for (std::size_t j = 1; j < SubN[i].size(); ++j)
//                    {
//                        // 把该套餐中的边都加入生成树中
//                        int u = Find(SubN[i][j]), v = Find(SubN[i][0]);
//                        if (u != v)
//                        {
//                            p[u] = v;
//                            --cnt;
//                        }
//                    }
//                }
//            }
//
//            std::vector<Edge> Dummy;    // 没什么用的变量
//            Ans = std::min(Ans, c + MST(cnt, Need, Dummy));
//        }
//
//        std::cout << Ans << std::endl;
//        if (T)
//        {
//            std::putchar('\n');
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//using ll = long long;
//
//constexpr int N = 50000;
//
//std::array<bool, N + 5> Vis{ false };
//std::array<int, N + 5> Mu{ 0 }, Prime{ 0 }, Sum{ 0 };
//
//void InitMu()
//{
//    Mu[1] = 1;
//    int cnt = 0;
//    for (int i = 2; i < N; ++i)
//    {
//        if (!Vis[i])
//        {
//            Prime[cnt++] = i;
//            Mu[i] = -1;
//        }
//
//        for (int j = 0; j < cnt && i * Prime[j] < N; ++j)
//        {
//            Vis[i * Prime[j]] = true;
//            if (i % Prime[j])
//            {
//                Mu[i * Prime[j]] = -Mu[i];
//            }
//            else
//            {
//                Mu[i * Prime[j]] = 0;
//                break;
//            }
//        }
//    }
//
//    for (int i = 1; i <= N; ++i)
//    {
//        Sum[i] = Sum[i - 1] + Mu[i];
//    }
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    InitMu();
//
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        ll a, b, d;
//        a = Read();
//        b = Read();
//        d = Read();
//
//        ll Ans = 0;
//        a /= d;
//        b /= d;
//        for (ll i = 1; i <= std::min(a, b); )
//        {
//            ll j = std::min(a / (a / i), b / (b / i));
//            Ans += (Sum[j] - Sum[i - 1]) * (a / i) * (b / i);
//            i = j + 1;
//        }
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//constexpr ll MOD = 1000000007;
//
//std::array<ll, 10000000> f{ 0 };
//
//ll PowMod(ll a, ll b, ll n) // “幂取模”的模板，算出a^b % n的值
//{
//    if (!b)
//    {
//        return 1;
//    }
//
//    ll k = PowMod(a, b / 2, n);
//    k = k * k % n;
//
//    if (b % 2)
//    {
//        k = k * a % n;
//    }
//
//    return k;
//}
//
//int main()
//{
//    ll n, K, L, H;
//    std::cin >> n >> K >> L >> H;
//
//    if (L % K == 0)
//    {
//        L /= K;
//    }
//    else
//    {
//        L = L / K + 1;
//    }
//    H /= K;
//
//    for (ll i = 1; i <= H - L; ++i)
//    {
//        ll l = L, r = H;
//        if (l % i == 0)
//        {
//            l /= i;
//        }
//        else
//        {
//            l = l / i + 1;
//        }
//        r /= i;
//
//        f[i] = (PowMod(r - l + 1, n, MOD) - (r - l + 1) + MOD) % MOD;
//    }
//    for (ll i = H - L; i > 0; --i)
//    {
//        for (ll j = i * 2; j <= H - L; j += i)
//        {
//            f[i] = (f[i] - f[j] + MOD) % MOD;
//        }
//    }
//
//    if (L == 1)
//    {
//        f[1] = (f[1] + 1) % MOD;
//    }
//
//    std::cout << f[1] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n, Ans = 0;
//    std::cin >> n;
//    for (int i = 1; i <= n; ++i)
//    {
//        Ans += n / i;
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n, Ans = 0;
//    std::cin >> n;
//
//    int i = 1, j;
//    while (i <= n)
//    {
//        j = n / (n / i);
//        Ans += (n / i) * (j - i + 1);
//        i = j + 1;
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//int main()
//{
//    int n;
//    std::vector<int> Vec;
//    std::cin >> n;
//    while (n > 0)
//    {
//        if (n % 2 == 0)
//        {
//            Vec.push_back(n / 2);
//        }
//        else
//        {
//            Vec.push_back(n / 2 + 1);
//        }
//
//        n /= 2;
//    }
//
//    std::sort(Vec.begin(), Vec.end());
//
//    std::cout << Vec.size() << std::endl;
//    for (const auto &r : Vec)
//    {
//        std::cout << r << ' ';
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<int, 40000 + 5> phi{ 0 };
//    phi[1] = 1;
//    for (int i = 2; i <= 40000; ++i)
//    {
//        if (phi[i] == 0)
//        {
//            for (int j = i; j <= 40000; j += i)
//            {
//                if (phi[j] == 0)
//                {
//                    phi[j] = j;
//                }
//
//                phi[j] = phi[j] / i * (i - 1);
//            }
//        }
//    }
//
//    int n;
//    std::cin >> n;
//    int Sum = 0;
//
//    if (n == 1)
//    {
//        Sum = 0;
//    }
//    else
//    {
//        for (int i = 1; i < n; ++i)
//        {
//            Sum += phi[i] * 2;
//        }
//        ++Sum;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <array>
//
//class Edge
//{
//public:
//    int u, v, d;
//
//    Edge() = default;
//    Edge(int u, int v, int d) :
//        u(u), v(v), d(d)
//    {
//    }
//};
//
//std::vector<Edge> e;
//
//std::array<int, 100 + 5> p{ 0 };
//
//int Find(int x)
//{
//    if (p[x] == x)
//    {
//        return x;
//    }
//    else
//    {
//        return p[x] = Find(p[x]);
//    }
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        p[i] = i;
//        for (int j = 0; j < n; ++j)
//        {
//            int d;
//            d = Read();
//
//            if (i < j)
//            {
//                e.emplace_back(i, j, d);
//            }
//        }
//    }
//    std::sort(e.begin(), e.end(), [](const Edge &a, const Edge &b)
//    {
//        return a.d < b.d;
//    });
//
//    int cnt = n;
//    int Ans = 0;
//    for (std::size_t i = 0; i < e.size(); ++i)
//    {
//        auto x = Find(e[i].u);
//        auto y = Find(e[i].v);
//        if (x != y)
//        {
//            p[x] = y;
//            Ans += e[i].d;
//
//            --cnt;
//            if (cnt == 1)
//            {
//                break;
//            }
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//// 首先按权值把边从小到大排序
//// 然后我们不断地向并查集里面加入新的边
//// 一开始加入的边为L，最后加入的边为R
//// 类似Krushal，直到所有边都联通了为止
//// 然后计算d[R] - d[L]，更新答案，L向前推进
//// 再把R重置为L，重复上面的过程直到走到底
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <array>
//
//constexpr int MaxN = 100 + 10;
//constexpr int INF = 999999999;
//
//int n, m;   // n：点的个数   m：边的个数
//std::array<int, MaxN> p{ 0 };
//
//// 并查集的查找操作
//int Find(int x)
//{
//    if (p[x] == x)
//    {
//        return x;
//    }
//    else
//    {
//        return p[x] = Find(p[x]);
//    }
//}
//
//// 快读
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//class Edge
//{
//public:
//    int u, v, d;
//
//    Edge() = default;
//    Edge(int u, int v, int d) : // 从u到v有一条权值为d的无向边
//        u(u), v(v), d(d)
//    {
//    }
//};
//
//std::vector<Edge> e;
//
//int Solve()
//{
//    // 首先把边按权值从小到大排序
//    std::sort(e.begin(), e.end(), [](const Edge &a, const Edge &b)
//    {
//        return a.d < b.d;
//    });
//
//    int Ans = INF;
//    for (int L = 0; L < m; ++L)
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            p[i] = i;   // 初始化并查集
//        }
//
//        auto cnt = n;
//        for (int R = L; R < m; ++R)
//        {
//            auto u = Find(e[R].u);
//            auto v = Find(e[R].v);
//            if (u != v) // 如果不在一个集合里
//            {
//                p[u] = v;   // 那就加入并查集
//                --cnt;
//                if (cnt == 1)   // 如果已经联通了，那就更新一下答案，立即退出循环
//                {
//                    Ans = std::min(Ans, e[R].d - e[L].d);
//                    break;
//                }
//            }
//        }
//    }
//
//    return (Ans == INF ? -1 : Ans);
//}
//
//int main()
//{
//    while (std::cin >> n >> m && n)
//    {
//        e.clear();
//        for (int i = 0; i < m; ++i)
//        {
//            int u, v, d;
//            u = Read();
//            v = Read();
//            d = Read();
//            e.emplace_back(u, v, d);
//        }
//
//        std::cout << Solve() << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//template <typename T>
//T GCD(T a, T b)
//{
//    return b == 0 ? a : GCD(b, a % b);
//}
//
//template <typename T>
//void Reduce(T &a, T &b)
//{
//    auto g = GCD(a, b);
//    a /= g;
//    b /= g;
//}
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    for (int NO = 1; NO <= T; ++NO)
//    {
//        int n, k;
//        std::cin >> n >> k;
//        ll b = 1LL << k;
//        ll a = b - k - 1;
//        Reduce(a, b);
//
//        std::cout << "Case #" << NO << ": " << a << "/" << b << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//    int n, m;
//    std::cin >> n >> m;
//
//    std::vector<int> Vec;
//    while (n--)
//    {
//        int x;
//        std::cin >> x;
//        Vec.push_back(x);
//    }
//
//    while (m--)
//    {
//        std::next_permutation(Vec.begin(), Vec.end());
//    }
//
//    for (const auto &r : Vec)
//    {
//        std::cout << r << ' ';
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<double, 35> d;
//
//    int n;
//    double t;
//    while (std::cin >> n >> t && n)
//    {
//        d[n] = 1 << n;
//        for (int i = n - 1; i >= 0; --i)
//        {
//            double p0 = static_cast<double>(1 << i) / d[i + 1];
//            if (p0 < t)
//            {
//                p0 = t;
//            }
//
//            double p1 = (p0 - t) / (1 - t);
//            d[i] = static_cast<double>(1 << i) * p1 + (1 + p0) / 2 * d[i + 1] * (1 - p1);
//        }
//
//        std::printf("%.3lf\n", d[0]);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int n, k;
//std::array<int, 1000000 + 5> a{ 0 };
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//void QueryMax()
//{
//    static std::array<int, 1000000 + 5> p{ 0 }, q{ 0 };
//
//    int Head = 1, Tail = 0;
//    for (int i = 1; i <= n; ++i)
//    {
//        while (Head <= Tail && q[Tail] <= a[i])
//        {
//            --Tail;
//        }
//        q[++Tail] = a[i];
//        p[Tail] = i;
//        while (p[Head] < i - k + 1)
//        {
//            ++Head;
//        }
//
//        if (i >= k)
//        {
//            std::cout << q[Head] << ' ';
//        }
//    }
//}
//
//void QueryMin()
//{
//    static std::array<int, 1000000 + 5> p{ 0 }, q{ 0 };
//
//    int Head = 1, Tail = 0;
//    for (int i = 1; i <= n; ++i)
//    {
//        while (Head <= Tail && q[Tail] >= a[i])
//        {
//            --Tail;
//        }
//        q[++Tail] = a[i];
//        p[Tail] = i;
//        while (p[Head] < i - k + 1)
//        {
//            ++Head;
//        }
//
//        if (i >= k)
//        {
//            std::cout << q[Head] << ' ';
//        }
//    }
//}
//
//int main()
//{
//    n = Read();
//    k = Read();
//    for (int i = 1; i <= n; ++i)
//    {
//        a[i] = Read();
//    }
//
//    QueryMin();
//    std::putchar('\n');
//    QueryMax();
//    std::putchar('\n');
//
//    return 0;
//}
//// luogu-judger-enable-o2
//#include <iostream>
//#include <array>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    static std::array<int, 2000001> a{ 0 }, b{ 0 }, c{ 0 }, deq{ 0 };
//    int n, m;
//    n = Read();
//    m = Read();
//    for (int i = 0; i < n; ++i)
//    {
//        a[i] = Read();
//    }
//
//    int s = 0, t = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        while (s < t && a[deq[t - 1]] >= a[i])
//        {
//            --t;
//        }
//        deq[t++] = i;
//        b[i] = a[deq[s]];
//        c[i] = a[deq[t]];
//
//        if (deq[s] == i - m + 1)
//        {
//            ++s;
//        }
//    }
//
//    for (int i = 0; i < n - 1; ++i)
//    {
//        std::printf("%d ", b[i]);
//    }
//    std::putchar('\n');
//    for (int i = 0; i < n - 1; ++i)
//    {
//        std::printf("%d ", c[i]);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        double a, b, s, Ans;
//        std::cin >> a >> b >> s;
//        double m = a * b;
//        if (std::abs(s) < 1e-6)
//        {
//            Ans = 1;
//        }
//        else if (s > m)
//        {
//            Ans = 0;
//        }
//        else
//        {
//            Ans = (m - s - s * std::log(m / s)) / m;
//        }
//
//        std::printf("%.6lf%%\n", Ans * 100);
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    double Now = 420000.0 / n, Ans = 0.0;
//    for (int i = 1; i <= n; ++i)
//    {
//        Ans += Now;
//        Now *= (1 - 0.5 / i);
//    }
//
//    std::printf("%.2lf\n", Ans);
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cmath>
//
//using std::log;
//using std::exp;
//
//constexpr int MaxN = 200000 + 5;
//
//long double logF[MaxN * 2 + 1];
//
//long double logC(int n, int m)
//{
//    return logF[n] - logF[m] - logF[n - m];
//}
//
//double Solve(int n, double p)
//{
//    double Ans = 0.0;
//    for (int i = 0; i <= n; ++i)
//    {
//        auto c = logC(n * 2 - i, n);
//        auto v1 = c + (n + 1) * log(p) + (n - i) * log(1 - p);
//        auto v2 = c + (n + 1) * log(1 - p) + (n - i) * log(p);
//        auto x = exp(v1) + exp(v2);
//        Ans += i * (exp(v1) + exp(v2));
//    }
//
//    return Ans;
//}
//
//int main()
//{
//    logF[0] = 0;
//    for (int i = 1; i <= MaxN; ++i)
//    {
//        logF[i] = logF[i - 1] + log(i);
//    }
//
//    int NO = 0, n;
//    double p;
//    while (std::cin >> n >> p)
//    {
//        std::printf("Case %d: %.6lf\n", ++NO, Solve(n, p));
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <array>
//
//constexpr int MaxN = 500000 + 5;
//constexpr int INF = 2147483647;
//
//class Edge
//{
//public:
//    int From, To, Dist;
//
//    Edge() = default;
//    Edge(int u, int v, int d) :
//        From(u), To(v), Dist(d)
//    {
//    }
//};
//
//std::vector<Edge> Edges;
//std::array<std::vector<int>, MaxN> G;
//std::array<bool, MaxN> Done{ false };
//std::array<int, MaxN> d{ 0 }, p{ 0 };
//
//void AddEdge(int From, int To, int Dist)
//{
//    Edges.emplace_back(From, To, Dist);
//    G[From].push_back(Edges.size() - 1);
//}
//
//class HeapNode
//{
//public:
//    int d, u;
//
//    HeapNode() = default;
//    HeapNode(int d, int u) :
//        d(d), u(u)
//    {
//    }
//
//    bool operator<(const HeapNode &rhs) const
//    {
//        return d > rhs.d;
//    }
//};
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int N, M, S;
//    N = Read();
//    M = Read();
//    S = Read();
//    for (int i = 0; i < M; ++i)
//    {
//        int From, To, Cost;
//        From = Read();
//        To = Read();
//        Cost = Read();
//        AddEdge(From, To, Cost);
//    }
//
//    std::priority_queue<HeapNode> Q;
//    for (int i = 1; i <= N; ++i)
//    {
//        d[i] = INF;
//    }
//    d[S] = 0;
//    Q.push(HeapNode(0, S));
//    while (!Q.empty())
//    {
//        auto x = Q.top();
//        Q.pop();
//
//        auto u = x.u;
//        if (Done[u])
//        {
//            continue;
//        }
//        Done[u] = true;
//
//        for (std::size_t i = 0; i < G[u].size(); ++i)
//        {
//            auto &e = Edges[G[u][i]];
//            if (d[e.To] > d[u] + e.Dist)
//            {
//                d[e.To] = d[u] + e.Dist;
//                p[e.To] = G[u][i];
//                Q.push(HeapNode(d[e.To], e.To));
//            }
//        }
//    }
//
//    for (int i = 1; i <= N; ++i)
//    {
//        std::cout << d[i] << ' ';
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//// 我们设船行驶的时间为T
//// 当船往左划时，T1 = 0.5L * 0.5 / v
//// 当船往右划时，T2 = (0.5L + L) * 0.5 / v
//// 最后过河，T3 = L / v
//// 所以总时间T = T1 + T2 + T3 = 2L / v
//// 然后再加上需要步行的时间即可
//#include <iostream>
//
//int main()
//{
//    int n, D;
//    int NO = 0;
//    while (std::cin >> n >> D && D)
//    {
//        double Ans = 0;
//        while (n--)
//        {
//            int p, L, v;
//            std::cin >> p >> L >> v;
//            D -= L; // 坐船就不需要步行
//            Ans += 2.0 * L / v; // 船行驶时间的数学期望
//        }
//
//        std::printf("Case %d: %.3lf\n\n", ++NO, Ans + D);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//int main()
//{
//    constexpr int MaxN = 20 + 1;
//    std::array<std::array<std::array<ll, MaxN>, MaxN>, MaxN> d{ 0 };
//    d[1][1][1] = 1;
//    for (int i = 2; i < MaxN; ++i)
//    {
//        for (int j = 1; j <= i; ++j)
//        {
//            for (int k = 1; k <= i; ++k)
//            {
//                d[i][j][k] = d[i - 1][j][k] * (i - 2);
//                if (j > 1)
//                {
//                    d[i][j][k] += d[i - 1][j - 1][k];
//                }
//                if (k > 1)
//                {
//                    d[i][j][k] += d[i - 1][j][k - 1];
//                }
//            }
//        }
//    }
//
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        int n, L, R;
//        std::cin >> n >> L >> R;
//        std::cout << d[n][L][R] << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//constexpr int MaxN = 1000;
//constexpr int MOD = 10056;
//
//std::array<std::array<int, MaxN + 1>, MaxN + 1> C{ 0 };
//std::array<int, MaxN + 1> f{ 0 };
//
//void Init()
//{
//    // 用递推式预先处理出C(n, i)的各个值
//    // 如果是已知范围的，可以用这个模板来做预处理
//    for (int i = 0; i <= MaxN; ++i)
//    {
//        C[i][0] = C[i][i] = 1;
//        for (int j = 1; j < i; ++j)
//        {
//            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
//        }
//    }
//
//    f[0] = 1;
//    for (int i = 1; i <= MaxN; ++i) // 递推预处理出f(N)的各个值
//    {
//        for (int j = 1; j <= i; ++j)
//        {
//            f[i] = (f[i] + C[i][j] * f[i - j]) % MOD;
//        }
//    }
//}
//
//int main()
//{
//    Init();
//
//    int T;
//    std::cin >> T;
//    for (int i = 1; i <= T; ++i)
//    {
//        int n;
//        std::cin >> n;
//        std::cout << "Case " << i << ": " << f[n] << std::endl;
//    }
//
//    return 0;
//}
//// 用：总组合数 - 安全组合 = 危险组合
//// d[i]表示第i个位置以L结束的序列，但前三个要特别说明
//// 因此有d[i] = d[i - 1] + d[i - 2] + d[i - 3]
//// 然后总的组合数为2^n
//// 最后相减即可
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<int, 55> d{ 0 };
//    d[1] = 2;   // U L
//    d[2] = 4;   // UU LL UL LU
//    d[3] = 7;   // LLU UUL ULL LLL LUU LUL ULU
//    for (int i = 4; i < 55; ++i)
//    {
//        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
//    }
//
//    int n;
//    while (std::cin >> n && n)
//    {
//        std::cout << (1 << n) - d[n] << std::endl;
//    }
//
//    return 0;
//}
//// 这一题利用了类似动态规划的思想
//// 枚举每一种合法的情况，然后统计概率和
//// 用一下记忆化搜索，降低搜索次数
//#include <iostream>
//#include <vector>
//#include <array>
//#include <string>
//#include <map>
//
//std::map<std::vector<int>, double> d;
//std::array<std::array<std::string, 4>, 9> Card;
//
//// cnt：牌的情况
//// c：一共还有c张牌
//double DP(std::vector<int> &cnt, int c)
//{
//    if (c == 0)
//    {
//        return 1.0;
//    }
//
//    if (d.count(cnt) != 0)  // 记忆化搜索
//    {
//        return d[cnt];
//    }
//
//    double Sum = 0.0;
//    int Tot = 0;
//    for (int i = 0; i < 9; ++i) // 枚举每一堆牌
//    {
//        if (cnt[i] > 0) // 如果还剩下牌
//        {
//            for (int j = i + 1; j < 9; ++j)
//            {
//                if (cnt[j] > 0)
//                {
//                    // 那就比较一下堆顶的牌是否面值一样
//                    // 取首字母就好了，因此是[0]
//                    if (Card[i][cnt[i] - 1][0] == Card[j][cnt[j] - 1][0])
//                    {
//                        ++Tot;  // 统计取了多少次
//                        --cnt[i];   // 拿走
//                        --cnt[j];
//
//                        Sum += DP(cnt, c - 2);  // 统计概率
//
//                        ++cnt[i];   // 放回去，回溯
//                        ++cnt[j];
//                    }
//                }
//            }
//        }
//    }
//
//    if (Tot == 0)
//    {
//        return d[cnt] = 0;  // 记忆化
//    }
//    else
//    {
//        return d[cnt] = Sum / Tot;  // 记忆化
//    }
//}
//
//bool Read()
//{
//    for (int i = 0; i < 9; ++i)
//    {
//        for (int j = 0; j < 4; ++j)
//        {
//            if (!(std::cin >> Card[i][j]))
//            {
//                return false;
//            }
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    while (Read())
//    {
//        // cnt[i]表示第i堆牌里面还剩下多少张
//        // 初始时为9堆牌，每堆4张
//        std::vector<int> cnt(9, 4);
//        d.clear();
//        std::printf("%.6lf\n", DP(cnt, 36));
//    }
//
//    return 0;
//}
//// 枚举每个人买不买东西，
//// 然后把每个人自己买东西的概率加起来，
//// 最后和总的可能的概率再做个除法
//#include <iostream>
//#include <array>
//#include <bitset>
//#include <algorithm>
//
//constexpr int MaxN = 20 + 5;
//int n, r;   // 一共有n个人，r人买了东西
//std::bitset<MaxN> Buy;  // 标记第i个人买不买东西
//std::array<double, MaxN> P{ 0 }, Sum{ 0 };
//// P[i]表示第i个人买东西的概率，Sum[i]表示第i个人买东西的概率之和
//
//// d：搜索深度
//// c：几个人去买了产品
//// prob：概率
//void DFS(int d, int c, double prob)
//{
//    // 如果已经大于r个人买东西或者没买东西的人差太多了都赶不上了
//    if (c > r || d - c > n - r)
//    {
//        return;
//    }
//
//    if (d == n) // 搜完了n个人（从0开始搜的）
//    {
//        Sum[n] += prob; // Sum[n]表示Sum[i(0 .. n - 1)]之和
//        for (int i = 0; i < n; ++i)
//        {
//            if (Buy[i]) // 如果第i个人买东西了，那就记录下这个概率，然后加和
//            {
//                Sum[i] += prob;
//            }
//        }
//
//        return;
//    }
//
//    Buy[d] = false;
//    DFS(d + 1, c, prob * (1 - P[d]));   // 第d个人不买
//    Buy[d] = true;
//    DFS(d + 1, c + 1, prob * P[d]);     // 第d个人买
//}
//
//int main()
//{
//    int NO = 0;
//    while (std::cin >> n >> r && n)
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> P[i];
//        }
//        std::fill(Sum.begin(), Sum.end(), 0);
//
//        DFS(0, 0, 1.0);
//
//        std::cout << "Case " << ++NO << ":" << std::endl;
//        for (int i = 0; i < n; ++i)
//        {
//            std::printf("%.6lf\n", Sum[i] / Sum[n]);
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    double a, b, c;
//    while (std::cin >> a >> b >> c)
//    {
//        std::printf("%.5lf\n", ((a * b + b * (b - 1)) / ((a + b) * (a + b - c - 1))));
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    double a, b, c;
//    while (std::cin >> a >> b >> c)
//    {
//        std::printf("%.5lf\n", (a + b - c) / (a + b));
//    }
//
//    return 0;
//}
//// 条件概率题：
//// 直接打一枪没事的概率是等于子串"00"的个数除以"00"和"01"的个数（即0的个数）
//// 这前面的一个0表示上一个人打的是空弹，后面的0/1表示这次的子弹情况
//// 转一下再打一枪没事的概率等于0在该字符串中出现的概率
//// 以a表示子串"00"的个数，b表示0的个数，n表示字符串长度
//// 所以就只要比较a/b和b/n的大小即可
//// 然后交叉相乘一下，避免除0的错误，也不用怕精度问题
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string Str;
//    while (std::cin >> Str)
//    {
//        int a = 0, b = 0;
//        auto n = static_cast<int>(Str.size());
//        for (int i = 0; i < n; ++i)
//        {
//            if (Str[i] == '0')
//            {
//                ++b;    // b表示0的个数
//                if (Str[(i + 1) % n] == '0')    // 注意是个环形的，所以要取模
//                {
//                    ++a;    // a表示"01"串的个数
//                }
//            }
//        }
//
//        if (a * n == b * b)
//        {
//            std::puts("EQUAL");
//        }
//        else if (a * n > b * b)
//        {
//            std::puts("SHOOT");
//        }
//        else
//        {
//            std::puts("ROTATE");
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_set>
//#include <string>
//
//int main()
//{
//    int T;
//
//    std::unordered_set<std::string> s;
//    std::string Str;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> Str;
//        s.insert(Str);
//    }
//
//    std::cout << s.size() << std::endl;
//    
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <array>
//#include <queue>
//#include <algorithm>
//
//constexpr int MAXV = 400000;
//constexpr int INF = 999999999;
//
//class Edge
//{
//public:
//    int to, cap, rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) :
//        to(to), cap(cap), rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, MAXV> G;
//std::array<int, MAXV> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].push_back(Edge(To, Cap, G[To].size()));
//    G[To].push_back(Edge(From, 0, G[From].size() - 1));
//}
//
//void BFS(int s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//    std::queue<int> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.cap > 0 && Level[e.to] < 0)
//            {
//                Level[e.to] = Level[v] + 1;
//                Que.push(e.to);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < static_cast<int>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//        if (e.cap > 0 && Level[v] < Level[e.to])
//        {
//            auto d = DFS(e.to, t, std::min(f, e.cap));
//            if (d > 0)
//            {
//                e.cap -= d;
//                G[e.to][e.rev].cap += d;
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//    while (1)
//    {
//        BFS(s);
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//        int f;
//        while ((f = DFS(s, t, INF)) > 0)
//        {
//            Flow += f;
//        }
//    }
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int T;
//    T = Read();
//    while (T--)
//    {
//        for (auto &r : Level)
//        {
//            r = 0;
//        }
//        for (auto &r : Iter)
//        {
//            r = 0;
//        }
//        for (auto &r : G)
//        {
//            r.clear();
//        }
//
//        int k;
//        k = Read();
//        int S = 0;
//        int T = 2 * k + 1;
//        for (int i = 1; i <= k; ++i)
//        {
//            AddEdge(S, i, 1);
//            AddEdge(i + k, T, 1);
//        }
//
//        for (int i = 1; i <= k; ++i)
//        {
//            for (int j = 1; j <= k; ++j)
//            {
//                int f;
//                f = Read();
//                if (f)
//                {
//                    AddEdge(i, j + k, 1);
//                }
//            }
//        }
//
//        std::cout << (MaxFlow(S, T) == k ? "Yes" : "No") << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//constexpr int INF = 999999999;
//
//class Edge
//{
//public:
//    int To, Cap, Rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) :
//        To(to), Cap(cap), Rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, 2500> G;
//std::array<int, 2500> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].emplace_back(To, Cap, G[To].size());
//    G[To].emplace_back(From, 0, G[From].size() - 1);
//}
//
//void BFS(int s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//
//    std::queue<int> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.Cap > 0 && Level[e.To] < 0)
//            {
//                Level[e.To] = Level[v] + 1;
//                Que.push(e.To);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < static_cast<int>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//
//        if (e.Cap > 0 && Level[v] < Level[e.To])
//        {
//            int d = DFS(e.To, t, std::min(f, e.Cap));
//
//            if (d > 0)
//            {
//                e.Cap -= d;
//                G[e.To][e.Rev].Cap += d;
//
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//
//    while (1)
//    {
//        BFS(s);
//
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//
//        int F;
//        while ((F = DFS(s, t, INF)) > 0)
//        {
//            Flow += F;
//        }
//    }
//}
//
//int main()
//{
//    std::array<std::array<int, 201>, 201> Like{ 0 };
//    int N, M;
//    std::cin >> N >> M;
//
//    int S = N + M;
//    int T = S + 1;
//    for (int i = 0; i < N; ++i)
//    {
//        AddEdge(S, i, 1);
//    }
//    for (int i = 0; i < M; ++i)
//    {
//        AddEdge(N + i, T, 1);
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        int x;
//        std::cin >> x;
//        for (int j = 0; j < x; ++j)
//        {
//            int t;
//            std::cin >> t;
//            AddEdge(i, N + t - 1, 1);
//        }
//    }
//
//    std::cout << MaxFlow(S, T) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <array>
//#include <queue>
//#include <algorithm>
//
//constexpr int MAXV = 400;
//constexpr int INF = 999999999;
//
//class Edge
//{
//public:
//    int to, cap, rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) :
//        to(to), cap(cap), rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, MAXV> G;
//std::array<int, MAXV> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].push_back(Edge(To, Cap, G[To].size()));
//    G[To].push_back(Edge(From, 0, G[From].size() - 1));
//}
//
//void BFS(int s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//    std::queue<int> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.cap > 0 && Level[e.to] < 0)
//            {
//                Level[e.to] = Level[v] + 1;
//                Que.push(e.to);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < static_cast<int>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//        if (e.cap > 0 && Level[v] < Level[e.to])
//        {
//            auto d = DFS(e.to, t, std::min(f, e.cap));
//            if (d > 0)
//            {
//                e.cap -= d;
//                G[e.to][e.rev].cap += d;
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//    while (1)
//    {
//        BFS(s);
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//        int f;
//        while ((f = DFS(s, t, INF)) > 0)
//        {
//            Flow += f;
//        }
//    }
//}
//
//int main()
//{
//    std::array<std::array<int, 201>, 201> Like{ 0 };
//    int N, M;
//    std::cin >> N >> M;
//
//    int S = N + M;
//    int T = S + 1;
//    for (int i = 0; i < N; ++i)
//    {
//        AddEdge(S, i, 1);
//    }
//    for (int i = 0; i < M; ++i)
//    {
//        AddEdge(N + i, T, 1);
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        int x;
//        std::cin >> x;
//        for (int j = 0; j < x; ++j)
//        {
//            int t;
//            std::cin >> t;
//            AddEdge(i, N + t - 1, 1);
//        }
//    }
//
//    std::cout << MaxFlow(S, T) << std::endl;
//
//    return 0;
//}
//// 直接按照字典序从小到大的顺序递归一个一个地枚举
//#include <iostream>
//#include <string>
//#include <array>
//
//int k, cnt;
//std::array<std::array<std::string, 6>, 2> p;
//std::array<char, 9> Ans;
//
//bool DFS(int Col)
//{
//    if (Col == 5)   // 因为是从0开始搜的，所以边界是4 + 1
//    {
//        if (++cnt == k) // 如果找到了k个了
//        {
//            for (int i = 0; i < Col; ++i)   // 那就把这第k个输出
//            {
//                std::putchar(Ans[i]);
//            }
//            std::putchar('\n');
//            return true;
//        }
//
//        return false;
//    }
//
//    std::array<std::array<bool, 26>, 2> Existed{ false };
//    for (int i = 0; i < 2; ++i) // 遍历两个图
//    {
//        for (int j = 0; j < 6; ++j) // 把这一列出现到的字母都标记起来
//        {
//            Existed[i][p[i][j][Col] - 'A'] = true;
//        }
//    }
//    for (int i = 0; i < 26; ++i)    // 递归地枚举每一个字母
//    {
//        if (Existed[0][i] && Existed[1][i]) // 如果这个字母在两张图中的同一列都出现了
//        {
//            Ans[Col] = 'A' + i; // 标记一下
//            if (DFS(Col + 1))   // 继续搜下一列
//            {
//                return true;
//            }
//        }
//    }
//
//    return false;   // 注意最后这个不能少
//}
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> k;
//        for (int i = 0; i < 2; ++i) // 把两个图读入
//        {
//            for (int j = 0; j < 6; ++j)
//            {
//                std::cin >> p[i][j];
//            }
//        }
//
//        cnt = 0;    // 当前是第几个按字典序找到的密码
//        if (!DFS(0))    // 如果找不到任何一种解决方案，再输出"NO"
//        {
//            std::puts("NO");
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//constexpr int MaxN = 50000;
//
//std::array<int, MaxN + 1> phi{ 0 }, phi_psum{ 0 };
//
//void phi_table(int n)
//{
//    phi[1] = 0;
//    for (int i = 2; i <= n; ++i)
//    {
//        if (phi[i] == 0)
//        {
//            for (int j = i; j <= n; j += i)
//            {
//                if (phi[j] == 0)
//                {
//                    phi[j] = j;
//                }
//
//                phi[j] = phi[j] / i * (i - 1);
//            }
//        }
//    }
//}
//
//int main()
//{
//    phi_table(MaxN);
//    for (int i = 1; i <= MaxN; ++i)
//    {
//        phi_psum[i] = phi_psum[i - 1] + phi[i];
//    }
//
//    int n;
//    while (std::cin >> n && n)
//    {
//        std::cout << 2 * phi_psum[n] + 1 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using ll = long long;
//
//char s[10000002], s_new[10000002];
//int p[10000002], f[10000002] = { 0 };
//
//int Init()
//{
//    auto len = std::strlen(s);
//    s_new[0] = '$';
//    s_new[1] = '#';
//    int j = 2;
//
//    for (std::size_t i = 0; i < len; ++i)
//    {
//        s_new[j++] = s[i];
//        s_new[j++] = '#';
//    }
//    s_new[j] = '\0';
//
//    return j;
//}
//
//void Manacher()
//{
//    auto len = Init();
//    int id, mx = 0;
//
//    for (int i = 1; i < len; ++i)
//    {
//        if (i < mx)
//        {
//            p[i] = std::min(p[2 * id - i], mx - i);
//        }
//        else
//        {
//            p[i] = 1;
//        }
//
//        while (s_new[i - p[i]] == s_new[i + p[i]])
//        {
//            ++p[i];
//        }
//
//        if (mx < i + p[i])
//        {
//            id = i;
//            mx = i + p[i];
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> s;
//    Manacher();
//
//    ll Ans = 0;
//    for (std::size_t i = 1; i <= std::strlen(s); ++i)
//    {
//        int l = 2, r = 2 * i;
//        int m = (l + r) / 2;
//        if (p[m] * 2 - 1 >= r - l + 1)
//        {
//            if (m % 2 == 0)
//            {
//                f[r] = f[m - 2] + 1;
//            }
//            else
//            {
//                f[r] = f[m - 1] + 1;
//            }
//        }
//
//        Ans += f[r];
//    }
//
//    std::cout << Ans << std::endl;
//}
//#include <iostream>
//#include <array>
//
//constexpr int M = 30000000;
//std::array<int, M + 1> cnt{ 0 }, Sum{ 0 };
//
//void Init()
//{
//    for (int c = 1; c <= M; ++c)
//    {
//        for (int a = c * 2; a <= M; a += c)
//        {
//            int b = a - c;
//            if (c == (a ^ b))
//            {
//                ++cnt[a];
//            }
//        }
//    }
//
//    Sum[0] = 0;
//    for (int i = 1; i <= M; ++i)
//    {
//        Sum[i] = Sum[i - 1] + cnt[i];
//    }
//}
//
//int main()
//{
//    Init();
//    int T, n, NO = 0;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> n;
//        std::cout << "Case " << ++NO << ": " << Sum[n] << std::endl;
//    }
//
//    return 0;
//}
//// 这一题用到的是唯一分解式
//#include <iostream>
//#include <cmath>
//
//using ll = long long;
//
//// 算出n里面最大能除掉多少d，返回d的k次方
//int DivedeAll(int &n, int d)
//{
//    int x = 1;
//    while (n % d == 0)
//    {
//        n /= d;
//        x *= d;
//    }
//
//    return x;
//}
//
//ll Solve(int n)
//{
//    if (n == 1) // 注意特判：1 == 1 * 1
//    {
//        return 2;
//    }
//
//    ll Ans = 0; // 最后的答案
//    int pf = 0; // 质因子的个数
//    int m = static_cast<int>(std::sqrt(n)); // 不要放在循环里，因为要修改n的值
//    for (int i = 2; i <= m; ++i)
//    {
//        if (n % i == 0) // i是一个新的质因子
//        {
//            ++pf;
//            Ans += DivedeAll(n, i);
//        }
//    }
//
//    if (n > 1)  // 如果除到最后还有剩余的，那就把它也加上去
//    {
//        ++pf;
//        Ans += n;
//    }
//    if (pf <= 1)
//    {
//        ++Ans;  // 如果n这个数是个质数，那还要加上1(n == 1 * n)
//    }
//
//    return Ans;
//}
//
//int main()
//{
//    int n, NO = 0;
//    while (std::cin >> n && n)
//    {
//        std::cout << "Case " << ++NO << ": " << Solve(n) << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <array>
//
//constexpr int MaxN = 10000;
//
//std::vector<int> Primes;
//std::array<int, MaxN> e;
//
//// d表示幂指数
//void AddInteger(int n, int d)
//{
//    for (std::size_t i = 0; i < Primes.size(); ++i)
//    {
//        while (n % Primes[i] == 0)  // 用到了唯一分解定理
//        {
//            n /= Primes[i];
//            e[i] += d;
//        }
//
//        if (n == 1) // 提前终止循环，节省时间
//        {
//            break;
//        }
//    }
//}
//
//// 表示把结果乘以(n!)^d
//void AddFactorial(int n, int d)
//{
//    for (int i = 1; i <= n; ++i)
//    {
//        AddInteger(i, d);
//    }
//}
//
//// 最传统的试商法判断质数
//bool IsPrime(int n)
//{
//    for (int a = 2; a <= std::sqrt(n); ++a)
//    {
//        if (n % a == 0)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    for (int i = 2; i <= 10000; ++i)    // 先处理出10000以内的质数
//    {
//        if (IsPrime(i))
//        {
//            Primes.push_back(i);
//        }
//    }
//
//    int p, q, r, s;
//    while (std::cin >> p >> q >> r >> s)
//    {
//        std::fill(e.begin(), e.end(), 0);   // 每次都要初始化一边
//        AddFactorial(p, 1);
//        AddFactorial(q, -1);
//        AddFactorial(p - q, -1); // 以上三步重现了C(p, q) = p! / (q! (p - q)!)
//        AddFactorial(r, -1);
//        AddFactorial(s, 1);
//        AddFactorial(r - s, 1);  // 以上三步重现了C(r, s) = r! / (s! (r - s)!)
//                                 // 但要注意这里还要取一个倒数
//        double Ans = 1.0;
//        for (std::size_t i = 0; i < Primes.size(); ++i)
//        {
//            Ans *= std::pow(Primes[i], e[i]);
//        }
//
//        std::printf("%.5lf\n", Ans);
//    }
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//void ExGCD(ll a, ll b, ll &d, ll &x, ll &y)
//{
//    if (!b)
//    {
//        x = 1;
//        y = 0;
//        d = a;
//    }
//    else
//    {
//        ExGCD(b, a % b, d, y, x);
//        y -= x * (a / b);
//    }
//}
//
//int main()
//{
//    ll a, b, c, d, x, y;
//    std::cin >> a >> b >> c;
//    c = -c;
//
//    ExGCD(a, b, d, x, y);
//
//    if (c % d != 0)
//    {
//        std::cout << -1 << std::endl;
//    }
//    else
//    {
//        std::cout << c / d * x << ' ' << c / d * y << std::endl;
//    }
//
//    return 0;
//}
//// 这一题十分暴力，就是枚举
//#include <iostream>
//#include <array>
//
//constexpr int MaxN = 100 * 2 + 5;
//constexpr int M = 10001;
//
//int T;
//std::array<int, MaxN> x{ 0 };
//
//void Solve()
//{
//    for (int a = 0; a < M; ++a) // 枚举a
//    {
//        for (int b = 0; b < M; ++b) // 枚举b
//        {
//            bool OK = true;
//            for (int i = 2; i <= T * 2; i += 2)
//            {
//                x[i] = (a * x[i - 1] + b) % M;
//                // 如果这个a和b能使数列满足递推关系，那就一直递推下去
//                // 否则就重新来过，继续试验
//                if (i + 1 <= T * 2 && x[i + 1] != (a * x[i] + b) % M)
//                {
//                    OK = false;
//                    break;
//                }
//            }
//
//            if (OK) // 如果找到其中一组a和b了，依题意，那就退出
//            {
//                return;
//            }
//        }
//    }
//}
//
//int main()
//{
//    while (std::cin >> T)
//    {
//        for (int i = 1; i <= T * 2 - 1; i += 2) // 读入奇数项的
//        {
//            std::cin >> x[i];
//        }
//        Solve();
//        for (int i = 2; i <= T * 2; i += 2) // 输出偶数项的
//        {
//            std::cout << x[i] << std::endl;
//        }
//    }
//
//    return 0;
//}
//// 一道数论题：
//// 会发现整个数列取模之后有循环节
//// 于是我们通过找到那个循环节来简化运算
//// 然后熟悉一下“幂取模”的模板还有模运算的一些基本性质
//// 具体见代码和注释
//#include <iostream>
//#include <array>
//
//using ULL = unsigned long long;
//
//constexpr int MaxN = 1000 + 5;
//
//std::array<std::array<ULL, MaxN * 6>, MaxN> f{ 0 };
//std::array<ULL, MaxN> Period{ 0 };
//
//int PowMod(ULL a, ULL b, int n) // “幂取模”的模板，算出a^b % n的值
//{
//    if (!b)
//    {
//        return 1;
//    }
//
//    int k = PowMod(a, b / 2, n);
//    k = k * k % n;
//
//    if (b % 2)
//    {
//        k = k * a % n;
//    }
//
//    return k;
//}
//
//ULL Solve(ULL a, ULL b, int n)
//{
//    if (a == 0 || n == 1)
//    {
//        return 0;
//    }
//
//    // 利用公式：a^b % p = ((a % p)^b) % p 
//    // 这个公式可以用二项式定理展开验证
//    auto p = PowMod(a % Period[n], b, Period[n]);
//
//    return f[n][p];
//}
//
//int main()
//{
//    for (int n = 2; n <= 1000; ++n) // 事先处理好各种n的情况，之后查表即可
//    {
//        f[n][0] = 0;
//        f[n][1] = 1;
//        for (int i = 2; ; ++i)
//        {
//            f[n][i] = (f[n][i - 1] + f[n][i - 2]) % n;  // 用斐波那契数列的模递推
//            if (f[n][i - 1] == 0 && f[n][i] == 1)   // 如果出现循环了
//            {
//                Period[n] = i - 1;  // Period[n]表示当输入n时，第几项出现循环
//                break;
//            }
//        }
//    }
//
//    ULL a, b;
//    int n, T;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> a >> b >> n;
//        std::cout << Solve(a, b, n) << std::endl;
//    }
//
//    return 0;
//}
//// 这是一道模拟题，其中有一些小细节要注意
//// 具体见代码和注释
//#include <iostream>
//#include <string>
//#include <array>
//
//int main()
//{
//    std::array<int, 100> Arr{ 0 };
//    int t, m;
//    std::cin >> t >> m;
//
//    int id = 1; // 标记着最远的编号，从1开始
//    std::string Command;
//    while (t--)
//    {
//        std::cin >> Command;
//        if (Command[0] == 'a')  // "alloc"
//        {
//            int p;
//            std::cin >> p;
//
//            int cnt = 0, idx = 0;
//            bool OK = false;
//            for (int i = 0; i < m; ++i)
//            {
//                if (!Arr[i])
//                {
//                    ++cnt;  // 去找有多少个连续的0
//                }
//                else
//                {
//                    cnt = 0;    // 中断了就清零重来
//                    idx = i + 1;
//                }
//
//                if (cnt == p)   // 依题意，找到了第一个能存放p个单位的就立马跳出
//                {
//                    OK = true;
//                    break;
//                }
//            }
//
//            if (OK)
//            {   // 从idx开始涂连续的p个
//                for (int i = idx; i < idx + p; ++i)
//                {
//                    Arr[i] = id;
//                }
//
//                // 这里要加一了
//                std::cout << id++ << std::endl;
//            }
//            else
//            {
//                std::puts("NULL");
//            }
//        }
//        else if (Command[0] == 'e') // "erase"
//        {
//            int p;
//            std::cin >> p;
//
//            if (p > id || p <= 0)   // 删除最大标号以外的或者删除1以下的均为非法
//            {
//                std::puts("ILLEGAL_ERASE_ARGUMENT");
//            }
//            else
//            {
//                int f = false;
//                int i;
//                for (i = 0; i < m; ++i)
//                {
//                    if (Arr[i] == p)    // 去找要被删去的第一个数的下标
//                    {
//                        break;
//                    }
//                }
//
//                while (Arr[i] == p)
//                {
//                    Arr[i] = 0; // 清零即是删除
//                    ++i;
//                    f = true;   // 标记删除操作被执行了
//                }
//
//                if (!f) // 如果这一次删除没有做任何操作，那么这个删除也是无效的
//                {
//                    std::puts("ILLEGAL_ERASE_ARGUMENT");
//                }
//            }
//        }
//        else   // "defragment"
//        {
//            int idx = 0;
//            for (int i = 0; i < m; ++i)
//            {
//                if (Arr[i]) // 如果非零，则存放在前面
//                {
//                    Arr[idx++] = Arr[i];
//                }
//            }
//            for (int i = idx; i < m; ++i)   // 后面那部分都是零
//            {
//                Arr[i] = 0;
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <string>
//
//int main()
//{
//    std::string Str;
//    int a = 0, b = 8;
//    for (int i = 0; i < 8; ++i)
//    {
//        int t = 0;
//
//        std::cin >> Str;
//        for (int i = 0; i < 8; ++i)
//        {
//            if (Str[i] == 'B')
//            {
//                ++t;
//            }
//        }
//
//        if (t == 8)
//        {
//            ++a;
//        }
//
//        b = std::min(b, t);
//    }
//
//    if (a == 8)
//    {
//        std::cout << 8 << std::endl;
//    }
//    else
//    {
//        std::cout << a + b << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<std::array<char, 8>, 8> Map;
//    for (int i = 0; i < 8; ++i)
//    {
//        for (int j = 0; j < 8; ++j)
//        {
//            std::cin >> Map[i][j];
//        }
//    }
//
//    int Ans = 0;
//    for (int i = 0; i < 8; ++i)
//    {
//        bool ok = true;
//        for (int j = 0; j < 8; ++j)
//        {
//            if (Map[i][j] != 'B')
//            {
//                ok = false;
//                break;
//            }
//        }
//
//        if (ok)
//        {
//            ++Ans;
//        }
//    }
//    for (int i = 0; i < 8; ++i)
//    {
//        bool ok = true;
//        for (int j = 0; j < 8; ++j)
//        {
//            if (Map[j][i] != 'B')
//            {
//                ok = false;
//                break;
//            }
//        }
//
//        if (ok)
//        {
//            ++Ans;
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    //std::array<std::array<char, 8>, 8> Map;
//    char Map[8][8];
//    for (int i = 0; i < 8; ++i)
//    {
//        for (int j = 0; j < 8; ++j)
//        {
//            std::cin >> Map[i][j];
//        }
//    }
//
//    int Ans = 0;
//    for (int i = 0; i < 8; ++i)
//    {
//        if (Map[0][i] == 'B')
//        {
//            bool OK = true;
//            for (int j = 0; j < 8; ++j)
//            {
//                if (Map[j][i] != 'B')
//                {
//                    OK = false;
//                    break;
//                }
//            }
//
//            if (OK)
//            {
//                for (int j = 0; j < 8; ++j)
//                {
//                    Map[j][i] = 'W';
//                }
//                ++Ans;
//            }
//        }
//    }
//    for (int i = 0; i < 8; ++i)
//    {
//        if (Map[i][7] == 'B')
//        {
//            bool OK = true;
//            for (int j = 0; j < 8; ++j)
//            {
//                if (Map[i][j] != 'B')
//                {
//                    OK = false;
//                    break;
//                }
//            }
//
//            if (OK)
//            {
//                for (int j = 0; j < 8; ++j)
//                {
//                    Map[i][j] = 'W';
//                }
//                ++Ans;
//            }
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//// 看这题的数据量似乎不算太大
//// 所以不用DP也可以
//// 直接上DFS也不会超时
//// 这个做法比较暴力但是容易想到
//// 具体看代码
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include <vector>
//
//int n, a, b;
//std::array<int, 100> h{ 0 };
//std::vector<int> Vec, Temp;
//
//int Ans = INT_MAX;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//// DFS(Now, Sum)表示：
//// 能打败前Now - 1个弓箭手需要最少打Sum发
//void DFS(int Now, int Sum)
//{
//    if (Sum >= Ans) // 剪枝
//    {
//        return;
//    }
//
//    if (Now == n - 1)   // 搜完了，因为最后一个人不能直接打，只能被间接打
//    {
//        if (h[n - 1] < 0)   // 如果最后一个也被打死了，那就可以更新答案
//        {
//            Ans = Sum;
//            Vec = Temp;
//        }
//
//        return;
//    }
//
//    // 否则就取肯定能打败其中一个的方案进行DFS
//    for (int i = 0;
//        i <= std::max({ (h[Now - 1] / b), (h[Now] / a), (h[Now + 1] / b) }) + 1;
//        ++i)
//    {
//        if (h[Now - 1] - b * i < 0) // 如果能打败最左边的那一个，满足我们DFS的要求
//        {
//            h[Now - 1] -= b * i;    // 那就试一下释放攻击
//            h[Now] -= a * i;        // 注意，三个人都会受伤
//            h[Now + 1] -= b * i;
//            for (int t = 0; t < i; ++t)
//            {
//                Temp.push_back(Now + 1);
//            }
//
//            DFS(Now + 1, Sum + i);  // 往下搜下一个
//
//            h[Now - 1] += b * i;    // 回溯
//            h[Now] += a * i;
//            h[Now + 1] += b * i;
//            for (int t = 0; t < i; ++t)
//            {
//                Temp.pop_back();
//            }
//        }
//    }
//
//    return;
//}
//
//int main()
//{
//    n = Read();
//    a = Read();
//    b = Read();
//    for (int i = 0; i < n; ++i)
//    {
//        h[i] = Read();
//    }
//
//    // 我们从0开始编号，注意第一个和最后一个人不能直接打
//    DFS(1, 0);
//
//    std::cout << Ans << std::endl;
//    for (const auto &r : Vec)
//    {
//        std::cout << r << ' ';
//    }
//    std::putchar('\n');
//
//    return 0;
//}
////楼上大佬的题解我有点不太理解
////我发一个跟我一样弱的都能看懂的做法
////希望能对大家有帮助
//#include <iostream>
//#include <vector>
//#include <utility>
//#include <set>
//#include <array>
//
////这题数据量还是比较大的，上快读加速明显
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    static std::array<int, 100000> Book{ 0 };
//    int n, k;
//    n = Read();
//    k = Read();
//
//    //v：存放答案的左端点和右端点
//    //s：可行序列
//    //l：左端点
//    //r：右端点
//    //Ans：最长的序列长度
//    std::vector<std::pair<int, int>> v;
//    std::multiset<int> s;
//    int l = 0, Ans = 0;
//    for (int r = 0; r < n; ++r)
//    {
//        Book[r] = Read();
//        s.insert(Book[r]);  // 利用std::multiset有序且可重复的特性
//        while (*s.crbegin() - *s.cbegin() > k)
//        {
//            //如果最大的减去最小的超范围了，那就不停地删掉左端点
//            //直到满足 <= k 为止
//            //这样做稍微有一点点尺取法的味道
//            s.erase(s.find(Book[l]));
//            ++l;
//        }
//
//        if (r - l + 1 > Ans)    // 如果得到了一个更长的序列，那就更新答案
//        {
//            v.clear();
//            Ans = r - l + 1;
//            v.push_back({ l + 1, r + 1 });  // 我从0开始算的，所以要加一
//        }
//        else if (r - l + 1 == Ans)  // 同样长的也要
//        {
//            v.push_back({ l + 1, r + 1 });
//        }
//    }
//
//    std::cout << Ans << ' ' << v.size() << std::endl;
//    for (const auto &r : v)
//    {
//        std::cout << r.first << ' ' << r.second << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <array>
//#include <utility>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n, k;
//    n = Read();
//    k = Read();
//    static std::array<int, 100000> Book{ 0 };
//    for (int i = 1; i <= n; ++i)
//    {
//        Book[i] = Read();
//    }
//
//    std::vector<std::pair<int, int>> v;
//    std::deque<int> High, Low;
//    int l = 1, r = 1, Ans = 0, cnt = 0;
//    for ( ; r <= n; ++r)
//    {
//        while (!High.empty() && High.back() < Book[r])
//        {
//            High.pop_back();
//        }
//        High.push_back(Book[r]);
//
//        while (!Low.empty() && Low.back() > Book[r])
//        {
//            Low.pop_back();
//        }
//        Low.push_back(Book[r]);
//
//        while (!High.empty() && !Low.empty() && High.front() - Low.front() > k)
//        {
//            if (v.empty() || (r - l) > Ans)
//            {
//                v.clear();
//                cnt = 1;
//                Ans = r - l;
//                v.push_back({ l, r - 1 });
//            }
//            else if (!v.empty() && r - l == Ans)
//            {
//                ++cnt;
//                v.push_back({ l, r - 1 });
//            }
//
//            if (High.front() == Book[l])
//            {
//                High.pop_front();
//            }
//            if (Low.front() == Book[l])
//            {
//                Low.pop_front();
//            }
//            ++l;
//        }
//
//        std::puts("High:");
//        for (const auto &r : High)
//        {
//            std::cout << r << ' ';
//        }
//        std::putchar('\n');
//        std::puts("Low:");
//        for (const auto &r : Low)
//        {
//            std::cout << r << ' ';
//        }
//        std::putchar('\n');
//        std::cout << l << ' ' << r << std::endl;
//        std::puts("-----------------------");
//    }
//
//    while (l <= n)
//    {
//        if (v.empty() || (r - l) > Ans)
//        {
//            v.clear();
//            cnt = 1;
//            Ans = r - l;
//            v.push_back({ l, r - 1 });
//        }
//        else if (!v.empty() && r - l == Ans)
//        {
//            ++cnt;
//            v.push_back({ l, r - 1 });
//        }
//
//        if (High.front() == Book[l])
//        {
//            High.pop_front();
//        }
//        if (Low.front() == Book[l])
//        {
//            Low.pop_front();
//        }
//        ++l;
//
//        std::puts("High:");
//        for (const auto &r : High)
//        {
//            std::cout << r << ' ';
//        }
//        std::putchar('\n');
//        std::puts("Low:");
//        for (const auto &r : Low)
//        {
//            std::cout << r << ' ';
//        }
//        std::putchar('\n');
//        std::cout << l << ' ' << r << std::endl;
//        std::puts("-----------------------");
//    }
//
//    std::cout << Ans << ' ' << cnt << std::endl;
//    for (const auto &r : v)
//    {
//        std::cout << r.first << ' ' << r.second << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int main()
//{
//    std::array<int, 100> p{ 0 }, q{ 0 };
//
//    int n;
//    std::cin >> n;
//    int Sum = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> p[i];
//        Sum += p[i];
//    }
//
//    int Avg = Sum / n;
//    for (int i = 1; i < n; ++i)
//    {
//        q[i] = q[i - 1] - Avg + p[i];
//    }
//    std::sort(q.begin(), q.begin() + n);
//
//    int Ans = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        Ans += std::abs(q[i] - q[n / 2]);
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<int, 100> a{ 0 };
//    int n;
//    std::cin >> n;
//
//    int Sum = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> a[i];
//        Sum += a[i];
//    }
//
//    int Avg = Sum / n;
//    for (int i = 0; i < n; ++i)
//    {
//        a[i] -= Avg;
//    }
//
//    int Ans = 0;
//    for (int i = 0; i < n - 1; ++i)
//    {
//        if (a[i] != 0)
//        {
//            a[i + 1] += a[i];
//            ++Ans;
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <array>
//#include <unordered_map>
//
//int main()
//{
//    static std::array<std::unordered_map<std::string, int>, 100000> Catalogue;
//    int n;
//    std::cin >> n;
//
//    int Ans = 0;
//    while (n--)
//    {
//        std::string Str;
//        std::cin >> Str;
//
//        int Now = 0;
//        std::string File;
//        for (std::size_t i = 1; i <= Str.size(); ++i)
//        {
//            if (Str[i] == '/' || i == Str.size())
//            {
//                if (Catalogue[Now][File] == 0)
//                {
//                    ++Ans;
//                    Catalogue[Now][File] = Ans;
//                    Now = Ans;
//                }
//                else
//                {
//                    Now = Catalogue[Now][File];
//                }
//            }
//            else
//            {
//                File.push_back(Str[i]);
//            }
//        }
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include <vector>
//
//int n, a, b;
//std::array<int, 100> h{ 0 };
//std::vector<int> Vec, Temp;
//
//int Ans = INT_MAX;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//void DFS(int Now, int Sum)
//{
//    if (Sum >= Ans)
//    {
//        return;
//    }
//
//    if (Now == n - 1)
//    {
//        if (h[n - 1] < 0)
//        {
//            Ans = Sum;
//            Vec = Temp;
//        }
//
//        return;
//    }
//
//    for (int i = 0;
//        i <= std::max({ (h[Now - 1] / b), (h[Now] / a), (h[Now + 1] / b) }) + 1;
//        ++i)
//    {
//        if (h[Now - 1] - b * i < 0)
//        {
//            h[Now - 1] -= b * i;
//            h[Now] -= a * i;
//            h[Now + 1] -= b * i;
//            for (int t = 0; t < i; ++t)
//            {
//                Temp.push_back(Now + 1);
//            }
//
//            DFS(Now + 1, Sum + i);
//
//            h[Now - 1] += b * i;
//            h[Now] += a * i;
//            h[Now + 1] += b * i;
//            for (int t = 0; t < i; ++t)
//            {
//                Temp.pop_back();
//            }
//        }
//    }
//
//    return;
//}
//
//int main()
//{
//    n = Read();
//    a = Read();
//    b = Read();
//    for (int i = 0; i < n; ++i)
//    {
//        h[i] = Read();
//    }
//
//    DFS(1, 0);
//
//    std::cout << Ans << std::endl;
//    for (const auto &r : Vec)
//    {
//        std::cout << r << ' ';
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include <vector>
//
//int n, a, b;
//std::array<int, 100> h{ 0 };
//std::vector<int> Vec, Temp;
//
//int Ans = INT_MAX;
//
//int Ceil(int x, int y)
//{
//    return (x - 1) / y + 1;
//}
//
//void DFS(int Now, int Sum)
//{
//    if (Sum > Ans)
//    {
//        return;
//    }
//
//    if (Now == n - 1)
//    {
//        if (h[n - 1] < 0)
//        {
//            Ans = Sum;
//            Vec = Temp;
//        }
//
//        return;
//    }
//
//    for (int i = 0;
//         i <= std::max({ Ceil(h[Now - 1], b), Ceil(h[Now], a), Ceil(h[Now + 1], b) });
//         ++i)
//    {
//        if (h[Now - 1] - b * i < 0)
//        {
//            h[Now - 1] -= b * i;
//            h[Now] -= a * i;
//            h[Now + 1] -= b * i;
//            for (int t = 0; t < i; ++t)
//            {
//                Temp.push_back(Now + 1);
//            }
//
//            DFS(Now + 1, Sum + i);
//
//            h[Now - 1] += b * i;
//            h[Now] += a * i;
//            h[Now + 1] += b * i;
//            for (int t = 0; t < i; ++t)
//            {
//                Temp.pop_back();
//            }
//        }
//    }
//
//    return;
//}
//
//int main()
//{
//    std::cin >> n >> a >> b;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> h[i];
//    }
//
//    DFS(1, 0);
//
//    std::cout << Ans << std::endl;
//    for (const auto &r : Vec)
//    {
//        std::cout << r << ' ';
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    std::array<int, 101> RP{ 0 }, Time{ 0 }, RMB{ 0 };
//    int n;
//    n = Read();
//    for (int i = 0; i < n; ++i)
//    {
//        RMB[i] = Read();
//        RP[i] = Read();
//        Time[i] = Read();
//    }
//
//    int M, R;
//    M = Read();
//    R = Read();
//
//    std::array<std::array<int, 101>, 101> DPSum{ 0 }, DPTime{ 0 };
//    for (int i = 0; i < n; ++i)
//    {
//        for (int m = M; m >= RMB[i]; --m)
//        {
//            for (int r = R; r >= RP[i]; --r)
//            {
//                if (DPSum[m][r] < DPSum[m - RMB[i]][r - RP[i]] + 1)
//                {
//                    DPSum[m][r] = DPSum[m - RMB[i]][r - RP[i]] + 1;
//                    DPTime[m][r] = DPTime[m - RMB[i]][r - RP[i]] + Time[i];
//                }
//                else if (DPSum[m][r] == DPSum[m - RMB[i]][r - RP[i]] + 1)
//                {
//                    DPTime[m][r] = std::min(DPTime[m][r],
//                                            DPTime[m - RMB[i]][r - RP[i]] + Time[i]);
//                }
//            }
//        }
//    }
//
//    std::cout << DPTime[M][R] << std::endl;
//
//    return 0;
//}
//// 首先先了解一下位运算的一些基本操作：
//// &：表示一个元素是否在这个集合里
//// |：表示将这个元素加入这个集合中
//// ^：表示将这个元素从这个集合中删除
//// 然后我们就用二进制数的每一位表示一个科目的状态
//// 最后就是简单的dp，难点在于对各个科目状态的表达
//// 详见代码和注释
//#include <iostream>
//#include <cstring>
//#include <sstream>
//#include <algorithm>
//#include <string>
//
//constexpr int MaxN = 100 + 20 + 5;
//constexpr int MaxS = 8;
//constexpr int INF = 1000000000;
//
//int m, n, s, c[MaxN], st[MaxN], d[MaxN][1 << MaxS][1 << MaxS];
//
//// dp(i, s0, s1, s2)表示：
//// 已经考虑了前i个人，还剩s0种没人会的科目，s1种一人会的科目，s2种两人以上会的科目
//int dp(int i, int s0, int s1, int s2)
//{
//    if (i == m + n) // 搜完了所有的人了
//    {   // 如果s2还没满的话，那就说明不可能满足了
//        return s2 == (1 << s) - 1 ? 0 : INF;
//    }
//
//    int &Ans = d[i][s1][s2];
//    if (Ans >= 0)   // 记忆化搜索的体现，因为没被搜过的时候是-1
//    {
//        return Ans;
//    }
//
//    Ans = INF;  // 没被搜过，就先初始化一下，设为INF
//    if (i >= m)
//    {
//        // 在可选的情况下却不选i。先算出不选i的结果，等待后面与选i的的结果比较。
//        Ans = dp(i + 1, s0, s1, s2);
//    }
//
//    // 下面是选i的情况：
//    // m0：在st[i]中没人会的，但i会的
//    // m1：在st[i]中只有一个人会的，i也会的
//    int m0 = st[i] & s0, m1 = st[i] & s1;
//    s0 ^= m0;   // 在s0中消除那些i会的
//    s1 = (s1 ^ m1) | m0;    // 在已经有一个人会的技能里面减去i会的，
//                            // 因为不减的话就是两个人会了
//                            // 然后再加上i独有的会的，就成了新的一人会的集合
//    s2 |= m1;   // 在s2中加上m1，表示现在有两个人会的有这么多
//    Ans = std::min(Ans, c[i] + dp(i + 1, s0, s1, s2));  // 看是选i贵还是不选i贵
//
//    return Ans;
//}
//
//int main()
//{
//    int x;
//    std::string Line;
//    while (std::getline(std::cin, Line))
//    {
//        std::stringstream ss(Line);
//        ss >> s >> m >> n;  // 共s个科目，m名在职，n名应聘
//        if (s == 0)
//        {
//            break;
//        }
//
//        for (int i = 0; i < m + n; ++i)
//        {
//            std::getline(std::cin, Line);
//            std::stringstream ss(Line);
//            ss >> c[i]; // 第i人所需要的工资
//            st[i] = 0;  // 他能教的科目先设为空
//            while (ss >> x)
//            {
//                st[i] |= (1 << (x - 1));    // 添加进去他所能教的科目集合里面
//            }                               // 减一是因为输入中的编号从1开始
//        }
//
//        std::memset(d, -1, sizeof(d));  // 表示还没有被搜过
//        std::cout << dp(0, (1 << s) - 1, 0, 0) << std::endl;
//    }             // 初始搜时所有科目都没人教，从0号开始搜
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//constexpr int INF = 999999999;
//
//class Edge
//{
//public:
//    int To, Cap, Rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) :
//        To(to), Cap(cap), Rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, 2500> G;
//std::array<int, 2500> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].emplace_back(To, Cap, G[To].size());
//    G[To].emplace_back(From, 0, G[From].size() - 1);
//}
//
//void BFS(int s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//
//    std::queue<int> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.Cap > 0 && Level[e.To] < 0)
//            {
//                Level[e.To] = Level[v] + 1;
//                Que.push(e.To);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < static_cast<int>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//
//        if (e.Cap > 0 && Level[v] < Level[e.To])
//        {
//            int d = DFS(e.To, t, std::min(f, e.Cap));
//
//            if (d > 0)
//            {
//                e.Cap -= d;
//                G[e.To][e.Rev].Cap += d;
//
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//
//    while (1)
//    {
//        BFS(s);
//
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//
//        int F;
//        while ((F = DFS(s, t, INF)) > 0)
//        {
//            Flow += F;
//        }
//    }
//}
//
//int main()
//{
//    int n, m, x;
//    std::cin >> n >> m >> x;
//    for (int i = 0; i < m; ++i)
//    {
//        int a, b, c;
//        std::cin >> a >> b >> c;
//        AddEdge(a, b, c);
//    }
//
//    int Ans = MaxFlow(1, n);
//    if (Ans == 0)
//    {
//        std::puts("Orz Ni Jinan Saint Cow!");
//    }
//    else
//    {
//        std::cout << Ans << ' ' << (x - 1) / Ans + 1 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//constexpr int INF = 999999999;
//
//class Edge
//{
//public:
//    int To, Cap, Rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) :
//        To(to), Cap(cap), Rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, 2500> G;
//std::array<int, 2500> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].emplace_back(To, Cap, G[To].size());
//    G[To].emplace_back(From, 0, G[From].size() - 1);
//}
//
//void BFS(int s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//
//    std::queue<int> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.Cap > 0 && Level[e.To] < 0)
//            {
//                Level[e.To] = Level[v] + 1;
//                Que.push(e.To);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < static_cast<int>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//
//        if (e.Cap > 0 && Level[v] < Level[e.To])
//        {
//            int d = DFS(e.To, t, std::min(f, e.Cap));
//
//            if (d > 0)
//            {
//                e.Cap -= d;
//                G[e.To][e.Rev].Cap += d;
//
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//
//    while (1)
//    {
//        BFS(s);
//
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//
//        int F;
//        while ((F = DFS(s, t, INF)) > 0)
//        {
//            Flow += F;
//        }
//    }
//}
//
//int main()
//{
//    int n, m;
//    std::cin >> n >> m;
//    for (int i = 0; i < n; ++i)
//    {
//        int s, e, c;
//        std::cin >> s >> e >> c;
//        AddEdge(s, e, c);
//    }
//
//    std::cout << MaxFlow(1, m) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <array>
//#include <algorithm>
//
//constexpr int MaxN = 100000 + 5;
//int n, T;
//std::array<std::vector<int>, MaxN> Sons;
//
//int dp(int u)
//{
//    if (Sons[u].empty())
//    {
//        return 1;
//    }
//
//    auto k = Sons[u].size();
//    std::vector<int> d;
//    for (std::size_t i = 0; i < k; ++i)
//    {
//        d.push_back(dp(Sons[u][i]));
//    }
//    std::sort(d.begin(), d.end());
//
//    auto c = (k * T - 1) / 100 + 1;
//    int Ans = 0;
//    for (decltype(c) i = 0; i < c; ++i)
//    {
//        Ans += d[i];
//    }
//
//    return Ans;
//}
//
//int main()
//{
//    int f;
//    while (std::cin >> n >> T && n)
//    {
//        for (int i = 0; i <= n; ++i)
//        {
//            Sons[i].clear();
//        }
//
//        for (int i = 1; i <= n; ++i)
//        {
//            std::cin >> f;
//            Sons[f].push_back(i);
//        }
//
//        std::cout << dp(0) << std::endl;
//    }
//
//    return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//constexpr int MaxN = 100 + 5;
//char S[MaxN];
//int n, d[MaxN][MaxN];
//
//bool Match(char a, char b)
//{
//    return (a == '(' && b == ')') || (a == '[' && b == ']');
//}
//
//void dp()
//{
//    for (int i = 0; i < n; ++i)
//    {
//        d[i + 1][i] = 0;
//        d[i][i] = 1;
//    }
//
//    for (int i = n - 2; i >= 0; --i)
//    {
//        for (int j = i + 1; j < n; ++j)
//        {
//            d[i][j] = n;
//            if (Match(S[i], S[j]))
//            {
//                d[i][j] = std::min(d[i][j], d[i + 1][j - 1]);
//            }
//
//            for (int k = i; k < j; ++k)
//            {
//                d[i][j] = std::min(d[i][j], d[i][k] + d[k + 1][j]);
//            }
//        }
//    }
//}
//
//void Print(int i, int j)
//{
//    if (i > j)
//    {
//        return;
//    }
//
//    if (i == j)
//    {
//        if (S[i] == '(' || S[i] == ')')
//        {
//            std::printf("()");
//        }
//        else
//        {
//            std::printf("[]");
//        }
//
//        return;
//    }
//
//    int Ans = d[i][j];
//    if (Match(S[i], S[j]) && Ans == d[i + 1][j - 1])
//    {
//        std::putchar(S[i]);
//        Print(i + 1, j - 1);
//        std::putchar(S[j]);
//
//        return;
//    }
//
//    for (int k = i; k < j; ++k)
//    {
//        if (Ans == d[i][k] + d[k + 1][j])
//        {
//            Print(i, k);
//            Print(k + 1, j);
//
//            return;
//        }
//    }
//}
//
//int main()
//{
//    int T;
//    std::fgets(S, MaxN, stdin);
//    std::sscanf(S, "%d", &T);
//    std::fgets(S, MaxN, stdin);
//
//    while (T--)
//    {
//        std::fgets(S, MaxN, stdin);
//        n = std::strlen(S) - 1;
//        std::memset(d, -1, sizeof(d));
//
//        dp();
//
//        Print(0, n - 1);
//        std::putchar('\n');
//        if (T)
//        {
//            std::putchar('\n');
//        }
//
//        std::fgets(S, MaxN, stdin);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//constexpr int MaxN = 50 + 5;
//constexpr int INF = 1000000000;
//
//int main()
//{
//    int n, t;
//    std::array<int, MaxN> Len{ 0 };
//    std::array<std::array<int, MaxN * 180 + 678>, 2> d;
//
//    int T;
//    std::cin >> T;
//    for (int NO = 1; NO <= T; ++NO)
//    {
//        std::cin >> n >> t;
//        for (int i = 1; i <= n; ++i)
//        {
//            std::cin >> Len[i];
//        }
//
//        for (int i = 0; i < t; ++i)
//        {
//            d[0][i] = -1;
//        }
//        d[0][0] = 0;
//
//        int p = 1, Ans = 0;
//        for (int i = 1; i <= n; ++i)
//        {
//            for (int j = 0; j < t; ++j)
//            {
//                d[p][j] = d[p ^ 1][j];
//                if (j >= Len[i] && d[p ^ 1][j - Len[i]] >= 0)
//                {
//                    d[p][j] = std::max(d[p][j], d[p ^ 1][j - Len[i]] + 1);
//                }
//
//                Ans = std::max(Ans, d[p][j]);
//            }
//
//            p ^= 1;
//        }
//
//        // 从t - 1秒开始往前倒数是因为至少要留1秒给《劲歌金曲》
//        // 然后我们要唱得尽量久，所以就从后面开始
//        for (int i = t - 1; i >= 0; --i)
//        {
//            if (d[p ^ 1][i] == Ans)
//            {
//                std::printf("Case %d: %d %d\n", NO, Ans + 1, i + 678);
//                break;
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//constexpr int MaxN = 100 + 5;
//constexpr int INF = 1000000000;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int m, n, a[MaxN][MaxN], d[MaxN][MaxN], Next[MaxN][MaxN];
//
//    while (std::cin >> m >> n && m)
//    {
//        for (int i = 0; i < m; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                a[i][j] = Read();
//            }
//        }
//
//        int Ans = INF, First = 0;
//        for (int j = n - 1; j >= 0; --j)
//        {
//            for (int i = 0; i < m; ++i)
//            {
//                if (j == n - 1)
//                {
//                    d[i][j] = a[i][j];
//                }
//                else
//                {
//                    int Rows[3] = { i, i - 1, i + 1 };
//                    if (i == 0)
//                    {
//                        Rows[1] = m - 1;
//                    }
//                    if (i == m - 1)
//                    {
//                        Rows[2] = 0;
//                    }
//                    std::sort(Rows, Rows + 3);
//
//                    d[i][j] = INF;
//                    for (const auto &r : Rows)
//                    {
//                        int v = d[r][j + 1] + a[i][j];
//                        if (v < d[i][j])
//                        {
//                            d[i][j] = v;
//                            Next[i][j] = r;
//                        }
//                    }
//                }
//
//                if (j == 0 && d[i][j] < Ans)
//                {
//                    Ans = d[i][j];
//                    First = i;
//                }
//            }
//        }
//
//        std::cout << First + 1;
//        for (int i = Next[First][0], j = 1; j < n; i = Next[i][j], ++j)
//        {
//            std::printf(" %d", i + 1);
//        }
//        std::printf("\n%d\n", Ans);
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int p, q;
//    std::cin >> p >> q;
//
//    int Ans = -1;
//    for (int j = q; j > p; --j)
//    {
//        bool ok = true;
//        for (int i = 2; i * i <= j && i <= p; ++i)
//        {
//            if (j % i == 0)
//            {
//                ok = false;
//                break;
//            }
//        }
//
//        if (ok)
//        {
//            Ans = j;
//            break;
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_set>
//
//int main()
//{
//    std::unordered_set<int> s;
//    int n;
//    std::cin >> n;
//    while (n--)
//    {
//        int x;
//        std::cin >> x;
//        if (x > 0)
//        {
//            s.insert(x);
//        }
//    }
//
//    std::cout << s.size() << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//#include <unordered_set>
//
//std::unordered_set<int> s;
//
//int p, y;
//
//bool IsOK(int t)
//{
//    for (int i = 2; i <= p; ++i)
//    {
//        if (t % i == 0)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    std::cin >> p >> y;
//    while (y > 1)
//    {
//        bool f = false;
//        
//        for (auto it = s.cbegin(); it != s.cend(); ++it)
//        {
//            if (y % *it == 0)
//            {
//                f = true;
//                break;
//            }
//        }
//
//        if (!f)
//        {
//            if (IsOK(y))
//            {
//                std::cout << y << std::endl;
//                break;
//            }
//        }
//
//        s.insert(y);
//
//        --y;
//    }
//
//    if (y == 1)
//    {
//        std::cout << -1 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//bool IsPrime(int t)
//{
//    for (int i = 2; i <= std::sqrt(t); ++i)
//    {
//        if (t % i == 0)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    int p, y;
//    std::cin >> p >> y;
//
//    int t;
//    for (t = y; t > p; --t)
//    {
//        if (IsPrime(t))
//        {
//            std::cout << t << std::endl;
//            break;
//        }
//    }
//
//    if (t == p)
//    {
//        std::cout << -1 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cstring>
//
//bool IsPrime[10000001] = { true };
//
//int main()
//{
//    std::memset(IsPrime, true, sizeof(IsPrime));
//    IsPrime[0] = IsPrime[1] = false;
//    for (int i = 2; i <= 10000001; ++i)
//    {
//        if (IsPrime[i])
//        {
//            for (int j = 2 * i; j <= 10000001; j += i)
//            {
//                IsPrime[j] = false;
//            }
//        }
//    }
//
//    int p, y, t;
//    std::cin >> p >> y;
//    for (t = y; t >= 2; --t)
//    {
//        if (IsPrime[t])
//        {
//            std::cout << t << std::endl;
//            break;
//        }
//    }
//
//    if (t == 1)
//    {
//        std::cout << -1 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_set>
//
//int main()
//{
//    std::unordered_set<int> s;
//    int n, x;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> x;
//        if (x > 0)
//        {
//            s.insert(x);
//        }
//    }
//
//    std::cout << s.size() << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//constexpr int MaxN = 50 + 5;
//constexpr int MaxT = 200 + 5;
//constexpr int INF = 1000000000;
//
//int main()
//{
//    int t[MaxN], HasTrain[MaxT][MaxN][2];
//    int dp[MaxT][MaxN];
//
//    int NO = 0, n, T;
//    while (std::cin >> n >> T && n)
//    {
//        int M1, M2, d;
//        for (int i = 1; i <= n - 1; ++i)
//        {
//            std::cin >> t[i];
//        }
//
//        std::memset(HasTrain, 0, sizeof(HasTrain));
//        std::cin >> M1;
//        while (M1--)
//        {
//            std::cin >> d;
//            for (int j = 1; j <= n - 1; ++j)
//            {
//                if (d <= T)
//                {
//                    HasTrain[d][j][0] = 1;
//                }
//
//                d += t[j];
//            }
//        }
//
//        std::cin >> M2;
//        while (M2--)
//        {
//            std::cin >> d;
//            for (int j = n - 1; j >= 1; --j)
//            {
//                if (d <= T)
//                {
//                    HasTrain[d][j + 1][1] = 1;
//                }
//
//                d += t[j];
//            }
//        }
//
//        for (int i = 1; i <= n - 1; ++i)
//        {
//            dp[T][i] = INF;
//        }
//        dp[T][n] = 0;
//
//        for (int i = T - 1; i >= 0; --i)
//        {
//            for (int j = 1; j <= n; ++j)
//            {
//                dp[i][j] = dp[i + 1][j] + 1;
//                if (j < n && HasTrain[i][j][0] && i + t[j] <= T)
//                {
//                    dp[i][j] = std::min(dp[i][j], dp[i + t[j]][j + 1]);
//                }
//                if (j > 1 && HasTrain[i][j][1] && i + t[j - 1] <= T)
//                {
//                    dp[i][j] = std::min(dp[i][j], dp[i + t[j - 1]][j - 1]);
//                }
//            }
//        }
//
//        std::cout << "Case Number " << ++NO << ": ";
//        if (dp[0][1] >= INF)
//        {
//            std::puts("impossible");
//        }
//        else
//        {
//            std::cout << dp[0][1] << std::endl;
//        }
//    }
//
//    return 0;
//}
//// 这一题就是纯正的物理题，搞不懂和编程有什么关系
//// 不过它的分类讨论也有一点点的繁琐
//// 但是比起高三的时候做的运动学问题已经好很多了
//// 要注意这一题有一个坑点：
//// 就是不是[0, d]的最大速度为w，而是只要通过d这一点时
//// 速度为w即可，为了这个点我还WA了一发
//// 详见代码里面的注释
//#include <iostream>
//#include <cmath>
//
//// 返回以初速为v1，最大速率为v2，加速度为a，通过l的最短时间
//double Move(double v1, double v2, double a, double l)
//{
//    double t = 0.0;
//    double s = (v2 * v2 - v1 * v1) / 2 / a;
//    if (s >= l)
//    {
//        t = (-v1 + std::sqrt(v1 * v1 + 2 * a * l)) / a;
//    }
//    else
//    {
//        double t1 = (v2 - v1) / a;
//        double t2 = (l - (v2 * v2 - v1 * v1) / 2 / a) / v2;
//        t = t1 + t2;
//    }
//
//    return t;
//}
//
//int main()
//{
//    double a, v, l, d, w, t;
//    std::cin >> a >> v >> l >> d >> w;
//
//    double s = v * v / 2 / a;
//    if (w >= v) // 如果最大速率还达不到限速，那就一直开过去就好了
//    {
//        t = Move(0, v, a, l);
//    }
//    else
//    {
//        double s1 = w * w / 2 / a;
//        if (s1 >= d)    // 如果一直加速到d还没达到限速w
//        {               // 那就一直开过去没事的
//            t = Move(0, v, a, l);
//        }
//        else   // 这里的讨论就需要自己动手画个图，解一下简单的方程了
//        {
//            double t11 = std::sqrt((2 * a * d + w * w) / 2 / a / a);
//
//            double t1;  // [0, d]的总时间
//            if (t11 * a <= v)   // 加速到某一速度然后减速到w通过d
//            {
//                t1 = 2 * t11 - w / a;
//            }
//            else   // 先加速到v，然后匀速行驶一段，最后减速到w通过d
//            {
//                double s11 = v * v / 2 / a; // 加速阶段走的路程
//                double s12 = (v * v - w * w) / 2 / a;   // 减速阶段走的路程
//                t1 = v / a + (v - w) / a + (d - s11 - s12) / v;
//            }
//            double t2 = Move(w, v, a, l - d);   // 通过d后一直到l的时间
//            t = t1 + t2;
//        }
//    }
//
//    std::printf("%.12f\n", t);
//
//    return 0;
//}
//// 这道题就是一道标准的DFS题，各种套路都是很基础的
//// 具体见代码
//#include <iostream>
//#include <string>
//#include <vector>
//#include <array>
//
//std::vector<std::string> Map;   // 整张地图
//std::array<bool, 26> Num{ 0 };  // 标记搜到过的桌子，这里类似桶排，就不用写判重了
//std::array<int, 4> dx{ 0, 1, -1, 0 }, dy{ -1, 0, 0, 1 };
//// 注意是四个方向而不是八个方向
//
//int n, m;   // 宽和长
//char p; // 总统桌的字母
//
//void DFS(int x, int y)
//{
//    // 超出边界了就立即返回
//    if (x < 0 || x >= n || y < 0 || y >= m)
//    {
//        return;
//    }
//    else
//    {
//        if (Map[x][y] != '.')   // 如果有桌子
//        {
//            if (Map[x][y] == p) // 如果是总统桌
//            {
//                Map[x][y] = '.';    // 就标记一下已经搜过了
//
//                for (int i = 0; i < 4; ++i) // 和总统桌连着的四个方向搜下去
//                {
//                    DFS(x + dx[i], y + dy[i]);
//                }
//            } 
//            else   // 如果是总统桌以外的桌子
//            {
//                Num[Map[x][y] - 'A'] = true;    // 就标记这个字母的桌子被搜到了
//                Map[x][y] = '.';    // 标记一下已经被搜过了
//            }
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> n >> m >> p;
//    std::string Str;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Str;
//        Map.push_back(Str);
//    }
//
//    int x, y;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j)
//        {
//            if (Map[i][j] == p) // 找总统桌的位置
//            {
//                x = i;
//                y = j;
//                goto Outside;   // 用goto跳出多重循环很方便的
//            }
//        }
//    }
//
//Outside:
//    DFS(x, y);  // 从第一张总统桌的位置往下搜
//
//    int Sum = 0;
//    for (int i = 0; i < 26; ++i)
//    {
//        if (Num[i])
//        {
//            ++Sum;  // 统计有多少张被搜到的桌子
//        }
//    }
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//    std::vector<int> v(4);
//    std::cin >> v[0] >> v[1] >> v[2] >> v[3];
//    std::sort(v.begin(), v.end());
//
//    if (v[0] + v[1] > v[2] || v[1] + v[2] > v[3])
//    {
//        std::puts("TRIANGLE");
//    }
//    else
//    {
//        if (v[0] + v[1] == v[2] || v[1] + v[2] == v[3])
//        {
//            std::puts("SEGMENT");
//        }
//        else
//        {
//            std::puts("IMPOSSIBLE");
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using ll = long long;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n;
//    n = Read();
//    std::vector<int> v(n);
//    for (int i = 0; i < n; ++i)
//    {
//        v[i] = Read();
//    }
//
//    auto Hightest = std::max_element(v.cbegin(), v.cend());
//    std::vector<int> w(Hightest, v.cend());
//    for (auto it = v.cbegin(); it != Hightest; ++it)
//    {
//        w.push_back(*it);
//    }
//
//    std::vector<int> Left(n, -1);
//    for (int i = 1; i < n; ++i)
//    {
//        int t = i - 1;
//        while (w[i] > w[t])
//        {
//            t = Left[t];
//        }
//
//        Left[i] = w[i] == w[t] ? Left[t] : t;
//    }
//
//    std::vector<int> Right(n, n), Same(n, 0);
//    for (int i = n - 2; i >= 0; --i)
//    {
//        int t = i + 1;
//        while (t < n && w[i] > w[t])
//        {
//            t = Right[t];
//        }
//
//        if (t == n)
//        {
//            Right[i] = n;
//            continue;
//        }
//
//        if (w[i] == w[t])
//        {
//            Right[i] = Right[t];
//            Same[i] = Same[t] + 1;
//        }
//        else
//        {
//            Right[i] = t;
//        }
//    }
//
//    ll Ans = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        if (Left[i] >= 0)
//        {
//            ++Ans;
//        }
//        if (Right[i] < n)
//        {
//            ++Ans;
//        }
//        if (Right[i] == n && Left[i] > 0)
//        {
//            ++Ans;
//        }
//
//        Ans += Same[i];
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//double Move(double v1, double v2, double a, double l)
//{
//    double t = 0.0;
//    double s = (v2 * v2 - v1 * v1) / 2 / a;
//    if (s >= l)
//    {
//        t = (-v1 + std::sqrt(v1 * v1 + 2 * a * l)) / a;
//    }
//    else
//    {
//        double t1 = (v2 - v1) / a;
//        double t2 = (l - (v2 * v2 - v1 * v1) / 2 / a) / v2;
//        t = t1 + t2;
//    }
//
//    return t;
//}
//
//int main()
//{
//    double a, v, l, d, w, t;
//    std::cin >> a >> v >> l >> d >> w;
//
//    double s = v * v / 2 / a;
//    if (w >= v)
//    {
//        t = Move(0, v, a, l);
//    }
//    else
//    {
//        double s1 = w * w / 2 / a;
//        if (s1 >= d)
//        {
//            double t1 = std::sqrt(2 * d / a);
//            double v1 = t1 * a;
//            double t2 = Move(v1, v, a, l - d);
//            t = t1 + t2;
//        }
//        else
//        {
//            double t11 = std::sqrt((2 * a * d + w * w) / 2 / a / a);
//
//            double t1;
//            if (t11 * a <= v)
//            {
//                t1 = 2 * t11 - w / a;
//            }
//            else
//            {
//                double s11 = v * v / 2 / a;
//                double s12 = (v * v - w * w) / 2 / a;
//                t1 = v / a + (v - w) / a + (d - s11 - s12) / v;
//            }
//            double t2 = Move(w, v, a, l - d);
//            t = t1 + t2;  
//        }
//    }
//
//    std::printf("%.12f\n", t);
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//#include <stack>
//
//std::array<int, 1000001> a{ 0 };
//
//int main()
//{
//    std::string Str;
//    std::cin >> Str;
//
//    int Max = 0, cnt = 1;
//    std::stack<int> s;
//    for (std::size_t i = 0; i < Str.size(); ++i)
//    {
//        if (Str[i] == '(')
//        {
//            s.push(i + 1);
//        }
//        else
//        {
//            if (!s.empty())
//            {
//                auto t = s.top();
//                s.pop();
//
//                a[i + 1] = a[t - 1] + i - t + 2;
//                if (a[i + 1] > Max)
//                {
//                    Max = a[i + 1];
//                    cnt = 1;
//                }
//                else if (a[i + 1] == Max)
//                {
//                    ++cnt;
//                }
//            }
//        }
//    }
//
//    std::cout << Max << ' ' << cnt << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <queue>
//#include <functional>
//
//int main()
//{
//    int T;
//    while (std::cin >> T && T)
//    {
//        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
//        int x;
//        for (int i = 0; i < T; ++i)
//        {
//            std::cin >> x;
//            q.push(x);
//        }
//
//        int Tol = 0;
//        int a, b;
//        while (q.size() != 1)
//        {
//            a = q.top();
//            q.pop();
//
//            b = q.top();
//            q.pop();
//
//            Tol += a + b;
//            q.push(a + b);
//        }
//
//        std::cout << Tol << std::endl;
//    }
//
//    return 0;
//}
//// 这一题的更详细的解释还是得看紫书P243
//// 我这里只是给出其中一种按书上思路的实现并且附上详尽的注释
//// 希望能对大家理解这一题有一点点的帮助
//#include <iostream>
//#include <array>
//#include <string>
//
//constexpr int MaxN = 100000 + 5;
//std::array<int, MaxN> Sum{ 0 }, p{ 0 };
//
//// 比较k-p2p1和k-p4p3的斜率大小
//// 用了乘法是因为交叉相乘了，变一下形即可
//int CompareAverage(int x1, int x2, int x3, int x4)
//{
//    return (Sum[x2] - Sum[x1 - 1]) * (x4 - x3 + 1)
//         - (Sum[x4] - Sum[x3 - 1]) * (x2 - x1 + 1);
//}
//
//int main()
//{
//    int n, L, T;
//    std::string s;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> n >> L >> s;
//
//        // 计算s[i]的前缀和
//        Sum[0] = 0;
//        for (int i = 1; i <= n; ++i)
//        {
//            Sum[i] = Sum[i - 1] + s[i - 1] - '0';
//        }
//
//        // p[i..j)是左端点的序列，这是一个单调队列
//        int AnsL = 1, AnsR = L;
//        int i = 0, j = 0;   // i是队头，j是队尾
//        for (int t = L; t <= n; ++t)    // 以t作为线段的右端点
//        {
//            // 删除所有的上凸点：
//            // 取出队尾两个点，比较它们和t - L的斜率大小
//            // 发现上凸就弹出队尾元素，维护单调性
//            while (j - i > 1 && CompareAverage(p[j - 2], t - L, p[j - 1], t - L) >= 0)
//            {
//                --j;
//            }
//            p[j++] = t - L + 1; // 入队，同时队尾加一
//
//            // i是线段左端点的在p[]中的下标
//            // 如果p[i]-p[i + 1]-t下凸，则p[i]不够p[i + 1]优
//            // 那就弹出队头
//            while (j - i > 1 && CompareAverage(p[i], t, p[i + 1], t) <= 0)
//            {
//                ++i;
//            }
//
//            // 如果斜率更大或者斜率相同但区间更小
//            // 就更新答案
//            int c = CompareAverage(p[i], t, AnsL, AnsR);
//            if (c > 0 || c == 0 && t - p[i] < AnsR - AnsL)
//            {
//                AnsL = p[i];
//                AnsR = t;
//            }
//        }
//
//        std::cout << AnsL << ' ' << AnsR << std::endl;
//    }
//
//    return 0;
//}
//// 这一题的更详细的解释还是得看紫书P242
//// 我这里只是给出其中一种按书上思路的实现并且附上详尽的注释
//// 希望能对大家理解这一题有一点点的帮助
//#include <iostream>
//#include <array>
//#include <set>
//
//constexpr int MaxN = 200000 + 5;
//
//int n;
//std::array<int, MaxN> a{ 0 }, f{ 0 }, g{ 0 };
//
//struct Pair
//{
//    int a, g;
//
//    Pair() = default;
//    Pair(int a, int g) :
//        a(a), g(g)
//    {
//    }
//
//    // 这是给std::set用的，让其以a的升序来排列
//    // 这里用上std::set是利用了其有序的性质
//    bool operator<(const Pair &r) const noexcept
//    {
//        return a < r.a;
//    }
//};
//
//// 这一题输入量较大，还是最好用上快读
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int T;
//    T = Read();
//    while (T--)
//    {
//        std::cin >> n;
//        for (int i = 0; i < n; ++i)
//        {
//            a[i] = Read();
//        }
//
//        // 如果原序列长度为一，那最大递增序列长度也只能是一
//        if (n == 1)
//        {
//            std::puts("1");
//            continue;
//        }
//
//        // g[i]为以第i个元素结尾的最长L序列长度
//        g[0] = 1;
//        for (int i = 1; i < n; ++i) // 这个要正着数
//        {
//            if (a[i - 1] < a[i])    // 如果序列能递增
//            {
//                g[i] = g[i - 1] + 1;    // 那就是上一个长度再加一，类似于动态规划
//            }
//            else
//            {
//                g[i] = 1;   // 否则以它结尾的最大递增序列只能是它自己
//            }
//        }
//
//        // f[i]为以第i个元素开头的最长L序列长度
//        f[n - 1] = 1;
//        for (int i = n - 2; i >= 0; --i)    //这个要倒着数
//        {
//            if (a[i] < a[i + 1])    // 如果序列能递增
//            {
//                f[i] = f[i + 1] + 1;    // 那就是上一个长度再加一，类似于动态规划
//            }
//            else
//            {
//                f[i] = 1;   // 否则以它结尾的最大递增序列只能是它自己
//            }
//        }
//
//        std::set<Pair> s;
//        s.insert(Pair(a[0], g[0]));
//        int Ans = 1;    // 最大递增序列至少有一个元素
//        for (int i = 1; i < n; ++i) // 对每一组数字枚举
//        {
//            Pair c(a[i], g[i]);
//            auto it = s.lower_bound(c); // 找到首个不小于c的元素的位置
//            bool Keep = true;
//            if (it != s.begin())    // 确保迭代器自减后不会越界
//            {
//                auto Last = *(--it);
//                auto Len = f[i] + Last.g;   // 以a[j]结尾a[i]开头的递增子序列的长度
//                Ans = std::max(Ans, Len);   // 更新答案
//
//                if (c.g <= Last.g)  // 它的潜力不够了，就不应该被保留
//                {
//                    Keep = false;
//                }
//            }
//
//            if (Keep)
//            {
//                s.erase(c);
//                s.insert(c);    // 更新一下c的位置
//
//                it = ++s.find(c);
//                while (it != s.end() && it->a > c.a && it->g <= c.g)
//                {
//                    // 删除那些数字比c大的，但能以之结尾的递增序列却比c短的
//                    s.erase(it++);
//                }
//            }
//        }
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 100001> a{ 0 };
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> a[i];
//    }
//
//    int Sum1 = 0, Sum2 = 0, p = 0, q = n - 1;
//    while (p <= q)
//    {
//        if (Sum1 <= Sum2)
//        {
//            Sum1 += a[p++];
//        }
//        else
//        {
//            Sum2 += a[q--];
//        }
//    }
//
//    std::cout << p << ' ' << n - q - 1 << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//std::array<int, 100001> a;
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> a[i];
//    }
//
//    int p = 0, q = 0;
//    for (int i = 0; i < n - i; ++i)
//    {
//        if (a[i] > a[n - i])
//        {
//            ++p;
//        }
//        else
//        {
//            ++q;
//        }
//    }
//
//    std::cout << p << ' ' << q << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_set>
//#include <algorithm>
//#include <array>
//
//constexpr int MaxN = 1000000 + 5;
//std::array<int, MaxN> A{ 0 };
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int T, n;
//    T = Read();
//    while (T--)
//    {
//        std::cin >> n;
//        for (int i = 0; i < n; ++i)
//        {
//            A[i] = Read();
//        }
//
//        std::unordered_set<int> s;
//        int L = 0, R = 0, Ans = 0;
//        while (R < n)
//        {
//            while (R < n && !s.count(A[R]))
//            {
//                s.insert(A[R]);
//                ++R;
//            }
//
//            Ans = std::max(Ans, R - L);
//            s.erase(A[L]);
//            ++L;
//        }
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//#include <cmath>
//
//constexpr int MaxN = 1000 + 5;
//
//// 存放点的信息的结构体(x, y)和相对角度Rad
//struct Point
//{
//    int x, y;
//    double Rad;
//};
//
//std::array<Point, MaxN> op, p;
//std::array<int, MaxN> Color{ 0 };
//int n;
//
//// 利用向量叉积来计算向量OA是否在向量OB的左边，从而确定点A是否在点B的左边
//// 若OA * OB >= 0，则点A在点B左侧或者OA和OB共线
//// 若OA * OB < 0，则点A在点B的右侧
//// 这是利用了叉积表达式中有一个sinx，从而可以确定左右
//// 详见：https://www.cnblogs.com/rhythmic/p/5727057.html
//bool IsLeft(const Point &A, const Point &B)
//{
//    return A.x * B.y - A.y * B.x >= 0;
//}
//
//int Solve()
//{
//    if (n <= 2)
//    {
//        return 2;
//    }
//
//    // 这是一道计算几何题：
//    // 以O-p[i]作为分割线，以O-p[j]作为扫描线
//    // 将要被扫描的点按极角排序
//    // 看看有多少个点在O-p[i]左边
//    // 然后旋转分割线，继续扫描
//    int Ans = 0;    // 符合条件的黑点和白点的和，最后作为答案返回
//    for (int i = 0; i < n; ++i) // 枚举基准点op[i]
//    {
//        int k = 0;  // 扫描线的编号
//        for (int j = 0; j < n; ++j) // 连接op[i]和op[j]，以此作为扫描线
//        {
//            if (i != j) //确保不要选到同一个点
//            {
//                p[k].x = op[j].x - op[i].x; // 相当于delta x
//                p[k].y = op[j].y - op[i].y; // 相当于delta y
//
//                                // 如果是黑点，那就把它变为白点，并且将坐标旋转180度
//                if (Color[j])   // 这是为了方便计数，因为在右边的点可以涂黑然后变成在左边的白点
//                {               // 最后我们只要选取在左边的白点即可
//                    p[k].x = -p[k].x;
//                    p[k].y = -p[k].y;
//                }
//                
//                // 这里要注意std::atan和std::atan2不一样，std::atan2会更精确，因为考虑了更多的象限
//                p[k].Rad = std::atan2(p[k].y, p[k].x);  // 算出倾斜角，初中的公式了
//
//                ++k;    // 扫描线编号加一
//            }
//        }
//
//        // 将点按极角排序，从小到大排
//        std::sort(p.begin(), p.begin() + k, [](const Point &A, const Point &B)
//        {
//            return A.Rad < B.Rad;
//        });
//
//        int L = 0, R = 0, cnt = 2;
//        while (L < k)   // 枚举每一个点
//        {
//            if (R == L) // 空区域，暂时先多算一个点，最后舍去
//            {
//                R = (R + 1) % k;
//                ++cnt;
//            }
//
//            // 如果点L在点R的左边，那就加一，然后扫描线旋转
//            // 注意这里的R的范围是[0, k)
//            while (R != L && IsLeft(p[L], p[R]))
//            {
//                R = (R + 1) % k;
//                ++cnt;
//            }
//
//            --cnt;  // 舍去多计入的一个点
//            ++L;    // 旋转分割线
//
//            Ans = std::max(Ans, cnt);   // 更新答案
//        }
//    }
//
//    return Ans;
//}
//
//int main()
//{
//    while (std::cin >> n && n)
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> op[i].x >> op[i].y >> Color[i];
//        }
//
//        std::cout << Solve() << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//#include <string>
//
//std::unordered_map<std::string, std::string> Par;
//std::unordered_map<std::string, int> Rank;
//
//template <typename T>
//T Find(const T &x)
//{
//    if (Par[x] == x)
//    {
//        return x;
//    }
//    else
//    {
//        return Par[x] = Find(Par[x]);
//    }
//}
//
//template <typename T>
//void Unite(T x, T y)
//{
//    x = Find(x);
//    y = Find(y);
//    if (x == y)
//    {
//        return;
//    }
//
//    if (Rank[x] < Rank[y])
//    {
//        Par[x] = y;
//    }
//    else
//    {
//        Par[y] = x;
//
//        if (Rank[x] == Rank[y])
//        {
//            ++Rank[x];
//        }
//    }
//}
//
//template <typename T>
//bool IsSame(const T &x, const T &y)
//{
//    return Find(x) == Find(y);
//}
//
//int main()
//{
//    int n, m, k;
//    std::cin >> n >> m >> k;
//    std::string Name;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Name;
//        Par[Name] = Name;
//        Rank[Name] = 0;
//    }
//
//    std::string x, y;
//    for (int i = 0; i < m; ++i)
//    {
//        std::cin >> x >> y;
//        Unite(x, y);
//    }
//
//    for (int i = 0; i < k; ++i)
//    {
//        std::cin >> x >> y;
//        std::cout << (IsSame(x, y) ? "Yes!" : "No!") << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//constexpr int MaxN = 5000 + 5;
//int n;
//
//// 找到一个数组c[]，使得a[i] <= c[i] <= b[i] (0 <= i < n)
//// 我懒得写出参数类型了所以弄了个template来偷懒
//template <typename T>
//bool Solve(const T &a, const T &b, T &c, int n) // 因为要修改c[]，所以这里是引用类型
//{
//    std::fill(c.begin(), c.begin() + n, -1);    // 将c[]初始化为全-1
//    for (int Col = 1; Col <= n; ++Col)  // 遍历棋盘的第[1, n]列
//    {
//        // Rook是车的编号，MinB是能选的区间中最右边的点的最小值
//        int Rook = -1, MinB = n + 1;
//        for (int i = 0; i < n; ++i)
//        {
//            // 遍历每辆车的每个小区间：
//            // 如果c[i]还没被安排点，因为任何两辆车不能在同一行或者同一列
//            // 并且b[i]能在最右边的点的最小值的左边
//            // 并且Col在左边的点的右边
//            // 那就可以安排这第i辆车
//            if (c[i] < 0 && b[i] < MinB && Col >= a[i])
//            {
//                Rook = i;       // 能安排第i辆车了
//                MinB = b[i];    // 更新区间的最右边的点的最小值
//            }
//        }
//
//        // 如果这一轮下来，Rook还是-1，即没被安排到车
//        // 或者最左边的点跑得比最右边的点还要右
//        // 那就说明并没有解
//        if (Rook < 0 || Col > MinB)
//        {
//            return false;
//        }
//
//        // 给编号为Rook的车安排位置，安排在第Col列（行）
//        c[Rook] = Col;
//    }
//
//    // 成功地安排好了位置
//    return true;
//}
//
//int main()
//{
//    std::array<int, MaxN> x1{ 0 }, y1{ 0 }, x2{ 0 }, y2{ 0 }, x{ 0 }, y{ 0 };
//
//    while (std::cin >> n && n)
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
//        }
//
//        // 这是一个贪心题：
//        // 注意和n皇后不同，因为没有对角线的限制
//        // 所以可以将一个二维的问题分解成了两个一维的问题
//        // 然后贪心地选取对后面的车影响最小的坐标
//        if (Solve(x1, x2, x, n) && Solve(y1, y2, y, n))
//        {
//            for (int i = 0; i < n; ++i)
//            {
//                std::cout << x[i] << ' ' << y[i] << std::endl;
//            }
//        }
//        else
//        {
//            std::puts("IMPOSSIBLE");
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//using ll = long long;
//
//constexpr int MaxN = 4000 + 5;
//int n, c;
//std::array<int, MaxN> A{ 0 }, B{ 0 }, C{ 0 }, D{ 0 };
//std::array<int, MaxN * MaxN> Sums{ 0 }; // 存放A[]和B[]两两相加的和
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> n;
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> A[i] >> B[i] >> C[i] >> D[i];
//        }
//
//        // 这一题的思路十分直白：
//        // 就是把每一组(A[i] + B[j])的组合都算出来，
//        // 然后存在Sums[]中，
//        // 接着对Sums[]排序，
//        // 然后寻找每一组(C[i] + D[j])在Sums[]中出现了多少次，把这些次数都加起来，
//        // 相加后的结果即是答案
//
//        c = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                Sums[c++] = A[i] + B[j];    // A[]和B[]两两相加
//            }
//        }
//        std::sort(Sums.begin(), Sums.begin() + c); // 排序，为了后面二分方便
//
//        ll cnt = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                // 其实就是在找Sums[]中有多少个连续的(-C[i] - D[j])，然后加起来
//                cnt += std::upper_bound(Sums.cbegin(), Sums.cbegin() + c, -C[i] - D[j])
//                     - std::lower_bound(Sums.cbegin(), Sums.cbegin() + c, -C[i] - D[j]);
//            }
//        }
//
//        std::cout << cnt << std::endl;
//
//        if (T)
//        {
//            std::putchar('\n');
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//
//// 因为输入的国家个数小于等于50，所以用大小写字母可以表示完全所有的国家
//char Country(int i)
//{
//    if (i < 26) // 当i小于26时，输出大写字母
//    {
//        return 'A' + i;
//    }
//    else   // 当i大于等于26时，输出小写字母
//    {
//        return 'a' + i - 26;
//    }
//}
//
//int main()
//{
//    int n;
//    while (std::cin >> n)
//    {
//        std::printf("2 %d %d\n", n, n); // 表示有两层楼，每层楼都是n * n
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                std::putchar(Country(i));   // 第一层第i行全是国家i
//            }
//            std::putchar('\n');
//        }
//
//        std::putchar('\n');
//
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                std::putchar(Country(j));   // 第二层第j列全是国家j
//            }
//            std::putchar('\n');
//        }
//    }
//
//    return 0;
//}
////
////这里给出一组输出（输入的n为3）：
////AAA
////BBB
////CCC
////
////ABC
////ABC
////ABC
////
////可以发现，对于第二层的每一列，它都能与第一层的同一列的所有国家相邻，
////这样就完成了对这个做法的正确性的简单直观证明。
//#include <iostream>
//#include <sstream>
//#include <utility>
//#include <array>
//#include <algorithm>
//
//// 该数组的容量
//constexpr int MaxN = 30 + 5;
//
//int n;  // 整个序列的长度
//std::array<int, MaxN> a{ 0 };   // 序列的数组
//
//// 翻转a[0...p]
//void Flip(int p)
//{
//    for (int i = 0; i < p - i; ++i)
//    {
//        std::swap(a[i], a[p - i]);
//    }
//
//    std::cout << n - p << ' ';  // 按题意输出翻转的位置
//}
//
//int main()
//{
//    std::string s;
//    while (std::getline(std::cin, s))
//    {
//        std::cout << s << std::endl;    // 因为不知道有多少个数，所以只能整行全部读入
//                                        // 要注意输入时的数据是从上到下给出的，类似一个栈，这里很坑
//        std::stringstream ss(s);
//        n = 0;
//        while (ss >> a[n])
//        {
//            ++n;
//        }
//
//        // 由于是按照从大到小的顺序处理，当处理第i大的煎饼时，
//        // 是不会影响第1, 2, 3, ..., i - 1大的煎饼的，
//        // 因为它们已经正确地被翻到了煎饼堆底部的i - 1个位置上了。
//        for (int i = n - 1; i > 0; --i)
//        {
//            // 元素a[0..i]的最大元素的下标，这里第二个参数要加一是因为C++使用的是左闭合区间
//            auto p = std::max_element(a.cbegin(), a.cbegin() + i + 1) - a.cbegin();
//            if (p == i)
//            {
//                continue;   //表示该元素已经是最大的了
//            }
//
//            if (p > 0)  // 不需要执行Flip(0)， 因为Flip(0)相当于单独翻转a[0]，没有意义
//            {
//                Flip(p);    // 先把最大的元素翻到a[0]处
//            }
//            Flip(i);    // 处理完最大的，这下再翻转的时候，a[]的后面就已经有序了
//                        // 这两步有点难理解，建议跟着调试一步一步看
//        }
//
//        std::cout << 0 << std::endl;    // 按题意，最后还要输出一个0
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//using ll = long long;
//
//int main()
//{
//    int n;
//    while (std::cin >> n && n)
//    {
//        ll Ans = 0, a, Last = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> a;
//            Ans += std::abs(Last);
//            Last += a;
//        }
//
//        std::cout << Ans << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//#include <algorithm>
//
//std::array<std::array<int, 101>, 101> Map{ 0 }, Max{ 0 };
//std::array<int, 8> dx{ 0, -1, 0, 1 }, dy{ -1, 0, 1, 0 };
//
//int R, C;
//
//int DFS(int i, int j)
//{
//    if (Max[i][j] != 0)
//    {
//        return Max[i][j];
//    }
//
//    int Sum = 1;
//    for (int t = 0; t < 4; ++t)
//    {
//        auto x = i + dx[t];
//        auto y = j + dy[t];
//
//        if (x >= 0 && x < R && y >= 0 && y < C && Map[x][y] > Map[i][j])
//        {
//            Sum = std::max(Sum, DFS(x, y) + 1);
//        }
//    }
//
//    return Max[i][j] = Sum;
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    while (n--)
//    {
//        for (auto &rr : Map)
//        {
//            for (auto &r : rr)
//            {
//                r = 0;
//            }
//        }
//        for (auto &rr : Max)
//        {
//            for (auto &r : rr)
//            {
//                r = 0;
//            }
//        }
//
//        std::string Name;
//        std::cin >> Name >> R >> C;
//        for (int i = 0; i < R; ++i)
//        {
//            for (int j = 0; j < C; ++j)
//            {
//                std::cin >> Map[i][j];
//            }
//        }
//
//        int Max = 1;
//        for (int i = 0; i < R; ++i)
//        {
//            for (int j = 0; j < C; ++j)
//            {
//                Max = std::max(DFS(i, j), Max);
//            }
//        }
//
//        std::cout << Name << ": " << Max << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//
//constexpr int MaxN = 200 + 5;
//int Dist[MaxN][MaxN], Cap[3], Ans[MaxN];
//bool Mark[MaxN][MaxN];
//
//struct Node
//{
//    int v[3], Dist;
//
//    bool operator<(const Node &rhs) const
//    {
//        return Dist > rhs.Dist;
//    }
//};
//
//void UpdateAns(const Node &u)
//{
//    for (int i = 0; i < 3; ++i)
//    {
//        int d = u.v[i];
//        if (Ans[d] < 0 || u.Dist < Ans[d])
//        {
//            Ans[d] = u.Dist;
//        }
//    }
//}
//
//void Solve(int a, int b, int c, int d)
//{
//    Cap[0] = a;
//    Cap[1] = b;
//    Cap[2] = c;
//    std::memset(Ans, -1, sizeof(Ans));
//    std::memset(Mark, false, sizeof(Mark));
//    std::memset(Dist, -1, sizeof(Dist));
//
//    std::priority_queue<Node> q;
//    Node Start;
//    Start.Dist = 0;
//    Start.v[0] = 0;
//    Start.v[1] = 0;
//    Start.v[2] = c;
//    q.push(Start);
//
//    Dist[0][0] = 0;
//    while (!q.empty())
//    {
//        auto u = q.top();
//        q.pop();
//
//        if (Mark[u.v[0]][u.v[1]])
//        {
//            continue;
//        }
//        Mark[u.v[0]][u.v[1]] = true;
//        UpdateAns(u);
//
//        if (Ans[d] >= 0)
//        {
//            break;
//        }
//
//        for (int i = 0; i < 3; ++i)
//        {
//            for (int j = 0; j < 3; ++j)
//            {
//                if (i != j)
//                {
//                    if (u.v[i] == 0 || u.v[j] == Cap[j])
//                    {
//                        continue;
//                    }
//
//                    int Amount = std::min(Cap[j], u.v[i] + u.v[j]) - u.v[j];
//                    Node u2;
//                    std::memcpy(&u2, &u, sizeof(u));
//                    u2.Dist = u.Dist + Amount;
//                    u2.v[i] -= Amount;
//                    u2.v[j] += Amount;
//                    auto &D = Dist[u2.v[0]][u2.v[1]];
//                    if (D < 0 || u2.Dist < D)
//                    {
//                        D = u2.Dist;
//                        q.push(u2);
//                    }
//                }
//            }
//        }
//    }
//
//    while (d >= 0)
//    {
//        if (Ans[d] >= 0)
//        {
//            std::cout << Ans[d] << ' ' << d << std::endl;
//            return;
//        }
//
//        --d;
//    }
//}
//
//int main()
//{
//    int T, a, b, c, d;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> a >> b >> c >> d;
//        Solve(a, b, c, d);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <unordered_set>
//
//using State = int[9];
//
//constexpr int MaxState = 1000000;
//State st[MaxState];
//int Dist[MaxState];
//
//constexpr int dx[] = { -1, 1, 0, 0 };
//constexpr int dy[] = { 0, 0, -1, 1 };
//constexpr int Goal[] = { 1, 2, 3, 8, 0, 4, 7, 6, 5 };
//
//std::unordered_set<int> Vis;
//
//bool TryToInsert(int s)
//{
//    int v = 0;
//    for (int i = 0; i < 9; ++i)
//    {
//        v = v * 10 + st[s][i];
//    }
//
//    if (Vis.count(v))
//    {
//        return false;
//    }
//
//    Vis.insert(v);
//    return true;
//}
//
//int bfs()
//{
//    int Front = 1, Rear = 2;
//    while (Front < Rear)
//    {
//        auto &s = st[Front];
//        if (std::memcmp(Goal, s, sizeof(s)) == 0)
//        {
//            return Front;
//        }
//
//        int x, y, z;
//        for (z = 0; z < 9; ++z)
//        {
//            if (s[z] == 0)
//            {
//                x = z / 3;
//                y = z % 3;
//                break;
//            }
//        }
//        
//        for (int d = 0; d < 4; ++d)
//        {
//            auto NewX = x + dx[d];
//            auto NewY = y + dy[d];
//            auto NewZ = NewX * 3 + NewY;
//            if (NewX >= 0 && NewX < 3 && NewY >= 0 && NewY < 3)
//            {
//                auto &t = st[Rear];
//                std::memcpy(&t, &s, sizeof(s));
//                t[NewZ] = s[z];
//                t[z] = s[NewZ];
//                Dist[Rear] = Dist[Front] + 1;
//
//                if (TryToInsert(Rear))
//                {
//                    ++Rear;
//                }
//            }
//        }
//
//        ++Front;
//    }
//
//    return 0;
//}
//
//int main()
//{
//    for (int i = 0; i < 9; ++i)
//    {
//        st[1][i] = std::getchar() - '0';
//    }
//
//    int Ans = bfs();
//    if (Ans > 0)
//    {
//        std::cout << Dist[Ans] << std::endl;
//    }
//    else
//    {
//        std::cout << -1 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int n, L, cnt;
//std::array<int, 100> S{ 0 };
//
//bool dfs(int cur)
//{
//    if (cnt++ == n)
//    {
//        for (int i = 0; i < cur; ++i)
//        {
//            if (i % 64 == 0 && i > 0)
//            {
//                std::putchar('\n');
//            }
//            else if (i % 4 == 0 && i > 0)
//            {
//                std::putchar(' ');
//            }
//
//            std::putchar('A' + S[i]);
//        }
//
//        std::printf("\n%d\n", cur);
//        return false;
//    }
//
//    for (int i = 0; i < L; ++i)
//    {
//        S[cur] = i;
//        bool ok = true;
//        for (int j = 1; j * 2 <= cur + 1; ++j)
//        {
//            bool equal = true;
//            for (int k = 0; k < j; ++k)
//            {
//                if (S[cur - k] != S[cur - k - j])
//                {
//                    equal = false;
//                    break;
//                }
//            }
//
//            if (equal)
//            {
//                ok = false;
//                break;
//            }
//        }
//
//        if (ok)
//        {
//            if (!dfs(cur + 1))
//            {
//                return false;
//            }
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    while (std::cin >> n >> L && n > 0)
//    {
//        cnt = 0;
//        dfs(0);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int n;
//std::array<int, 50> A{ 0 };
//std::array<bool, 50> Vis{ false }, isp{ false };
//
//bool IsPrime(int x)
//{
//    for (int i = 2; i * i <= x; ++i)
//    {
//        if (x % i == 0)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//void DFS(int Cur)
//{
//    if (Cur == n && isp[A[0] + A[n - 1]])
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            if (i != 0)
//            {
//                std::putchar(' ');
//            }
//            std::cout << A[i];
//        }
//
//        std::putchar('\n');
//    }
//    else
//    {
//        for (int i = 2; i <= n; ++i)
//        {
//            if (!Vis[i] && isp[i + A[Cur - 1]])
//            {
//                A[Cur] = i;
//                Vis[i] = true;
//                DFS(Cur + 1);
//                Vis[i] = false;
//            }
//        }
//    }
//}
//
//int main()
//{
//    int NO = 0;
//    while (std::cin >> n && n > 0)
//    {
//        if (NO > 0)
//        {
//            std::putchar('\n');
//        }
//        std::cout << "Case " << ++NO << ":" << std::endl;
//
//        for (int i = 2; i <= n * 2; ++i)
//        {
//            isp[i] = IsPrime(i);
//        }
//        std::fill(Vis.begin(), Vis.end(), false);
//
//        A[0] = 1;
//        DFS(1);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <vector>
//#include <array>
//#include <unordered_map>
//#include <algorithm>
//
//constexpr int MaxN = 10000;
//
//int cnt = 0;
//std::unordered_map<std::string, int> Name2ID;
//std::array<std::string, MaxN> Name;
//std::array<std::vector<int>, MaxN> Depend, Depend2;
//std::array<int, MaxN> Status{ 0 };
//std::vector<int> Installed;
//
//int ID(const std::string &Item)
//{
//    if (!Name2ID.count(Item))
//    {
//        Name[++cnt] = Item;
//        Name2ID[Item] = cnt;
//    }
//
//    return Name2ID[Item];
//}
//
//bool Needed(int Item)
//{
//    for (const auto &r : Depend2[Item])
//    {
//        if (Status[r])
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//void Install(int Item, bool TopLevel)
//{
//    if (!Status[Item])
//    {
//        for (const auto &r : Depend[Item])
//        {
//            Install(r, false);
//        }
//
//        std::cout << "   Installing " << Name[Item] << std::endl;
//        Status[Item] = TopLevel ? 1 : 2;
//        Installed.push_back(Item);
//    }
//}
//
//void Remove(int Item, bool TopLevel)
//{
//    if ((TopLevel || Status[Item] == 2) && !Needed(Item))
//    {
//        Status[Item] = 0;
//        Installed.erase(std::remove(Installed.begin(), Installed.end(), Item), Installed.end());
//        std::cout << "   Removing " << Name[Item] << std::endl;
//
//        for (const auto &r : Depend[Item])
//        {
//            Remove(r, false);
//        }
//    }
//}
//
//void List()
//{
//    for (const auto &r : Installed)
//    {
//        std::cout << "   " << Name[r] << std::endl;
//    }
//}
//
//int main()
//{
//    std::string Line, cmd;
//    while (std::getline(std::cin, Line))
//    {
//        std::cout << Line << std::endl;
//
//        std::stringstream ss(Line);
//        ss >> cmd;
//        if (cmd[0] == 'E')
//        {
//            break;
//        }
//
//        std::string Item1, Item2;
//        if (cmd[0] == 'L')
//        {
//            List();
//        }
//        else
//        {
//            ss >> Item1;
//            auto i1 = ID(Item1);
//            if (cmd[0] == 'D')
//            {
//                while (ss >> Item2)
//                {
//                    auto i2 = ID(Item2);
//                    Depend[i1].push_back(i2);
//                    Depend2[i2].push_back(i1);
//                }
//            }
//            else if (cmd[0] == 'I')
//            {
//                if (Status[i1])
//                {
//                    std::cout << "   " << Item1 << " is already installed." << std::endl;
//                }
//                else
//                {
//                    Install(i1, true);
//                }
//            }
//            else
//            {
//                if (!Status[i1])
//                {
//                    std::cout << "   " << Item1 << " is not installed." << std::endl;
//                }
//                else if (Needed(i1))
//                {
//                    std::cout << "   " << Item1 << " is still needed." << std::endl;
//                }
//                else
//                {
//                    Remove(i1, true);
//                }
//            }
//        }
//    }
//
//    return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cctype>
//#include <cstring>
//
//constexpr int maxn = 200 + 10;
//int n;
//char buf[maxn][maxn];
//
//void dfs(int r, int c)
//{
//    std::printf("%c(", buf[r][c]);
//    if (r + 1 < n && buf[r + 1][c] == '|')
//    {
//        int i = c;
//        while (i - 1 >= 0 && buf[r + 2][i - 1] == '-')
//        {
//            --i;
//        }
//
//        while (buf[r + 2][i] == '-' && buf[r + 3][i] != '\0')
//        {
//            if (!std::isspace(buf[r + 3][i]))
//            {
//                dfs(r + 3, i);
//            }
//
//            ++i;
//        }
//    }
//
//    std::putchar(')');
//}
//
//void solve()
//{
//    n = 0;
//    while (1)
//    {
//        std::fgets(buf[n], maxn, stdin);
//        if (buf[n][0] == '#')
//        {
//            break;
//        }
//        else
//        {
//            ++n;
//        }
//    }
//
//    std::putchar('(');
//
//    if (n)
//    {
//        for (std::size_t i = 0; i < std::strlen(buf[0]); ++i)
//        {
//            if (buf[0][i] != ' ')
//            {
//                dfs(0, i);
//                break;
//            }
//        }
//    }
//
//    std::puts(")");
//}
//
//int main()
//{
//    int T;
//    std::fgets(buf[0], maxn, stdin);
//    std::sscanf(buf[0], "%d", &T);
//    while (T--)
//    {
//        solve();
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//
//constexpr int MaxN = 1000;
//int n, m, G[MaxN][MaxN], c[MaxN], topo[MaxN], t;
//
//bool DFS(int u)
//{
//    c[u] = -1;
//    for (int v = 0; v < n; ++v)
//    {
//        if (G[u][v])
//        {
//            if (c[v] < 0)
//            {
//                return false;
//            }
//            else if (!c[v])
//            {
//                DFS(v);
//            }
//        }
//    }
//
//    c[u] = 1;
//    topo[--t] = u;
//
//    return true;
//}
//
//bool TopoSort()
//{
//    t = n;
//    std::memset(c, 0, sizeof(c));
//    for (int u = 0; u < n; ++u)
//    {
//        if (!c[u])
//        {
//            if (!DFS(u))
//            {
//                return false;
//            }
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    while (std::cin >> n >> m && n)
//    {
//        std::memset(G, 0, sizeof(G));
//        for (int i = 0; i < m; ++i)
//        {
//            int u, v;
//            std::cin >> u >> v;
//            --u;
//            --v;
//            G[u][v] = 1;
//        }
//
//        if (TopoSort())
//        {
//            for (int i = 0; i < n - 1; ++i)
//            {
//                std::cout << topo[i] + 1 << ' ';
//            }
//            std::cout << topo[n - 1] + 1 << std::endl;
//        }
//        else
//        {
//            std::cout << "No" << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <queue>
//
//struct Node
//{
//    int r, c, dir;
//    Node() = default;
//    Node(int r, int c, int dir) :
//        r(r), c(c), dir(dir)
//    {
//    }
//};
//
//constexpr int MaxN = 10;
//constexpr char *dirs = const_cast<char*>("NESW");
//constexpr char *turns = const_cast<char*>("FLR");
//
//int HasEdge[MaxN][MaxN][4][3];
//int d[MaxN][MaxN][4];
//Node p[MaxN][MaxN][4];
//int r0, c0, dir, r1, c1, r2, c2;
//
//int DirID(char c)
//{
//    return std::strchr(dirs, c) - dirs;
//}
//
//int TurnID(char c)
//{
//    return std::strchr(turns, c) - turns;
//}
//
//constexpr int dr[] = { -1, 0, 1, 0 };
//constexpr int dc[] = { 0, 1, 0, -1 };
//
//Node Walk(const Node &u, int Turn)
//{
//    int dir = u.dir;
//    if (Turn == 1)
//    {
//        dir = (dir + 3) % 4;
//    }
//    if (Turn == 2)
//    {
//        dir = (dir + 1) % 4;
//    }
//
//    return Node(u.r + dr[dir], u.c + dc[dir], dir);
//}
//
//bool Inside(int r, int c)
//{
//    return r >= 1 && r <= 9 && c >= 1 && c <= 9;
//}
//
//bool ReadCase()
//{
//    char s[99], s2[99];
//    if (!(std::cin >> s >> r0 >> c0 >> s2 >> r2 >> c2))
//    {
//        return false;
//    }
//    std::puts(s);
//
//    dir = DirID(s2[0]);
//    r1 = r0 + dr[dir];
//    c1 = c0 + dc[dir];
//
//    std::memset(HasEdge, 0, sizeof(HasEdge));
//    while (1)
//    {
//        int r, c;
//        std::cin >> r;
//        if (r == 0)
//        {
//            break;
//        }
//        std::cin >> c;
//        while (std::cin >> s && s[0] != '*')
//        {
//            for (std::size_t i = 1; i < std::strlen(s); ++i)
//            {
//                HasEdge[r][c][DirID(s[0])][TurnID(s[i])] = 1;
//            }
//        }
//    }
//
//    return true;
//}
//
//void PrintAns(Node u)
//{
//    std::vector<Node> Nodes;
//    while (1)
//    {
//        Nodes.push_back(u);
//        if (d[u.r][u.c][u.dir] == 0)
//        {
//            break;
//        }
//
//        u = p[u.r][u.c][u.dir];
//    }
//    Nodes.push_back(Node(r0, c0, dir));
//
//    int cnt = 0;
//    for (int i = static_cast<int>(Nodes.size() - 1); i >= 0; --i)
//    {
//        if (cnt % 10 == 0)
//        {
//            std::putchar(' ');
//        }
//        std::printf(" (%d,%d)", Nodes[i].r, Nodes[i].c);
//        if (++cnt % 10 == 0)
//        {
//            std::putchar('\n');
//        }
//    }
//
//    if (Nodes.size() % 10 != 0)
//    {
//        std::putchar('\n');
//    }
//}
//
//void Solve()
//{
//    std::queue<Node> q;
//    std::memset(d, -1, sizeof(d));
//    Node u(r1, c1, dir);
//    d[u.r][u.c][u.dir] = 0;
//    q.push(u);
//
//    while (!q.empty())
//    {
//        auto u = q.front();
//        q.pop();
//        if (u.r == r2 && u.c == c2)
//        {
//            PrintAns(u);
//            return;
//        }
//
//        for (int i = 0; i < 3; ++i)
//        {
//            auto v = Walk(u, i);
//            if (HasEdge[u.r][u.c][u.dir][i] && Inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0)
//            {
//                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
//                p[v.r][v.c][v.dir] = u;
//                q.push(v);
//            }
//        }
//    }
//
//    std::cout << "  No Solution Possible" << std::endl;
//}
//
//int main()
//{
//    while (ReadCase())
//    {
//        Solve();
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//constexpr int MaxN = 100 + 5;
//std::array<std::array<char, MaxN>, MaxN> Pic;
//int m, n;
//
//void DFS(int r, int c)
//{
//    if (r < 0 || r >= m || c < 0 || c >= n)
//    {
//        return;
//    }
//
//    if (Pic[r][c] == '@')
//    {
//        Pic[r][c] = '*';
//        for (int dr = -1; dr <= 1; ++dr)
//        {
//            for (int dc = -1; dc <= 1; ++dc)
//            {
//                if (dr != 0 || dc != 0)
//                {
//                    DFS(r + dr, c + dc);
//                }
//            }
//        }
//    }
//}
//
//int main()
//{
//    while (std::cin >> m >> n && m && n)
//    {
//        for (int i = 0; i < m; ++i)
//        {
//            std::getchar();
//
//            for (int j = 0; j < n; ++j)
//            {
//                Pic[i][j] = std::getchar();
//            }
//        }
//
//        int cnt = 0;
//        for (int i = 0; i < m; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                if (Pic[i][j] == '@')
//                {
//                    ++cnt;
//                    DFS(i, j);
//                }
//            }
//        }
//
//        std::cout << cnt << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <array>
//
//constexpr int Len = 32;
//std::array<std::array<int, Len>, Len> Buf;
//std::string s;
//int cnt;
//
//void Draw(const std::string &s, int &p, int r, int c, int w)
//{
//    auto ch = s[p++];
//    if (ch == 'p')
//    {
//        Draw(s, p, r, c + w / 2, w / 2);
//        Draw(s, p, r, c, w / 2);
//        Draw(s, p, r + w / 2, c, w / 2);
//        Draw(s, p, r + w / 2, c + w / 2, w / 2);
//    }
//    else if (ch == 'f')
//    {
//        for (int i = r; i < r + w; ++i)
//        {
//            for (int j = c; j < c + w; ++j)
//            {
//                if (Buf[i][j] == 0)
//                {
//                    Buf[i][j] = 1;
//                    ++cnt;
//                }
//            }
//        }
//    }
//}
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        for (int i = 0; i < Len; ++i)
//        {
//            for (int j = 0; j < Len; ++j)
//            {
//                Buf[i][j] = 0;
//            }
//        }
//        cnt = 0;
//
//        for (int i = 0; i < 2; ++i)
//        {
//            std::cin >> s;
//            int p = 0;
//            Draw(s, p, 0, 0, Len);
//        }
//
//        std::cout << "There are " << cnt << " black pixels." << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<double, 15> a{ 0 };
//
//int n;
//double Left, Right, MidL, MidR;
//
//constexpr double EPS = 1e-6;
//
//double f(double x)
//{
//    double Sum = 0.0;
//    for (int i = 0; i <= n; ++i)
//    {
//        Sum = Sum * x + a[i];
//    }
//
//    return Sum;
//}
//
//int main()
//{
//    std::cin >> n >> Left >> Right;
//    for (int i = 0; i <= n; ++i)
//    {
//        std::cin >> a[i];
//    }
//
//    while (Right - Left > EPS)
//    {
//        MidL = (Left + Right) / 2;
//        MidR = (MidL + Right) / 2;
//        if (f(MidL) >= f(MidR))
//        {
//            Right = MidR;
//        }
//        else
//        {
//            Left = MidL;
//        }
//    }
//
//    std::printf("%.5lf\n", Left);
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//constexpr int MaxN = 100000;
//
//std::array<int, MaxN> Sum{ 0 };
//
//void Build(int p)
//{
//    int v;
//    std::cin >> v;
//    if (v == -1)
//    {
//        return;
//    }
//
//    Sum[p] += v;
//    Build(p - 1);
//    Build(p + 1);
//}
//
//bool Init()
//{
//    int v;
//    std::cin >> v;
//    if (v == -1)
//    {
//        return false;
//    }
//
//    std::fill(Sum.begin(), Sum.end(), 0);
//
//    int Pos = MaxN / 2;
//    Sum[Pos] = v;
//    Build(Pos - 1);
//    Build(Pos + 1);
//
//    return true;
//}
//
//int main()
//{
//    int NO = 0;
//    while (Init())
//    {
//        int p = 0;
//        while (Sum[p] == 0)
//        {
//            ++p;
//        }
//
//        std::cout << "Case " << ++NO << ":\n" << Sum[p++];
//        while (Sum[p] != 0)
//        {
//            std::cout << " " << Sum[p++];
//        }
//        std::puts("\n");
//    }
//
//    return 0;
//}
//#include <iostream>
//
//bool Solve(int &W)
//{
//    int W1, D1, W2, D2;
//    bool b1 = true, b2 = true;
//
//    std::cin >> W1 >> D1 >> W2 >> D2;
//    if (!W1)
//    {
//        b1 = Solve(W1);
//    }
//    if (!W2)
//    {
//        b2 = Solve(W2);
//    }
//    W = W1 + W2;
//
//    return b1 && b2 && (W1 * D1 == W2 * D2);
//}
//
//int main()
//{
//    int T, W;
//    std::cin >> T;
//    while (T--)
//    {
//        if (Solve(W))
//        {
//            std::cout << "YES" << std::endl;
//        }
//        else
//        {
//            std::cout << "NO" << std::endl;
//        }
//
//        if (T)
//        {
//            std::putchar('\n');
//        }
//    }
//}
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <algorithm>
//#include <array>
//
//constexpr int MaxV = 10000 + 10;
//std::array<int, MaxV> InOrder{ 0 }, PostOrder{ 0 }, lch{ 0 }, rch{ 0 };
//int n;
//
//int Best, BestSum;
//
//template <typename T>
//bool ReadList(T &a)
//{
//    std::string Line;
//    if (!std::getline(std::cin, Line))
//    {
//        return false;
//    }
//
//    std::stringstream ss(Line);
//    n = 0;
//    int x;
//    while (ss >> x)
//    {
//        a[n++] = x;
//    }
//
//    return n > 0;
//}
//
//int Build(int L1, int R1, int L2, int R2)
//{
//    if (L1 > R1)
//    {
//        return 0;
//    }
//
//    int Root = PostOrder[R2];
//    int p = L1;
//    while (InOrder[p] != Root)
//    {
//        ++p;
//    }
//
//    int cnt = p - L1;
//    lch[Root] = Build(L1, p - 1, L2, L2 + cnt - 1);
//    rch[Root] = Build(p + 1, R1, L2 + cnt, R2 - 1);
//
//    return Root;
//}
//
//void DFS(int u, int Sum)
//{
//    Sum += u;
//    if (!lch[u] && !rch[u])
//    {
//        if (Sum < BestSum || (Sum == BestSum && u < Best))
//        {
//            Best = u;
//            BestSum = Sum;
//        }
//    }
//
//    if (lch[u])
//    {
//        DFS(lch[u], Sum);
//    }
//    if (rch[u])
//    {
//        DFS(rch[u], Sum);
//    }
//}
//
//int main()
//{
//    while (ReadList(InOrder))
//    {
//        ReadList(PostOrder);
//
//        Build(0, n - 1, 0, n - 1);
//        BestSum = 1000000000;
//        DFS(PostOrder[n - 1], 0);
//
//        std::cout << Best << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int p;
//    while (std::cin >> p && p != -1)
//    {
//        int D, I;
//        while (p--)
//        {
//            std::cin >> D >> I;
//            int k = 1;
//            for (int i = 0; i < D - 1; ++i)
//            {
//                if (I % 2)
//                {
//                    k = k * 2;
//                    I = (I + 1) / 2;
//                }
//                else
//                {
//                    k = k * 2 + 1;
//                    I = I / 2;
//                }
//            }
//
//            std::cout << k << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cstring>
//
//int main()
//{
//    constexpr int MaxN = 100000 + 5;
//
//    char s[MaxN];
//    int Last, Cur;
//    std::array<int, MaxN> Next{ 0 };
//    while (std::cin >> s + 1)
//    {
//        auto n = std::strlen(s + 1);
//        Last = Cur = 0;
//        Next[0] = 0;
//        
//        for (std::size_t i = 1; i <= n; ++i)
//        {
//            auto ch = s[i];
//            if (ch == '[')
//            {
//                Cur = 0;
//            }
//            else if (ch == ']')
//            {
//                Cur = Last;
//            }
//            else
//            {
//                Next[i] = Next[Cur];
//                Next[Cur] = i;
//                if (Cur == Last)
//                {
//                    Last = i;
//                }
//                Cur = i;
//            }
//        }
//
//        for (int i = Next[0]; i != 0; i = Next[i])
//        {
//            std::putchar(s[i]);
//        }
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//struct r
//{
//    int x, y;
//};
//
//int main()
//{
//    int n, L;
//    std::cin >> n >> L;
//
//    std::array<r, 10000> p;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> p[i].x >> p[i].y;
//    }
//    std::sort(p.begin(), p.begin() + n, [](const r &a, const r &b)
//    {
//        return a.x < b.x;
//    });
//
//    int Now = p[0].x;
//    int Sum = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        while (Now < p[i].y)
//        {
//            Now += L;
//            ++Sum;
//        }
//
//        Now = std::max(Now, p[i + 1].x);
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//char s[21000001];
//char s_new[42000002];
//int p[21000001];
//
//int Init()
//{
//    auto len = std::strlen(s);
//    s_new[0] = '$';
//    s_new[1] = '#';
//    int j = 2;
//
//    for (std::size_t i = 0; i < len; ++i)
//    {
//        s_new[j++] = s[i];
//        s_new[j++] = '#';
//    }
//    s_new[j] = '\0';
//
//    return j;
//}
//
//int Manacher()
//{
//    int len = Init();
//    int MaxLen = -1;
//    int id;
//    int mx = 0;
//
//    for (int i = 1; i < len; ++i)
//    {
//        if (i < mx)
//        {
//            p[i] = std::min(p[2 * id - i], mx - i);
//        }
//        else
//        {
//            p[i] = 1;
//        }
//
//        while (s_new[i - p[i]] == s_new[i + p[i]])
//        {
//            ++p[i];
//        }
//
//        if (mx < i + p[i])
//        {
//            id = i;
//            mx = i + p[i];
//        }
//
//        MaxLen = std::max(MaxLen, p[i] - 1);
//    }
//
//    return MaxLen;
//}
//
//int main()
//{
//    std::cin >> s;
//    std::cout << Manacher() << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//struct p
//{
//    int x, y, a, b;
//};
//
//int main()
//{
//    std::array<p, 10001> P;
//
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> P[i].x >> P[i].y >> P[i].a >> P[i].b;
//    }
//
//    int X, Y;
//    std::cin >> X >> Y;
//
//    int Ans = -1;
//    bool ok = false;
//    for (int i = n - 1; i >= 0; --i)
//    {
//        if (P[i].x <= X && P[i].y <= Y && (P[i].x + P[i].a) >= X && (P[i].y + P[i].b) >= Y)
//        {
//            Ans = i + 1;
//            break;
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <stack>
//#include <string>
//#include <cctype>
//
//struct Matrix
//{
//    int a, b;
//
//    Matrix() = default;
//    Matrix(int a, int b) :
//        a(a), b(b)
//    {
//    }
//};
//
//int main()
//{
//    std::array<Matrix, 26> m;
//
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        std::string Name;
//        std::cin >> Name;
//        auto k = Name[0] - 'A';
//        std::cin >> m[k].a >> m[k].b;
//    }
//
//    std::stack<Matrix> s;
//    std::string Expr;
//    while (std::cin >> Expr)
//    {
//        bool Error = false;
//        int Ans = 0;
//
//        for (std::size_t i = 0; i < Expr.size(); ++i)
//        {
//            if (std::isalpha(Expr[i]))
//            {
//                s.push(m[Expr[i] - 'A']);
//            }
//            else if (Expr[i] == ')')
//            {
//                auto m2 = s.top();
//                s.pop();
//                auto m1 = s.top();
//                s.pop();
//
//                if (m1.b != m2.a)
//                {
//                    Error = true;
//                    break;
//                }
//
//                Ans += m1.a * m1.b * m2.b;
//
//                s.push(Matrix(m1.a, m2.b));
//            }
//        }
//
//        if (Error)
//        {
//            std::puts("error");
//        }
//        else
//        {
//            std::cout << Ans << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <stack>
//
//constexpr int MaxN = 1000 + 10;
//
//int main()
//{
//    std::array<int, MaxN> Target{ 0 };
//    int n;
//    while (std::cin >> n && n != 0)
//    {
//        while (std::cin >> Target[1] && Target[1] != 0)
//        {
//            for (int i = 2; i <= n; ++i)
//            {
//                std::cin >> Target[i];
//            }
//
//            bool ok = true;
//            int A = 1, B = 1;
//            std::stack<int> s;
//            while (B <= n)
//            {
//                if (A == Target[B])
//                {
//                    ++A;
//                    ++B;
//                }
//                else if (!s.empty() && s.top() == Target[B])
//                {
//                    s.pop();
//                    ++B;
//                }
//                else if (A <= n)
//                {
//                    s.push(A++);
//                }
//                else
//                {
//                    ok = false;
//                    break;
//                }
//            }
//
//            std::cout << (ok ? "Yes" : "No") << std::endl;
//        }
//
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//using ll = double;
//
//struct Boat
//{
//    ll beg, end;
//
//    bool operator<(const Boat &r) const noexcept
//    {
//        return beg < r.beg || (beg == r.beg && end < r.end);
//    }
//};
//
//std::array<Boat, 20001> b;
//std::array<ll, 40001> x{ 0 };
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    ll p, q;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> p >> q;
//        b[i].beg = p;
//        b[i].end = q;
//        x[i * 2] = p;
//        x[i * 2 + 1] = q;
//    }
//
//    std::sort(b.begin(), b.begin() + n);
//    std::sort(x.begin(), x.begin() + 2 * n);
//    auto m = std::unique(x.begin(), x.begin() + 2 * n) - x.begin();
//
//    ll Sum = 0;
//    for (int i = 0; i < m - 1; ++i)
//    {
//        double t = (x[i] + x[i + 1]) / 2;
//
//        bool ok = false;
//        for (int j = 0; j < n; ++j)
//        {
//            if (t > b[j].beg && t < b[j].end)
//            {
//                ok = true;
//                break;
//            }
//        }
//        if (ok)
//        {
//            Sum += x[i + 1] - x[i];
//        }
//    }
//
//    std::cout << static_cast<long long>(Sum) << std::endl;
//    
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <array>
//
//std::array<int, 1000000 + 5> f{ 0 };
//
//void GetFail(const std::string &P)
//{
//    for (std::size_t i = 1; i < P.size(); ++i)
//    {
//        auto j = f[i];
//        while (j && P[i] != P[j])
//        {
//            j = f[j];
//        }
//        f[i + 1] = P[i] == P[j] ? j + 1 : 0;
//    }
//}
//
//void Find(const std::string &T, const std::string &P)
//{
//    GetFail(P);
//    std::size_t j = 0;
//    for (std::size_t i = 0; i < T.size(); ++i)
//    {
//        while (j && P[j] != T[i])
//        {
//            j = f[j];
//        }
//        if (P[j] == T[i])
//        {
//            ++j;
//        }
//        if (j == P.size())
//        {
//            std::cout << i - P.size() + 2 << std::endl;
//        }
//    }
//}
//
//int main()
//{
//    std::string T, P;
//    std::cin >> T >> P;
//
//    Find(T, P);
//    for (std::size_t i = 1; i <= P.size(); ++i)
//    {
//        std::cout << f[i] << ' ';
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//constexpr int MaxN = 100 + 5;
//
//struct Building
//{
//    int id;
//    double x, y, w, d, h;
//
//    bool operator<(const Building &rhs) const noexcept
//    {
//        return x < rhs.x || (x == rhs.x && y < rhs.y);
//    }
//};
//
//int n;
//
//std::array<Building, MaxN> b;
//std::array<double, MaxN * 2> x;
//
//bool Cover(int i, double mx)
//{
//    return b[i].x <= mx && b[i].x + b[i].w >= mx;
//}
//
//bool Visible(int i, double mx)
//{
//    if (!Cover(i, mx))
//    {
//        return false;
//    }
//    for (int k = 0; k < n; ++k)
//    {
//        if (b[k].y < b[i].y && b[k].h >= b[i].h && Cover(k, mx))
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    int NO = 0;
//    while (std::cin >> n && n != 0)
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> b[i].x >> b[i].y >> b[i].w >> b[i].d >> b[i].h;
//            x[i * 2] = b[i].x;
//            x[i * 2 + 1] = b[i].x + b[i].w;
//            b[i].id = i + 1;
//        }
//
//        std::sort(b.begin(), b.begin() + n);
//        std::sort(x.begin(), x.begin() + n * 2);
//        auto m = std::unique(x.begin(), x.begin() + n * 2) - x.begin();
//
//        if (NO++)
//        {
//            std::putchar('\n');
//        }
//        std::printf("For map #%d, the visible buildings are numbered as follows:\n%d", NO, b[0].id);
//
//        for (int i = 1; i < n; ++i)
//        {
//            bool Vis = false;
//            for (int j = 0; j < m - 1; ++j)
//            {
//                if (Visible(i, (x[j] + x[j + 1]) / 2))
//                {
//                    Vis = true;
//                    break;
//                }
//            }
//            if (Vis)
//            {
//                std::printf(" %d", b[i].id);
//            }
//        }
//
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <vector>
//
//int main()
//{
//    std::string Str;
//    std::vector<std::string> s;
//
//    int Max = 0;
//    while (std::getline(std::cin, Str))
//    {
//        s.push_back(Str);
//        if (static_cast<int>(Str.size()) > Max)
//        {
//            Max = Str.size();
//        }
//    }
//
//    for (int i = 0; i < Max + 2; ++i)
//    {
//        std::putchar('*');
//    }
//    std::putchar('\n');
//
//    bool Left = true;
//    for (const auto &r : s)
//    {
//        if (r == "\n")
//        {
//            std::putchar('*');
//            for (int i = 0; i < Max; ++i)
//            {
//                std::putchar(' ');
//            }
//            std::putchar('*');
//            std::putchar('\n');
//        }
//        else
//        {
//            if ((Max - r.size()) % 2 == 0)
//            {
//                std::putchar('*');
//                for (std::size_t i = 0; i < ((Max - r.size()) / 2); ++i)
//                {
//                    std::putchar(' ');
//                }
//                std::cout << r;
//                for (std::size_t i = 0; i < ((Max - r.size()) / 2); ++i)
//                {
//                    std::putchar(' ');
//                }
//                std::putchar('*');
//                std::putchar('\n');
//            }
//            else
//            {
//                if (Left)
//                {
//                    std::putchar('*');
//                    for (std::size_t i = 0; i < ((Max - r.size()) / 2); ++i)
//                    {
//                        std::putchar(' ');
//                    }
//                    std::cout << r;
//                    for (std::size_t i = 0; i <= ((Max - r.size()) / 2); ++i)
//                    {
//                        std::putchar(' ');
//                    }
//                    std::putchar('*');
//                    std::putchar('\n');
//                }
//                else
//                {
//                    std::putchar('*');
//                    for (std::size_t i = 0; i <= ((Max - r.size()) / 2); ++i)
//                    {
//                        std::putchar(' ');
//                    }
//                    std::cout << r;
//                    for (std::size_t i = 0; i < ((Max - r.size()) / 2); ++i)
//                    {
//                        std::putchar(' ');
//                    }
//                    std::putchar('*');
//                    std::putchar('\n');
//                }
//
//                Left = !Left;
//            }
//        }
//    }
//
//    for (int i = 0; i < Max + 2; ++i)
//    {
//        std::putchar('*');
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    int Num = 0, Sum = 0;
//
//    std::string msg;
//    while (std::getline(std::cin, msg))
//    {
//        if (msg[0] == '+')
//        {
//            ++Num;
//        }
//        else if (msg[0] == '-')
//        {
//            --Num;
//        }
//        else
//        {
//            auto Start = msg.find_first_of(':');
//            auto t = msg.size() - Start - 1;
//            Sum += t * Num;
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_set>
//#include <string>
//
//int main()
//{
//    int Sum = 0;
//
//    std::unordered_set<std::string> Set;
//    std::string Str;
//    while (std::cin >> Str)
//    {
//        if (Str[0] != '+' && Str[0] != '-')
//        {
//            std::string Message;
//            std::getline(std::cin, Message);
//
//            int Tol = 0;
//            auto Start = Message.find(':');
//            for (auto i = Start; i < Message.size(); ++i)
//            {
//                if (Message[i] != '\n')
//                {
//                    ++Tol;
//                }
//            }
//            Sum += Tol * Set.size();
//        }
//        else
//        {
//            if (Str[0] == '+')
//            {
//                Set.insert(std::string(Str, 1));
//            }
//            else
//            {
//                Set.erase(std::string(Str, 1));
//            }
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <vector>
//#include <set>
//#include <unordered_map>
//#include <map>
//
//void ParseAddress(const std::string &s, std::string &User, std::string &MTA)
//{
//    auto k = s.find('@');
//    User = s.substr(0, k);
//    MTA = s.substr(k + 1);
//}
//
//int main()
//{
//    int k;
//    std::string s, t, User1, MTA1, User2, MTA2;
//    std::set<std::string> Addr;
//
//    while (std::cin >> s && s != "*")
//    {
//        std::cin >> s >> k;
//        while (k--)
//        {
//            std::cin >> t;
//            Addr.insert(t + "@" + s);
//        }
//    }
//
//    while (std::cin >> s && s != "*")
//    {
//        ParseAddress(s, User1, MTA1);
//
//        std::vector<std::string> MTA;
//        std::map<std::string, std::vector<std::string>> Dest;
//        std::set<std::string> Vis;
//        while (std::cin >> t && t != "*")
//        {
//            ParseAddress(t, User2, MTA2);
//            if (Vis.count(t) != 0)
//            {
//                continue;
//            }
//            Vis.insert(t);
//
//            if (Dest.count(MTA2) == 0)
//            {
//                MTA.push_back(MTA2);
//                Dest[MTA2] = std::vector<std::string>();
//            }
//            Dest[MTA2].push_back(t);
//        }
//
//        std::getline(std::cin, t);
//
//        std::string Data;
//        while (std::getline(std::cin, t) && t[0] != '*')
//        {
//            Data += "     " + t + "\n";
//        }
//
//        for (std::size_t i = 0; i < MTA.size(); ++i)
//        {
//            auto MTA2 = MTA[i];
//            auto Users = Dest[MTA2];
//            std::cout << "Connection between " << MTA1 << " and " << MTA2 << std::endl;
//            std::cout << "     HELO " << MTA1 << std::endl;
//            std::cout << "     250" << std::endl;
//            std::cout << "     MAIL FROM:<" << s << ">" << std::endl;
//            std::cout << "     250" << std::endl;
//
//            bool ok = false;
//            for (std::size_t i = 0; i < Users.size(); ++i)
//            {
//                std::cout << "     RCPT TO:<" << Users[i] << ">" << std::endl;
//                if (Addr.count(Users[i]))
//                {
//                    ok = true;
//                    std::cout << "     250" << std::endl;
//                }
//                else
//                {
//                    std::cout << "     550" << std::endl;
//                }
//            }
//
//            if (ok)
//            {
//                std::cout << "     DATA\n"
//                          << "     354\n"
//                          << Data
//                          << "     .\n"
//                          << "     250"
//                          << std::endl;
//            }
//
//            std::printf("     QUIT\n");
//            std::printf("     221\n");
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include <stack>
//
//struct Envelope
//{
//    int w, h, NO;
//};
//
//std::array<Envelope, 5001> E;
//std::array<int, 5001> DP{ 0 }, Pre{ -1 };
//int ID = 1;
//
//void Print()
//{
//    std::stack<Envelope> s;
//    int k = ID;
//    while (k >= 0)
//    {
//        s.push(E[k]);
//        k = Pre[k];
//    }
//
//    while (!s.empty())
//    {
//        std::cout << s.top().NO + 1 << ' ';
//        s.pop();
//    }
//}
//
//int main()
//{
//    int n, w, h;
//    std::cin >> n >> w >> h;
//    int Tol = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        int W, H;
//        std::cin >> W >> H;
//        if (w < W && h < H)
//        {
//            E[Tol].w = W;
//            E[Tol].h = H;
//            E[Tol].NO = i;
//            ++Tol;
//        }
//    }
//    std::sort(E.begin(), E.begin() + Tol, [](const Envelope &a, const Envelope &b)
//    {
//        return a.w < b.w;
//    });
//
//    std::fill_n(Pre.begin(), Tol + 1, -1);
//
//    int Ans = 0;
//    for (int i = 0; i < Tol; ++i)
//    {
//        DP[i] = 1;
//        for (int j = i - 1; j >= 0; --j)
//        {
//            if (E[i].h > E[j].h && E[i].w > E[j].w && DP[j] + 1 > DP[i])
//            {
//                DP[i] = DP[j] + 1;
//                Pre[i] = j;
//            }
//        }
//
//        if (DP[i] > Ans)
//        {
//            Ans = DP[i];
//            ID = i;
//        }
//    }
//
//    if (Ans == 0)
//    {
//        std::putchar('0');
//    }
//    else
//    {
//        std::cout << Ans << std::endl;
//        Print();
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//#include <string>
//
//int main()
//{
//    std::string Str;
//    std::unordered_map<std::string, int> Map;
//    int n;
//    std::cin >> n;
//    while (n--)
//    {
//        std::cin >> Str;
//        if (Map[Str]++ == 0)
//        {
//            std::cout << "OK" << std::endl;
//        }
//        else
//        {
//            std::cout << Str << Map[Str] - 1 << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <array>
//
//void Print(const std::string &s, int Len, char Extra)
//{
//    std::cout << s;
//    for (int i = 0; i < static_cast<int>(Len - s.size()); ++i)
//    {
//        std::putchar(Extra);
//    }
//}
//
//int main()
//{
//    constexpr int MaxCol = 60;
//    constexpr int MaxN = 100 + 5;
//    std::array<std::string, MaxN> FileNames;
//
//    int n;
//    while (std::cin >> n)
//    {
//        int M = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> FileNames[i];
//            M = std::max(M, static_cast<int>(FileNames[i].size()));
//        }
//
//        int Cols = (MaxCol - M) / (M + 2) + 1;
//        int Rows = (n - 1) / Cols + 1;
//        Print("", 60, '-');
//        std::putchar('\n');
//
//        std::sort(FileNames.begin(), FileNames.begin() + n);
//        for (int r = 0; r < Rows; ++r)
//        {
//            for (int c = 0; c < Cols; ++c)
//            {
//                int idx = c * Rows + r;
//                if (idx < n)
//                {
//                    Print(FileNames[idx], c == Cols - 1 ? M : M + 2, ' ');
//                }
//            }
//
//            std::putchar('\n');
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <unordered_set>
//#include <functional>
//
//constexpr int t[] = { 2, 3, 5 };
//
//using ll = long long;
//
//int main()
//{
//    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
//    std::unordered_set<ll> s;
//    pq.push(1);
//    s.insert(1);
//
//    ll x;
//    for (int i = 0; i < 1500; ++i)
//    {
//        x = pq.top();
//        pq.pop();
//
//        for (int i = 0; i < 3; ++i)
//        {
//            auto x2 = x * t[i];
//            if (!s.count(x2))
//            {
//                s.insert(x2);
//                pq.push(x2);
//            }
//        }
//    }
//
//    std::cout << "The 1500'th ugly number is " << x << '.' << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <queue>
//#include <unordered_map>
//#include <array>
//#include <string>
//
//int main()
//{
//    int t, NO = 0;
//    while (std::cin >> t && t != 0)
//    {
//        std::cout << "Scenario #" << ++NO << std::endl;
//
//        std::unordered_map<int, int> Team;
//        for (int i = 0; i < t; ++i)
//        {
//            int n, x;
//            std::cin >> n;
//            while (n--)
//            {
//                std::cin >> x;
//                Team[x] = i;
//            }
//        }
//
//        std::queue<int> q;
//        std::array<std::queue<int>, 1010> q2;
//        while (1)
//        {
//            std::string Command;
//            std::cin >> Command;
//            if (Command[0] == 'S')
//            {
//                break;
//            }
//            else
//            {
//                if (Command[0] == 'D')
//                {
//                    auto t = q.front();
//                    std::cout << q2[t].front() << std::endl;
//                    q2[t].pop();
//
//                    if (q2[t].empty())
//                    {
//                        q.pop();
//                    }
//                }
//                else if (Command[0] == 'E')
//                {
//                    int x;
//                    std::cin >> x;
//
//                    auto t = Team[x];
//                    if (q2[t].empty())
//                    {
//                        q.push(t);
//                    }
//
//                    q2[t].push(x);
//                }
//            }
//        }
//
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <cctype>
//#include <algorithm>
//#include <vector>
//#include <map>
//
//std::string Repr(const std::string &s)
//{
//    auto Ans = s;
//    std::transform(Ans.begin(), Ans.end(), Ans.begin(), [](unsigned char c)
//    {
//        return std::tolower(c);
//    });
//    std::sort(Ans.begin(), Ans.end());
//
//    return Ans;
//}
//
//int main()
//{
//    std::vector<std::string> Words;
//    std::map<std::string, int> Count;
//
//    std::string s;
//    while (std::cin >> s && s[0] != '#')
//    {
//        Words.push_back(s);
//
//        auto r = Repr(s);
//        ++Count[r];
//    }
//
//    std::vector<std::string> Ans;
//    for (const auto &r : Words)
//    {
//        if (Count[Repr(r)] == 1)
//        {
//            Ans.push_back(r);
//        }
//    }
//    std::sort(Ans.begin(), Ans.end());
//
//    for (const auto &r : Ans)
//    {
//        std::cout << r << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//int main()
//{
//    ll a, b;
//    std::cin >> a >> b;
//    std::cout << a * b - a - b << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <vector>
//#include <array>
//
//constexpr int MaxN = 30;
//int n;
//std::array<std::vector<int>, MaxN> Pile;
//
//void FindBlock(int a, int &p, int &h)
//{
//    for (p = 0; p < n; ++p)
//    {
//        for (h = 0; h < static_cast<int>(Pile[p].size()); ++h)
//        {
//            if (Pile[p][h] == a)
//            {
//                return;
//            }
//        }
//    }
//}
//
//void ClearAbove(int p, int h)
//{
//    for (std::size_t i = h + 1; i < Pile[p].size(); ++i)
//    {
//        int b = Pile[p][i];
//        Pile[b].push_back(b);
//    }
//
//    Pile[p].resize(h + 1);
//}
//
//void PileOnto(int p, int h, int p2)
//{
//    for (std::size_t i = h; i < Pile[p].size(); ++i)
//    {
//        Pile[p2].push_back(Pile[p][i]);
//    }
//
//    Pile[p].resize(h);
//}
//
//void Print()
//{
//    for (int i = 0; i < n; ++i)
//    {
//        std::cout << i << ':';
//        for (std::size_t j = 0; j < Pile[i].size(); ++j)
//        {
//            std::cout << ' ' << Pile[i][j];
//        }
//        std::putchar('\n');
//    }
//}
//
//int main()
//{
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        Pile[i].push_back(i);
//    }
//
//    int a, b;
//    std::string s1, s2;
//    while (std::cin >> s1 >> a >> s2 >> b)
//    {
//        int pa, pb, ha, hb;
//        FindBlock(a, pa, ha);
//        FindBlock(b, pb, hb);
//
//        if (pa == pb)
//        {
//            continue;
//        }
//        else
//        {
//            if (s2 == "onto")
//            {
//                ClearAbove(pb, hb);
//            }
//            if (s1 == "move")
//            {
//                ClearAbove(pa, ha);
//            }
//
//            PileOnto(pa, ha, pb);
//        }
//    }
//    Print();
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//
//struct Command
//{
//    std::string c;
//    int r1, c1, r2, c2;
//    int a;
//    std::array<int, 20> x;
//};
//
//std::array<Command, 10000> cmd;
//
//int r, c, n;
//
//bool Simulate(int &r0, int &c0)
//{
//    for (int i = 0; i < n; ++i)
//    {
//        if (cmd[i].c[0] == 'E')
//        {
//            if (cmd[i].r1 == r0 && cmd[i].c1 == c0)
//            {
//                r0 = cmd[i].r2;
//                c0 = cmd[i].c2;
//            }
//            else if (cmd[i].r2 == r0 && cmd[i].c2 == c0)
//            {
//                r0 = cmd[i].r1;
//                c0 = cmd[i].c1;
//            }
//        }
//        else
//        {
//            int dr = 0, dc = 0;
//            for (int j = 0; j < cmd[i].a; ++j)
//            {
//                int x = cmd[i].x[j];
//                if (cmd[i].c[0] == 'I')
//                {
//                    if (cmd[i].c[1] == 'R' && x <= r0)
//                    {
//                        ++dr;
//                    }
//                    else if (cmd[i].c[1] == 'C' && x <= c0)
//                    {
//                        ++dc;
//                    }
//                }
//                else
//                {
//                    if (cmd[i].c[1] == 'R' && x == r0)
//                    {
//                        return false;
//                    }
//                    else if (cmd[i].c[1] == 'C' && x == c0)
//                    {
//                        return false;
//                    }
//                    else if (cmd[i].c[1] == 'R' && x < r0)
//                    {
//                        --dr;
//                    }
//                    else if (cmd[i].c[1] == 'C' && x < c0)
//                    {
//                        --dc;
//                    }
//                }
//            }
//
//            r0 += dr;
//            c0 += dc;
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    int NO = 0;
//
//    while (std::cin >> r >> c >> n && r != 0)
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> cmd[i].c;
//            if (cmd[i].c[0] == 'E')
//            {
//                std::cin >> cmd[i].r1 >> cmd[i].c1 >> cmd[i].r2 >> cmd[i].c2;
//            }
//            else
//            {
//                std::cin >> cmd[i].a;
//                for (int j = 0; j < cmd[i].a; ++j)
//                {
//                    std::cin >> cmd[i].x[j];
//                }
//            }
//        }
//
//        if (NO > 0)
//        {
//            std::putchar('\n');
//        }
//        std::cout << "Spreadsheet #" << ++NO << std::endl;
//
//        int r0, c0, q;
//        std::cin >> q;
//        while (q--)
//        {
//            std::cin >> r0 >> c0;
//            std::printf("Cell data in (%d,%d) ", r0, c0);
//            if (!Simulate(r0, c0))
//            {
//                std::puts("GONE");
//            }
//            else
//            {
//                std::printf("moved to (%d,%d)\n", r0, c0);
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//
//int Code[8][1 << 8];
//
//int ReadChar()
//{
//    while (1)
//    {
//        int ch = std::getchar();
//        if (ch != '\n' && ch != '\r')
//        {
//            return ch;
//        }
//    }
//}
//
//int ReadInt(int c)
//{
//    int v = 0;
//    while (c--)
//    {
//        v = v * 2 + ReadChar() - '0';
//    }
//
//    return v;
//}
//
//bool ReadCodes()
//{
//    std::memset(Code, 0, sizeof(Code));
//    Code[1][0] = ReadChar();
//
//    for (int Len = 2; Len <= 7; ++Len)
//    {
//        for (int i = 0; i < (1 << Len) - 1; ++i)
//        {
//            auto ch = std::getchar();
//            if (ch == EOF)
//            {
//                return false;
//            }
//            if (ch == '\n' || ch == '\r')
//            {
//                return true;
//            }
//
//            Code[Len][i] = ch;
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    while (ReadCodes())
//    {
//        while (1)
//        {
//            auto Len = ReadInt(3);
//            if (Len == 0)
//            {
//                break;
//            }
//
//            while (1)
//            {
//                auto v = ReadInt(Len);
//                if (v == (1 << Len) - 1)
//                {
//                    break;
//                }
//                std::putchar(Code[Len][v]);
//            }
//        }
//
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 21> a{ 0 };
//
//int n;
//
//int Go(int p, int d, int t)
//{
//    while (t--)
//    {
//        do
//        {
//            p = (p + d + n - 1) % n + 1;
//        } while (a[p] == 0);
//    }
//
//    return p;
//}
//
//int main()
//{
//    int k, m;
//    while (std::cin >> n >> k >> m && n != 0)
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            a[i] = i;
//        }
//
//        int Left = n;
//        int p1 = n, p2 = 1;
//        while (Left)
//        {
//            p1 = Go(p1, 1, k);
//            p2 = Go(p2, -1, m);
//            
//            std::printf("%3d", p1);
//            --Left;
//            if (p2 != p1)
//            {
//                std::printf("%3d", p2);
//                --Left;
//            }
//
//            a[p1] = a[p2] = 0;
//
//            if (Left)
//            {
//                std::putchar(',');
//            }
//        }
//
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int Left, Chance;
//bool Win, Lose;
//
//std::string Str1, Str2;
//
//void Guess(char ch)
//{
//    bool Bad = true;
//    for (std::size_t i = 0; i < Str1.size(); ++i)
//    {
//        if (ch == Str1[i])
//        {
//            --Left;
//            Str1[i] = ' ';
//            Bad = false;
//        }
//    }
//
//    if (Bad)
//    {
//        --Chance;
//    }
//    if (!Chance)
//    {
//        Lose = true;
//    }
//    if (!Left)
//    {
//        Win = true;
//    }
//}
//
//int main()
//{
//    int Round;
//    std::cin >> Round;
//    while (Round != -1)
//    {
//        std::cout << "Round " << Round << std::endl;
//        Win = Lose = false;
//        std::cin >> Str1 >> Str2;
//        Left = static_cast<int>(Str1.size());
//        Chance = 7;
//
//        for (std::size_t i = 0; i < Str2.size(); ++i)
//        {
//            Guess(Str2[i]);
//            if (Win || Lose)
//            {
//                break;
//            }
//        }
//
//        if (Win)
//        {
//            std::cout << "You win." << std::endl;
//        }
//        else if (Lose)
//        {
//            std::cout << "You lose." << std::endl;
//        }
//        else
//        {
//            std::cout << "You chickened out." << std::endl;
//        }
//
//        std::cin >> Round;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    std::string Str1, Str2;
//    while (std::cin >> Str1)
//    {
//        std::cin >> Str2;
//
//        std::array<int, 26> Arr1{ 0 }, Arr2{ 0 };
//        for (const auto &r : Str1)
//        {
//            ++Arr1[r - 'A'];
//        }
//        for (const auto &r : Str2)
//        {
//            ++Arr2[r - 'A'];
//        }
//
//        std::sort(Arr1.begin(), Arr1.end());
//        std::sort(Arr2.begin(), Arr2.end());
//
//        std::cout << (Arr1 == Arr2 ? "YES" : "NO") << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<int, 31> Min{ 0 }, Max{ 0 };
//    int d, SumTime;
//    std::cin >> d >> SumTime;
//
//    int Sum = 0;
//    int Least = 0;
//    for (int i = 0; i < d; ++i)
//    {
//        std::cin >> Min[i] >> Max[i];
//        Sum += Max[i];
//        Least += Min[i];
//    }
//
//    if (Sum < SumTime || Least > SumTime)
//    {
//        std::cout << "NO" << std::endl;
//    }
//    else
//    {
//        int Delta = SumTime - Least;
//        int i = 0;
//        while (Delta > 0)
//        {
//            Delta -= Max[i] - Min[i];
//            Min[i] = Max[i];
//            ++i;
//        }
//        if (Delta < 0)
//        {
//            Min[--i] += Delta;
//        }
//
//        std::puts("YES");
//        for (int i = 0; i < d; ++i)
//        {
//            std::cout << Min[i] << ' ';
//        }
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <queue>
//
//class Cost
//{
//public:
//    int p, v;
//
//    Cost() = default;
//    Cost(int P, int V) :
//        p(P), v(V)
//    {
//    }
//
//    bool operator<(const Cost &t) const
//    {
//        return t.v > v;
//    }
//};
//
//int main()
//{
//    std::string Str;
//    std::cin >> Str;
//    int Cnt = 0;
//    std::priority_queue<Cost> q;
//
//    long long Ans = 0;
//    for (std::size_t i = 0; i < Str.size(); ++i)
//    {
//        if (Str[i] == '(')
//        {
//            ++Cnt;
//        }
//        else
//        {
//            --Cnt;
//        }
//
//        int a, b;
//        if (Str[i] == '?')
//        {
//            std::cin >> a >> b;
//            q.push(std::move(Cost(i, b - a)));
//            Str[i] = ')';
//            Ans += b;
//        }
//
//        if (Cnt < 0 && q.empty())
//        {
//            Ans = -1;
//            break;
//        }
//
//        if (Cnt < 0)
//        {
//            auto Top = q.top();
//            q.pop();
//            Ans -= Top.v;
//            Str[Top.p] = '(';
//            Cnt += 2;
//        }
//    }
//
//    if (Cnt > 0)
//    {
//        Ans = -1;
//    }
//    std::cout << Ans << std::endl;
//    if (Ans != -1)
//    {
//        std::cout << Str << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//bool Less(const std::string &Str, int p, int q)
//{
//    for (std::size_t i = 0; i < Str.size(); ++i)
//    {
//        if (Str[(p + i) % Str.size()] != Str[(q + i) % Str.size()])
//        {
//            return Str[(p + i) % Str.size()] < Str[(q + i) % Str.size()];
//        }
//    }
//
//    return false;
//}
//
//int main()
//{
//    int t;
//    std::cin >> t;
//
//    std::string Str;
//    while (t--)
//    {
//        std::cin >> Str;
//        int Ans = 0;
//        for (std::size_t i = 1; i < Str.size(); ++i)
//        {
//            if (Less(Str, i, Ans))
//            {
//                Ans = i;
//            }
//        }
//
//        for (std::size_t i = 0; i < Str.size(); ++i)
//        {
//            std::putchar(Str[(i + Ans) % Str.size()]);
//        }
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    static std::array<int, 100053> Ans{ 0 };
//    for (int m = 1; m <= 100000; ++m)
//    {
//        int x = m, y = m;
//        while (x > 0)
//        {
//            y += x % 10;
//            x /= 10;
//        }
//
//        if (Ans[y] == 0 || m < Ans[y])
//        {
//            Ans[y] = m;
//        }
//    }
//
//    int n;
//    std::cin >> n;
//    while (n--)
//    {
//        int t;
//        std::cin >> t;
//        std::cout << Ans[t] << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n;
//    std::array<int, 1001> a{ 0 }, b{ 0 };
//    int Turn = 0;
//    while (std::cin >> n && n != 0)
//    {
//        std::cout << "Game " << ++Turn << ':' << std::endl;
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> a[i];
//        }
//
//        while (1)
//        {
//            int A = 0, B = 0;
//            for (int i = 0; i < n; ++i)
//            {
//                std::cin >> b[i];
//                if (a[i] == b[i])
//                {
//                    ++A;
//                }
//            }
//            if (b[0] == 0)
//            {
//                break;
//            }
//
//            for (int d = 1; d <= 9; ++d)
//            {
//                int c1 = 0, c2 = 0;
//                for (int i = 0; i < n; ++i)
//                {
//                    if (a[i] == d)
//                    {
//                        ++c1;
//                    }
//                    if (b[i] == d)
//                    {
//                        ++c2;
//                    }
//                }
//
//                if (c1 < c2)
//                {
//                    B += c1;
//                }
//                else
//                {
//                    B += c2;
//                }
//            }
//
//            std::printf("    (%d,%d)\n", A, B - A);
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//constexpr char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
//constexpr const char *msg[] = { "not a palindrome",
//                                "a regular palindrome",
//                                "a mirrored string",
//                                "a mirrored palindrome" };
//
//char r(char ch)
//{
//    if ('A' <= ch && ch <= 'Z')
//    {
//        return rev[ch - 'A'];
//    }
//    else
//    {
//        return rev[ch - '0' + 25];
//    }
//}
//
//int main()
//{
//    std::string Str;
//    while (std::cin >> Str)
//    {
//        int p = 1, m = 1;
//        for (std::size_t i = 0; i < (Str.size() + 1) / 2; ++i)
//        {
//            if (Str[i] != Str[Str.size() - 1 - i])
//            {
//                p = 0;
//            }
//            if (r(Str[i]) != Str[Str.size() - 1 - i])
//            {
//                m = 0;
//            }
//        }
//
//        std::cout << Str << " -- is " << msg[m * 2 + p] << ".\n" << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cmath>
//
//int main()
//{
//    int First = 0, Second = 0, Left = 9;
//    std::array<std::array<char, 3>, 3> Map;
//    for (int i = 0; i < 3; ++i)
//    {
//        for (int j = 0; j < 3; ++j)
//        {
//            std::cin >> Map[i][j];
//            if (Map[i][j] == 'X')
//            {
//                ++First;
//                --Left;
//            }
//            else if (Map[i][j] == '0')
//            {
//                ++Second;
//                --Left;
//            }
//        }
//    }
//
//    if ((Left == 0 && (First - Second) != 1)
//      || std::abs(First - Second) >= 2
//      || Second > First)
//    {
//        std::cout << "illegal" << std::endl;
//    }
//    else
//    {
//        if (Map[0][0] == 'X'
//         && Map[1][1] == 'X'
//         && Map[2][2] == 'X')
//        {
//            if (First - Second == 1)
//            {
//                std::cout << "the first player won" << std::endl;
//            }
//            else
//            {
//                std::cout << "illegal" << std::endl;
//            }
//        }
//        else if (Map[0][0] == '0'
//              && Map[1][1] == '0'
//              && Map[2][2] == '0')
//        {
//            if (First == Second)
//            {
//                std::cout << "the second player won" << std::endl;
//            }
//            else
//            {
//                std::cout << "illegal" << std::endl;
//            }
//        }
//        else if (Map[0][2] == 'X'
//              && Map[1][1] == 'X'
//              && Map[2][0] == 'X')
//        {
//            if (First - Second == 1)
//            {
//                std::cout << "the first player won" << std::endl;
//            }
//            else
//            {
//                std::cout << "illegal" << std::endl;
//            }
//        }
//        else if (Map[0][2] == '0'
//              && Map[1][1] == '0'
//              && Map[2][0] == '0')
//        {
//            if (First == Second)
//            {
//                std::cout << "the second player won" << std::endl;
//            }
//            else
//            {
//                std::cout << "illegal" << std::endl;
//            }
//        }
//        else
//        {
//            for (int i = 0; i < 3; ++i)
//            {
//                if (Map[0][i] == Map[1][i]
//                    && Map[1][i] == Map[2][i])
//                {
//                    if (Map[0][i] == 'X')
//                    {
//                        if (First - Second == 1)
//                        {
//                            std::cout << "the first player won" << std::endl;
//                        }
//                        else
//                        {
//                            std::cout << "illegal" << std::endl;
//                        }                        
//                        return 0;
//                    }
//                    else if (Map[0][i] == '0')
//                    {
//                        if (First == Second)
//                        {
//                            std::cout << "the second player won" << std::endl;
//                        }
//                        else
//                        {
//                            std::cout << "illegal" << std::endl;
//                        }
//                        return 0;
//                    }
//                }
//            }
//            for (int i = 0; i < 3; ++i)
//            {
//                if (Map[i][0] == Map[i][1]
//                    && Map[i][1] == Map[i][2])
//                {
//                    if (Map[i][0] == 'X')
//                    {
//                        if (First - Second == 1)
//                        {
//                            std::cout << "the first player won" << std::endl;
//                        }
//                        else
//                        {
//                            std::cout << "illegal" << std::endl;
//                        }                
//                        return 0;
//                    }
//                    else if (Map[i][0] == '0')
//                    {
//                        if (First == Second)
//                        {
//                            std::cout << "the second player won" << std::endl;
//                        }
//                        else
//                        {
//                            std::cout << "illegal" << std::endl;
//                        }
//                        return 0;
//                    }
//                }
//            }
//
//            if (Left == 0)
//            {
//                std::cout << "draw" << std::endl;
//            }
//            else if (First == Second)
//            {
//                std::cout << "first" << std::endl;
//            }
//            else if (First - Second == 1)
//            {
//                std::cout << "second" << std::endl;
//            }
//            else
//            {
//                std::cout << "illegal" << std::endl;
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cmath>
//#include <algorithm>
//
//int main()
//{
//    std::array<int, 1001> Arr{ 0 }, M{ 0 };
//    int n;
//    std::cin >> n;
//    for (int i = 1; i <= n; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//    for (int i = 1; i < n; ++i)
//    {
//        M[i] = std::abs(Arr[i] - Arr[i + 1]);
//    }
//
//    std::sort(M.begin() + 1, M.begin() + n);
//    for (int i = 1; i < n; ++i)
//    {
//        if (M[i] != i)
//        {
//            std::cout << "Not jolly" << std::endl;
//            return 0;
//        }
//    }
//    std::cout << "Jolly" << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    char c;
//    bool q = true;
//
//    while ((c = std::getchar()) != EOF)
//    {
//        if (c == '"')
//        {
//            if (q)
//            {
//                std::putchar('`');
//                std::putchar('`');
//            }
//            else
//            {
//                std::putchar('\'');
//                std::putchar('\'');
//            }
//
//            q = !q;
//        }
//        else
//        {
//            std::putchar(c);
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <utility>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n, v;
//    n = Read();
//    v = Read();
//    
//    std::vector<std::pair<int, int>> Kayak, Catamaran;
//    for (int i = 0; i < n; ++i)
//    {
//        int t, p;
//        t = Read();
//        p = Read();
//        if (t == 1)
//        {
//            Kayak.push_back({ i + 1, p });
//        }
//        else
//        {
//            Catamaran.push_back({ i + 1, p });
//        }
//    }
//
//    std::sort(Kayak.begin(), Kayak.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
//    {
//        return a.second > b.second;
//    });
//    std::sort(Catamaran.begin(), Catamaran.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
//    {
//        return a.second > b.second;
//    });
//
//    std::vector<int> KVal;
//    KVal.push_back(0);
//    for (std::size_t i = 0; i < Kayak.size(); i++)
//    {
//        KVal.push_back(KVal[KVal.size() - 1] + Kayak[i].second);
//    }
//
//    std::vector<int> CVal;
//    CVal.push_back(0);
//    for (std::size_t i = 0; i < Catamaran.size(); i++)
//    {
//        CVal.push_back(CVal[CVal.size() - 1] + Catamaran[i].second);
//    }
//
//    int CNum = 0, KNum = 0, Ans = 0;
//    for (std::size_t i = 0; i < CVal.size() && i * 2 <= static_cast<std::size_t>(v); ++i)
//    {
//        std::size_t j = v - 2 * i;
//        j = (j >= KVal.size() ? KVal.size() - 1 : (j < 0 ? 0 : j));
//        if (CVal[i] + KVal[j] > Ans)
//        {
//            Ans = CVal[i] + KVal[j];
//            CNum = i;
//            KNum = j;
//        }
//    }
//
//    std::vector<int> All;
//    for (int i = 0; i < KNum; ++i)
//    {
//        All.push_back(Kayak[i].first);
//    }
//    for (int j = 0; j < CNum; ++j)
//    {
//        All.push_back(Catamaran[j].first);
//    }
//
//    std::cout << Ans << std::endl;
//    for (std::size_t i = 0; i < All.size(); ++i)
//    {
//        std::printf("%d ", All[i]);
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//class Boat
//{
//public:
//    int NO, Type;
//    double Per;
//
//    Boat() = default;
//    Boat(double per, int type, int no) :
//        Per(per), Type(type), NO(no)
//    {
//    }
//};
//
//int main()
//{
//    int n, v;
//    std::cin >> n >> v;
//
//    std::vector<Boat> Vec;
//    for (int i = 0; i < n; ++i)
//    {
//        int t, p;
//        std::cin >> t >> p;
//        Vec.emplace_back(static_cast<double>(p) / t, t, i + 1);
//    }
//
//    std::sort(Vec.begin(), Vec.end(), [](const Boat &a, const Boat &b)
//    {
//        return a.Per > b.Per;
//    });
//
//    std::vector<int> Ans;
//    int i = 0;
//    int Tol = 0;
//    while (v > 0 && i < n)
//    {
//        if (v - Vec[i].Type >= 0)
//        {
//            v -= Vec[i].Type;
//            Tol += static_cast<int>(Vec[i].Per * Vec[i].Type);
//            Ans.push_back(Vec[i].NO);
//        }
//        ++i;
//    }
//
//    std::cout << Tol << std::endl;
//    for (const auto &r : Ans)
//    {
//        std::cout << r << ' ';
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    while (1)
//    {
//        std::cin >> n;
//        if (n != 42)
//        {
//            std::cout << n << std::endl;
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//
//int main()
//{
//    char c;
//    int n;
//    std::cin >> c >> n;
//    int KX = c - 'a' + 1;
//    int KY = n;
//    std::cin >> c >> n;
//    int BX = c - 'a' + 1;
//    int BY = n;
//
//    int dx = KX - BX, dy = KY - BY;
//    char mx = dx > 0 ? 'L' : 'R';
//    char my = dy > 0 ? 'D' : 'U';
//    dx = std::abs(dx);
//    dy = std::abs(dy);
//
//    std::cout << std::max(dx, dy) << std::endl;
//    while (dx > 0 || dy > 0)
//    {
//        if (dx > 0)
//        {
//            std::putchar(mx);
//            --dx;
//        }
//        if (dy > 0)
//        {
//            std::putchar(my);
//            --dy;
//        }
//
//        std::putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cmath>
//
//constexpr double EPS = 1e-5;
//
//struct Point
//{
//    double x, y, r;
//};
//
//std::array<Point, 3> P;
//
//double Dist(double x, double y, Point P)
//{
//    return std::sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
//}
//
//double Calc(double x, double y)
//{
//    std::array<double, 3> T;
//    for (int i = 0; i < 3; ++i)
//    {
//        T[i] = Dist(x, y, P[i]) / P[i].r;
//    }
//
//    double Tol = 0.0;
//    for (int i = 0; i < 3; ++i)
//    {
//        Tol += (T[i] - T[(i + 1) % 3]) * (T[i] - T[(i + 1) % 3]);
//    }
//
//    return Tol;
//}
//
//int main()
//{
//    for (int i = 0; i < 3; ++i)
//    {
//        std::cin >> P[i].x >> P[i].y >> P[i].r;
//    }
//
//    double x, y;
//    x = (P[0].x + P[1].x + P[2].x) / 3;
//    y = (P[0].y + P[1].y + P[2].y) / 3;
//
//    double Step = 10;
//    while (Step > EPS)
//    {
//        double Now = Calc(x, y);
//
//        if (Calc(x - Step, y) < Now)
//        {
//            x -= Step;
//        }
//        else if (Calc(x + Step, y) < Now)
//        {
//            x += Step;
//        }
//        else if (Calc(x, y - Step) < Now)
//        {
//            y -= Step;
//        }
//        else if (Calc(x, y + Step) < Now)
//        {
//            y += Step;
//        }
//        else
//        {
//            Step /= 2;
//        }
//    }
//
//    if (Calc(x, y) <= EPS)
//    {
//        std::printf("%.5lf %.5lf\n", x, y);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//std::array<std::array<int, 1000>, 1000> Map{ 0 };
//std::array<std::array<std::array<int, 2>, 1000>, 1000> DP{ 9999999 };
//std::array<std::array<std::array<char, 2>, 1000>, 1000> Ans{ '\0' };
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int Get(int i, int n)
//{
//    int Tol = 0;
//    while (i > 0 && i % n == 0)
//    {
//        ++Tol;
//        i /= n;
//    }
//
//    return Tol;
//}
//
//void Print(int i, int j, int k)
//{
//    if (i >= 0 && j >= 0)
//    {
//        if (Ans[i][j][k] == 'D')
//        {
//            Print(i - 1, j, k);
//        }
//        else
//        {
//            Print(i, j - 1, k);
//        }
//
//        if (Ans[i][j][k] != '\0')
//        {
//            std::putchar(Ans[i][j][k]);
//        }
//    }
//}
//
//void PrintZero(int x, int y, int n)
//{
//    std::puts("1");
//    for (int i = 0; i < x; ++i)
//    {
//        std::putchar('D');
//    }
//    for (int i = 0; i < y; ++i)
//    {
//        std::putchar('R');
//    }
//    for (int i = 0; i < n - x - 1; ++i)
//    {
//        std::putchar('D');
//    }
//    for (int i = 0; i < n - y - 1; ++i)
//    {
//        std::putchar('R');
//    }
//}
//
//int main()
//{
//    int n;
//    n = Read();
//
//    bool Flag = false;
//    int x, y;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            Map[i][j] = Read();
//            if (Map[i][j] == 0)
//            {
//                Flag = true;
//                Map[i][j] = 10;
//                x = i;
//                y = j;
//            }
//        }
//    }
//
//    DP[0][0][0] = Get(Map[0][0], 2);
//    DP[0][0][1] = Get(Map[0][0], 5);
//    for (int i = 1; i < n; ++i)
//    {
//        DP[i][0][0] += DP[i - 1][0][0] + Get(Map[i][0], 2);
//        DP[i][0][1] += DP[i - 1][0][1] + Get(Map[i][0], 5);
//        DP[0][i][0] += DP[0][i - 1][0] + Get(Map[0][i], 2);
//        DP[0][i][1] += DP[0][i - 1][1] + Get(Map[0][i], 5);
//
//        Ans[i][0][0] = 'D';
//        Ans[i][0][1] = 'D';
//        Ans[0][i][0] = 'R';
//        Ans[0][i][1] = 'R';
//    }
//
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 1; j < n; ++j)
//        {
//            auto p2i = DP[i - 1][j][0];
//            auto p2j = DP[i][j - 1][0];
//            auto p5i = DP[i - 1][j][1];
//            auto p5j = DP[i][j - 1][1];
//
//            p2i += Get(Map[i][j], 2);
//            p2j += Get(Map[i][j], 2);
//            p5i += Get(Map[i][j], 5);
//            p5j += Get(Map[i][j], 5);
//
//            if (p2i < p2j)
//            {
//                DP[i][j][0] = p2i;
//                Ans[i][j][0] = 'D';
//            }
//            else
//            {
//                DP[i][j][0] = p2j;
//                Ans[i][j][0] = 'R';
//            }
//            if (p5i < p5j)
//            {
//                DP[i][j][1] = p5i;
//                Ans[i][j][1] = 'D';
//            }
//            else
//            {
//                DP[i][j][1] = p5j;
//                Ans[i][j][1] = 'R';
//            } 
//        }
//    }
//
//    auto Cost = std::min(DP[n - 1][n - 1][0], DP[n - 1][n - 1][1]);
//    if (Flag && Cost > 0)
//    {
//        PrintZero(x, y, n);
//    }
//    else
//    {
//        if (DP[n - 1][n - 1][0] > DP[n - 1][n - 1][1])
//        {
//            std::cout << Cost << std::endl;
//            Print(n - 1, n - 1, 1);
//        }
//        else
//        {
//            std::cout << Cost << std::endl;
//            Print(n - 1, n - 1, 0);
//        }
//    }
//    std::putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <utility>
//#include <climits>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    
//    std::unordered_map<std::string, int> Map;
//    std::vector<std::pair<std::string, int>> Vec;
//    std::string Name;
//    int Score, Max = -INT_MAX;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Name >> Score;
//        Map[Name] += Score;
//        Vec.push_back({ Name, Score });
//    }
//    for (const auto &r : Map)
//    {
//        Max = std::max(Max, r.second);
//    }
//
//    int Tol = 0;
//    std::string Ans;
//    for (const auto &r : Map)
//    {
//        if (r.second == Max)
//        {
//            ++Tol;
//            Ans = r.first;
//        }
//    }
//
//    if (Tol == 1)
//    {
//        std::cout << Ans << std::endl;
//    }
//    else
//    {
//        std::unordered_map<std::string, int> Temp;
//        for (int i = 0; i < n; ++i)
//        {
//            Temp[Vec[i].first] += Vec[i].second;
//            if (Map[Vec[i].first] == Max && Temp[Vec[i].first] >= Max)
//            {
//                std::cout << Vec[i].first << std::endl;
//                break;
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//constexpr double EPS = 1e-3;
//
//double Dist(double x1, double x2, double y1, double y2)
//{
//    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
//}
//
//double FGCD(double a, double b)
//{
//    if (std::fabs(b) < EPS)
//    {
//        return a;
//    }
//    else if (std::fabs(a) < EPS)
//    {
//        return b;
//    }
//    else
//    {
//        return FGCD(b, std::fmod(a, b));
//    }
//}
//
//int main()
//{
//    double x1, x2, y1, y2, x3, y3;
//    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
//
//    double S = 0.5 * (x1 * y2 - x1 * y3 + x2 * y3 - x2 * y1 + x3 * y1 - y2 * x3);
//    double a = Dist(x1, x2, y1, y2);
//    double b = Dist(x1, x3, y1, y3);
//    double c = Dist(x2, x3, y2, y3);
//    double R = a * b * c / 4.0 / S;
//    double A = 2 * std::asin(a / (2 * R));
//    double B = 2 * std::asin(b / (2 * R));
//    double C = 2 * std::acos(-1) - A - B;
//    double t = FGCD(FGCD(A, B), C);
//    double Ans = std::acos(-1) * R * R * std::sin(t) / t;
//    std::printf("%.8lf\n", Ans);
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//constexpr char Base[] = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
//
//void ToExcel(const std::string &Str)
//{
//    int Row = 0;
//    auto Beg = Str.cbegin() + 1;
//    while (*Beg != 'C')
//    {
//        Row *= 10;
//        Row += *Beg - '0';
//        ++Beg;
//    }
//
//    ++Beg;
//    int Col = 0;
//    while (Beg != Str.cend())
//    {
//        Col *= 10;
//        Col += *Beg - '0';
//        ++Beg;
//    }
//
//    std::string StrCol;
//    while (Col > 0)
//    {
//        StrCol.push_back(Base[Col % 26]);
//        Col /= 26;
//    }
//
//    for (auto beg = StrCol.crbegin(); beg != StrCol.crend(); ++beg)
//    {
//        std::cout << *beg;
//    }
//    std::cout << Row << std::endl;
//}
//
//void ToRXCY(const std::string &Str)
//{
//    int Col = 0;
//    auto beg = Str.cbegin();
//    for ( ; !('0' <= *beg && *beg <= '9'); ++beg)
//    {
//        Col *= 26;
//        Col += *beg - 'A' + 1;
//    }
//
//    int Row = 0;
//    while (beg != Str.cend())
//    {
//        Row *= 10;
//        Row += *beg - '0';
//        ++beg;
//    }
//
//    std::cout << 'R' << Row << 'C' << Col << std::endl;
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    while (n--)
//    {
//        std::string Str;
//        std::cin >> Str;
//        if (Str[0] == 'R' && '0' <= Str[1] && Str[1] <= '9')
//        {
//            ToExcel(Str);
//        }
//        else
//        {
//            ToRXCY(Str);
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//
//constexpr char Base[] = "0123456789ABCDEFGHIJ";
//
//std::string Change(int Num, int b)
//{
//    std::string Str;
//    while (Num > 0)
//    {
//        Str.push_back(Base[Num % b]);
//        Num /= b;
//    }
//
//    return Str;
//}
//
//bool Check(const std::string &Str)
//{
//    auto beg = Str.cbegin();
//    auto end = Str.crbegin();
//    for (; beg != Str.cend(), end != Str.crend(); ++beg, ++end)
//    {
//        if (*beg != *end)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    int n, num;
//    std::cin >> n >> num;
//    int tol = 0;
//    while (1)
//    {
//        if (tol == n)
//        {
//            break;
//        }
//        else
//        {
//            ++num;
//
//            int cnt = 0;
//            for (int b = 2; b <= 10; ++b)
//            {
//                if (Check(Change(num, b)))
//                {
//                    ++cnt;
//                }
//
//                if (cnt >= 2)
//                {
//                    std::cout << num << std::endl;
//                    ++tol;
//                    break;
//                }
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//
//constexpr char Base[] = "0123456789ABCDEFGHIJ";
//
//std::string Change(int Num, int b)
//{
//    std::string Str;
//    while (Num > 0)
//    {
//        Str.push_back(Base[Num % b]);
//        Num /= b;
//    }
//
//    return Str;
//}
//
//bool Check(const std::string Str)
//{
//    auto beg = Str.cbegin();
//    auto end = Str.crbegin();
//    for (; beg != Str.cend(), end != Str.crend(); ++beg, ++end)
//    {
//        if (*beg != *end)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    std::array<int, 300> SquareOf;
//    for (int i = 0; i < 300; ++i)
//    {
//        SquareOf[i] = (i + 1) * (i + 1);
//    }
//
//    int b;
//    std::cin >> b;
//    for (int i = 0; i < 300; ++i)
//    {
//        auto rev = Change(SquareOf[i], b);
//        if (Check(rev))
//        {
//            auto base = Change(i + 1, b);
//            for (auto beg = base.crbegin(); beg != base.crend(); ++beg)
//            {
//                std::cout << *beg;
//            }
//            putchar(' ');
//
//            for (auto beg = rev.crbegin(); beg != rev.crend(); ++beg)
//            {
//                std::cout << *beg;
//            }
//            putchar('\n');
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int n;
//
//template <typename T>
//T Turn(const T &Map)
//{
//    T Temp;
//    for (int i = 0; i < 11; ++i)
//    {
//        for (int j = 0; j < 11; ++j)
//        {
//            if (Temp[i][j] != '@' || Temp[i][j] != '-')
//            {
//                Temp[i][j] = ' ';
//            }
//        }
//    }
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            Temp[j][n + 1 - i] = Map[i][j];
//        }
//    }
//
//    return Temp;
//}
//
//template <typename T>
//T Horizon(const T &Map)
//{
//    T Temp;
//    for (int i = 0; i < 11; ++i)
//    {
//        for (int j = 0; j < 11; ++j)
//        {
//            if (Temp[i][j] != '@' || Temp[i][j] != '-')
//            {
//                Temp[i][j] = ' ';
//            }
//        }
//    }
//
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            Temp[i][n + 1 - j] = Map[i][j];
//        }
//    }
//
//    return Temp;
//}
//
//int main()
//{
//    std::array<std::array<char, 11>, 11> Map, Aim;
//    for (int i = 0; i < 11; ++i)
//    {
//        for (int j = 0; j < 11; ++j)
//        {
//            Map[i][j] = Aim[i][j] = ' ';
//        }
//    }
//
//    std::cin >> n;
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            std::cin >> Map[i][j];
//        }
//    }
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            std::cin >> Aim[i][j];
//        }
//    }
//
//    int Ans = 1;
//    if (Turn(Map) == Aim)
//    {
//        Ans = 1;
//    }
//    else if (Turn(Turn(Map)) == Aim)
//    {
//        Ans = 2;
//    }
//    else if (Turn(Turn(Turn(Map))) == Aim)
//    {
//        Ans = 3;
//    }
//    else if (Horizon(Map) == Aim)
//    {
//        Ans = 4;
//    }
//    else if (Turn(Horizon(Map)) == Aim
//          || Turn(Turn(Horizon(Map))) == Aim
//          || Turn(Turn(Turn(Horizon(Map)))) == Aim)
//    {
//        Ans = 5;
//    }
//    else if (Map == Aim)
//    {
//        Ans = 6;
//    }
//    else
//    {
//        Ans = 7;
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <bitset>
//#include <algorithm>
//
//int main()
//{
//    int n;
//    int a, b;
//
//    int Max = 0, Min = 1000000;
//    std::bitset<1000001> Bits;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> a >> b;
//        for (int j = a; j < b; ++j)
//        {
//            Bits[j] = true;
//        }
//        Max = std::max(Max, b);
//        Min = std::min(Min, a);
//    }
//
//    int AnsL = 0, AnsNL = 0;
//    int L = 0, NL = 0;
//    for (int i = Min; i < Max; ++i)
//    {
//        if (Bits[i] == true)
//        {
//            ++L;
//
//            if (Bits[i + 1] == false)
//            {
//                AnsL = std::max(AnsL, L);
//                L = 0;
//            }
//        }
//
//        if (Bits[i] == false)
//        {
//            ++NL;
//
//            if (Bits[i + 1] == true)
//            {
//                AnsNL = std::max(AnsNL, NL);
//                NL = 0;
//            }
//        }
//    }
//
//    std::cout << AnsL << ' ' << AnsNL << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    int n;
//    std::string s;
//    std::cin >> n >> s;
//    
//    int state, max = 0, current, j;
//    char c;
//    s += s;
//    for (int i = 0; i < n; ++i)
//    {
//        c = s[i];
//        if (c == 'w')
//        {
//            state = 0;
//        }
//        else
//        {
//            state = 1;
//        }
//
//        j = i;
//        current = 0;
//        while (state <= 2)
//        {
//            while (j < n + i && (s[j] == c || s[j] == 'w'))
//            {
//                ++current;
//                ++j;
//            }
//
//            ++state;
//            c = s[j];
//        }
//
//        if (current > max)
//        {
//            max = current;
//        }
//    }
//
//    std::cout << max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//bool IsLeapYear(int Year)
//{
//    return Year % ((Year % 100) ? 4 : 400) ? false : true;
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    int Last = 3;
//    std::array<int, 12> Day{ 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
//    std::array<int, 7> Ans{ 0 };
//    for (int Year = 1900; Year < 1900 + n; ++Year)
//    {
//        if (IsLeapYear(Year))
//        {
//            Day[2] = 29;
//        }
//
//        for (int i = 0; i < 12; ++i)
//        {
//            Last = (Last + Day[i]) % 7;
//            ++Ans[Last];
//        }
//
//        Day[2] = 28;
//    }
//
//    std::cout << Ans[6] << ' ';
//    for (int i = 0; i < 6; ++i)
//    {
//        std::cout << Ans[i] << ' ';
//    }
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//#include <string>
//#include <array>
//
//int main()
//{
//    int NP;
//    std::cin >> NP;
//
//    std::array<std::string, 10> Name;
//    std::string Person;
//    std::unordered_map<std::string, int> Map;
//    for (int i = 0; i < NP; ++i)
//    {
//        std::cin >> Person;
//        Map[Person] = 0;
//        Name[i] = Person;
//    }
//
//    for (int i = 0; i < NP; ++i)
//    {
//        std::cin >> Person;
//        int Tol, Num;
//        std::cin >> Tol >> Num;
//
//        if (Num != 0)
//        {
//            Map[Person] -= Tol;
//            Map[Person] += Tol % Num;
//            for (int i = 0; i < Num; ++i)
//            {
//                std::cin >> Person;
//                Map[Person] += Tol / Num;
//            }
//        }
//    }
//
//    for (int i = 0; i < NP; ++i)
//    {
//        std::cout << Name[i] << ' ' << Map[Name[i]] << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string Str1, Str2;
//    std::cin >> Str1 >> Str2;
//
//    int num1 = 1, num2 = 1;
//    for (const auto &r : Str1)
//    {
//        num1 *= r - 'A' + 1;
//    }
//    num1 %= 47;
//
//    for (const auto &r : Str2)
//    {
//        num2 *= r - 'A' + 1;
//    }
//    num2 %= 47;
//
//    std::cout << (num1 == num2 ? "GO" : "STAY") << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    static std::array<int, 2000001> a{ 0 }, b{ 0 }, deq{ 0 };
//    int n, m;
//    n = Read();
//    m = Read();
//    for (int i = 0; i < n; ++i)
//    {
//        a[i] = Read();
//    }
//
//    int s = 0, t = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        while (s < t && a[deq[t - 1]] >= a[i])
//        {
//            --t;
//        }
//        deq[t++] = i;
//        b[i] = a[deq[s]];
//
//        if (deq[s] == i - m + 1)
//        {
//            ++s;
//        }
//    }
//
//    std::puts("0");
//    for (int i = 0; i < n - 1; ++i)
//    {
//        std::printf("%d\n", b[i]);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <array>
//
//int V;
//std::array<std::vector<int>, 50001> G, RG;
//std::array<bool, 50001> Used{ false };
//std::array<int, 50001> Cmp{ 0 };
//std::vector<int> VS;
//
//void AddEdge(int From, int To)
//{
//    G[From].push_back(To);
//    RG[To].push_back(From);
//}
//
//void DFS(int v)
//{
//    Used[v] = true;
//    for (std::size_t i = 0; i < G[v].size(); ++i)
//    {
//        if (!Used[G[v][i]])
//        {
//            DFS(G[v][i]);
//        }
//    }
//    VS.push_back(v);
//}
//
//void RDFS(int v, int k)
//{
//    Used[v] = true;
//    Cmp[v] = k;
//    for (std::size_t i = 0; i < RG[v].size(); ++i)
//    {
//        if (!Used[RG[v][i]])
//        {
//            RDFS(RG[v][i], k);
//        }
//    }
//}
//
//int SCC()
//{
//    for (int v = 0; v < V; ++v)
//    {
//        if (!Used[v])
//        {
//            DFS(v);
//        }
//    }
//
//    std::fill(Used.begin(), Used.end(), false);
//    int k = 0;
//    for (int i = static_cast<int>(VS.size()) - 1; i >= 0; --i)
//    {
//        if (!Used[VS[i]])
//        {
//            RDFS(VS[i], k++);
//        }
//    }
//
//    return k;
//}
//
//int main()
//{
//    int N, M;
//    std::cin >> N >> M;
//
//    std::array<int, 50001> A{ 0 }, B{ 0 };
//    for (int i = 0; i < M; ++i)
//    {
//        std::cin >> A[i] >> B[i];
//    }
//
//    V = N;
//    for (int i = 0; i < M; ++i)
//    {
//        AddEdge(A[i] - 1, B[i] - 1);
//    }
//    int n = SCC();
//
//    int u = 0, num = 0;
//    for (int v = 0; v < V; ++v)
//    {
//        if (Cmp[v] == n - 1)
//        {
//            u = v;
//            ++num;
//        }
//    }
//
//    std::fill(Used.begin(), Used.end(), false);
//    RDFS(u, 0);
//    for (int v = 0; v < V; ++v)
//    {
//        if (!Used[v])
//        {
//            num = 0;
//            break;
//        }
//    }
//
//    std::cout << num << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int k;
//    std::cin >> k;
//    if (k % 2 == 0 && k >= 4)
//    {
//        std::cout << "YES" << std::endl;
//    }
//    else
//    {
//        std::cout << "NO" << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    while (n != 0)
//    {
//        if (n % 2 == 0)
//        {
//            std::cout << "Alice" << std::endl;
//        }
//        else
//        {
//            std::cout << "Bob" << std::endl;
//        }
//
//        std::cin >> n;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int t, x = 0;
//    std::cin >> t;
//    static std::array<int, 500001> Arr{ 0 };
//    for (int i = 1; i <= t; ++i)
//    {
//        std::cin >> Arr[i];
//        x ^= Arr[i];
//    }
//
//    if (x == 0)
//    {
//        std::cout << "lose" << std::endl;
//    }
//    else
//    {
//        for (int i = 1; i <= t; ++i)
//        {
//            if ((Arr[i] ^ x) < Arr[i])
//            {
//                std::cout << (Arr[i] - (Arr[i] ^ x)) << ' ' << i << std::endl;
//                Arr[i] ^= x;
//                break;
//            }
//        }
//
//        for (int i = 1; i <= t; ++i)
//        {
//            std::cout << Arr[i] << ' ';
//        }
//        putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int t;
//    std::cin >> t;
//    while (t--)
//    {
//        int n, p, x = 0;
//        std::cin >> n;
//        for (int i = 0; i < n; ++i)
//        {
//            std::cin >> p;
//            x ^= p;
//        }
//
//        if (x != 0)
//        {
//            std::cout << "Yes" << std::endl;
//        }
//        else
//        {
//            std::cout << "No" << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    while (n--)
//    {
//        int p;
//        std::cin >> p;
//        if (p % 6 == 0)
//        {
//            std::cout << "Roy wins!" << std::endl;
//        }
//        else
//        {
//            std::cout << "October wins!" << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//int main()
//{
//    int n, k;
//    std::cin >> n >> k;
//
//    int Ans = 0, p;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> p;
//        if (k % p == 0)
//        {
//            Ans = std::max(Ans, p);
//        }
//    }
//
//    std::cout << k / Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int a, b;
//    std::cin >> a >> b;
//    std::cout << a + b << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string s, t;
//    std::cin >> s >> t;
//
//    auto sb = s.cbegin();
//    auto tb = t.crbegin();
//    for (; sb != s.cend(), tb != t.crend(); ++sb, ++tb)
//    {
//        if (*sb != *tb)
//        {
//            std::cout << "NO" << std::endl;
//            return 0;
//        }
//    }
//
//    std::cout << "YES" << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//int main()
//{
//    ll N, M, L;
//    std::cin >> N >> M >> L;
//
//    ll Pos = L;
//    N /= 2;
//    for (ll i = 1; i <= M; ++i)
//    {
//        if (L % 2 == 0)
//        {
//            L /= 2;
//        }
//        else
//        {
//            L = L / 2 + N + 1;
//        }
//
//        if (L == Pos && i != 0)
//        {
//            M %= i;
//            i = 0;
//        }
//    }
//
//    std::cout << L << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//template <typename T>
//void extgcd(T a, T b, T &x, T &y)
//{
//    if (b != 0)
//    {
//        extgcd(b, a % b, y, x);
//        y -= (a / b) * x;
//    }
//    else
//    {
//        x = 1;
//        y = 0;
//    }
//}
//
//template <typename T>
//T ModInverse(T a, T m)
//{
//    T x, y;
//    extgcd(a, m, x, y);
//
//    return (m + x % m) % m;
//}
//
//int main()
//{
//    ll a, b;
//    std::cin >> a >> b;
//    std::cout << ModInverse(a, b) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//int main()
//{
//    ll n, m, a;
//    std::cin >> n >> m >> a;
//
//    ll p, q;
//    if (n % a == 0)
//    {
//        p = n / a;
//    }
//    else
//    {
//        p = n / a + 1;
//    }
//    if (m % a == 0)
//    {
//        q = m / a;
//    }
//    else
//    {
//        q = m / a + 1;
//    }
//
//    std::cout << p * q << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n, p;
//    std::cin >> n >> p;
//
//    static std::array<long long, 3000001> Arr{ 0 };
//    Arr[1] = 1;
//    std::cout << 1 << std::endl;
//    for (long long i = 2; i <= n; ++i)
//    {
//        Arr[i] = static_cast<long long>((p - p / i) * Arr[p % i] % p);
//        std::printf("%lld\n", Arr[i]);
//    }
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//template <typename T>
//T extgcd(T a, T b, T &x, T &y)
//{
//    T d = 0;
//    if (b != 0)
//    {
//        d = extgcd(b, a % b, y, x);
//        y -= (a / b) * x;
//    }
//    else
//    {
//        x = 1;
//        y = 0;
//    }
//
//    return d;
//}
//
//template <typename T>
//T ModInverse(T a, T m)
//{
//    T x, y;
//    extgcd(a, m, x, y);
//
//    return (m + x % m) % m;
//}
//
//int main()
//{
//    ll n, p;
//    std::cin >> n >> p;
//
//    for (ll i = 1; i <= n; ++i)
//    {
//        std::printf("%lld\n", ModInverse(i, p));
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <utility>
//#include <cmath>
//
//using vec = std::vector<double>;
//using mat = std::vector<vec>;
//
//constexpr double EPS = 1e-8;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//vec GaussJordan(const mat &A, const vec &b)
//{
//    auto n = A.size();
//    mat B(n, vec(n + 1));
//    for (std::size_t i = 0; i < n; ++i)
//    {
//        for (std::size_t j = 0; j < n; ++j)
//        {
//            B[i][j] = A[i][j];
//        }
//        B[i][n] = b[i];
//    }
//
//    for (std::size_t i = 0; i < n; ++i)
//    {
//        auto Privot = i;
//        for (auto j = i; j < n; ++j)
//        {
//            if (std::abs(B[j][i]) > std::abs(B[Privot][i]))
//            {
//                Privot = j;
//            }
//        }
//        std::swap(B[i], B[Privot]);
//
//        if (std::abs(B[i][i]) < EPS)
//        {
//            return vec();
//        }
//
//        for (auto j = i + 1; j <= n; ++j)
//        {
//            B[i][j] /= B[i][i];
//        }
//        for (std::size_t j = 0; j < n; ++j)
//        {
//            if (i != j)
//            {
//                for (auto k = i + 1; k <= n; ++k)
//                {
//                    B[j][k] -= B[j][i] * B[i][k];
//                }
//            }
//        }
//    }
//
//    vec x(n);
//    for (std::size_t i = 0; i < n; ++i)
//    {
//        x[i] = B[i][n];
//    }
//
//    return x;
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    mat A(n, vec(n));
//    vec B(n);
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            A[i][j] = Read();
//        }
//        B[i] = Read();
//    }
//
//    auto Ans = GaussJordan(A, B);
//    if (Ans.empty())
//    {
//        std::cout << "No Solution" << std::endl;
//    }
//    else
//    {
//        for (const auto &r : Ans)
//        {
//            std::printf("%.2lf\n", r);
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n, m;
//    std::cin >> n >> m;
//
//    std::array<int, 1001> P{ 0 };
//    for (int i = 0; i < m; ++i)
//    {
//        int a, b;
//        std::cin >> a >> b;
//        ++P[a];
//        ++P[b];
//    }
//
//    int Ans = 0;
//    for (const auto &r : P)
//    {
//        if (r % 2 == 1)
//        {
//            ++Ans;
//        }
//    }
//
//    if (Ans == 0)
//    {
//        std::cout << 1 << std::endl;
//    }
//    else
//    {
//        std::cout << Ans / 2 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 100001> Par{ 0 }, Rank{ 0 }, Prime{ 0 };
//std::array<bool, 100001> IsPrime{ false };
//
//void Init(int n)
//{
//    for (int i = 0; i < 100001; ++i)
//    {
//        Par[i] = i;
//    }
//}
//
//int Find(int x)
//{
//    if (Par[x] == x)
//    {
//        return x;
//    }
//    else
//    {
//        return Par[x] = Find(Par[x]);
//    }
//}
//
//void Unite(int x, int y)
//{
//    x = Find(x);
//    y = Find(y);
//    if (x == y)
//    {
//        return;
//    }
//    else
//    {
//        if (Rank[x] < Rank[y])
//        {
//            Par[x] = y;
//        }
//        else
//        {
//            Par[y] = x;
//
//            if (Rank[x] == Rank[y])
//            {
//                ++Rank[x];
//            }
//        }
//    }
//}
//
//bool IsSame(int x, int y)
//{
//    return Find(x) == Find(y);
//}
//
//int Sieve(int n)
//{
//    int p = 0;
//    for (int i = 2; i <= n; ++i)
//    {
//        IsPrime[i] = true;
//    }
//
//    for (int i = 2; i <= n; ++i)
//    {
//        if (IsPrime[i])
//        {
//            Prime[p++] = i;
//
//            for (int j = 2 * i; j <= n; j += i)
//            {
//                IsPrime[j] = false;
//            }
//        }
//    }
//
//    return p;
//}
//
//int main()
//{
//    int A, B, P;
//    std::cin >> A >> B >> P;
//
//    int Len = B - A + 1;
//    Init(Len);
//
//    int p = Sieve(B);
//    for (int i = 0; i < p; ++i)
//    {
//        if (Prime[i] >= P)
//        {
//            int Start = (A + Prime[i] - 1) / Prime[i] * Prime[i];
//            int End = B / Prime[i] * Prime[i];
//            for (int j = Start; j <= End; j += Prime[i])
//            {
//                Unite(Start - A, j - A);
//            }
//        }
//    }
//
//    int Res = 0;
//    for (int i = A; i <= B; ++i)
//    {
//        if (Find(i - A) == i - A)
//        {
//            ++Res;
//        }
//    }
//
//    std::cout << Res << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//constexpr double EPS = 1e-10;
//
//double Add(double a, double b)
//{
//    if (std::abs(a + b) < EPS * (std::abs(a) + std::abs(b)))
//    {
//        return 0;
//    }
//    else
//    {
//        return a + b;
//    }
//}
//
//struct Point
//{
//public:
//    double x, y;
//    Point() = default;
//    Point(double X, double Y) :
//        x(X), y(Y)
//    {
//    }
//
//    Point operator+(const Point &p)
//    {
//        return Point(Add(x, p.x), Add(y, p.y));
//    }
//
//    Point operator-(const Point &p)
//    {
//        return Point(Add(x, -p.x), Add(y, -p.y));
//    }
//
//    Point operator*(double d)
//    {
//        return Point(x * d, y * d);
//    }
//
//    double Dot(const Point &p)
//    {
//        return Add(x * p.x, y * p.y);
//    }
//
//    double Det(const Point &p)
//    {
//        return Add(x * p.y, -y * p.x);
//    }
//};
//
//std::vector<Point> ConvexHull(std::vector<Point> &ps)
//{
//    std::sort(ps.begin(), ps.end(), [](const Point &p, const Point &q)
//    {
//        if (p.x != q.x)
//        {
//            return p.x < q.x;
//        }
//        else
//        {
//            return p.y < q.y;
//        }
//    });
//
//    int k = 0;
//    std::vector<Point> qs(ps.size() * 2);
//    for (std::size_t i = 0; i < ps.size(); ++i)
//    {
//        while (k > 1 && (qs[k - 1] - qs[k - 2]).Det(ps[i] - qs[k - 1]) <= 0)
//        {
//            --k;
//        }
//        qs[k++] = ps[i];
//    }
//    for (int i = static_cast<int>(ps.size() - 2), t = k; i >= 0; --i)
//    {
//        while (k > t && (qs[k - 1] - qs[k - 2]).Det(ps[i] - qs[k - 1]) <= 0)
//        {
//            --k;
//        }
//        qs[k++] = ps[i];
//    }
//
//    qs.resize(k - 1);
//    return qs;
//}
//
//double Dist(const Point &p, const Point &q)
//{
//    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    std::vector<Point> ps;
//    for (int i = 0; i < n; ++i)
//    {
//        double x, y;
//        std::cin >> x >> y;
//        ps.emplace_back(x, y);
//    }
//
//    auto qs = ConvexHull(ps);
//    double Res = 0.0;
//    for (std::size_t i = 0; i < qs.size(); ++i)
//    {
//        for (std::size_t j = 0; j < i; ++j)
//        {
//            Res = std::max(Res, Dist(qs[i], qs[j]));
//        }
//    }
//
//    std::printf("%.0lf\n", Res);
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//#include <cmath>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n;
//    n = Read();
//
//    static std::array<int, 10000> x{ 0 }, y{ 0 };
//    for (int i = 0; i < n; ++i)
//    {
//        x[i] = Read();
//        y[i] = Read();
//    }
//
//    double Ans = 99999999999.9;
//    for (int i = 0; i < n - 1; ++i)
//    {
//        for (int j = i + 1; j < n; ++j)
//        {
//            Ans = std::min(Ans, std::sqrt((x[i] - x[j]) * (x[i] - x[j])
//                                        + (y[i] - y[j]) * (y[i] - y[j])));
//        }
//    }
//
//    std::printf("%.4lf\n", Ans);
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <unordered_set>
//
//constexpr int INF = 999999999;
//
//class Edge
//{
//public:
//    int To, Cap, Rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) :
//        To(to), Cap(cap), Rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, 2500> G;
//std::array<int, 2500> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].emplace_back(To, Cap, G[To].size());
//    G[To].emplace_back(From, 0, G[From].size() - 1);
//}
//
//void BFS(int s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//
//    std::queue<int> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.Cap > 0 && Level[e.To] < 0)
//            {
//                Level[e.To] = Level[v] + 1;
//                Que.push(e.To);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < static_cast<int>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//
//        if (e.Cap > 0 && Level[v] < Level[e.To])
//        {
//            int d = DFS(e.To, t, std::min(f, e.Cap));
//
//            if (d > 0)
//            {
//                e.Cap -= d;
//                G[e.To][e.Rev].Cap += d;
//
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//
//    while (1)
//    {
//        BFS(s);
//
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//
//        int F;
//        while ((F = DFS(s, t, INF)) > 0)
//        {
//            Flow += F;
//        }
//    }
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    std::unordered_set<int> X, Y, Z;
//    int S = 2001, T = 2002;
//    while (n--)
//    {
//        int x, y, z;
//        x = Read();
//        y = Read();
//        z = Read();
//
//        if (X.find(x) == X.end())
//        {
//            AddEdge(S, x, 1);
//            X.insert(x);
//        }
//
//        AddEdge(x, y + 500, 1);
//        AddEdge(y + 500, y + 1000, 1);
//
//        if (Z.find(z) == Z.end())
//        {
//            AddEdge(y + 1000, z + 1500, 1);
//            AddEdge(z + 1500, T, 1);
//        }
//    }
//
//    std::cout << MaxFlow(S, T) << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    int m, n;
//    std::cin >> m >> n;
//    
//    std::array<std::array<int, 51>, 51> Map{ 0 };
//    for (int i = 1; i <= m; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            Map[i][j] = Read();
//        }
//    }
//
//    static std::array<std::array<std::array<std::array<int, 51>, 51>, 51>, 51> DP{ 0 };
//    for (int i = 1; i <= m; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            for (int k = 1; k <= m; ++k)
//            {
//                for (int l = 1; l <= n; ++l)
//                {
//                    DP[i][j][k][l] = std::max({ DP[i - 1][j][k - 1][l], 
//                                                DP[i - 1][j][k][l - 1],
//                                                DP[i][j - 1][k - 1][l],
//                                                DP[i][j - 1][k][l - 1] });
//
//                    if (i == k && j == l)
//                    {
//                        DP[i][j][k][l] += Map[i][j];
//                    }
//                    else
//                    {
//                        DP[i][j][k][l] += Map[i][j] + Map[k][l];
//                    }
//                }
//            }
//        }
//    }
//
//    std::cout << DP[m][n][m][n] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    std::array<std::array<int, 10>, 10> Map{ 0 };
//
//    int N;
//    std::cin >> N;
//
//    int i, j, num;
//    std::cin >> i >> j >> num;
//    while (i != 0 && j != 0 && num != 0)
//    {
//        Map[i][j] = num;
//        std::cin >> i >> j >> num;
//    }
//
//    std::array<std::array<std::array<std::array<int, 10>, 10>, 10>, 10> DP{ 0 };
//    for (int i = 1; i <= N; ++i)
//    {
//        for (int j = 1; j <= N; ++j)
//        {
//            for (int k = 1; k <= N; ++k)
//            {
//                for (int l = 1; l <= N; ++l)
//                {
//                    DP[i][j][k][l] = std::max({ DP[i - 1][j][k - 1][l],
//                                                DP[i - 1][j][k][l - 1], 
//                                                DP[i][j - 1][k - 1][l],
//                                                DP[i][j - 1][k][l - 1] });
//
//                    if (i == k && j == l)
//                    {
//                        DP[i][j][k][l] += Map[i][j];
//                    }
//                    else
//                    {
//                        DP[i][j][k][l] += Map[i][j] + Map[k][l];
//                    }
//                }
//            }
//        }
//    }
//
//    std::cout << DP[N][N][N][N] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int Ans = 0;
//int n;
//
//std::array<std::array<int, 20>, 20> P{ 0 }, Q{ 0 };
//std::array<bool, 20> Used{ false };
//std::array<int, 20> Sum{ 0 };
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//void DFS(int x, int tol)
//{
//    if (x == n)
//    {
//        Ans = std::max(Ans, tol);
//    }
//    else
//    {
//        int Temp = tol;
//        for (int i = x; i < n; ++i)
//        {
//            Temp += Sum[i];
//        }
//        if (Temp < Ans)
//        {
//            return;
//        }
//
//        for (int i = 0; i < n; ++i)
//        {
//            if (!Used[i])
//            {
//                Used[i] = true;
//                DFS(x + 1, tol + P[x][i] * Q[i][x]);
//                Used[i] = false;
//            }
//        }
//    }
//}
//
//int main()
//{
//    n = Read();
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            P[i][j] = Read();
//        }
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            Q[i][j] = Read();
//        }
//    }
//
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            Sum[i] = std::max(P[i][j] * Q[j][i], Sum[i]);
//        }
//    }
//
//    DFS(0, 0);
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <array>
//#include <utility>
//
//int main()
//{
//    int n, m;
//    std::cin >> n >> m;
//
//    static std::array<std::pair<std::string, bool>, 100000> Toy;
//    std::string Str;
//    bool Face;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Face >> Str;
//        Toy[i] = std::move(std::pair<std::string, bool>(Str, Face));
//    }
//
//    static std::array<bool, 100000> LR;
//    static std::array<int, 100000> Step;
//    for (int i = 0; i < m; ++i)
//    {
//        std::cin >> LR[i] >> Step[i];
//    }
//
//    int Loc = 0;
//    for (int i = 0; i < m; ++i)
//    {
//        bool Flag = Toy[Loc].second ^ LR[i];
//        if (Flag == true)
//        {
//            Loc = (Loc + Step[i]) % n;
//        }
//        else
//        {
//            Loc = (Loc - Step[i] + n) % n;
//        }
//    }
//
//    std::cout << Toy[Loc].first << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <utility>
//#include <algorithm>
//#include <limits>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    std::vector<std::pair<int, int>> Vec;
//    for (int i = 0; i < n; ++i)
//    {
//        int Count;
//        std::cin >> Count;
//        Vec.push_back({ Count, i });
//    }
//    int Sum = Vec.front().first;
//
//    std::sort(Vec.begin(), Vec.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
//    {
//        return a.first < b.first;
//    });
//
//    for (int i = 0; i < n; ++i)
//    {
//        if (Vec[i].second == 0)
//        {
//            continue;
//        }
//
//        int Temp = 1 << 30;
//        for (int j = i - 1; j >= 0; --j)
//        {
//            if (Vec[j].second < Vec[i].second)
//            {
//                Temp = Vec[i].first - Vec[j].first;
//                break;
//            }
//        }
//        for (int j = i + 1; j < n; ++j)
//        {
//            if (Vec[j].second < Vec[i].second)
//            {
//                Temp = std::min(Temp, Vec[j].first - Vec[i].first);
//                break;
//            }
//        }
//
//        Sum += Temp;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string Str;
//    std::cin >> Str;
//
//    int Boy = 0, Girl = 0;
//    for (std::size_t i = 0; i < Str.size() - 2; ++i)
//    {
//        if (Str[i] == 'b' || Str[i + 1] == 'o' || Str[i + 2] == 'y')
//        {
//            ++Boy;
//        }
//        if (Str[i] == 'g' || Str[i + 1] == 'i' || Str[i + 2] == 'r' || Str[i + 3] == 'l')
//        {
//            ++Girl;
//        }
//    }
//
//    std::cout << Boy << '\n' << Girl << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n, i, j;
//    std::cin >> n >> i >> j;
//
//    static std::array<std::array<int, 10001>, 10001> Map{ 0 };
//    for (int i = 0; i <= n + 1; ++i)
//    {
//        Map[0][i] = 1;
//        Map[n + 1][i] = 1;
//        Map[i][0] = 1;
//        Map[i][n + 1] = 1;
//    }
//
//    int x = 1, y = 0;
//    int turn = 0;
//    for (int now = 1; now <= n * n; ++now)
//    {
//        if (turn % 4 == 0)
//        {
//            if (Map[x][y + 1] == 0)
//            {
//                ++y;
//                Map[x][y] = now;
//            }
//            else
//            {
//                ++turn;
//                --now;
//            }
//        }
//        else if (turn % 4 == 1)
//        {
//            if (Map[x + 1][y] == 0)
//            {
//                ++x;
//                Map[x][y] = now;
//            }
//            else
//            {
//                ++turn;
//                --now;
//            }
//        }
//        else if (turn % 4 == 2)
//        {
//            if (Map[x][y - 1] == 0)
//            {
//                --y;
//                Map[x][y] = now;
//            }
//            else
//            {
//                ++turn;
//                --now;
//            }
//        }
//        else if (turn % 4 == 3)
//        {
//            if (Map[x - 1][y] == 0)
//            {
//                --x;
//                Map[x][y] = now;
//            }
//            else
//            {
//                ++turn;
//                --now;
//            }
//        }
//    }
//
//    std::cout << Map[i][j] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//constexpr int INF = 999999999;
//
//int N;
//
//class Edge
//{
//public:
//    int To, Cap, Rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) :
//        To(to), Cap(cap), Rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, 110> G;
//std::array<int, 110> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].emplace_back(To, Cap, G[To].size());
//    G[To].emplace_back(From, 0, G[From].size() - 1);
//}
//
//void BFS(int s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//
//    std::queue<int> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.Cap > 0 && Level[e.To] < 0)
//            {
//                Level[e.To] = Level[v] + 1;
//                Que.push(e.To);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < static_cast<int>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//
//        if (e.Cap > 0 && Level[v] < Level[e.To])
//        {
//            int d = DFS(e.To, t, std::min(f, e.Cap));
//
//            if (d > 0)
//            {
//                e.Cap -= d;
//                G[e.To][e.Rev].Cap += d;
//
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//
//    while (1)
//    {
//        BFS(s);
//
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//
//        int F;
//        while ((F = DFS(s, t, INF)) > 0)
//        {
//            Flow += F;
//        }
//    }
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//
//int main()
//{
//    int T;
//    std::cin >> T;
//    while (T--)
//    {
//        // 一大波初始化，因为每次进来这个循环的时候都要避免被上次的影响
//        std::fill(Level.begin(), Level.end(), 0);
//        std::fill(Iter.begin(), Iter.end(), 0);
//        for (int i = 0; i < 110; ++i)
//        {
//            G[i].clear();
//        }
//
//        std::cin >> N;
//        int S = N * 2, T = S + 1;
//
//        std::array<bool, 110> SchoolStudent{ false };
//        for (int i = 0; i < N; ++i)
//        {
//            std::cin >> SchoolStudent[i];
//        }
//
//        std::array<bool, 110> Home{ false };
//        for (int i = 0; i < N; ++i)
//        {
//            std::cin >> Home[i];
//
//            if (SchoolStudent[i])
//            {
//                // 将i的床和汇点连起来
//                AddEdge(i + N, T, 1);
//
//                if (!Home[i]) // 如果在校生却不回家，那么它就有一种选择是睡自己的床，于是将他和自己的床连起来
//                {
//                    AddEdge(i, i + N, 1);
//                }
//            }
//        }
//
//        for (int i = 0; i < N; ++i)
//        {
//            // 如果有睡觉的需求（在校生但不回家或者外校学生）
//            if (!SchoolStudent[i] || (SchoolStudent[i] && !Home[i]))
//            {
//                AddEdge(S, i, 1);
//            }
//        }
//
//        int Num = 0;
//        for (int i = 0; i < N; ++i)
//        {
//            if (!SchoolStudent[i] || (SchoolStudent[i] && !Home[i]))
//            {
//                ++Num;
//            }
//        }
//
//        for (int i = 0; i < N; ++i)
//        {
//            for (int j = 0; j < N; ++j)
//            {
//                bool Known;
//                std::cin >> Known;
//                if (Known && SchoolStudent[j]) // 如果i认识j，那么i就可以睡j的床
//                {
//                    AddEdge(i, j + N, 1);
//                }
//            }
//        }
//
//        if (MaxFlow(S, T) < Num) // 如果最大流比要睡觉的人数要小，那么就不行
//        {
//            std::cout << "T_T" << std::endl;
//        }
//        else                      // 否则则可行
//        {
//            std::cout << "^_^" << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    
//    std::array<int, 1001> Arr{ 0 };
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= i / 2; ++j)
//        {
//            Arr[i] += Arr[j];
//        }
//        ++Arr[i];
//    }
//    std::cout << Arr[n] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//ll GCD(ll a, ll b)
//{
//    if (b == 0)
//    {
//        return a;
//    }
//    else
//    {
//        return GCD(b, a % b);
//    }
//}
//
//int main()
//{
//    ll a, b, c;
//    std::cin >> a >> b >> c;
//    
//    ll m = a * b / GCD(a, b);
//    ll n = m * c / GCD(m, c);
//    std::cout << n << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int gcd(int a, int b)
//{
//    if (b == 0)
//    {
//        return a;
//    }
//    else
//    {
//        return gcd(b, a % b);
//    }
//}
//
//int main()
//{
//    int a, b, l;
//    std::cin >> a >> b >> l;
//
//    int ansa = l;
//    int ansb = 1;
//    for (int i = 1; i <= l; ++i)
//    {
//        for (int j = 1; j <= l; ++j)
//        {
//            if (i * b - j * a >= 0 && gcd(i, j) == 1 && (i * ansb - j * ansa) < 0)
//            {
//                ansa = i;
//                ansb = j;
//            }
//        }
//    }
//
//    std::cout << ansa << ' ' << ansb << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//constexpr int INF = 999999999;
//
//int N, M;
//
//std::array<std::array<bool, 100>, 100> Can{ false };
//
//class Edge
//{
//public:
//    int To, Cap, Rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) :
//        To(to), Cap(cap), Rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, 800> G;
//std::array<int, 800> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].emplace_back(To, Cap, G[To].size());
//    G[To].emplace_back(From, 0, G[From].size() - 1);
//}
//
//void BFS(int s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//
//    std::queue<int> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.Cap > 0 && Level[e.To] < 0)
//            {
//                Level[e.To] = Level[v] + 1;
//                Que.push(e.To);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < static_cast<int>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//
//        if (e.Cap > 0 && Level[v] < Level[e.To])
//        {
//            int d = DFS(e.To, t, std::min(f, e.Cap));
//
//            if (d > 0)
//            {
//                e.Cap -= d;
//                G[e.To][e.Rev].Cap += d;
//
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//
//    while (1)
//    {
//        BFS(s);
//
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//
//        int F;
//        while ((F = DFS(s, t, INF)) > 0)
//        {
//            Flow += F;
//        }
//    }
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    std::cin >> M >> N;
//    
//    int From, To;
//    std::cin >> From >> To;
//    while (1)
//    {
//        Can[From][To] = true;
//        std::cin >> From >> To;
//        if (From == -1 && To == -1)
//        {
//            break;
//        }
//    }
//
//    int S = N, T = S + 1;
//    for (int i = 0; i < M; ++i)
//    {
//        AddEdge(S, i, 1);
//    }
//    for (int i = M; i < N; ++i)
//    {
//        AddEdge(i, T, 1);
//    }
//    for (int i = 0; i < M; ++i)
//    {
//        for (int j = M; j < N; ++j)
//        {
//            if (Can[i + 1][j + 1])
//            {
//                AddEdge(i, j, 1);
//            }
//        }
//    }
//
//    int Ans = MaxFlow(S, T);
//    if (Ans == 0)
//    {
//        std::cout << "No Solution!" << std::endl;
//    }
//    else
//    {
//        std::cout << Ans << std::endl;
//        for (int i = 0; i < M; ++i)
//        {
//            for (int j = M; j < N; ++j)
//            {
//                if (Can[i + 1][j + 1])
//                {
//                    for (std::size_t p = 0; p < G[i].size(); ++p)
//                    {
//                        if (G[i][p].To == j && G[i][p].Cap == 0)
//                        {
//                            std::cout << i + 1 << ' ' << j + 1 << std::endl;
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <climits>
//
//using ll = long long;
//
//ll N;
//
//std::array<std::array<bool, 8010>, 8010> Can{ false };
//
//class Edge
//{
//public:
//    ll To, Cap, Rev;
//
//    Edge() = default;
//    Edge(ll to, ll cap, ll rev) :
//        To(to), Cap(cap), Rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, 8010> G;
//std::array<ll, 8010> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(ll From, ll To, ll Cap)
//{
//    G[From].emplace_back(To, Cap, G[To].size());
//    G[To].emplace_back(From, 0, G[From].size() - 1);
//}
//
//void BFS(ll s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//
//    std::queue<ll> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.Cap > 0 && Level[e.To] < 0)
//            {
//                Level[e.To] = Level[v] + 1;
//                Que.push(e.To);
//            }
//        }
//    }
//}
//
//ll DFS(ll v, ll t, ll f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (ll &i = Iter[v]; i < static_cast<ll>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//
//        if (e.Cap > 0 && Level[v] < Level[e.To])
//        {
//            ll d = DFS(e.To, t, std::min(f, e.Cap));
//
//            if (d > 0)
//            {
//                e.Cap -= d;
//                G[e.To][e.Rev].Cap += d;
//
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//ll MaxFlow(ll s, ll t)
//{
//    ll Flow = 0;
//
//    while (1)
//    {
//        BFS(s);
//
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//
//        ll F;
//        while ((F = DFS(s, t, LLONG_MAX)) > 0)
//        {
//            Flow += F;
//        }
//    }
//}
//
//ll Read()
//{
//    ll n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    N = Read();
//    for (ll i = 0; i < N * 2; ++i)
//    {
//        ll To1, To2;
//        To1 = Read();
//        To2 = Read();
//        Can[i][To1] = true;
//        Can[i][To2] = true;
//    }
//
//    ll S = N * 3, T = S + 1;
//    for (ll i = 0; i < N * 2; ++i)
//    {
//        AddEdge(S, i, 1);
//    }
//    for (ll i = 0; i < N; ++i)
//    {
//        AddEdge(N * 2 + i, T, 2);
//    }
//    for (ll i = 0; i < N * 2; ++i)
//    {
//        for (ll j = 0; j < N; ++j)
//        {
//            if (Can[i][j + 1])
//            {
//                AddEdge(i, N * 2 + j, 1);
//            }
//        }
//    }
//
//    std::cout << MaxFlow(S, T) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    std::array<std::array<int, 201>, 201> Map{ 0 };
//    for (int i = 0; i <= n + 1; ++i)
//    {
//        Map[0][i] = 1;
//        Map[n + 1][i] = 1;
//        Map[i][0] = 1;
//        Map[i][n + 1] = 1;
//    }
//
//    int x = 1, y = 0;
//    int turn = 0;
//    for (int now = 1; now <= n * n; ++now)
//    {
//        if (turn % 4 == 0)
//        {
//            if (Map[x][y + 1] == 0)
//            {
//                ++y;
//                Map[x][y] = now;
//            }
//            else
//            {
//                ++turn;
//                --now;
//            }
//        }
//        else if (turn % 4 == 1)
//        {
//            if (Map[x + 1][y] == 0)
//            {
//                ++x;
//                Map[x][y] = now;
//            }
//            else
//            {
//                ++turn;
//                --now;
//            }
//        }
//        else if (turn % 4 == 2)
//        {
//            if (Map[x][y - 1] == 0)
//            {
//                --y;
//                Map[x][y] = now;
//            }
//            else
//            {
//                ++turn;
//                --now;
//            }
//        }
//        else if (turn % 4 == 3)
//        {
//            if (Map[x - 1][y] == 0)
//            {
//                --x;
//                Map[x][y] = now;
//            }
//            else
//            {
//                ++turn;
//                --now;
//            }
//        }
//    }
//
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            std::cout << Map[i][j] << ' ';
//        }
//        putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//constexpr int INF = 999999999;
//
//int N, M, E;
//
//std::array<std::array<bool, 2002>, 2002> Can{ false };
//
//class Edge
//{
//public:
//    int To, Cap, Rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) :
//        To(to), Cap(cap), Rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, 2002> G;
//std::array<int, 2002> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].emplace_back(To, Cap, G[To].size());
//    G[To].emplace_back(From, 0, G[From].size() - 1);
//}
//
//void BFS(int s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//
//    std::queue<int> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.Cap > 0 && Level[e.To] < 0)
//            {
//                Level[e.To] = Level[v] + 1;
//                Que.push(e.To);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < static_cast<int>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//
//        if (e.Cap > 0 && Level[v] < Level[e.To])
//        {
//            int d = DFS(e.To, t, std::min(f, e.Cap));
//
//            if (d > 0)
//            {
//                e.Cap -= d;
//                G[e.To][e.Rev].Cap += d;
//
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//
//    while (1)
//    {
//        BFS(s);
//
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//
//        int F;
//        while ((F = DFS(s, t, INF)) > 0)
//        {
//            Flow += F;
//        }
//    }
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    N = Read();
//    M = Read();
//    E = Read();
//    for (int i = 0; i < E; ++i)
//    {
//        int From, To;
//        From = Read();
//        To = Read();
//        if (To <= M)
//        {
//            Can[From][To] = true;
//        }
//    }
//
//    int S = N + M, T = S + 1;
//    for (int i = 0; i < N; ++i)
//    {
//        AddEdge(S, i, 1);
//    }
//    for (int i = 0; i < M; ++i)
//    {
//        AddEdge(N + i, T, 1);
//    }
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < M; ++j)
//        {
//            if (Can[i + 1][j + 1])
//            {
//                AddEdge(i, N + j, 1);
//            }
//        }
//    }
//
//    std::cout << MaxFlow(S, T) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//constexpr int INF = 999999999;
//
//int N, F, D;
//
//std::array<std::array<bool, 800>, 800> LikeF{ false }, LikeD{ false };
//
//class Edge
//{
//public:
//    int To, Cap, Rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) :
//        To(to), Cap(cap), Rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, 800> G;
//std::array<int, 800> Level{ 0 }, Iter{ 0 };
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].emplace_back(To, Cap, G[To].size());
//    G[To].emplace_back(From, 0, G[From].size() - 1);
//}
//
//void BFS(int s)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//
//    std::queue<int> Que;
//    Level[s] = 0;
//    Que.push(s);
//    while (!Que.empty())
//    {
//        auto v = Que.front();
//        Que.pop();
//
//        for (std::size_t i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.Cap > 0 && Level[e.To] < 0)
//            {
//                Level[e.To] = Level[v] + 1;
//                Que.push(e.To);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < static_cast<int>(G[v].size()); ++i)
//    {
//        auto &e = G[v][i];
//
//        if (e.Cap > 0 && Level[v] < Level[e.To])
//        {
//            int d = DFS(e.To, t, std::min(f, e.Cap));
//
//            if (d > 0)
//            {
//                e.Cap -= d;
//                G[e.To][e.Rev].Cap += d;
//
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//
//    while (1)
//    {
//        BFS(s);
//
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//
//        int F;
//        while ((F = DFS(s, t, INF)) > 0)
//        {
//            Flow += F;
//        }
//    }
//}
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    N = Read();
//    F = Read();
//    D = Read();
//
//    for (int i = 0; i < N; ++i)
//    {
//        int f, d;
//        std::cin >> f >> d;
//
//        for (int j = 0; j < f; ++j)
//        {
//            int Food;
//            std::cin >> Food;
//            LikeF[i][Food] = true;
//        }
//        for (int j = 0; j < d; ++j)
//        {
//            int Drink;
//            std::cin >> Drink;
//            LikeD[i][Drink] = true;
//        }
//    }
//
//    int S = N * 2 + F + D, T = S + 1;
//    for (int i = 0; i < F; ++i)
//    {
//        AddEdge(S, N * 2 + i, 1);
//    }
//    for (int i = 0; i < D; ++i)
//    {
//        AddEdge(N * 2 + F + i, T, 1);
//    }
//    for (int i = 0; i < N; ++i)
//    {
//        AddEdge(i, N + i, 1);
//
//        for (int j = 0; j < F; ++j)
//        {
//            if (LikeF[i][j + 1])
//            {
//                AddEdge(N * 2 + j, i, 1);
//            }
//        }
//        for (int j = 0; j < D; ++j)
//        {
//            if (LikeD[i][j + 1])
//            {
//                AddEdge(N + i, N * 2 + F + j, 1);
//            }
//        }
//    }
//
//    std::cout << MaxFlow(S, T) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n, m;
//    std::array<std::array<char, 101>, 101> Map{ '\0' };
//    std::cin >> n >> m;
//
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= m; ++j)
//        {
//            std::cin >> Map[i][j];
//        }
//    }
//
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= m; ++j)
//        {
//            if (Map[i][j] == '*')
//            {
//                putchar('*');
//            }
//            else
//            {
//                int num = 0;
//                for (int dx = -1; dx <= 1; ++dx)
//                {
//                    for (int dy = -1; dy <= 1; ++dy)
//                    {
//                        if (Map[i + dx][j + dy] == '*')
//                        {
//                            ++num;
//                        }
//                    }
//                }
//
//                std::cout << num;
//            }
//        }
//
//        putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    int r, g;
//    std::cin >> r >> g;
//
//    if (std::abs(r - g) > 1)
//    {
//        std::cout << "NO" << std::endl;
//    }
//    else
//    {
//        std::cout << "YES" << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int a, b;
//    std::cin >> a >> b;
//    std::cout << a + b << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//using ll = long long;
//
//template<typename T>
//T gcd(const T &a, const T &b)
//{
//    if (b == 0)
//    {
//        return a;
//    }
//    else
//    {
//        return gcd(b, a % b);
//    }
//}
//
//int main()
//{
//    ll n;
//    std::cin >> n;
//    while (n--)
//    {
//        ll x1, x2, y1, y2;
//        std::cin >> x1 >> y1 >> x2 >> y2;
//        
//        ll dx = std::abs(x1 - x2), dy = std::abs(y1 - y2);
//        if (dx == 0 && dy >= 1)
//        {
//            std::cout << "yes" << std::endl;
//        }
//        else if (dy == 0 && dx >= 1)
//        {
//            std::cout << "yes" << std::endl;
//        }
//        else if (dx == 0 || dy == 0)
//        {
//            std::cout << "no" << std::endl;
//        }
//        else
//        { 
//            if (gcd(dx, dy) == 1)
//            {
//                std::cout << "no" << std::endl;
//            }
//            else
//            {
//                std::cout << "yes" << std::endl;
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//using ll = long long;
//
//int main()
//{
//    ll Sum = 0;
//
//    ll Temp;
//    ll n = 0;
//    while (std::cin >> Temp)
//    {
//        ++n;
//        Sum += Temp;
//    }
//
//    Sum *= static_cast<ll>(std::pow(2, n - 1));
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//std::size_t Ans = 100000;
//
//void Check(const std::string &Line)
//{
//    if (Line.size() % 2 == 1)
//    {
//        Ans = std::min(Ans, Line.size());
//        return;
//    }
//    else
//    {
//        auto beg = Line.cbegin();
//        auto rbeg = Line.cend() - 1;
//
//        while (1)
//        {
//            if (*beg != *rbeg)
//            {
//                Ans = std::min(Ans, Line.size());
//                return;
//            }
//            else if (rbeg - beg == 1)
//            {
//                break;
//            }
//            else
//            {
//                ++beg;
//                --rbeg;
//            }
//        }
//
//        Check(std::string(Line, Line.size() / 2));
//    }
//}
//
//int main()
//{
//    std::string Str;
//    std::cin >> Str;
//
//    Check(Str);
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <opencv2\opencv.hpp>
//
//int main()
//{
//    auto Image = cv::imread("C:\\Users\\Crablet\\Desktop\\QQ截图20180114204534.png");
//    cv::imshow("Test", Image);
//    cv::waitKey(0);
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//int main()
//{
//    int R, B, C, D, E;
//    std::cin >> R >> B >> C >> D >> E;
//    
//    int Sum = R * C + B * D;
//    for (int i = 0; i <= (R >= B ? B : R); ++i)
//    {
//        Sum = std::max(Sum, i * E + (R - i) * C + i * E + (B - i) * D);
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int a = 10;
//    int &pa = a;
//    std::cout << sizeof(pa) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <queue>
//
//int main()
//{
//    std::priority_queue<int> Clothes;
//    int N, A, B;
//    std::cin >> N >> A >> B;
//
//    for (int i = 0; i < N; ++i)
//    {
//        int t;
//        std::cin >> t;
//        Clothes.push(t);
//    }
//
//    int Time = 0;
//    while (1)
//    {
//        if (Clothes.top() - A * Time <= 0)
//        {
//            break;
//        }
//        else
//        {
//            auto Top = Clothes.top();
//            Clothes.pop();
//            Top -= B;
//            Clothes.push(Top);
//            ++Time;
//        }
//    }
//
//    std::cout << Time << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <utility>
//
//int main()
//{
//    static std::array<std::array<std::pair<bool, int>, 101>, 10001> Room;
//    std::array<int, 10001> Stairs{ 0 };
//    int N, M;
//    std::cin >> N >> M;
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < M; ++j)
//        {
//            bool b;
//            int k;
//            std::cin >> b >> k;
//            Room[i][j].first = b;
//            Room[i][j].second = k;
//
//            if (b == true)
//            {
//                ++Stairs[i];
//            }
//        }
//    }
//
//    int Now;
//    std::cin >> Now;
//
//    int Sum = 0;
//    for (int i = 0; i < N; ++i)
//    {
//        Sum = (Sum + Room[i][Now].second) % 20123;
//
//        int Step = Room[i][Now].second % Stairs[i];
//        if (Step == 0)
//        {
//            Step = Stairs[i];
//        }
//
//        int p = 0;
//        --Now;
//        while (p < Step)
//        {
//            ++Now;
//
//            if (Now == M)
//            {
//                Now = 0;
//            }
//
//            if (Room[i][Now].first == true)
//            {
//                ++p;
//            }
//        }
//    }
//
//    std::cout << Sum % 20123 << std::endl;
//
//    return 0;
//} 
//#include <iostream>
//#include <stack>
//#include <vector>
//#include <string>
//#include <cmath>
//
//std::vector<std::string> Oper;
//
//void f(long long x)
//{
//    std::stack<long long> Sta;
//    if (std::abs(x) > 1000000000)
//    {
//        std::cout << "ERROR" << std::endl;
//        return;
//    }
//    else
//    {
//        Sta.push(x);
//    }
//
//    auto Now = Oper.cbegin();
//    while (1)
//    {
//        if (Now == Oper.cend())
//        {
//            break;
//        }
//        else if (*Now == "NUM")
//        {
//            ++Now;
//            if (std::abs(std::stoll(*Now)) > 1000000000)
//            {
//                std::cout << "ERROR" << std::endl;
//                return;
//            }
//            else
//            {
//                Sta.push(std::stoll(*Now));
//            }
//        }
//        else if (*Now == "POP")
//        {
//            if (!Sta.empty())
//            {
//                Sta.pop();
//            }
//            else
//            {
//                std::cout << "ERROR" << std::endl;
//                return;
//            }
//        }
//        else if (*Now == "INV")
//        {
//            if (!Sta.empty())
//            {
//                auto Temp = Sta.top();
//                Sta.pop();
//                Sta.push(-Temp);
//            }
//            else
//            {
//                std::cout << "ERROR" << std::endl;
//                return;
//            }
//        }
//        else if (*Now == "DUP")
//        {
//            if (!Sta.empty())
//            {
//                Sta.push(Sta.top());
//            }
//            else
//            {
//                std::cout << "ERROR" << std::endl;
//                return;
//            }
//        }
//        else if (*Now == "SWP")
//        {
//            if (Sta.size() >= 2)
//            {
//                auto t1 = Sta.top();
//                Sta.pop();
//                auto t2 = Sta.top();
//                Sta.pop();
//
//                Sta.push(t1);
//                Sta.push(t2);
//            }
//            else
//            {
//                std::cout << "ERROR" << std::endl;
//                return;
//            }
//        }
//        else if (*Now == "ADD")
//        {
//            if (Sta.size() >= 2)
//            {
//                auto t1 = Sta.top();
//                Sta.pop();
//                auto t2 = Sta.top();
//                Sta.pop();
//
//                auto Sum = t1 + t2;
//                if (std::abs(Sum) > 1000000000)
//                {
//                    std::cout << "ERROR" << std::endl;
//                    return;
//                }
//                else
//                {
//                    Sta.push(Sum);
//                }
//            }
//        }
//        else if (*Now == "SUB")
//        {
//            if (Sta.size() >= 2)
//            {
//                auto t1 = Sta.top();
//                Sta.pop();
//                auto t2 = Sta.top();
//                Sta.pop();
//
//                auto Sum = t2 - t1;
//                if (std::abs(Sum) > 1000000000)
//                {
//                    std::cout << "ERROR" << std::endl;
//                    return;
//                }
//                else
//                {
//                    Sta.push(Sum);
//                }
//            }
//        }
//        else if (*Now == "MUL")
//        {
//            if (Sta.size() >= 2)
//            {
//                auto t1 = Sta.top();
//                Sta.pop();
//                auto t2 = Sta.top();
//                Sta.pop();
//
//                auto Sum = t1 * t2;
//                if (std::abs(Sum) > 1000000000)
//                {
//                    std::cout << "ERROR" << std::endl;
//                    return;
//                }
//                else
//                {
//                    Sta.push(Sum);
//                }
//            }
//        }
//        else if (*Now == "DIV")
//        {
//            if (Sta.size() >= 2)
//            {
//                auto t1 = Sta.top();
//                Sta.pop();
//                auto t2 = Sta.top();
//                Sta.pop();
//
//                if (t1 == 0)
//                {
//                    std::cout << "ERROR" << std::endl;
//                    return;
//                }
//
//                auto Sum = t2 / t1;
//                if (std::abs(Sum) > 1000000000)
//                {
//                    std::cout << "ERROR" << std::endl;
//                    return;
//                }
//                else
//                {
//                    Sta.push(Sum);
//                }
//            }
//        }
//        else if (*Now == "MOD")
//        {
//            if (Sta.size() >= 2)
//            {
//                auto t1 = Sta.top();
//                Sta.pop();
//                auto t2 = Sta.top();
//                Sta.pop();
//
//                if (t1 == 0)
//                {
//                    std::cout << "ERROR" << std::endl;
//                    return;
//                }
//
//                auto Sum = t2 % t1;
//                if (std::abs(Sum) > 1000000000)
//                {
//                    std::cout << "ERROR" << std::endl;
//                    return;
//                }
//                else
//                {
//                    Sta.push(Sum);
//                }
//            }
//            else
//            {
//                std::cout << "ERROR" << std::endl;
//                return;
//            }
//        }
//
//        ++Now;
//    }
//
//    if (Sta.size() != 1)
//    {
//        std::cout << "ERROR" << std::endl;
//        return;
//    }
//    else
//    {
//        std::cout << Sta.top() << std::endl;
//    }
//}
//
//int main()
//{
//    std::string Ope;
//    std::cin >> Ope;
//    while (Ope != "END")
//    {
//        Oper.push_back(Ope);
//        std::cin >> Ope;
//    }
//    Oper.push_back(Ope);
//
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        long long num;
//        std::cin >> num;
//        f(num);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//int main()
//{
//    long n, m;
//    std::cin >> n >> m;
//
//    long Sum = 0;
//    for (long i = 1; i <= std::min(n, m); ++i)
//    {
//        Sum += (n - i + 1) * (m - i + 1);
//    }
//
//    std::cout << Sum << ' ' << (1 + n) * n / 2 * (1 + m) * m / 2 - Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//void PreOrder(const std::string &InOrder, const std::string &PostOrder)
//{
//    if (!InOrder.empty())
//    {
//        const auto Root = PostOrder.back();
//        std::cout << Root;
//
//        const auto Pos = InOrder.find(Root);
//        PreOrder(std::string(InOrder, 0, Pos), std::string(PostOrder, 0, Pos));
//        PreOrder(std::string(InOrder, Pos + 1), std::string(PostOrder, Pos, PostOrder.size() - Pos - 1));
//    }
//}
//
//int main()
//{
//    std::string InOrder, PostOrder;
//    std::cin >> InOrder >> PostOrder;
//
//    PreOrder(InOrder, PostOrder);
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    std::array<int, 3001> SumOf{ 0 };
//    int n, m;
//    std::cin >> n >> m;
//
//    for (int i = 1; i <= n; ++i)
//    {
//        int Now;
//        std::cin >> Now;
//        SumOf[i] = SumOf[i - 1] + Now;
//    }
//
//    int Ans = 99999;
//    for (int i = m; i <= n; ++i)
//    {
//        Ans = std::min(Ans, SumOf[i] - SumOf[i - m]);
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <random>
//#include <array>
//#include <climits>
//#include <cmath>
//
//std::array<int, 10000> X{ 0 }, Y{ 0 }, W{ 0 };
//
//int n;
//
//double XAns, YAns, DisAns;
//
//constexpr double TMin = 1e-16;
//constexpr double Delta = 0.993;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//template <typename T>
//double Calc(const T &x, const T &y)
//{
//    double Sum = 0.0;
//    for (int i = 0; i < n; ++i)
//    {
//        Sum += std::sqrt((x - X[i]) * (x - X[i]) + (y - Y[i]) * (y - Y[i])) * W[i];
//    }
//
//    return Sum;
//}
//
//void SA()
//{
//    auto X = XAns;
//    auto Y = YAns;
//    double T = 100;
//
//    while (T > TMin)
//    {
//        auto XTemp = X + (rand() * 2 - RAND_MAX) * T;
//        auto YTemp = Y + (rand() * 2 - RAND_MAX) * T;
//        auto DisTemp = Calc(XTemp, YTemp);
//
//        if (DisTemp < DisAns)
//        {
//            XAns = XTemp;
//            YAns = YTemp;
//            DisAns = DisTemp;
//        }
//        else if (std::exp(-(DisTemp - DisAns) / T) * RAND_MAX > rand())
//        {
//            X = XTemp;
//            Y = YTemp;
//        }
//
//        T *= Delta;
//    }
//}
//
//int main()
//{
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        X[i] = Read();
//        Y[i] = Read();
//        W[i] = Read();
//    }
//
//    XAns = X[0];
//    YAns = Y[0];
//    DisAns = 9999999999999999999999.9;
//
//    for (int i = 0; i < 10; ++i)
//    {
//        SA();
//    }
//
//    std::printf("%.3lf %.3lf\n", XAns, YAns);
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    unsigned long long n;
//    std::cin >> n;
//    std::cout << ((n - 3) * (n - 2) / 2 * (n - 1) / 3 * n / 4) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    static std::array<int, 100000> Red{ 0 }, Green{ 0 }, Dis{ 0 };
//    int N, M;
//    std::cin >> N >> M;
//
//    for (int i = 0; i < N - 1; ++i)
//    {
//        std::cin >> Dis[i];
//    }
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> Red[i];
//    }
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> Green[i];
//    }
//
//    int Sum = M;
//    for (int i = 0; i < N; ++i)
//    {
//        if (i > 0)
//        {
//            Sum += Dis[i - 1];
//        }
//
//        int Temp = Red[i] + Green[i];
//        if (Sum % Temp > Green[i])
//        {
//            Sum += Temp - Sum % Temp;
//        }
//
//        std::cout << Sum << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//constexpr long long fac(int i)
//{
//    return i == 0 ? 1 : i * fac(i - 1);
//}
//
//int main()
//{
//    constexpr long long n = fac(20);
//    std::cout << n << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 100> Arr{ 0 };
//
//int DFS(int i)
//{
//    if (Arr[i] != 0)
//    {
//        return Arr[i];
//    }
//    
//    if (i < 0)
//    {
//        return Arr[i] = 0;
//    }
//    else if (i == 1 || i == 0)
//    {
//        return Arr[i] = 1;
//    }
//    else
//    {
//        return Arr[i] = DFS(i - 1) + DFS(i - 2);
//    }
//}
//
//int main()
//{
//    std::cout << DFS(10) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 14> Row{ 0 };
//std::array<bool, 30> LR{ false }, RL{ false }, Col{ false };
//
//int n, Tol = 0;
//
//void Print()
//{
//    if (Tol <= 3)
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            std::cout << Row[i] << ' ';
//        }
//        putchar('\n');
//    }
//}
//
//void DFS(int Now)
//{
//    if (Now == n + 1)
//    {
//        ++Tol;
//        Print();
//
//        return;
//    }
//    else
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            if (!Col[i] && !LR[i + Now] && !RL[i - Now + n])
//            {
//                Row[Now] = i;
//                LR[i + Now] = true;
//                RL[i - Now + n] = true;
//                Col[i] = true;
//
//                DFS(Now + 1);
//
//                LR[i + Now] = false;
//                RL[i - Now + n] = false;
//                Col[i] = false;
//            }
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> n;
//
//    DFS(1);
//
//    std::cout << Tol << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    char c[10] = "ABCD";
//
//    std::cout << c << std::endl;
//
//    c[4] = 'P';
//
//    std::cout << c << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    std::array<int, 50> RX{ 0 }, RY{ 0 }, R{ 0 };
//    int X1, X2, Y1, Y2;
//
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> RX[i];
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> RY[i];
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> R[i];
//    }
//    std::cin >> X1 >> Y1 >> X2 >> Y2;
//
//    int Sum = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        if ((((X1 - RX[i]) * (X1 - RX[i]) + (Y1 - RY[i]) * (Y1 - RY[i])) <= R[i] * R[i])
//          ^ (((X2 - RX[i]) * (X2 - RX[i]) + (Y2 - RY[i]) * (Y2 - RY[i])) <= R[i] * R[i]))
//        {
//            ++Sum;
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    if (n < 9)
//    {
//        std::cout << 0 << std::endl;
//    }
//    else if (n == 9)
//    {
//        std::cout << 9 << std::endl;
//    }
//    else
//    {
//        std::cout << 72;
//        for (int i = 0; i < n - 10; ++i)
//        {
//            putchar('0');
//        }
//        putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    long long Sum;
//
//    Sum = 0;
//    for (long long i = 100000000; i <= 999999999; ++i)
//    {
//        if (((i * i) % 1000000000) == 987654321)
//        {
//            ++Sum;
//        }
//    }
//    std::cout << Sum << std::endl;
//
//    Sum = 0;
//    for (long long i = 1000000000; i <= 10000000000 - 1; ++i)
//    {
//        if (((i * i) % 1000000000) == 987654321)
//        {
//            ++Sum;
//        }
//    }
//    std::cout << Sum << std::endl;
//
//    Sum = 0;
//    for (long long i = 10000000000; i <= 100000000000 - 1; ++i)
//    {
//        if (((i * i) % 1000000000) == 987654321)
//        {
//            ++Sum;
//        }
//    }
//    std::cout << Sum << std::endl;
//
//    Sum = 0;
//    for (long long i = 100000000000; i <= 1000000000000 - 1; ++i)
//    {
//        if (((i * i) % 1000000000) == 987654321)
//        {
//            ++Sum;
//        }
//    }
//    std::cout << Sum << std::endl;
//
//    Sum = 0;
//    for (long long i = 1000000000000; i <= 10000000000000 - 1; ++i)
//    {
//        if (((i * i) % 1000000000) == 987654321)
//        {
//            ++Sum;
//        }
//    }
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//int Arr[1000000];
//
//int main()
//{
//    int n, m;
//    std::cin >> n >> m;
//
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//
//    std::sort(std::begin(Arr), std::begin(Arr) + n);
//
//    for (int i = 0; i < m; ++i)
//    {
//        std::cout << Arr[i] << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int f(int m)
//{
//    static int i = 0;
//    int s = 0;
//    for (; i <= m; ++i)
//    {
//        s += i;
//    }
//
//    return s;
//}
//
//int main()
//{
//    int Sum = f(5);
//    Sum += f(3);
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    int x, y;
//    std::cin >> x >> y;
//    int tx, ty;
//    std::cin >> tx >> ty;
//
//    int Sum = std::abs(x - tx) + std::abs(y - ty);
//
//    int t;
//    std::cin >> t;
//    int n = x, s = x, w = y, e = y;
//    while (t--)
//    {
//        char c;
//        std::cin >> c;
//
//        switch (c)
//        {
//        case 'N':
//            ++n;
//            break;
//
//        case 'S':
//            --s;
//            break;
//
//        case 'W':
//            --w;
//            break;
//
//        case 'E':
//            ++e;
//            break;
//
//        default:
//            break;
//        }
//    }
//
//    if (w <= tx && e >= tx && s <= ty && n >= ty)
//    {
//        std::cout << Sum << std::endl;
//    }
//    else
//    {
//        std::cout << -1 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    static std::array<std::array<int, 1000>, 1000> Map{ 0 };
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            std::cin >> Map[i][j];
//        }
//    }
//
//    int Ans = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            int Temp = 0;
//            if (Map[i][j] == 0)
//            {
//                for (int p = 0; p < n; ++p)
//                {
//                    Temp += Map[i][p] + Map[p][j];
//                }
//            }
//
//            Ans = std::max(Ans, Temp);
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int s, x;
//    std::cin >> s >> x;
//
//    double Sum = 0.0, Step = 7.0;
//    while (Sum < s - x)
//    {
//        Sum += Step;
//        Step *= 0.98;
//    }
//
//    if (Step > s + x - Sum)
//    {
//        std::cout << 'n' << std::endl;
//    }
//    else
//    {
//        std::cout << 'y' << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    int s, x;
//    std::cin >> s >> x;
//
//    int n = 1;
//    while ((350 - 350 * std::pow(0.98, n) < (s - x)))
//    {
//        ++n;
//    }
//
//    if (std::pow(0.98, n) * 7 >= (s + x - (350 - 350 * std::pow(0.98, n))))
//    {
//        std::cout << 'n' << std::endl;
//    }
//    else
//    {
//        std::cout << 'y' << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//
//int main()
//{
//    std::unordered_map<int, int> Map;
//    Map[1] = 1;
//
//    auto beg = Map.cbegin();
//    std::cout << beg->first << ' ' << beg->second << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int N;
//
//std::array<bool, 100> Used{ false };
//std::array<int, 100> Arr{ 0 };
//
//void DFS(int Now)
//{
//    if (Now == N)
//    {
//        for (int i = 0; i < N; ++i)
//        {
//            std::cout << Arr[i] << ' ';
//        }
//        putchar('\n');
//
//        return;
//    }
//    else
//    {
//        for (int i = 1; i <= N; ++i)
//        {
//            if (!Used[i])
//            {
//                Arr[Now] = i;
//
//                Used[i] = true;
//                DFS(Now + 1);
//                Used[i] = false;
//            }
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> N;
//
//    DFS(0);
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//int main()
//{
//    int N;
//    std::cin >> N;
//
//    std::vector<int> Vec;
//    for (int i = 0; i < N; ++i)
//    {
//        int t;
//        std::cin >> t;
//        Vec.push_back(t);
//    }
//
//    if (std::prev_permutation(Vec.begin(), Vec.end()))
//    {
//        for (const auto &r : Vec)
//        {
//            std::cout << r << ' ';
//        }
//        putchar('\n');
//    }
//    else
//    {
//        std::cout << "ERROR" << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//int main()
//{
//    int N;
//    std::cin >> N;
//
//    std::vector<int> Vec;
//    for (int i = 1; i <= N; ++i)
//    {
//        Vec.push_back(i);
//    }
//
//    int Num;
//    std::cin >> Num;
//
//    int Ans = 0;
//    do
//    {
//        ++Ans;
//
//        int Sum = 0;
//        for (const auto &r : Vec)
//        {
//            Sum = Sum * 10 + r;
//        }
//
//        if (Sum == Num)
//        {
//            std::cout << Ans << std::endl;
//            break;
//        }
//    } while (std::next_permutation(Vec.begin(), Vec.end()));
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    std::array<int, 100001> H{ 0 };
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> H[i];
//    }
//
//    int Sum = 0;
//    for (int i = 1; i < n - 1; ++i)
//    {
//        if (H[i] <= H[i - 1] && H[i] < H[i + 1])
//        {
//            ++Sum;
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int Sum = 0;
//    int Temp;
//    while (std::cin >> Temp)
//    {
//        Sum += Temp;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <iomanip>
//
//std::array<int, 10> Arr{ 0 };
//std::array<bool, 10> Used{ false };
//int n;
//
//void DFS(int Now)
//{
//    if (Now == n + 1)
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            std::cout << std::setw(5) << Arr[i];
//        }
//        std::cout << std::endl;
//    }
//    else
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            if (!Used[i])
//            {
//                Arr[Now] = i;
//                Used[i] = true;
//                DFS(Now + 1);
//                Used[i] = false;
//            }
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> n;
//
//    DFS(1);
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int Max, Ans = 0;
//
//std::array<std::array<int, 9000>, 9000> Arr{ 0 };
//std::array<int, 11> t{ 0 };
//
//void DFS(int Now, int Sum)
//{
//    if (Now == 10)
//    {
//        if (Sum == Max)
//        {
//            for (int i = 0; i < 10; ++i)
//            {
//                Arr[Ans][i] = t[i];
//            }
//
//            ++Ans;
//        }
//
//        return;
//    }
//
//    for (int i = 1; i <= 3; ++i)
//    {
//        if (Sum + i <= Max)
//        {
//            t[Now] = i;
//            DFS(Now + 1, Sum + i);
//            t[Now] = 1;
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> Max;
//
//    DFS(0, 0);
//
//    std::cout << Ans << std::endl;
//    for (int i = 0; i < Ans; ++i)
//    {
//        for (int j = 0; j < 10; ++j)
//        {
//            std::cout << Arr[i][j] << ' ';
//        }
//        putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//
//int main()
//{
//    std::vector<int> vec{ 1, 2, 3, 4, 5 };
//    for (decltype(vec.size()) i = 0; i < vec.size(); ++i)
//    {
//        std::cout << vec[i];
//    }
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    std::cout << "薛岚韵帅气又机智" << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <queue>
//#include <array>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//constexpr int INF = INT_MAX;
//
//int N, M, S, T;
//
//class Edge
//{
//public:
//    int To, Cap, Rev;
//
//    Edge() = default;
//    Edge(int to, int cap, int rev) : To(to), Cap(cap), Rev(rev)
//    {
//    }
//};
//
//std::array<std::vector<Edge>, 10001> G;
//std::array<int, 10001> Level, Iter;
//
//void AddEdge(int From, int To, int Cap)
//{
//    G[From].emplace_back(To, Cap, G[To].size());
//    G[To].emplace_back(From, 0, G[From].size() - 1);
//}
//
//void BFS(int S)
//{
//    std::fill(Level.begin(), Level.end(), -1);
//    Level[S] = 0;
//
//    std::queue<int> Que;
//    Que.push(S);
//
//    while (!Que.empty())
//    {
//        const auto v = Que.front();
//        Que.pop();
//
//        for (int i = 0; i < G[v].size(); ++i)
//        {
//            auto &e = G[v][i];
//            if (e.Cap > 0 && Level[e.To] < 0)
//            {
//                Level[e.To] = Level[v] + 1;
//                Que.push(e.To);
//            }
//        }
//    }
//}
//
//int DFS(int v, int t, int f)
//{
//    if (v == t)
//    {
//        return f;
//    }
//
//    for (int &i = Iter[v]; i < G[v].size(); ++i)
//    {
//        auto &e = G[v][i];
//        if (e.Cap > 0 && Level[v] < Level[e.To])
//        {
//            int d = DFS(e.To, t, std::min(f, e.Cap));
//            if (d > 0)
//            {
//                e.Cap -= d;
//                G[e.To][e.Rev].Cap += d;
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int MaxFlow(int s, int t)
//{
//    int Flow = 0;
//    while (1)
//    {
//        BFS(s);
//        if (Level[t] < 0)
//        {
//            return Flow;
//        }
//
//        std::fill(Iter.begin(), Iter.end(), 0);
//        int f;
//        while ((f = DFS(s, t, INF)) > 0)
//        {
//            Flow += f;
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> N >> M >> S >> T;
//
//    for (int i = 0; i < M; ++i)
//    {
//        int u, v, w;
//        std::cin >> u >> v >> w;
//        AddEdge(u, v, w);
//    }
//
//    std::cout << MaxFlow(S, T) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <utility>
//
//using ll = long long;
//using vec = std::vector<ll>;
//using mat = std::vector<vec>;
//
//constexpr int mod = 1000000007;
//
//mat operator*(const mat &A, const mat &B)
//{
//    mat C(A.size(), vec(B[0].size()));
//    for (int i = 0; i < A.size(); ++i)
//    {
//        for (int k = 0; k < B.size(); ++k)
//        {
//            for (int j = 0; j < B[0].size(); ++j)
//            {
//                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
//            }
//        }
//    }
//
//    return C;
//}
//
//mat operator^(mat &A, ll n)
//{
//    mat B(A.size(), vec(A.size()));
//    for (int i = 0; i < A.size(); ++i)
//    {
//        B[i][i] = 1;
//    }
//
//    while (n > 0)
//    {
//        if (n & 1)
//        {
//            B = B * A;
//        }
//
//        A = A * A;
//        n >>= 1;
//    }
//
//    return B;
//}
//
//int main()
//{
//    int t;
//    std::cin >> t;
//
//    while (t--)
//    {
//        mat A(3, vec(3));
//        A[0][0] = 1; A[0][1] = 0; A[0][2] = 1;
//        A[1][0] = 1; A[1][1] = 0; A[1][2] = 0;
//        A[2][0] = 0; A[2][1] = 1; A[2][2] = 0;
//
//        ll n;
//        std::cin >> n;
//        if (n <= 3)
//        {
//            std::cout << 1 << std::endl;
//        }
//        else
//        {
//            A = std::move(A ^ (n - 3));
//            std::cout << (A[0][0] + A[0][1] + A[0][2]) % 1000000007 << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//
//using ll = long long;
//using vec = std::vector<ll>;
//using mat = std::vector<vec>;
//
//constexpr int mod = 1e9 + 7;
//
//mat operator*(const mat &A, const mat &B)
//{
//    mat C(A.size(), vec(B[0].size()));
//    for (ll i = 0; i < A.size(); ++i)
//    {
//        for (ll k = 0; k < B.size(); ++k)
//        {
//            for (ll j = 0; j < B[0].size(); ++j)
//            {
//                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
//            }
//        }
//    }
//
//    return C;
//}
//
//mat operator^(mat A, ll n)
//{
//    mat B(A.size(), vec(A.size()));
//    for (ll i = 0; i < A.size(); ++i)
//    {
//        B[i][i] = 1;
//    }
//
//    while (n > 0)
//    {
//        if (n & 1)
//        {
//            B = B * A;
//        }
//
//        A = A * A;
//        n >>= 1;
//    }
//
//    return B;
//}
//
//int main()
//{
//    ll n, k;
//    std::cin >> n >> k;
//
//    mat A(n, vec(n));
//    for (ll i = 0; i < n; ++i)
//    {
//        for (ll j = 0; j < n; ++j)
//        {
//            std::cin >> A[i][j];
//        }
//    }
//
//    A = A ^ k;
//
//    for (ll i = 0; i < n; ++i)
//    {
//        for (ll j = 0; j < n; ++j)
//        {
//            std::cout << A[i][j] << ' ';
//        }
//
//        putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//template <typename T>
//ll GCD(const T &a, const T &b)
//{
//    if (b == 0)
//    {
//        return a;
//    }
//    else
//    {
//        return GCD(b, a % b);
//    }
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    while (n--)
//    {
//        std::array<ll, 10000> Arr{ 0 };
//        
//        int t;
//        std::cin >> t;
//        for (int i = 0; i < t; ++i)
//        {
//            std::cin >> Arr[i];
//        }
//
//        Arr[1] /= GCD(Arr[0], Arr[1]);
//        for (int i = 2; i < t; ++i)
//        {
//            Arr[1] /= GCD(Arr[i], Arr[1]);
//        }
//
//        if (Arr[1] == 1)
//        {
//            std::cout << "Yes" << std::endl;
//        }
//        else
//        {
//            std::cout << "No" << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int a, b;
//    std::cin >> a >> b;
//    std::cout << a / b << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using vec = std::vector<int>;
//using mat = std::vector<vec>;
//
//constexpr int mod = 1 << 31;
//
//mat operator*(const mat &A, const mat &B)
//{
//    mat C(A.size(), vec(B[0].size()));
//
//    for (int i = 0; i < A.size(); ++i)
//    {
//        for (int k = 0; k < B.size(); ++k)
//        {
//            for (int j = 0; j < B[0].size(); ++j)
//            {
//                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
//            }
//        }
//    }
//
//    return C;
//}
//
//mat operator^(mat A, int n)
//{
//    mat B(A.size(), vec(A.size()));
//    for (int i = 0; i < A.size(); ++i)
//    {
//        B[i][i] = 1;
//    }
//
//    while (n > 0)
//    {
//        if (n & 1)
//        {
//            B = B * A;
//        }
//
//        A = A * A;
//        n >>= 1;
//    }
//
//    return B;
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    mat A(2, vec(2));
//    A[0][0] = 1; A[0][1] = 1;
//    A[1][0] = 1; A[1][1] = 0;
//    A = A ^ n;
//
//    std::cout << A[1][0] << '=';
//    if (A[1][0] <= 3)
//    {
//        std::cout << A[1][0] << std::endl;
//    }
//    else
//    {
//        int Temp = A[1][0];
//        for (int i = 2; i <= Temp; ++i)
//        {
//            while (A[1][0] % i == 0)
//            {
//                std::cout << i;
//                A[1][0] /= i;
//
//                if (A[1][0] > 1)
//                {
//                    putchar('*');
//                }
//            }
//
//            if (i > A[1][0])
//            {
//                break;
//            }
//        }
//    }
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//#include <array>
//
//int main()
//{
//    int S;
//    std::cin >> S;
//
//    std::array<int, 1001> V{ 1 };
//    for (int i = 1; i <= 1000; ++i)
//    {
//        for (int j = 1; j <= std::sqrt(i); ++j)
//        {
//            if (i % j == 0)
//            {
//                V[i] += j;
//
//                if (j * j != i)
//                {
//                    V[i] += i / j;
//                }
//            }
//        }
//
//        V[i] -= i;
//    }
//
//    std::array<int, 1001> DP{ 0 };
//    for (int i = 1; i <= S; ++i)
//    {
//        for (int j = S; j >= i; --j)
//        {
//            DP[j] = std::max(DP[j], DP[j - i] + V[i]);
//        }
//    }
//
//    std::cout << DP[S] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    int N, M, K, R;
//    std::cin >> N >> M >> K >> R;
//
//    std::array<int, 151> Pro{ 0 };
//    for (int i = 1; i <= N; ++i)
//    {
//        std::cin >> Pro[i];
//    }
//
//    std::array<int, 151> W{ 0 }, V{ 0 }, DP{ 0 };
//    for (int i = 1; i <= M; ++i)
//    {
//        std::cin >> W[i];
//    }
//    for (int i = 1; i <= M; ++i)
//    {
//        std::cin >> V[i];
//    }
//
//    for (int i = 1; i <= M; ++i)
//    {
//        for (int j = R; j >= W[i]; --j)
//        {
//            DP[j] = std::max(DP[j], DP[j - W[i]] + V[i]);
//        }
//    }
//
//    int t;
//    for (int i = 1; i <= R; ++i)
//    {
//        if (DP[i] >= K)
//        {
//            t = i;
//            break;
//        }
//    }
//
//    std::sort(Pro.begin() + 1, Pro.begin() + N + 1);
//    int Left = R - t, Sum = 0;
//    for (int i = 1; i <= N; ++i)
//    {
//        Left -= Pro[i];
//        if (Left >= 0)
//        {
//            ++Sum;
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int N, M;
//    std::cin >> N >> M;
//
//    std::array<int, 10001> DP{ 0 }, A{ 0 };
//    for (int i = 1; i <= N; ++i)
//    {
//        std::cin >> A[i];
//    }
//
//    DP[0] = 1;
//    for (int i = 1; i <= N; ++i)
//    {
//        for (int j = M; j >= A[i]; --j)
//        {
//            DP[j] = DP[j] + DP[j - A[i]];
//        }
//    }
//
//    std::cout << DP[M] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    int Ans = 0;
//    while (n--)
//    {
//        int Now;
//        std::cin >> Now;
//        Ans ^= Now;
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cmath>
//
//int main()
//{
//    std::array<char, 40001> Arr;
//    char ch;
//    int i = 0;
//    while (std::cin >> ch)
//    {
//        if (ch != '\n')
//        {
//            Arr[i++] = ch;
//        }
//    }
//
//    std::cout << static_cast<int>(std::sqrt(i + 1)) << ' ';
//
//    if (Arr[0] == '1')
//    {
//        std::cout << "0 ";
//    }
//
//    int Sum = 1;
//    for (int j = 0; j < i - 1; ++j)
//    {
//        if (Arr[j] == Arr[j + 1])
//        {
//            ++Sum;
//        }
//        else
//        {
//            std::cout << Sum << ' ';
//            Sum = 1;
//        }
//    }
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int N, Ans = 0;
//
//void DFS(int j, int Sum)
//{
//    if (j > 4)
//    {
//        if (Sum == N)
//        {
//            ++Ans;
//        }
//
//        return;
//    }
//
//    for (int i = 0; i <= std::sqrt(N); ++i)
//    {
//        Sum += i * i;
//        DFS(j + 1, Sum);
//        Sum -= i * i;
//    }
//}
//
//int main()
//{
//    std::cin >> N;
//    DFS(1, 0); 
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    int a, b;
//    std::cin >> n;
//
//    int Sum = 0, Now = 0;
//    while (n--)
//    {
//        std::cin >> a >> b;
//        Now += a + b - 8;
//        Sum += Now;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int N, M;
//    std::cin >> N >> M;
//
//    static std::array<int, 100001> Arr{ 0 };
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//
//    int Ans = 0, Sum = 0, p = 0;
//    while (p < N)
//    {
//        if (Sum + Arr[p] <= M)
//        {
//            Sum += Arr[p];
//            ++p;
//        }
//        else
//        {
//            ++Ans;
//            Sum = 0;
//        }
//    }
//
//    std::cout << Ans + 1 << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//std::array<std::array<int, 101>, 101> Map{ 0 }, Max{ 0 };
//std::array<int, 8> dx{ 0, -1, 0, 1 }, dy{ -1, 0, 1, 0 };
//
//int R, C;
//
//int DFS(int i, int j)
//{
//    if (Max[i][j] != 0)
//    {
//        return Max[i][j];
//    }
//
//    int Sum = 1;
//    for (int t = 0; t < 4; ++t)
//    {
//        auto x = i + dx[t];
//        auto y = j + dy[t];
//
//        if (x >= 0 && x < R && y >= 0 && y < C && Map[x][y] > Map[i][j])
//        {
//            Sum = std::max(Sum, DFS(x, y) + 1);
//        }
//    }
//
//    return Max[i][j] = Sum;
//}
//
//int main()
//{
//    std::cin >> R >> C;
//    for (int i = 0; i < R; ++i)
//    {
//        for (int j = 0; j < C; ++j)
//        {
//            std::cin >> Map[i][j];
//        }
//    }
//
//    int Max = 1;
//    for (int i = 0; i < R; ++i)
//    {
//        for (int j = 0; j < C; ++j)
//        {
//            Max = std::max(DFS(i, j), Max);
//        }
//    }
//
//    std::cout << Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int a, b;
//    std::cin >> a >> b;
//
//    int c = a / b;
//    int d = a % b;
//    for (int i = d; i < b; ++i)
//    {
//        std::cout << c << ' ';
//    }
//    for (int i = 0; i < d; ++i)
//    {
//        std::cout << c + 1 << ' ';
//    }
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 40001> Arr, Temp;
//
//int Sum = 0;
//
//template <typename T>
//void Merge(T &Arr, int Begin, int Middle, int End, T &Temp)
//{
//    int pb = 0;
//    int p1 = Begin, p2 = Middle + 1;
//
//    while (p1 <= Middle && p2 <= End)
//    {
//        if (Arr[p1] < Arr[p2])
//        {
//            Temp[pb++] = Arr[p1++];
//        }
//        else
//        {
//            Temp[pb++] = Arr[p2++];
//            Sum += Middle - p1 + 1;
//        }
//    }
//
//    while (p1 <= Middle)
//    {
//        Temp[pb++] = Arr[p1++];
//    }
//    while (p2 <= End)
//    {
//        Temp[pb++] = Arr[p2++];
//    }
//
//    for (int i = 0; i < End - Begin + 1; ++i)
//    {
//        Arr[Begin + i] = Temp[i];
//    }
//}
//
//template <typename T>
//void MergeSort(T &Arr, int Begin, int End, T &Temp)
//{
//    if (Begin < End)
//    {
//        int Middle = (Begin + End) / 2;
//        MergeSort(Arr, Begin, Middle, Temp);
//        MergeSort(Arr, Middle + 1, End, Temp);
//        Merge(Arr, Begin, Middle, End, Temp);
//    }
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//
//    MergeSort(Arr, 0, n - 1, Temp);
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//int dx[9] = { 0, -1, -1, -1, 0, 0, 1, 1, 1 },
//    dy[9] = { 0, -1, 0, 1, -1, 1, 0, 1, -1 };
//
//int Visit[8][8] = { 0 }, Map[8][8] = { 0 };
//
//int n, m;
//int Ans;
//
//template <typename T>
//void DFS(T x, T y, const T &Sum)
//{
//    if (x > n)
//    {
//        Ans = std::max(Ans, Sum);
//        return;
//    }
//
//    if (y > m)
//    {
//        ++x;
//        y = 1;
//    }
//
//    if (Visit[x][y] == 0)
//    {
//        for (int t = 0; t < 9; ++t)
//        {
//            ++Visit[x + dx[t]][y + dy[t]];
//        }
//
//        DFS(x, y + 2, Sum + Map[x][y]);
//
//        for (int t = 0; t < 9; ++t)
//        {
//            --Visit[x + dx[t]][y + dy[t]];
//        }
//    }
//
//    DFS(x, y + 1, Sum);
//}
//
//int main()
//{
//    int t;
//    std::cin >> t;
//    while (t--)
//    {
//        std::cin >> n >> m;
//        for (int i = 1; i <= n; ++i)
//        {
//            for (int j = 1; j <= m; ++j)
//            {
//                std::cin >> Map[i][j];
//                Visit[i][j] = 0;
//            }
//        }
//
//        Ans = 0;
//        DFS(1, 1, 0);
//        std::cout << Ans << std::endl;
//
//        for (auto &rr : Map)
//        {
//            for (auto &r : rr)
//            {
//                r = 0;
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//struct Node
//{
//    int S, A;
//};
//
//std::array<Node, 100001> Arr;
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Arr[i].S;
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Arr[i].A;
//    }
//
//    std::sort(Arr.begin(), Arr.begin() + n, [](const Node &a, const Node &b)
//    {
//        return a.A > b.A;
//    });
//
//    int t, MaxI;
//    int Sum = 0, Max = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        if (Arr[i].S * 2 + Arr[i].A > Max)
//        {
//            Max = Arr[i].S * 2 + Arr[i].A;
//            t = i;
//            MaxI = i;
//        }
//    }
//
//    Sum += Max;
//    std::cout << Sum << std::endl;
//
//    for (int i = 0; i < n; ++i)
//    {
//        if (i != t)
//        {
//            if (Arr[i].S > Arr[MaxI].S)
//            {
//                Sum -= Arr[MaxI].S * 2 + Arr[MaxI].A;
//                Sum += Arr[i].A;
//                MaxI = i;
//            }
//            else
//            {
//                Sum += Arr[i].A;
//            }
//
//            std::cout << Sum << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//std::array<ll, 500001> Arr, Temp;
//
//ll Sum = 0;
//
//template <typename T>
//void Merge(T &Arr, ll Begin, ll Middle, ll End, T &Temp)
//{
//    ll pb = 0;
//    ll p1 = Begin, p2 = Middle + 1;
//
//    while (p1 <= Middle && p2 <= End)
//    {
//        if (Arr[p1] <= Arr[p2])
//        {
//            Temp[pb++] = Arr[p1++];
//        }
//        else
//        {
//            Temp[pb++] = Arr[p2++];
//            Sum += Middle - p1 + 1;
//        }
//    }
//
//    while (p1 <= Middle)
//    {
//        Temp[pb++] = Arr[p1++];
//    }
//    while (p2 <= End)
//    {
//        Temp[pb++] = Arr[p2++];
//    }
//
//    for (ll i = 0; i < End - Begin + 1; ++i)
//    {
//        Arr[Begin + i] = Temp[i];
//    }
//}
//
//template <typename T>
//void MergeSort(T &Arr, ll Begin, ll End, T &Temp)
//{
//    if (Begin < End)
//    {
//        ll Middle = (Begin + End) / 2;
//        MergeSort(Arr, Begin, Middle, Temp);
//        MergeSort(Arr, Middle + 1, End, Temp);
//        Merge(Arr, Begin, Middle, End, Temp);
//    }
//}
//
//int main()
//{
//    ll n;
//    std::cin >> n;
//
//    for (ll i = 0; i < n; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//
//    MergeSort(Arr, 0, n - 1, Temp);
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int Map[751][751] = { 0 }, Square[751][751] = { 0 };
//
//constexpr int Mod = 1000000007;
//
//int DFS(int x, int y)
//{
//    if (Map[x][y] != 0)
//    {
//        return Map[x][y];
//    }
//
//    int Ans = 0;
//    for (int x1 = 1; x1 < x; ++x1)
//    {
//        for (int y1 = 1; y1 < y; ++y1)
//        {
//            if (Square[x][y] != Square[x1][y1])
//            {
//                Ans = (Ans + DFS(x1, y1)) % Mod;
//            }
//        }
//    }
//
//    return Map[x][y] = Ans;
//}
//
//int main()
//{
//    int R, C, K;
//    std::cin >> R >> C >> K;
//
//    for (int i = 1; i <= R; ++i)
//    {
//        for (int j = 1; j <= C; ++j)
//        {
//            std::cin >> Square[i][j];
//        }
//    }
//
//    Map[1][1] = 1;
//
//    std::cout << DFS(R, C) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <climits>
//
//int main()
//{
//    int n, k;
//    std::cin >> n >> k;
//
//    static std::array<int, 100001> Ans{ 0 };
//    std::array<int, 1001> a{ 0 }, b{ 0 };
//    for (int i = 1; i <= n; ++i)
//    {
//        std::cin >> a[i];
//    }
//
//    Ans[0] = 1;
//    int Now = 0;
//    while (Now < k)
//    {
//        int Min = INT_MAX, MinX = 0;
//        for (int i = 1; i <= n; ++i)
//        {
//            if (Ans[b[i]] * a[i] < Min)
//            {
//                Min = Ans[b[i]] * a[i];
//                MinX = i;
//            }
//        }
//
//        ++b[MinX];
//
//        if (Min != Ans[Now])
//        {
//            Ans[++Now] = Min;
//        }
//    }
//
//    std::cout << Ans[k] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<bool, 101> Visit{ false };
//    int n, m;
//    std::cin >> n >> m;
//
//    int t = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j)
//        {
//            ++t;
//            if (t > n)
//            {
//                t = 1;
//            }
//            if (Visit[t])
//            {
//                --j;
//            }
//        }
//        Visit[t] = true;
//
//        std::cout << t << ' ';
//    }
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//struct P
//{
//    int x, y;
//};
//
//int main()
//{
//    int m, n, x, y;
//    std::cin >> x >> y >> m >> n;
//
//    std::array<int, 2000> x1{ 0 }, x2{ 0 }, y1{ 0 }, y2{ 0 };
//    for (int i = 0; i < m; ++i)
//    {
//        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
//    }
//
//    std::array<P, 2000> Des;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Des[i].x >> Des[i].y;
//    }
//
//    std::array<int, 2000> Last{ 0 }, Turn{ 0 };
//    for (int j = 0; j < n; ++j)
//    {
//        for (int i = 0; i < m; ++i)
//        {
//            if (x1[i] <= Des[j].x && Des[j].x <= x2[i] &&
//                y1[i] <= Des[j].y && Des[j].y <= y2[i])
//            {
//                ++Turn[j];
//                Last[j] = i + 1;
//            }
//        }
//    }
//
//    for (int j = 0; j < n; ++j)
//    {
//        if (Last[j] == 0)
//        {
//            std::cout << "N" << std::endl;
//        }
//        else
//        {
//            std::cout << "Y " << Turn[j] << ' ' << Last[j] << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//struct P
//{
//    int x, y;
//};
//
//int main()
//{
//    int m, n;
//    std::cin >> m >> n;
//
//    std::array<int, 2000> x1{ 0 }, x2{ 0 }, y1{ 0 }, y2{ 0 };
//    for (int i = 0; i < m; ++i)
//    {
//        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
//    }
//
//    std::array<P, 2000> Des;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Des[i].x >> Des[i].y;
//    }
//
//    std::array<int, 2000> Last{ 0 }, Turn{ 0 };
//    for (int j = 0; j < n; ++j)
//    {
//        for (int i = 0; i < m; ++i)
//        {
//            if (x1[i] <= Des[j].x && Des[j].x <= x2[i] &&
//                y1[i] <= Des[j].y && Des[j].y <= y2[i])
//            {
//                ++Turn[j];
//                Last[j] = i + 1;
//            }
//        }
//    }
//
//    for (int j = 0; j < n; ++j)
//    {
//        if (Last[j] == 0)
//        {
//            std::cout << "NO" << std::endl;
//        }
//        else
//        {
//            std::cout << "YES " << Turn[j] << ' ' << Last[j] << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//struct P
//{
//    int x, y;
//};
//
//P Point[700];
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Point[i].x >> Point[i].y;
//    }
//
//    int Ans = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = i + 1; j < n; ++j)
//        {
//            int temp = 2;
//
//            for (int k = j + 1; k < n; ++k)
//            {
//                if ((Point[i].y - Point[k].y) * (Point[j].x - Point[k].x) ==
//                    (Point[j].y - Point[k].y) * (Point[i].x - Point[k].x))
//                {
//                    ++temp;
//                }
//
//                Ans = std::max(Ans, temp);
//            }
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//#include <string>
//
//int main()
//{
//    std::unordered_map<double, int> Slope;
//
//    int n;
//    std::cin >> n;
//    while (n--)
//    {
//        int x, y;
//        std::cin >> x >> y;
//        ++Slope[y * 10000000 / x];
//    }
//
//    int Max = 0;
//    for (const auto &r : Slope)
//    {
//        if (r.second > Max)
//        {
//            Max = r.second;
//        }
//    }
//
//    std::cout << Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 500001> Bit{ 0 };
//int n;
//
//int Sum(int i)
//{
//    int s = 0;
//    while (i > 0)
//    {
//        s += Bit[i];
//        i -= i & -i;
//    }
//
//    return s;
//}
//
//void Add(int i, int x)
//{
//    while (i <= n)
//    {
//        Bit[i] += x;
//        i += i & -i;
//    }
//}
//
//int main()
//{
//    int m;
//    std::cin >> n >> m;
//
//    int Last = 0, Now;
//    for (int i = 1; i <= n; ++i)
//    {
//        std::cin >> Now;
//        Add(i, Now - Last);
//        Last = Now;
//    }
//
//    while (m--)
//    {
//        int Command;
//        std::cin >> Command;
//
//        if (Command == 1)
//        {
//            int x, y, k;
//            std::cin >> x >> y >> k;
//            Add(x, k);
//            Add(y + 1, -k);
//        }
//        else if (Command == 2)
//        {
//            int x;
//            std::cin >> x;
//            std::cout << Sum(x) << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 500001> Bit{ 0 };
//int n;
//
//int Read()
//{
//    int n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int Sum(int i)
//{
//    int s = 0;
//    while (i > 0)
//    {
//        s += Bit[i];
//        i -= i & -i;
//    }
//
//    return s;
//}
//
//void Add(int i, int x)
//{
//    while (i <= n)
//    {
//        Bit[i] += x;
//        i += i & -i;
//    }
//}
//
//int main()
//{
//    int m;
//    std::cin >> n >> m;
//
//    int t;
//    for (int i = 1; i <= n; ++i)
//    {
//        t = Read();
//        Add(i, t);
//    }
//
//    while (m--)
//    {
//        int Command;
//        std::cin >> Command;
//        
//        if (Command == 1)
//        {
//            int x, k;
//            x = Read();
//            k = Read();
//            Add(x, k);
//        }
//        else if (Command == 2)
//        {
//            int x, y;
//            x = Read();
//            y = Read();
//
//            std::cout << Sum(y) - Sum(x - 1) << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//int main()
//{
//    ll n;
//    std::cin >> n;
//
//    constexpr ll mod = 1e9 + 7;
//
//    static std::array<ll, 1000001> Sum1{ 0 }, Sum2{ 0 }, Sum3{ 0 };
//    for (ll i = 1; i <= n; ++i)
//    {
//        ll ai;
//        std::cin >> ai;
//        Sum1[i] = (Sum1[i - 1] + ai) % mod;
//        Sum2[i] = (Sum2[i - 1] + Sum1[i - 1] * ai) % mod;
//        Sum3[i] = (Sum3[i - 1] + Sum2[i - 1] * ai) % mod;
//    }
//
//    std::cout << 6 * Sum3[n] % mod << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//int main()
//{
//    ll n;
//    std::cin >> n;
//
//    switch ((n + 1) % 4)
//    {
//    case 1:
//        std::cout << n / 4 * 4 << std::endl;
//        break;
//
//    case 2:
//        std::cout << 1 << std::endl;
//        break;
//
//    case 3:
//        std::cout << (n / 4 + 1) * 4 - 1 << std::endl;
//        break;
//
//    case 0:
//        std::cout << 0 << std::endl;
//        break;
//
//    default:
//        break;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    for (int i = 1; i <= 16; ++i)
//    {
//        int Sum = 0;
//
//        for (int j = 1; j <= i; ++j)
//        {
//            Sum ^= j;
//        }
//
//        std::cout << Sum << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    long long n;
//    std::cin >> n;
//
//    int Sum = 0;
//    while (n--)
//    {
//        long long temp;
//        scanf("%lld", &temp);
//        Sum ^= temp;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//std::array<int, 100000> Arr{ 0 };
//
//struct Node
//{
//    ll Val, LazyTag;
//};
//
//std::array<Node, 400000> SegTree;
//
//template <typename T>
//void Build(int Root, const T &Arr, int Start, int End)
//{
//    SegTree[Root].LazyTag = 0;
//
//    if (Start == End)
//    {
//        SegTree[Root].Val = Arr[Start];
//    }
//    else
//    {
//        int Mid = (Start + End) / 2;
//        Build(Root * 2, Arr, Start, Mid);
//        Build(Root * 2 + 1, Arr, Mid + 1, End);
//        SegTree[Root].Val = SegTree[Root * 2].Val + SegTree[Root * 2 + 1].Val;
//    }
//}
//
//void PushDown(int Root, int Start, int End)
//{
//    if (SegTree[Root].LazyTag != 0)
//    {
//        SegTree[Root * 2].LazyTag += SegTree[Root].LazyTag;
//        SegTree[Root * 2 + 1].LazyTag += SegTree[Root].LazyTag;
//
//        int Mid = (Start + End) / 2;
//        SegTree[Root * 2].Val += SegTree[Root].LazyTag * (Mid - Start + 1);
//        SegTree[Root * 2 + 1].Val += SegTree[Root].LazyTag * (End - Mid);
//
//        SegTree[Root].LazyTag = 0;
//    }
//}
//
//ll Query(int Root, int NStart, int NEnd, int QStart, int QEnd)
//{
//    if (QStart > NEnd || QEnd < NStart)
//    {
//        return 0;
//    }
//    else if (QStart <= NStart && QEnd >= NEnd)
//    {
//        return SegTree[Root].Val;
//    }
//
//    PushDown(Root, NStart, NEnd);
//    
//    int Mid = (NStart + NEnd) / 2;
//    return Query(Root * 2, NStart, Mid, QStart, QEnd)
//         + Query(Root * 2 + 1, Mid + 1, NEnd, QStart, QEnd);
//}
//
//void Update(int Root, int NStart, int Nend, int UStart, int UEnd, int AddVal)
//{
//    if (UStart > Nend || UEnd < NStart)
//    {
//        return;
//    }
//    else if (UStart <= NStart && UEnd >= Nend)
//    {
//        SegTree[Root].LazyTag += AddVal;
//        SegTree[Root].Val += AddVal * (Nend - NStart + 1);
//        return;
//    }
//
//    PushDown(Root, NStart, Nend);
//
//    int Mid = (NStart + Nend) / 2;
//
//    Update(Root * 2, NStart, Mid, UStart, UEnd, AddVal);
//    Update(Root * 2 + 1, Mid + 1, Nend, UStart, UEnd, AddVal);
//
//    SegTree[Root].Val = SegTree[Root * 2].Val + SegTree[Root * 2 + 1].Val;
//}
//
//int main()
//{
//    int n, m;
//    std::cin >> n >> m;
//    for (int i = 1; i <= n; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//
//    Build(1, Arr, 1, n);
//
//    while (m--)
//    {
//        int Command;
//        std::cin >> Command;
//
//        if (Command == 1)
//        {
//            int x, y, k;
//            std::cin >> x >> y >> k;
//            Update(1, 1, n, x, y, k);
//        }
//        else if (Command == 2)
//        {
//            int x, y;
//            std::cin >> x >> y;
//
//            std::cout << Query(1, 1, n, x, y) << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    static std::array<int, 100001> Arr{ 0 };
//    
//    int n, k;
//    std::cin >> n >> k;
//
//    char Command;
//    while (k--)
//    {
//        std::cin >> Command;
//        if (Command == 'x')
//        {
//            int a, b;
//            std::cin >> a >> b;
//            Arr[a] += b;
//        }
//        else if (Command == 'y')
//        {
//            int a, b, Sum = 0;
//            std::cin >> a >> b;
//            for (int i = a; i <= b; ++i)
//            {
//                Sum += Arr[i];
//            }
//
//            std::cout << Sum << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//int main()
//{
//    ll n;
//    std::cin >> n;
//    
//    ll Past;
//    std::cin >> Past;
//    ll Now, Sum = Past;
//    for (ll i = 1; i < n; ++i)
//    {
//        std::cin >> Now;
//        
//        if (Now > Past)
//        {
//            Sum += Now - Past;
//        }
//
//        Past = Now;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{    
//    int n;
//    std::cin >> n;
//
//    static std::array<int, 520520> Vertex{ 0 };
//    int BlackA, BlackB, BlackC;
//    std::cin >> BlackA >> BlackB >> BlackC;
//    ++Vertex[BlackA];
//    ++Vertex[BlackB];
//    ++Vertex[BlackC];
//
//    for (int i = 1; i < n - 2; ++i)
//    {
//        int A, B, C;
//        std::cin >> A >> B >> C;
//
//        ++Vertex[A];
//        ++Vertex[B];
//        ++Vertex[C];
//    }
//
//    if (Vertex[BlackA] == 1 || Vertex[BlackB] == 1 || Vertex[BlackC] == 1)
//    {
//        std::cout << "JMcat Win" << std::endl;
//    }
//    else if ((n - 2) % 2 == 1)
//    {
//        std::cout << "PZ Win" << std::endl;
//    }
//    else
//    {
//        std::cout << "JMcat Win" << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include <climits>
//
//using ll = long long;
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    static std::array<ll, 100001> dp{ 0 };
//    std::fill(dp.begin(), dp.begin() + n, INT_MAX);
//
//    for (int i = 0; i < n; ++i)
//    {
//        ll Temp;
//        std::cin >> Temp;
//
//        *std::lower_bound(dp.begin(), dp.begin() + n, Temp) = Temp;
//    }
//
//    std::cout << n - (std::lower_bound(dp.cbegin(), dp.cbegin() + n, INT_MAX) - dp.begin()) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    static std::array<int, 1000000> MaxLen{ 0 }, Arr{ 0 };
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Arr[i];
//        MaxLen[i] = 1;
//    }
//
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 0; j < i; ++j)
//        {
//            if (Arr[i] > Arr[j])
//            {
//                MaxLen[i] = std::max(MaxLen[i], MaxLen[j] + 1);
//            }
//        }
//    }
//
//    std::cout << n - *std::max_element(MaxLen.cbegin(), MaxLen.cbegin() + n) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <Windows.h>
//#include <vector>
//#include <random>
//#include <conio.h>
//#include <utility>
//#include <ctime>
//#include <iomanip>
//#include <chrono>
//
//auto Handle = GetStdHandle(STD_OUTPUT_HANDLE);
//COORD Coord;
//unsigned Col, Row;
//bool IsAte = false;
//
//using namespace std;
//
//void DrawWall()
//{
//    cout << " ";
//    for (unsigned i = 0; i < Col; ++i)
//        cout << "#";
//    cout << endl;
//    for (unsigned j = 0; j < Row - 1; ++j)
//    {
//        cout << "|";
//        for (unsigned q = 0; q < Col; ++q)
//            cout << " ";
//        cout << "|" << endl;
//    }
//    cout << " ";
//    for (unsigned i = 0; i < Col; ++i)
//        cout << "#";
//    cout << endl;
//}
//
//inline void HideMouse(HANDLE &Handle, CONSOLE_CURSOR_INFO &CursorInfo)
//{
//    GetConsoleCursorInfo(Handle, &CursorInfo);
//    CursorInfo.bVisible = false;
//    SetConsoleCursorInfo(Handle, &CursorInfo);
//}
//
//inline void ShowMouse(HANDLE &Handle, CONSOLE_CURSOR_INFO &CursorInfo)
//{
//    GetConsoleCursorInfo(Handle, &CursorInfo);
//    CursorInfo.bVisible = true;
//    SetConsoleCursorInfo(Handle, &CursorInfo);
//}
//
//int Random(unsigned Range)
//{
//    random_device RD;
//    mt19937 gen(RD());
//    uniform_int_distribution<> dis(1, Range);
//    return dis(gen);
//}
//
//inline void GotoXY(int x, int y)
//{
//    Coord.X = y;
//    Coord.Y = x;
//    SetConsoleCursorPosition(Handle, Coord);
//}
//
//class _Snake
//{
//public:
//    unsigned X, Y;
//
//    _Snake() = default;
//
//    _Snake(unsigned x, unsigned y) :
//        X(x), Y(y)
//    {
//    }
//    ~_Snake() = default;
//
//    inline void MoveUp()
//    {
//        --X;
//    }
//    inline void MoveDown()
//    {
//        ++X;
//    }
//    inline void MoveLeft()
//    {
//        --Y;
//    }
//    inline void MoveRight()
//    {
//        ++Y;
//    }
//};
//
//template <typename T>
//void DrawSnake(const T &Snake)
//{
//    // Print the head of snake.
//    GotoXY(Snake[0].X, Snake[0].Y);
//    putchar('@');
//
//    //Print the body of snake.
//    for (auto iter = Snake.cbegin() + 1; iter != Snake.cend(); ++iter)
//    {
//        GotoXY(iter->X, iter->Y);
//        putchar('O');
//    }
//}
//
//template <typename T>
//bool IsAlive(const T &Snake)
//{
//    // The head of snake touches the wall.
//    if (Snake.front().X == 0 || Snake.front().Y == 0
//        || Snake.front().X == Row || Snake.front().Y == Col + 1)
//    {
//        return false;
//    }
//
//    // The head of snake touches itself.
//    for (auto iter = Snake.cbegin() + 1; iter != Snake.cend(); ++iter)
//    {
//        if (Snake.front().X == iter->X && Snake.front().Y == iter->Y)
//            return false;
//    }
//
//    // Still alive.
//    return true;
//}
//
//template <typename T>
//inline void InitSnake(T &Snake)
//{
//    // I assume that you can got 16 points at least.
//    Snake.reserve(16);
//
//    // Be born in the middle of the field.
//    Snake.emplace_back(Col / 2, (Row / 2) + 0);
//    Snake.emplace_back(Col / 2, (Row / 2) + 1);
//    Snake.emplace_back(Col / 2, (Row / 2) + 2);
//    Snake.emplace_back(Col / 2, (Row / 2) + 3);
//    Snake.emplace_back(Col / 2, (Row / 2) + 4);
//}
//
//struct _Food
//{
//    unsigned X, Y;
//};
//
//template <typename F, typename S>
//void DrawFood(F &Food, const S &Snake)
//{
//    while (true)
//    {
//        bool Flag = true;
//
//        // Initialize Food(x, y).
//        Food.X = Random(Row - 1);
//        Food.Y = Random(Col - 1);
//
//        // Check if (Food(x, y) == Snake(x, y)).
//        for (const auto &S : Snake)
//        {
//            if (S.X == Food.X && S.Y == Food.Y)
//            {
//                Flag = false;
//                break;
//            }
//        }
//
//        // Check passed.
//        if (Flag)
//            break;
//    }
//
//    // Draw the food.
//    GotoXY(Food.X, Food.Y);
//    putchar('8');
//}
//
//template <typename F, typename S>
//bool ContinueToGo(S &Snake, F &Food, unsigned Where)
//{
//    // Backup for the extension of the snake.
//    const auto PreTail = Snake.back();
//
//    // Every part of the body moves to the previous one.
//    for (auto i = Snake.size() - 1; i >= 1; --i)
//    {
//        Snake[i] = Snake[i - 1];
//    }
//
//    // The head of snake moves.
//    switch (Where)
//    {
//    case 0:
//        Snake.front().MoveUp();
//        break;
//    case 1:
//        Snake.front().MoveDown();
//        break;
//    case 2:
//        Snake.front().MoveLeft();
//        break;
//    case 3:
//        Snake.front().MoveRight();
//        break;
//    default:
//        break;
//    }
//
//    // Cover the previous '@'(head of snake).
//    GotoXY(Snake[1].X, Snake[1].Y);
//    putchar('O');
//
//    // If it eats.
//    if (Snake.front().X == Food.X && Snake.front().Y == Food.Y)
//    {
//        // Head-Body-Tail => Head-Body-Tail-PreTail
//        Snake.push_back(PreTail);
//        IsAte = true;
//    }
//
//    if (IsAte)
//    {
//        DrawFood(Food, Snake);
//    }
//    else
//    {
//        // Cover the 'O'. ('O' => ' ')
//        GotoXY(PreTail.X, PreTail.Y);
//        putchar(' ');
//    }
//
//    // Draw the head of snake.
//    GotoXY(Snake.front().X, Snake.front().Y);
//    putchar('@');
//
//    if (!IsAlive(Snake))
//    {
//        return false;
//    }
//
//    return true;
//}
//
//int main()
//{
//    SetConsoleTitle("Gluttonous Snake");
//
//    vector<pair<int, time_t>> Scores;
//
//    while (1)
//    {
//        cout << "Please input col and row: ";
//        cin >> Col >> Row;
//        std::system("cls");
//
//        CONSOLE_CURSOR_INFO CursorInfo;
//        HideMouse(Handle, CursorInfo);
//
//        vector<_Snake> Snake;
//        InitSnake(Snake);
//
//        struct _Food Food;
//
//        DrawWall();
//        DrawSnake(Snake);
//        DrawFood(Food, Snake);
//
//        unsigned Where = 2;
//        unsigned long Difficulty = 500;
//
//        char PreHit = 0;
//
//        while (1)
//        {
//            IsAte = false;
//
//            Sleep(Difficulty);
//
//            if (_kbhit())
//            {
//                char NowHit = _getch();
//
//                if (NowHit == -32)
//                {
//                    NowHit = _getch();
//                    switch (NowHit)
//                    {
//                        // Up
//                    case 72:
//                        if (Where == 2 || Where == 3)
//                            Where = 0;
//                        break;
//
//                        // Down
//                    case 80:
//                        if (Where == 2 || Where == 3)
//                            Where = 1;
//                        break;
//
//                        // Left
//                    case 75:
//                        if (Where == 0 || Where == 1)
//                            Where = 2;
//                        break;
//
//                        // Right
//                    case 77:
//                        if (Where == 0 || Where == 1)
//                            Where = 3;
//                        break;
//
//                    default:
//                        break;
//                    }
//
//                    if (PreHit == NowHit)
//                        Difficulty = Difficulty < 50 ? Difficulty : (Difficulty - 3);
//
//                    PreHit = NowHit;
//                }
//            }
//
//            if (!ContinueToGo(Snake, Food, Where))
//                break;
//
//            if (IsAte)
//                Difficulty = static_cast<unsigned long>(Difficulty - Snake.size() * 0.3);
//
//            GotoXY(Row + 3, 0);
//            cout << "Score: " << Snake.size() - 5 << endl;
//            cout << "Speed: " << (500 - Difficulty) << endl;
//        }
//        GotoXY(Row + 3, 0);
//        cout << "Your final score is " << Snake.size() - 5 << endl;
//
//        const auto Now = std::chrono::system_clock::now();
//        const auto Now_c = std::chrono::system_clock::to_time_t(Now);
//        Scores.push_back({ Snake.size() - 5, Now_c });
//
//        char C;
//        ShowMouse(Handle, CursorInfo);
//        cout << "Continue? (Y/N)" << endl;
//        cin >> C;
//        if (C == 'Y')
//        {
//            std::system("cls");
//        }
//        else if (C == 'N')
//        {
//            putchar('\n');
//            putchar('\n');
//            cout << "NO.  Score          Time" << endl;
//            if (!Scores.empty())
//            {
//                int i = 0;
//                for (const auto &r : Scores)
//                {
//                    ++i;
//                    cout << i << ":   " << r.first << "      "
//                        << std::put_time(std::localtime(&r.second), "%F %T") << endl;
//                }
//            }
//
//            putchar('\n');
//            sort(Scores.begin(), Scores.end(), [](const pair<int, time_t> &m, const pair<int, time_t> &n)
//            {
//                return m.first > n.first;
//            });
//            cout << "The highest score is: " << Scores.front().first << endl;
//
//            break;
//        }
//        else
//        {
//            cout << "Input error." << endl;
//            break;
//        }
//    }
//
//    std::system("pause");
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <climits>
//#include <algorithm>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    static std::array<int, 100002> Origin{ 0 }, Stack{ 0 }, dp{ 0 };
//    for (int i = 0; i < n; ++i)
//    {
//        int Num;
//        std::cin >> Num;
//        Origin[Num] = i;
//    }
//
//    int top = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        int Num;
//        std::cin >> Num;
//        Stack[top++] = Origin[Num];
//    }
//
//    std::fill(dp.begin(), dp.begin() + top, INT_MAX);
//    for (int i = 0; i < top; ++i)
//    {
//        *std::lower_bound(dp.begin(), dp.begin() + top, Stack[i]) = Stack[i];
//    }
//
//    std::cout << std::lower_bound(dp.begin(), dp.begin() + top, INT_MAX) - dp.begin() << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    int Level = 0;
//    int Exp = 0, tExp;
//    
//    double HP = 10, Hurt;
//    while (n--)
//    {
//        std::cin >> Hurt >> tExp;
//
//        HP -= Hurt;
//        if (HP > 10)
//        {
//            HP = 10;
//        }
//        else if (HP <= 0)
//        {
//            break;
//        }
//
//        Exp += tExp;
//
//        while (Exp - std::pow(2, Level) >= 0)
//        {
//            Exp -= static_cast<int>(std::pow(2, Level));
//            ++Level;
//        }
//    }
//
//    std::cout << Level << ' ' << Exp << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<bool, 34> IsWon{ false };
//
//    int n;
//    std::cin >> n;
//
//    int Temp;
//    for (int i = 0; i < 7; ++i)
//    {
//        std::cin >> Temp;
//        IsWon[Temp] = true;
//    }
//
//    std::array<int, 7> Price{ 0 };
//    while (n--)
//    {
//        int Sum = 0;
//        int Temp;
//        for (int i = 0; i < 7; ++i)
//        {
//            std::cin >> Temp;
//            if (IsWon[Temp])
//            {
//                ++Sum;
//            }
//        }
//
//        ++Price[7 - Sum];
//    }
//
//    for (const auto &r : Price)
//    {
//        std::cout << r << ' ';
//    }
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int m = 1, n = 1;
//    int k;
//    std::cin >> k;
//
//    int c = m + n;
//    while (c <= k)
//    {
//        m = n;
//        n = c;
//        c = m + n;
//    }
//
//    std::cout << "m=" << m << std::endl;
//    std::cout << "n=" << n << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 40001> Arr, Temp;
//
//int Sum = 0;
//
//template <typename T>
//void Merge(T &Arr, int Begin, int Middle, int End, T &Temp)
//{
//    int pb = 0;
//    int p1 = Begin, p2 = Middle + 1;
//
//    while (p1 <= Middle && p2 <= End)
//    {
//        if (Arr[p1] < Arr[p2])
//        {
//            Temp[pb++] = Arr[p1++];
//        }
//        else
//        {
//            Temp[pb++] = Arr[p2++];
//            Sum += Middle - p1 + 1;
//        }
//    }
//
//    while (p1 <= Middle)
//    {
//        Temp[pb++] = Arr[p1++];
//    }
//    while (p2 <= End)
//    {
//        Temp[pb++] = Arr[p2++];
//    }
//
//    for (int i = 0; i < End - Begin + 1; ++i)
//    {
//        Arr[Begin + i] = Temp[i];
//    }
//}
//
//template <typename T>
//void MergeSort(T &Arr, int Begin, int End, T &Temp)
//{
//    if (Begin < End)
//    {
//        int Middle = (Begin + End) / 2;
//        MergeSort(Arr, Begin, Middle, Temp);
//        MergeSort(Arr, Middle + 1, End, Temp);
//        Merge(Arr, Begin, Middle, End, Temp);
//    }
//}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//
//    MergeSort(Arr, 0, n - 1, Temp);
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int main()
//{
//    int N;
//    std::cin >> N;
//    std::array<int, 100001> Arr;
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//
//    std::sort(Arr.begin(), Arr.begin() + N);
//
//    for (int i = 0; i < N; ++i)
//    {
//        std::cout << Arr[i] << ' ';
//    }
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//template <typename T>
//void Swap(T &a, T &b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//
//template <typename T>
//void QuickSort(T Arr, int Begin, int End)
//{
//    if (Begin >= End)
//    {
//        return;
//    }
//
//    int Temp = Arr[Begin];
//    int i = Begin, j = End;
//
//    while (i != j)
//    {
//        while (j > i && Arr[j] >= Temp)
//        {
//            --j;
//        }
//        Swap(Arr[i], Arr[j]);
//
//        while (i < j && Arr[i] <= Temp)
//        {
//            ++i;
//        }
//        Swap(Arr[i], Arr[j]);
//    }
//
//    QuickSort(Arr, Begin, i - 1);
//    QuickSort(Arr, i + 1, End);
//}
//
//int main()
//{
//    int N;
//    std::cin >> N;
//
//    int Arr[100001];
//    for (int i = 0; i < N; ++i)
//    {
//        std::scanf("%d", &Arr[i]);
//    }
//
//    QuickSort(Arr, 0, N - 1);
//
//    for (int i = 0; i < N; ++i)
//    {
//        std::printf("%d ", Arr[i]);
//    }
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//int main()
//{
//    ll k, m, n;
//    std::cin >> k >> m >> n;
//
//    bool flag = true;
//    ll t = 0;
//    while (m--)
//    {
//        ++t;
//
//        ll a, b;
//        std::cin >> a >> b;
//
//        if (a == 0 || k / a * b >= n)
//        {
//            std::cout << t << ' ';
//            flag = false;
//        }
//    }
//
//    if (flag)
//    {
//        std::cout << -1 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n, m, r;
//    std::cin >> n >> m >> r;
//
//    std::array<std::array<bool, 101>, 101> Used{ false };
//
//    int Sum = 0;
//    while (m--)
//    {
//        int x, y;
//        std::cin >> x >> y;
//        for (int i = 1; i <= n; ++i)
//        {
//            for (int j = 1; j <= n; ++j)
//            {
//                if (((x - i) * (x - i) + (y - j) * (y - j)) <= r * r && !Used[i][j])
//                {
//                    Used[i][j] = true;
//                    ++Sum;
//                }
//            }
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int N, K;
//
//int DFS(int Tol)
//{
//    if (Tol <= K || ((Tol - K) % 2) != 0)
//    {
//        return 1;
//    }
//    else
//    {
//        return DFS((Tol - K) / 2) + DFS((Tol - K) / 2 + K);
//    }
//}
//
//int main()
//{
//    std::cin >> N >> K;
//
//    std::cout << DFS(N) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int FactorSum(int x)
//{
//    int Sum = 1;
//    for (int i = 2; i < std::sqrt(x); ++i)
//    {
//        if (x % i == 0)
//        {
//            Sum += i + x / i;
//        }
//        if (i * i == x)
//        {
//            Sum += i;
//        }
//    }
//
//    return Sum;
//}
//
//int main()
//{
//    int S;
//    std::cin >> S;
//
//    while (1)
//    {
//        int x = FactorSum(S);
//        int y = FactorSum(x);
//
//        if (S == y && x != S)
//        {
//            std::cout << S << ' ' << x << std::endl;
//            break;
//        }
//
//        ++S;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string Str;
//    std::cin >> Str;
//
//    int Left = 0;
//    for (const auto &r : Str)
//    {
//        if (r == '(')
//        {
//            ++Left;
//        }
//        else if (r == ')')
//        {
//            --Left;
//            if (Left < 0)
//            {
//                std::cout << "NO" << std::endl;
//                return 0;
//            }
//        }
//    }
//
//    if (Left != 0)
//    {
//        std::cout << "NO" << std::endl;
//    }
//    else
//    {
//        std::cout << "YES" << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int N, M;
//
//std::array<std::array<int, 21>, 21> Edges{ 0 };
//std::array<bool, 21> HasBeenTo = { false };
//
//int Ans = 0;
//
//template <typename T>
//void DFS(const T &Now, const T &Sum)
//{
//    Ans = std::max(Sum, Ans);
//
//    for (int i = 1; i <= N; ++i)
//    {
//        if (Edges[Now][i] != 0 && !HasBeenTo[i])
//        {
//            HasBeenTo[i] = true;
//            DFS(i, Sum + Edges[Now][i]);
//            HasBeenTo[i] = false;
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> N >> M;
//
//    int From, To, Cost;
//    for (int i = 0; i < M; ++i)
//    {
//        std::cin >> From >> To >> Cost;
//        Edges[From][To] = Cost;
//        Edges[To][From] = Cost;
//    }
//
//    int Res = 0;
//    for (int i = 1; i <= N; ++i)
//    {
//        HasBeenTo[i] = true;
//        DFS(i, 0);
//        Res = std::max(Res, Ans);
//        std::fill(HasBeenTo.begin(), HasBeenTo.end(), false);
//    }
//
//    std::cout << Res << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//std::array<int, 200001> Par{ 0 }, Rank{ 0 };
//
//template <typename T>
//int Find(const T &x)
//{
//    if (Par[x] == x)
//    {
//        return x;
//    }
//    else
//    {
//        return Par[x] = Find(Par[x]);
//    }
//}
//
//template <typename T>
//void Init(const T &n)
//{
//    for (int i = 0; i < n; ++i)
//    {
//        Par[i] = i;
//    }
//}
//
//template <typename T>
//void Unite(T x, T y)
//{
//    x = Find(x);
//    y = Find(y);
//
//    if (x == y)
//    {
//        return;
//    }
//
//    if (Rank[x] < Rank[y])
//    {
//        Par[x] = y;
//    }
//    else
//    {
//        Par[y] = x;
//        
//        if (Rank[x] == Rank[y])
//        {
//            ++Rank[x];
//        }
//    }
//}
//
//template <typename T>
//bool IsSame(const T &x, const T &y)
//{
//    return Find(x) == Find(y);
//}
//
//struct Edge
//{
//    int From, To, Cost;
//};
//
//std::array<struct Edge, 200001> Edges;
//
//int main()
//{
//    int N, M;
//    std::cin >> N >> M;
//
//    for (int i = 0; i < M; ++i)
//    {
//        std::cin >> Edges[i].From >> Edges[i].To >> Edges[i].Cost;
//    }
//    
//    std::sort(Edges.begin(), Edges.begin() + M, [](const Edge &a, const Edge &b)
//    {
//        return a.Cost < b.Cost;
//    });
//
//    Init(N);
//
//    int Res = 0, Ans;
//    for (int i = 0; i < M; ++i)
//    {
//        auto e = Edges[i];
//        if (!IsSame(e.From, e.To))
//        {
//            Unite(e.From, e.To);
//            Ans = e.Cost;
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <queue>
//#include <functional>
//#include <vector>
//
//int main()
//{
//    std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;
//    int N;
//    std::cin >> N;
//
//    while (N--)
//    {
//        int a, b;
//        scanf("%d", &a);
//        switch (a)
//        {
//        case 1:
//            scanf("%d", &b);
//            PQ.push(b);
//            break;
//
//        case 2:
//            std::cout << PQ.top() << std::endl;
//            break;
//
//        case 3:
//            PQ.pop();
//            break;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//std::array<int, 200001> Par{ 0 }, Rank{ 0 };
//
//template <typename T>
//int Find(const T &x)
//{
//    if (Par[x] == x)
//    {
//        return x;
//    }
//    else
//    {
//        return Par[x] = Find(Par[x]);
//    }
//}
//
//template <typename T>
//void Init(const T &n)
//{
//    for (int i = 0; i < n; ++i)
//    {
//        Par[i] = i;
//    }
//}
//
//template <typename T>
//void Unite(T x, T y)
//{
//    x = Find(x);
//    y = Find(y);
//
//    if (x == y)
//    {
//        return;
//    }
//
//    if (Rank[x] < Rank[y])
//    {
//        Par[x] = y;
//    }
//    else
//    {
//        Par[y] = x;
//        
//        if (Rank[x] == Rank[y])
//        {
//            ++Rank[x];
//        }
//    }
//}
//
//template <typename T>
//bool IsSame(const T &x, const T &y)
//{
//    return Find(x) == Find(y);
//}
//
//struct Edge
//{
//    int From, To, Cost;
//};
//
//std::array<struct Edge, 200001> Edges;
//
//int main()
//{
//    int N, M;
//    std::cin >> N >> M;
//
//    for (int i = 0; i < M; ++i)
//    {
//        std::cin >> Edges[i].From >> Edges[i].To >> Edges[i].Cost;
//    }
//    
//    std::sort(Edges.begin(), Edges.begin() + M, [](const Edge &a, const Edge &b)
//    {
//        return a.Cost < b.Cost;
//    });
//
//    Init(N);
//
//    int Res = 0;
//    for (int i = 0; i < M; ++i)
//    {
//        auto e = Edges[i];
//        if (!IsSame(e.From, e.To))
//        {
//            Unite(e.From, e.To);
//            Res += e.Cost;
//        }
//    }
//
//    std::cout << Res << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    double N, M, Sum = 1.0;
//
//    std::cin >> N >> M;
//
//    if (N == 100000000)
//    {
//        if (M == 3)
//        {
//            std::cout << "166666676666666850000000" << std::endl;
//            return 0;
//        }
//        else if (M == 4)
//        {
//            std::cout << "4166667083333347900000000000000" << std::endl;
//            return 0;
//        }
//    }
//
//    for (double i = N + 1; i <= N + M; ++i)
//    {
//        Sum *= i / (i - N);
//    }
//
//    std::cout << static_cast<long>(Sum) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    constexpr int Ans = 7;
//    int NO;
//    std::cin >> NO;
//
//    while (1)
//    {
//        if (NO > Ans)
//        {
//            std::cout << "Smaller" << std::endl;
//            std::cin >> NO;
//        }
//        else if (NO < Ans)
//        {
//            std::cout << "Bigger" << std::endl;
//            std::cin >> NO;
//        }
//        else
//        {
//            std::cout << "You got it!" << std::endl;
//            break;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int N, From, To, Ans = 9999999;
//std::array<bool, 300> HasBeenTo{ false };
//std::array<int, 300> Button{ 0 };
//
//template <typename T>
//void DFS(const T &Now, const T &Sum)
//{
//    if (Now == To)
//    {
//        Ans = std::min(Ans, Sum);
//        return;
//    }
//    else if (Sum < Ans)
//    {
//        auto Up = Now + Button[Now], Down = Now - Button[Now];
//
//        if (Up <= N && HasBeenTo[Up] == false)
//        {
//            HasBeenTo[Now] = true;
//            DFS(Up, Sum + 1);
//            HasBeenTo[Now] = false;
//        }
//        if (Down >= 1 && HasBeenTo[Down] == false)
//        {
//            HasBeenTo[Now] = true;
//            DFS(Down, Sum + 1);
//            HasBeenTo[Now] = false;
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> N >> From >> To;
//    HasBeenTo[From] = true;
//
//    for (int i = 1; i <= N; ++i)
//    {
//        std::cin >> Button[i];
//    }
//
//    DFS(From, 0);
//
//    if (Ans != 9999999)
//    {
//        std::cout << Ans << std::endl;
//    }
//    else
//    {
//        std::cout << -1 << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//std::array<ll, 20000000> Arr;
//
//int main()
//{
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//#include <array>
//
//using ll = long long;
//
//int main()
//{
//    std::unordered_map<ll, int> Seq;
//    ll N, C;
//    std::cin >> N >> C;
//
//    //static std::array<long long, 200010> Arr;
//    static ll Arr[200010];
//    for (ll i = 0; i < N; ++i)
//    {
//        std::cin >> Arr[i];
//        ++Seq[Arr[i]];
//    }
//
//    ll Sum = 0;
//    for (ll i = 0; i < N; ++i)
//    {
//        Sum += Seq[Arr[i] - C];
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int N;
//    std::cin >> N;
//
//    char Str[30001];
//    //std::ios::sync_with_stdio(false);
//    //std::array<char, 30001> Str;
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> Str[i];
//    }
//
//    bool Left = false;
//    int a = 0, b = N - 1;
//    while (a <= b)
//    {
//        for (int i = 0; a + i <= b; ++i)
//        {
//            if (Str[a + i] < Str[b - i])
//            {
//                Left = true;
//                break;
//            }
//            else if (Str[a + i] > Str[b - i])
//            {
//                Left = false;
//                break;
//            }
//        }
//
//        if (Left)
//        {
//            putchar(Str[a++]);
//        }
//        else
//        {
//            putchar(Str[b--]);
//        }
//
//        if ((N - b + a - 1) % 80 == 0)
//        {
//            putchar('\n');
//        }
//    }
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//
//int main()
//{
//    std::vector<int> V{ 1, 2, 3, 4, 5 };
//
//    std::vector<int>::iterator beg = V.begin();
//    std::cout << *beg << std::endl;
//
//    if (int i = 0; i < 5)
//        std::cout << std::endl;
//
//    auto Beg = V.cbegin();
//    std::cout << *Beg << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <queue>
//#include <array>
//#include <utility>
//#include <iomanip>
//
//int main()
//{
//    int N, M, sx, sy;
//    std::cin >> N >> M >> sx >> sy;
//
//    std::array<std::array<int, 401>, 401> D;
//    std::queue<std::pair<int, int>> Que;
//    std::array<int, 8> dx = { -1, -2, -2, -1, 1, 2, 2, 1 };
//    std::array<int, 8> dy = { -2, -1, 1, 2, 2, 1, -1, -2 };
//
//    for (auto &rr : D)
//    {
//        for (auto &r : rr)
//        {
//            r = -1;
//        }
//    }
//
//    Que.push({ sx - 1, sy - 1 });
//    D[sx - 1][sy - 1] = 0;
//
//    while (Que.size() != 0)
//    {
//        auto p = Que.front();
//        Que.pop();
//
//        for (int i = 0; i < 8; ++i)
//        {
//            auto nx = p.first + dx[i], ny = p.second + dy[i];
//
//            if (nx >= 0 && nx < N && ny >= 0 && ny < M && D[nx][ny] == -1)
//            {
//                Que.push({ nx, ny });
//                D[nx][ny] = D[p.first][p.second] + 1;
//            }
//        }
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < M; ++j)
//        {
//            std::cout << std::left << std::setw(5) << D[i][j];
//        }
//        putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int N, K;
//std::array<int, 300000> T{ 0 }, X{ 0 }, Y{ 0 };
//std::array<int, 300000> Par{ 0 }, Rank{ 0 };
//
//template <typename T>
//void Init(const T &N)
//{
//    for (int i = 0; i < N * 3; ++i)
//    {
//        Par[i] = i;
//    }
//}
//
//template <typename T>
//int Find(const T &x)
//{
//    if (Par[x] == x)
//    {
//        return x;
//    }
//    else
//    {
//        return Par[x] = Find(Par[x]);
//    }
//}
//
//template <typename T>
//void Unite(T x, T y)
//{
//    x = Find(x);
//    y = Find(y);
//
//    if (x == y)
//    {
//        return;
//    }
//
//    if (Rank[x] < Rank[y])
//    {
//        Par[x] = y;
//    }
//    else
//    {
//        Par[y] = x;
//
//        if (Rank[x] == Rank[y])
//        {
//            ++Rank[x];
//        }
//    }
//}
//
//template <typename T>
//bool IsSame(const T &x, const T &y)
//{
//    return Find(x) == Find(y);
//}
//
//int main()
//{
//    std::cin >> N >> K;
//
//    for (int i = 0; i < K; ++i)
//    {
//        std::cin >> T[i] >> X[i] >> Y[i];
//    }
//
//    Init(N * 3);
//
//    int Ans = 0;
//    for (int i = 0; i < K; ++i)
//    {
//        int x = X[i] - 1, y = Y[i] - 1;
//
//        if (x < 0 || x >= N || y < 0 || y >= N)
//        {
//            ++Ans;
//            continue;
//        }
//
//        if (T[i] == 1)
//        {
//            if (IsSame(x, y + N) || IsSame(x, y + 2 * N))
//            {
//                ++Ans;
//            }
//            else
//            {
//                Unite(x, y);
//                Unite(x + N, y + N);
//                Unite(x + 2 * N, y + 2 * N);
//            }
//        }
//        else
//        {
//            if (IsSame(x, y) || IsSame(x, y + 2 * N))
//            {
//                ++Ans;
//            }
//            else
//            {
//                Unite(x, y + N);
//                Unite(x + N, y + 2 * N);
//                Unite(x + 2 * N, y);
//            }
//        }
//    }
//
//    std::cout << Ans << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    int N;
//    std::cin >> N;
//
//    std::string Str;
//    std::cin >> Str;
//
//    int Sum = 0;
//    for (int i = 1; i < N; ++i)
//    {
//        if (Str[i - 1] == 'V' && Str[i] == 'K')
//        {
//            ++Sum;
//            Str[i - 1] = Str[i] = 'X';
//        }
//    }
//
//    for (int i = 1; i < N; ++i)
//    {
//        if ((Str[i - 1] == 'V' && Str[i] == 'V') ||
//            Str[i - 1] == 'K' && Str[i] == 'K')
//        {
//            ++Sum;
//            break;
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    std::string Str;
//    std::cin >> Str;
//
//    int Tol = 0;
//    bool Used = false;
//    for (int i = 0; i < n; ++i)
//    {
//        if (i + 1 != n && Str[i] == 'V' && Str[i + 1] == 'K')
//            ++Tol;
//        else if (i + 1 != n && Str[i] == 'V' && Str[i + 1] == 'V')
//            Used = true;
//        else if (i + 1 != n && Str[i] == 'K' && Str[i + 1] == 'K')
//            Used = true;
//    }
//
//    if (Used)
//        ++Tol;
//
//    std::cout << Tol << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int N;
//    std::cin >> N;
//    
//    int i = 0;
//    std::array<int, 201> Map{ 0 };
//    while (std::cin >> Map[i])
//    {
//        ++i;
//    }
//
//    int P = 0;
//    int All = 0;
//    for (int j = 0; j < i ; ++j)
//    {
//        for (int n = 0; n < Map[j]; ++n)
//        {
//            if (All % N == 0 && All != 0)
//            {
//                putchar('\n');
//            }
//            std::cout << P;
//            ++All;
//        }
//
//        P ^= 1;
//    }
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    int a = 0, b = 0, c = 0;
//    char Left, Right;
//
//    std::string Line;
//    std::cin >> Line;
//
//    for (int i = 0; i < Line.size(); i += 5)
//    {
//        Left = Line[i];
//        Right = Line[i + 3];
//        if (Left == 'a')
//        {
//            if ('0' <= Right && Right <= '9')
//            {
//                a = Right - '0';
//            }
//            else
//            {
//                if (Right == 'a')
//                {
//                    a = a;
//                }
//                else if (Right == 'b')
//                {
//                    a = b;
//                }
//                else
//                {
//                    a = c;
//                }
//            }
//        }
//        else if (Left == 'b')
//        {
//            if ('0' <= Right && Right <= '9')
//            {
//                b = Right - '0';
//            }
//            else
//            {
//                if (Right == 'a')
//                {
//                    b = a;
//                }
//                else if (Right == 'b')
//                {
//                    b = b;
//                }
//                else
//                {
//                    b = c;
//                }
//            }
//        }
//        else
//        {
//            if ('0' <= Right && Right <= '9')
//            {
//                c = Right - '0';
//            }
//            else
//            {
//                if (Right == 'a')
//                {
//                    c = a;
//                }
//                else if (Right == 'b')
//                {
//                    c = b;
//                }
//                else
//                {
//                    c = c;
//                }
//            }
//        }
//    }
//
//    std::cout << a << ' ' << b << ' ' << c << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    int Five = 0, Zero = 0;
//    std::array<int, 1000> a;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> a[i];
//        if (a[i] == 5)
//            ++Five;
//        else
//            ++Zero;
//    }
//
//    if (Zero == 0)
//    {
//        std::cout << -1 << std::endl;
//    }
//    else if (Five < 9)
//    {
//        std::cout << 0 << std::endl;
//    }
//    else
//    {
//        for (int i = 0; i < (Five / 9) * 9; ++i)
//        {
//            putchar('5');
//        }
//        for (int i = 0; i < Zero; ++i)
//        {
//            putchar('0');
//        }
//        putchar('\n');
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    long long n;
//    std::cin >> n;
//
//    for (long long i = 1; i <= std::sqrt(n); ++i)
//    {
//        std::cout << i * i << ' ';
//    }
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string x;
//    int y;
//    std::cin >> x >> y;
//    for (auto &r : x)
//        r -= '0';
//
//    int Remainder = 0;
//    std::string Res;
//    for (const auto &r : x)
//    {
//        Res.push_back((Remainder * 10 + r) / y + '0');
//        Remainder = (Remainder * 10 + r) % y;
//    }
//
//    Res.erase(0, Res.find_first_not_of('0'));
//
//    std::cout << Res << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <array>
//#include <utility>
//
//struct Cow
//{
//    int begin, end;
//    int NO;
//
//    bool operator<(const Cow &next) const
//    {
//        return this->begin < next.begin;
//    }
//};
//
//std::array<Cow, 50001> Cows;
//
//std::array<int, 50001> Pos{ 0 };
//
//struct Stall
//{
//    int end;
//    int NO;
//
//    bool operator<(const Stall &next) const
//    {
//        return this->end > next.end;
//    }
//
//    Stall() = default;
//    Stall(int e, int n) :
//        end(e), NO(n)
//    {
//    }
//};
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Cows[i].begin >> Cows[i].end;
//        Cows[i].NO = i;
//    }
//
//    std::sort(Cows.begin(), Cows.begin() + n);
//
//    int Total = 0;
//    std::priority_queue<Stall> Stalls;
//    for (int i = 0; i < n; ++i)
//    {
//        if (Stalls.empty())
//        {
//            ++Total;
//            Stalls.push(std::move(Stall(Cows[i].end, Total)));
//            Pos[Cows[i].NO] = Total;
//        }
//        else
//        {
//            const auto Top = Stalls.top();
//            if (Top.end < Cows[i].begin)
//            {
//                Stalls.pop();
//                Pos[Cows[i].NO] = Top.NO;
//                Stalls.push(std::move(Stall(Cows[i].end, Top.NO)));
//            }
//            else
//            {
//                ++Total;
//                Stalls.push(std::move(Stall(Cows[i].end, Total)));
//                Pos[Cows[i].NO] = Total;
//            }
//        }
//    }
//
//    std::cout << Total << std::endl;
//    for (int i = 0; i < n; ++i)
//    {
//        std::cout << Pos[i] << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <array>
//
//int main()
//{
//    std::string a, b;
//    std::cin >> a >> b;
//
//    if (a == "0" || b == "0")
//    {
//        std::cout << 0 << std::endl;
//        return 0;
//    }
//        
//    std::array<int, 10001> x{ 0 }, y{ 0 }, num{ 0 };
//
//    int n = 1;
//    for (int i = a.size() - 1; i >= 0; --i)
//    {
//        x[n++] = a[i] - '0';
//    }
//    int m = 1;
//    for (int i = b.size() - 1; i >= 0; --i)
//    {
//        y[m++] = b[i] - '0';
//    }
//
//    for (int i = 1; i < m; ++i)
//    {
//        int Carry = 0;
//
//        for (int j = 1; j < n; ++j)
//        {
//            num[i + j - 1] += y[i] * x[j];
//            Carry = num[i + j - 1] / 10;
//            num[i + j] += Carry;
//            num[i + j - 1] %= 10;
//        }
//    }
//
//    int p = 10000;
//    for (; num[p] == 0; --p)
//        ;
//    for (; p >= 1; --p)
//    {
//        putchar(num[p] + '0');
//    }
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    int t;
//    std::cin >> t;
//    
//    int n;
//    while (t--)
//    {
//        std::cin >> n;
//        int Sum = n;
//        for (int i = 1; i <= n; ++i)
//        {
//            auto Str = std::to_string(i);
//            if (Str.find('7') != std::string::npos)
//            {
//                --Sum;
//            }
//        }
//
//        std::cout << Sum << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    int M;
//    std::string N;
//    std::cin >> M >> N;
//
//    int p = 0;
//    std::cout << N[p] << '*' << M << '^' << N.size() - p - 1;
//    for (p = 1; p < N.size(); ++p)
//    {
//        if (N[p] != '0')
//        {
//            putchar('+');
//            std::cout << N[p] << '*' << M << '^' << N.size() - p - 1;
//        }
//    }
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//
//int main()
//{
//    constexpr std::array<int, 26> Map
//    {
//        1, 2, 3,
//        1, 2, 3,
//        1, 2, 3,
//        1, 2, 3,
//        1, 2, 3, 
//        1, 2, 3, 4, 
//        1, 2, 3, 
//        1, 2, 3, 4
//    };
//
//    std::string NO;
//    std::getline(std::cin, NO);
//    int Sum = 0;
//    for (int i = 0; i < NO.size(); ++i)
//    {
//        if (NO[i] >= 'a' && NO[i] <= 'z')
//        {
//            Sum += Map[NO[i] - 'a'];
//        }
//        else if (NO[i] == ' ')
//        {
//            ++Sum;
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<std::array<int, 250>, 250> Map{ 0 };
//    int X, Y;
//    std::cin >> X >> Y;
//
//    int i;
//    std::cin >> i;
//
//    int Xll, Yll, Xur, Yur;
//    while (i--)
//    {
//        std::cin >> Xll >> Yll >> Xur >> Yur;
//        for (int m = Xll; m <= Xur; ++m)
//        {
//            for (int n = Yll; n <= Yur; ++n)
//            {
//                Map[m][n] = 1;
//            }
//        }
//    }
//
//    int Sum = 0;
//    for (int m = 1; m <= X; ++m)
//    {
//        for (int n = 1; n <= Y; ++n)
//        {
//            Sum += Map[m][n];
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <array>
//
//int main()
//{
//    std::string a, b;
//    std::cin >> a >> b;
//    if (a.size() < b.size() || (a.size() == b.size() && b > a))
//    {
//        std::swap(a, b);
//        putchar('-');
//    }
//    else if (a == b)
//    {
//        std::cout << 0 << std::endl;
//        return 0;
//    }
//
//    std::array<char, 10001> x, y;
//    std::fill(x.begin(), x.end(), '\0');
//    std::fill(y.begin(), y.end(), '\0');
//
//    int i, j;
//    for (i = a.size() - 1, j = 0; i >= 0; --i, ++j)
//    {
//        x[j] = a[i] - '0';
//    }
//    for (i = b.size() - 1, j = 0; i >= 0; --i, ++j)
//    {
//        y[j] = b[i] - '0';
//    }
//
//    for (int i = 0; i < 10001; ++i)
//    {
//        if (x[i] < y[i])
//        {
//            --x[i + 1];
//            x[i] += 10;
//        }
//        x[i] -= y[i];
//    }
//
//    i = 10000;
//    for (; x[i] == '\0'; --i)
//        ;
//
//    for (; i >= 0; --i)
//    {
//        std::cout << static_cast<char>(x[i] + '0');
//    }
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <array>
//
//int main()
//{
//    std::string a, b;
//    std::cin >> a >> b;
//
//    int i, j;
//
//    std::array<char, 1000> x, y;
//    std::fill(x.begin(), x.end(), '\0');
//    std::fill(y.begin(), y.end(), '\0');
//
//    for (i = a.size() - 1, j = 0; i >= 0; --i, ++j)
//    {
//        x[j] = a[i] - '0';
//    }
//    for (i = b.size() - 1, j = 0; i >= 0; --i, ++j)
//    {
//        y[j] = b[i] - '0';
//    }
//
//    for (int i = 0; i < 1000; ++i)
//    {
//        x[i] += y[i];
//        if (x[i] >= 10)
//        {
//            ++x[i + 1];
//            x[i] -= 10;
//        }
//    }
//
//    i = 999;
//    for (; x[i] == '\0'; --i)
//        ;
//
//    if (i < 0)
//        std::cout << 0 << std::endl;
//
//    for (; i >= 0; --i)
//    {
//        std::cout << static_cast<char>(x[i] + '0');
//    }
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//#include <utility>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    std::array<std::pair<int, int>, 5001> Node;
//    int N, M;
//    std::cin >> N >> M;
//
//    int Price, Sum;
//    for (int i = 0; i < M; ++i)
//    {
//        std::cin >> Price >> Sum;
//        Node[i].first = Price;
//        Node[i].second = Sum;
//    }
//
//    std::sort(Node.begin(), Node.begin() + M, [](std::pair<int, int> &a, std::pair<int, int> &b)
//    {
//        return a.first < b.first;
//    });
//
//    int i = 0;
//    int Cost = 0;
//    while (N > 0)
//    {
//        if (Node[i].second > N)
//        {
//            Cost += N * Node[i].first;
//            break;
//        }
//
//        N -= Node[i].second;
//        Cost += Node[i].first * Node[i].second;
//        ++i;
//    }
//
//    std::cout << Cost << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int Left, Right;
//    int Sum = 0;
//
//    std::cin >> Left >> Right;
//    for (int i = Left; i <= Right; ++i)
//    {
//        int Temp = i;
//        while (Temp > 0)
//        {
//            if (Temp % 10 == 2)
//                ++Sum;
//            Temp /= 10;
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int M, N;
//
//std::array<std::array<int, 20>, 20> Fliptile{ 0 }, Opt{ 0 }, Flip{ 0 };
//
//constexpr int dx[5] = { -1, 0, 0, 0, 1 };
//constexpr int dy[5] = { 0, -1, 0, 1, 0 };
//
//int Get(int x, int y)
//{
//    int c = Fliptile[x][y];
//    for (int d = 0; d < 5; ++d)
//    {
//        auto x2 = x + dx[d], y2 = y + dy[d];
//        if (0 <= x2 && x2 < M && 0 <= y2 && y2 < N)
//        {
//            c += Flip[x2][y2];
//        }
//    }
//
//    return c % 2;
//}
//
//int Calc()
//{
//    for (int i = 1; i < M; ++i)
//    {
//        for (int j = 0; j < N; ++j)
//        {
//            if (Get(i - 1, j) == 1)
//            {
//                Flip[i][j] = 1;
//            }
//        }
//    }
//
//    for (int j = 0; j < N; ++j)
//    {
//        if (Get(M - 1, j) == 1)
//            return -1;
//    }
//
//    int Res = 0;
//    for (int i = 0; i < M; ++i)
//    {
//        for (int j = 0; j < N; ++j)
//        {
//            Res += Flip[i][j];
//        }
//    }
//
//    return Res;
//}
//
//int main()
//{
//    std::cin >> M >> N;
//    for (int i = 0; i < M; ++i)
//    {
//        for (int j = 0; j < N; ++j)
//        {
//            std::cin >> Fliptile[i][j];
//        }
//    }
//
//    int Res = -1;
//    for (int i = 0; i < 1 << N; ++i)
//    {
//        for (auto &rr : Flip)
//        {
//            for (auto &r : rr)
//                r = 0;
//        }
//
//        for (int j = 0; j < N; ++j)
//        {
//            Flip[0][N - j - 1] = i >> j & 1;
//        }
//
//        auto Sum = Calc();
//        if (Sum >= 0 && (Res < 0 || Res > Sum))
//        {
//            Res = Sum;
//            Opt = Flip;
//        }
//    }
//
//    if (Res == -1)
//    {
//        std::cout << "IMPOSSIBLE" << std::endl;
//    }
//    else
//    {
//        for (int i = 0; i < M; ++i)
//        {
//            for (int j = 0; j < N; ++j)
//            {
//                std::cout << Opt[i][j] << (j == N - 1 ? '\n' : ' ');
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string Coins;
//    std::cin >> Coins;
//
//    int Sum = 0;
//    for (auto i = Coins.size() - 1; i > 0; --i)
//    {
//        if (Coins[i] == '0' && Coins[i - 1] == '1')
//            Sum += 2;
//    }
//    if (Coins[0] == '0')
//        ++Sum;
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    std::cout << n << std::endl;
//
//    std::array<int, 101> Arr{ 0 };
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            if (i != j)
//            {
//                Arr[j] ^= 1;
//            }
//        }
//
//        for (int i = 0; i < n; ++i)
//        {
//            std::cout << Arr[i];
//        }
//        putchar('\n');
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    using ll = long long;
//    ll a, b;
//    std::cin >> a >> b;
//
//    int Tol = 0;
//    for (ll i = a; i <= b; ++i)
//    {
//        if (std::abs(i) % 4 != 2)
//            ++Tol;
//    }
//
//    std::cout << Tol << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    unsigned Num;
//    std::cin >> Num;
//    std::cout << (Num << 16 | Num >> 16) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cmath>
//#include <algorithm>
//
//int main()
//{
//    static std::array<int, 1000010> Guess{ 0 }, Score{ 0 };
//    int m, n;
//    std::cin >> m >> n;
//    Score[0] = -99999, Score[m + 1] = 99999;
//    for (int i = 1; i <= m; ++i)
//    {
//        std::cin >> Score[i];
//    }
//    for (int j = 0; j < n; ++j)
//    {
//        std::cin >> Guess[j];
//    }
//
//    std::sort(Score.begin(), Score.begin() + m + 1);
//
//    int Tol = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        int lb = 0, ub = m + 1;
//        while (ub - lb > 1)
//        {
//            auto mid = static_cast<int>((lb + ub) / 2);
//            if (Guess[i] < Score[mid])
//                ub = mid;
//            else
//                lb = mid;
//        }
//        
//        Tol += std::min(std::abs(Guess[i] - Score[lb]), std::abs(Score[ub] - Guess[i]));
//    }
//
//    std::cout << Tol << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//#include <climits>
//
//using ll = long long;
//
//ll n;
//
//template <typename T>
//inline bool Check(const T &k)
//{
//    return k * std::log10(k) < n - 1;
//}
//
//int main()
//{
//    std::cin >> n;
//
//    if (n == 1)
//    {
//        std::cout << 1 << std::endl;
//        return 0;
//    }
//
//    ll lb = 0, ub = LLONG_MAX;
//    for (int i = 0; i < 1000; ++i)
//    {
//        auto mid = static_cast<ll>((lb + ub) / 2);
//        if (Check(mid))
//            lb = mid + 1;
//        else
//            ub = mid;
//    }
//
//    if (!Check(lb))
//        std::cout << ub << std::endl;
//    else
//        std::cout << lb << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include <climits>
//
//using ll = long long;
//
//int N, C;
//std::array<ll, 100001> Cowshed{ 0 };
//
//template <typename T>
//bool Check(const T &Distance)
//{
//    int Last = 0;
//    for (int i = 0; i < C; ++i)
//    {
//        int Now = Last + 1;
//        while (Now < N && Cowshed[Now] - Cowshed[Last] < Distance)
//        {
//            ++Now;
//        }
//
//        if (Last == N)
//        {
//            return false;
//        }
//
//        Last = Now;
//    }
//
//    return true;
//}
//
//int main()
//{
//    std::cin >> N >> C;
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> Cowshed[i];
//    }
//
//    std::sort(Cowshed.begin(), Cowshed.begin() + N);
//
//    int lb = 0, ub = INT_MAX;
//    while (ub - lb > 1)
//    {
//        auto mid = static_cast<int>((lb + ub) / 2);
//        if (Check(mid))
//            lb = mid;
//        else
//            ub = mid;
//    }
//
//    std::cout << lb << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//ll N, K;
//std::array<ll, 100001> Log{ 0 };
//
//template <typename T>
//bool Check(const T &Length)
//{
//    ll Num = 0;
//    for (ll i = 0; i < N; ++i)
//    {
//        Num += static_cast<ll>(Log[i] / Length);
//    }
//
//    return Num >= K;
//}
//
//int main()
//{
//    std::cin >> N >> K;
//    for (ll i = 0; i < N; ++i)
//    {
//        std::cin >> Log[i];
//    }
//
//    ll lb = 0, ub = 999999999;
//    for (int i = 0; i < 100; ++i)
//    {
//        auto mid = static_cast<ll>(lb + (ub - lb) / 2);
//
//        if (mid == 0)
//        {
//            std::cout << 0 << std::endl;
//            return 0;
//        }
//
//        if (Check(mid))
//            lb = mid;
//        else
//            ub = mid;
//    }
//
//    std::cout << lb << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cmath>
//
//int N, K;
//std::array<double, 10001> Rope{ 0 };
//
//template <typename T>
//bool Check(const T &Length)
//{
//    int Num = 0;
//    for (int i = 0; i < N; ++i)
//    {
//        Num += static_cast<int>(Rope[i] / Length);
//    }
//
//    return Num >= K;
//}
//
//int main()
//{
//    std::cin >> N >> K;
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> Rope[i];
//    }
//
//    double lb = 0.0, ub = 9999999;
//    for (int i = 0; i < 100; ++i)
//    {
//        auto mid = (lb + ub) / 2;
//        if (Check(mid))
//            lb = mid;
//        else
//            ub = mid;
//    }
//
//    printf("%.2lf\n", std::floor(ub * 100) / 100);
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    int Num;
//    std::unordered_map<int, int> Ball;
//    for (int i = 1; i <= n; ++i)
//    {
//        std::cin >> Num;
//        Ball[Num] = i;
//    }
//
//    int Q, m;
//    std::cin >> Q;
//    while (Q--)
//    {
//        std::cin >> m;
//        std::cout << Ball[m] << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//std::array<std::array<int, 5>, 5> Lights{ 0 };
//std::array<std::array<bool, 5>, 5> Switches{ false };
//
//int Max = 99999;
//
//template <typename T>
//bool Judge(const T &Lights)
//{
//    for (int i = 1; i <= 3; ++i)
//    {
//        for (int j = 1; j <= 3; ++j)
//        {
//            if (Lights[i][j] == 0)
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//void DFS(int Now)
//{
//    if (Now > Max)
//    {
//        return;
//    }
//
//    for (int i = 1; i <= 3; ++i)
//    {
//        for (int j = 1; j <= 3; ++j)
//        {
//            if (!Switches[i][j])
//            {
//                Switches[i][j] = true;
//                Lights[i][j] ^= 1;
//                Lights[i - 1][j] ^= 1;
//                Lights[i + 1][j] ^= 1;
//                Lights[i][j - 1] ^= 1;
//                Lights[i][j + 1] ^= 1;
//
//                if (Judge(Lights))
//                {
//                    Max = std::min(Max, Now);
//                }
//
//                DFS(Now + 1);
//
//                Switches[i][j] = false;
//                Lights[i][j] ^= 1;
//                Lights[i - 1][j] ^= 1;
//                Lights[i + 1][j] ^= 1;
//                Lights[i][j - 1] ^= 1;
//                Lights[i][j + 1] ^= 1;
//            }
//        }
//    }
//}
//
//int main()
//{
//    for (int i = 1; i <= 3; ++i)
//    {
//        for (int j = 1; j <= 3; ++j)
//        {
//            std::cin >> Lights[i][j];
//        }
//    }
//
//    DFS(1);
//
//    std::cout << Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//#include <array>
//#include <algorithm>
//
//double Ans = 999999;
//int n;
//
//std::array<std::array<double, 40>, 40> Map{ 0 };
//std::array<bool, 40> Visited{ false };
//
//void DFS(int Step, double Length, int Now)
//{
//    if (Length > Ans)
//    {
//        return;
//    }
//
//    if (Step == n + 1)
//    {
//        Ans = std::min(Ans, Length);
//        return;
//    }
//
//    for (int i = 1; i <= n; ++i)
//    {
//        if (!Visited[i])
//        {
//            Visited[i] = true;
//            DFS(Step + 1, Length + Map[Now][i], i);
//            Visited[i] = false;
//        }
//    }
//
//    return;
//}
//
//int main()
//{
//    std::cin >> n;
//
//    std::array<double, 40> X, Y;
//    for (int i = 1; i <= n; ++i)
//    {
//        std::cin >> X[i] >> Y[i];
//    }
//    X[0] = Y[0] = 0;
//
//    for (int i = 0; i <= n; ++i)
//    {
//        for (int j = 0; j <= n; ++j)
//        {
//            Map[i][j] = std::sqrt((X[i] - X[j])*(X[i] - X[j]) + (Y[i] - Y[j])*(Y[i] - Y[j]));
//        }
//    }
//
//    DFS(1, 0.0, 0);
//
//    printf("%.2lf\n", Ans);
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//using ll = long long;
//
//int main()
//{
//    ll n, Height;
//    std::cin >> n >> Height;
//    std::array<ll, 20001> Cows{ 0 };
//
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> Cows[i];
//    }
//
//    std::sort(Cows.begin(), Cows.end(), [](ll a, ll b) { return a > b; });
//
//    int Sum = 0, i = 0;
//    while (Height > 0)
//    {
//        ++Sum;
//        Height -= Cows[i];
//        ++i;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int S1, S2, S3;
//    std::cin >> S1 >> S2 >> S3;
//
//    std::array<int, 90> Arr{ 0 };
//
//    for (int i = 1; i <= S1; ++i)
//    {
//        for (int j = 1; j <= S2; ++j)
//        {
//            for (int k = 1; k <= S3; ++k)
//            {
//                ++Arr[i + j + k];
//            }
//        }
//    }
//
//    int Max = 0, Res;
//    for (int i = 3; i <= 80; ++i)
//    {
//        if (Arr[i] > Max)
//        {
//            Max = Arr[i];
//            Res = i;
//        }
//    }
//
//    std::cout << Res << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string Str;
//    int n;
//    std::cin >> n;
//
//    while (n--)
//    {
//        std::cin >> Str;
//        if ((Str.back() - '0') & 1)
//        {
//            std::cout << "odd" << std::endl;
//        }
//        else
//        {
//            std::cout << "even" << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//int main()
//{
//    std::array<int, 10> Arr{ 0 };
//    ll M, N;
//    std::cin >> M >> N;
//
//    ll Temp = 0;
//    for (ll i = M; i <= N; ++i)
//    {
//        Temp = i;
//        while (Temp > 0)
//        {
//            ++Arr[Temp % 10];
//            Temp /= 10;
//        }
//    }
//
//    for (const auto &r : Arr)
//    {
//        std::cout << r << ' ';
//    }
//
//    putchar('\n');
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//ll Read()
//{
//    ll n = 0, k = 1;
//    char ch = getchar();
//    while ((ch > '9' || ch < '0') && ch != '-')
//        ch = getchar();
//
//    if (ch == '-')
//    {
//        k = -1;
//        ch = getchar();
//    }
//
//    while (ch <= '9' && ch >= '0')
//    {
//        n = n * 10 + ch - '0';
//        ch = getchar();
//    }
//
//    return n * k;
//}
//
//int main()
//{
//    ll h1, h2, m1, m2, s1, s2;
//    h1 = Read();
//    m1 = Read();
//    s1 = Read();
//    h2 = Read();
//    m2 = Read();
//    s2 = Read();
//    ll Per = Read();
//
//    std::cout << ((h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1)) * Per << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <climits>
//#include <algorithm>
//
//int main()
//{
//    std::array<int, 120> Prisoner{ 0 };
//    std::array<std::array<int, 120>, 120> DP{ 0 };
//    int TotalPrisoners, SetFreePrisoners;
//
//    std::cin >> TotalPrisoners >> SetFreePrisoners;
//    Prisoner[0] = 0;
//    Prisoner[SetFreePrisoners + 1] = TotalPrisoners + 1;
//    for (int i = 1; i <= SetFreePrisoners; ++i)
//    {
//        std::cin >> Prisoner[i];
//    }
//
//    for (int w = 2; w <= SetFreePrisoners + 1; ++w)
//    {
//        for (int i = 0; i + w <= SetFreePrisoners + 1; ++i)
//        {
//            int j = i + w, NowCost = INT_MAX;
//            for (int k = i + 1; k < j; ++k)
//            {
//                NowCost = std::min(NowCost, DP[i][k] + DP[k][j]);
//            }
//
//            DP[i][j] = NowCost + Prisoner[j] - Prisoner[i] - 2;
//        }
//    }
//
//    std::cout << DP[0][SetFreePrisoners + 1] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    long long k;
//    std::cin >> n;
//
//    while (n--)
//    {
//        std::cin >> k;
//        if (k & 1)
//        {
//            std::cout << "zs wins" << std::endl;
//        }
//        else
//        {
//            std::cout << "pb wins" << std::endl;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    int Tol = 1;
//    int Prev;
//    std::cin >> Prev;
//    --n;
//
//    int Now, Max = 1;
//    while (n--)
//    {
//        std::cin >> Now;
//        if (Now == Prev + 1)
//        {
//            ++Tol;
//            Max = std::max(Max, Tol);
//        }
//        else
//            Tol = 1;
//
//        Prev = Now;
//    }
//
//    std::cout << Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//std::array<std::array<bool, 10>, 10> Map{ false };
//std::array<std::array<int, 10>, 10> Field{ 0 };
//
//int Life = 6, Max = 99999;
//
//int n, m;
//
//template <typename T>
//void DFS(const T &x, const T &y, int Life, int Tol)
//{
//    if (x < 0 || y < 0 || x >= n || y >= m ||
//        Life == 0 ||
//        Field[x][y] == 0 ||
//        Map[x][y] == true
//       )
//    {
//        return;
//    }
//
//    if (Field[x][y] == 3)
//    {
//        Max = std::min(Max, Tol);
//        return;
//    }
//
//    if (Field[x][y] == 4)
//    {
//        Life = 6;
//    }
//
//    Map[x][y] = true;
//    DFS(x + 1, y, Life - 1, Tol + 1);
//    DFS(x - 1, y, Life - 1, Tol + 1);
//    DFS(x, y + 1, Life - 1, Tol + 1);
//    DFS(x, y - 1, Life - 1, Tol + 1);
//    Map[x][y] = false;
//
//    return;
//}
//
//int main()
//{
//    int SX, SY;
//    std::cin >> n >> m;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j)
//        {
//            std::cin >> Field[i][j];
//            if (Field[i][j] == 2)
//            {
//                SX = i;
//                SY = j;
//            }
//        }
//    }
//
//    DFS(SX, SY, 6, 0);
//
//    std::cout << (Max != 99999 ? Max : -1) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//using ll = long long;
//
//template <typename T>
//T gcd(const T &a, const T &b)
//{
//    if (b == 0)
//        return a;
//    else
//        return gcd(b, a % b);
//}
//
//int main()
//{
//    ll a, b, c;
//    std::cin >> a >> b >> c;
//    ll Max = std::max(a, std::max(b, c));
//    ll Min = std::min(a, std::min(b, c));
//    ll k = gcd(Max, Min);
//    std::cout << Min / k << '/' << Max / k << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<long long, 50> Arr;
//    Arr[0] = Arr[1] = 1;
//
//    int n;
//    std::cin >> n;
//    if (n == 1 || n == 2)
//        std::cout << "1.00" << std::endl;
//    else if (n == 0)
//        std::cout << "0.00" << std::endl;
//    else
//    {
//        for (int i = 2; i < n; ++i)
//        {
//            Arr[i] = Arr[i - 1] + Arr[i - 2];
//        }
//        std::cout << Arr[n - 1] << ".00" << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//int main()
//{
//    ll n, k;
//    std::cin >> n >> k;
//    ll Sum = 0;
//    Sum += n;
//    while (n >= k)
//    {
//        Sum += n / k;
//        n = n / k + n % k;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int k;
//    std::cin >> k;
//
//    bool Flag = true;
//    for (int a = 1; a <= 3; ++a)
//    {
//        for (int b = 0; b <= 9; ++b)
//        {
//            for (int c = 0; c <= 9; ++c)
//            {
//                for (int d = 0; d <= 9; ++d)
//                {
//                    for (int e = 0; e <= 9; ++e)
//                    {
//                        if ((a * 100 + b * 10 + c) % k == 0 &&
//                            (b * 100 + c * 10 + d) % k == 0 &&
//                            (c * 100 + d * 10 + e) % k == 0)
//                        {
//                            std::cout << a << b << c << d << e << std::endl;
//                            Flag = false;
//                        }
//                        if (a == 3 && b == 0)
//                            goto Outside;
//                    }
//                }
//            }
//        }
//    }
//
//Outside:
//    if (Flag)
//    {
//        std::cout << "No" << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//ll gcd(ll a, ll b)
//{
//    if (b == 0)
//        return a;
//    else
//        return gcd(b, a % b);
//}
//
//int main()
//{
//    int a, b, c, d;
//    scanf_s("%d/%d", &a, &b);
//    scanf_s("%d/%d", &c, &d);
//    ll k = gcd(a * c, b * d);
//    ll m = a * c / k, n = b * d / k;
//    std::cout << n << ' ' << m << std::endl;
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//using ll = long long;
//
//std::array<std::array<std::array<int, 100>, 100>, 100> M{ 0 };
//
//ll W(ll a, ll b, ll c)
//{
//
//    if (a <= 0 || b <= 0 || c <= 0)
//        return 1;
//    else if (a > 20 || b > 20 || c > 20)
//        return W(20, 20, 20);
//    if (M[a][b][c])
//        return M[a][b][c];
//    else if (a < b && b < c)
//        return M[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
//    else
//        return M[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
//}
//
//int main()
//{
//    ll a, b, c;
//    std::cin >> a >> b >> c;
//    while (a != -1 || b != -1 || c != -1)
//    {
//        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << W(a, b, c) << std::endl;
//        std::cin >> a >> b >> c;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<std::array<bool, 10>, 10> Maze{ false };
//
//int Tol = 0;
//
//int N, M, T;
//int SX, SY, FX, FY;
//
//template <typename T>
//void DFS(const T &x, const T &y)
//{
//    if (x == FX && y == FY && Maze[x][y])
//    {
//        ++Tol;
//        return;
//    }
//    else
//    {
//        if (x >= 1 && x <= N && y >= 1 && y <= M && Maze[x][y])
//        {
//            Maze[x][y] = false;
//            DFS(x - 1, y);
//            DFS(x + 1, y);
//            DFS(x, y - 1);
//            DFS(x, y + 1);
//            Maze[x][y] = true;
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> N >> M >> T;
//    for (int i = 1; i <= N; ++i)
//    {
//        for (int j = 1; j <= M; ++j)
//        {
//            Maze[i][j] = true;
//        }
//    }
//
//    std::cin >> SX >> SY >> FX >> FY;
//    
//    int TX, TY;
//    while (T--)
//    {
//        std::cin >> TX >> TY;
//        Maze[TX][TY] = false;
//    }
//
//    DFS(SX, SY);
//
//    std::cout << Tol << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int main()
//{
//    int N;
//    std::cin >> N;
//    std::array<double, 101> Rate, Mark, Dollor;
//    for (int i = 1; i <= N; ++i)
//    {
//        std::cin >> Rate[i];
//    }
//
//    Dollor[0] = 100.0;
//    Mark[0] = 0.0;
//    for (int i = 1; i <= N; ++i)
//    {
//        Dollor[i] = std::max(Dollor[i - 1], Mark[i - 1] / Rate[i] * 100);
//        Mark[i] = std::max(Mark[i - 1], Dollor[i - 1] / 100 * Rate[i]);
//    }
//
//    printf("%.2lf\n", Dollor[N]);
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//using ll = long long;
//
//std::array<ll, 1000009> DP{ 0 }, Win{ 0 }, Lose{ 0 }, Use{ 0 };
//
//int main()
//{
//    ll N, W;
//    std::cin >> N >> W;
//    for (ll i = 0; i < N; ++i)
//    {
//        std::cin >> Lose[i] >> Win[i] >> Use[i];
//    }
//
//    for (ll i = 0; i < N; ++i)
//    {
//        for (ll j = W; j >= 0; --j)
//        {
//            if (j >= Use[i])
//            {
//                DP[j] = std::max(DP[j] + Lose[i], DP[j - Use[i]] + Win[i]);
//            }
//            else
//            {
//                DP[j] = DP[j] + Lose[i];
//            }
//        }
//    }
//
//    std::cout << DP[W] * 5 << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    
//    int Prev = 0, Max = 1, Now, Temp = 1;
//    while (n--)
//    {
//        std::cin >> Now;
//        if (Now > Prev)
//        {
//            ++Temp;
//            if (Temp > Max)
//                Max = Temp;
//        }
//        else
//        {
//            Temp = 1;
//        }
//
//        Prev = Now;
//    }
//
//    std::cout << Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//std::array<int, 5001> X{ 0 };
//
//int main()
//{
//    int L, N;
//    std::cin >> L >> N;
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> X[i];
//    }
//
//    int MaxT = 0, MinT = 0;
//    for (int i = 0; i < N; ++i)
//    {
//        MaxT = std::max(MaxT, std::max(X[i], L - X[i] + 1));
//        MinT = std::max(MinT, std::min(X[i], L - X[i] + 1));
//    }
//
//    std::cout << MinT << ' ' << MaxT << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//bool IsPrime[20001];
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    std::fill(std::begin(IsPrime), std::end(IsPrime), true);
//    IsPrime[0] = IsPrime[1] = false;
//    for (int i = 2; i <= n; ++i)
//    {
//        if (IsPrime[i])
//        {
//            for (int j = 2 * i; j <= n; j += i)
//            {
//                IsPrime[j] = false;
//            }
//        }
//    }
//
//    for (int i = 2; i <= n; ++i)
//    {
//        if (IsPrime[i])
//        {
//            for (int j = i; j <= n; ++j)
//            {
//                if (IsPrime[j])
//                {
//                    for (int k = j; k <= n; ++k)
//                    {
//                        if (IsPrime[n - i - j])
//                        {
//                            std::cout << i << ' ' << j << ' ' << n - i - j << std::endl;
//                            goto Outside;
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//Outside:
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cmath>
//
//std::array<bool, 10001> IsPrime;
//
//int main()
//{
//    int N;
//    std::cin >> N;
//
//    std::fill(IsPrime.begin(), IsPrime.end(), true);
//    IsPrime[0] = IsPrime[1] = false;
//    for (int i = 2; i <= N; ++i)
//    {
//        if (IsPrime[i])
//        {
//            for (int j = 2 * i; j <= N; j += i)
//            {
//                IsPrime[j] = false;
//            }
//        }
//    }
//
//    for (int i = 2; i <= N; i += 2)
//    {
//        for (int p = 2; p <= i; ++p)
//        {
//            if (IsPrime[p] && IsPrime[i - p])
//            {
//                std::cout << i << '=' << p << '+' << i - p << std::endl;
//                break;
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<bool, 10000001> IsPrime;
//
//using ll = long long;
//
//int main()
//{
//    ll N, M;
//    std::cin >> N >> M;
//
//    std::fill(IsPrime.begin(), IsPrime.end(), true);
//    IsPrime[0] = IsPrime[1] = false;
//    for (ll i = 2; i <= N; ++i)
//    {
//        if (IsPrime[i])
//        {
//            for (ll j = 2 * i; j <= N; j += i)
//            {
//                IsPrime[j] = false;
//            }
//        }
//    }
//
//    ll Temp;
//    while (M--)
//    {
//        std::cin >> Temp;
//        std::cout << (IsPrime[Temp] ? "Yes" : "No") << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//
//using ll = long long;
//
//template <typename T>
//ll ModPow(T x, T n, T &mod)
//{
//    ll Res = 1;
//    while (n > 0)
//    {
//        if (n & 1)
//            Res =  Res * x % mod;
//        x = x * x % mod;
//        n >>= 1;
//    }
//    return Res;
//}
//
//int main()
//{
//    ll b, p, k;
//    std::cin >> b >> p >> k;
//    std::cout << b << '^' << p << " mod " << k << '=' << ModPow(b, p, k) << std::endl;
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<std::array<char, 101>, 101> Arr;
//
//int M, N;
//
//template <typename T>
//void DFS(const T &x, const T &y)
//{
//    if (x >= 0 && y >= 0 && x < M && y < N && Arr[x][y] != '0')
//    {
//        Arr[x][y] = '0';
//        DFS(x + 1, y);
//        DFS(x - 1, y);
//        DFS(x, y + 1);
//        DFS(x, y - 1);
//    }
//
//    return;
//}
//
//int main()
//{
//    std::cin >> M >> N;
//    for (int i = 0; i < M; ++i)
//    {
//        for (int j = 0; j < N; ++j)
//        {
//            std::cin >> Arr[i][j];
//        }
//    }
//
//    int Tol = 0;
//    for (int i = 0; i < M; ++i)
//    {
//        for (int j = 0; j < N; ++j)
//        {
//            if (Arr[i][j] != '0')
//            {
//                ++Tol;
//                DFS(i, j);
//            }
//        }
//    }
//
//    std::cout << Tol << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//
//std::array<std::array<char, 101>, 101> Arr;
//
//int M, N;
//
//template <typename T>
//void DFS(const T &i, const T &j)
//{
//    if (i < 1 || j < 1 || i > M || j > N || Arr[i][j] == '0')
//        return;
//    Arr[i][j] = '0';
//    DFS(i - 1, j);
//    DFS(i + 1, j);
//    DFS(i, j - 1);
//    DFS(i, j + 1);
//}
//
//int main()
//{
//    std::cin >> M >> N;
//    for (int i = 1; i <= M; ++i)
//    {
//        for (int j = 1; j <= N; ++j)
//        {
//            std::cin >> Arr[i][j];
//        }
//    }
//
//    int Tol = 0;
//    for (int i = 1; i <= M; ++i)
//    {
//        for (int j = 1; j <= N; ++j)
//        {
//            if (Arr[i][j] != '0')
//            {
//                ++Tol;
//                DFS(i, j);
//            }
//        }
//    }
//
//    std::cout << Tol << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//std::array<std::array<int, 1001>, 1001> DP{ 0 };
//
//int main()
//{
//    int M;
//    std::cin >> M;
//    for (int i = 1; i <= M; ++i)
//    {
//        for (int j = 1; j <= i; ++j)
//        {
//            std::cin >> DP[i][j];
//            DP[i][j] += std::max(DP[i - 1][j], DP[i - 1][j - 1]);
//        }
//    }
//
//    int Max = 0; 
//    for (int i = 1; i <= M; ++i)
//    {
//        if (DP[M][i] > Max)
//            Max = DP[M][i];
//    }
//
//    std::cout << Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//template <typename T>
//int F(const T &Apples, const T &Plates)
//{
//    if (Apples < Plates)
//        return F(Apples, Apples);
//    if (Apples == 0)
//        return 1;
//    if (Plates <= 0)
//        return 0;
//
//    return F(Apples, Plates - 1) + F(Apples - Plates, Plates);
//}
//
//int main()
//{
//    int T, M, N;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> M >> N;
//        std::cout << F(M, N) << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//#include <string>
//
//std::unordered_map<std::string, std::string> Par;
//std::unordered_map<std::string, int> Rank;
//
//template <typename T>
//std::string Find(const T &x)
//{
//    if (Par[x] == x)
//        return x;
//    else
//        return Par[x] = Find(Par[x]);
//}
//
//template <typename T>
//void Unite(T &x, T &y)
//{
//    x = Find(x);
//    y = Find(y);
//    if (x == y)
//        return;
//
//    if (Rank[x] < Rank[y])
//    {
//        Par[x] = y;
//    }
//    else
//    {
//        Par[y] = x;
//        if (Rank[x] == Rank[y])
//            ++Rank[x];
//    }
//}
//
//template <typename T>
//bool IsSame(const T &x, const T &y)
//{
//    return Find(x) == Find(y);
//}
//
//int main()
//{
//    int N, M, K;
//    std::cin >> N >> M;
//    std::string Player;
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> Player;
//        Par[Player] = Player;
//        Rank[Player] = 0;
//    }
//
//    std::string Player1, Player2;
//    for (int i = 0; i < M; ++i)
//    {
//        std::cin >> Player1 >> Player2;
//        Unite(Player1, Player2);
//    }
//    
//    std::cin >> K;
//    for (int i = 0; i < K; ++i)
//    {
//        std::cin >> Player1 >> Player2;
//        std::cout << (IsSame(Player1, Player2) ? "Yes." : "No.") << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<std::array<int, 1001>, 1001> Cost{ 0 };
//std::array<int, 1001> D;
//
//int main()
//{
//    constexpr int INF = 99999;
//    std::fill(D.begin(), D.end(), INF);
//
//    int V, E;
//    std::cin >> V >> E;
//    int From, To, S;
//    for (int i = 1; i <= E; ++i)
//    {
//        std::cin >> From >> To >> S;
//        Cost[From][To] = S;
//    }
//
//    D[1] = 1;
//    for (int i = 1; i <= V; ++i)
//    {
//        for (int j = 2; j <= V; ++j)
//        {
//            int Temp = D[i] * Cost[i][j];
//            if (Cost[i][j] != 0 && D[j] > Temp)
//            {
//                D[j] = Temp;
//            }
//        }
//    }
//
//    std::cout << D[V] % 9987<< std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//std::array<int, 10001> Past{ 0 };
//std::array<std::array<int, 10001>, 10001> DP{ 0 };
//
//int main()
//{
//    int N, M;
//    std::cin >> N >> M;
//    for (int i = 1; i <= M; ++i)
//    {
//        std::cin >> Past[i];
//    }
//
//    for (int i = 1; i <= N; ++i)
//    {
//        for (int j = 1; j <= N; ++j)
//        {
//            std::cin >> DP[i][j];
//        }
//    }
//
//    for (int k = 1; k <= N; ++k)
//    {
//        for (int i = 1; i <= N; ++i)
//        {
//            for (int j = 1; j <= N; ++j)
//            {
//                DP[i][j] = std::min(DP[i][j], DP[i][k] + DP[k][j]);
//            }
//        }
//    }
//
//    int Tol = 0, Now = 1;
//    for (int i = 1; i <= M; ++i)
//    {
//        Tol += DP[Now][Past[i]];
//        Now = Past[i];
//    }
//
//    std::cout << Tol << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//std::array<std::array<int, 201>, 201> DP{ 0 };
//
//int main()
//{
//    int N;
//    std::cin >> N;
//    for (int i = 0; i < N - 1; ++i)
//    {
//        for (int j = i + 1; j < N; ++j)
//            std::cin >> DP[i][j];
//    }
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < i; ++j)
//        {
//            if (i != j)
//                DP[i][j] = 99999;
//        }
//    }
//
//    for (int k = 0; k < N; ++k)
//    {
//        for (int i = 0; i < N; ++i)
//        {
//            for (int j = 0; j < N; ++j)
//            {
//                DP[i][j] = std::min(DP[i][j], DP[i][k] + DP[k][j]);
//            }
//        }
//    }
//
//    std::cout << DP[0][N - 1] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int Par[1001] = { 0 };
//
//template <typename T>
//int Find(const T &x)
//{
//    if (Par[x] == x)
//        return x;
//    else
//        return Par[x] = Find(Par[x]);
//}
//
//template <typename T>
//void Unite(T &x, T &y)
//{
//    Par[Find(x)] = Find(y);
//}
//
//template <typename T>
//bool IsSame(const T &x, const T &y)
//{
//    return Find(x) == Find(y);
//}
//
//int main()
//{
//    int N, M;
//
//    std::cin >> N;
//    while (N != 0)
//    {
//        std::cin >> M;
//        for (auto &r : Par)
//            r = 0;
//        for (int i = 0; i < N; ++i)
//        {
//            Par[i] = i;
//        }
//
//        int X, Y;
//        while (M--)
//        {
//            std::cin >> X >> Y;
//            Unite(X, Y);
//        }
//
//        int Tol = 0;
//        for (int i = 0; i < N; ++i)
//        {
//            for (int j = i + 1; j < N; ++j)
//            {
//                if (!IsSame(i, j))
//                {
//                    Unite(i, j);
//                    ++Tol;
//                }
//            }
//        }
//        std::cout << Tol << std::endl;
//        std::cin >> N;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 5001> Par{ 0 }, Rank{ 0 };
//
//template <typename T>
//int Find(const T &x)
//{
//    if (Par[x] == x)
//        return x;
//    else
//        return Par[x] = Find(Par[x]);
//}
//
//template <typename T>
//void Unite(T &x, T &y)
//{
//    x = Find(x);
//    y = Find(y);
//    if (x == y)
//        return;
//
//    if (Rank[x] < Rank[y])
//    {
//        Par[x] = y;
//    }
//    else
//    {
//        Par[y] = x;
//        if (Rank[x] == Rank[y])
//            ++Rank[x];
//    }
//}
//
//template <typename T>
//void IsSame(const T &x, const T &y)
//{
//    if (Find(x) == Find(y))
//        std::cout << "Yes" << std::endl;
//    else
//        std::cout << "No" << std::endl;
//}
//
//int main()
//{
//    int N, M, P;
//    std::cin >> N >> M >> P;
//    for (int i = 0; i < N; ++i)
//    {
//        Par[i] = i;
//        Rank[i] = 0;
//    }
//
//    int X, Y;
//    while (M--)
//    {
//        std::cin >> X >> Y;
//        Unite(X, Y);
//    }
//
//    while (P--)
//    {
//        std::cin >> X >> Y;
//        IsSame(X, Y);
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 100001> Par{ 0 }, Rank{ 0 };
//
//template <typename T>
//int Find(const T &x)
//{
//    if (Par[x] == x)
//        return x;
//    else
//        return Par[x] = Find(Par[x]);
//}
//
//template <typename T>
//void Unite(T &x, T &y)
//{
//    x = Find(x);
//    y = Find(y);
//    if (x == y)
//        return;
//
//    if (Rank[x] < Rank[y])
//    {
//        Par[x] = y;
//    }
//    else
//    {
//        Par[y] = x;
//        if (Rank[x] == Rank[y])
//            ++Rank[x];
//    }
//}
//
//template <typename T>
//void IsSame(const T &x, const T &y)
//{
//    if (Find(x) == Find(y))
//        std::cout << 'Y' << std::endl;
//    else
//        std::cout << 'N' << std::endl;
//}
//
//int main()
//{
//    int N, M;
//    std::cin >> N >> M;
//    for (int i = 0; i < N; ++i)
//    {
//        Par[i] = i;
//        Rank[i] = 0;
//    }
//
//    int Z, X, Y;
//    while (M--)
//    {
//        std::cin >> Z >> X >> Y;
//        switch (Z)
//        {
//        case 1:
//            Unite(X, Y);
//            break;
//
//        case 2:
//            IsSame(X, Y);
//            break;
//
//        default:
//            break;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 100001> Stair{ 0 };
//int N, K;
//
//template <typename T>
//int DFS(const T &n)
//{
//    if (Stair[n])
//        return Stair[n];
//    if (n == 0)
//        return 1;
//    else if (n == 1)
//        return 1;
//    else
//    {
//        int Tol = 0;
//        for (int i = 1; i <= K; ++i)
//        {
//            if (i <= n)
//                Tol = (DFS(n - i) + Tol) % 100003;
//        }
//        Stair[n] = Tol;
//        return Tol;
//    }
//}
//
//int main()
//{
//    std::cin >> N >> K;
//
//    Stair[0] = 1;
//    Stair[1] = 1;
//
//    std::cout << DFS(N) << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int N;
//    long long Sum = 0;
//    std::cin >> N;
//
//    int Now = 1;
//    while (N > 0)
//    {
//        Sum += Now * Now;
//        N -= Now;
//        ++Now;
//
//        if (N < Now)
//        {
//            Sum += Now * N;
//            break;
//        }
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int N, M;
//    std::cin >> N >> M;
//
//    int Rectangle = 0, Square = 0;
//    for (int i = 1; i <= N; ++i)
//    {
//        for (int j = 1; j <= M; ++j)
//        {
//            if (i == j)
//                Square += (N - i + 1) * (M - j + 1);
//            else
//                Rectangle += (N - i + 1) * (M - j + 1);
//        }
//    }
//
//    std::cout << Square << ' ' << Rectangle << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int Min = 9999999;
//    int Num, Price, Tol;
//
//    std::cin >> Tol;
//    
//    int Temp;
//    for (int i = 0; i < 3; ++i)
//    {
//        std::cin >> Num >> Price;
//        if (Tol % Num == 0)
//        {
//            Temp = Tol / Num * Price;
//            if (Temp < Min)
//                Min = Temp;
//        }
//        else
//        {
//            Temp = (Tol / Num + 1) * Price;
//            if (Temp < Min)
//                Min = Temp;
//        }
//    }
//
//    std::cout << Min << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<std::array<char, 100>, 100> Field{ 0 };
//
//int N, M;
//
//template <typename T>
//void DFS(const T &i, const T &j)
//{
//    Field[i][j] = '.';
//
//    for (int dx = -1; dx <= 1; ++dx)
//    {
//        for (int dy = -1; dy <= 1; ++dy)
//        {
//            int x = i + dx;
//            int y = j + dy;
//
//            if (x >= 0 && x < N && y >= 0 && y < M && Field[x][y] == 'W')
//            {
//                DFS(x, y);
//            }
//        }
//    }
//
//    return;
//}
//
//int main()
//{
//    std::cin >> N >> M;
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < M; ++j)
//        {
//            std::cin >> Field[i][j];
//        }
//    }
//
//    int Tol = 0;
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < M; ++j)
//        {
//            if (Field[i][j] == 'W')
//            {
//                DFS(i, j);
//                ++Tol;
//            }
//        }
//    }
//
//    std::cout << Tol << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//std::array<int, 20001> V{ 0 };
//
//int Max = 0;
//int M, N;
//
//void DFS(int n, int m)
//{
//    if (m > M)
//        return;
//
//    if (n == N + 1)
//    {
//        if (m > Max)
//        {
//            Max = m;
//        }
//        return;
//    }
//
//    DFS(n + 1, m);
//    DFS(n + 1, m + V[n]);
//}
//
//int main()
//{
//    std::cin >> M >> N;
//
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> V[i];
//    }
//
//    DFS(0, 0);
//
//    std::cout << M - Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//std::array<int, 200001> DP{ 0 }, V{ 0 };
//
//int main()
//{
//    int N, W;
//    std::cin >> W >> N;
//
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> V[i];
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = W; j >= V[i]; --j)
//        {
//            DP[j] = std::max(DP[j], DP[j - V[i]] + V[i]);
//        }
//    }
//
//    std::cout << W - DP[W] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <functional>
//
//int main()
//{
//    int N;
//    std::cin >> N;
//
//    std::priority_queue<int, std::vector<int>, std::greater<int>> Fruit;
//    int Temp;
//    while (N--)
//    {
//        std::cin >> Temp;
//        Fruit.push(Temp);
//    }
//
//    long long Tol = 0;
//    int L1, L2;
//    while (Fruit.size() != 1)
//    {
//        L1 = Fruit.top();
//        Fruit.pop();
//
//        L2 = Fruit.top();
//        Fruit.pop();
//
//        Tol += L1 + L2;
//        Fruit.push(L1 + L2);
//    }
//
//    std::cout << Tol << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <cmath>
//
//std::array<int, 21> Arr{ 0 };
//std::array<bool, 21> Used{ false };
//
//int N, K;
//int Sum = 0;
//
//template <typename T>
//bool IsPrime(const T &j)
//{
//    if (j == 1 || j == 2)
//        return true;
//    else
//    {
//        for (int i = 2; i <= std::sqrt(j); ++i)
//        {
//            if (j % i == 0)
//                return false;
//        }
//        return true;
//    }
//}
//
//template <typename T>
//void DFS(const T &P, const T &Now, const T &Tol)
//{
//    if (Now == K)
//    {
//        if (IsPrime(Tol))
//        {
//            ++Sum;
//            return;
//        }
//    }
//    else
//    {
//        for (int i = 1; i <= N; ++i)
//        {
//            if (!Used[i] && i > P)
//            {
//                Used[i] = true;
//                DFS(i, Now + 1, Tol + Arr[i]);
//                Used[i] = false;
//            }
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> N >> K;
//    for (int i = 1; i <= N; ++i)
//    {
//        std::cin >> Arr[i];
//    }
//
//    DFS(0, 0, 0);
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <iomanip>
//
//std::array<int, 10> Arr{ 0 };
//std::array<bool, 10> Used{ false };
//int n;
//
//void DFS(int Now)
//{
//    if (Now == n + 1)
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            std::cout << std::setw(5) << Arr[i];
//        }
//        std::cout << std::endl;
//    }
//    else
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            if (!Used[i])
//            {
//                Arr[Now] = i;
//                Used[i] = true;
//                DFS(Now + 1);
//                Used[i] = false;
//            }
//        }
//    }
//}
//
//int main()
//{
//    std::cin >> n;
//    for (int i = 1; i <= n; ++i)
//    {
//        Arr[i] = i;
//    }
//
//    DFS(1);
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iomanip>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    std::vector<int> V;
//    for (int i = 1; i <= n; ++i)
//        V.push_back(i);
//
//    do
//    {
//        for (const auto &r : V)
//        {
//            std::cout << std::setw(5) << r;
//        }
//        std::cout << std::endl;
//    } while (std::next_permutation(V.begin(), V.end()));
//
//    return 0;
//}
//#include <iostream>
//#include <bitset>
//#include <array>
//
//int main()
//{
//    std::bitset<1001> Tol{ 0 };
//    std::array<int, 6> A;
//    for (int i = 0; i < 6; ++i)
//    {
//        std::cin >> A[i];
//    }
//
//    for (int a = 0; a <= A[0]; ++a)
//    {
//        for (int b = 0; b <= A[1]; ++b)
//        {
//            for (int c = 0; c <= A[2]; ++c)
//            {
//                for (int d = 0; d <= A[3]; ++d)
//                {
//                    for (int e = 0; e <= A[4]; ++e)
//                    {
//                        for (int f = 0; f <= A[5]; ++f)
//                        {
//                            int Now = a + b * 2 + c * 3 + d * 5 + e * 10 + f * 20;
//                            if (!Tol[Now])
//                                Tol[Now] = 1;
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    std::cout << "Total=" << Tol.count() - 1 << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int Max = -99999;
//int V, M, N;
//std::array<int, 501> A{ 0 }, B{ 0 }, C{ 0 };
//
//void DFS(int Step, int a, int b, int c)
//{
//    if (a > V || b > M)
//        return;
//    if (Step == N + 1)
//    {
//        Max = std::max(Max, c);
//        return;
//    }
//
//    DFS(Step + 1, a, b, c);
//    DFS(Step + 1, a + A[Step], b + B[Step], c + C[Step]);
//}
//
//int main()
//{
//    std::cin >> V >> M >> N;
//
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> A[i] >> B[i] >> C[i];
//    }
//
//    DFS(0, 0, 0, 0);
//
//    std::cout << Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    std::array<std::array<int, 501>, 501> DP{ 0 };
//    std::array<int, 501> A{ 0 }, B{ 0 }, C{ 0 };
//    int V, M, N;
//    std::cin >> V >> M >> N;
//
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> A[i] >> B[i] >> C[i];
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = V; j >= A[i]; --j)
//        {
//            for (int l = M; l >= B[i]; --l)
//            {
//                DP[j][l] = std::max(DP[j][l], DP[j - A[i]][l - B[i]] + C[i]);
//            }
//        }
//    }
//
//    std::cout << DP[V][M] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int Max = -99999;
//int N, M, X;
//int A[1001] = { 0 };
//int B[1001] = { 0 };
//int C[1001] = { 0 };
//
//void DFS(int i, int a, int b, int c)
//{
//    if (b > M || c > X)
//    {
//        return;
//    }
//
//    if (i == N + 1)
//    {
//        Max = std::max(Max, a);
//        return;
//    }
//
//    DFS(i + 1, a + A[i], b + B[i], c + C[i]);
//    DFS(i + 1, a, b, c);
//}
//
//int main()
//{
//    std::cin >> N >> M >> X;
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> A[i] >> B[i] >> C[i];
//    }
//
//    DFS(0, 0, 0, 0);
//
//    std::cout << Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
////std::array<std::array<int, 1001>, 1001> DP{ 0 };
////std::array<int, 1001> A{ 0 }, B{ 0 }, C{ 0 };
//
//int DP[1001][1001] = { 0 };
//int A[1001] = { 0 }, B[1001] = { 0 }, C[1001] = { 0 };
//
//int main()
//{
//    int N, M, X;
//
//    std::cin >> N >> M >> X;
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> A[i] >> B[i] >> C[i];
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = M; j >= B[i]; --j)
//        {
//            for (int k = X; k >= C[i]; --k)
//            {
//                DP[j][k] = std::max(DP[j][k], DP[j - B[i]][k - C[i]] + A[i]);
//            }
//        }
//    }
//
//    std::cout << DP[M][X] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    int Max = -99999, Tol = 0;
//    int Temp;
//    while (n--)
//    {
//        std::cin >> Temp;
//        Tol += Temp;
//
//        if (Tol > Max)
//            Max = Tol;
//
//        if (Tol < 0)
//            Tol = 0;
//    }
//
//    std::cout << Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int A[200001] = { 0 }, DP[200001] = { 0 };
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    //std::array<int, 200001> A{ 0 }, DP{ 0 };
//    for (int i = 1; i <= n; ++i)
//    {
//        std::cin >> A[i];
//    }
//
//    int Max = 0;
//    for (int i = 1; i <= n; ++i)
//    {
//        if (DP[i - 1] > 0)
//        {
//            DP[i] = DP[i - 1] + A[i];
//        }
//        else
//        {
//            DP[i] = A[i];
//        }
//
//        if (DP[i] > Max)
//            Max = DP[i];
//
//        if (DP[i] < 0)
//            DP[i] = 0;
//    }
//
//    std::cout << Max << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    int M, N;
//    std::cin >> M >> N;
//
//    std::array<int, 1001> DP{ 0 }, w{ 0 }, v{ 0 };
//
//    int i = 0;
//    while (i < N)
//    {
//        std::cin >> w[i] >> v[i];
//        ++i;
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = M; j >= w[i]; --j)
//        {
//            DP[j] = std::max(DP[j], DP[j - w[i]] + v[i]);
//        }
//    }
//
//    std::cout << DP[M] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int main()
//{
//    int W, N;
//    std::cin >> W >> N;
//
//    int v[50005] = { 0 }, DP[50005] = { 0 };
//    //std::array<int, 50001> v{ 0 }, DP{ 0 };
//    int i = 0;
//    while (i < N)
//    {
//        std::cin >> v[i];
//        ++i;
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = W; j >= v[i]; --j)
//        {
//            DP[j] = std::max(DP[j], DP[j - v[i]] + v[i]);
//        }
//        
//        if (DP[W] == W)
//        {
//            std::cout << DP[W] << std::endl;
//            return 0;
//        }
//    }
//
//    std::cout << DP[W] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int main()
//{
//    int M, N;
//    std::cin >> M >> N;
//
//    //std::array<int, 10001> W{ 0 }, V{ 0 }, DP{ 0 };
//    int W[10001] = { 0 }, V[10001] = { 0 }, DP[10001] = { 0 };
//    int i = 0;
//    while (i < N)
//    {
//        std::cin >> V[i] >> W[i];
//        ++i;
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = W[i]; j <= M; ++j)
//        {
//            DP[j] = std::max(DP[j], DP[j - W[i]] + V[i]);
//        }
//    }
//
//    std::cout << DP[M] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    int H, N;
//    std::array<int, 45001> DP{ 0 };
//    std::array<int, 501> W{ 0 };
//
//    std::cin >> H >> N;
//    int i = 0;
//    while (i < N)
//    {
//        std::cin >> W[i];
//        ++i;
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = H; j >= W[i]; --j)
//        {
//            DP[j] = std::max(DP[j], DP[j - W[i]] + W[i]);
//        }
//    }
//
//    std::cout << DP[H] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    //std::array<int, 12881> DP{ 0 };
//    //std::array<int, 12881> W{ 0 }, V{ 0 };
//    int DP[12881] = { 0 };
//    int W[12881] = { 0 }, V[12881] = { 0 };
//    int N, M;
//    std::cin >> N >> M;
//    int i = 0;
//
//    while (i < N)
//    {
//        std::cin >> W[i] >> V[i];
//        ++i;
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = M; j >= W[i]; --j)
//        {
//            DP[j] = std::max(DP[j], DP[j - W[i]] + V[i]);
//        }
//    }
//
//    std::cout << DP[M] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    int N, M;
//    std::cin >> N >> M;
//    int i = 0;
//
//    std::array<int, 1000> W{ 0 }, V{ 0 };
//    while (i < N)
//    {
//        std::cin >> W[i] >> V[i];
//        ++i;
//    }
//
//    std::array<std::array<int, 1000>, 1000> DP{ 0 };
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j <= M; ++j)
//        {
//            if (j < W[i])
//                DP[i + 1][j] = DP[i][j];
//            else
//                DP[i + 1][j] = std::max(DP[i][j], DP[i][j - W[i]] + V[i]);
//        }
//    }
//
//    std::cout << DP[N][M] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//#include <string>
//
//int main()
//{
//    int n, m;
//    std::unordered_map<std::string, int> Master;
//
//    std::string Temp;
//    std::cin >> n >> m;
//    std::getline(std::cin, Temp);
//
//    if (n == 1 && m == 1)
//    {
//        std::getline(std::cin, Temp);
//        std::cout << 1 << std::endl;
//        return 0;
//    }
//
//    while (n--)
//    {
//        std::getline(std::cin, Temp);
//        Master[Temp] = 0;
//    }
//
//    while (m--)
//    {
//        std::getline(std::cin, Temp);
//        if (Master.find(Temp) != Master.end())
//            ++Master[Temp];
//    }
//
//    int Total = 0;;
//    for (const auto &r : Master)
//    {
//        Total += r.second;
//    }
//
//    std::cout << Total << std::endl;
//    
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    int n;
//    std::string X, Z;
//    std::cin >> n >> X >> Z;
//
//    bool Flag = true;
//    for (int i = 0; i < n; ++i)
//    {
//        if (Z[i] > X[i])
//        {
//            std::cout << -1 << std::endl;
//            Flag = false;
//            break;
//        }
//    }
//
//    if (Flag)
//    {
//        std::cout << Z << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    long long N;
//    std::cin >> N;
//
//    for (long long i = 2; i <= std::sqrt(N); ++i)
//    {
//        if (N % i == 0)
//        {
//            std::cout << N / i << std::endl;
//            break;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//template <typename T>
//bool IsPrime(const T &n)
//{
//    if (n == 1 || n == 2)
//        return true;
//    else
//    {
//        for (T i = 2; i <= std::sqrt(n); ++i)
//        {
//            if (n % i == 0)
//                return false;
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//    long long N;
//    std::cin >> N;
//    for (long long n = N; n >= std::sqrt(N); --n)
//    {
//        if (IsPrime(n) && N % n == 0)
//        {
//            std::cout << n << std::endl;
//            break;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    long long X, N;
//    std::cin >> X >> N;
//
//    long long Sum = 1;
//    while (N--)
//    {
//        Sum += Sum * X;
//    }
//
//    std::cout << Sum << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int i = 0;
//    std::array<int, 1000> Nums;
//    do
//    {
//        std::cin >> Nums[i];
//        ++i;
//    } while (Nums[i - 1] != 0);
//    for (int p = i - 2; p >= 0; --p)
//        std::cout << Nums[p] << ' ';
//    std::cout << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    int n; 
//    std::cin >> n;
//    std::string PW;
//    std::cin >> PW;
//
//    for (auto &r : PW)
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            ++r;
//            if (r > 'z')
//                r = 'a';
//        }
//    }
//
//    std::cout << PW << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<int, 101> Fish{ 0 }, Sum{ 0 };
//
//    int t;
//    std::cin >> t;
//    for (int i = 0; i < t; ++i)
//        std::cin >> Fish[i];
//
//    for (int n = 1; n < t; ++n)
//    {
//        for (int Now = 0; Now < n; ++Now)
//        {
//            if (Fish[n] > Fish[Now])
//                ++Sum[n];
//        }
//    }
//
//    for (int i = 0; i < t; ++i)
//        std::cout << Sum[i] << ' ';
//    std::cout << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <bitset>
//
//int main()
//{
//    std::bitset<10001> Trees;
//    int L, M;
//    std::cin >> L >> M;
//
//    for (int i = 0; i <= L; ++i)
//        Trees[i] = 1;
//
//    int P, Q;
//    while (M--)
//    {
//        std::cin >> P >> Q;
//        for (int i = P; i <= Q; ++i)
//            Trees.reset(i);
//    }
//
//    std::cout << Trees.count() << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int Count(unsigned i)
//{
//    if (i == 1)
//        return 1;
//    else
//        return (i & 1) + Count(i >> 1);
//}
//
//int main()
//{
//    std::cout << Count(33) << std::endl;
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//void Reverse(const std::string &Str)
//{
//    long long Temp = std::stoi(Str);
//    if (Temp < 0)
//    {
//        std::cout << '-';
//        Temp = -Temp;
//    }
//    else if (Temp == 0)
//    {
//        std::cout << 0;
//        return;
//    }
//
//    while (Temp % 10 == 0)
//        Temp /= 10;
//
//    while (Temp > 0)
//    {
//        std::cout << Temp % 10;
//        Temp /= 10;
//    }
//}
//
//int main()
//{
//    std::string Str;
//    std::cin >> Str;
//    auto Pos1 = Str.find('%');
//    auto Pos2 = Str.find('.');
//    auto Pos3 = Str.find('/');
//
//    if (Pos1 != std::string::npos)
//    {
//        Reverse(Str.substr(0, Pos1));
//        std::cout << '%' << std::endl;
//    }
//    else if (Pos2 != std::string::npos)
//    {
//        Reverse(Str.substr(0, Pos2));
//        std::cout << '.';
//        Reverse(Str.substr(Pos2 + 1));
//    }
//    else if (Pos3 != std::string::npos)
//    {
//        Reverse(Str.substr(0, Pos3));
//        std::cout << '/';
//        Reverse(Str.substr(Pos3 + 1));
//    }
//    else
//        Reverse(Str);
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <string>
//
//template <typename N, typename M>
//int Max(const N &n, const M &m)
//{
//    int max = 0;
//    for (auto beg = n; beg != m; ++beg)
//    {
//        if (*beg > max)
//            max = *beg;
//    }
//
//    return max;
//}
//
//int main()
//{
//    std::string Str1, Str2, Str3, Str4;
//    std::getline(std::cin, Str1);
//    std::getline(std::cin, Str2);
//    std::getline(std::cin, Str3);
//    std::getline(std::cin, Str4);
//
//    std::array<int, 26> Arr{ 0 };
//
//    for (const auto &r : Str1)
//    {
//        if (r >= 'A' && r <= 'Z')
//            ++Arr[r - 'A'];
//    }
//    for (const auto &r : Str2)
//    {
//        if (r >= 'A' && r <= 'Z')
//            ++Arr[r - 'A'];
//    }
//    for (const auto &r : Str3)
//    {
//        if (r >= 'A' && r <= 'Z')
//            ++Arr[r - 'A'];
//    }
//    for (const auto &r : Str4)
//    {
//        if (r >= 'A' && r <= 'Z')
//            ++Arr[r - 'A'];
//    }
//
//    const int max = Max(Arr.begin(), Arr.end());
//
//    std::array<std::array<char, 500>, 26> Graph;
//    for (int n = max - 1; n >= 0; --n)
//    {
//        for (int m = 0; m < 26; ++m)
//        {
//            if (Arr[m] > n)
//                Graph[n][m] = '*';
//            else
//                Graph[n][m] = ' ';
//        }
//    }
//
//    for (int n = max - 1; n >= 0; --n)
//    {
//        for (int m = 0; m < 26; ++m)
//        {
//            std::cout << Graph[n][m];
//            if (m != 25)
//                std::cout << ' ';
//        }
//        std::cout << std::endl;
//    }
//    std::cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << std::endl;
//    
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<long long, 100000> Catalan{ 0 };
//    Catalan[0] = 1;
//    Catalan[1] = 1;
//    int T;
//    std::cin >> T;
//    for (long long n = 2; n <= T; ++n)
//    {
//        for (long long m = 0; m < n; ++m)
//            Catalan[n] = (Catalan[m] * Catalan[n - m - 1] % 100000007
//                       + Catalan[n]) % 100000007;
//    }
//    std::cout << Catalan[T]<< std::endl;
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<long long, 100> Catalan{ 0 };
//    Catalan[0] = 1;
//    Catalan[1] = 1;
//    int T;
//    std::cin >> T;
//    for (int n = 2; n <= T; ++n)
//    {
//        for (int m = 0; m < n; ++m)
//            Catalan[n] += Catalan[m] * Catalan[n - m - 1];
//    }
//    std::cout << Catalan[T] << std::endl;
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int a, b, c;
//    std::cin >> a >> b >> c;
//    std::cout << a * 0.2 + b * 0.3 + c * 0.5 << std::endl;
//    return 0;
//}
//#include <iostream>
//#include <map>
//#include <string>
//
//int main()
//{
//    std::string Str1, Str2;
//    std::cin >> Str1 >> Str2;
//    std::map<std::string, unsigned> Front, Back;
//
//    const auto Length1 = Str1.size();
//    const auto Length2 = Str2.size();
//
//    for (std::size_t i = 0; i < Length1; ++i)
//    {
//        Front[std::string(Str1, 0, i + 1)] = 0;
//        Back[std::string(Str1, i)] = 0;
//    }
//
//    for (std::size_t i = 0; i < Length2; ++i)
//    {
//        if (Front.find(std::string(Str2, i)) != Front.cend())
//            ++Front[std::string(Str2, i)];
//        if (Back.find(std::string(Str2, 0, i + 1)) != Back.cend())
//            ++Back[std::string(Str2, 0, i + 1)];
//    }
//
//    unsigned Max = 0;
//    for (const auto &r : Front)
//    {
//        if (r.second >= 1 && r.first.length() > Max)
//        {
//            Max = r.first.length();
//        }
//    }
//    for (const auto &r : Back)
//    {
//        if (r.second >= 1 && r.first.length() > Max)
//        {
//            Max = r.first.length();
//        }
//    }
//
//    std::cout << Max << std::endl;
//    return 0;
//}
//#include <iostream>
//
//template <long N>
//class Data
//{
//public:
//    enum { res = Data<N - 1>::res + Data<N - 2>::res };
//};
//
//template <>
//class Data<1>
//{
//public:
//    enum { res = 1L };
//};
//
//template <>
//class Data<0>
//{
//public:
//    enum { res = 1L };
//};
//
//int main()
//{
//    std::cout << Data<45L>::res << std::endl;
//    return 0;
//}
//#include <iostream>
//#include <set>
//
//int main()
//{
//    std::set<int> Set;
//    int n;
//    std::size_t m;
//    std::cin >> n >> m;
//
//    int Temp;
//    while (n--)
//    {
//        std::cin >> Temp;
//        Set.insert(Temp);
//    }
//
//    if (m > Set.size())
//        std::cout << "NO RESULT" << std::endl;
//    else
//    {
//        auto beg = Set.begin();
//        for (int i = 0; i < m - 1; ++beg, ++i)
//            ;
//        std::cout << *beg << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <set>
//
//int main()
//{
//    std::set<int> NO;
//    int n;
//
//    int Temp;
//    std::cin >> n;
//    while (n--)
//    {
//        std::cin >> Temp;
//        NO.insert(Temp);
//    }
//
//    std::cout << NO.size() << std::endl;
//
//    for (const auto &r : NO)
//    {
//        std::cout << r << ' ';
//    }
//    std::cout << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<bool, 1001> NO{ false };
//    int n, i;
//    std::cin >> n;
//    while (n--)
//    {
//        std::cin >> i;
//        NO[i] = true;
//    }
//
//    int Total = 0;
//    for (int i = 0; i < 1001; ++i)
//    {
//        if (NO[i])
//            ++Total;
//    }
//    std::cout << Total << std::endl;
//
//    for (int i = 0; i < 1001; ++i)
//    {
//        if (NO[i])
//            std::cout << i << ' ';
//    }
//
//    std::cout << std::endl;
//    return 0;
//}
//#include <array>
//#include <iostream>
//
//int main()
//{
//    std::array<std::array<long long, 30>, 30> Arr{ 0 };
//    std::array<std::array<long long, 30>, 30> Map{ 0 };
//    long long i, j, m, n;
//    std::cin >> i >> j >> m >> n;
//
//    Map[m][n] = 1;
//    Map[m - 2][n - 1] = 1;
//    Map[m - 2][n + 1] = 1;
//    Map[m - 1][n - 2] = 1;
//    Map[m - 1][n + 2] = 1;
//    Map[m + 1][n - 2] = 1;
//    Map[m + 1][n + 2] = 1;
//    Map[m + 2][n - 1] = 1;
//    Map[m + 2][n + 1] = 1;
//
//    Arr[0][1] = 1;
//    
//    for (int row = 1; row <= i + 1; ++row)
//    {
//        for (int col = 1; col <= j + 1; ++col)
//        {
//            Arr[row][col] = Arr[row - 1][col] + Arr[row][col - 1];
//            if (Map[row - 1][col - 1])
//                Arr[row][col] = 0;
//        }
//    }
//
//    std::cout << Arr[i + 1][j + 1] << std::endl;
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cout << "请输入行数：";
//    cin >> n;
//
//    set<string> A, B;
//    cout << "请输入文本：" << endl;
//
//    for (int i = 0; i < n + 1; ++i)
//    {
//        string Temp;
//        getline(cin, Temp);
//        istringstream InStr(Temp);
//
//        string word;
//        vector<string> VecTemp;
//        while (InStr >> word)
//        {
//            VecTemp.push_back(word);
//        }
//
//        bool Flag = false;
//        for (const auto &r : VecTemp)
//        {
//            if (r == "->")
//                Flag = true;
//
//            if (Flag)
//                B.insert(r);
//            else
//                A.insert(r);
//        }
//    }
//
//    cout << "A部分单词：";
//    for (const auto &r : A)
//    {
//        cout << r << ' ';
//    }
//
//    cout << endl;
//
//    cout << "B部分单词：";
//    for (const auto &r : B)
//    {
//        if (auto iter = A.find(r) == A.end())
//            cout << r << ' ';
//    }
//
//    cout << endl;
//
//    return 0;
//}
//#include <set>
//#include <map>
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::set<std::string> Exclude{ "aaa", "bbb", "ccc" };
//    std::map<std::string, std::size_t> WordCount;
//    std::string Word;
//    while (std::cin >> Word)
//    {
//        if (Exclude.find(Word) == Exclude.end())
//            ++WordCount[Word];
//    }
//    for (const auto &r : WordCount)
//    {
//        std::cout << r.first << ' ' << r.second << std::endl;
//    }
//    return 0;
//}
//#include <iostream>
//#include <array>
//#include <algorithm>
//
//int main()
//{
//    std::array<int, 10> a;
//    for (int i = 123; i <= 329; ++i)
//    {
//        bool Flag = true;
//        a[1] = i % 10;
//        a[2] = i / 100;
//        a[3] = i % 100 / 10;
//        a[4] = 2 * i % 10;
//        a[5] = 2 * i / 100;
//        a[6] = 2 * i % 100 / 10;
//        a[7] = 3 * i % 10;
//        a[8] = 3 * i / 100;
//        a[9] = 3 * i % 100 / 10;
//        std::sort(a.begin() + 1, a.end());
//        for (int j = 1; j <= 9; ++j)
//        {
//            if (a[j] != j)
//                Flag = false;
//        }
//        if (Flag)
//            std::cout << i << ' ' << i * 2 << ' ' << i * 3 << std::endl;
//    }
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    std::array<int, 10> Height;
//
//    for (int i = 0; i < 10; ++i)
//    {
//        std::cin >> Height[i];
//    }
//
//    int Tao;
//    std::cin >> Tao;
//    Tao += 30;
//
//    int n = 0;
//    for (int i = 0; i < 10; ++i)
//    {
//        if (Tao >= Height[i])
//            ++n;
//    }
//
//    std::cout << n << std::endl;
//    return 0;
//}
//#include <iostream>
//#include <array>
//
//int main()
//{
//    int Size, Aim;
//    std::array<int, 10> Arr{ 0 };
//    std::cin >> Size >> Aim;
//    for (int i = 1; i <= Size; ++i)
//    {
//        int n = i;
//        while (n > 0)
//        {
//            ++Arr[n % 10];
//            n /= 10;
//        }
//    }
//    std::cout << Arr[Aim] << std::endl;
//    return 0;
//}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//    double Dis;
//    std::cin >> Dis;
//    int n = 1;
//    while (100 - 100 * std::pow(0.98, n) < Dis)
//        ++n;
//    std::cout << n << std::endl;
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    long int n, x, Sum = 0;
//    std::cin >> x >> n;
//    for (long int i = x; i <= n + x - 1; ++i)
//    {
//        if (i % 7 != 6 && i % 7 != 0)
//            Sum += 250;
//    }
//    std::cout << Sum << std::endl;
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    double Sum = 0.0;
//    int n = 1, K;
//    std::cin >> K;
//    while (Sum <= K)
//    {
//        Sum += 1.0 / n;
//        ++n;
//    }
//
//    std::cout << n - 1 << std::endl;
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int Save = 0, Left = 0, Used;
//    bool Flag = false;
//    for (int i = 1; i <= 12; ++i)
//    {
//        std::cin >> Used;
//        Left += 300 - Used;
//        if (Left < 0)
//        {
//            std::cout << -i << std::endl;
//            Flag = true;
//            break;
//        }
//        else
//        {
//            Save += Left / 100 * 100;
//            Left -= Left / 100 * 100;
//        }
//    }
//
//    if (!Flag)
//        std::cout << Save * 1.2 + Left << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string InString;
//    std::cin >> InString;
//    if (InString.front() == '-')
//    {
//        InString.erase(InString.begin());
//        auto length = InString.find_last_not_of('0');
//        InString.erase(InString.begin() + length + 1, InString.end());
//        std::cout << "-";
//        for (auto beg = InString.rbegin(); beg != InString.rend(); ++beg)
//            std::cout << *beg;
//    }
//    else
//    {
//        auto length = InString.find_last_not_of('0');
//        InString.erase(InString.begin() + length + 1, InString.end());
//        for (auto beg = InString.rbegin(); beg != InString.rend(); ++beg)
//            std::cout << *beg;
//    }
//
//    std::cout << std::endl;
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    long n;
//    std::cin >> n;
//    if (n < 0)
//    {
//        std::cout << "-";
//        n = -n;
//        while (n % 10 == 0)
//            n /= 10;
//        while (n != 0)
//        {
//            std::cout << n % 10;
//            n /= 10;
//        }
//    }
//    else
//    {
//        while (n % 10 == 0)
//            n /= 10;
//        while (n != 0)
//        {
//            std::cout << n % 10;
//            n /= 10;
//        }
//    }
//    std::cout << std::endl;
//}
//#include <iostream>
//
//int main()
//{
//    int SumMax = 0, DayMax = 0;
//    for (int i = 1; i <= 7; ++i)
//    {
//        int a, b;
//        std::cin >> a >> b;
//        if (a + b > 8 && a + b > SumMax)
//        {
//            SumMax = a + b;
//            DayMax = i;
//        }
//    }
//    std::cout << DayMax << std::endl;
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <string>
//
//template <typename T>
//int Compare(const T &a, const T &b)
//{
//    if (a > b)
//        return 1;
//    else if (a < b)
//        return -1;
//    else
//        return 0;
//}
//
//template <unsigned N, unsigned M>
//#include <iostream>
//#include <vector>
//
//template <typename I, typename T>
//I Find(I b, I e, const T &x)
//{
//    while (b != e && *b != x)
//        ++b;
//    return b;
//}
//
//template <typename T, unsigned N>
//const T* MyBegin(const T (&arr)[N])
//{
//    return &arr[0];
//}
//
//template <typename T, unsigned N>
//const T* MyEnd(const T (&arr)[N])
//{
//    return &arr[0] + N;
//}
//
//int main()
//{
//    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    std::vector<int> v{ 1, 2, 3, 4, 5 };
//    auto iter = Find(MyBegin(arr), MyEnd(arr), 1);
//    if (iter != MyEnd(arr))
//        std::cout << "Find!" << std::endl;
//    return 0;
//}
//int Compare(const char (&p1)[N], const char (&p2)[M])
//{
//    return strcmp(p1, p2);
//}
//
//class C
//{
//public:
//    C() = default;
//    ~C() = default;
//
//private:
//    int n;
//};
//
//int main()
//{
//    std::vector<int> va{ 1, 2, 3 };
//    std::vector<int> vb{ 2, 3, 4 };
//    std::cout << Compare(va, vb) << std::endl;
//    return 0;
//}


//#include <iostream>
//#include <iomanip>
//
//int main()
//{
//    unsigned n;
//    std::cin >> n;
//    std::cout << std::setiosflags(std::ios::fixed);
//    std::cout.precision(1);
//    if (n <= 150)
//    {
//        std::cout << n * 0.4463 << std::endl;
//    }
//    else if (n > 150 && n <= 400)
//    {
//        std::cout << 150 * 0.4463 + (n - 150) * 0.4663 << std::endl;
//    }
//    else
//    {
//        std::cout << 150 * 0.4463 + (400 - 150) * 0.4663 + (n - 400) * 0.5663 << std::endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//    int n;
//    std::vector<int> v;
//    do
//    {
//        std::cin >> n;
//        v.push_back(n);
//    } while (n < 0);
//
//    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
//
//    for (const auto &r : v)
//        std::cout << r << " ";
//    std::cout << std::endl;
//
//    std::cout << v[1] << " " << v[2] << std::endl;
//
//    return 0;
//}
//#include <iostream>
//
//int main()
//{
//    int a, b, c, d;
//    std::cin >> a >> b >> c >> d;
//    int Sum1, Sum2;
//    if (b > d)
//    {
//        Sum1 = c - a - 1;
//        Sum2 = d + 60 - b;
//    }
//    else
//    {
//        Sum1 = c - a;
//        Sum2 = d - b;
//    }
//    std::cout << Sum1 << " " << Sum2 << std::endl;
//    return 0;
//}