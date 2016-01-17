#pragma once

#include <sys/stat.h>
#include "doRoutines.h"
#include "CalibrateISDialog.h"
#include "CalibrateSlewingDialog.h"
#include "SpectrographWavelengthsDialog.h"
#include "AdjustTelescopeFocusDialog.h"
#include "RoboFocuser.h"

namespace OSUrob {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		static Form1^ OSUrobForm;
		static SerialPort ^ComPortPtr;
		static SerialPort ^ScopeComPortPtr;
		static SerialPort ^ObsConComPortPtr;
		static bool DontUpdate;
	private: System::Windows::Forms::RichTextBox^  MainStatusBox;
	private: System::Windows::Forms::ToolStripMenuItem^  LinkToScopeMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  UnlinkFromScopeMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  calibrateInstrumentSelectorToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  calibrateScopeSlewingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  SpectrographWavelengthsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  turnOnOffGlobalDebuggingToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  initGPSToolStripMenuItem;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  FocusPosTextBox;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TextBox^  FocusTempTextBox;
	private: System::Windows::Forms::CheckBox^  PowerCCDButton;

	private: System::Windows::Forms::CheckBox^  PowerSpectroButton;

	private: System::Windows::Forms::CheckBox^  PowerColorButton;
	private: System::Windows::Forms::CheckBox^  PowerAux2Button;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  FWPositionTextBox;
	private: System::Windows::Forms::ToolStripMenuItem^  focuserToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  configureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  adjustToolStripMenuItem;







