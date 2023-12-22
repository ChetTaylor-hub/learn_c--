/* 数组.cpp */
#include <cstring>
#include <iostream>

int main()
{

    char *sPtr;
    const char *s = "hello";
    sPtr = new char[strlen(s) + 1];
    /*
    字符串的长度计算：
    strlen(s) 返回字符串s的长度，但不包括结尾的空字符('\0')。
    strlen(s) + 1 确保分配的内存空间足够存储字符串中的所有字符以及结尾的空字符。
    如果只分配 strlen(s) 的空间，字符串末尾将缺少空字符('\0')，这可能导致在处理字符串时出现问题，因为很多字符串处理函数依赖于字符串以空字符('\0')结尾。
    因此，为了正确处理字符串，需要确保分配的内存空间足够大，包括字符串中的字符以及结尾的空字符('\0')。
    */

    strncpy(sPtr, s, strlen(s));
    std::cout << sPtr << std::endl;
    delete sPtr;
    return 0;
}