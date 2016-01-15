#pragma once

#include "externs.h"

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
			this->FocusListComboBox->Items->Clear();
			String ^name;
			for (int i = 0; i < FocuserSettings.numFocusPositions; i++) {
				name = gcnew String(FocuserSettings.FocusPositionNames[i]);
				this->FocusListComboBox->Items->Add(name);
				delete name;
			}
			this->FocusListComboBox->SelectedIndex = 0;
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
	private: System::Windows::Forms::Button^  CancelButton;
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
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->OkayButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StepSizeNumericUpDown))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
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
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
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
			this->groupBox1->Size = System::Drawing::Size(141, 96);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Current";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
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
			this->tableLayoutPanel4->Size = System::Drawing::Size(135, 77);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Temp:";
			// 
			// TemperatureTextBox
			// 
			this->TemperatureTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->TemperatureTextBox->Location = System::Drawing::Point(70, 9);
			this->TemperatureTextBox->Name = L"TemperatureTextBox";
			this->TemperatureTextBox->Size = System::Drawing::Size(61, 20);
			this->TemperatureTextBox->TabIndex = 1;
			// 
			// CurrentPositionTextBox
			// 
			this->CurrentPositionTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentPositionTextBox->Location = System::Drawing::Point(70, 47);
			this->CurrentPositionTextBox->Name = L"CurrentPositionTextBox";
			this->CurrentPositionTextBox->Size = System::Drawing::Size(61, 20);
			this->CurrentPositionTextBox->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Position:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel5);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(150, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(142, 96);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Step";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 3;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				57.83133F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				42.16867F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				54)));
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
			this->tableLayoutPanel5->Size = System::Drawing::Size(136, 77);
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
			this->OutRadioButton->Size = System::Drawing::Size(41, 17);
			this->OutRadioButton->TabIndex = 1;
			this->OutRadioButton->TabStop = true;
			this->OutRadioButton->Text = L"Out";
			this->OutRadioButton->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(51, 6);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 26);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Size:";
			// 
			// StepSizeNumericUpDown
			// 
			this->StepSizeNumericUpDown->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StepSizeNumericUpDown->Location = System::Drawing::Point(84, 9);
			this->StepSizeNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->StepSizeNumericUpDown->Name = L"StepSizeNumericUpDown";
			this->StepSizeNumericUpDown->Size = System::Drawing::Size(42, 20);
			this->StepSizeNumericUpDown->TabIndex = 3;
			// 
			// StepButton
			// 
			this->StepButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StepButton->Location = System::Drawing::Point(87, 46);
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
				155)));
			this->tableLayoutPanel6->Controls->Add(this->DeleteButton, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->NewButton, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->SetButton, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->GoToButton, 1, 1);
			this->tableLayoutPanel6->Controls->Add(this->FocusListComboBox, 2, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 43.54839F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 56.45161F)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(289, 83);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// DeleteButton
			// 
			this->DeleteButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DeleteButton->Location = System::Drawing::Point(69, 6);
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
			this->NewButton->Location = System::Drawing::Point(3, 6);
			this->NewButton->Name = L"NewButton";
			this->NewButton->Size = System::Drawing::Size(58, 23);
			this->NewButton->TabIndex = 0;
			this->NewButton->Text = L"New";
			this->NewButton->UseVisualStyleBackColor = true;
			this->NewButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::NewButton_Click);
			// 
			// SetButton
			// 
			this->SetButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SetButton->Location = System::Drawing::Point(3, 48);
			this->SetButton->Name = L"SetButton";
			this->SetButton->Size = System::Drawing::Size(58, 23);
			this->SetButton->TabIndex = 2;
			this->SetButton->Text = L"Set";
			this->SetButton->UseVisualStyleBackColor = true;
			this->SetButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::SetButton_Click);
			// 
			// GoToButton
			// 
			this->GoToButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GoToButton->Location = System::Drawing::Point(69, 48);
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
			this->FocusListComboBox->Location = System::Drawing::Point(136, 3);
			this->FocusListComboBox->MaxDropDownItems = 16;
			this->FocusListComboBox->Name = L"FocusListComboBox";
			this->FocusListComboBox->Size = System::Drawing::Size(121, 21);
			this->FocusListComboBox->Sorted = true;
			this->FocusListComboBox->TabIndex = 4;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->OkayButton, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->CancelButton, 1, 0);
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
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(183, 8);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 1;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &AdjustTelescopeFocusDialog::CancelButton_Click);
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
			this->tableLayoutPanel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void OkayButton_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Hide();
	
	}


	private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Hide();
	}


	private: System::Void InRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void StepButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void NewButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void DeleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void SetButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void GoToButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}

};
}
