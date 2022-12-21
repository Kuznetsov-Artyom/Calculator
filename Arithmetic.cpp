#include "Arithmetic.hpp"


// +-+-+-+-+-+-+-+-+ ��������� ������ +-+-+-+-+-+-+-+-+

// ���������� ����������� ������ ������
void Arithmetic::GenerationPostForm()
{
	std::stack<Token> stOperation;

	for (size_t i = 0; i < tokens.GetCount(); ++i)
	{
		// ���� ������� ���������� ��� ���������
		if (tokens[i].type == TypeToken::VARIABLE || tokens[i].type == TypeToken::CONST)
		{
			postForm.emplace_back(tokens[i]);
			tableVariable[tokens[i].name] = tokens[i].value;
		}
		// ���� ������� ����������� ������
		else if (tokens[i].type == TypeToken::OPEN_BRACKET)
		{
			stOperation.push(tokens[i]);
		}
		// ���� ������� ����������� ������
		else if (tokens[i].type == TypeToken::CLOSE_BRACKET)
		{
			while (!(stOperation.top().type == TypeToken::OPEN_BRACKET))
			{
				postForm.emplace_back(stOperation.top());
				stOperation.pop();
			}

			stOperation.pop();
		}
		// ���� ������� ��������
		else if (tokens[i].type == TypeToken::OPERATION)
		{
			// �������� �� ���������
			if (tokens[i].name == "+" || tokens[i].name == "-")
			{
				if (i == 0 || tokens[i - 1].type == TypeToken::OPEN_BRACKET)
				{
					tokens[i].arity = Arity::UNARY;
				}
			}

			while (!stOperation.empty() && tokens[i].value <= stOperation.top().value)
			{
				postForm.emplace_back(stOperation.top());
				stOperation.pop();
			}

			stOperation.push(tokens[i]);
		}
	}

	while (!stOperation.empty())
	{
		postForm.emplace_back(stOperation.top());
		stOperation.pop();
	}

	for (const auto& token : postForm)
	{
		polStr += token.name;
		polStr += ' ';
	}
	polStr = polStr.substr(0, polStr.size() - 1);
}

// �������� ������ ������ ���� Arithmetic
void Arithmetic::CopyOther(const Arithmetic& other)
{
	tokens = other.tokens;
	tableVariable = other.tableVariable;
	postForm = other.postForm;
	polStr = other.polStr;
	result = other.result;
}




// +-+-+-+-+-+-+-+-+ ������������ +-+-+-+-+-+-+-+-+

Arithmetic::Arithmetic(const std::string& str) : tokens{ str }
{
	GenerationPostForm();
}
Arithmetic::Arithmetic(const Arithmetic& other) { CopyOther(other); }




// +-+-+-+-+-+-+-+-+ ������ (�������) +-+-+-+-+-+-+-+-+

// ���������� "�������� �������� ������"
std::string Arithmetic::GetPolStr() const noexcept { return polStr; }

// ���������� �������� ���������� ������
std::string Arithmetic::GetSrcStr() const noexcept { return tokens.GetSrcStr(); }

// ���������� ��������� ����������
double Arithmetic::GetResult() const noexcept { return result; }

// ���������� �������� ������������ ����������
double Arithmetic::GetValVar(const std::string& name)
{
	if (tableVariable.find(name) == tableVariable.end())
		throw std::logic_error{ "������ ������� ����������" };

	return tableVariable[name];
}

// ���������� ����������� ������ �� ������� � ����������� � �� ����������
const std::map<std::string, double>& Arithmetic::GetTableVar() const noexcept
{
	return tableVariable;
}




// +-+-+-+-+-+-+-+-+ ������ +-+-+-+-+-+-+-+-+

// �������� �������� ���������� �� �������
void Arithmetic::SetValVar(std::string name, double value)
{
	if (tableVariable.find(name) == tableVariable.end())
		throw std::logic_error{"������ ������� ����������"};

	tableVariable[name] = value;
}




// +-+-+-+-+-+-+-+-+ ������ ������ +-+-+-+-+-+-+-+-+

// ��������� ��������� ���������
void Arithmetic::Calculation()
{
	std::stack<double> stVariable;
	double left{};
	double right{};

	for (const auto& token : postForm)
	{
		// ���� ������� ���������� ��� ���������
		if (token.type == TypeToken::CONST || token.type == TypeToken::VARIABLE)
		{
			stVariable.push(tableVariable[token.name]);
		}
		// ���� ������� ��������
		else if (token.type == TypeToken::OPERATION)
		{
			// ���� �������� �������
			if (token.arity == Arity::UNARY)
			{
				right = stVariable.top();
				stVariable.pop();

				if (token.name == "+")
					stVariable.push(right);
				if (token.name == "-")
					stVariable.push(-right);

				right = 0;
			}
			// ����� �������� ��������
			else
			{
				right = stVariable.top();
				stVariable.pop();

				left = stVariable.top();
				stVariable.pop();

				if (token.name == "+") stVariable.push(left + right);
				else if (token.name == "-") stVariable.push(left - right);
				else if (token.name == "*") stVariable.push(left * right);
				else if (token.name == "/")
				{
					// ����������� ����������, ���� ���������� ������� �� ����
					if (right == 0)
						throw ExceptionRecord{ CodeError::ZERO_DIVISION, "������� �� ����" };

					stVariable.push(left / right);
				}
				else stVariable.push(pow(left, right));

				left = 0;
				right = 0;
			}
		}
	}

	result = stVariable.top();
}

// ������� ���������� � �� �������� � ������� (����)
void Arithmetic::ShowTableVar() const noexcept
{
	std::cout << "size tableVariable = " << tableVariable.size() << '\n';
	for (const auto& elem : tableVariable)
	{
		std::cout << elem.first << ' ' << elem.second << '\n';
	}
}




// +-+-+-+-+-+-+-+-+ ��������� +-+-+-+-+-+-+-+-+

Arithmetic& Arithmetic::operator = (const Arithmetic& other)
{
	if (this == &other) return *this;

	CopyOther(other);

	return *this;
}
Arithmetic& Arithmetic::operator = (const std::string& str)
{
	if (tokens.GetSrcStr() == str) return *this;

	Arithmetic tmp(str);
	CopyOther(tmp);

	return *this;
}



