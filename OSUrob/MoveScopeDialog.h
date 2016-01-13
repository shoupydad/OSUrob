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
	/// Summary for MoveScopeDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MoveScopeDialog : public System::Windows::Forms::Form
	{
	public:
		static MoveScopeDialog ^FormPtr;
		static double ra, dec;
		static float epoch;
		MoveScopeDialog(void)
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
		~MoveScopeDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  CloseButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  MoveButton;
	private: System::Windows::Forms::TextBox^  DECTextBox;
	private: System::Windows::Forms::TextBox^  RATextBox;
	private: System::Windows::Forms::TextBox^  ObjectTextBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::ComboBox^  PreviousMovesComboBox;

	private: System::Windows::Forms::Button^  PreviousMoveButton;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->MoveButton = (gcnew System::Windows::Forms::Button());
			this->RATextBox = (gcnew System::Windows::Forms::TextBox());
			this->DECTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ObjectTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PreviousMovesComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->PreviousMoveButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->CloseButton, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 59.39849F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.18045F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.04511F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(259, 266);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel2);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(253, 152);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"New Move";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel3);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(3, 161);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(253, 53);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Previous Moves";
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CloseButton->Location = System::Drawing::Point(92, 230);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 7;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &MoveScopeDialog::CloseButton_Clicked);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->ObjectTextBox, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->MoveButton, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->DECTextBox, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->RATextBox, 1, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(247, 133);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(79, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Object:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"RA (hh:mm:ss.s):";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"DEC (+dd:mm:ss):";
			// 
			// MoveButton
			// 
			this->MoveButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MoveButton->Location = System::Drawing::Point(126, 104);
			this->MoveButton->Name = L"MoveButton";
			this->MoveButton->Size = System::Drawing::Size(75, 23);
			this->MoveButton->TabIndex = 4;
			this->MoveButton->Text = L"Move";
			this->MoveButton->UseVisualStyleBackColor = true;
			this->MoveButton->Click += gcnew System::EventHandler(this, &MoveScopeDialog::MoveButton_Clicked);
			// 
			// RATextBox
			// 
			this->RATextBox->Location = System::Drawing::Point(126, 36);
			this->RATextBox->Name = L"RATextBox";
			this->RATextBox->Size = System::Drawing::Size(69, 20);
			this->RATextBox->TabIndex = 2;
			this->RATextBox->Text = L"23:59:59.9";
			// 
			// DECTextBox
			// 
			this->DECTextBox->Location = System::Drawing::Point(126, 69);
			this->DECTextBox->Name = L"DECTextBox";
			this->DECTextBox->Size = System::Drawing::Size(69, 20);
			this->DECTextBox->TabIndex = 3;
			this->DECTextBox->Text = L"+89:59:59";
			// 
			// ObjectTextBox
			// 
			this->ObjectTextBox->Location = System::Drawing::Point(126, 3);
			this->ObjectTextBox->Name = L"ObjectTextBox";
			this->ObjectTextBox->Size = System::Drawing::Size(69, 20);
			this->ObjectTextBox->TabIndex = 1;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				65.16854F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				34.83146F)));
			this->tableLayoutPanel3->Controls->Add(this->PreviousMoveButton, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->PreviousMovesComboBox, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(247, 34);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// PreviousMovesComboBox
			// 
			this->PreviousMovesComboBox->FormattingEnabled = true;
			this->PreviousMovesComboBox->Location = System::Drawing::Point(3, 3);
			this->PreviousMovesComboBox->Name = L"PreviousMovesComboBox";
			this->PreviousMovesComboBox->Size = System::Drawing::Size(154, 21);
			this->PreviousMovesComboBox->TabIndex = 5;
			// 
			// PreviousMoveButton
			// 
			this->PreviousMoveButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PreviousMoveButton->Location = System::Drawing::Point(166, 5);
			this->PreviousMoveButton->Name = L"PreviousMoveButton";
			this->PreviousMoveButton->Size = System::Drawing::Size(75, 23);
			this->PreviousMoveButton->TabIndex = 6;
			this->PreviousMoveButton->Text = L"Move";
			this->PreviousMoveButton->UseVisualStyleBackColor = true;
			this->PreviousMoveButton->Click += gcnew System::EventHandler(this, &MoveScopeDialog::PreviousMoveButton_Clicked);
			// 
			// MoveScopeDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(259, 266);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"MoveScopeDialog";
			this->Text = L"Move Scope Dialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void CloseButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->Hide();
		 }
