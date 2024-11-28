#ifndef RW_H
#define RW_H

#include <map>
#include <string>

#include "errors.h"

using namespace std;

/**
 * @brief Читает пользователей из указанного файла.
 * 
 * @param path Путь к файлу с пользователями.
 * @return map<string, string> Словарь пользователей и паролей.
 * @throw ReadWriteError Если файл не может быть открыт.
 * @throw InvalidLineFormat Если строка в файле имеет неверный формат.
 */
map<string, string> readUsers(const string &path);

/**
 * @brief Записывает информацию об исключении в лог-файл.
 * 
 * @param path Путь к лог-файлу.
 * @param e Объект исключения UnknownError.
 * @throw ReadWriteError Если лог-файл не может быть открыт.
 */
void writeLog(const string &path, const UnknownError &e);

#endif // RW_H
