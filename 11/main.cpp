#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Record {
    std::string FIO;
    int number_of_seats;
    int weight;
};

void createNewFile() {
    system("clear");
    std::string filename;
    int number_of_record;
    std::cout << "Введите название файла: ";
    std::cin >> filename;
    std::cout << "Введите количество записей: ";
    std::cin >> number_of_record;

    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 1; i <= std::abs(number_of_record); i++) {
            Record record;
            std::cout << i << ": ";
            std::cin >> record.FIO >> record.number_of_seats >> record.weight;
            file << record.FIO << " " << record.number_of_seats << " " << record.weight << std::endl;
        }
        file.close();
    } else {
        std::cout << "Ошибка создания файла(" << std::endl;
        std::cin >> filename;
    }
}

void lookFile() {
    system("clear");
    std::string filename;
    std::cout << "Введите название файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (file.is_open()) {
        char c = file.get();
        while (!file.eof()) {
            std::cout << c;
            c = file.get();
        }
        std::cout << std::endl;
        file.close();
    } else
        std::cout << "Ошибка открытия файла(" << std::endl;
    std::cin >> filename;
}

void addNewRecord() {
    system("clear");
    std::string filename;
    std::cout << "Введите название файла: ";
    std::cin >> filename;

    std::ifstream file_(filename);
    if (file_.is_open()) {
        std::string text;
        char c = file_.get();
        while (!file_.eof()) {
            text.push_back(c);
            c = file_.get();
        }
        std::ofstream file(filename);
        Record record;
        file << text;
        std::cin >> record.FIO >> record.number_of_seats >> record.weight;
        file << record.FIO << " " << record.number_of_seats << " " << record.weight << std::endl;
        file.close();
    } else {
        std::cout << "Ошибка открытия файла(" << std::endl;
        std::cin >> filename;
    }
}

void removeLightPeople() {
    system("clear");
    std::string filename;
    std::cout << "Введите название файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (file.is_open()) {
        std::vector<std::vector<std::string>> lines;
        while (!file.eof()) {
            std::string line;
            getline(file, line);
            std::vector<std::string> words;
            std::string word;
            for (auto symbol : line) {
                if (symbol == ' ' || symbol == '\n') {
                    words.push_back(word);
                    word = "";
                } else
                    word.push_back(symbol);
            }
            words.push_back(word);
            int weight = 0;
            int i = words[2].length();
            for (char symbol : words[2])
                weight += (symbol - '0') * pow(10, --i);
            if (weight >= 10)
                lines.push_back(words);
        }
        file.close();
        std::ofstream file_(filename);
        for (auto line : lines)
            file_ << line[0] << " " << line[1] << " " << line[2] << std::endl;
        file_.close();
    } else {
        std::cout << "Ошибка открытия файла(" << std::endl;
        std::cin >> filename;
    }
}

void changeWeight() {
    system("clear");
    std::string filename;
    std::cout << "Введите название файла: ";
    std::cin >> filename;
    std::string FIO;
    std::cout << "Введите ФИО пассажира (без пробелов): ";
    std::cin >> FIO;
    std::string new_weight;
    std::cout << "Введите новый вес: ";
    std::cin >> new_weight;

    std::ifstream file(filename);
    if (file.is_open()) {
        std::vector<std::vector<std::string>> lines;
        while (!file.eof()) {
            std::string line;
            getline(file, line);
            std::vector<std::string> words;
            std::string word;
            for (auto symbol : line) {
                if (symbol == ' ' || symbol == '\n') {
                    words.push_back(word);
                    word = "";
                } else
                    word.push_back(symbol);
            }
            words.push_back(word);
            if (FIO.compare(words[0]) == 0)
                words[2] = new_weight;
            lines.push_back(words);
        }
        file.close();
        std::ofstream file_(filename);
        for (auto line : lines)
            file_ << line[0] << " " << line[1] << " " << line[2] << std::endl;
        file_.close();
    } else {
        std::cout << "Ошибка открытия файла(" << std::endl;
        std::cin >> filename;
    }
}

int main() {
    int mode;

    do {
        system("clear");
        std::cout << "1 - Создать новый файл" << std::endl;
        std::cout << "2 - Просмотреть файл" << std::endl;
        std::cout << "3 - Добавить запись" << std::endl;
        std::cout << "4 - Удалить лёгких людей" << std::endl;
        std::cout << "5 - Изменить вес пасажира" << std::endl;
        std::cout << "0 - Выйти" << std::endl;
        std::cin >> mode;

        switch (mode) {
            case 1:
                createNewFile();
                break;

            case 2:
                lookFile();
                break;

            case 3:
                addNewRecord();
                break;

            case 4:
                removeLightPeople();
                break;

            case 5:
                changeWeight();
                break;

            case 0:
                break;

            default:
                system("clear");
                std::cout << "ШО?!" << std::endl
                          << "Попробовать ещё раз" << std::endl;
                std::cin >> mode;
                break;
        }
    } while (mode != 0);

    return 0;
}