	public: 
		static bool TimerBusy;
		Form1(void)
		{
			InitializeComponent();
			OSUrobForm = this;
			DontUpdate = false;
			TimerBusy = false;
			OSUrobFormExists = true;
			_unlink(MESSAGEFILENAME);
			_unlink(RESPONSEFILENAME);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  MainMenu;





	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;

	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  OpenObsButton;
	private: System::Windows::Forms::ToolStripButton^  CloseObsButton;
	private: System::Windows::Forms::ToolStripButton^  DomeStopButton;

	private: System::Windows::Forms::RadioButton^  SpectroButton;





	private: System::Windows::Forms::RadioButton^  CCDButton;
	private: System::Windows::Forms::RadioButton^  ColorCCDButton;

	private: System::Windows::Forms::RadioButton^  EyeButton;








	private: System::Windows::Forms::Button^  SouthButton;
	private: System::Windows::Forms::Button^  EastButton;
	private: System::Windows::Forms::Button^  WestButton;





	private: System::Windows::Forms::Button^  NorthButton;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  SecRadioButton;



	private: System::Windows::Forms::RadioButton^  MinRadioButton;

	private: System::Windows::Forms::RadioButton^  DegRadioButton;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  DomeGotoAzTextBox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  DomeGotoGoButton;


	private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::CheckBox^  PowerAux1Button;


	private: System::Windows::Forms::CheckBox^  PowerLightButton;
private: System::Windows::Forms::CheckBox^  PowerFlatsButton;



	private: System::Windows::Forms::CheckBox^  PowerScopeButton;

	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar1;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  LSTTextBox;

	private: System::Windows::Forms::TextBox^  LocalTextBox;
	private: System::Windows::Forms::TextBox^  UTTextBox;



	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TextBox^  AltTextBox;

	private: System::Windows::Forms::TextBox^  DECTextBox;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::TextBox^  RATextBox;
private: System::Windows::Forms::TextBox^  AzTextBox;



	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
private: System::Windows::Forms::TextBox^  DomeScopeTextBox;



private: System::Windows::Forms::TextBox^  DomeSlitTextBox;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::TextBox^  DomeAzTextBox;



	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::GroupBox^  groupBox9;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
private: System::Windows::Forms::TextBox^  GuidingTextBox;


	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::TextBox^  MirrorCoverTextBox;

	private: System::Windows::Forms::GroupBox^  groupBox10;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::TextBox^  OutsideTempTextBox;

private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::TextBox^  HumidityTextBox;

private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::TextBox^  WindSpeedTextBox;

private: System::Windows::Forms::TextBox^  DewPointTextBox;

private: System::Windows::Forms::CheckBox^  DomeLinkCheckButton;
private: System::Windows::Forms::NumericUpDown^  StepSizeNumeric;


private: System::Windows::Forms::ToolStripMenuItem^  telescopeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  guidingToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  hToolStripMenuItem;





private: System::Windows::Forms::ToolStripMenuItem^  slitOpenToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  slitCloseToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  homeDomeToolStripMenuItem;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::TextBox^  DSRInterlockTextBox;



private: System::Windows::Forms::ToolStripMenuItem^  openMirrorCoverToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  closeMirrorCoverToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  ParkScopeMenuItem;


private: System::Windows::Forms::ToolStripMenuItem^  moveScopeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::TextBox^  JDTextBox;
private: System::Windows::Forms::Timer^  MainTmer;

private: System::ComponentModel::IContainer^  components;

	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->MainMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->slitOpenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->slitCloseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->homeDomeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->telescopeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openMirrorCoverToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeMirrorCoverToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LinkToScopeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->UnlinkFromScopeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moveScopeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ParkScopeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->initGPSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guidingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calibrateInstrumentSelectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calibrateScopeSlewingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SpectrographWavelengthsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->turnOnOffGlobalDebuggingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->focuserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->configureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adjustToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->OpenObsButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->CloseObsButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->DomeStopButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->SpectroButton = (gcnew System::Windows::Forms::RadioButton());
			this->CCDButton = (gcnew System::Windows::Forms::RadioButton());
			this->ColorCCDButton = (gcnew System::Windows::Forms::RadioButton());
			this->EyeButton = (gcnew System::Windows::Forms::RadioButton());
			this->SouthButton = (gcnew System::Windows::Forms::Button());
			this->EastButton = (gcnew System::Windows::Forms::Button());
			this->WestButton = (gcnew System::Windows::Forms::Button());
			this->NorthButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->StepSizeNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->SecRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->MinRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->DegRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->DomeLinkCheckButton = (gcnew System::Windows::Forms::CheckBox());
			this->DomeGotoAzTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DomeGotoGoButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->PowerAux2Button = (gcnew System::Windows::Forms::CheckBox());
			this->PowerSpectroButton = (gcnew System::Windows::Forms::CheckBox());
			this->PowerColorButton = (gcnew System::Windows::Forms::CheckBox());
			this->PowerCCDButton = (gcnew System::Windows::Forms::CheckBox());
			this->PowerAux1Button = (gcnew System::Windows::Forms::CheckBox());
			this->PowerLightButton = (gcnew System::Windows::Forms::CheckBox());
			this->PowerFlatsButton = (gcnew System::Windows::Forms::CheckBox());
			this->PowerScopeButton = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->LSTTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LocalTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->UTTextBox = (gcnew System::Windows::Forms::TextBox());
			this->JDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->AzTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->AltTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DECTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->RATextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->DomeSlitTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->DomeScopeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->DomeAzTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DSRInterlockTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->MirrorCoverTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->GuidingTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->FocusPosTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FocusTempTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->FWPositionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->HumidityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->OutsideTempTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->WindSpeedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DewPointTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MainTmer = (gcnew System::Windows::Forms::Timer(this->components));
			this->MainStatusBox = (gcnew System::Windows::Forms::RichTextBox());
			this->MainMenu->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StepSizeNumeric))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// MainMenu
			// 
			this->MainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->helpToolStripMenuItem,
					this->telescopeToolStripMenuItem, this->guidingToolStripMenuItem, this->settingsToolStripMenuItem, this->focuserToolStripMenuItem,
					this->hToolStripMenuItem
			});
			this->MainMenu->Location = System::Drawing::Point(0, 0);
			this->MainMenu->Name = L"MainMenu";
			this->MainMenu->Size = System::Drawing::Size(886, 24);
			this->MainMenu->TabIndex = 0;
			this->MainMenu->Text = L"Main Menu";
			this->MainMenu->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->slitOpenToolStripMenuItem,
					this->slitCloseToolStripMenuItem, this->homeDomeToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->helpToolStripMenuItem->Text = L"Observatory";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::helpToolStripMenuItem_Click);
			// 
			// slitOpenToolStripMenuItem
			// 
			this->slitOpenToolStripMenuItem->Name = L"slitOpenToolStripMenuItem";
			this->slitOpenToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->slitOpenToolStripMenuItem->Text = L"Open Shutter";
			this->slitOpenToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::OpenSlitMenuItemClick);
			// 
			// slitCloseToolStripMenuItem
			// 
			this->slitCloseToolStripMenuItem->Name = L"slitCloseToolStripMenuItem";
			this->slitCloseToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->slitCloseToolStripMenuItem->Text = L"Close Shutter";
			this->slitCloseToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::CloseSlitMenuItemClick);
			// 
			// homeDomeToolStripMenuItem
			// 
			this->homeDomeToolStripMenuItem->Name = L"homeDomeToolStripMenuItem";
			this->homeDomeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->homeDomeToolStripMenuItem->Text = L"Home Dome";
			this->homeDomeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::HomeDomeMenuItemClick);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ExitMenuItemClick);
			// 
			// telescopeToolStripMenuItem
			// 
			this->telescopeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->openMirrorCoverToolStripMenuItem,
					this->closeMirrorCoverToolStripMenuItem, this->LinkToScopeMenuItem, this->UnlinkFromScopeMenuItem, this->moveScopeToolStripMenuItem,
					this->ParkScopeMenuItem, this->initGPSToolStripMenuItem
			});
			this->telescopeToolStripMenuItem->Name = L"telescopeToolStripMenuItem";
			this->telescopeToolStripMenuItem->Size = System::Drawing::Size(72, 20);
			this->telescopeToolStripMenuItem->Text = L"Telescope";
			// 
			// openMirrorCoverToolStripMenuItem
			// 
			this->openMirrorCoverToolStripMenuItem->Name = L"openMirrorCoverToolStripMenuItem";
			this->openMirrorCoverToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->openMirrorCoverToolStripMenuItem->Text = L"Open Mirror Cover";
			this->openMirrorCoverToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::OpenMirrorCoverMenuItemClick);
			// 
			// closeMirrorCoverToolStripMenuItem
			// 
			this->closeMirrorCoverToolStripMenuItem->Name = L"closeMirrorCoverToolStripMenuItem";
			this->closeMirrorCoverToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->closeMirrorCoverToolStripMenuItem->Text = L"Close Mirror Cover";
			this->closeMirrorCoverToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::CloseMirrorCoverMenuItemClick);
			// 
			// LinkToScopeMenuItem
			// 
			this->LinkToScopeMenuItem->Name = L"LinkToScopeMenuItem";
			this->LinkToScopeMenuItem->Size = System::Drawing::Size(173, 22);
			this->LinkToScopeMenuItem->Text = L"Link to Scope";
			this->LinkToScopeMenuItem->Click += gcnew System::EventHandler(this, &Form1::LinkToScopeMenuItem_Click);
			// 
			// UnlinkFromScopeMenuItem
			// 
			this->UnlinkFromScopeMenuItem->Name = L"UnlinkFromScopeMenuItem";
			this->UnlinkFromScopeMenuItem->Size = System::Drawing::Size(173, 22);
			this->UnlinkFromScopeMenuItem->Text = L"Unlink from Scope";
			this->UnlinkFromScopeMenuItem->Click += gcnew System::EventHandler(this, &Form1::UnlinkFromScopeMenuItem_Click);
			// 
			// moveScopeToolStripMenuItem
			// 
			this->moveScopeToolStripMenuItem->Name = L"moveScopeToolStripMenuItem";
			this->moveScopeToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->moveScopeToolStripMenuItem->Text = L"Move Scope";
			this->moveScopeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::MoveScopeMenuItemClick);
			// 
			// ParkScopeMenuItem
			// 
			this->ParkScopeMenuItem->Name = L"ParkScopeMenuItem";
			this->ParkScopeMenuItem->Size = System::Drawing::Size(173, 22);
			this->ParkScopeMenuItem->Text = L"Park Scope";
			this->ParkScopeMenuItem->Click += gcnew System::EventHandler(this, &Form1::ParkScopeMenuItem_Click);
			// 
			// initGPSToolStripMenuItem
			// 
			this->initGPSToolStripMenuItem->Name = L"initGPSToolStripMenuItem";
			this->initGPSToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->initGPSToolStripMenuItem->Text = L"Init GPS";
			this->initGPSToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::initGPSToolStripMenuItem_Click);
			// 
			// guidingToolStripMenuItem
			// 
			this->guidingToolStripMenuItem->Name = L"guidingToolStripMenuItem";
			this->guidingToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->guidingToolStripMenuItem->Text = L"Guiding";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->calibrateInstrumentSelectorToolStripMenuItem,
					this->calibrateScopeSlewingToolStripMenuItem, this->SpectrographWavelengthsToolStripMenuItem, this->turnOnOffGlobalDebuggingToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// calibrateInstrumentSelectorToolStripMenuItem
			// 
			this->calibrateInstrumentSelectorToolStripMenuItem->Name = L"calibrateInstrumentSelectorToolStripMenuItem";
			this->calibrateInstrumentSelectorToolStripMenuItem->Size = System::Drawing::Size(239, 22);
			this->calibrateInstrumentSelectorToolStripMenuItem->Text = L"Calibrate Instrument Selector";
			this->calibrateInstrumentSelectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::calibrateInstrumentSelectorToolStripMenuItem_Click);
			// 
			// calibrateScopeSlewingToolStripMenuItem
			// 
			this->calibrateScopeSlewingToolStripMenuItem->Name = L"calibrateScopeSlewingToolStripMenuItem";
			this->calibrateScopeSlewingToolStripMenuItem->Size = System::Drawing::Size(239, 22);
			this->calibrateScopeSlewingToolStripMenuItem->Text = L"Calibrate Scope Slewing";
			this->calibrateScopeSlewingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::calibrateScopeSlewingToolStripMenuItem_Click);
			// 
			// SpectrographWavelengthsToolStripMenuItem
			// 
			this->SpectrographWavelengthsToolStripMenuItem->Name = L"SpectrographWavelengthsToolStripMenuItem";
			this->SpectrographWavelengthsToolStripMenuItem->Size = System::Drawing::Size(239, 22);
			this->SpectrographWavelengthsToolStripMenuItem->Text = L"Spectrograph Wavelengths";
			this->SpectrographWavelengthsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::SpectrographWavelengthsToolStripMenuItem_Click);
			// 
			// turnOnOffGlobalDebuggingToolStripMenuItem
			// 
			this->turnOnOffGlobalDebuggingToolStripMenuItem->Name = L"turnOnOffGlobalDebuggingToolStripMenuItem";
			this->turnOnOffGlobalDebuggingToolStripMenuItem->Size = System::Drawing::Size(239, 22);
			this->turnOnOffGlobalDebuggingToolStripMenuItem->Text = L"Turn On/Off Global Debugging";
			this->turnOnOffGlobalDebuggingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::turnOnOffGlobalDebuggingToolStripMenuItem_Click);
			// 
			// focuserToolStripMenuItem
			// 
			this->focuserToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->configureToolStripMenuItem,
					this->adjustToolStripMenuItem
			});
			this->focuserToolStripMenuItem->Name = L"focuserToolStripMenuItem";
			this->focuserToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->focuserToolStripMenuItem->Text = L"Focuser";
			// 
			// configureToolStripMenuItem
			// 
			this->configureToolStripMenuItem->Name = L"configureToolStripMenuItem";
			this->configureToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->configureToolStripMenuItem->Text = L"Configure";
			this->configureToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::FocuserConfigureToolStripMenuItem_Click);
			// 
			// adjustToolStripMenuItem
			// 
			this->adjustToolStripMenuItem->Name = L"adjustToolStripMenuItem";
			this->adjustToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->adjustToolStripMenuItem->Text = L"Adjust";
			this->adjustToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::FocuserAdjustToolStripMenuItem_Click);
			// 
			// hToolStripMenuItem
			// 
			this->hToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->hToolStripMenuItem->Name = L"hToolStripMenuItem";
			this->hToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->hToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::SystemColors::Control;
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->OpenObsButton, this->CloseObsButton,
					this->DomeStopButton
			});
			this->toolStrip1->Location = System::Drawing::Point(3, 16);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(216, 38);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// OpenObsButton
			// 
			this->OpenObsButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"OpenObsButton.Image")));
			this->OpenObsButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->OpenObsButton->Name = L"OpenObsButton";
			this->OpenObsButton->Size = System::Drawing::Size(67, 35);
			this->OpenObsButton->Text = L"Open Obs.";
			this->OpenObsButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->OpenObsButton->Click += gcnew System::EventHandler(this, &Form1::OpenObsButtonClick);
			// 
			// CloseObsButton
			// 
			this->CloseObsButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CloseObsButton.Image")));
			this->CloseObsButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->CloseObsButton->Name = L"CloseObsButton";
			this->CloseObsButton->Size = System::Drawing::Size(67, 35);
			this->CloseObsButton->Text = L"Close Obs.";
			this->CloseObsButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->CloseObsButton->Click += gcnew System::EventHandler(this, &Form1::CloseObsButtonClick);
			// 
			// DomeStopButton
			// 
			this->DomeStopButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DomeStopButton.Image")));
			this->DomeStopButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->DomeStopButton->Name = L"DomeStopButton";
			this->DomeStopButton->Size = System::Drawing::Size(70, 35);
			this->DomeStopButton->Text = L"Dome Stop";
			this->DomeStopButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->DomeStopButton->Click += gcnew System::EventHandler(this, &Form1::DomeStopButtonClick);
			// 
			// SpectroButton
			// 
			this->SpectroButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SpectroButton->AutoSize = true;
			this->SpectroButton->Location = System::Drawing::Point(65, 47);
			this->SpectroButton->Name = L"SpectroButton";
			this->SpectroButton->Size = System::Drawing::Size(62, 17);
			this->SpectroButton->TabIndex = 3;
			this->SpectroButton->TabStop = true;
			this->SpectroButton->Text = L"Spectro";
			this->SpectroButton->UseVisualStyleBackColor = true;
			this->SpectroButton->Click += gcnew System::EventHandler(this, &Form1::SpectroButton_Clicked);
			// 
			// CCDButton
			// 
			this->CCDButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CCDButton->AutoSize = true;
			this->CCDButton->Location = System::Drawing::Point(7, 47);
			this->CCDButton->Name = L"CCDButton";
			this->CCDButton->Size = System::Drawing::Size(47, 17);
			this->CCDButton->TabIndex = 2;
			this->CCDButton->TabStop = true;
			this->CCDButton->Text = L"CCD";
			this->CCDButton->UseVisualStyleBackColor = true;
			this->CCDButton->Click += gcnew System::EventHandler(this, &Form1::CCDButton_Clicked);
			// 
			// ColorCCDButton
			// 
			this->ColorCCDButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ColorCCDButton->AutoSize = true;
			this->ColorCCDButton->Location = System::Drawing::Point(65, 25);
			this->ColorCCDButton->Name = L"ColorCCDButton";
			this->ColorCCDButton->Size = System::Drawing::Size(49, 17);
			this->ColorCCDButton->TabIndex = 1;
			this->ColorCCDButton->TabStop = true;
			this->ColorCCDButton->Text = L"Color";
			this->ColorCCDButton->UseVisualStyleBackColor = true;
			this->ColorCCDButton->Click += gcnew System::EventHandler(this, &Form1::ColorCCDButton_Clicked);
			// 
			// EyeButton
			// 
			this->EyeButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->EyeButton->AutoSize = true;
			this->EyeButton->Location = System::Drawing::Point(7, 25);
			this->EyeButton->Name = L"EyeButton";
			this->EyeButton->Size = System::Drawing::Size(43, 17);
			this->EyeButton->TabIndex = 0;
			this->EyeButton->TabStop = true;
			this->EyeButton->Text = L"Eye";
			this->EyeButton->UseVisualStyleBackColor = true;
			this->EyeButton->Click += gcnew System::EventHandler(this, &Form1::EyeButton_Clicked);
			// 
			// SouthButton
			// 
			this->SouthButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SouthButton->Location = System::Drawing::Point(29, 52);
			this->SouthButton->Name = L"SouthButton";
			this->SouthButton->Size = System::Drawing::Size(24, 23);
			this->SouthButton->TabIndex = 1;
			this->SouthButton->Text = L"S";
			this->SouthButton->UseVisualStyleBackColor = true;
			this->SouthButton->Click += gcnew System::EventHandler(this, &Form1::SouthButtonClick);
			// 
			// EastButton
			// 
			this->EastButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->EastButton->Location = System::Drawing::Point(58, 32);
			this->EastButton->Name = L"EastButton";
			this->EastButton->Size = System::Drawing::Size(24, 23);
			this->EastButton->TabIndex = 2;
			this->EastButton->Text = L"E";
			this->EastButton->UseVisualStyleBackColor = true;
			this->EastButton->Click += gcnew System::EventHandler(this, &Form1::EastButtonClick);
			// 
			// WestButton
			// 
			this->WestButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->WestButton->Location = System::Drawing::Point(1, 32);
			this->WestButton->Name = L"WestButton";
			this->WestButton->Size = System::Drawing::Size(24, 23);
			this->WestButton->TabIndex = 2;
			this->WestButton->Text = L"W";
			this->WestButton->UseVisualStyleBackColor = true;
			this->WestButton->Click += gcnew System::EventHandler(this, &Form1::WestButtonClick);
			// 
			// NorthButton
			// 
			this->NorthButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->NorthButton->Location = System::Drawing::Point(29, 12);
			this->NorthButton->Name = L"NorthButton";
			this->NorthButton->Size = System::Drawing::Size(24, 23);
			this->NorthButton->TabIndex = 3;
			this->NorthButton->Text = L"N";
			this->NorthButton->UseVisualStyleBackColor = true;
			this->NorthButton->Click += gcnew System::EventHandler(this, &Form1::NorthButtonClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->StepSizeNumeric);
			this->groupBox1->Controls->Add(this->SecRadioButton);
			this->groupBox1->Controls->Add(this->MinRadioButton);
			this->groupBox1->Controls->Add(this->DegRadioButton);
			this->groupBox1->Controls->Add(this->SouthButton);
			this->groupBox1->Controls->Add(this->NorthButton);
			this->groupBox1->Controls->Add(this->EastButton);
			this->groupBox1->Controls->Add(this->WestButton);
			this->groupBox1->Location = System::Drawing::Point(349, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(175, 75);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Scope Slew";
			// 
			// StepSizeNumeric
			// 
			this->StepSizeNumeric->DecimalPlaces = 2;
			this->StepSizeNumeric->Location = System::Drawing::Point(73, 10);
			this->StepSizeNumeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->StepSizeNumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->StepSizeNumeric->Name = L"StepSizeNumeric";
			this->StepSizeNumeric->Size = System::Drawing::Size(51, 20);
			this->StepSizeNumeric->TabIndex = 16;
			this->StepSizeNumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// SecRadioButton
			// 
			this->SecRadioButton->AutoSize = true;
			this->SecRadioButton->Location = System::Drawing::Point(130, 52);
			this->SecRadioButton->Name = L"SecRadioButton";
			this->SecRadioButton->Size = System::Drawing::Size(30, 17);
			this->SecRadioButton->TabIndex = 8;
			this->SecRadioButton->TabStop = true;
			this->SecRadioButton->Text = L"\"";
			this->SecRadioButton->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->SecRadioButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->SecRadioButton->UseVisualStyleBackColor = true;
			// 
			// MinRadioButton
			// 
			this->MinRadioButton->AutoSize = true;
			this->MinRadioButton->Location = System::Drawing::Point(130, 32);
			this->MinRadioButton->Name = L"MinRadioButton";
			this->MinRadioButton->Size = System::Drawing::Size(27, 17);
			this->MinRadioButton->TabIndex = 7;
			this->MinRadioButton->TabStop = true;
			this->MinRadioButton->Text = L"\'";
			this->MinRadioButton->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->MinRadioButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->MinRadioButton->UseVisualStyleBackColor = true;
			// 
			// DegRadioButton
			// 
			this->DegRadioButton->AutoSize = true;
			this->DegRadioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DegRadioButton->Location = System::Drawing::Point(130, 10);
			this->DegRadioButton->Name = L"DegRadioButton";
			this->DegRadioButton->Size = System::Drawing::Size(31, 17);
			this->DegRadioButton->TabIndex = 6;
			this->DegRadioButton->TabStop = true;
			this->DegRadioButton->Text = L"o";
			this->DegRadioButton->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->DegRadioButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->DegRadioButton->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->SpectroButton);
			this->groupBox2->Controls->Add(this->EyeButton);
			this->groupBox2->Controls->Add(this->CCDButton);
			this->groupBox2->Controls->Add(this->ColorCCDButton);
			this->groupBox2->Location = System::Drawing::Point(216, 27);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(129, 75);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Instrument Port";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->DomeLinkCheckButton);
			this->groupBox3->Controls->Add(this->DomeGotoAzTextBox);
			this->groupBox3->Controls->Add(this->DomeGotoGoButton);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Location = System::Drawing::Point(530, 27);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(105, 75);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Dome Goto";
			// 
			// DomeLinkCheckButton
			// 
			this->DomeLinkCheckButton->AutoSize = true;
			this->DomeLinkCheckButton->Location = System::Drawing::Point(53, 52);
			this->DomeLinkCheckButton->Name = L"DomeLinkCheckButton";
			this->DomeLinkCheckButton->Size = System::Drawing::Size(46, 17);
			this->DomeLinkCheckButton->TabIndex = 16;
			this->DomeLinkCheckButton->Text = L"Link";
			this->DomeLinkCheckButton->UseVisualStyleBackColor = true;
			this->DomeLinkCheckButton->CheckedChanged += gcnew System::EventHandler(this, &Form1::DomeLinkCheckButtonChanged);
			// 
			// DomeGotoAzTextBox
			// 
			this->DomeGotoAzTextBox->Location = System::Drawing::Point(59, 17);
			this->DomeGotoAzTextBox->Name = L"DomeGotoAzTextBox";
			this->DomeGotoAzTextBox->Size = System::Drawing::Size(32, 20);
			this->DomeGotoAzTextBox->TabIndex = 9;
			// 
			// DomeGotoGoButton
			// 
			this->DomeGotoGoButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DomeGotoGoButton->Location = System::Drawing::Point(9, 46);
			this->DomeGotoGoButton->Name = L"DomeGotoGoButton";
			this->DomeGotoGoButton->Size = System::Drawing::Size(32, 23);
			this->DomeGotoGoButton->TabIndex = 9;
			this->DomeGotoGoButton->Text = L"Go";
			this->DomeGotoGoButton->UseVisualStyleBackColor = true;
			this->DomeGotoGoButton->Click += gcnew System::EventHandler(this, &Form1::DomeGotoGoButtonClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Azimuth:";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->PowerAux2Button);
			this->groupBox4->Controls->Add(this->PowerSpectroButton);
			this->groupBox4->Controls->Add(this->PowerColorButton);
			this->groupBox4->Controls->Add(this->PowerCCDButton);
			this->groupBox4->Controls->Add(this->PowerAux1Button);
			this->groupBox4->Controls->Add(this->PowerLightButton);
			this->groupBox4->Controls->Add(this->PowerFlatsButton);
			this->groupBox4->Controls->Add(this->PowerScopeButton);
			this->groupBox4->Location = System::Drawing::Point(641, 27);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(245, 75);
			this->groupBox4->TabIndex = 7;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Power Up";
			// 
			// PowerAux2Button
			// 
			this->PowerAux2Button->AutoSize = true;
			this->PowerAux2Button->Location = System::Drawing::Point(176, 43);
			this->PowerAux2Button->Name = L"PowerAux2Button";
			this->PowerAux2Button->Size = System::Drawing::Size(50, 17);
			this->PowerAux2Button->TabIndex = 13;
			this->PowerAux2Button->Text = L"Aux2";
			this->PowerAux2Button->UseVisualStyleBackColor = true;
			this->PowerAux2Button->Click += gcnew System::EventHandler(this, &Form1::PowerAux2ButtonClick);
			// 
			// PowerSpectroButton
			// 
			this->PowerSpectroButton->AutoSize = true;
			this->PowerSpectroButton->Location = System::Drawing::Point(176, 20);
			this->PowerSpectroButton->Name = L"PowerSpectroButton";
			this->PowerSpectroButton->Size = System::Drawing::Size(63, 17);
			this->PowerSpectroButton->TabIndex = 12;
			this->PowerSpectroButton->Text = L"Spectro";
			this->PowerSpectroButton->UseVisualStyleBackColor = true;
			this->PowerSpectroButton->Click += gcnew System::EventHandler(this, &Form1::PowerSpectroButtonClick);
			// 
			// PowerColorButton
			// 
			this->PowerColorButton->AutoSize = true;
			this->PowerColorButton->Location = System::Drawing::Point(122, 42);
			this->PowerColorButton->Name = L"PowerColorButton";
			this->PowerColorButton->Size = System::Drawing::Size(50, 17);
			this->PowerColorButton->TabIndex = 11;
			this->PowerColorButton->Text = L"Color";
			this->PowerColorButton->UseVisualStyleBackColor = true;
			this->PowerColorButton->Click += gcnew System::EventHandler(this, &Form1::PowerColorButtonClick);
			// 
			// PowerCCDButton
			// 
			this->PowerCCDButton->AutoSize = true;
			this->PowerCCDButton->Location = System::Drawing::Point(122, 20);
			this->PowerCCDButton->Name = L"PowerCCDButton";
			this->PowerCCDButton->Size = System::Drawing::Size(48, 17);
			this->PowerCCDButton->TabIndex = 10;
			this->PowerCCDButton->Text = L"CCD";
			this->PowerCCDButton->UseVisualStyleBackColor = true;
			this->PowerCCDButton->Click += gcnew System::EventHandler(this, &Form1::PowerCCDButtonClick);
			// 
			// PowerAux1Button
			// 
			this->PowerAux1Button->AutoSize = true;
			this->PowerAux1Button->Location = System::Drawing::Point(60, 42);
			this->PowerAux1Button->Name = L"PowerAux1Button";
			this->PowerAux1Button->Size = System::Drawing::Size(50, 17);
			this->PowerAux1Button->TabIndex = 9;
			this->PowerAux1Button->Text = L"Aux1";
			this->PowerAux1Button->UseVisualStyleBackColor = true;
			this->PowerAux1Button->Click += gcnew System::EventHandler(this, &Form1::PowerAux1ButtonClick);
			// 
			// PowerLightButton
			// 
			this->PowerLightButton->AutoSize = true;
			this->PowerLightButton->Location = System::Drawing::Point(59, 19);
			this->PowerLightButton->Name = L"PowerLightButton";
			this->PowerLightButton->Size = System::Drawing::Size(54, 17);
			this->PowerLightButton->TabIndex = 9;
			this->PowerLightButton->Text = L"Lights";
			this->PowerLightButton->UseVisualStyleBackColor = true;
			this->PowerLightButton->Click += gcnew System::EventHandler(this, &Form1::PowerLightButtonClick);
			// 
			// PowerFlatsButton
			// 
			this->PowerFlatsButton->AutoSize = true;
			this->PowerFlatsButton->Location = System::Drawing::Point(6, 42);
			this->PowerFlatsButton->Name = L"PowerFlatsButton";
			this->PowerFlatsButton->Size = System::Drawing::Size(48, 17);
			this->PowerFlatsButton->TabIndex = 9;
			this->PowerFlatsButton->Text = L"Flats";
			this->PowerFlatsButton->UseVisualStyleBackColor = true;
			this->PowerFlatsButton->Click += gcnew System::EventHandler(this, &Form1::PowerFlatsButtonClick);
			// 
			// PowerScopeButton
			// 
			this->PowerScopeButton->AutoSize = true;
			this->PowerScopeButton->Location = System::Drawing::Point(6, 19);
			this->PowerScopeButton->Name = L"PowerScopeButton";
			this->PowerScopeButton->Size = System::Drawing::Size(57, 17);
			this->PowerScopeButton->TabIndex = 8;
			this->PowerScopeButton->Text = L"Scope";
			this->PowerScopeButton->UseVisualStyleBackColor = true;
			this->PowerScopeButton->Click += gcnew System::EventHandler(this, &Form1::PowerScopeButtonClick);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->toolStrip1);
			this->groupBox5->Location = System::Drawing::Point(0, 27);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(210, 75);
			this->groupBox5->TabIndex = 8;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Quick Buttons";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripProgressBar1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 441);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(886, 22);
			this->statusStrip1->TabIndex = 9;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(100, 16);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->tableLayoutPanel1);
			this->groupBox6->Location = System::Drawing::Point(3, 301);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(125, 137);
			this->groupBox6->TabIndex = 10;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Time";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				36.84211F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				63.15789F)));
			this->tableLayoutPanel1->Controls->Add(this->label18, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->LSTTextBox, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->LocalTextBox, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->UTTextBox, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->JDTextBox, 1, 3);
			this->tableLayoutPanel1->Location = System::Drawing::Point(6, 19);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99813F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(114, 113);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(3, 92);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(32, 13);
			this->label18->TabIndex = 15;
			this->label18->Text = L"MJD:";
			// 
			// LSTTextBox
			// 
			this->LSTTextBox->Location = System::Drawing::Point(45, 59);
			this->LSTTextBox->Name = L"LSTTextBox";
			this->LSTTextBox->Size = System::Drawing::Size(66, 20);
			this->LSTTextBox->TabIndex = 14;
			this->LSTTextBox->Text = L"00:00:00";
			// 
			// LocalTextBox
			// 
			this->LocalTextBox->Location = System::Drawing::Point(45, 31);
			this->LocalTextBox->Name = L"LocalTextBox";
			this->LocalTextBox->Size = System::Drawing::Size(66, 20);
			this->LocalTextBox->TabIndex = 13;
			this->LocalTextBox->Text = L"00:00:00";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 63);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"LST:";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Local:";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"UT:";
			// 
			// UTTextBox
			// 
			this->UTTextBox->Location = System::Drawing::Point(45, 3);
			this->UTTextBox->Name = L"UTTextBox";
			this->UTTextBox->Size = System::Drawing::Size(66, 20);
			this->UTTextBox->TabIndex = 12;
			this->UTTextBox->Text = L"00:00:00";
			// 
			// JDTextBox
			// 
			this->JDTextBox->Location = System::Drawing::Point(45, 87);
			this->JDTextBox->Name = L"JDTextBox";
			this->JDTextBox->Size = System::Drawing::Size(66, 20);
			this->JDTextBox->TabIndex = 16;
			this->JDTextBox->Text = L"9999.99999";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->tableLayoutPanel2);
			this->groupBox7->Location = System::Drawing::Point(293, 301);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(140, 137);
			this->groupBox7->TabIndex = 11;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Scope Position";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				36.84211F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				63.15789F)));
			this->tableLayoutPanel2->Controls->Add(this->AzTextBox, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->label9, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->AltTextBox, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->DECTextBox, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->label6, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->label7, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label8, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->RATextBox, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(14, 17);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00063F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00063F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99813F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(114, 113);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// AzTextBox
			// 
			this->AzTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->AzTextBox->Location = System::Drawing::Point(45, 88);
			this->AzTextBox->Name = L"AzTextBox";
			this->AzTextBox->Size = System::Drawing::Size(66, 20);
			this->AzTextBox->TabIndex = 15;
			this->AzTextBox->Text = L"00:00:00";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 92);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(22, 13);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Az:";
			// 
			// AltTextBox
			// 
			this->AltTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->AltTextBox->Location = System::Drawing::Point(45, 60);
			this->AltTextBox->Name = L"AltTextBox";
			this->AltTextBox->Size = System::Drawing::Size(66, 20);
			this->AltTextBox->TabIndex = 14;
			this->AltTextBox->Text = L"00:00:00";
			// 
			// DECTextBox
			// 
			this->DECTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DECTextBox->Location = System::Drawing::Point(45, 32);
			this->DECTextBox->Name = L"DECTextBox";
			this->DECTextBox->Size = System::Drawing::Size(66, 20);
			this->DECTextBox->TabIndex = 13;
			this->DECTextBox->Text = L"00:00:00";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(22, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Alt:";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 35);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(32, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"DEC:";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 7);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(25, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"RA:";
			// 
			// RATextBox
			// 
			this->RATextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->RATextBox->Location = System::Drawing::Point(45, 4);
			this->RATextBox->Name = L"RATextBox";
			this->RATextBox->Size = System::Drawing::Size(66, 20);
			this->RATextBox->TabIndex = 12;
			this->RATextBox->Text = L"00:00:00.0";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->tableLayoutPanel3);
			this->groupBox8->Location = System::Drawing::Point(439, 301);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(183, 137);
			this->groupBox8->TabIndex = 12;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Observatory Status";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				85)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				91)));
			this->tableLayoutPanel3->Controls->Add(this->label1, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->label12, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->DomeSlitTextBox, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->label11, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->DomeScopeTextBox, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->label14, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->DomeAzTextBox, 1, 2);
			this->tableLayoutPanel3->Controls->Add(this->DSRInterlockTextBox, 1, 3);
			this->tableLayoutPanel3->Location = System::Drawing::Point(6, 17);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 4;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00063F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00063F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99813F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(176, 113);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 15;
			this->label1->Text = L"DSR Interlock:";
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(3, 7);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(75, 13);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Dome Shutter:";
			// 
			// DomeSlitTextBox
			// 
			this->DomeSlitTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DomeSlitTextBox->Location = System::Drawing::Point(88, 4);
			this->DomeSlitTextBox->Name = L"DomeSlitTextBox";
			this->DomeSlitTextBox->Size = System::Drawing::Size(66, 20);
			this->DomeSlitTextBox->TabIndex = 13;
			this->DomeSlitTextBox->Text = L"Closed";
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 35);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(74, 13);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Dome/Scope:";
			// 
			// DomeScopeTextBox
			// 
			this->DomeScopeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DomeScopeTextBox->Location = System::Drawing::Point(88, 32);
			this->DomeScopeTextBox->Name = L"DomeScopeTextBox";
			this->DomeScopeTextBox->Size = System::Drawing::Size(66, 20);
			this->DomeScopeTextBox->TabIndex = 14;
			this->DomeScopeTextBox->Text = L"Unlinked";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(3, 63);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(53, 13);
			this->label14->TabIndex = 13;
			this->label14->Text = L"Dome Az:";
			// 
			// DomeAzTextBox
			// 
			this->DomeAzTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DomeAzTextBox->Location = System::Drawing::Point(88, 60);
			this->DomeAzTextBox->Name = L"DomeAzTextBox";
			this->DomeAzTextBox->Size = System::Drawing::Size(31, 20);
			this->DomeAzTextBox->TabIndex = 13;
			this->DomeAzTextBox->Text = L"000";
			// 
			// DSRInterlockTextBox
			// 
			this->DSRInterlockTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DSRInterlockTextBox->Location = System::Drawing::Point(88, 88);
			this->DSRInterlockTextBox->Name = L"DSRInterlockTextBox";
			this->DSRInterlockTextBox->Size = System::Drawing::Size(66, 20);
			this->DSRInterlockTextBox->TabIndex = 16;
			this->DSRInterlockTextBox->Text = L"Closed";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->tableLayoutPanel4);
			this->groupBox9->Location = System::Drawing::Point(628, 301);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(258, 140);
			this->groupBox9->TabIndex = 13;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Misc. Status";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 4;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				77)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				58)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				59)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				39)));
			this->tableLayoutPanel4->Controls->Add(this->label21, 0, 3);
			this->tableLayoutPanel4->Controls->Add(this->label19, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->MirrorCoverTextBox, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->label16, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->GuidingTextBox, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->label20, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->FocusPosTextBox, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->FocusTempTextBox, 1, 3);
			this->tableLayoutPanel4->Controls->Add(this->label22, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->FWPositionTextBox, 3, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(6, 19);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 4;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00063F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00063F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99813F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(233, 113);
			this->tableLayoutPanel4->TabIndex = 14;
			// 
			// label21
			// 
			this->label21->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(3, 92);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(69, 13);
			this->label21->TabIndex = 18;
			this->label21->Text = L"Focus Temp:";
			// 
			// label19
			// 
			this->label19->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(3, 7);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(67, 13);
			this->label19->TabIndex = 0;
			this->label19->Text = L"Mirror Cover:";
			// 
			// MirrorCoverTextBox
			// 
			this->MirrorCoverTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MirrorCoverTextBox->Location = System::Drawing::Point(80, 4);
			this->MirrorCoverTextBox->Name = L"MirrorCoverTextBox";
			this->MirrorCoverTextBox->Size = System::Drawing::Size(47, 20);
			this->MirrorCoverTextBox->TabIndex = 12;
			this->MirrorCoverTextBox->Text = L"N/A";
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(3, 35);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(46, 13);
			this->label16->TabIndex = 12;
			this->label16->Text = L"Guiding:";
			// 
			// GuidingTextBox
			// 
			this->GuidingTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GuidingTextBox->Location = System::Drawing::Point(80, 32);
			this->GuidingTextBox->Name = L"GuidingTextBox";
			this->GuidingTextBox->Size = System::Drawing::Size(47, 20);
			this->GuidingTextBox->TabIndex = 15;
			this->GuidingTextBox->Text = L"Off";
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(3, 63);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(60, 13);
			this->label20->TabIndex = 16;
			this->label20->Text = L"Focus Pos:";
			// 
			// FocusPosTextBox
			// 
			this->FocusPosTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FocusPosTextBox->Location = System::Drawing::Point(80, 60);
			this->FocusPosTextBox->Name = L"FocusPosTextBox";
			this->FocusPosTextBox->Size = System::Drawing::Size(47, 20);
			this->FocusPosTextBox->TabIndex = 17;
			this->FocusPosTextBox->Text = L"0";
			// 
			// FocusTempTextBox
			// 
			this->FocusTempTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FocusTempTextBox->Location = System::Drawing::Point(80, 88);
			this->FocusTempTextBox->Name = L"FocusTempTextBox";
			this->FocusTempTextBox->Size = System::Drawing::Size(47, 20);
			this->FocusTempTextBox->TabIndex = 19;
			this->FocusTempTextBox->Text = L"0";
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(138, 7);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(48, 13);
			this->label22->TabIndex = 20;
			this->label22->Text = L"FW Pos:";
			// 
			// FWPositionTextBox
			// 
			this->FWPositionTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FWPositionTextBox->Location = System::Drawing::Point(197, 4);
			this->FWPositionTextBox->Name = L"FWPositionTextBox";
			this->FWPositionTextBox->Size = System::Drawing::Size(33, 20);
			this->FWPositionTextBox->TabIndex = 21;
			this->FWPositionTextBox->Text = L"-1";
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->tableLayoutPanel5);
			this->groupBox10->Location = System::Drawing::Point(134, 301);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(153, 140);
			this->groupBox10->TabIndex = 15;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Weather";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				85)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->tableLayoutPanel5->Controls->Add(this->label13, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->HumidityTextBox, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->label10, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->OutsideTempTextBox, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->label17, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->label15, 0, 3);
			this->tableLayoutPanel5->Controls->Add(this->WindSpeedTextBox, 1, 3);
			this->tableLayoutPanel5->Controls->Add(this->DewPointTextBox, 1, 2);
			this->tableLayoutPanel5->Location = System::Drawing::Point(6, 19);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 4;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00063F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00063F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99813F)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(137, 113);
			this->tableLayoutPanel5->TabIndex = 14;
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 63);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(59, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"Dew Point:";
			// 
			// HumidityTextBox
			// 
			this->HumidityTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->HumidityTextBox->Location = System::Drawing::Point(88, 32);
			this->HumidityTextBox->Name = L"HumidityTextBox";
			this->HumidityTextBox->Size = System::Drawing::Size(42, 20);
			this->HumidityTextBox->TabIndex = 18;
			this->HumidityTextBox->Text = L"+00 F";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 7);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(76, 13);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Outside Temp:";
			// 
			// OutsideTempTextBox
			// 
			this->OutsideTempTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->OutsideTempTextBox->Location = System::Drawing::Point(88, 4);
			this->OutsideTempTextBox->Name = L"OutsideTempTextBox";
			this->OutsideTempTextBox->Size = System::Drawing::Size(42, 20);
			this->OutsideTempTextBox->TabIndex = 12;
			this->OutsideTempTextBox->Text = L"+00 F";
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(3, 35);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(50, 13);
			this->label17->TabIndex = 17;
			this->label17->Text = L"Humidity:";
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(3, 92);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(69, 13);
			this->label15->TabIndex = 16;
			this->label15->Text = L"Wind Speed:";
			// 
			// WindSpeedTextBox
			// 
			this->WindSpeedTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->WindSpeedTextBox->Location = System::Drawing::Point(88, 88);
			this->WindSpeedTextBox->Name = L"WindSpeedTextBox";
			this->WindSpeedTextBox->Size = System::Drawing::Size(42, 20);
			this->WindSpeedTextBox->TabIndex = 16;
			this->WindSpeedTextBox->Text = L"00 W";
			// 
			// DewPointTextBox
			// 
			this->DewPointTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DewPointTextBox->Location = System::Drawing::Point(88, 60);
			this->DewPointTextBox->Name = L"DewPointTextBox";
			this->DewPointTextBox->Size = System::Drawing::Size(42, 20);
			this->DewPointTextBox->TabIndex = 19;
			this->DewPointTextBox->Text = L"+00 F";
			// 
			// MainTmer
			// 
			this->MainTmer->Enabled = true;
			this->MainTmer->Interval = 1000;
			this->MainTmer->Tick += gcnew System::EventHandler(this, &Form1::MainTimerTick);
			// 
			// MainStatusBox
			// 
			this->MainStatusBox->Location = System::Drawing::Point(3, 108);
			this->MainStatusBox->Name = L"MainStatusBox";
			this->MainStatusBox->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
			this->MainStatusBox->Size = System::Drawing::Size(883, 187);
			this->MainStatusBox->TabIndex = 16;
			this->MainStatusBox->Text = L"";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(886, 463);
			this->Controls->Add(this->MainStatusBox);
			this->Controls->Add(this->groupBox10);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->MainMenu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->MainMenu;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"OSUrob - The Ohio State University at Lima Robotic Observatory";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1ClosingEventHandler);
			this->MainMenu->ResumeLayout(false);
			this->MainMenu->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StepSizeNumeric))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->groupBox10->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
			 }
