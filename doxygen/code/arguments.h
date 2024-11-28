#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstring>
#include <iostream>

#include "errors.h"

using namespace std;

/**
 * @class Parser
 * @brief Класс для парсинга аргументов командной строки и хранения параметров.
 */
class Parser
{
public:
    /**
     * @brief Конструктор по умолчанию. Устанавливает пути по умолчанию и параметры.
     */
    Parser();

    /**
     * @brief Парсит аргументы командной строки.
     * 
     * @param argc Количество аргументов.
     * @param argv Массив аргументов.
     * @throw InvalidArgumentError если указан неверный аргумент.
     */
    void parse(int argc, char *argv[]);

    /**
     * @brief Выводит сообщение помощи.
     */
    void help() const;

    /**
     * @brief Возвращает путь к файлу с пользователями.
     * 
     * @return std::string& Путь к файлу с пользователями.
     */
    std::string& getPathToUsers();

    /**
     * @brief Возвращает путь к файлу логов.
     * 
     * @return std::string& Путь к файлу логов.
     */
    std::string& getPathToLog();

    /**
     * @brief Возвращает адрес.
     * 
     * @return std::string& Адрес.
     */
    std::string& getAddress();

    /**
     * @brief Возвращает порт.
     * 
     * @return int Порт.
     */
    int getPort() const;

private:
    std::string pathToUsers; ///< Путь к файлу с пользователями.
    std::string pathToLog;   ///< Путь к файлу логов.
    std::string address;     ///< Адрес.
    int port;                ///< Порт.
};

#endif // PARSER_H
