// ��һ��ֻҪ����һ�����ʵ�ѭ���ڼ��ɣ�����Ҫ��'c'����������С�����ǿ��Գ�����ȫ��ʹ��'c'
// �ڲݸ�ֽ�϶��Լ�������ҵ��������ѭ�����ˣ���Ψһ
// �ҹ����ѭ�������£�abba abba abba ...
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int Length;
    std::cin >> Length;
    for (int i = 0; i < Length; ++i)
    {
        switch (i % 4)
        {
        case 0: case 3:
            std::cout << 'a';
            break;

        case 1: case 2:
            std::cout << 'b';
            break;

        default:
            break;
        }
    }
    std::cout << std::endl;

    return 0;
}