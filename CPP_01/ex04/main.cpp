#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char** argv)
{
    std::string linha;
    if (argc != 4)
    {
        std::cout << "Incorrect number of arguments." << std::endl;
        return (0);
    }

    std::ifstream file(argv[1], std::ios::in | std::ios::out);
    if (!file.is_open())
    {
        std::cout << "File \"" << argv[1] << "\" cannot be open" << std::endl;
        return (1);
    }
    while (std::getline(file, linha))
    {
        std::cout << linha << std::endl;
        //find();
    }
    file.close();
    return (0);
}