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


// Преобразовывает String^ в std::string
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
	}
	catch (const ExceptionRecord& ex)
	{

	}
}

System::Void Calculator::FormCalculator::buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Calculator::FormCalculator::buttonClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}