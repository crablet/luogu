// ����һ��ģ����
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int Sum = 0;    // ���㵱ǰҳ���ĺ�

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        Sum += a;   // ����Ҫд��ҳ��
        std::cout << Sum / m << ' ';    // ���㵱��Ҫ������ҳ��
        Sum %= m;   // Ȼ�������һҳ�Ѿ����˶���
    }
    std::cout << std::endl;

    return 0;
}