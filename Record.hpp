#ifndef RECORD_HPP
#define RECORD_HPP


#include "Token.hpp"
#include <stdexcept>


// ������������ � ������ ��������� ������
enum class CodeError
{
	DEFAULT = 0,
	EMPTY_EXPRESSION = -1,
	TYPE_UNDEFINED = -2,
	INVALID_PARENTHESES = -3,
	NO_OPERATOR = -4,
	NO_OPERAND = -5,
	EMPTY_PARENTHESES = -6,
	ZERO_DIVISION = -7,
};

// ����� ���������� ��� ������ Record
class ExceptionRecord : public std::exception
{

private:
	CodeError code = CodeError::DEFAULT;

public:
	ExceptionRecord(CodeError codeError, const char* msgError) : exception{ msgError }
	{
		code = codeError;
	}

	int GetCodeError() const noexcept { return static_cast<int>(code); };
};




// ��������� �� ������������ ������� ������
bool CheckingParentheses(const std::string& str);




class Record
{
private:
	std::string srcStr{};
	std::vector<std::string> strTokens;
	std::vector<Token> tokens{};

private:
	// +-+-+-+-+-+-+-+-+ ��������� ������ +-+-+-+-+-+-+-+-+

	// ��������� �������� ������ �� �������
	void SplitOnTokens(const std::string& str);

	// ���������� ���� ������
	void DefiningTypes();

	// ��������� ������������ ���������� ���������
	void CheckingCorrect();

public:
	// +-+-+-+-+-+-+-+-+ ������������ +-+-+-+-+-+-+-+-+

	Record() {}
	Record(const std::string& str);
	Record(const Record& other);



	// +-+-+-+-+-+-+-+-+ ������ (�������) +-+-+-+-+-+-+-+-+

	// ���������� ���������� ������ � ������
	size_t GetCount() const noexcept;

	// ���������� �������� ���������� ������
	std::string  GetSrcStr() const noexcept;




	// +-+-+-+-+-+-+-+-+ ��������� +-+-+-+-+-+-+-+-+

	Record& operator = (const Record& other);
	Record& operator = (const std::string& str);
	Token& operator [] (const size_t& pos);
};




#endif // RECORD_HPP