private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void OpenSlitMenuItemClick(System::Object^  sender, System::EventArgs^  e) {

			 short dummy, answer, ntries;
			 bool success=false;

			 // Ask user if sure...

			 if (! Observatory.DomeHome) {
				 Form1::StatusPrint("*** Warning - Dome not home, move dome home first...\n");
				 return;
			 }
			 if (! Observatory.DomeHome) {
				 Form1::StatusPrint("*** Warning - Dome not home, move dome home first...\n");
				 return;
			 }
			 answer = MessageBox("Sure you want to OPEN observatory shutter?", YESNO);
			 if ((answer == CANCEL) || (answer == NO))
				 return;

			 dummy = 0;
			 DontUpdateNow(true);
			 ntries = 0;
			 do {
				 success = DoDomeFunction(DDW_OPEN_SHUTTER, &dummy, true);
				 if (success) break;
				 usleep(100000, true);
				 ntries++;
			 } while (ntries < 10);
			 DontUpdateNow(false);
			 if (! success)
				 Form1::StatusPrint("*** Warning - Open dome shutter failed...\n");

		 }
private: System::Void CloseSlitMenuItemClick(System::Object^  sender, System::EventArgs^  e) {

			 short dummy, answer;

			 // Ask user if sure...

			 answer = MessageBox("Sure you want to CLOSE observatory shutter?", YESNO);
			 if ((answer == CANCEL) || (answer == NO))
				 return;

			 dummy = 0;
			 DoDomeFunction(DDW_CLOSE_SHUTTER, &dummy, true);
		 }
