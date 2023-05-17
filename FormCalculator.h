#pragma once

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ FormCalculator
	/// </summary>
	public ref class FormCalculator : public System::Windows::Forms::Form
	{
	public:
		FormCalculator(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~FormCalculator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelSrcStr;
	protected:

	private: System::Windows::Forms::TextBox^ textBoxSrcStr;
	private: System::Windows::Forms::TextBox^ textBoxPolStr;

	protected:


	private: System::Windows::Forms::Label^ labelPolStr;
	private: System::Windows::Forms::TextBox^ textBoxResult;


	private: System::Windows::Forms::Label^ labelResult;
	private: System::Windows::Forms::DataGridView^ dataGridViewTableVar;


	private: System::Windows::Forms::Button^ buttonCalculate;
	private: System::Windows::Forms::GroupBox^ groupBoxWorkSpace;



	private: System::Windows::Forms::GroupBox^ groupBoxTableVar;
	private: System::Windows::Forms::Button^ buttonGenTable;
	private: System::Windows::Forms::GroupBox^ groupBoxResults;
	private: System::Windows::Forms::Button^ buttonClear;

	private: System::Windows::Forms::ToolTip^ toolTipButtonCreateTable;
	private: System::Windows::Forms::ToolTip^ toolTipButtonCalculate;
	private: System::Windows::Forms::ToolTip^ toolTipButtonClear;

	private: System::ComponentModel::IContainer^ components;














	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormCalculator::typeid));
			this->labelSrcStr = (gcnew System::Windows::Forms::Label());
			this->textBoxSrcStr = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPolStr = (gcnew System::Windows::Forms::TextBox());
			this->labelPolStr = (gcnew System::Windows::Forms::Label());
			this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->dataGridViewTableVar = (gcnew System::Windows::Forms::DataGridView());
			this->buttonCalculate = (gcnew System::Windows::Forms::Button());
			this->groupBoxWorkSpace = (gcnew System::Windows::Forms::GroupBox());
			this->buttonGenTable = (gcnew System::Windows::Forms::Button());
			this->groupBoxTableVar = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxResults = (gcnew System::Windows::Forms::GroupBox());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->toolTipButtonCreateTable = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTipButtonCalculate = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTipButtonClear = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTableVar))->BeginInit();
			this->groupBoxWorkSpace->SuspendLayout();
			this->groupBoxTableVar->SuspendLayout();
			this->groupBoxResults->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelSrcStr
			// 
			this->labelSrcStr->AutoSize = true;
			this->labelSrcStr->Font = (gcnew System::Drawing::Font(L"Tahoma", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelSrcStr->Location = System::Drawing::Point(13, 22);
			this->labelSrcStr->Name = L"labelSrcStr";
			this->labelSrcStr->Size = System::Drawing::Size(214, 30);
			this->labelSrcStr->TabIndex = 0;
			this->labelSrcStr->Text = L"Source expression";
			// 
			// textBoxSrcStr
			// 
			this->textBoxSrcStr->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSrcStr->Location = System::Drawing::Point(18, 57);
			this->textBoxSrcStr->Name = L"textBoxSrcStr";
			this->textBoxSrcStr->Size = System::Drawing::Size(550, 29);
			this->textBoxSrcStr->TabIndex = 1;
			this->textBoxSrcStr->TabStop = false;
			this->textBoxSrcStr->TextChanged += gcnew System::EventHandler(this, &FormCalculator::textBoxSrcStr_TextChanged);
			// 
			// textBoxPolStr
			// 
			this->textBoxPolStr->Cursor = System::Windows::Forms::Cursors::No;
			this->textBoxPolStr->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxPolStr->Location = System::Drawing::Point(18, 59);
			this->textBoxPolStr->Name = L"textBoxPolStr";
			this->textBoxPolStr->ReadOnly = true;
			this->textBoxPolStr->Size = System::Drawing::Size(550, 29);
			this->textBoxPolStr->TabIndex = 3;
			this->textBoxPolStr->TabStop = false;
			// 
			// labelPolStr
			// 
			this->labelPolStr->AutoSize = true;
			this->labelPolStr->Font = (gcnew System::Drawing::Font(L"Tahoma", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPolStr->Location = System::Drawing::Point(13, 26);
			this->labelPolStr->Name = L"labelPolStr";
			this->labelPolStr->Size = System::Drawing::Size(275, 30);
			this->labelPolStr->TabIndex = 2;
			this->labelPolStr->Text = L"Reverse Polish Notation";
			// 
			// textBoxResult
			// 
			this->textBoxResult->Cursor = System::Windows::Forms::Cursors::No;
			this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxResult->Location = System::Drawing::Point(18, 155);
			this->textBoxResult->Name = L"textBoxResult";
			this->textBoxResult->ReadOnly = true;
			this->textBoxResult->Size = System::Drawing::Size(257, 29);
			this->textBoxResult->TabIndex = 5;
			this->textBoxResult->TabStop = false;
			this->textBoxResult->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// labelResult
			// 
			this->labelResult->AutoSize = true;
			this->labelResult->Font = (gcnew System::Drawing::Font(L"Tahoma", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelResult->Location = System::Drawing::Point(13, 122);
			this->labelResult->Name = L"labelResult";
			this->labelResult->Size = System::Drawing::Size(203, 30);
			this->labelResult->TabIndex = 4;
			this->labelResult->Text = L"Calculation result";
			// 
			// dataGridViewTableVar
			// 
			this->dataGridViewTableVar->AllowUserToAddRows = false;
			this->dataGridViewTableVar->AllowUserToDeleteRows = false;
			this->dataGridViewTableVar->AllowUserToResizeColumns = false;
			this->dataGridViewTableVar->AllowUserToResizeRows = false;
			this->dataGridViewTableVar->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridViewTableVar->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTableVar->ColumnHeadersVisible = false;
			this->dataGridViewTableVar->Location = System::Drawing::Point(22, 26);
			this->dataGridViewTableVar->Name = L"dataGridViewTableVar";
			this->dataGridViewTableVar->RowHeadersVisible = false;
			this->dataGridViewTableVar->RowHeadersWidth = 51;
			this->dataGridViewTableVar->RowTemplate->Height = 24;
			this->dataGridViewTableVar->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridViewTableVar->Size = System::Drawing::Size(222, 364);
			this->dataGridViewTableVar->TabIndex = 6;
			this->dataGridViewTableVar->TabStop = false;
			// 
			// buttonCalculate
			// 
			this->buttonCalculate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonCalculate->Enabled = false;
			this->buttonCalculate->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCalculate->Location = System::Drawing::Point(311, 109);
			this->buttonCalculate->Name = L"buttonCalculate";
			this->buttonCalculate->Size = System::Drawing::Size(257, 60);
			this->buttonCalculate->TabIndex = 7;
			this->buttonCalculate->TabStop = false;
			this->buttonCalculate->Text = L"Calculate";
			this->toolTipButtonCalculate->SetToolTip(this->buttonCalculate, L"The calculation of the entered expression will be performed");
			this->buttonCalculate->UseVisualStyleBackColor = true;
			this->buttonCalculate->Click += gcnew System::EventHandler(this, &FormCalculator::buttonCalculate_Click);
			// 
			// groupBoxWorkSpace
			// 
			this->groupBoxWorkSpace->Controls->Add(this->buttonGenTable);
			this->groupBoxWorkSpace->Controls->Add(this->buttonCalculate);
			this->groupBoxWorkSpace->Controls->Add(this->labelSrcStr);
			this->groupBoxWorkSpace->Controls->Add(this->textBoxSrcStr);
			this->groupBoxWorkSpace->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxWorkSpace->Location = System::Drawing::Point(20, 14);
			this->groupBoxWorkSpace->Name = L"groupBoxWorkSpace";
			this->groupBoxWorkSpace->Size = System::Drawing::Size(585, 194);
			this->groupBoxWorkSpace->TabIndex = 8;
			this->groupBoxWorkSpace->TabStop = false;
			// 
			// buttonGenTable
			// 
			this->buttonGenTable->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonGenTable->Enabled = false;
			this->buttonGenTable->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonGenTable->Location = System::Drawing::Point(18, 109);
			this->buttonGenTable->Name = L"buttonGenTable";
			this->buttonGenTable->Size = System::Drawing::Size(257, 60);
			this->buttonGenTable->TabIndex = 8;
			this->buttonGenTable->TabStop = false;
			this->buttonGenTable->Text = L"Create table";
			this->toolTipButtonCreateTable->SetToolTip(this->buttonGenTable, L"After clicking, it will generate a table of variables and constants of the entere"
				L"d expression");
			this->buttonGenTable->UseVisualStyleBackColor = true;
			this->buttonGenTable->Click += gcnew System::EventHandler(this, &FormCalculator::buttonGenTable_Click);
			// 
			// groupBoxTableVar
			// 
			this->groupBoxTableVar->Controls->Add(this->dataGridViewTableVar);
			this->groupBoxTableVar->Enabled = false;
			this->groupBoxTableVar->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxTableVar->Location = System::Drawing::Point(626, 14);
			this->groupBoxTableVar->Name = L"groupBoxTableVar";
			this->groupBoxTableVar->Size = System::Drawing::Size(266, 411);
			this->groupBoxTableVar->TabIndex = 9;
			this->groupBoxTableVar->TabStop = false;
			this->groupBoxTableVar->Text = L"Table of variables";
			// 
			// groupBoxResults
			// 
			this->groupBoxResults->Controls->Add(this->buttonClear);
			this->groupBoxResults->Controls->Add(this->textBoxPolStr);
			this->groupBoxResults->Controls->Add(this->labelResult);
			this->groupBoxResults->Controls->Add(this->labelPolStr);
			this->groupBoxResults->Controls->Add(this->textBoxResult);
			this->groupBoxResults->Enabled = false;
			this->groupBoxResults->Location = System::Drawing::Point(20, 220);
			this->groupBoxResults->Name = L"groupBoxResults";
			this->groupBoxResults->Size = System::Drawing::Size(585, 205);
			this->groupBoxResults->TabIndex = 10;
			this->groupBoxResults->TabStop = false;
			// 
			// buttonClear
			// 
			this->buttonClear->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClear->Location = System::Drawing::Point(311, 125);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(257, 60);
			this->buttonClear->TabIndex = 9;
			this->buttonClear->TabStop = false;
			this->buttonClear->Text = L"Clear";
			this->toolTipButtonClear->SetToolTip(this->buttonClear, L"Returns the program to its start state");
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &FormCalculator::buttonClear_Click);
			// 
			// FormCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(909, 445);
			this->Controls->Add(this->groupBoxResults);
			this->Controls->Add(this->groupBoxTableVar);
			this->Controls->Add(this->groupBoxWorkSpace);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"FormCalculator";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Reverse Polish Notation";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTableVar))->EndInit();
			this->groupBoxWorkSpace->ResumeLayout(false);
			this->groupBoxWorkSpace->PerformLayout();
			this->groupBoxTableVar->ResumeLayout(false);
			this->groupBoxResults->ResumeLayout(false);
			this->groupBoxResults->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void textBoxSrcStr_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonGenTable_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e);


private: System::Void clearTable();
private: System::Void clearPolStr();
private: System::Void clearSrcStr();
private: System::Void clearResult();

};
}
