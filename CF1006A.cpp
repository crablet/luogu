// ֱ���ҹ��ɣ�����ÿ���ȴ��������ٴ���ż����������������->ż->�棬ż����ż->��
// ����������䣬ż����һ���Ǵ�
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--)
    {
        int n;
        std::cin >> n;
        std::cout << (n & 1 ? n : n - 1) << ' ';
    }
    std::cout << std::endl;

    return 0;
}