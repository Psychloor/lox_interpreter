#include <iostream>

int main()
{
    try
    {
        std::cout << "Hello, World!" << '\n';
        return EXIT_SUCCESS;
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } catch (...)
    {
        std::cerr << "Unknown error\n";
    }

    return EXIT_FAILURE;
}