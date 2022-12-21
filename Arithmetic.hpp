#ifndef ARITHMETIC_HPP
#define ARITHMETIC_HPP


#include <iostream>
#include "Record.hpp"
#include <map>
#include <stack>
#include <cmath>
#include <stdexcept>



class Arithmetic
{
private:
	Record tokens;
	std::map<std::string, double> tableVariable;
	std::vector<Token> postForm;
	std::string polStr{};
	double result{};

private:
	// +-+-+-+-+-+-+-+-+ ��������� ������ +-+-+-+-+-+-+-+-+

	// ���������� ����������� ������ ������
	void GenerationPostForm();

	// �������� ������ ������ ���� Arithmetic
	void CopyOther(const Arithmetic& other);

public:
	// +-+-+-+-+-+-+-+-+ ������������ +-+-+-+-+-+-+-+-+

	Arithmetic() {}
	Arithmetic(const std::string& str);
	Arithmetic(const Arithmetic& other);

	~Arithmetic() {}



	// +-+-+-+-+-+-+-+-+ ������ (�������) +-+-+-+-+-+-+-+-+

	// ���������� "�������� �������� ������"
	std::string GetPolStr() const noexcept;

	// ���������� �������� ���������� ������
	std::string GetSrcStr() const noexcept;

	// ���������� ��������� ����������
	double GetResult() const noexcept;

	// ���������� �������� ������������ ����������
	double GetValVar(const std::string& name);

	// ���������� ����������� ������ �� ������� � ����������� � �� ����������
	const std::map<std::string, double>& GetTableVar() const noexcept;




	// +-+-+-+-+-+-+-+-+ ������ +-+-+-+-+-+-+-+-+

	// �������� �������� ���������� �� �������
	void SetValVar(std::string name, double value);




	// +-+-+-+-+-+-+-+-+ ������ ������ +-+-+-+-+-+-+-+-+

	// ��������� ��������� ���������
	void Calculation();

	// ������� ���������� � �� �������� � ������� (����)
	void ShowTableVar() const noexcept;




	// +-+-+-+-+-+-+-+-+ ��������� +-+-+-+-+-+-+-+-+

	Arithmetic& operator = (const Arithmetic& other);
	Arithmetic& operator = (const std::string& str);
};



#endif // !CALCULATOR_HPP