private: System::Void HomeDomeMenuItemClick(System::Object^  sender, System::EventArgs^  e) {

			 short dummy, ntries;
			 bool success;

			 if (Observatory.DomeHome) {
				 Form1::StatusPrint("*** Info - Dome is already at home position\n");
				 return;
			 }

			 DontUpdateNow(true);
			 ntries = 0;
			 do {
				success = DoDomeFunction(DDW_HOME_DOME,&dummy,true);
				ntries++;
			 } while ((! success) && (ntries <= 5));
			 DontUpdateNow(false);
			 if (! success) {
				 Form1::StatusPrint("*** Warning - Couldn't send dome to home position\n");
			 }
		 }
private: System::Void Form1ClosingEventHandler(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

			 if (ExitMenuItemClicked)
				 return;
			 if (! CloseObservatory()) {
				 e->Cancel = true;
			 }
		 }
private: System::Void ExitMenuItemClick(System::Object^  sender, System::EventArgs^  e) {

			 int answer;
			 answer = MessageBox("Sure you want to exit OSUrob?", YESNO);
			 if ((answer == CANCEL) || (answer == NO))
				 return;
			 ExitMenuItemClicked = true;
			 if (CloseObservatory()) {
				 Application::Exit();
			 } else
				 ExitMenuItemClicked = false;
		 }
