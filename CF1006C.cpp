// ��һ����˫ָ�룬��һͷһβ��ָ��Ϊl��r��Ȼ��������ָ�벻ͣ�����м��ƶ�������ͷβ֮�ͷֱ����ʱ���¼һ��
// �м��ƶ��Ĺ�����ע��һ�º�ʱ�ƶ�һ��ָ�룬��ʱ����ָ��ͬʱ�ƶ��ͺ�����AC��
#include <iostream>
#include <algorithm>
#include <array>

using ll = long long;

constexpr int MaxN = 200000 + 5;

std::array<int, MaxN> Arr{ 0 };

ll Ans = 0;

// ������DFS(l, r, sl, sr)Ϊͷָ��ָ��Arr[l]��βָ��ָ��Arr[r]����ʱͷ֮��Ϊsl��β֮��Ϊsr
void DFS(int l, int r, ll sl, ll sr)
{
    if (sl == sr)   // ����ͷβ֮����ȵ����
    {
        Ans = sl;   // ���¼һ��Ŀǰ�����ֵ�������������������������������Ա�֤ÿ��������ȵ��������ĿǰΪֹ�����Ž⣩

        if (l < r)  // ����ָ�뻹û�������������ǻ���ͬʱ���м��һ��
        {
            DFS(l + 1, r - 1, sl + Arr[l], sr + Arr[r]);
        }
    }
    else if (l > r) // �ݹ��յ�
    {
        return;
    }
    else if (sl < sr)   // ͷ֮�ͱȽ�С�������ƶ�ͷָ��
    {
        DFS(l + 1, r, sl + Arr[l], sr);
    }
    else if (sl > sr)   // β֮�ͱȽ�С�������ƶ�βָ��
    {
        DFS(l, r - 1, sl, sr + Arr[r]);
    }
    else    // ��֪������ʲô����ֵֹ������������������
    {
        return;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> Arr[i];
    }

    DFS(0, n - 1, 0, 0);    // һͷһβ��ʼ�ѣ���ʼʱͷ֮�ͺ�β֮�Ͷ�Ϊ0

    std::cout << Ans << std::endl;

    return 0;
}