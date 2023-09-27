#include <vector> 
#include <string>
#include <fstream> 
#include <iostream>
#include <cstring>
#include <sstream>
#include <limits> 





class FileO {
    

public:
    FileO() {}
    void Save(std::string name, std::vector<std::string> strings) {
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

private:

};



class TextArray {
public:
    TextArray() {}
    std::vector<std::string> strings;
    void addStringFromNewLine(std::string str) {
        strings.push_back(str);
        
        pointer++;
        vecRedoUndo.resize(pointer);
        vecRedoUndo.push_back(strings);
     
       
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
        pointer++;
        vecRedoUndo.resize(pointer);
        vecRedoUndo.push_back(strings);
    }

    


    void printer() {
        for (int i = 0; i < strings.size(); i++)
        {
            std::cout << strings[i] << std::endl;
        }
       // std::cout << pointer << std::endl;
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
        //std::cout << pointer << std::endl;
    }



    void Delete(int row, int Place, int amount) {
      
        for (int i = 0; i < strings[row].length() + 1; i++)
        {
            if (i==Place)
            {
                strings[row].erase(i, amount);
            }

        }

        pointer++;
        vecRedoUndo.resize(pointer);
        vecRedoUndo.push_back(strings);
        //std::cout << pointer << std::endl;
    }
    void Undo() {

       // vecRedoUndo.push_back(strings);
       // pointer++;
        if (pointer > 0) {
            pointer--;
            strings = vecRedoUndo[pointer];
        }
        else
        {
            std::cout << "mistake" << std::endl;
        }
        
        
    }
    void Redo() {
        if (pointer + 1 < vecRedoUndo.size()) { 
            pointer++;
            strings = vecRedoUndo[pointer];
            std::cout << pointer << std::endl;
        }
        else
        {
            std::cout << "mistake" << std::endl;
        }

      
    }
private:
    int pointer = 0;
    
    std::vector<std::vector<std::string>> vecRedoUndo;

};
class Command {


public:
    Command() {}
    void commandLoop() {

        std::cout << "1-Apepend from nl, 2-insert by index, 3-Save to file, 4-load from file, 5-print to console, 6-Search, 7-del, 8-undo, 9-redo\n";
        TextArray Editor;
        FileO FileOperator;
        while (true) {
            int choice;
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice)
            {
            case 1:
            {
                std::string Inputstring;
                std::getline(std::cin, Inputstring);
                Editor.addStringFromNewLine(Inputstring);
                break;
            }
            case 2: {
                int row;
                int Place;
                std::string str;
                std::cin >> row;
                std::cin >> Place;
                std::cin >> str;
                Editor.addStringByIndex(row, Place, str);
                break;
            }

            case 3: {
                std::string fname;
                std::cin >> fname;
                FileOperator.Save(fname, Editor.strings);
                break;
            }
            case 4: {
                std::string fname2;
                std::cin >> fname2;
                FileOperator.Read(fname2);
                break;
            }
            case 5: {

                Editor.printer();
                break;
            }
            case 6: {
                std::string fname3;
                std::string search;
                Editor.Search(fname3, search);
                break;
            }
            case 7: {
                int row;
                int Place;
                int amount;
                std::cin >> row;
                std::cin >> Place;
                std::cin >> amount;
                Editor.Delete(row, Place, amount);
                break;


            }
            case 8: {
                Editor.Undo();

                break;
            }
            case 9: {
                Editor.Redo();
                break;
            }

            default:
                std::cout << "Wrong numba\n";
                break;
            }
        }

    }
};
int main()
{
    Command com;

    com.commandLoop();
   /* TextArray Editor;
    FileO FileOperator;
   // Editor.addStringFromNewLine("asdf Hello");
    //Editor.addStringByIndex(0, 5, " Hello");
    //Editor.addStringFromNewLine("sdssd");
    //Editor.addStringFromNewLine("sdssd");
   // Editor.addStringFromNewLine("sdssd");
    //Editor.Read("myfile.txt");
    //Editor.printer();

    //Editor.Search("myfile.txt", "ello");
   // Editor.Delete(0, 0, 3);
   // Editor.printer();
    //std::cout << "Hello World!\n";
    std::cout << "1-Append from nl, 2-insert by index, 3-Save to file, 4-load from file, 5-print to console, 6-Search, 7-del, 8-undo, 9-redo\n";

    while (true) {
        int choice;
       std::cin >> choice;
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       switch (choice)
       {
       case 1:
       {
           std::string Inputstring;
           std::getline(std::cin, Inputstring);
           Editor.addStringFromNewLine(Inputstring);
           break;
       }
       case 2: {
           int row;
           int Place;
           std::string str;
           std::cin >> row;
           std::cin >> Place;
           std::cin >> str;
           Editor.addStringByIndex(row,Place,str);
           break;
       }

       case 3: {
           std::string fname;
           std::cin >> fname;
           FileOperator.Save(fname, Editor.strings);
           break;
       }
       case 4: {
           std::string fname2;
           std::cin >> fname2;
           FileOperator.Read(fname2);
           break;
       }
       case 5:{
        
           Editor.printer();
           break;
       }
       case 6: {
           std::string fname3;
           std::string search;
           Editor.Search(fname3, search);
           break;
       }
       case 7: {
           int row;
           int Place;
           int amount;
           std::cin >> row;
           std::cin >> Place;
           std::cin >> amount;
           Editor.Delete( row, Place, amount);
           break;

        
       }
       case 8: {
           Editor.Undo();
          
           break;
       }
       case 9: {
           Editor.Redo();
           break;
       }

       default:
           std::cout << "Wrong numba\n";
           break;
       }
    }
    */
}
