#include "arguments.h"
#include "server.h"
#include "rw.h"
#include <iostream>

/**
 * @brief Запуск сервера с парсером аргументов.
 * 
 * @param parser Объект класса Parser для чтения аргументов.
 * @throw UnknownError Если возникает критическая ошибка.
 */
void run(Parser &parser) {
    Server server(parser.getAddress(), parser.getPort(), readUsers(parser.getPathToUsers()));
    server.startup();
    while (true) {
        try {
            server.connect();
            server.authentication();
            server.averange();
        } catch (const UnknownError &error) {
            if (error.isCritical()) {
                throw error;
            }
            std::cerr << error.what();
            writeLog(parser.getPathToLog(), error);
        }
    }
}

/**
 * @brief Основная функция программы.
 * 
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return int Код завершения программы.
 */
int main(int argc, char *argv[]) {
    Parser parser;
    try {
        parser.parse(argc, argv);
        run(parser); // запуск сервера с аргументами
    } catch (const UnknownError &error) {
        std::cerr << error.what();
        writeLog(parser.getPathToLog(), error);
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred.\n";
        return 1;
    }
    return 0;
}
