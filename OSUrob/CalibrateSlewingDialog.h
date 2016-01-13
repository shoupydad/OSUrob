#pragma once

#include "doRoutines.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OSUrob {

	/// <summary>
	/// Summary for CalibrateSlewingDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CalibrateSlewingDialog : public System::Windows::Forms::Form
	{
	public:
		static CalibrateSlewingDialog ^FormPtr;
		CalibrateSlewingDialog(void)
		{
			InitializeComponent();
			CalibrateSlewingDialogExists = true;
			FormPtr = this;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CalibrateSlewingDialog()
		{
			if (components)
			{
				delete components;
				CalibrateSlewingDialogExists = false;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::RadioButton^  GuideRadioButton;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  SlewRadioButton;
	private: System::Windows::Forms::RadioButton^  FindRadioButton;
	private: System::Windows::Forms::RadioButton^  CenterRadioButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::RadioButton^  WestRadioButton;
	private: System::Windows::Forms::RadioButton^  EastRadioButton;
	private: System::Windows::Forms::RadioButton^  SouthRadioButton;
	private: System::Windows::Forms::RadioButton^  NorthRadioButon;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  SlewTimeTextBox;

	private: System::Windows::Forms::Button^  StepButton;
	private: System::Windows::Forms::Button^  OkayButton;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::Button^  NButton;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SlewRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->FindRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->CenterRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->GuideRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->WestRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->EastRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->SouthRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->NorthRadioButon = (gcnew System::Windows::Forms::RadioButton());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SlewTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StepButton = (gcnew System::Windows::Forms::Button());
			this->OkayButton = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->NButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->OkayButton, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->groupBox3, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 52.71566F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 36.74121F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.22364F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(258, 313);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				54.24354F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				45.75646F)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox2, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel5, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->StepButton, 1, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 79.04192F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20.95808F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(252, 159);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel3);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(130, 119);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Speed";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel3->Controls->Add(this->SlewRadioButton, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->FindRadioButton, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->CenterRadioButton, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->GuideRadioButton, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 4;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(124, 100);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// SlewRadioButton
			// 
			this->SlewRadioButton->AutoSize = true;
			this->SlewRadioButton->Location = System::Drawing::Point(3, 78);
			this->SlewRadioButton->Name = L"SlewRadioButton";
			this->SlewRadioButton->Size = System::Drawing::Size(48, 17);
			this->SlewRadioButton->TabIndex = 3;
			this->SlewRadioButton->Text = L"Slew";
			this->SlewRadioButton->UseVisualStyleBackColor = true;
			// 
			// FindRadioButton
			// 
			this->FindRadioButton->AutoSize = true;
			this->FindRadioButton->Location = System::Drawing::Point(3, 53);
			this->FindRadioButton->Name = L"FindRadioButton";
			this->FindRadioButton->Size = System::Drawing::Size(45, 17);
			this->FindRadioButton->TabIndex = 2;
			this->FindRadioButton->Text = L"Find";
			this->FindRadioButton->UseVisualStyleBackColor = true;
			// 
			// CenterRadioButton
			// 
			this->CenterRadioButton->AutoSize = true;
			this->CenterRadioButton->Location = System::Drawing::Point(3, 28);
			this->CenterRadioButton->Name = L"CenterRadioButton";
			this->CenterRadioButton->Size = System::Drawing::Size(56, 17);
			this->CenterRadioButton->TabIndex = 1;
			this->CenterRadioButton->Text = L"Center";
			this->CenterRadioButton->UseVisualStyleBackColor = true;
			// 
			// GuideRadioButton
			// 
			this->GuideRadioButton->AutoSize = true;
			this->GuideRadioButton->Checked = true;
			this->GuideRadioButton->Location = System::Drawing::Point(3, 3);
			this->GuideRadioButton->Name = L"GuideRadioButton";
			this->GuideRadioButton->Size = System::Drawing::Size(53, 17);
			this->GuideRadioButton->TabIndex = 0;
			this->GuideRadioButton->TabStop = true;
			this->GuideRadioButton->Text = L"Guide";
			this->GuideRadioButton->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel4);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(139, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(110, 119);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Direction";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel4->Controls->Add(this->WestRadioButton, 0, 3);
			this->tableLayoutPanel4->Controls->Add(this->EastRadioButton, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->SouthRadioButton, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->NorthRadioButon, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 4;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(104, 100);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// WestRadioButton
			// 
			this->WestRadioButton->AutoSize = true;
			this->WestRadioButton->Location = System::Drawing::Point(3, 78);
			this->WestRadioButton->Name = L"WestRadioButton";
			this->WestRadioButton->Size = System::Drawing::Size(50, 17);
			this->WestRadioButton->TabIndex = 3;
			this->WestRadioButton->TabStop = true;
			this->WestRadioButton->Text = L"West";
			this->WestRadioButton->UseVisualStyleBackColor = true;
			// 
			// EastRadioButton
			// 
			this->EastRadioButton->AutoSize = true;
			this->EastRadioButton->Location = System::Drawing::Point(3, 53);
			this->EastRadioButton->Name = L"EastRadioButton";
			this->EastRadioButton->Size = System::Drawing::Size(46, 17);
			this->EastRadioButton->TabIndex = 2;
			this->EastRadioButton->TabStop = true;
			this->EastRadioButton->Text = L"East";
			this->EastRadioButton->UseVisualStyleBackColor = true;
			// 
			// SouthRadioButton
			// 
			this->SouthRadioButton->AutoSize = true;
			this->SouthRadioButton->Location = System::Drawing::Point(3, 28);
			this->SouthRadioButton->Name = L"SouthRadioButton";
			this->SouthRadioButton->Size = System::Drawing::Size(53, 17);
			this->SouthRadioButton->TabIndex = 1;
			this->SouthRadioButton->TabStop = true;
			this->SouthRadioButton->Text = L"South";
			this->SouthRadioButton->UseVisualStyleBackColor = true;
			// 
			// NorthRadioButon
			// 
			this->NorthRadioButon->AutoSize = true;
			this->NorthRadioButon->Location = System::Drawing::Point(3, 3);
			this->NorthRadioButon->Name = L"NorthRadioButon";
			this->NorthRadioButon->Size = System::Drawing::Size(51, 17);
			this->NorthRadioButon->TabIndex = 0;
			this->NorthRadioButon->TabStop = true;
			this->NorthRadioButon->Text = L"North";
			this->NorthRadioButon->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel5->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->SlewTimeTextBox, 1, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 128);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(130, 28);
			this->tableLayoutPanel5->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Slew Time:";
			// 
			// SlewTimeTextBox
			// 
			this->SlewTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SlewTimeTextBox->Location = System::Drawing::Point(68, 4);
			this->SlewTimeTextBox->Name = L"SlewTimeTextBox";
			this->SlewTimeTextBox->Size = System::Drawing::Size(59, 20);
			this->SlewTimeTextBox->TabIndex = 1;
			// 
			// StepButton
			// 
			this->StepButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StepButton->Location = System::Drawing::Point(156, 130);
			this->StepButton->Name = L"StepButton";
			this->StepButton->Size = System::Drawing::Size(75, 23);
			this->StepButton->TabIndex = 3;
			this->StepButton->Text = L"Step";
			this->StepButton->UseVisualStyleBackColor = true;
			this->StepButton->Click += gcnew System::EventHandler(this, &CalibrateSlewingDialog::StepButton_Clicked);
			// 
			// OkayButton
			// 
			this->OkayButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkayButton->Location = System::Drawing::Point(91, 285);
			this->OkayButton->Name = L"OkayButton";
			this->OkayButton->Size = System::Drawing::Size(75, 23);
			this->OkayButton->TabIndex = 4;
			this->OkayButton->Text = L"Okay";
			this->OkayButton->UseVisualStyleBackColor = true;
			this->OkayButton->Click += gcnew System::EventHandler(this, &CalibrateSlewingDialog::OkayButton_Clicked);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel6);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(3, 168);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(252, 109);
			this->groupBox3->TabIndex = 5;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Guiding";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				52.43903F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				47.56097F)));
			this->tableLayoutPanel6->Controls->Add(this->tableLayoutPanel7, 0, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(246, 90);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 3;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel7->Controls->Add(this->NButton, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->button1, 2, 1);
			this->tableLayoutPanel7->Controls->Add(this->button2, 1, 2);
			this->tableLayoutPanel7->Controls->Add(this->button3, 0, 1);
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 3;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(123, 84);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// NButton
			// 
			this->NButton->Location = System::Drawing::Point(44, 3);
			this->NButton->Name = L"NButton";
			this->NButton->Size = System::Drawing::Size(34, 21);
			this->NButton->TabIndex = 0;
			this->NButton->Text = L"N";
			this->NButton->UseVisualStyleBackColor = true;
			this->NButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CalibrateSlewingDialog::NButton_MouseDown);
			this->NButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CalibrateSlewingDialog::NButton_MouseUp);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(85, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(34, 21);
			this->button1->TabIndex = 1;
			this->button1->Text = L"E";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CalibrateSlewingDialog::EButton_MouseDown);
			this->button1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CalibrateSlewingDialog::EButton_MouseUp);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(44, 59);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(34, 21);
			this->button2->TabIndex = 2;
			this->button2->Text = L"S";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CalibrateSlewingDialog::SButton_MouseDown);
			this->button2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CalibrateSlewingDialog::SButton_MouseUp);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(3, 31);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(34, 21);
			this->button3->TabIndex = 3;
			this->button3->Text = L"W";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CalibrateSlewingDialog::WButton_MouseDown);
			this->button3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CalibrateSlewingDialog::WButton_MouseUp);
			// 
			// CalibrateSlewingDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(258, 313);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"CalibrateSlewingDialog";
			this->Text = L"CalibrateSlewingDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void StepButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 bool success;
			 int command;
			 float duration, speed;
			 char buffer[160];

			 if (FormPtr->GuideRadioButton->Checked)
				 speed = 1;
			 else if (FormPtr->CenterRadioButton->Checked)
				 speed = 2;
			 else if (FormPtr->FindRadioButton->Checked)
				 speed = 3;
			 else
				 speed = 4;

			 if (FormPtr->NorthRadioButon->Checked)
				 command = SCOPE_JOG_NORTH;
			 else if (FormPtr->SouthRadioButton->Checked)
				 command = SCOPE_JOG_SOUTH;
			 else if (FormPtr->EastRadioButton->Checked)
				 command = SCOPE_JOG_EAST;
			 else
				 command = SCOPE_JOG_WEST;

			 FormPtr->GetSlewTimeTextBox(buffer);
			 sscanf_s(buffer, "%f", &duration);
			 if ((duration < 0.0) || (duration > 60.0)) {
				 sprintf_s(buffer, sizeof(buffer), "Warning - Invalid step duration, %f, keep between 0.0 and 60.0 secs",
					 duration);
				 MessageBox(buffer, OKAY);
			 } else {
				 success = DoScopeFunction(command, &speed, &duration, true);
			 }
			 return;
		 }
