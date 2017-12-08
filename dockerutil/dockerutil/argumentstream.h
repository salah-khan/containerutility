#pragma once
class ArgumentStream
{
public:
    ArgumentStream(int ArgumentCount, char** Arguments);
    ~ArgumentStream();

    char* GetArgument();
    void Advance();

protected:
    ArgumentStream();

private:
    char** m_Arguments;
    unsigned int m_CurrentIndex;
    unsigned int m_NumberOfArguments;
};