private: System::Void OpenMirrorCoverMenuItemClick(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void CloseMirrorCoverMenuItemClick(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void HandBoxMenuItemClick(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void MoveScopeMenuItemClick(System::Object^  sender, System::EventArgs^  e) {

			 ShowMoveScopeDialog();
			 return;
		 }
private: System::Void calibrateInstrumentSelectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];

			 if (! CalibrateISDialogExists) {
				 gcnew CalibrateISDialog();
			 }
			 sprintf_s(buffer, sizeof(buffer), "%d", ISSettings.CurrentStepPosition);
			 CalibrateISDialog::FormPtr->SetPositionTextBox(buffer);
			 CalibrateISDialog::FormPtr->Show();
		 }
private: System::Void OpenObsButtonClick(System::Object^  sender, System::EventArgs^  e) {

		 int answer;
		 bool success;
		 short dummy;
			 
		 answer = MessageBox("Sure you want to OPEN observatory?", YESNO);
		 if (answer != YES)
			 return;

		 // Check weather, make sure okay to open

		 answer = MessageBox("Check the current weather radar/cloud images at weather.com\n Want to continue?", YESNO);
		 if (answer != YES)
			 return;
		 answer = MessageBox("Now check that wind speed is < 25 mph using the Heavy Weather program.  Want to continue?",
			 YESNO);
		 if (answer != YES)
			 return;

		 // Turn on AC power to ccds

		 Form1::StatusPrint("*** Turning on ccd...\n");
		 PowerOnOff(ACPOWER_PORT_CCD,ACPOWER_ON);
		 usleep(5000000,true);

		 // Turn on AC power to scope

		 Form1::StatusPrint("*** Turning on scope...\n");
		 PowerOnScope();

		 // Check if dome is home.  If not, home it

		 if (! Observatory.DomeHome) {
			 answer = MessageBox("Dome not home, want to continue to open observatory?", YESNO);
			 if (answer != YES)
				 return;
			 Form1::StatusPrint("*** Info - Sending dome to home position.");
			 success = DoDomeFunction(DDW_HOME_DOME, &dummy, true);
			 if (! success) {
				 Form1::StatusPrint("*** Warning - Failed to home dome, cancelling open.\n");
				 return;
			 }
		 }

		 // Open Dome slit

		 Form1::StatusPrint("*** Info - Opening dome shutter, will take ~ 2 minutes...\n");
		 success = DoDomeFunction(DDW_OPEN_SHUTTER, &dummy, true);  // open dome

		 // Set Instrument selector to ccd

		 Form1::StatusPrint("*** Info - Setting instrument port to ccd.\n");
		 SelectPort(CCDPORT);

		 Form1::StatusPrint("*** Info - Observatory is open...\n");

		 }

private: System::Void CloseObsButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 int answer;
			 bool success;
			 short dummy;

			 answer = MessageBox("Sure you want to CLOSE observatory?", YESNO);
			 if (answer != YES)
				return;

			 Form1::StatusPrint("*** Info - Sending dome to home position\n");
			 success = DoDomeFunction(DDW_HOME_DOME, &dummy, true);
			 if (! success) {
				 answer = MessageBox("WARNING - Can't home dome, can't close shutter."
					 "PLEASE MANUALLY CLOSE! Click okay when done", OKAY);
				 return;
			 }

			 Form1::StatusPrint("*** Info - Closing shutter, will take about 2 minutes.\n");
			 success = DoDomeFunction(DDW_CLOSE_SHUTTER, &dummy, true);
			 if (! success) {
				 answer = MessageBox("WARNING - Can't close shutter."
					 "PLEASE MANUALLY CLOSE! Click okay when done", OKAY);
				 return;
			 }

			 Form1::StatusPrint("*** Info - Turning off scope & ccds\n");
			 PowerOnOff(ACPOWER_PORT_CCD, ACPOWER_OFF);
			 PowerOffScope();

			 Form1::StatusPrint("*** Info - Observatory is closed\n");

			 return;

		 }

