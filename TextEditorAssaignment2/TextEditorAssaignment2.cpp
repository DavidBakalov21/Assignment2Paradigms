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
        std::cout << "AddTextNewLine" << std::endl;
        strings.push_back(str);
        
        pointer++;
        vecRedoUndo.resize(pointer);
        vecRedoUndo.push_back(strings);
     
       
    }

    void addStringByIndex(int row,int place, std::string str) {
        std::cout << "SearchByIndex" << std::endl;
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
    }
    void Search(std::string name, std::string search) {
        std::cout << "Search" << std::endl;
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
        std::cout << "Delete" << std::endl;
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
    }
    void Undo() {
        std::cout << "Undo" << std::endl;
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
        std::cout << "Redo" << std::endl;
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

    void Cut(int row, int Place, int amount) {
        std::cout << "Cut" << std::endl;
        for (int i = 0; i < strings[row].length(); i++)
        {
            if (i == Place)
            {
                CopyPasteBuffer = strings[row].substr(i, amount);
                strings[row].erase(i, amount);
            }

        }

        pointer++;
        vecRedoUndo.resize(pointer);
        vecRedoUndo.push_back(strings);
    }
    void Copy(int row, int Place, int amount) {
        std::cout << "Copy" << std::endl;
        for (int i = 0; i < strings[row].length() ; i++)
        {
            if (i == Place)
            {
                CopyPasteBuffer = strings[row].substr(i, amount);
                
            }

        }
    }


    void Paste(int row, int Place, int userChoice) {

        if (userChoice==1)
        {
            std::cout << "Paste replacement" << std::endl;
            for (int i = 0; i < CopyPasteBuffer.length(); i++) {
                strings[row][Place + i] = CopyPasteBuffer[i];
            }
        }else{
            std::cout << "Paste insertion" << std::endl;
            addStringByIndex( row,  Place, CopyPasteBuffer);
        }
        pointer++;
        vecRedoUndo.resize(pointer);
        vecRedoUndo.push_back(strings);

    }


    void Replacement(int row, int Place, std::string bufer) {

       
            std::cout << "Paste replacement" << std::endl;
            for (int i = 0; i < bufer.length(); i++) {
                strings[row][Place + i] = bufer[i];

            }
        
        pointer++;
        vecRedoUndo.resize(pointer);
        vecRedoUndo.push_back(strings);

    }

private:
    int pointer = 0;
    std::string CopyPasteBuffer;
    std::vector<std::vector<std::string>> vecRedoUndo;

};
class Command {


public:
    Command() {}
    void commandLoop() {

        std::cout << "1-Apepend from nl, 2-insert by index, 3-Save to file, 4-load from file, 5-print to console, 6-Search, 7-del, 8-undo, 9-redo, 10-cut, 11-copy, 12-paste, 13-replacement\n";
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

            case 10: {
                int row;
                int Place;
                int amount;
                std::cin >> row;
                std::cin >> Place;
                std::cin >> amount;
                Editor.Cut(row,Place,amount);
                break;
            }

            case 11: {
                int row;
                int Place;
                int amount;
                std::cin >> row;
                std::cin >> Place;
                std::cin >> amount;
                Editor.Copy(row, Place, amount);
                break;
            }
            case 12: {
                int row;
                int Place;
                int choice;
                std::cin >> row;
                std::cin >> Place;
                std::cin >> choice;
                Editor.Paste(row, Place, choice);
                break;
            }

            case 13: {
                int row;
                int Place;
                std::string str;
                std::cin >> row;
                std::cin >> Place;
                std::cin >> str;
                Editor.Replacement(row, Place, str);
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
   
}
