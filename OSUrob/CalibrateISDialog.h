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
	/// Summary for CalibrateISDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CalibrateISDialog : public System::Windows::Forms::Form
	{
	public:
		static CalibrateISDialog ^FormPtr;
		CalibrateISDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			CalibrateISDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CalibrateISDialog()
		{
			if (components)
			{
				delete components;
				CalibrateISDialogExists = false;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  StepSizeNumeric;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::RadioButton^  CCWRadioButton;
	private: System::Windows::Forms::RadioButton^  CWRadioButton;
	private: System::Windows::Forms::Button^  StepButton;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::Button^  ColorCCDButton;

	private: System::Windows::Forms::Button^  EyeButton;






	private: System::Windows::Forms::Button^  CCDButton;
	private: System::Windows::Forms::Button^  SpectroButton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::Button^  GotoParkButton;
	private: System::Windows::Forms::Button^  FindHomeButton;
	private: System::Windows::Forms::Button^  OkayButton;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  CalibrateButton;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  PositionTextBox;



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
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->StepSizeNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CCWRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->CWRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->StepButton = (gcnew System::Windows::Forms::Button());
			this->PositionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SpectroButton = (gcnew System::Windows::Forms::Button());
			this->CCDButton = (gcnew System::Windows::Forms::Button());
			this->ColorCCDButton = (gcnew System::Windows::Forms::Button());
			this->EyeButton = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->CalibrateButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->GotoParkButton = (gcnew System::Windows::Forms::Button());
			this->FindHomeButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->OkayButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->StepSizeNumeric))->BeginInit();
			this->tableLayoutPanel6->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 61.99095F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.62443F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15.38461F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(476, 221);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33444F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33444F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33112F)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox3, 2, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(470, 131);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel5);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(150, 125);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Step Instrument Selector";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel5->Controls->Add(this->label2, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->label1, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->StepSizeNumeric, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->tableLayoutPanel6, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->StepButton, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->PositionTextBox, 1, 2);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 3;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.88679F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.5283F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.5283F)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(144, 106);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Position:";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Step Size:";
			// 
			// StepSizeNumeric
			// 
			this->StepSizeNumeric->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StepSizeNumeric->Location = System::Drawing::Point(75, 57);
			this->StepSizeNumeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->StepSizeNumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->StepSizeNumeric->Name = L"StepSizeNumeric";
			this->StepSizeNumeric->Size = System::Drawing::Size(60, 20);
			this->StepSizeNumeric->TabIndex = 3;
			this->StepSizeNumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 1;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel6->Controls->Add(this->CCWRadioButton, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->CWRadioButton, 0, 0);
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(59, 42);
			this->tableLayoutPanel6->TabIndex = 4;
			// 
			// CCWRadioButton
			// 
			this->CCWRadioButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CCWRadioButton->AutoSize = true;
			this->CCWRadioButton->Location = System::Drawing::Point(4, 24);
			this->CCWRadioButton->Name = L"CCWRadioButton";
			this->CCWRadioButton->Size = System::Drawing::Size(50, 15);
			this->CCWRadioButton->TabIndex = 2;
			this->CCWRadioButton->TabStop = true;
			this->CCWRadioButton->Text = L"CCW";
			this->CCWRadioButton->UseVisualStyleBackColor = true;
			// 
			// CWRadioButton
			// 
			this->CWRadioButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CWRadioButton->AutoSize = true;
			this->CWRadioButton->Location = System::Drawing::Point(8, 3);
			this->CWRadioButton->Name = L"CWRadioButton";
			this->CWRadioButton->Size = System::Drawing::Size(43, 15);
			this->CWRadioButton->TabIndex = 1;
			this->CWRadioButton->TabStop = true;
			this->CWRadioButton->Text = L"CW";
			this->CWRadioButton->UseVisualStyleBackColor = true;
			// 
			// StepButton
			// 
			this->StepButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StepButton->Location = System::Drawing::Point(78, 15);
			this->StepButton->Name = L"StepButton";
			this->StepButton->Size = System::Drawing::Size(60, 23);
			this->StepButton->TabIndex = 5;
			this->StepButton->Text = L"Step";
			this->StepButton->UseVisualStyleBackColor = true;
			this->StepButton->Click += gcnew System::EventHandler(this, &CalibrateISDialog::StepButton_Clicked);
			// 
			// PositionTextBox
			// 
			this->PositionTextBox->Location = System::Drawing::Point(75, 82);
			this->PositionTextBox->Name = L"PositionTextBox";
			this->PositionTextBox->Size = System::Drawing::Size(60, 20);
			this->PositionTextBox->TabIndex = 7;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel7);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(159, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(150, 125);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Set Port Position";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 2;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel7->Controls->Add(this->SpectroButton, 1, 1);
			this->tableLayoutPanel7->Controls->Add(this->CCDButton, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->ColorCCDButton, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->EyeButton, 0, 0);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 2;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(144, 106);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// SpectroButton
			// 
			this->SpectroButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SpectroButton->Location = System::Drawing::Point(78, 68);
			this->SpectroButton->Name = L"SpectroButton";
			this->SpectroButton->Size = System::Drawing::Size(59, 23);
			this->SpectroButton->TabIndex = 3;
			this->SpectroButton->Text = L"Spectro";
			this->SpectroButton->UseVisualStyleBackColor = true;
			this->SpectroButton->Click += gcnew System::EventHandler(this, &CalibrateISDialog::SpectroButton_Clicked);
			// 
			// CCDButton
			// 
			this->CCDButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CCDButton->Location = System::Drawing::Point(6, 68);
			this->CCDButton->Name = L"CCDButton";
			this->CCDButton->Size = System::Drawing::Size(59, 23);
			this->CCDButton->TabIndex = 2;
			this->CCDButton->Text = L"CCD";
			this->CCDButton->UseVisualStyleBackColor = true;
			this->CCDButton->Click += gcnew System::EventHandler(this, &CalibrateISDialog::CCDButton_Clicked);
			// 
			// ColorCCDButton
			// 
			this->ColorCCDButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ColorCCDButton->Location = System::Drawing::Point(78, 15);
			this->ColorCCDButton->Name = L"ColorCCDButton";
			this->ColorCCDButton->Size = System::Drawing::Size(59, 23);
			this->ColorCCDButton->TabIndex = 1;
			this->ColorCCDButton->Text = L"Color";
			this->ColorCCDButton->UseVisualStyleBackColor = true;
			this->ColorCCDButton->Click += gcnew System::EventHandler(this, &CalibrateISDialog::ColorCCDButton_Clicked);
			// 
			// EyeButton
			// 
			this->EyeButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EyeButton->Location = System::Drawing::Point(6, 15);
			this->EyeButton->Name = L"EyeButton";
			this->EyeButton->Size = System::Drawing::Size(59, 23);
			this->EyeButton->TabIndex = 0;
			this->EyeButton->Text = L"Eye";
			this->EyeButton->UseVisualStyleBackColor = true;
			this->EyeButton->Click += gcnew System::EventHandler(this, &CalibrateISDialog::EyeButton_Clicked);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->CalibrateButton);
			this->groupBox3->Location = System::Drawing::Point(315, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(152, 100);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Calibrate";
			// 
			// CalibrateButton
			// 
			this->CalibrateButton->Location = System::Drawing::Point(43, 54);
			this->CalibrateButton->Name = L"CalibrateButton";
			this->CalibrateButton->Size = System::Drawing::Size(75, 23);
			this->CalibrateButton->TabIndex = 0;
			this->CalibrateButton->Text = L"Calibrate";
			this->CalibrateButton->UseVisualStyleBackColor = true;
			this->CalibrateButton->Click += gcnew System::EventHandler(this, &CalibrateISDialog::CalibrateButton_Clicked);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel3->Controls->Add(this->SaveButton, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->GotoParkButton, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->FindHomeButton, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 140);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(470, 43);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// SaveButton
			// 
			this->SaveButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SaveButton->Location = System::Drawing::Point(361, 10);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(59, 23);
			this->SaveButton->TabIndex = 3;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &CalibrateISDialog::SaveButton_Clicked);
			// 
			// GotoParkButton
			// 
			this->GotoParkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GotoParkButton->Location = System::Drawing::Point(200, 10);
			this->GotoParkButton->Name = L"GotoParkButton";
			this->GotoParkButton->Size = System::Drawing::Size(67, 23);
			this->GotoParkButton->TabIndex = 2;
			this->GotoParkButton->Text = L"Goto Park";
			this->GotoParkButton->UseVisualStyleBackColor = true;
			this->GotoParkButton->Click += gcnew System::EventHandler(this, &CalibrateISDialog::GotoParkButton_Clicked);
			// 
			// FindHomeButton
			// 
			this->FindHomeButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FindHomeButton->Location = System::Drawing::Point(39, 10);
			this->FindHomeButton->Name = L"FindHomeButton";
			this->FindHomeButton->Size = System::Drawing::Size(77, 23);
			this->FindHomeButton->TabIndex = 1;
			this->FindHomeButton->Text = L"Find Home";
			this->FindHomeButton->UseVisualStyleBackColor = true;
			this->FindHomeButton->Click += gcnew System::EventHandler(this, &CalibrateISDialog::FindHomeButton_Clicked);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel4->Controls->Add(this->OkayButton, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 189);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(470, 29);
			this->tableLayoutPanel4->TabIndex = 2;
			// 
			// OkayButton
			// 
			this->OkayButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkayButton->Location = System::Drawing::Point(205, 3);
			this->OkayButton->Name = L"OkayButton";
			this->OkayButton->Size = System::Drawing::Size(59, 23);
			this->OkayButton->TabIndex = 2;
			this->OkayButton->Text = L"Okay";
			this->OkayButton->UseVisualStyleBackColor = true;
			this->OkayButton->Click += gcnew System::EventHandler(this, &CalibrateISDialog::OkayButton_Clicked);
			// 
			// CalibrateISDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(476, 221);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"CalibrateISDialog";
			this->Text = L"CalibrateISDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->StepSizeNumeric))->EndInit();
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void StepButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 short numSteps;
			 bool Success;
			 char buffer[80];

			 numSteps = ((short) CalibrateISDialog::FormPtr->StepSizeNumeric->Value);
			 if (CalibrateISDialog::FormPtr->CCWRadioButton->Checked)
				 numSteps = - numSteps;
			 Success = StepSelectorMotor(numSteps);
			 if (Success) {
				ISSettings.CurrentStepPosition += numSteps;
				if (ISSettings.CurrentStepPosition > 1600)
					ISSettings.CurrentStepPosition -= 1600;
				else if (ISSettings.CurrentStepPosition < 0)
					ISSettings.CurrentStepPosition += 1600;
				sprintf_s(buffer, sizeof(buffer), "%d", ISSettings.CurrentStepPosition);
				FormPtr->SetPositionTextBox(buffer);
			 }

		 }