private: System::Void EyeButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 SelectPort(EYEPORT);
		 }
private: System::Void ColorCCDButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 SelectPort(COLORCCDPORT);
		 }
private: System::Void CCDButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 SelectPort(CCDPORT);
		 }
private: System::Void SpectroButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 SelectPort(SPECTROPORT);
		 }
private: System::Void NorthButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 float StepSize, StepSizeInMins, zero=0.0;
			 char Message[160];

			 // Get step size to move scope
			 
			 StepSize = Decimal::ToSingle(Form1::StepSizeNumeric->Value);

			 // Get units on step size

			 if (Form1::DegRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = (float) (StepSize*60.0);
			 } else if (Form1::MinRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > 60.0*MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = StepSize;
			 } else if (Form1::SecRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > 3600.0*MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = (float) (StepSize/60.0);
			 }

			 // Move the scope

			 DoScopeFunction(SCOPE_BUMP, &zero, &StepSizeInMins, true);

			 // Tell user scope was moved

			 sprintf_s(Message, sizeof(Message), "*** Info - Scope was moved north by %f arcmins\n", StepSizeInMins);
			 Form1::StatusPrint(Message);
		 }
private: System::Void SouthButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 float StepSize, StepSizeInMins, zero=0.0;
			 char Message[160];

			 // Get step size to move scope
			 
			 StepSize = Decimal::ToSingle(Form1::StepSizeNumeric->Value);

			 // Get units on step size

			 if (Form1::DegRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = (float) (StepSize*60.0);
			 } else if (Form1::MinRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > 60.0*MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = StepSize;
			 } else if (Form1::SecRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > 3600.0*MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = (float) (StepSize/60.0);
			 }
			 StepSizeInMins = - StepSizeInMins;

			 // Move the scope

			 DoScopeFunction(SCOPE_BUMP, &zero, &StepSizeInMins, true);

			 // Tell user scope was moved

			 sprintf_s(Message, sizeof(Message), "*** Info - Scope was moved south by %f arcmins\n", StepSizeInMins);
			 Form1::StatusPrint(Message);
		 }
private: System::Void EastButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 float StepSize, StepSizeInMins, zero=0.0;
			 char Message[160];

			 // Get step size to move scope
			 
			 StepSize = Decimal::ToSingle(Form1::StepSizeNumeric->Value);

			 // Get units on step size

			 if (Form1::DegRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = (float) (StepSize*60.0);
			 } else if (Form1::MinRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > 60.0*MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = StepSize;
			 } else if (Form1::SecRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > 3600.0*MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = (float) (StepSize/60.0);
			 }

			 // Move the scope

			 DoScopeFunction(SCOPE_BUMP, &StepSizeInMins, &zero, true);

			 // Tell user scope was moved

			 sprintf_s(Message, sizeof(Message), "*** Info - Scope was moved east by %f arcmins\n", StepSizeInMins);
			 Form1::StatusPrint(Message);
		 }
private: System::Void WestButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 float StepSize, StepSizeInMins, zero=0.0;
			 char Message[160];

			 // Get step size to move scope
			 
			 StepSize = Decimal::ToSingle(Form1::StepSizeNumeric->Value);

			 // Get units on step size

			 if (Form1::DegRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = (float) (StepSize*60.0);
			 } else if (Form1::MinRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > 60.0*MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = StepSize;
			 } else if (Form1::SecRadioButton->Checked) {
				 if ((StepSize <= 0.0) || (StepSize > 3600.0*MAXSLEWSTEPSIZE)) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Scope Slew Step size not appropriate: %f\n", StepSize);
					 MessageBox(Message, OKAY);
					 return;
				 }
				 StepSizeInMins = (float) (StepSize/60.0);
			 }
			 StepSizeInMins = - StepSizeInMins;

			 // Move the scope

			 DoScopeFunction(SCOPE_BUMP, &StepSizeInMins, &zero, true);

			 // Tell user scope was moved

			 sprintf_s(Message, sizeof(Message), "*** Info - Scope was moved west by %f arcmins\n", StepSizeInMins);
			 Form1::StatusPrint(Message);
		 }
private: System::Void DomeGotoGoButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 short nItems, azimuth, ntries, diff;
			 bool success;
			 char buffer[80], message[160];

			 if (!DDWOPEN) {
				 Form1::StatusPrint("*** Sorry - Can't move dome, no connection to DDW (DomeGotoGoButtonClick)\n");
				 return;
			 }
			 Form1::OSUrobForm->GetDomeGotoAzTextBox(buffer);
			 nItems = sscanf_s(buffer,"%hd", &azimuth);
			 if (nItems != 1) {
				 sprintf_s(message, sizeof(message),
						"*** Warning - bad format in requested azimuth: %s\n", buffer);
				 Form1::StatusPrint(message);
				 return;
			 }
			 if ((azimuth < 0) || (azimuth > 360)) {
				 sprintf_s(message, sizeof(message),
					 "*** Warning - Requested azimuth: %d, out of of range 0 to 360\n", azimuth);
				 Form1::StatusPrint(message);
				 return;
			 }
			 diff = ((short) (azimuth - Observatory.DomeCurrentAzimuth));
			 if (diff < -180)
				 diff += 360;
			 else if (diff > 180)
				 diff -= 360;
			 diff = abs(diff);
			 if (diff < 5) {
				 Form1::StatusPrint("*** Warning - Dome moves must be > 5 degrees\n");
				 return;
			 }
			 ntries = 0;
			 DontUpdateNow(true);
			 do {
				success = DoDomeFunction(DDW_ROTATE_DOME,&azimuth,true);
				if (success)
					break;
				usleep(100000,true);
				ntries++;
			 } while (ntries < 10);
			 DontUpdateNow(false);
			 if (! success)
				 Form1::StatusPrint("*** Warning - Dome rotation failed\n");

		 }
private: System::Void PowerScopeButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 if (Form1::OSUrobForm->PowerScopeButton->Checked) {
				 PowerOnScope();
			 } else
				 PowerOffScope();
		 }

private: System::Void PowerFlatsButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 if (Form1::OSUrobForm->PowerFlatsButton->Checked)
				 PowerOnOff(ACPOWER_PORT_FLATS,ACPOWER_ON);
			 else
				 PowerOnOff(ACPOWER_PORT_FLATS,ACPOWER_OFF);
		 }

private: System::Void PowerLightButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 if (Form1::OSUrobForm->PowerLightButton->Checked)
				 PowerOnOff(ACPOWER_PORT_LIGHT,ACPOWER_ON);
			 else
				 PowerOnOff(ACPOWER_PORT_LIGHT,ACPOWER_OFF);
		 }

private: System::Void PowerAux1ButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 if (Form1::OSUrobForm->PowerAux1Button->Checked)
				 PowerOnOff(ACPOWER_PORT_AUX1,ACPOWER_ON);
			 else
				 PowerOnOff(ACPOWER_PORT_AUX1,ACPOWER_OFF);
		 }

private: System::Void PowerCCDButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 if (Form1::OSUrobForm->PowerCCDButton->Checked)
				 PowerOnOff(ACPOWER_PORT_CCD,ACPOWER_ON);
			 else
				 PowerOnOff(ACPOWER_PORT_CCD,ACPOWER_OFF);
		 }

private: System::Void PowerColorButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 if (Form1::OSUrobForm->PowerColorButton->Checked)
				 PowerOnOff(ACPOWER_PORT_COLOR,ACPOWER_ON);
			 else
				 PowerOnOff(ACPOWER_PORT_COLOR,ACPOWER_OFF);
		 }
private: System::Void PowerSpectroButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 if (Form1::OSUrobForm->PowerSpectroButton->Checked)
				 PowerOnOff(ACPOWER_PORT_SPECTRO,ACPOWER_ON);
			 else
				 PowerOnOff(ACPOWER_PORT_SPECTRO,ACPOWER_OFF);
		 }
private: System::Void PowerAux2ButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 if (Form1::OSUrobForm->PowerAux2Button->Checked)
				 PowerOnOff(ACPOWER_PORT_AUX2,ACPOWER_ON);
			 else
				 PowerOnOff(ACPOWER_PORT_AUX2,ACPOWER_OFF);
		 }

private: System::Void DomeStopButtonClick(System::Object^  sender, System::EventArgs^  e) {

			 SendDDWText("GSTP"); // Command DDW to stop dome/shutter movement
			 Form1::StatusPrint("*** Warning - Send 'All Stop' command to DDW...\n");
		 }

private: System::Void DomeLinkCheckButtonChanged(System::Object^  sender, System::EventArgs^  e) {

			 bool state;

			 state = Form1::DomeLinkCheckButton->Checked;
			 Observatory.DomeLinked = state;
		 }
