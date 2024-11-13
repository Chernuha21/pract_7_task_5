#include <iostream>
#include <queue>
#include <string>

struct Document {
    std::string name;
    std::string content;
};

int main() {
    std::queue<Document> printQueue;
    std::string command;

    while (true) {
        std::cout << "Write a comand: ";
        std::cin >> command;

        if (command == "add") {
            Document newDoc;
            std::cout << "name of file: ";
            std::cin.ignore(); // Очищення буфера
            std::getline(std::cin, newDoc.name);
            std::cout << "text: ";
            std::getline(std::cin, newDoc.content);
            printQueue.push(newDoc);
            std::cout << "Document '" << newDoc.name << "' add." << std::endl;

        }
        else if (command == "print") {
            if (!printQueue.empty()) {
                Document docToPrint = printQueue.front();
                printQueue.pop();
                std::cout << "print document: " << docToPrint.name << std::endl;
                std::cout << "text: " << docToPrint.content << std::endl;
            }
            else {
                std::cout << "Tehre is no document." << std::endl;
            }

        }
        else if (command == "close") {
            break;

        }
        else {
            std::cout << "unknow command, try again." << std::endl;
        }
    }

    std::cout << "Program is out." << std::endl;
    return 0;
}
