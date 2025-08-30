#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char** argv)
{
    std::string line;
    std::string text;
    int i;

    i = -1;
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
    while (std::getline(file, line))
    {
        i = line.find(argv[2]);
        if (i > 0)
        {
            //copia para text com as alterações
        }
        else
        {
            //copia o resto
        }
    }
    file.close();
    return (0);
}