private: System::Void EyeButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 ISSettings.PortStepPositions[EYEPORT-1] = ISSettings.CurrentStepPosition;
		 }
private: System::Void ColorCCDButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 ISSettings.PortStepPositions[COLORCCDPORT-1] = ISSettings.CurrentStepPosition;
		 }
private: System::Void CCDButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 ISSettings.PortStepPositions[CCDPORT-1] = ISSettings.CurrentStepPosition;
		 }

private: System::Void FindHomeButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];
			 SelectPort(HOMEPORT);
			 sprintf_s(buffer, sizeof(buffer), "%d", ISSettings.CurrentStepPosition);
			 FormPtr->SetPositionTextBox(buffer);
		 }
private: System::Void SpectroButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 ISSettings.PortStepPositions[SPECTROPORT-1] = ISSettings.CurrentStepPosition;
		 }
private: System::Void GotoParkButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];
			 SelectPort(PARKINGPORT);
			 sprintf_s(buffer, sizeof(buffer), "%d", ISSettings.CurrentStepPosition);
			 FormPtr->SetPositionTextBox(buffer);
		 }
private: System::Void SaveButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[160];
			 FILE *fptr;

			 fopen_s(&fptr, INSTRUMENTSELECTORSETTINGSFILE, "w");
			 if (fptr != NULL) {
				 fprintf_s(fptr, "%d %d %d %d %d\n", ISSettings.PortStepPositions[0],
					 ISSettings.PortStepPositions[1], ISSettings.PortStepPositions[2],
					 ISSettings.PortStepPositions[3], ISSettings.PortStepPositions[4]);
				 fclose(fptr);
				 sprintf_s(buffer, sizeof(buffer), "Wrote port positions: %d %d %d %d %d\n", ISSettings.PortStepPositions[0],
					 ISSettings.PortStepPositions[1], ISSettings.PortStepPositions[2],
					 ISSettings.PortStepPositions[3], ISSettings.PortStepPositions[4]);
				 MessageBox(buffer, OKAY);
			 }

		 }
private: System::Void OkayButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 CalibrateISDialog::FormPtr->Hide();
		 }
private: System::Void CalibrateButton_Clicked(System::Object^  sender, System::EventArgs^  e) {
		MessageBox("Info - We on longer need to calibrate instrument selector\n", OKAY);
		return;
		 }
public: static void SetPositionTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->PositionTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetPositionTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		FormPtr->PositionTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
};
}
