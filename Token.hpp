#ifndef TOKEN_HPP
#define TOKEN_HPP


#include <string>
#include <vector>
#include <cctype>




// ��������� �������� ������
enum class TypeToken
{
	DEFAULT = 0,
	CONST = 1,
	VARIABLE = 2,
	OPERATION = 3,
	OPEN_BRACKET = 4,
	CLOSE_BRACKET = 5
};




// ������� ���������
enum class Arity
{
	DEFAULT = 0,
	UNARY = 1,
	BINARY = 2
};




// ��������� ����������� �������
struct Token
{
	TypeToken type = TypeToken::DEFAULT;
	std::string name{};
	double value{};

	// ���� ��� ������� ���� OPERATION
	Arity arity = Arity::DEFAULT;

	Token() {}
	Token(TypeToken t, std::string n, double v = 0.0, Arity a = Arity::DEFAULT) : type{ t }, name{ n }, value{ v }, arity{ a } {}
};



// ��������� ������� �� ��� CONST
bool IsConst(std::string token);

// ��������� ������� �� ��� VARIABLE
bool IsVariable(std::string token);

// ��������� ������� �� ��� OPERATION
bool IsOperation(std::string token);

// ��������� ������� �� ��� OPEN_BRACKET
bool IsOpenBracket(std::string token);

// ��������� ������� �� ��� CLOSE_BRACKET
bool IsCloseBracket(std::string token);



#endif // !TOKEN_HPP