private: System::Void MoveButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 int hours, degs, mins, isecs, nItems, answer;
			 float secs, ra_float, dec_float;
			 double ra, dec, lst, HourAngle;
			 bool success;
			 char bufferRA[80], bufferDEC[80], Message[160], Object[80], bufferLST[80];

			 // Get desired right ascension

			 FormPtr->GetRATextBox(bufferRA);
			 nItems = sscanf_s(bufferRA, "%d:%d:%f", &hours, &mins, &secs);
			 success = false;
			 if (nItems == 3) {
				 success = ConvertHMStoRA(hours, mins, secs, &ra);
			 }
			 if (! success) {
				 sprintf_s(Message, sizeof(Message), "Warning - Bad RA in scope move: %s\n", bufferRA);
				 MessageBox(Message, OKAY);
				 return;
			 }

			 // Get desired declination

			 FormPtr->GetDECTextBox(bufferDEC);
			 nItems = sscanf_s(bufferDEC, "%d:%d:%f", &degs, &mins, &secs);
			 success = false;
			 if (nItems == 3) {
				 success = ConvertDMStoDEC(degs, mins, secs, &dec);
			 }
			 if (! success) {
				 sprintf_s(Message, sizeof(Message), "Warning - Bad DEC in scope move: %s\n", bufferDEC);
				 MessageBox(Message, OKAY);
				 return;
			 }

			 // Check that move is within reasonable limits for scope

			 GetLSTTextBox(bufferLST);
			 sscanf_s(bufferLST, "%d:%d:%d", &hours, &mins, &isecs);
			 lst = hours + mins/60.0 + isecs/3600.0;
			 HourAngle = ra - lst;
			 if (fabs(HourAngle) > 5.0) {
				 sprintf_s(Message, sizeof(Message), "Warning - Hour angle of new position too big: %5.2f\n",
					 (float) HourAngle);
				 MessageBox(Message, OKAY);
				 return;
			 }
			 if (dec < -30.0) {
				 sprintf_s(Message, sizeof(Message), "Warning - DEC of new position too far south: %5.2f\n",
					 (float) dec);
				 MessageBox(Message, OKAY);
				 return;
			 }
			 FormPtr->GetObjectTextBox(Object);
			 sprintf_s(Message, sizeof(Message), "Sure you want to move the scope to: %s = RA: %s, DEC: %s?",
				 Object, bufferRA, bufferDEC);
			 answer = MessageBox(Message, YESNO);
			 if (answer == YES) {
				 ra_float = (float) ra;
				 dec_float = (float) dec;
				 DoScopeFunction(SCOPE_MOVE, &ra_float, &dec_float, true);
				 sprintf_s(Message, sizeof(Message), "%s = RA: %s, DEC: %s", Object, bufferRA, bufferDEC);
				 FormPtr->AddPreviousMovesItem(Message);
			 }
		 }
private: System::Void PreviousMoveButton_Clicked(System::Object^  sender, System::EventArgs^  e) {
		 }
public: System::Void ShowTheDialog(void) {

			FormPtr->Show();
		}
public: static void SetObjectTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->ObjectTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetObjectTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->ObjectTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetRATextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->RATextBox->Text = buffer;
		delete buffer;
		}
public: static void GetRATextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->RATextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetDECTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->DECTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetDECTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->DECTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void AddPreviousMovesItem(char *text) {

			String ^buffer;
			buffer = gcnew String(text);
			FormPtr->PreviousMovesComboBox->Items->Add(buffer);
			delete buffer;
		}
};
}
