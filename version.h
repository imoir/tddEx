#pragma once

#include <string>

namespace luminator
{
    class version
    {
    public:
        version() {}
        version(unsigned major, unsigned minor, unsigned subMinor = 0, unsigned build = 0)
            : m_valid(true), m_major(major), m_minor(minor), m_subMinor(subMinor), m_build(build) {}
        bool isValid() const { return m_valid; }
        int major() const { return m_major; }
        int minor() const { return m_minor; }
        int subMinor() const { return m_subMinor; }
        int build() const { return m_build; }

        bool fromString(const std::string &versionStr);

    private:
        bool m_valid = false;
        int m_major = 0;
        int m_minor = 0;
        int m_subMinor = 0;
        int m_build = 0;

        unsigned getNumber(const std::string &versionStr, size_t &index);
    };
}
