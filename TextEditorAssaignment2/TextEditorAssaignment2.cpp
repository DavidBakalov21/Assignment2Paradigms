#include <vector> 
#include <string>
#include <fstream> 
#include <iostream>
#include <cstring>
#include <sstream>
class TextArray {
public:
    TextArray() {}
    void addStringFromNewLine(std::string str) {
        strings.push_back(str);
    }

    
   
    void addStringByIndex(int row,int place, std::string str) {
        std::string Buffer = "";
        for (int i = 0; i < strings[row].length()+1; i++)
        {
            if (place == i) {
                for (int j = 0; j < str.length(); j++) {
                    Buffer += str[j];
                }

            }
            if (i < strings[row].length()) {
                Buffer += strings[row][i];
            }
            
        }
        strings[row] = Buffer;

    }

    void Save(std::string name) {
        std::ofstream file(name);
        for (int i = 0; i < strings.size(); i++)
        {
            file << strings[i] << std::endl;
        }
        file.close();
    }

    void Read(std::string name) {
        std::ifstream file(name);

        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
    }


    void printer() {
        for (int i = 0; i < strings.size(); i++)
        {
            std::cout << strings[i] << std::endl;
        }
    }
    void Search(std::string name, std::string search) {
        std::ifstream file(name);
        int row = 0;
        int place = 0;
        std::string line;
        while (getline(file, line)) {

            if (line.find(search) != std::string::npos)
            {

                std::istringstream iss(line);

                std::vector<std::string> tokens;
                std::string token;
                while (iss >> token) {
                    tokens.push_back(token);
                }
                for (size_t i = 0; i < tokens.size(); i++)
                {
                    if (tokens[i].find(search) != std::string::npos)
                    {
                        std::cout << row << std::endl;
                        std::cout << place << std::endl;
                    }
                    place++;
                }

            }
           

            row++;

        }
    }



    void Delete(int row, int Place, int amount) {
        for (int i = 0; i < strings[row].length() + 1; i++)
        {
            if (i==Place)
            {
                strings[row].erase(i, amount);
            }

        }
    }
  

private:
    std::vector<std::string> strings;
};
int main()
{
    TextArray Editor;
    Editor.addStringFromNewLine("asdf Hello");
    //Editor.addStringByIndex(0, 5, " Hello");
    //Editor.addStringFromNewLine("sdssd");
    //Editor.addStringFromNewLine("sdssd");
   // Editor.addStringFromNewLine("sdssd");
    //Editor.Read("myfile.txt");
    //Editor.printer();

    //Editor.Search("myfile.txt", "ello");
    Editor.Delete(0, 0, 3);
    Editor.printer();
    //std::cout << "Hello World!\n";
}
