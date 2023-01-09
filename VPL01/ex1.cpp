#include <iostream>

int main()
{
    std::string palavra;
    std::cin >> palavra;
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    for (char letra : palavra)
    {
        if (letra == 'a')
            a++;
        else if (letra == 'e')
            e++;
        else if (letra == 'i')
            i++;
        else if (letra == 'o')
            o++;
        else if (letra == 'u')
            u++;
    }

    if (a != 0)
        std::cout << "a " << a << std::endl;
    if (e != 0)
        std::cout << "e " << e << std::endl;
    if (i != 0)
        std::cout << "i " << i << std::endl;
    if (o != 0)
        std::cout << "o " << o << std::endl;
    if (u != 0)
        std::cout << "u " << u << std::endl;

    return 0;
}