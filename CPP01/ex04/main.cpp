#include <exception>
#include <fstream>
#include <iostream>

void replaceLine(std::string &line, std::string &s1, std::string &s2)
{
    size_t s1_len = s1.length();
    size_t s2_len = s2.length();
    size_t pos;

    pos = line.find(s1, 0);
    while (pos != std::string::npos)
    {
        line.erase(pos, s1_len);
        line.insert(pos, s2);
        pos = line.find(s1, pos + s2_len);
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream ifs;
    std::ofstream ofs;

    try
    {
        if (s1.length() == 0)
            throw std::runtime_error("Error: String to look for is empty");
        ifs.open(filename);
        if (ifs.fail())
            throw std::runtime_error("Error: open input file failed");
        ofs.open(filename.append(".replace"));
        if (ofs.fail())
            throw std::runtime_error("Error: open output file failed");
    }
    catch (std::exception &expt)
    {
        std::cerr << expt.what() << std::endl;
        return (1);
    }

    std::string line;
    while (1)
    {
        std::getline(ifs, line);
        replaceLine(line, s1, s2);
        ofs << line;
        if (ifs.eof() == true)
            break;
        ofs << '\n';
    }

    // C++은 객체지향언어로, 소멸자가 있어 스코프에서 벗어나면 자동으로 자원을 해제한다. (즉 RAIL이 지원됨)
    // 그래서 아래와 같이 close를 해주지 않아도 문제는 없지만, 명료하게 작성해두는 편이 좋다
    ifs.close();
    ofs.close();
}