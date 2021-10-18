#include "version.h"

bool luminator::version::fromString(const std::string &versionStr)
{
    try
    {
        size_t index = 0;

        // trim past leading spaces
        while (index < versionStr.length() && std::isspace(versionStr.at(index)) != 0)
            index++;

        m_major = getNumber(versionStr, index);

        if (index < versionStr.length() && versionStr.at(index) == '.')
            index++;
        else
            throw 0;

        m_minor = getNumber(versionStr, index);

        if (index < versionStr.length() && versionStr.at(index) == '.')
        {
            index++;
            m_subMinor = getNumber(versionStr, index);

            if (index < versionStr.length() && versionStr.at(index) == '.')
            {
                index++;
                m_build = getNumber(versionStr, index);
            }
        }
        while (index < versionStr.length() && std::isspace(versionStr.at(index)) != 0)
            index++;
        if (index < versionStr.length())
            throw 0;
        m_valid = true;
    }
    catch (...)
    {
        m_valid = false;
    }
    return m_valid;
}

unsigned luminator::version::getNumber(const std::string &versionStr, size_t &index)
{
    if (index >= versionStr.length())
        throw 0;
    char c = versionStr.at(index);
    if (c < '0' || c > '9')
        throw 0;
    index++;
    unsigned number = c - '0';
    while (index < versionStr.length())
    {
        c = versionStr.at(index);
        if (c == '.' || std::isspace(c) != 0)
            break;
        if (c < '0' || c > '9')
            throw 0;
        number = (number *10) + (c - '0');
        index++;
    }
    return number;
}
