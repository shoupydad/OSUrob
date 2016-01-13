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
	/// Summary for CalibrateFilterWheelDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CalibrateFilterWheelDialog : public System::Windows::Forms::Form
	{
	public:
		static CalibrateFilterWheelDialog^ FormPtr;
		CalibrateFilterWheelDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CalibrateFilterWheelDialog()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  StepSizeNumeric;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::RadioButton^  CCWRadioButton;
	private: System::Windows::Forms::RadioButton^  CWRadioButton;
	private: System::Windows::Forms::Button^  StepButton;
	private: System::Windows::Forms::TextBox^  PositionTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;





	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  SaveButton;

	private: System::Windows::Forms::Button^  FindHomeButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Button^  OkayButton;
	private: System::Windows::Forms::Button^  SetButton;
	private: System::Windows::Forms::ListBox^  FilterListBox;
	private: System::Windows::Forms::Button^  CalibrateButton;



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
			this->SetButton = (gcnew System::Windows::Forms::Button());
			this->FilterListBox = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CalibrateButton = (gcnew System::Windows::Forms::Button());
			this->FindHomeButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
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
			this->tableLayoutPanel1->Size = System::Drawing::Size(289, 266);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				38.16327F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				28.36735F)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(283, 158);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel5);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(156, 152);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Step Filter Wheel";
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
			this->tableLayoutPanel5->Size = System::Drawing::Size(150, 133);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Position:";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Step Size:";
			// 
			// StepSizeNumeric
			// 
			this->StepSizeNumeric->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StepSizeNumeric->Location = System::Drawing::Point(78, 74);
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
			this->StepButton->Location = System::Drawing::Point(82, 22);
			this->StepButton->Name = L"StepButton";
			this->StepButton->Size = System::Drawing::Size(60, 23);
			this->StepButton->TabIndex = 5;
			this->StepButton->Text = L"Step";
			this->StepButton->UseVisualStyleBackColor = true;
			this->StepButton->Click += gcnew System::EventHandler(this, &CalibrateFilterWheelDialog::StepButton_Clicked);
			// 
			// PositionTextBox
			// 
			this->PositionTextBox->Location = System::Drawing::Point(78, 103);
			this->PositionTextBox->Name = L"PositionTextBox";
			this->PositionTextBox->Size = System::Drawing::Size(60, 20);
			this->PositionTextBox->TabIndex = 7;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel7);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(165, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(115, 152);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Set Filter Position";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 1;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel7->Controls->Add(this->SetButton, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->FilterListBox, 0, 0);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 2;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(109, 133);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// SetButton
			// 
			this->SetButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SetButton->Location = System::Drawing::Point(24, 88);
			this->SetButton->Name = L"SetButton";
			this->SetButton->Size = System::Drawing::Size(60, 23);
			this->SetButton->TabIndex = 6;
			this->SetButton->Text = L"Set";
			this->SetButton->UseVisualStyleBackColor = true;
			this->SetButton->Click += gcnew System::EventHandler(this, &CalibrateFilterWheelDialog::SetButton_Clicked);
			// 
			// FilterListBox
			// 
			this->FilterListBox->FormattingEnabled = true;
			this->FilterListBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"UV Filter", L"B Filter", L"V Filter", L"R Filter", 
				L"I Flter", L"Clear Filter"});
			this->FilterListBox->Location = System::Drawing::Point(3, 3);
			this->FilterListBox->Name = L"FilterListBox";
			this->FilterListBox->Size = System::Drawing::Size(85, 56);
			this->FilterListBox->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33444F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33444F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33112F)));
			this->tableLayoutPanel3->Controls->Add(this->CalibrateButton, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->FindHomeButton, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->SaveButton, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 167);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(283, 54);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// CalibrateButton
			// 
			this->CalibrateButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CalibrateButton->Location = System::Drawing::Point(102, 15);
			this->CalibrateButton->Name = L"CalibrateButton";
			this->CalibrateButton->Size = System::Drawing::Size(77, 23);
			this->CalibrateButton->TabIndex = 4;
			this->CalibrateButton->Text = L"Calibrate";
			this->CalibrateButton->UseVisualStyleBackColor = true;
			this->CalibrateButton->Click += gcnew System::EventHandler(this, &CalibrateFilterWheelDialog::CalibrateButton_Clicked);
			// 
			// FindHomeButton
			// 
			this->FindHomeButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FindHomeButton->Location = System::Drawing::Point(8, 15);
			this->FindHomeButton->Name = L"FindHomeButton";
			this->FindHomeButton->Size = System::Drawing::Size(77, 23);
			this->FindHomeButton->TabIndex = 1;
			this->FindHomeButton->Text = L"Find Home";
			this->FindHomeButton->UseVisualStyleBackColor = true;
			this->FindHomeButton->Click += gcnew System::EventHandler(this, &CalibrateFilterWheelDialog::FindHomeButton_Clicked);
			// 
			// SaveButton
			// 
			this->SaveButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SaveButton->Location = System::Drawing::Point(206, 15);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(59, 23);
			this->SaveButton->TabIndex = 3;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &CalibrateFilterWheelDialog::SaveButton_Clicked);
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
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 227);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(283, 36);
			this->tableLayoutPanel4->TabIndex = 2;
			// 
			// OkayButton
			// 
			this->OkayButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkayButton->Location = System::Drawing::Point(112, 6);
			this->OkayButton->Name = L"OkayButton";
			this->OkayButton->Size = System::Drawing::Size(59, 23);
			this->OkayButton->TabIndex = 2;
			this->OkayButton->Text = L"Okay";
			this->OkayButton->UseVisualStyleBackColor = true;
			this->OkayButton->Click += gcnew System::EventHandler(this, &CalibrateFilterWheelDialog::OkayButton_Clicked);
			// 
			// CalibrateFilterWheelDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(289, 266);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"CalibrateFilterWheelDialog";
			this->Text = L"CalibrateFilterWheelDialog";
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
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void StepButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 short numSteps;
			 char buffer[80];

			 numSteps = ((short) CalibrateFilterWheelDialog::FormPtr->StepSizeNumeric->Value);
			 if (CalibrateFilterWheelDialog::FormPtr->CCWRadioButton->Checked)
				 numSteps = - numSteps;
			 StepFWMotor(numSteps);
			 FWSettings.CurrentStepPosition += numSteps;
			 sprintf_s(buffer, sizeof(buffer), "%d", FWSettings.CurrentStepPosition);
			 FormPtr->SetPositionTextBox(buffer);
		 }
