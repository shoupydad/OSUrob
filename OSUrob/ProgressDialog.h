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
	/// Summary for ProgressDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ProgressDialog : public System::Windows::Forms::Form
	{
	public:
		static ProgressDialog ^FormPtr;
		static bool CancelRequested;
		ProgressDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			ProgressDialogExists = true;
			CancelRequested = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProgressDialog()
		{
			if (components)
			{
				delete components;
			}
			ProgressDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::Label^  OperationLabel;
	private: System::Windows::Forms::ProgressBar^  ProgressBar;
	private: System::Windows::Forms::Button^  CancelButton;


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
			this->OperationLabel = (gcnew System::Windows::Forms::Label());
			this->ProgressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel1->Controls->Add(this->OperationLabel, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->ProgressBar, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->CancelButton, 0, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(294, 171);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Click += gcnew System::EventHandler(this, &ProgressDialog::ProgressDialogCancelButtonClicked);
			// 
			// OperationLabel
			// 
			this->OperationLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OperationLabel->AutoSize = true;
			this->OperationLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OperationLabel->Location = System::Drawing::Point(20, 19);
			this->OperationLabel->Name = L"OperationLabel";
			this->OperationLabel->Size = System::Drawing::Size(253, 18);
			this->OperationLabel->TabIndex = 0;
			this->OperationLabel->Text = L"Current progress of requested operation";
			// 
			// ProgressBar
			// 
			this->ProgressBar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ProgressBar->Location = System::Drawing::Point(41, 74);
			this->ProgressBar->Name = L"ProgressBar";
			this->ProgressBar->Size = System::Drawing::Size(212, 23);
			this->ProgressBar->Step = 1;
			this->ProgressBar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->ProgressBar->TabIndex = 1;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(109, 131);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 2;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &ProgressDialog::ProgressDialogCancelButtonClicked);
			// 
			// ProgressDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 170);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"ProgressDialog";
			this->Text = L"Operation Progress";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void ProgressDialogCancelButtonClicked(System::Object^  sender, System::EventArgs^  e) {

			 ProgressDialog::FormPtr->CancelRequested = true;
			 ProgressDialog::FormPtr->Hide();
		 }

public: static void SetProgressBarValue(int value) {

			ProgressDialog::FormPtr->ProgressBar->Value = value;
		}

public:  static void SetLabel(char *text) {

			String ^buffer;
			buffer = gcnew String(text);
			ProgressDialog::FormPtr->OperationLabel->Text = buffer;
			delete buffer;
		}

public:  void ShowTheDialog(void) {
			 ProgressDialog::FormPtr->Show();
		 }

public:  void HideTheDialog(void) {

			 ProgressDialog::CancelRequested = false;
			 ProgressDialog::FormPtr->Hide();
		 }

};
}
