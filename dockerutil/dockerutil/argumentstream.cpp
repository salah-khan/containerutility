#include "dockerutil.h"

ArgumentStream::ArgumentStream() : m_CurrentIndex(0), m_NumberOfArguments(0)
{
}

ArgumentStream::ArgumentStream(int ArgumentCount, char** Arguments) : m_CurrentIndex(0), m_NumberOfArguments(ArgumentCount), m_Arguments(Arguments)
{
}

ArgumentStream::~ArgumentStream()
{
}

char* ArgumentStream::GetArgument()
{
    if (m_CurrentIndex >= m_NumberOfArguments) {
        return nullptr;
    }

    return m_Arguments[m_CurrentIndex];
}

void ArgumentStream::Advance()
{
    if (m_CurrentIndex < m_NumberOfArguments) {
        m_CurrentIndex++;
    }
}