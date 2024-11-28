#ifndef SHA1_H
#define SHA1_H

#include <string>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/osrng.h>
#include <cryptopp/filters.h>

using namespace std;

/**
 * @brief Функция для вычисления SHA-1 хэша строки.
 * 
 * @param data Входная строка, для которой необходимо вычислить хэш.
 * @return string Хэш строки в шестнадцатеричном формате.
 */
string SHA1(const string &data);

#endif // SHA1_H
