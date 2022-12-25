#include "FormCalculator.h"
#include "Arithmetic.hpp"



using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Calculator::FormCalculator form;
	Application::Run(% form);

	return 0;
}



Arithmetic record;


// ��������������� String^ � std::string
void MarshalString(String^ s, std::string& str)
{
	using namespace Runtime::InteropServices;

	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();

	str = chars;

	Marshal::FreeHGlobal(IntPtr((void*)chars));
}



System::Void Calculator::FormCalculator::textBoxSrcStr_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	
	groupBoxTableVar->Enabled = false;
	groupBoxResults->Enabled = false;
	buttonCalculate->Enabled = false;


	clearTable();
	clearPolStr();
	clearResult();
	

	if (textBoxSrcStr->Text == "")
	{
		buttonGenTable->Enabled = false;
	}
	else
	{
		buttonGenTable->Enabled = true;
	}
}




System::Void Calculator::FormCalculator::buttonGenTable_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		std::string inputStr{};
		MarshalString(textBoxSrcStr->Text, inputStr);

		record = inputStr;

		groupBoxTableVar->Enabled = true;
		buttonCalculate->Enabled = true;

		size_t row = record.GetTableVar().size();
		size_t col = 2;

		// ������� ������� �������� �������������� ���������
		dataGridViewTableVar->RowCount = row;
		dataGridViewTableVar->ColumnCount = col;

		// ������������� ���������� ������ �����
		for (size_t i = 0; i < row; ++i)
			dataGridViewTableVar->Rows[i]->Height = Convert::ToDouble(dataGridViewTableVar->Height) / Convert::ToDouble(row) - 1;

		// ������������� ���������� ������ ��������
		for (size_t i = 0; i < col; ++i)
			dataGridViewTableVar->Columns[i]->Width = Convert::ToDouble(dataGridViewTableVar->Width) / Convert::ToDouble(col) - 2;


		// ��������� ������ ������� ������� ���������
		for (size_t i = 0; i < row; ++i)
		{
			auto it = std::next(record.GetTableVar().begin(), i);
			
			dataGridViewTableVar->Rows[i]->Cells[0]->Value = gcnew String(it->first.c_str());
			dataGridViewTableVar->Rows[i]->Cells[0]->ReadOnly = true;
		}

		// ��������� ������ ������� ���������� ��������� (���� ��������� ��������� ������ ����������)
		for (size_t i = 0; i < row; ++i)
		{
			auto it = std::next(record.GetTableVar().begin(), i);

			dataGridViewTableVar->Rows[i]->Cells[1]->Value = gcnew String(std::to_string(it->second).c_str());

			if (IsConst(it->first))
				dataGridViewTableVar->Rows[i]->Cells[1]->ReadOnly = true;
		}		
	}
	catch (const ExceptionRecord& ex)
	{
		MessageBox::Show(gcnew String((std::string("��� ������: ") + std::to_string(ex.GetCodeError()) + '\n' + std::string(ex.what())).c_str()),
			"������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	buttonGenTable->Enabled = false;
}
System::Void Calculator::FormCalculator::buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e)
{
	size_t row = record.GetTableVar().size();
	size_t col = 2;

	// �������� �� ������������ ��������� ��������� � ������� ����������
	for (size_t i = 0; i < row; ++i)
	{
		std::string value{};
		std::string name{};

		MarshalString(Convert::ToString(dataGridViewTableVar->Rows[i]->Cells[0]->Value), name);
		MarshalString(Convert::ToString(dataGridViewTableVar->Rows[i]->Cells[1]->Value), value);

		// ���� ��������� �� ���������� (�.�. ������������ �������)
		if (IsConst(name))
			continue;

		// ���� ����������, �� ��������� �� ������������
		if (IsVariable(name))
		{
			if ((value[0] == '-' && IsConst(value.substr(1)) && value.size() > 1) || IsConst(value))
			{
				record.SetValVar(name, std::atof(value.c_str()));
			}
			else
			{
				MessageBox::Show("������������ ���� � ������� ����������.",
					"������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
	}

	// ���� �������� ������� ������ �������, �������� ����������
	try
	{
		record.Calculation();
	}
	catch (const ExceptionRecord& ex)
	{
		MessageBox::Show(gcnew String((std::string("��� ������: ") + std::to_string(ex.GetCodeError()) + '\n' + std::string(ex.what())).c_str()),
			"������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// ���� ���������� ������ �������, �� ������ ��������� ���� � ������������
	groupBoxResults->Enabled = true;

	textBoxPolStr->Text = gcnew String(record.GetPolStr().c_str());
	textBoxResult->Text = gcnew String(std::to_string(record.GetResult()).c_str());
}
System::Void Calculator::FormCalculator::buttonClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearSrcStr();
	clearPolStr();
	clearTable();
	clearResult();

	groupBoxTableVar->Enabled = false;
	groupBoxResults->Enabled = false;
	buttonCalculate->Enabled = false;
	buttonGenTable->Enabled = false;
}




System::Void Calculator::FormCalculator::clearTable()
{
	dataGridViewTableVar->Rows->Clear();
	dataGridViewTableVar->Columns->Clear();
}
System::Void Calculator::FormCalculator::clearPolStr()
{
	textBoxPolStr->Clear();
}
System::Void Calculator::FormCalculator::clearSrcStr()
{
	textBoxSrcStr->Clear();
}
System::Void Calculator::FormCalculator::clearResult()
{
	textBoxResult->Clear();
}
