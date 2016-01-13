#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "doRoutines.h"


namespace OSUrob {

	/// <summary>
	/// Summary for SpectrographWavelengthsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class SpectrographWavelengthsDialog : public System::Windows::Forms::Form
	{
	public:
		static SpectrographWavelengthsDialog^ FormPtr;
		SpectrographWavelengthsDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			SpectrographWavelengthsDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SpectrographWavelengthsDialog()
		{
			if (components)
			{
				delete components;
				SpectrographWavelengthsDialogExists = false;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  LowTextBox;
	private: System::Windows::Forms::Button^  HighGotoButton;

	private: System::Windows::Forms::Button^  MidGotoButton;

	private: System::Windows::Forms::TextBox^  MidTextBox;
	private: System::Windows::Forms::Button^  LowGotoButton;
	private: System::Windows::Forms::TextBox^  HighTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;





	private: System::Windows::Forms::Button^  StepButton;
	private: System::Windows::Forms::TextBox^  StepSizeTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  OkayButton;
	private: System::Windows::Forms::CheckBox^  LampOnCheckBox;

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
			this->HighGotoButton = (gcnew System::Windows::Forms::Button());
			this->MidGotoButton = (gcnew System::Windows::Forms::Button());
			this->MidTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->LowTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LowGotoButton = (gcnew System::Windows::Forms::Button());
			this->HighTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->StepButton = (gcnew System::Windows::Forms::Button());
			this->StepSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OkayButton = (gcnew System::Windows::Forms::Button());
			this->LampOnCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->OkayButton, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 77.77778F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.22222F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(331, 197);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				164)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				162)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(325, 147);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel3);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(158, 141);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Wavelengths";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				54)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				46)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				56)));
			this->tableLayoutPanel3->Controls->Add(this->HighGotoButton, 2, 2);
			this->tableLayoutPanel3->Controls->Add(this->MidGotoButton, 2, 1);
			this->tableLayoutPanel3->Controls->Add(this->MidTextBox, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->LowTextBox, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->LowGotoButton, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->HighTextBox, 1, 2);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 3;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00063F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(152, 122);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// HighGotoButton
			// 
			this->HighGotoButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HighGotoButton->Location = System::Drawing::Point(105, 89);
			this->HighGotoButton->Name = L"HighGotoButton";
			this->HighGotoButton->Size = System::Drawing::Size(45, 23);
			this->HighGotoButton->TabIndex = 8;
			this->HighGotoButton->Text = L"Goto";
			this->HighGotoButton->UseVisualStyleBackColor = true;
			this->HighGotoButton->Click += gcnew System::EventHandler(this, &SpectrographWavelengthsDialog::HighGotoButton_Clicked);
			// 
			// MidGotoButton
			// 
			this->MidGotoButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->MidGotoButton->Location = System::Drawing::Point(105, 48);
			this->MidGotoButton->Name = L"MidGotoButton";
			this->MidGotoButton->Size = System::Drawing::Size(45, 23);
			this->MidGotoButton->TabIndex = 7;
			this->MidGotoButton->Text = L"Goto";
			this->MidGotoButton->UseVisualStyleBackColor = true;
			this->MidGotoButton->Click += gcnew System::EventHandler(this, &SpectrographWavelengthsDialog::MidGotoButton_Clicked);
			// 
			// MidTextBox
			// 
			this->MidTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MidTextBox->Location = System::Drawing::Point(57, 50);
			this->MidTextBox->Name = L"MidTextBox";
			this->MidTextBox->Size = System::Drawing::Size(37, 20);
			this->MidTextBox->TabIndex = 5;
			this->MidTextBox->Text = L"9999";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Low (A):";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Mid (A):";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"High (A):";
			// 
			// LowTextBox
			// 
			this->LowTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LowTextBox->Location = System::Drawing::Point(57, 10);
			this->LowTextBox->Name = L"LowTextBox";
			this->LowTextBox->Size = System::Drawing::Size(37, 20);
			this->LowTextBox->TabIndex = 3;
			this->LowTextBox->Text = L"9999";
			// 
			// LowGotoButton
			// 
			this->LowGotoButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->LowGotoButton->Location = System::Drawing::Point(105, 8);
			this->LowGotoButton->Name = L"LowGotoButton";
			this->LowGotoButton->Size = System::Drawing::Size(45, 23);
			this->LowGotoButton->TabIndex = 4;
			this->LowGotoButton->Text = L"Goto";
			this->LowGotoButton->UseVisualStyleBackColor = true;
			this->LowGotoButton->Click += gcnew System::EventHandler(this, &SpectrographWavelengthsDialog::LowGotoButton_Clicked);
			// 
			// HighTextBox
			// 
			this->HighTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->HighTextBox->Location = System::Drawing::Point(57, 91);
			this->HighTextBox->Name = L"HighTextBox";
			this->HighTextBox->Size = System::Drawing::Size(37, 20);
			this->HighTextBox->TabIndex = 6;
			this->HighTextBox->Text = L"9999";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel4);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(167, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(156, 141);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Step Micrometer";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				45.91195F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				54.08805F)));
			this->tableLayoutPanel4->Controls->Add(this->label4, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->StepButton, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->StepSizeTextBox, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->LampOnCheckBox, 1, 1);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(150, 122);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"StepSize:";
			// 
			// StepButton
			// 
			this->StepButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StepButton->Location = System::Drawing::Point(10, 80);
			this->StepButton->Name = L"StepButton";
			this->StepButton->Size = System::Drawing::Size(47, 23);
			this->StepButton->TabIndex = 3;
			this->StepButton->Text = L"Step";
			this->StepButton->UseVisualStyleBackColor = true;
			this->StepButton->Click += gcnew System::EventHandler(this, &SpectrographWavelengthsDialog::StepButton_Clicked);
			// 
			// StepSizeTextBox
			// 
			this->StepSizeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StepSizeTextBox->Location = System::Drawing::Point(71, 20);
			this->StepSizeTextBox->Name = L"StepSizeTextBox";
			this->StepSizeTextBox->Size = System::Drawing::Size(37, 20);
			this->StepSizeTextBox->TabIndex = 5;
			this->StepSizeTextBox->Text = L"9999";
			// 
			// OkayButton
			// 
			this->OkayButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkayButton->Location = System::Drawing::Point(128, 163);
			this->OkayButton->Name = L"OkayButton";
			this->OkayButton->Size = System::Drawing::Size(75, 23);
			this->OkayButton->TabIndex = 1;
			this->OkayButton->Text = L"Okay";
			this->OkayButton->UseVisualStyleBackColor = true;
			this->OkayButton->Click += gcnew System::EventHandler(this, &SpectrographWavelengthsDialog::OkayButton_Clicked);
			// 
			// LampOnCheckBox
			// 
			this->LampOnCheckBox->AutoSize = true;
			this->LampOnCheckBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LampOnCheckBox->Location = System::Drawing::Point(71, 64);
			this->LampOnCheckBox->Name = L"LampOnCheckBox";
			this->LampOnCheckBox->Size = System::Drawing::Size(76, 55);
			this->LampOnCheckBox->TabIndex = 6;
			this->LampOnCheckBox->Text = L"Lamp On";
			this->LampOnCheckBox->UseVisualStyleBackColor = true;
			this->LampOnCheckBox->CheckedChanged += gcnew System::EventHandler(this, &SpectrographWavelengthsDialog::LampOnCheckBox_Changed);
			// 
			// SpectrographWavelengthsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(331, 197);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"SpectrographWavelengthsDialog";
			this->Text = L"SpectrographWavelengthsDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void LowGotoButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 short low, mid, high, nSteps;
			 int answer;
			 char buffer[80], Message[160];

			 // Get low value & check validity

			 FormPtr->GetLowTextBox(buffer);
			 sscanf_s(buffer, "%hd", &low);
			 if ((low < 3000) || (low > 10000)) {
				 sprintf_s(Message, sizeof(Message), "*** Warning - Low Wavelength must be between 3000-10000 A\n");
				 MessageBox(Message, OKAY);
				 return;
			 }

			 // Compute Mid & High values

			 high = (int) (low + SpSettings.AngstromsPerPixel*SpSettings.NumPixels);
			 mid  = (high+low)/2;
			 sprintf_s(buffer, sizeof(buffer), "%d", mid);
			 FormPtr->SetMidTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%d", high);
			 FormPtr->SetHighTextBox(buffer);

			 // Compute # of steps to move & move time

			 nSteps = (int) ((low-SpSettings.LowWavelength)/SpSettings.AngstromsPerStep);
			 sprintf_s(Message, sizeof(Message), "About to move micrometer by %d steps, continue?", nSteps);
			 answer = MessageBox(Message, YESNO);
			 if (answer == YES) {
				 StepMicrometerMotor(nSteps);
				 SpSettings.LowWavelength = low;
				 SpSettings.MidWavelength = mid;
				 SpSettings.HighWavelength = high;
			 }
		 }
