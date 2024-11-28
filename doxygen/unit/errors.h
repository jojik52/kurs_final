#ifndef ERRORS_H
#define ERRORS_H

#include <string>
#include <ctime>
#include <exception>

using namespace std;

/**
 * @class UnknownError
 * @brief Базовый класс для всех ошибок.
 */
class UnknownError : public exception
{
public:
    /**
     * @brief Конструктор UnknownError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    UnknownError(const string &func, bool is_critical = false);

    /**
     * @brief Получает имя ошибки.
     * @return Имя ошибки.
     */
    string getName() const;

    /**
     * @brief Получает имя функции, в которой возникла ошибка.
     * @return Имя функции.
     */
    string getFunc() const;

    /**
     * @brief Получает сообщение об ошибке.
     * @return Сообщение об ошибке.
     */
    string getMessage() const;

    /**
     * @brief Получает время возникновения ошибки.
     * @return Время возникновения ошибки.
     */
    time_t getTime() const;

    /**
     * @brief Проверяет, является ли ошибка критической.
     * @return true, если ошибка критическая, иначе false.
     */
    bool isCritical() const;

    /**
     * @brief Получает сообщение об ошибке для вывода.
     * @return Сообщение об ошибке.
     */
    const char *what() const noexcept override;

protected:
    string name = "UnknownError"; ///< Имя ошибки.

private:
    string func;            ///< Имя функции, в которой возникло исключение.
    time_t time;            ///< Время возникновения исключения.
    bool is_critical;       ///< Флаг критичности исключения.
    mutable string message; ///< Сообщение об ошибке.
};

/**
 * @class InvalidArgumentError
 * @brief Ошибка некорректного аргумента.
 */
class InvalidArgumentError : public UnknownError
{
public:
    /**
     * @brief Конструктор InvalidArgumentError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    InvalidArgumentError(const string &func, bool is_critical = false);
};

// Ошибки чтения/записи

/**
 * @class ReadWriteError
 * @brief Ошибка чтения/записи.
 */
class ReadWriteError : public UnknownError
{
public:
    /**
     * @brief Конструктор ReadWriteError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    ReadWriteError(const string &func, bool is_critical = false);
};

/**
 * @class InvalidLineFormat
 * @brief Ошибка некорректного формата строки.
 */
class InvalidLineFormat : public UnknownError
{
public:
    /**
     * @brief Конструктор InvalidLineFormat.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    InvalidLineFormat(const string &func, bool is_critical = false);
};

// Ошибки сокета

/**
 * @class CreateSocketError
 * @brief Ошибка создания сокета.
 */
class CreateSocketError : public UnknownError
{
public:
    /**
     * @brief Конструктор CreateSocketError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    CreateSocketError(const string &func, bool is_critical = false);
};

/**
 * @class BindSocketError
 * @brief Ошибка привязки сокета.
 */
class BindSocketError : public UnknownError
{
public:
    /**
     * @brief Конструктор BindSocketError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    BindSocketError(const string &func, bool is_critical = false);
};

/**
 * @class ListenSocketError
 * @brief Ошибка прослушивания сокета.
 */
class ListenSocketError : public UnknownError
{
public:
    /**
     * @brief Конструктор ListenSocketError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    ListenSocketError(const string &func, bool is_critical = false);
};

/**
 * @class ShutdownSocketError
 * @brief Ошибка завершения работы сокета.
 */
class ShutdownSocketError : public UnknownError
{
public:
    /**
     * @brief Конструктор ShutdownSocketError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    ShutdownSocketError(const string &func, bool is_critical = false);
};

/**
 * @class AcceptConnectionError
 * @brief Ошибка принятия соединения.
 */
class AcceptConnectionError : public UnknownError
{
public:
    /**
     * @brief Конструктор AcceptConnectionError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    AcceptConnectionError(const string &func, bool is_critical = false);
};

/**
 * @class RecvDataError
 * @brief Ошибка получения данных.
 */
class RecvDataError : public UnknownError
{
public:
    /**
     * @brief Конструктор RecvDataError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    RecvDataError(const string &func, bool is_critical = false);
};

/**
 * @class SendDataError
 * @brief Ошибка отправки данных.
 */
class SendDataError : public UnknownError
{
public:
    /**
     * @brief Конструктор SendDataError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    SendDataError(const string &func, bool is_critical = false);
};

// Ошибки аутентификации

/**
 * @class InvalidAuthDataFormatError
 * @brief Ошибка некорректного формата данных аутентификации.
 */
class InvalidAuthDataFormatError : public UnknownError
{
public:
    /**
     * @brief Конструктор InvalidAuthDataFormatError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    InvalidAuthDataFormatError(const string &func, bool is_critical = false);
};

/**
 * @class InvalidLoginOrPasswordError
 * @brief Ошибка некорректного логина или пароля.
 */
class InvalidLoginOrPasswordError : public UnknownError
{
public:
    /**
     * @brief Конструктор InvalidLoginOrPasswordError.
     * @param func Имя функции, в которой возникла ошибка.
     * @param is_critical Флаг критичности ошибки.
     */
    InvalidLoginOrPasswordError(const string &func, bool is_critical = false);
};

#endif // ERRORS_H