private: System::Void OkayButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->Hide();
			 return;
		 }
public:  System::Void ShowTheDialog(void) {

			 FormPtr->Show();
			 return;
		 }
public: static void SetSlewTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->SlewTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSlewTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->SlewTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

private: System::Void NButton_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 // Start slewing at guiding speed.  Stopped by "mouse up" routine
			 
			 OnOffGuiding(NORTH, ON);
		 }

private: System::Void NButton_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 // Stop slewing at guiding speed.  Started by "mouse down" routine

			 OnOffGuiding(NORTH, OFF);
		 }

private: System::Void SButton_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 // Start slewing at guiding speed.  Stopped by "mouse up" routine
			 
			 OnOffGuiding(SOUTH, ON);
		 }

private: System::Void SButton_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 // Stop slewing at guiding speed.  Started by "mouse down" routine

			 OnOffGuiding(SOUTH, OFF);
		 }

private: System::Void EButton_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 // Start slewing at guiding speed.  Stopped by "mouse up" routine
			 
			 OnOffGuiding(EAST, ON);
		 }

private: System::Void EButton_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 // Stop slewing at guiding speed.  Started by "mouse down" routine

			 OnOffGuiding(EAST, OFF);
		 }

private: System::Void WButton_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 // Start slewing at guiding speed.  Stopped by "mouse up" routine
			 
			 OnOffGuiding(WEST, ON);
		 }

private: System::Void WButton_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 // Stop slewing at guiding speed.  Started by "mouse down" routine

			 OnOffGuiding(WEST, OFF);
		 }
};
}
