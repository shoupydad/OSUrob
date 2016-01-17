#pragma once

#include "doRoutines.h"
#include "RoboFocuser.h"

namespace OSUrob {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdjustTelescopeFocusDialog
	/// </summary>
	public ref class AdjustTelescopeFocusDialog : public System::Windows::Forms::Form
	{
	public:

		static AdjustTelescopeFocusDialog^ FormPtr;
		AdjustTelescopeFocusDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			AdjustTelescopeFocusDialogExists = true;
			FormPtr = this;
			this->UpdateComponentValues();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdjustTelescopeFocusDialog()
		{
			if (components)
			{
				delete components;
			}
			AdjustTelescopeFocusDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  OkayButton;
	private: System::Windows::Forms::Button^  RefreshButton;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  TemperatureTextBox;
	private: System::Windows::Forms::TextBox^  CurrentPositionTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::RadioButton^  InRadioButton;
	private: System::Windows::Forms::RadioButton^  OutRadioButton;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  StepSizeNumericUpDown;
	private: System::Windows::Forms::Button^  StepButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Button^  DeleteButton;
	private: System::Windows::Forms::Button^  NewButton;
	private: System::Windows::Forms::Button^  SetButton;
	private: System::Windows::Forms::Button^  GoToButton;
	private: System::Windows::Forms::ComboBox^  FocusListComboBox;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::TextBox^  AbsolutePositionTextBox;

	private: System::Windows::Forms::Button^  AbsoluteGoToButton;

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
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TemperatureTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentPositionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->InRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->OutRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->StepSizeNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->StepButton = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->NewButton = (gcnew System::Windows::Forms::Button());
			this->SetButton = (gcnew System::Windows::Forms::Button());
			this->GoToButton = (gcnew System::Windows::Forms::Button());
			this->FocusListComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->AbsoluteGoToButton = (gcnew System::Windows::Forms::Button());
			this->AbsolutePositionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->OkayButton = (gcnew System::Windows::Forms::Button());
			this->RefreshButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StepSizeNumericUpDown))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(301, 262);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				38.64407F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				61.35593F)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(295, 102);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel4);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(108, 96);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Current";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				54.38596F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				45.61404F)));
			this->tableLayoutPanel4->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->TemperatureTextBox, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->CurrentPositionTextBox, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(102, 77);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Temp:";
			// 
			// TemperatureTextBox
			// 
			this->TemperatureTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->TemperatureTextBox->Location = System::Drawing::Point(58, 9);
			this->TemperatureTextBox->Name = L"TemperatureTextBox";
			this->TemperatureTextBox->ReadOnly = true;
			this->TemperatureTextBox->Size = System::Drawing::Size(35, 20);
			this->TemperatureTextBox->TabIndex = 1;
			this->TemperatureTextBox->Text = L"0000";
			// 
			// CurrentPositionTextBox
			// 
			this->CurrentPositionTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentPositionTextBox->Location = System::Drawing::Point(58, 47);
			this->CurrentPositionTextBox->Name = L"CurrentPositionTextBox";
			this->CurrentPositionTextBox->ReadOnly = true;
			this->CurrentPositionTextBox->Size = System::Drawing::Size(35, 20);
			this->CurrentPositionTextBox->TabIndex = 2;
			this->CurrentPositionTextBox->Text = L"0000";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Position:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel5);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(117, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(175, 96);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Relative Step";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 3;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				57.83133F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				42.16867F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				58)));
			this->tableLayoutPanel5->Controls->Add(this->InRadioButton, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->OutRadioButton, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->label3, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->StepSizeNumericUpDown, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->StepButton, 2, 1);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 2;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(169, 77);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// InRadioButton
			// 
			this->InRadioButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->InRadioButton->AutoSize = true;
			this->InRadioButton->Location = System::Drawing::Point(3, 10);
			this->InRadioButton->Name = L"InRadioButton";
			this->InRadioButton->Size = System::Drawing::Size(34, 17);
			this->InRadioButton->TabIndex = 0;
			this->InRadioButton->TabStop = true;
			this->InRadioButton->Text = L"In";
			this->InRadioButton->UseVisualStyleBackColor = true;
			this->InRadioButton->CheckedChanged += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::InRadioButton_CheckedChanged);
			// 
			// OutRadioButton
			// 
			this->OutRadioButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->OutRadioButton->AutoSize = true;
			this->OutRadioButton->Location = System::Drawing::Point(3, 49);
			this->OutRadioButton->Name = L"OutRadioButton";
			this->OutRadioButton->Size = System::Drawing::Size(42, 17);
			this->OutRadioButton->TabIndex = 1;
			this->OutRadioButton->TabStop = true;
			this->OutRadioButton->Text = L"Out";
			this->OutRadioButton->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(77, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Size:";
			// 
			// StepSizeNumericUpDown
			// 
			this->StepSizeNumericUpDown->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StepSizeNumericUpDown->Location = System::Drawing::Point(113, 9);
			this->StepSizeNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->StepSizeNumericUpDown->Name = L"StepSizeNumericUpDown";
			this->StepSizeNumericUpDown->Size = System::Drawing::Size(42, 20);
			this->StepSizeNumericUpDown->TabIndex = 3;
			// 
			// StepButton
			// 
			this->StepButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StepButton->Location = System::Drawing::Point(118, 46);
			this->StepButton->Name = L"StepButton";
			this->StepButton->Size = System::Drawing::Size(42, 23);
			this->StepButton->TabIndex = 4;
			this->StepButton->Text = L"Step";
			this->StepButton->UseVisualStyleBackColor = true;
			this->StepButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::StepButton_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel6);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(3, 111);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(295, 102);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Focus Positions";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 3;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47.85714F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				52.14286F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				159)));
			this->tableLayoutPanel6->Controls->Add(this->DeleteButton, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->NewButton, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->SetButton, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->GoToButton, 1, 1);
			this->tableLayoutPanel6->Controls->Add(this->FocusListComboBox, 2, 0);
			this->tableLayoutPanel6->Controls->Add(this->groupBox4, 2, 1);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 39.75904F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 60.24096F)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(289, 83);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// DeleteButton
			// 
			this->DeleteButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DeleteButton->Location = System::Drawing::Point(66, 5);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(59, 23);
			this->DeleteButton->TabIndex = 1;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::DeleteButton_Click);
			// 
			// NewButton
			// 
			this->NewButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->NewButton->Location = System::Drawing::Point(3, 5);
			this->NewButton->Name = L"NewButton";
			this->NewButton->Size = System::Drawing::Size(56, 23);
			this->NewButton->TabIndex = 0;
			this->NewButton->Text = L"New";
			this->NewButton->UseVisualStyleBackColor = true;
			this->NewButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::NewButton_Click);
			// 
			// SetButton
			// 
			this->SetButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SetButton->Location = System::Drawing::Point(3, 46);
			this->SetButton->Name = L"SetButton";
			this->SetButton->Size = System::Drawing::Size(56, 23);
			this->SetButton->TabIndex = 2;
			this->SetButton->Text = L"Set";
			this->SetButton->UseVisualStyleBackColor = true;
			this->SetButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::SetButton_Click);
			// 
			// GoToButton
			// 
			this->GoToButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GoToButton->Location = System::Drawing::Point(66, 46);
			this->GoToButton->Name = L"GoToButton";
			this->GoToButton->Size = System::Drawing::Size(59, 23);
			this->GoToButton->TabIndex = 3;
			this->GoToButton->Text = L"GoTo";
			this->GoToButton->UseVisualStyleBackColor = true;
			this->GoToButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::GoToButton_Click);
			// 
			// FocusListComboBox
			// 
			this->FocusListComboBox->FormattingEnabled = true;
			this->FocusListComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"40 mm Eyepiece", L"Apogee Alta U8300 CCD",
					L"LHIRES III", L"Orion Starshoot Pro V2.0"
			});
			this->FocusListComboBox->Location = System::Drawing::Point(132, 3);
			this->FocusListComboBox->MaxDropDownItems = 16;
			this->FocusListComboBox->Name = L"FocusListComboBox";
			this->FocusListComboBox->Size = System::Drawing::Size(144, 21);
			this->FocusListComboBox->Sorted = true;
			this->FocusListComboBox->TabIndex = 4;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tableLayoutPanel7);
			this->groupBox4->Location = System::Drawing::Point(132, 36);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(151, 44);
			this->groupBox4->TabIndex = 5;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Absolute GoTo";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 2;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel7->Controls->Add(this->AbsoluteGoToButton, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->AbsolutePositionTextBox, 0, 0);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 1;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(145, 25);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// AbsoluteGoToButton
			// 
			this->AbsoluteGoToButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AbsoluteGoToButton->Location = System::Drawing::Point(79, 3);
			this->AbsoluteGoToButton->Name = L"AbsoluteGoToButton";
			this->AbsoluteGoToButton->Size = System::Drawing::Size(59, 19);
			this->AbsoluteGoToButton->TabIndex = 4;
			this->AbsoluteGoToButton->Text = L"GoTo";
			this->AbsoluteGoToButton->UseVisualStyleBackColor = true;
			this->AbsoluteGoToButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::AbsoluteGoToButton_Click);
			// 
			// AbsolutePositionTextBox
			// 
			this->AbsolutePositionTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->AbsolutePositionTextBox->Location = System::Drawing::Point(3, 3);
			this->AbsolutePositionTextBox->Name = L"AbsolutePositionTextBox";
			this->AbsolutePositionTextBox->Size = System::Drawing::Size(66, 20);
			this->AbsolutePositionTextBox->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->OkayButton, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->RefreshButton, 1, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 219);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(295, 40);
			this->tableLayoutPanel3->TabIndex = 2;
			// 
			// OkayButton
			// 
			this->OkayButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkayButton->Location = System::Drawing::Point(36, 8);
			this->OkayButton->Name = L"OkayButton";
			this->OkayButton->Size = System::Drawing::Size(75, 23);
			this->OkayButton->TabIndex = 0;
			this->OkayButton->Text = L"Okay";
			this->OkayButton->UseVisualStyleBackColor = true;
			this->OkayButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::OkayButton_Click);
			// 
			// RefreshButton
			// 
			this->RefreshButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->RefreshButton->Location = System::Drawing::Point(183, 8);
			this->RefreshButton->Name = L"RefreshButton";
			this->RefreshButton->Size = System::Drawing::Size(75, 23);
			this->RefreshButton->TabIndex = 1;
			this->RefreshButton->Text = L"Refresh";
			this->RefreshButton->UseVisualStyleBackColor = true;
			this->RefreshButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::RefreshButton_Click);
			// 
			// AdjustTelescopeFocusDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(301, 262);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"AdjustTelescopeFocusDialog";
			this->Text = L"Adjust Telescope Focus";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StepSizeNumericUpDown))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void OkayButton_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Hide();
	
	}


	private: System::Void InRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void StepButton_Click(System::Object^  sender, System::EventArgs^  e) {

		int stepSize, currentPosition, newPosition;
		bool success;

		// Get value and direction to change focus position by

		stepSize = System::Decimal::ToInt32(this->StepSizeNumericUpDown->Value);
		if (this->InRadioButton->Checked) {
			stepSize = -stepSize;
		}

		// Compute new position

		currentPosition = RoboFocuser::Ptr->GetPosition();
		if (currentPosition < 0) {
			MessageBox("*** Warning - Can't move focuser, got bad current position (StepButton_Click)\n", OKAY);
			return;
		}
		newPosition = currentPosition + stepSize;

		// Move Focuser

		success = RoboFocuser::Ptr->GoToPosition(newPosition);
		if (!success) {
			MessageBox("*** Warning - Failed to move focuser (StepButton_Click)\n", OKAY);
			return;
		}

		// Update dialog components

		this->UpdateComponentValues();

	}


	private: System::Void UpdateComponentValues() {

		char buffer[80];
		int curPosition, rawTemp;
		double curTemp;

		// Update combo box with current state of named focus positions

		this->FocusListComboBox->Items->Clear();
		String ^name;
		for (int i = 0; i < FocuserSettings.numFocusPositions; i++) {
			sprintf_s(buffer, "%04d %06.1f %s", FocuserSettings.FocusPositionValues[i], FocuserSettings.FocusPositionTemps[i],
				FocuserSettings.FocusPositionNames[i]);
			name = gcnew String(buffer);
			this->FocusListComboBox->Items->Add(name);
			delete name;
		}
		this->FocusListComboBox->SelectedIndex = 0;

		// Update other components

		curPosition = RoboFocuser::Ptr->GetPosition();
		sprintf_s(buffer, "%04d", curPosition);
		String ^string;
		string = gcnew String(buffer);
		this->CurrentPositionTextBox->Text = string;
		delete string;

		rawTemp = RoboFocuser::Ptr->GetTemperature();
		if (rawTemp > 0) {
			curTemp = FocuserSettings.TempCalSlope * rawTemp + FocuserSettings.TempCalZeroPoint;
		}
		else {
			curTemp = -99.0;
		}
		FocuserSettings.rawTemperature = rawTemp;
		FocuserSettings.Temperature = curTemp;
		sprintf_s(buffer, sizeof(buffer), "%6.1f", curTemp);
		string = gcnew String(buffer);
		this->TemperatureTextBox->Text = string;
		delete string;

	}


	private: System::Void NewButton_Click(System::Object^  sender, System::EventArgs^  e) {

		int i;
		String ^buffer;
		char buf[80];

		// Check if we have room for new position in list

		if (FocuserSettings.numFocusPositions >= MAX_NUM_FOCUS_POSITIONS) {
			MessageBox("*** Warning - No room for new focus position. Change MAX_NUM_FOCUS_POSITIONS (NewButton_Click)\n", OKAY);
			return;
		}

		// Get name, position & temperature of new focus position

		this->FocusListComboBox->SelectAll();
		buffer = this->FocusListComboBox->SelectedText;
		for (i = 0; i < buffer->Length; i++) buf[i] = (char) buffer[i];
		buf[i] = 0;
		strcpy_s(FocuserSettings.FocusPositionNames[FocuserSettings.numFocusPositions], MAX_FOCUS_POSITION_NAME_LENGTH, buf);
		buffer = this->CurrentPositionTextBox->Text;
		for (i = 0; i < buffer->Length; i++) buf[i] = (char)buffer[i];
		buf[i] = 0;
		sscanf_s(buf, "%d", &FocuserSettings.FocusPositionValues[FocuserSettings.numFocusPositions]);
		buffer = this->TemperatureTextBox->Text;
		for (i = 0; i < buffer->Length; i++) buf[i] = (char)buffer[i];
		buf[i] = 0;
		sscanf_s(buf, "%lf", &FocuserSettings.FocusPositionTemps[FocuserSettings.numFocusPositions]);
		FocuserSettings.numFocusPositions++;

		// Update dialog components

		this->UpdateComponentValues();
	}


	private: System::Void DeleteButton_Click(System::Object^  sender, System::EventArgs^  e) {

		int i, indexSelected;

		// Get text of selected focus position to delete

		indexSelected = this->FocusListComboBox->SelectedIndex;
		if (indexSelected != FocuserSettings.numFocusPositions-1) {
			for (i = indexSelected; i < FocuserSettings.numFocusPositions - 1; i++) {
				strcpy_s(FocuserSettings.FocusPositionNames[i], MAX_FOCUS_POSITION_NAME_LENGTH,
					FocuserSettings.FocusPositionNames[i + 1]);
				FocuserSettings.FocusPositionValues[i] = FocuserSettings.FocusPositionValues[i + 1];
				FocuserSettings.FocusPositionTemps[i] = FocuserSettings.FocusPositionTemps[i + 1];
			}
		}
		FocuserSettings.numFocusPositions--;
		this->UpdateComponentValues();
	}


	private: System::Void SetButton_Click(System::Object^  sender, System::EventArgs^  e) {

		int indexSelected, curPosition, rawTemp;
		double calTemp;

		indexSelected = this->FocusListComboBox->SelectedIndex;
		curPosition = RoboFocuser::Ptr->GetPosition();
		rawTemp = RoboFocuser::Ptr->GetTemperature();
		calTemp = FocuserSettings.TempCalSlope * rawTemp + FocuserSettings.TempCalZeroPoint;
		FocuserSettings.FocusPositionTemps[indexSelected] = calTemp;
		FocuserSettings.FocusPositionValues[indexSelected] = curPosition;

		this->UpdateComponentValues();

	}


	private: System::Void GoToButton_Click(System::Object^  sender, System::EventArgs^  e) {

		int indexSelected;
		bool success;
		char message[160];

		indexSelected = this->FocusListComboBox->SelectedIndex;

		success = RoboFocuser::Ptr->GoToPosition(FocuserSettings.FocusPositionValues[indexSelected]);
		if (!success) {
			sprintf_s(message, sizeof(message), "*** Warning - couldn't move to focus position %d (%s)",
				FocuserSettings.FocusPositionValues[indexSelected], FocuserSettings.FocusPositionNames[indexSelected]);
			MessageBox(message, OKAY);
		}

		this->UpdateComponentValues();

	}


	private: System::Void AbsoluteGoToButton_Click(System::Object^  sender, System::EventArgs^  e) {

		int newPosition, i;
		String ^buffer;
		char buf[20], message[160];
		bool success;

		// Get position from text box

		buffer = this->AbsolutePositionTextBox->Text;
		for (i = 0; i < buffer->Length; i++) buf[i] = (char) buffer[i];
		sscanf_s(buf, "%d", &newPosition);
		success = RoboFocuser::Ptr->GoToPosition(newPosition);
		if (!success) {
			sprintf_s(message, sizeof(message), "*** Warning - couldn't move to focus position %d", newPosition);
			MessageBox(message, OKAY);
		}

		this->UpdateComponentValues();

	}


	private: System::Void RefreshButton_Click(System::Object^  sender, System::EventArgs^  e) {

		this->UpdateComponentValues();
	}
};
}
