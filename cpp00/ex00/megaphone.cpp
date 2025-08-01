#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        int i;
        size_t j;
        std::string arr;

        for(i = 1; i < argc; i++)
        {
            arr = argv[i];
            for(j = 0; j < arr.length(); j++)
                std::cout << (char)(std::toupper(arr[j]));
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