private: System::Void MidGotoButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 short low, mid, high, nSteps;
			 int answer;
			 char buffer[80], Message[160];

			 // Get mid value & check validity

			 FormPtr->GetMidTextBox(buffer);
			 sscanf_s(buffer, "%hd", &mid);
			 if ((mid < 3000) || (mid > 10000)) {
				 sprintf_s(Message, sizeof(Message), "*** Warning - Mid Wavelength must be between 3000-10000 A\n");
				 MessageBox(Message, OKAY);
				 return;
			 }

			 // Compute Low & High values

			 low = (int) (mid - SpSettings.AngstromsPerPixel*SpSettings.NumPixels/2);
			 high = (int) (low + SpSettings.AngstromsPerPixel*SpSettings.NumPixels);
			 sprintf_s(buffer, sizeof(buffer), "%d", low);
			 FormPtr->SetLowTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%d", high);
			 FormPtr->SetHighTextBox(buffer);

			 // Compute # of steps to move & move time

			 nSteps = (int) ((low-SpSettings.LowWavelength)/SpSettings.AngstromsPerStep);
			 sprintf_s(Message, sizeof(Message), "About to move micrometer by %d steps, continue?", nSteps);
			 answer = MessageBox(Message, YESNO);
			 if (answer == YES) {
				 StepMicrometerMotor(nSteps);
				 SpSettings.LowWavelength = low;
				 SpSettings.MidWavelength = mid;
				 SpSettings.HighWavelength = high;
			 }
		 }
