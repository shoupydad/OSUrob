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
	/// Summary for AdjustFocusDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AdjustFocusDialog : public System::Windows::Forms::Form
	{
	public:
		static AdjustFocusDialog ^FormPtr;
		AdjustFocusDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			AdjustFocusDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdjustFocusDialog()
		{
			if (components)
			{
				delete components;
			}
			AdjustFocusDialogExists = true;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;


	private: System::Windows::Forms::Button^  StepButton;



	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  DurationTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Button^  CancelButton;

	private: System::Windows::Forms::Button^  OkayButton;
	private: System::Windows::Forms::RadioButton^  InRadioButton;
	private: System::Windows::Forms::RadioButton^  OutRadioButton;

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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->StepButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->DurationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->OkayButton = (gcnew System::Windows::Forms::Button());
			this->InRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->OutRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->tableLayoutPanel1->SuspendLayout();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel1->Controls->Add(this->splitContainer1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(204, 182);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 3);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->tableLayoutPanel2);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->StepButton);
			this->splitContainer1->Size = System::Drawing::Size(198, 54);
			this->splitContainer1->SplitterDistance = 99;
			this->splitContainer1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel2->Controls->Add(this->InRadioButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->OutRadioButton, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(99, 54);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// StepButton
			// 
			this->StepButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StepButton->Location = System::Drawing::Point(11, 15);
			this->StepButton->Name = L"StepButton";
			this->StepButton->Size = System::Drawing::Size(75, 23);
			this->StepButton->TabIndex = 0;
			this->StepButton->Text = L"Step";
			this->StepButton->UseVisualStyleBackColor = true;
			this->StepButton->Click += gcnew System::EventHandler(this, &AdjustFocusDialog::StepButton_Clicked);
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
			this->tableLayoutPanel3->Controls->Add(this->label2, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->DurationTextBox, 1, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 63);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(198, 54);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(135, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"(secs)";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Duration:";
			// 
			// DurationTextBox
			// 
			this->DurationTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DurationTextBox->Location = System::Drawing::Point(69, 17);
			this->DurationTextBox->Name = L"DurationTextBox";
			this->DurationTextBox->Size = System::Drawing::Size(60, 20);
			this->DurationTextBox->TabIndex = 1;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel4->Controls->Add(this->CancelButton, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->OkayButton, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 123);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(198, 56);
			this->tableLayoutPanel4->TabIndex = 2;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(119, 16);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(59, 23);
			this->CancelButton->TabIndex = 4;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &AdjustFocusDialog::CancelButton_Clicked);
			// 
			// OkayButton
			// 
			this->OkayButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkayButton->Location = System::Drawing::Point(20, 16);
			this->OkayButton->Name = L"OkayButton";
			this->OkayButton->Size = System::Drawing::Size(59, 23);
			this->OkayButton->TabIndex = 3;
			this->OkayButton->Text = L"Okay";
			this->OkayButton->UseVisualStyleBackColor = true;
			this->OkayButton->Click += gcnew System::EventHandler(this, &AdjustFocusDialog::OkayButton_Clicked);
			// 
			// InRadioButton
			// 
			this->InRadioButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InRadioButton->AutoSize = true;
			this->InRadioButton->Location = System::Drawing::Point(32, 5);
			this->InRadioButton->Name = L"InRadioButton";
			this->InRadioButton->Size = System::Drawing::Size(34, 17);
			this->InRadioButton->TabIndex = 0;
			this->InRadioButton->TabStop = true;
			this->InRadioButton->Text = L"In";
			this->InRadioButton->UseVisualStyleBackColor = true;
			// 
			// OutRadioButton
			// 
			this->OutRadioButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OutRadioButton->AutoSize = true;
			this->OutRadioButton->Location = System::Drawing::Point(28, 32);
			this->OutRadioButton->Name = L"OutRadioButton";
			this->OutRadioButton->Size = System::Drawing::Size(42, 17);
			this->OutRadioButton->TabIndex = 1;
			this->OutRadioButton->TabStop = true;
			this->OutRadioButton->Text = L"Out";
			this->OutRadioButton->UseVisualStyleBackColor = true;
			// 
			// AdjustFocusDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(204, 182);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"AdjustFocusDialog";
			this->Text = L"Adjust Focus Dialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkayButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 AdjustFocusDialog::FormPtr->Hide();
			 }
private: System::Void CancelButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 AdjustFocusDialog::FormPtr->Hide();
		 }
private: System::Void StepButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 int sign, nTries;
			 float duration;
			 bool success;
			 char buffer[80];

			 if (AdjustFocusDialog::FormPtr->InRadioButton->Checked)
				 sign = 1;
			 else
				 sign = -1;
			 AdjustFocusDialog::FormPtr->GetDurationTextBox(buffer);
			 sscanf_s(buffer, "%f", &duration);
			 if (duration < 0.1) {
				 MessageBox("Focus step duration too small, make > 0.1 seconds", OKAY);
			 } else if (duration > 5.0) {
				 MessageBox("Focus step duration too big, make < 5.0 seconds", OKAY);
			 } else {
				 duration = sign *duration;
				 DontUpdateNow(true);
				 nTries = 0;
				 do {
					 success = DoScopeFunction(SCOPE_FOCUS, &duration, &duration, true);
					 if (success) break;
					 nTries++;
					 usleep(1000000, true);
				 } while (nTries < 5);
				 if (! success) {
					 MessageBox("Can't step focus!  Scope too busy?", OKAY);
				 }
				 DontUpdateNow(false);
			 }
		 }
public: static void SetDurationTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AdjustFocusDialog::FormPtr->DurationTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetDurationTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AdjustFocusDialog::FormPtr->DurationTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
};
}