private: System::Void MainTimerTick(System::Object^  sender, System::EventArgs^  e) {

			 static int DomeCountDown;
			 static bool First=true;

			 if (First) {
				 DomeCountDown = 5;
				 First = false;
			 }

			 if (TimerBusy)
				return;

			 TimerBusy = true;
			 ProcessMessages();
			 Form1::UpdateMainWindow();

			 if (Observatory.DomeLinked) {
				 if (DomeCountDown-- == 0) {
					 SyncDomeScope();
					 DomeCountDown = 5;
				 }
			 }

			 TimerBusy = false;
		 }


		 // Public routines

public: static bool CloseObservatory() {

			short dummy=0, i;
			float fdummy=0.0;
			char Message[160];
//			int answer;
			FILE *fptr;

			DoDomeFunction(DDW_CLOSE,&dummy,true); // close serial port to DDW
			DoScopeFunction(SCOPE_CLOSE, &fdummy, &fdummy, true);

			// Save spectrograph settings

			fopen_s(&fptr, SPECTROGRAPHSETTINGSFILE, "w");
			if (fptr == NULL) {
				sprintf_s(Message, sizeof(Message), "Warning can't save spectrograph settings to file: %s", SPECTROGRAPHSETTINGSFILE);
				MessageBox(Message, OKAY);
			} else {
				fprintf_s(fptr, "Low (A): %d\nMid (A): %d\nHigh (A): %d\nAPerStep: %f\nAPerPixel: %f\n# Pixels: %d",
					SpSettings.LowWavelength, SpSettings.MidWavelength, SpSettings.HighWavelength,
					SpSettings.AngstromsPerStep, SpSettings.AngstromsPerPixel, SpSettings.NumPixels);
				fclose(fptr);
			}

			// Save focuser settings

			fopen_s(&fptr, FOCUSERSETTINGSFILE, "w");
			if (fptr == NULL) {
				sprintf_s(Message, sizeof(Message), "Warning can't save focuser settings to file: %s", FOCUSERSETTINGSFILE);
				MessageBox(Message, OKAY);
			}
			else {
				fprintf_s(fptr, "%lf %lf\n", FocuserSettings.TempCalSlope, FocuserSettings.TempCalZeroPoint);
				for (i = 0; i < FocuserSettings.numFocusPositions; i++) {
					fprintf_s(fptr, "%04d %06.1f %s\n", FocuserSettings.FocusPositionValues[i],
							FocuserSettings.FocusPositionTemps[i], FocuserSettings.FocusPositionNames[i]);
				}
				fclose(fptr);
			}


			// Close com port to observatory controller

			if (Form1::ObsConComPortPtr != nullptr) {
				if (Form1::ObsConComPortPtr->IsOpen)
					Form1::ObsConComPortPtr->Close();
			}

			return true;
		}


public: bool UpdateMainWindow() {

	static unsigned short DDWCountToTryAgain = 0;
	static bool UpdateBusy = false;
	struct tm LocalTime, UTTime;
	__time64_t CurrentSeconds;
	double JDate, lst;
	short dummy, i, nTries;
	bool success;
	int lsthrs, lstmin, lstsec, result, DiffTime, FWPosition;
	static int UpdateDomeScopeFreq = 0;
	FILE *fptr;
	int rah, ram, decd, decm, azd, azm, altd, altm, nItems;
	short hours, degs, mins, value;
	float ras, decs, azs, alts, fdummy, secs;
	struct _stat buf;
	char buffer[120], Message[240];

	// Don't update if not supposed to

	if (Form1::DontUpdate)
		return false;

	if (!OSUrobFormExists)
		return false;

	if (UpdateBusy)
		return false;
	UpdateBusy = true;

	// Create link to digital dome works control

	if (!DDWOPEN) {
		if (DDWCountToTryAgain == 0) {
			dummy = 0;
			if (DoDomeFunction(DDW_INIT, &dummy, true)) {
				DDWOPEN = true;
			} else {
				DDWCountToTryAgain = 10;
			}
		} else {
			DDWCountToTryAgain--;
		}
	} 

	// Update time displays

		// UT

	_time64(&CurrentSeconds);
	_gmtime64_s(&UTTime, &CurrentSeconds);
	strftime(buffer, sizeof(buffer), "%X", &UTTime);
	SetUTTextBox(buffer);

	// Local

	_localtime64_s(&LocalTime, &CurrentSeconds);
	strftime(buffer, sizeof(buffer), "%X", &LocalTime);
	SetLocalTextBox(buffer);

	// Julian Date

	JulianDay(UTTime.tm_year + 1900, UTTime.tm_mon,
		UTTime.tm_mday, UTTime.tm_hour,
		UTTime.tm_min, UTTime.tm_sec, 0, &JDate);
	sprintf_s(buffer, sizeof(buffer), "%lf13.5", JDate - 2450000.0);
	SetJDTextBox(buffer);

	// Local Sidereal Time

	lmst(JDate, &lst);
	lsthrs = (int)floor(lst);
	lstmin = (int)floor((lst - lsthrs)*60.0);
	lstsec = (int)floor((lst - lsthrs - lstmin / 60.0)*3600.0);
	sprintf_s(buffer, sizeof(buffer), "%02i:%02i:%02i", lsthrs, lstmin, lstsec);
	SetLSTTextBox(buffer);

	// Update dome status

	if (UpdateDomeScopeFreq < 3) {
		UpdateDomeScopeFreq++;
	} else {
		UpdateDomeScopeFreq = 0;
		if (DDWOPEN) {
			success = DoDomeFunction(DDW_GET_DOME_STATUS, &dummy, true);
			if (success) {
				if (Observatory.DomeLinked)
					Form1::OSUrobForm->SetDomeScopeTextBox("Linked");
				else
					Form1::OSUrobForm->SetDomeScopeTextBox("Unlinked");
				sprintf_s(buffer, sizeof(buffer), "%4.0f", Observatory.DomeCurrentAzimuth);
				SetDomeAzTextBox(buffer);
				if (Observatory.ShutterPercentOpen >= 100)
					Form1::SetDomeSlitTextBox("Fully Open");
				else if (Observatory.ShutterPercentOpen == 0)
					Form1::SetDomeSlitTextBox("Fully Closed");
				else if (Observatory.ShutterPercentOpen < 0)
					Form1::SetDomeSlitTextBox("Partial Open");
				else {
					sprintf_s(buffer, sizeof(buffer), "%3d%% Open\n", Observatory.ShutterPercentOpen);
					Form1::SetDomeSlitTextBox(buffer);
				}
				if (Observatory.DSRInterlock == 0)
					Form1::SetDSRInterlockTextBox("Unknown");
				else if (Observatory.DSRInterlock == 1)
					Form1::SetDSRInterlockTextBox("Closed");
				else
					Form1::SetDSRInterlockTextBox("Open");
			}
			else {
//				Form1::StatusPrint("*** Warning - Can't get Dome info in UpdateMainWindow...\n");
			}
		}
	}

	// Update RoboFocuser status

	if (!RoboFocuserExists) {
		gcnew RoboFocuser();
		RoboFocuserExists = true;
	}

	// Update AC power status

	if (RoboFocuser::Ptr->ComPortOpen) {
		for (i = 1; i < 5; i++)
			Observatory.ACPower[i - 1] = RoboFocuser::Ptr->GetUserButtonState(i);
	} else {
		for (i = 1; i < 5; i++)
			Observatory.ACPower[i - 1] = false;
	}

	nTries = 0;
	do {
		SendObsCon("$AC_GET#", buffer, sizeof(buffer));
		nItems = sscanf_s(buffer, "$AC_POW %hd", &value);
		if (nItems == 1) break;
		nTries++;
		usleep(10000, true);
	} while (nTries < 10);
	if (nItems == 1) {
		Observatory.ACPower[4] = ((value & 0x01) != 0);
		Observatory.ACPower[5] = ((value & 0x02) != 0);
		Observatory.ACPower[6] = ((value & 0x04) != 0);
		Observatory.ACPower[7] = ((value & 0x08) != 0);
	} else {
//		sprintf_s(Message, sizeof(Message), "*** Warning - Can't get AC power info in UpdateMainWindow (%s)...\n", buffer);
//		Form1::StatusPrint(Message);
		Observatory.ACPower[4] = false;
		Observatory.ACPower[5] = false;
		Observatory.ACPower[6] = false;
		Observatory.ACPower[7] = false;
	}

	if (Observatory.ACPower[ACPOWER_PORT_SCOPE-1] != Form1::OSUrobForm->PowerScopeButton->Checked)
		Form1::OSUrobForm->PowerScopeButton->Checked = Observatory.ACPower[ACPOWER_PORT_SCOPE-1];
	if (Observatory.ACPower[ACPOWER_PORT_FLATS-1] != Form1::OSUrobForm->PowerFlatsButton->Checked)
		Form1::OSUrobForm->PowerFlatsButton->Checked = Observatory.ACPower[ACPOWER_PORT_FLATS-1];
	if (Observatory.ACPower[ACPOWER_PORT_LIGHT-1] != Form1::OSUrobForm->PowerLightButton->Checked)
		Form1::OSUrobForm->PowerLightButton->Checked = Observatory.ACPower[ACPOWER_PORT_LIGHT-1];
	if (Observatory.ACPower[ACPOWER_PORT_AUX1-1] != Form1::OSUrobForm->PowerAux1Button->Checked)
		Form1::OSUrobForm->PowerAux1Button->Checked = Observatory.ACPower[ACPOWER_PORT_AUX1-1];
	if (Observatory.ACPower[ACPOWER_PORT_CCD-1] != Form1::OSUrobForm->PowerCCDButton->Checked)
		Form1::OSUrobForm->PowerCCDButton->Checked = Observatory.ACPower[ACPOWER_PORT_CCD-1];
	if (Observatory.ACPower[ACPOWER_PORT_COLOR-1] != Form1::OSUrobForm->PowerColorButton->Checked)
		Form1::OSUrobForm->PowerColorButton->Checked = Observatory.ACPower[ACPOWER_PORT_COLOR-1];
	if (Observatory.ACPower[ACPOWER_PORT_SPECTRO-1] != Form1::OSUrobForm->PowerSpectroButton->Checked)
		Form1::OSUrobForm->PowerSpectroButton->Checked = Observatory.ACPower[ACPOWER_PORT_SPECTRO-1];
	if (Observatory.ACPower[ACPOWER_PORT_AUX2-1] != Form1::OSUrobForm->PowerAux2Button->Checked)
		Form1::OSUrobForm->PowerAux2Button->Checked = Observatory.ACPower[ACPOWER_PORT_AUX2-1];

	// Update filter wheel position

	nTries = 0;
	do {
		SendObsCon("$FW_GET#", buffer, sizeof(buffer));
		nItems = sscanf_s(buffer, "$FW_AT %d#", &FWPosition);
		if (nItems == 1) break;
		nTries++;
		usleep(10000, true);
	} while (nTries < 10);
	if (nItems == 1) {
		if ((FWPosition > 0) && (FWPosition < 8))
			sprintf_s(buffer, sizeof(buffer), "%c", Observatory.FWPositions[FWPosition-1]);
		else
			strcpy_s(buffer, sizeof(buffer), "UNK");
		Form1::OSUrobForm->SetFWTextBox(buffer);
	} else {
//		sprintf_s(Message, sizeof(Message), "*** Warning - Can't get FW info in UpdateMainWindow (%s)...\n", buffer);
//		Form1::StatusPrint(Message);
		Form1::OSUrobForm->SetFWTextBox("UNK");
	}

	// Update Scope Position  (via TheSky file, or internally)

	success = false;
	result = _stat(THESKYSCOPEPOSITIONFILE, &buf);
	if (result == 0) {
		DiffTime = ((int) (CurrentSeconds - buf.st_mtime));
//		DiffTime = 10; // ALS - DEBUG
		if (abs(DiffTime) < 60) {
			errno_t err = fopen_s(&fptr, THESKYSCOPEPOSITIONFILE, "r");
			if (err == 0) {
				fgets(buffer, sizeof(buffer), fptr);
				nItems = sscanf_s(buffer, "RA=%2dh %2dm %fs  DEC=%3d°%2d'%f%*c  AZ=%3d°%2d'%f%*c  ALT=%3d°%2d'%f",
					&rah, &ram, &ras, &decd, &decm, &decs, &azd, &azm, &azs, &altd, &altm, &alts);
				if (nItems != 12) {
					sprintf_s(Message, sizeof(Message), "*** Warning - Bad format in TheSky scope position: %s\n", buffer);
					Form1::StatusPrint(Message);
				} else {
					ScopeInfo.RA =  ((float) (((float) rah) + ((float) ram)/60.0 + ras/3600.0));
					ScopeInfo.DEC = ((float) (((float) decd) + ((float) decm)/60.0 + decs/3600.0));
					ScopeInfo.Az =  ((float) (((float) azd) + ((float) azm)/60.0 + azs/3600.0));
					ScopeInfo.Alt = ((float) (((float) altd) + ((float) altm)/60.0 + alts/3600.0));
//					ScopeInfo.Az = 90.0; ScopeInfo.Alt = 45.0;  // ALS - DEBUG
				}
				fclose(fptr);
				success = true;
			}
		}
	}
	if (! success) {
		if (ScopeInfo.LinkOpen) {
			success = DoScopeFunction(SCOPE_GET_POSITION, &fdummy, &fdummy, true);
		}
	}

	if (ScopeInfo.RA > 0.0) {

		hours = ((short) ScopeInfo.RA);
		mins = ((short) ((ScopeInfo.RA - hours)*60.0));
		secs = ((float) ((ScopeInfo.RA - hours - mins/60.0)*3600.0));
		sprintf_s(buffer, sizeof(buffer), "%02d:%02d:%04.1f", hours, mins, secs);
		Form1::SetRATextBox(buffer);

		degs = ((short) ScopeInfo.DEC);
		mins = ((short) ((ScopeInfo.DEC - degs)*60.0));
		secs = ((float) ((ScopeInfo.DEC - degs - mins/60.0)*3600.0));	
		sprintf_s(buffer, sizeof(buffer), "%3d:%02d:%04.1f", degs, abs(mins), fabs(secs));
		Form1::SetDECTextBox(buffer);

		degs = ((short) ScopeInfo.Az);
		mins = ((short) ((ScopeInfo.Az - degs)*60.0));
		secs = ((float) ((ScopeInfo.Az - degs - mins/60.0)*3600.0));	
		sprintf_s(buffer, sizeof(buffer), "%03d:%02d:%04.1f", degs, mins, secs);
		Form1::SetAzTextBox(buffer);

		degs = ((short) ScopeInfo.Alt);
		mins = ((short) ((ScopeInfo.Alt - degs)*60.0));
		secs = ((float) ((ScopeInfo.Alt - degs - mins/60.0)*3600.0));	
		sprintf_s(buffer, sizeof(buffer), "%02d:%02d:%04.1f", degs, abs(mins), fabs(secs));
		Form1::SetAltTextBox(buffer);

	} else {

		Form1::SetRATextBox("Unknown");
		Form1::SetDECTextBox("Unknown");
		Form1::SetAzTextBox("Unknown");
		Form1::SetAltTextBox("Unknown");
	}

	UpdateBusy = false;
	return false;

}
public: static void SetInstrumentPortButtons(short port) {

			switch (port) {
				case CCDPORT:
					Form1::OSUrobForm->CCDButton->Checked = true;
					break;
				case EYEPORT:
					Form1::OSUrobForm->EyeButton->Checked = true;
					break;
				case COLORCCDPORT:
					Form1::OSUrobForm->ColorCCDButton->Checked = true;
					break;
				case SPECTROPORT:
					Form1::OSUrobForm->SpectroButton->Checked = true;
					break;
				default:
					break;
			}
			return;
		}
