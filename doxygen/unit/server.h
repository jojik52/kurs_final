#ifndef SERVER_H
#define SERVER_H

#include "sha1.h"
#include "errors.h"

#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <cstdint>
#include <iostream>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

/**
 * @class Server
 * @brief Класс для представления сервера, способного обрабатывать подключения и аутентификацию пользователей.
 */
class Server
{
public:
    /**
     * @brief Конструктор Server.
     * @param address Адрес сервера.
     * @param port Порт сервера.
     * @param users Логины и пароли пользователей.
     */
    Server(const string &address, uint16_t port, const map<string, string> &users);

    /**
     * @brief Возвращает адрес сервера.
     * @return string& Адрес сервера.
     */
    string& getAddress();

    /**
     * @brief Возвращает порт сервера.
     * @return uint16_t& Порт сервера.
     */
    uint16_t& getPort();

    /**
     * @brief Возвращает логины и пароли пользователей.
     * @return map<string, string>& Логины и пароли пользователей.
     */
    map<string, string>& getUsers();

    /**
     * @brief Запускает сервер.
     * @throw CreateSocketError Если сокет не может быть создан.
     * @throw BindSocketError Если сокет не может быть привязан к адресу.
     * @throw ListenSocketError Если сокет не может быть переведен в режим прослушивания.
     */
    void startup();

    /**
     * @brief Останавливает сервер.
     * @throw ShutdownSocketError Если сокет не может быть корректно закрыт.
     */
    void shutdown();

    /**
     * @brief Ожидает подключения клиента.
     * @throw AcceptConnectionError Если подключение не может быть принято.
     */
    void connect();

    /**
     * @brief Аутентифицирует клиента.
     * @throw RecvDataError Если данные не могут быть получены от клиента.
     * @throw InvalidAuthDataFormatError Если формат данных аутентификации некорректен.
     * @throw InvalidLoginOrPasswordError Если логин или пароль некорректны.
     */
    void authentication();

    /**
     * @brief Вычисляет среднее арифметическое значений, полученных от клиента.
     * @throw RecvDataError Если данные не могут быть получены от клиента.
     * @throw SendDataError Если данные не могут быть отправлены клиенту.
     */
    void averange();

private:
    string address;            ///< Адрес сервера.
    uint16_t port;             ///< Порт сервера.
    map<string, string> users; ///< Логины и пароли пользователей.
    int socket;                ///< Сокет сервера.
    int client;                ///< Сокет клиента.
};

#endif // SERVER_H
