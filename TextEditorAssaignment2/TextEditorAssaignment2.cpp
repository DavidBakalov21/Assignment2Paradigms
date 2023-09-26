#include <vector> 
#include <string>
#include <iostream>
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

    void printer() {
        for (int i = 0; i < strings.size(); i++)
        {
            std::cout << strings[i] << std::endl;
        }
    }
  

private:
    std::vector<std::string> strings;
};
int main()
{
    TextArray Editor;
    Editor.addStringFromNewLine("sdssd");
    Editor.addStringByIndex(0, 5, " Helllo");

    Editor.printer();
    std::cout << "Hello World!\n";
}