public: static void SetDomeScopeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->DomeScopeTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetDomeSlitTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->DomeSlitTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetDSRInterlockTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->DSRInterlockTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetDomeAzTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->DomeAzTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetRATextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->RATextBox->Text = buffer;
		delete buffer;
		}
public: static void GetRATextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = Form1::OSUrobForm->RATextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetDECTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->DECTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetDECTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = Form1::OSUrobForm->DECTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetAltTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->AltTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetAzTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->AzTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetUTTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->UTTextBox->Text = buffer;
		delete buffer;
		}

public: static void SetLocalTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->LocalTextBox->Text = buffer;
		delete buffer;
		}

public: static void SetLSTTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->LSTTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetLSTTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = Form1::OSUrobForm->LSTTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetJDTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->JDTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetDomeGotoAzTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = Form1::OSUrobForm->DomeGotoAzTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetFWTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::OSUrobForm->FWPositionTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFWTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = Form1::OSUrobForm->FWPositionTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}


public: static void StatusPrint(char *Message) {

		String ^buffer;

		buffer = gcnew String(Message);
		if ((strstr(Message,"Warning") != NULL) ||
			(strstr(Message,"WARNING") != NULL))
			Form1::OSUrobForm->MainStatusBox->ForeColor = System::Drawing::Color::Red;
		else
			Form1::OSUrobForm->MainStatusBox->ForeColor = System::Drawing::Color::Black;
		Form1::OSUrobForm->MainStatusBox->AppendText(buffer);
		Form1::OSUrobForm->MainStatusBox->ScrollToCaret();
		delete buffer;
		 }


private: System::Void LinkToScopeMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 float dummy;
			 bool success;

			 DontUpdateNow(true);
			 success = DoScopeFunction(SCOPE_INIT, &dummy, &dummy, true);
			 DontUpdateNow(false);
			 if (! success) {
				 Form1::StatusPrint("*** Warning - Failed in linking to scope.\n");
			 }
			 return;
		 }
private: System::Void ParkScopeMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 float dummy;
			 int answer;
			 bool success;

			 answer = MessageBox("Sure you want to park scope", YESNO);
			 if (answer == YES) {
				 DontUpdateNow(true);
				 success = DoScopeFunction(SCOPE_PARK, &dummy, &dummy, true);
				 DontUpdateNow(false);
				 if (! success) {
					 Form1::StatusPrint("*** Warning - Failed in parking scope.\n");
				 }
			 }
			 return;
		 }
private: System::Void UnlinkFromScopeMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 float dummy;
			 bool success;

			 DontUpdateNow(true);
			 success = DoScopeFunction(SCOPE_CLOSE, &dummy, &dummy, true);
			 DontUpdateNow(false);
			 if (! success) {
				 Form1::StatusPrint("*** Warning - Failed in closing link to scope.\n");
			 }
			 return;
		 }
private: System::Void focusToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

//			 if (! AdjustFocusDialogExists) {
//				 gcnew AdjustFocusDialog();
//			 }
//			 AdjustFocusDialog::FormPtr->ShowDialog();
		 }
private: System::Void calibrateScopeSlewingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (! CalibrateSlewingDialogExists)
				 gcnew CalibrateSlewingDialog();
			 CalibrateSlewingDialog::FormPtr->ShowTheDialog();
		 }
private: System::Void SpectrographWavelengthsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (! SpectrographWavelengthsDialogExists) {
				 gcnew SpectrographWavelengthsDialog();
			 }
			 SpectrographWavelengthsDialog::FormPtr->ShowTheDialog();
		 }
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 char message[160];

			 sprintf_s(message, sizeof(message), "This is the OSU-Lima Student Observatory Master Program, Version %3.1f",
				 RELEASE_VERSION);
			 MessageBox(message, OKAY);
		 }
private: System::Void turnOnOffGlobalDebuggingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (GlobalDebug) {
				 Form1::StatusPrint("*** Info - Turning off debug messages.\n");
				 GlobalDebug = false;
			 } else {
				 Form1::StatusPrint("*** Info - Turning on debug messages.\n");
				 GlobalDebug = true;
			 }
			 return;
		 }
private: System::Void initGPSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 float dummy;
			 int answer, itries;
			 bool success;

			 answer = MessageBox("Sure you want to initialize GPS on Scope", YESNO);
			 if (answer == YES) {
				 itries = 0;
				 DontUpdateNow(true);
				 do {
					success = DoScopeFunction(SCOPE_GPS_INIT, &dummy, &dummy, true);
					if (success) break;
					itries++;
					usleep(1000000, true);
				 } while (itries < 5);
				 DontUpdateNow(false);
				 if (itries >= 5) {
					 Form1::StatusPrint("*** Warning - Failed in initializing GPS on scope.\n");
				 }
			 }
			 return;
		 }


private: System::Void FocuserConfigureToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			// Show dialog to allow user to change Focuser parameters

		}


private: System::Void FocuserAdjustToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			// Show dialog to allow user to adjust the focus of the telescope
			
			if (!AdjustTelescopeFocusDialogExists) {
				gcnew AdjustTelescopeFocusDialog();
				AdjustTelescopeFocusDialogExists = true;
			}
			
			AdjustTelescopeFocusDialog::FormPtr->Show();
		}
};
}