private: System::Void HighGotoButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 short low, mid, high, nSteps;
			 int answer;
			 char buffer[80], Message[160];

			 // Get high value & check validity

			 FormPtr->GetHighTextBox(buffer);
			 sscanf_s(buffer, "%hd", &high);
			 if ((high < 3000) || (high > 10000)) {
				 sprintf_s(Message, sizeof(Message), "*** Warning - High Wavelength must be between 3000-10000 A\n");
				 MessageBox(Message, OKAY);
				 return;
			 }

			 // Compute Low & Mid values

			 low = (int) (high - SpSettings.AngstromsPerPixel*SpSettings.NumPixels);
			 mid  = (high+low)/2;
			 sprintf_s(buffer, sizeof(buffer), "%d", low);
			 FormPtr->SetLowTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%d", mid);
			 FormPtr->SetMidTextBox(buffer);

			 // Compute # of steps to move & move time

			 nSteps = (int) ((low-SpSettings.LowWavelength)/SpSettings.AngstromsPerStep);
			 sprintf_s(Message, sizeof(Message), "About to move micrometer by %d steps, continue?", nSteps);
			 answer = MessageBox(Message, YESNO);
			 if (answer == YES) {
				 StepMicrometerMotor(nSteps);
				 SpSettings.LowWavelength = low;
				 SpSettings.MidWavelength = mid;
				 SpSettings.HighWavelength = high;
			 }
		 }
private: System::Void StepButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 short low, mid, high, nSteps;
			 int answer;
			 char buffer[80], Message[160];

			 // Get step size & check validity

			 FormPtr->GetStepSizeTextBox(buffer);
			 sscanf_s(buffer, "%hd", &nSteps);
			 if ((nSteps < -32000) || (nSteps > 32000)) {
				 sprintf_s(Message, sizeof(Message), "*** Warning - step size must be between -32000 & +32000\n");
				 MessageBox(Message, OKAY);
				 return;
			 }

			 // Compute new Low, Mid & High values

			 low = (int) (SpSettings.LowWavelength + SpSettings.AngstromsPerStep*nSteps);
			 high = (int) (low + SpSettings.AngstromsPerPixel*SpSettings.NumPixels);
			 mid  = (high+low)/2;
			 sprintf_s(buffer, sizeof(buffer), "%d", mid);
			 FormPtr->SetMidTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%d", high);
			 FormPtr->SetHighTextBox(buffer);

			 // Compute # of steps to move & move time

			 sprintf_s(Message, sizeof(Message), "About to move micrometer by %d steps, continue?", nSteps);
			 answer = MessageBox(Message, YESNO);
			 if (answer == YES) {
				 StepMicrometerMotor(nSteps);
				 SpSettings.LowWavelength = low;
				 SpSettings.MidWavelength = mid;
				 SpSettings.HighWavelength = high;
			 }
		 }
private: System::Void OkayButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->Hide();
		 }
public:  Void ShowTheDialog(void) {

			 char buffer[80];

			 sprintf_s(buffer, sizeof(buffer), "%d", SpSettings.LowWavelength);
			 FormPtr->SetLowTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%d", SpSettings.MidWavelength);
			 FormPtr->SetMidTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%d", SpSettings.HighWavelength);
			 FormPtr->SetHighTextBox(buffer);
			 FormPtr->SetStepSizeTextBox("100");
			 FormPtr->Show();
		 }
public: static void SetLowTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->LowTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetLowTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->LowTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}



public: static void SetMidTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->MidTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetMidTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->MidTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetHighTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->HighTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetHighTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->HighTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}



public: static void SetStepSizeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->StepSizeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetStepSizeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->StepSizeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}



private: System::Void LampOnCheckBox_Changed(System::Object^  sender, System::EventArgs^  e) {

			 if (FormPtr->LampOnCheckBox->Checked) {
				 SpectroLampOnOff(true);  // turn on spectrograph calibration lamp
			 } else {
				 SpectroLampOnOff(false); // turn off spectrograph calibration lamp
			 }
		 }
};
}