private: System::Void SetButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char message[160];
			 int index;

			 index = FormPtr->FilterListBox->SelectedIndex+1;
			 FWSettings.FilterStepPositions[index] = FWSettings.CurrentStepPosition;
			 sprintf_s(message, sizeof(message), "Set filter #%d to step position %d.\n",
				 index, FWSettings.CurrentStepPosition);
			 MessageBox(message, OKAY);
			 return;
		 }
private: System::Void FindHomeButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];
			 SetFilterWheelPosition(0);
			 sprintf_s(buffer, sizeof(buffer), "%d", FWSettings.CurrentStepPosition);
			 FormPtr->SetPositionTextBox(buffer);
		 }
private: System::Void SaveButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[160];
			 FILE *fptr;

			 fopen_s(&fptr, FILTERWHEELSETTINGSFILE, "w");
			 if (fptr != NULL) {
				 fprintf_s(fptr, "%d %d %d %d %d %d %d\n", FWSettings.FilterStepPositions[0],
					 FWSettings.FilterStepPositions[1], FWSettings.FilterStepPositions[2],
					 FWSettings.FilterStepPositions[3], FWSettings.FilterStepPositions[4],
					 FWSettings.FilterStepPositions[5], FWSettings.FilterStepPositions[6]);
				 fclose(fptr);
				 sprintf_s(buffer, sizeof(buffer), "Wrote filter positions: %d %d %d %d %d %d %d\n",
					 FWSettings.FilterStepPositions[0],
					 FWSettings.FilterStepPositions[1], FWSettings.FilterStepPositions[2],
					 FWSettings.FilterStepPositions[3], FWSettings.FilterStepPositions[4],
					 FWSettings.FilterStepPositions[5], FWSettings.FilterStepPositions[6]);
				 MessageBox(buffer, OKAY);
			 }
		 }
private: System::Void OkayButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->Hide();
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

private: System::Void CalibrateButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 bool success;
			 int nSteps, answer;
			 char Message[160];

			 // Count steps for full circle (home to home)

				// Move to home position

			 success = SetFilterWheelPosition(0);
			 if (! success) {
				 MessageBox("Can't find home position, aborting calibration", OKAY);
				 return;
			 }

				// Count steps until off home

			 MessageBox("Counting steps until off home", OKAY);
			 nSteps = 0;
			 while (GetFWStatus() && (nSteps < 200)) {
				 StepFWMotor(-1);
				 nSteps++;
			 }
			 if (nSteps >= 200) {
				 MessageBox("Can't get off home position, aborting calibrations", OKAY);
				 return;
			 }
			 sprintf_s(Message, sizeof(Message), "Off home, counted %d steps so far", nSteps);
			 answer = MessageBox(Message, OKAY);
			 if (answer == CANCEL)
				 return;

				// Count steps until back at home

			 while ((! GetFWStatus()) && (nSteps < 1000)) {
				 StepFWMotor(-1);
				 nSteps++;
			 }

			 if (nSteps >= 1000) {
				 MessageBox("Didn't find home again in 1000 steps, aborting calibrations.", OKAY);
				 return;
			 }
			 sprintf_s(Message, sizeof(Message), "Counted %d steps in full rotation (home-to-home)", nSteps);
			 MessageBox(Message, OKAY);

			 return;
		 }
};
}
