#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO::Ports;
using namespace System::Runtime::InteropServices;

#include <time.h>
#include <string.h>
#include "TLaser_UTM_30LX/TLaser_UTM_30LX.h"

#define _USE_MATH_DEFINES
#include <math.h>

//#include "../../Core/DataStruct/HdwStruct/HdwStruct.h"

namespace SKS_VC2013{

	/// <summary>
	/// Summary for TLaserForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class TLaserForm : public System::Windows::Forms::Form
	{
	public:
		TLaserForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//RS232_Laser_Form = gcnew TRS232_Laser_Form;
			Laser1_30LX = new TLaser_HOKUYO(def_30LX_StartStep, def_30LX_EndStep, def_30LX_Resolution, def_30LX_StartAngle, true);
			Laser2_04LX = new TLaser_HOKUYO(def_04LX_StartStep, def_04LX_EndStep, def_04LX_Resolution, def_04LX_StartAngle, true);
			Cmd_30LX = new tsLaserCommand();
			Cmd_04LX = new tsLaserCommand();

			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TLaserForm()
		{
			if (components)
			{
				delete components;
			}
			delete Laser1_30LX;
		}

	private: System::Windows::Forms::Panel^  panelMain;
	private: System::Windows::Forms::GroupBox^  gbxSetup;
	private: System::Windows::Forms::NumericUpDown^  updownNumOfScans;
	private: System::Windows::Forms::CheckBox^  checkContinuous;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  cboxInterval;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::HScrollBar^  hsbarCluster;
	private: System::Windows::Forms::HScrollBar^  hsbarEndStep;
	private: System::Windows::Forms::HScrollBar^  hsbarStartStep;
	private: System::Windows::Forms::TextBox^  txtCluster;
	private: System::Windows::Forms::TextBox^  txtEndStep;
	private: System::Windows::Forms::TextBox^  txtStartStep;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cboxCmdType;
	private: System::Windows::Forms::ComboBox^  cboxLaserList;
	private: System::Windows::Forms::GroupBox^  gbxRS232;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  cbox04LXBaudRate;
	private: System::Windows::Forms::ComboBox^  cbox04LXPortList;
	private: System::Windows::Forms::Label^  lab04LXConnectState;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ComboBox^  cbox30LXBaudRate;
	private: System::Windows::Forms::ComboBox^  cbox30LXPortList;
	private: System::Windows::Forms::Button^  btnSearch;
	private: System::Windows::Forms::ProgressBar^  progressbarSearch;
	private: System::Windows::Forms::Label^  lab30LXConnectState;

	private: System::IO::Ports::SerialPort^  serialport30LX;
	private: System::IO::Ports::SerialPort^  serialport04LX;
	private: System::Windows::Forms::Label^  labLength;
	private: System::Windows::Forms::Label^  labTmpLength;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::CheckBox^  checkSendData;
	private: System::Windows::Forms::CheckBox^  checkReceiveData;

	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::ListBox^  lbox_Info;
	private: System::Windows::Forms::Label^  labScale;
	private: System::Windows::Forms::Label^  lab_DisR2;
	private: System::Windows::Forms::Label^  lab_DisL1;
	private: System::Windows::Forms::Label^  lab_DisL2;
	private: System::Windows::Forms::Label^  lab_DisR1;
	private: System::Windows::Forms::TrackBar^  trackbarScale;
	private: System::Windows::Forms::CheckBox^  checkShow04LX;
	private: System::Windows::Forms::CheckBox^  checkShow30LX;
	private: System::Windows::Forms::PictureBox^  pboxLaserInfo;
	private: System::Windows::Forms::Button^  btnSetup;
	private: System::Windows::Forms::Button^  btnLoad;
	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::Button^  btnStop;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::CheckBox^  check30LX;
	private: System::Windows::Forms::CheckBox^  check04LX;
	private: System::Windows::Forms::CheckBox^  checkAllLaser;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  lab04LX_State;
	private: System::Windows::Forms::Label^  lab30LX_State;
	private: System::Windows::Forms::Label^  lab30LX_Info;
	private: System::Windows::Forms::Label^  lab04LX_Info;
	private: System::Windows::Forms::Button^  btnLoadLaserCmd;

	private: System::Windows::Forms::Button^  btnSaveLaserCmd;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TLaserForm::typeid));
			this->panelMain = (gcnew System::Windows::Forms::Panel());
			this->gbxRS232 = (gcnew System::Windows::Forms::GroupBox());
			this->labLength = (gcnew System::Windows::Forms::Label());
			this->labTmpLength = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->checkSendData = (gcnew System::Windows::Forms::CheckBox());
			this->checkReceiveData = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cbox04LXBaudRate = (gcnew System::Windows::Forms::ComboBox());
			this->cbox04LXPortList = (gcnew System::Windows::Forms::ComboBox());
			this->lab04LXConnectState = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cbox30LXBaudRate = (gcnew System::Windows::Forms::ComboBox());
			this->cbox30LXPortList = (gcnew System::Windows::Forms::ComboBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->progressbarSearch = (gcnew System::Windows::Forms::ProgressBar());
			this->lab30LXConnectState = (gcnew System::Windows::Forms::Label());
			this->gbxSetup = (gcnew System::Windows::Forms::GroupBox());
			this->btnLoadLaserCmd = (gcnew System::Windows::Forms::Button());
			this->btnSaveLaserCmd = (gcnew System::Windows::Forms::Button());
			this->lab04LX_Info = (gcnew System::Windows::Forms::Label());
			this->lab30LX_Info = (gcnew System::Windows::Forms::Label());
			this->updownNumOfScans = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkContinuous = (gcnew System::Windows::Forms::CheckBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cboxInterval = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->hsbarCluster = (gcnew System::Windows::Forms::HScrollBar());
			this->hsbarEndStep = (gcnew System::Windows::Forms::HScrollBar());
			this->hsbarStartStep = (gcnew System::Windows::Forms::HScrollBar());
			this->txtCluster = (gcnew System::Windows::Forms::TextBox());
			this->txtEndStep = (gcnew System::Windows::Forms::TextBox());
			this->txtStartStep = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cboxCmdType = (gcnew System::Windows::Forms::ComboBox());
			this->cboxLaserList = (gcnew System::Windows::Forms::ComboBox());
			this->serialport30LX = (gcnew System::IO::Ports::SerialPort(this->components));
			this->serialport04LX = (gcnew System::IO::Ports::SerialPort(this->components));
			this->lbox_Info = (gcnew System::Windows::Forms::ListBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->labScale = (gcnew System::Windows::Forms::Label());
			this->lab_DisR2 = (gcnew System::Windows::Forms::Label());
			this->lab_DisL1 = (gcnew System::Windows::Forms::Label());
			this->lab_DisL2 = (gcnew System::Windows::Forms::Label());
			this->lab_DisR1 = (gcnew System::Windows::Forms::Label());
			this->trackbarScale = (gcnew System::Windows::Forms::TrackBar());
			this->checkShow04LX = (gcnew System::Windows::Forms::CheckBox());
			this->checkShow30LX = (gcnew System::Windows::Forms::CheckBox());
			this->pboxLaserInfo = (gcnew System::Windows::Forms::PictureBox());
			this->btnSetup = (gcnew System::Windows::Forms::Button());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->check30LX = (gcnew System::Windows::Forms::CheckBox());
			this->check04LX = (gcnew System::Windows::Forms::CheckBox());
			this->checkAllLaser = (gcnew System::Windows::Forms::CheckBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lab04LX_State = (gcnew System::Windows::Forms::Label());
			this->lab30LX_State = (gcnew System::Windows::Forms::Label());
			this->panelMain->SuspendLayout();
			this->gbxRS232->SuspendLayout();
			this->gbxSetup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->updownNumOfScans))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackbarScale))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pboxLaserInfo))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelMain
			// 
			this->panelMain->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelMain->Controls->Add(this->gbxRS232);
			this->panelMain->Controls->Add(this->gbxSetup);
			this->panelMain->Dock = System::Windows::Forms::DockStyle::Right;
			this->panelMain->Location = System::Drawing::Point(630, 0);
			this->panelMain->Name = L"panelMain";
			this->panelMain->Size = System::Drawing::Size(243, 669);
			this->panelMain->TabIndex = 12;
			// 
			// gbxRS232
			// 
			this->gbxRS232->Controls->Add(this->labLength);
			this->gbxRS232->Controls->Add(this->labTmpLength);
			this->gbxRS232->Controls->Add(this->label9);
			this->gbxRS232->Controls->Add(this->checkSendData);
			this->gbxRS232->Controls->Add(this->checkReceiveData);
			this->gbxRS232->Controls->Add(this->label7);
			this->gbxRS232->Controls->Add(this->cbox04LXBaudRate);
			this->gbxRS232->Controls->Add(this->cbox04LXPortList);
			this->gbxRS232->Controls->Add(this->lab04LXConnectState);
			this->gbxRS232->Controls->Add(this->label8);
			this->gbxRS232->Controls->Add(this->cbox30LXBaudRate);
			this->gbxRS232->Controls->Add(this->cbox30LXPortList);
			this->gbxRS232->Controls->Add(this->btnSearch);
			this->gbxRS232->Controls->Add(this->progressbarSearch);
			this->gbxRS232->Controls->Add(this->lab30LXConnectState);
			this->gbxRS232->Dock = System::Windows::Forms::DockStyle::Top;
			this->gbxRS232->Location = System::Drawing::Point(0, 285);
			this->gbxRS232->Name = L"gbxRS232";
			this->gbxRS232->Size = System::Drawing::Size(241, 225);
			this->gbxRS232->TabIndex = 13;
			this->gbxRS232->TabStop = false;
			this->gbxRS232->Text = L"RS232 Laser";
			// 
			// labLength
			// 
			this->labLength->AutoSize = true;
			this->labLength->Location = System::Drawing::Point(99, 194);
			this->labLength->Name = L"labLength";
			this->labLength->Size = System::Drawing::Size(11, 12);
			this->labLength->TabIndex = 24;
			this->labLength->Text = L"0";
			// 
			// labTmpLength
			// 
			this->labTmpLength->AutoSize = true;
			this->labTmpLength->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->labTmpLength->Location = System::Drawing::Point(11, 194);
			this->labTmpLength->Name = L"labTmpLength";
			this->labTmpLength->Size = System::Drawing::Size(77, 12);
			this->labTmpLength->TabIndex = 23;
			this->labTmpLength->Text = L"Data Length:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label9->Location = System::Drawing::Point(11, 172);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(72, 12);
			this->label9->TabIndex = 22;
			this->label9->Text = L"Information";
			// 
			// checkSendData
			// 
			this->checkSendData->AutoSize = true;
			this->checkSendData->Location = System::Drawing::Point(101, 171);
			this->checkSendData->Name = L"checkSendData";
			this->checkSendData->Size = System::Drawing::Size(47, 16);
			this->checkSendData->TabIndex = 21;
			this->checkSendData->Text = L"Send";
			this->checkSendData->UseVisualStyleBackColor = true;
			// 
			// checkReceiveData
			// 
			this->checkReceiveData->AutoSize = true;
			this->checkReceiveData->Location = System::Drawing::Point(154, 171);
			this->checkReceiveData->Name = L"checkReceiveData";
			this->checkReceiveData->Size = System::Drawing::Size(61, 16);
			this->checkReceiveData->TabIndex = 20;
			this->checkReceiveData->Text = L"Receive";
			this->checkReceiveData->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(65, 143);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 12);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Baud Rate:";
			// 
			// cbox04LXBaudRate
			// 
			this->cbox04LXBaudRate->FormattingEnabled = true;
			this->cbox04LXBaudRate->Items->AddRange(gcnew cli::array< System::Object^  >(14) {L"600", L"1200", L"2400", L"4800", L"9600", 
				L"14400", L"19200", L"28800", L"38400", L"56000", L"57600", L"115200", L"128000", L"256000"});
			this->cbox04LXBaudRate->Location = System::Drawing::Point(144, 138);
			this->cbox04LXBaudRate->Name = L"cbox04LXBaudRate";
			this->cbox04LXBaudRate->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->cbox04LXBaudRate->Size = System::Drawing::Size(80, 20);
			this->cbox04LXBaudRate->TabIndex = 18;
			this->cbox04LXBaudRate->Text = L"115200";
			// 
			// cbox04LXPortList
			// 
			this->cbox04LXPortList->FormattingEnabled = true;
			this->cbox04LXPortList->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"未啟用"});
			this->cbox04LXPortList->Location = System::Drawing::Point(144, 112);
			this->cbox04LXPortList->Name = L"cbox04LXPortList";
			this->cbox04LXPortList->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->cbox04LXPortList->Size = System::Drawing::Size(80, 20);
			this->cbox04LXPortList->TabIndex = 17;
			this->cbox04LXPortList->Text = L"Un-Enable";
			this->cbox04LXPortList->SelectedIndexChanged += gcnew System::EventHandler(this, &TLaserForm::cbox04LXPortList_SelectedIndexChanged);
			// 
			// lab04LXConnectState
			// 
			this->lab04LXConnectState->BackColor = System::Drawing::Color::Red;
			this->lab04LXConnectState->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lab04LXConnectState->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lab04LXConnectState->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lab04LXConnectState->Location = System::Drawing::Point(10, 112);
			this->lab04LXConnectState->Name = L"lab04LXConnectState";
			this->lab04LXConnectState->Size = System::Drawing::Size(122, 20);
			this->lab04LXConnectState->TabIndex = 16;
			this->lab04LXConnectState->Text = L"04LX Disconnect";
			this->lab04LXConnectState->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label8->Location = System::Drawing::Point(65, 90);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(67, 12);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Baud Rate:";
			// 
			// cbox30LXBaudRate
			// 
			this->cbox30LXBaudRate->FormattingEnabled = true;
			this->cbox30LXBaudRate->Items->AddRange(gcnew cli::array< System::Object^  >(14) {L"600", L"1200", L"2400", L"4800", L"9600", 
				L"14400", L"19200", L"28800", L"38400", L"56000", L"57600", L"115200", L"128000", L"256000"});
			this->cbox30LXBaudRate->Location = System::Drawing::Point(144, 85);
			this->cbox30LXBaudRate->Name = L"cbox30LXBaudRate";
			this->cbox30LXBaudRate->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->cbox30LXBaudRate->Size = System::Drawing::Size(80, 20);
			this->cbox30LXBaudRate->TabIndex = 14;
			this->cbox30LXBaudRate->Text = L"115200";
			// 
			// cbox30LXPortList
			// 
			this->cbox30LXPortList->FormattingEnabled = true;
			this->cbox30LXPortList->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"未啟用"});
			this->cbox30LXPortList->Location = System::Drawing::Point(144, 59);
			this->cbox30LXPortList->Name = L"cbox30LXPortList";
			this->cbox30LXPortList->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->cbox30LXPortList->Size = System::Drawing::Size(80, 20);
			this->cbox30LXPortList->TabIndex = 13;
			this->cbox30LXPortList->Text = L"Un-Enable";
			this->cbox30LXPortList->SelectedIndexChanged += gcnew System::EventHandler(this, &TLaserForm::cbox30LXPortList_SelectedIndexChanged);
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(10, 21);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(80, 25);
			this->btnSearch->TabIndex = 12;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &TLaserForm::btnSearch_Click);
			// 
			// progressbarSearch
			// 
			this->progressbarSearch->Location = System::Drawing::Point(98, 22);
			this->progressbarSearch->Name = L"progressbarSearch";
			this->progressbarSearch->Size = System::Drawing::Size(126, 25);
			this->progressbarSearch->TabIndex = 11;
			// 
			// lab30LXConnectState
			// 
			this->lab30LXConnectState->BackColor = System::Drawing::Color::Red;
			this->lab30LXConnectState->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lab30LXConnectState->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lab30LXConnectState->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lab30LXConnectState->Location = System::Drawing::Point(10, 59);
			this->lab30LXConnectState->Name = L"lab30LXConnectState";
			this->lab30LXConnectState->Size = System::Drawing::Size(122, 20);
			this->lab30LXConnectState->TabIndex = 10;
			this->lab30LXConnectState->Text = L"30LX Disconnect";
			this->lab30LXConnectState->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// gbxSetup
			// 
			this->gbxSetup->Controls->Add(this->btnLoadLaserCmd);
			this->gbxSetup->Controls->Add(this->btnSaveLaserCmd);
			this->gbxSetup->Controls->Add(this->lab04LX_Info);
			this->gbxSetup->Controls->Add(this->lab30LX_Info);
			this->gbxSetup->Controls->Add(this->updownNumOfScans);
			this->gbxSetup->Controls->Add(this->checkContinuous);
			this->gbxSetup->Controls->Add(this->label6);
			this->gbxSetup->Controls->Add(this->cboxInterval);
			this->gbxSetup->Controls->Add(this->label5);
			this->gbxSetup->Controls->Add(this->hsbarCluster);
			this->gbxSetup->Controls->Add(this->hsbarEndStep);
			this->gbxSetup->Controls->Add(this->hsbarStartStep);
			this->gbxSetup->Controls->Add(this->txtCluster);
			this->gbxSetup->Controls->Add(this->txtEndStep);
			this->gbxSetup->Controls->Add(this->txtStartStep);
			this->gbxSetup->Controls->Add(this->label4);
			this->gbxSetup->Controls->Add(this->label3);
			this->gbxSetup->Controls->Add(this->label2);
			this->gbxSetup->Controls->Add(this->label1);
			this->gbxSetup->Controls->Add(this->cboxCmdType);
			this->gbxSetup->Controls->Add(this->cboxLaserList);
			this->gbxSetup->Dock = System::Windows::Forms::DockStyle::Top;
			this->gbxSetup->Location = System::Drawing::Point(0, 0);
			this->gbxSetup->Name = L"gbxSetup";
			this->gbxSetup->Size = System::Drawing::Size(241, 285);
			this->gbxSetup->TabIndex = 14;
			this->gbxSetup->TabStop = false;
			this->gbxSetup->Text = L"Setup";
			// 
			// btnLoadLaserCmd
			// 
			this->btnLoadLaserCmd->Location = System::Drawing::Point(126, 244);
			this->btnLoadLaserCmd->Name = L"btnLoadLaserCmd";
			this->btnLoadLaserCmd->Size = System::Drawing::Size(55, 26);
			this->btnLoadLaserCmd->TabIndex = 23;
			this->btnLoadLaserCmd->Text = L"Load";
			this->btnLoadLaserCmd->UseVisualStyleBackColor = true;
			// 
			// btnSaveLaserCmd
			// 
			this->btnSaveLaserCmd->Location = System::Drawing::Point(61, 244);
			this->btnSaveLaserCmd->Name = L"btnSaveLaserCmd";
			this->btnSaveLaserCmd->Size = System::Drawing::Size(59, 26);
			this->btnSaveLaserCmd->TabIndex = 22;
			this->btnSaveLaserCmd->Text = L"Save";
			this->btnSaveLaserCmd->UseVisualStyleBackColor = true;
			// 
			// lab04LX_Info
			// 
			this->lab04LX_Info->AutoSize = true;
			this->lab04LX_Info->Location = System::Drawing::Point(13, 223);
			this->lab04LX_Info->Name = L"lab04LX_Info";
			this->lab04LX_Info->Size = System::Drawing::Size(168, 12);
			this->lab04LX_Info->TabIndex = 21;
			this->lab04LX_Info->Text = L"04LX: [122.4,-122.4] [0.36] [725]";
			// 
			// lab30LX_Info
			// 
			this->lab30LX_Info->AutoSize = true;
			this->lab30LX_Info->Location = System::Drawing::Point(13, 204);
			this->lab30LX_Info->Name = L"lab30LX_Info";
			this->lab30LX_Info->Size = System::Drawing::Size(156, 12);
			this->lab30LX_Info->TabIndex = 20;
			this->lab30LX_Info->Text = L"30LX: [135,-135] [0.25] [1081]";
			// 
			// updownNumOfScans
			// 
			this->updownNumOfScans->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->updownNumOfScans->Location = System::Drawing::Point(177, 171);
			this->updownNumOfScans->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {99, 0, 0, 0});
			this->updownNumOfScans->Name = L"updownNumOfScans";
			this->updownNumOfScans->Size = System::Drawing::Size(42, 23);
			this->updownNumOfScans->TabIndex = 17;
			this->updownNumOfScans->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->updownNumOfScans->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->updownNumOfScans->ValueChanged += gcnew System::EventHandler(this, &TLaserForm::updownNumOfScans_ValueChanged);
			// 
			// checkContinuous
			// 
			this->checkContinuous->AutoSize = true;
			this->checkContinuous->Checked = true;
			this->checkContinuous->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkContinuous->Location = System::Drawing::Point(93, 174);
			this->checkContinuous->Name = L"checkContinuous";
			this->checkContinuous->Size = System::Drawing::Size(78, 16);
			this->checkContinuous->TabIndex = 16;
			this->checkContinuous->Text = L"Continuous";
			this->checkContinuous->UseVisualStyleBackColor = true;
			this->checkContinuous->Click += gcnew System::EventHandler(this, &TLaserForm::checkContinuous_Click);
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(11, 175);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(76, 12);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Num of Scans:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cboxInterval
			// 
			this->cboxInterval->FormattingEnabled = true;
			this->cboxInterval->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
				L"8", L"9"});
			this->cboxInterval->Location = System::Drawing::Point(62, 143);
			this->cboxInterval->Name = L"cboxInterval";
			this->cboxInterval->Size = System::Drawing::Size(41, 20);
			this->cboxInterval->TabIndex = 14;
			this->cboxInterval->Text = L"3";
			this->cboxInterval->SelectedIndexChanged += gcnew System::EventHandler(this, &TLaserForm::cboxInterval_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(11, 147);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(45, 12);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Interval:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// hsbarCluster
			// 
			this->hsbarCluster->LargeChange = 1;
			this->hsbarCluster->Location = System::Drawing::Point(106, 113);
			this->hsbarCluster->Maximum = 99;
			this->hsbarCluster->Minimum = 1;
			this->hsbarCluster->Name = L"hsbarCluster";
			this->hsbarCluster->Size = System::Drawing::Size(126, 17);
			this->hsbarCluster->TabIndex = 11;
			this->hsbarCluster->Value = 12;
			this->hsbarCluster->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &TLaserForm::AdjustLaserCommand);
			// 
			// hsbarEndStep
			// 
			this->hsbarEndStep->LargeChange = 1;
			this->hsbarEndStep->Location = System::Drawing::Point(106, 85);
			this->hsbarEndStep->Maximum = 1080;
			this->hsbarEndStep->Name = L"hsbarEndStep";
			this->hsbarEndStep->Size = System::Drawing::Size(126, 17);
			this->hsbarEndStep->TabIndex = 10;
			this->hsbarEndStep->Value = 1080;
			this->hsbarEndStep->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &TLaserForm::AdjustLaserCommand);
			// 
			// hsbarStartStep
			// 
			this->hsbarStartStep->LargeChange = 1;
			this->hsbarStartStep->Location = System::Drawing::Point(106, 55);
			this->hsbarStartStep->Maximum = 1080;
			this->hsbarStartStep->Name = L"hsbarStartStep";
			this->hsbarStartStep->Size = System::Drawing::Size(126, 17);
			this->hsbarStartStep->TabIndex = 9;
			this->hsbarStartStep->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &TLaserForm::AdjustLaserCommand);
			// 
			// txtCluster
			// 
			this->txtCluster->Location = System::Drawing::Point(62, 111);
			this->txtCluster->Name = L"txtCluster";
			this->txtCluster->Size = System::Drawing::Size(41, 22);
			this->txtCluster->TabIndex = 8;
			this->txtCluster->Text = L"3";
			// 
			// txtEndStep
			// 
			this->txtEndStep->Location = System::Drawing::Point(62, 83);
			this->txtEndStep->Name = L"txtEndStep";
			this->txtEndStep->Size = System::Drawing::Size(41, 22);
			this->txtEndStep->TabIndex = 7;
			this->txtEndStep->Text = L"270";
			// 
			// txtStartStep
			// 
			this->txtStartStep->Location = System::Drawing::Point(62, 55);
			this->txtStartStep->Name = L"txtStartStep";
			this->txtStartStep->Size = System::Drawing::Size(41, 22);
			this->txtStartStep->TabIndex = 6;
			this->txtStartStep->Text = L"0";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(11, 118);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 12);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Cluster:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(11, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 12);
			this->label3->TabIndex = 4;
			this->label3->Text = L"End:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(11, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Start:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(130, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Type:";
			// 
			// cboxCmdType
			// 
			this->cboxCmdType->FormattingEnabled = true;
			this->cboxCmdType->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Angle", L"Step"});
			this->cboxCmdType->Location = System::Drawing::Point(169, 21);
			this->cboxCmdType->Name = L"cboxCmdType";
			this->cboxCmdType->Size = System::Drawing::Size(63, 20);
			this->cboxCmdType->TabIndex = 1;
			this->cboxCmdType->Text = L"Angle";
			this->cboxCmdType->SelectedIndexChanged += gcnew System::EventHandler(this, &TLaserForm::cboxCmdType_SelectedIndexChanged);
			// 
			// cboxLaserList
			// 
			this->cboxLaserList->FormattingEnabled = true;
			this->cboxLaserList->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"UTM_30LX", L"URG_04LX"});
			this->cboxLaserList->Location = System::Drawing::Point(18, 21);
			this->cboxLaserList->Name = L"cboxLaserList";
			this->cboxLaserList->Size = System::Drawing::Size(85, 20);
			this->cboxLaserList->TabIndex = 0;
			this->cboxLaserList->Text = L"UTM_30LX";
			this->cboxLaserList->SelectedIndexChanged += gcnew System::EventHandler(this, &TLaserForm::cboxLaserList_SelectedIndexChanged);
			// 
			// serialport30LX
			// 
			this->serialport30LX->ErrorReceived += gcnew System::IO::Ports::SerialErrorReceivedEventHandler(this, &TLaserForm::serialport30LX_ErrorReceived);
			this->serialport30LX->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &TLaserForm::serialport30LX_DataReceived);
			// 
			// serialport04LX
			// 
			this->serialport04LX->ErrorReceived += gcnew System::IO::Ports::SerialErrorReceivedEventHandler(this, &TLaserForm::serialport04LX_ErrorReceived);
			this->serialport04LX->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &TLaserForm::serialport04LX_DataReceived);
			// 
			// lbox_Info
			// 
			this->lbox_Info->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lbox_Info->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lbox_Info->FormattingEnabled = true;
			this->lbox_Info->HorizontalScrollbar = true;
			this->lbox_Info->ItemHeight = 12;
			this->lbox_Info->Location = System::Drawing::Point(0, 0);
			this->lbox_Info->Name = L"lbox_Info";
			this->lbox_Info->ScrollAlwaysVisible = true;
			this->lbox_Info->Size = System::Drawing::Size(630, 669);
			this->lbox_Info->TabIndex = 26;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->labScale);
			this->panel3->Controls->Add(this->lab_DisR2);
			this->panel3->Controls->Add(this->lab_DisL1);
			this->panel3->Controls->Add(this->lab_DisL2);
			this->panel3->Controls->Add(this->lab_DisR1);
			this->panel3->Controls->Add(this->trackbarScale);
			this->panel3->Controls->Add(this->checkShow04LX);
			this->panel3->Controls->Add(this->checkShow30LX);
			this->panel3->Controls->Add(this->pboxLaserInfo);
			this->panel3->Controls->Add(this->btnSetup);
			this->panel3->Controls->Add(this->btnLoad);
			this->panel3->Controls->Add(this->btnReset);
			this->panel3->Controls->Add(this->btnStop);
			this->panel3->Controls->Add(this->btnStart);
			this->panel3->Controls->Add(this->panel1);
			this->panel3->Controls->Add(this->panel2);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(630, 557);
			this->panel3->TabIndex = 27;
			// 
			// labScale
			// 
			this->labScale->AutoSize = true;
			this->labScale->Location = System::Drawing::Point(128, 522);
			this->labScale->Name = L"labScale";
			this->labScale->Size = System::Drawing::Size(41, 12);
			this->labScale->TabIndex = 26;
			this->labScale->Text = L"Scale: 1";
			// 
			// lab_DisR2
			// 
			this->lab_DisR2->AutoSize = true;
			this->lab_DisR2->BackColor = System::Drawing::SystemColors::Window;
			this->lab_DisR2->Location = System::Drawing::Point(577, 244);
			this->lab_DisR2->Name = L"lab_DisR2";
			this->lab_DisR2->Size = System::Drawing::Size(17, 12);
			this->lab_DisR2->TabIndex = 24;
			this->lab_DisR2->Text = L"d2";
			// 
			// lab_DisL1
			// 
			this->lab_DisL1->AutoSize = true;
			this->lab_DisL1->BackColor = System::Drawing::SystemColors::Window;
			this->lab_DisL1->Location = System::Drawing::Point(377, 119);
			this->lab_DisL1->Name = L"lab_DisL1";
			this->lab_DisL1->Size = System::Drawing::Size(17, 12);
			this->lab_DisL1->TabIndex = 25;
			this->lab_DisL1->Text = L"d1";
			// 
			// lab_DisL2
			// 
			this->lab_DisL2->AutoSize = true;
			this->lab_DisL2->BackColor = System::Drawing::SystemColors::Window;
			this->lab_DisL2->Location = System::Drawing::Point(376, 43);
			this->lab_DisL2->Name = L"lab_DisL2";
			this->lab_DisL2->Size = System::Drawing::Size(17, 12);
			this->lab_DisL2->TabIndex = 22;
			this->lab_DisL2->Text = L"d2";
			// 
			// lab_DisR1
			// 
			this->lab_DisR1->AutoSize = true;
			this->lab_DisR1->BackColor = System::Drawing::SystemColors::Window;
			this->lab_DisR1->Location = System::Drawing::Point(504, 244);
			this->lab_DisR1->Name = L"lab_DisR1";
			this->lab_DisR1->Size = System::Drawing::Size(17, 12);
			this->lab_DisR1->TabIndex = 23;
			this->lab_DisR1->Text = L"d1";
			// 
			// trackbarScale
			// 
			this->trackbarScale->AutoSize = false;
			this->trackbarScale->LargeChange = 1;
			this->trackbarScale->Location = System::Drawing::Point(173, 514);
			this->trackbarScale->Maximum = 100;
			this->trackbarScale->Minimum = 1;
			this->trackbarScale->Name = L"trackbarScale";
			this->trackbarScale->Size = System::Drawing::Size(277, 27);
			this->trackbarScale->TabIndex = 19;
			this->trackbarScale->TickFrequency = 5;
			this->trackbarScale->Value = 10;
			this->trackbarScale->ValueChanged += gcnew System::EventHandler(this, &TLaserForm::trackbarScale_ValueChanged);
			// 
			// checkShow04LX
			// 
			this->checkShow04LX->AutoSize = true;
			this->checkShow04LX->Location = System::Drawing::Point(544, 515);
			this->checkShow04LX->Name = L"checkShow04LX";
			this->checkShow04LX->Size = System::Drawing::Size(80, 16);
			this->checkShow04LX->TabIndex = 21;
			this->checkShow04LX->Text = L"Show 04LX";
			this->checkShow04LX->UseVisualStyleBackColor = true;
			// 
			// checkShow30LX
			// 
			this->checkShow30LX->AutoSize = true;
			this->checkShow30LX->Location = System::Drawing::Point(458, 515);
			this->checkShow30LX->Name = L"checkShow30LX";
			this->checkShow30LX->Size = System::Drawing::Size(80, 16);
			this->checkShow30LX->TabIndex = 20;
			this->checkShow30LX->Text = L"Show 30LX";
			this->checkShow30LX->UseVisualStyleBackColor = true;
			// 
			// pboxLaserInfo
			// 
			this->pboxLaserInfo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pboxLaserInfo.Image")));
			this->pboxLaserInfo->Location = System::Drawing::Point(124, 11);
			this->pboxLaserInfo->Name = L"pboxLaserInfo";
			this->pboxLaserInfo->Size = System::Drawing::Size(500, 500);
			this->pboxLaserInfo->TabIndex = 18;
			this->pboxLaserInfo->TabStop = false;
			// 
			// btnSetup
			// 
			this->btnSetup->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSetup->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnSetup->Location = System::Drawing::Point(3, 413);
			this->btnSetup->Name = L"btnSetup";
			this->btnSetup->Size = System::Drawing::Size(115, 46);
			this->btnSetup->TabIndex = 14;
			this->btnSetup->Text = L"Setup";
			this->btnSetup->UseVisualStyleBackColor = true;
			// 
			// btnLoad
			// 
			this->btnLoad->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnLoad->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnLoad->Location = System::Drawing::Point(3, 465);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(115, 44);
			this->btnLoad->TabIndex = 13;
			this->btnLoad->Text = L"Load";
			this->btnLoad->UseVisualStyleBackColor = true;
			// 
			// btnReset
			// 
			this->btnReset->BackColor = System::Drawing::SystemColors::Control;
			this->btnReset->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnReset->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnReset->ForeColor = System::Drawing::Color::Blue;
			this->btnReset->Location = System::Drawing::Point(3, 280);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(115, 57);
			this->btnReset->TabIndex = 12;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = false;
			// 
			// btnStop
			// 
			this->btnStop->BackColor = System::Drawing::SystemColors::Control;
			this->btnStop->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStop->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnStop->ForeColor = System::Drawing::Color::Red;
			this->btnStop->Location = System::Drawing::Point(3, 220);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(115, 57);
			this->btnStop->TabIndex = 11;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = false;
			this->btnStop->Click += gcnew System::EventHandler(this, &TLaserForm::btnStop_Click);
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::SystemColors::Control;
			this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnStart->ForeColor = System::Drawing::Color::Lime;
			this->btnStart->Location = System::Drawing::Point(3, 160);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(115, 57);
			this->btnStart->TabIndex = 10;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &TLaserForm::btnStart_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->check30LX);
			this->panel1->Controls->Add(this->check04LX);
			this->panel1->Controls->Add(this->checkAllLaser);
			this->panel1->Location = System::Drawing::Point(3, 84);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(115, 70);
			this->panel1->TabIndex = 8;
			// 
			// check30LX
			// 
			this->check30LX->AutoSize = true;
			this->check30LX->Checked = true;
			this->check30LX->CheckState = System::Windows::Forms::CheckState::Checked;
			this->check30LX->Location = System::Drawing::Point(8, 29);
			this->check30LX->Name = L"check30LX";
			this->check30LX->Size = System::Drawing::Size(82, 16);
			this->check30LX->TabIndex = 5;
			this->check30LX->Text = L"UTM_30LX";
			this->check30LX->UseVisualStyleBackColor = true;
			this->check30LX->Click += gcnew System::EventHandler(this, &TLaserForm::check30LX_Click);
			// 
			// check04LX
			// 
			this->check04LX->AutoSize = true;
			this->check04LX->Checked = true;
			this->check04LX->CheckState = System::Windows::Forms::CheckState::Checked;
			this->check04LX->Location = System::Drawing::Point(8, 48);
			this->check04LX->Name = L"check04LX";
			this->check04LX->Size = System::Drawing::Size(81, 16);
			this->check04LX->TabIndex = 4;
			this->check04LX->Text = L"URG_04LX";
			this->check04LX->UseVisualStyleBackColor = true;
			this->check04LX->Click += gcnew System::EventHandler(this, &TLaserForm::check04LX_Click);
			// 
			// checkAllLaser
			// 
			this->checkAllLaser->AutoSize = true;
			this->checkAllLaser->Checked = true;
			this->checkAllLaser->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkAllLaser->Location = System::Drawing::Point(9, 10);
			this->checkAllLaser->Name = L"checkAllLaser";
			this->checkAllLaser->Size = System::Drawing::Size(38, 16);
			this->checkAllLaser->TabIndex = 3;
			this->checkAllLaser->Text = L"All";
			this->checkAllLaser->UseVisualStyleBackColor = true;
			this->checkAllLaser->Click += gcnew System::EventHandler(this, &TLaserForm::checkAllLaser_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->lab04LX_State);
			this->panel2->Controls->Add(this->lab30LX_State);
			this->panel2->Location = System::Drawing::Point(3, 9);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(115, 69);
			this->panel2->TabIndex = 7;
			// 
			// lab04LX_State
			// 
			this->lab04LX_State->BackColor = System::Drawing::Color::White;
			this->lab04LX_State->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lab04LX_State->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lab04LX_State->Location = System::Drawing::Point(10, 33);
			this->lab04LX_State->Name = L"lab04LX_State";
			this->lab04LX_State->Size = System::Drawing::Size(92, 23);
			this->lab04LX_State->TabIndex = 2;
			this->lab04LX_State->Text = L"04LX : 0/s";
			this->lab04LX_State->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lab30LX_State
			// 
			this->lab30LX_State->BackColor = System::Drawing::Color::White;
			this->lab30LX_State->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lab30LX_State->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lab30LX_State->Location = System::Drawing::Point(10, 11);
			this->lab30LX_State->Name = L"lab30LX_State";
			this->lab30LX_State->Size = System::Drawing::Size(92, 23);
			this->lab30LX_State->TabIndex = 1;
			this->lab30LX_State->Text = L"30LX : 0/s";
			this->lab30LX_State->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TLaserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 669);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->lbox_Info);
			this->Controls->Add(this->panelMain);
			this->KeyPreview = true;
			this->Name = L"TLaserForm";
			this->Text = L"TLaserForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TLaserForm::TLaserForm_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &TLaserForm::TLaserForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &TLaserForm::TLaserForm_Load);
			this->panelMain->ResumeLayout(false);
			this->gbxRS232->ResumeLayout(false);
			this->gbxRS232->PerformLayout();
			this->gbxSetup->ResumeLayout(false);
			this->gbxSetup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->updownNumOfScans))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackbarScale))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pboxLaserInfo))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


		//==========================================================================
		//		Customize Data
		//==========================================================================
	public:

		TLaser_HOKUYO *Laser1_30LX,*Laser2_04LX;


		String^ StrFilePath;

		//--------------------------------------------------------------------------
	private:
		Bitmap^ bmpLaserBG;

		Graphics^ Draw;

		tsLaserCommand *Cmd_30LX, *Cmd_04LX;

		double ScanLineScale;
		int xCenter, yCenter;

		//==========================================================================
	private: System::Void TLaserForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {

				 StrFilePath = "./DefaultConfigData/LaserRS232.ini";

				 this->lbox_Info->Items->Add("[Msg] Please Search Com Port!!");

				 LoadRS232infoFile();

				 ScanLineScale = 10.0;

				 xCenter = this->pboxLaserInfo->Width / 2;
				 yCenter = this->pboxLaserInfo->Height/ 2;

				 this->Cmd_30LX->Start   = this->hsbarStartStep->Value;
				 this->Cmd_30LX->End     = this->hsbarEndStep->Value;
				 this->Cmd_30LX->Cluster = this->hsbarCluster->Value;
				 this->Cmd_30LX->Interval= Convert::ToInt32(this->cboxInterval->Text);
				 this->Cmd_30LX->NumOfScans = 0;

				 this->Cmd_04LX->Start   = 84;
				 this->Cmd_04LX->End     = 684;
				 this->Cmd_04LX->Cluster = 10;
				 this->Cmd_04LX->Interval= 3;
				 this->Cmd_04LX->NumOfScans = 0;

				 Laser1_30LX->LaserSetup(Cmd_30LX);
				 Laser2_04LX->LaserSetup(Cmd_04LX);
				 this->DisplayCommand(Cmd_30LX);
				 this->DisplayCommand(Cmd_04LX);

				 cboxLaserList_SelectedIndexChanged(sender,e);

			 }
	public:  System::Void LaserDeviceClosed( void )
			 {
				 if ( this->serialport30LX->IsOpen)
				 {
					 char* cmd = Laser1_30LX->QT_Command();
					 this->TransCmd( this->serialport30LX, cmd, Laser1_30LX->Command_Length());
					 this->CloseComDevice(this->serialport30LX, this->lab30LXConnectState);

				 }
				 if ( this->serialport04LX->IsOpen)
				 {
					 char* cmd = Laser2_04LX->QT_Command();
					 this->TransCmd( this->serialport04LX, cmd, Laser2_04LX->Command_Length());
					 this->CloseComDevice(this->serialport04LX, this->lab04LXConnectState);
				 }
			 }
	private: System::Void TLaserForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
			 {

			 }
	private: System::Void TLaserForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
			 {
				 e->Cancel = true;
				 this->Hide();
			 }
	private: System::Void checkAllLaser_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (checkAllLaser->Checked)
				 {
					 check30LX->Checked = true;
					 check04LX->Checked = true;
				 } 
				 else
				 {
					 check30LX->Checked = false;
					 check04LX->Checked = false;
				 }
			 }
	private: System::Void check30LX_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 checkAllLaser->Checked = false;
				 check30LX->Checked = check30LX->Checked? true: false;
			 }
	private: System::Void check04LX_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 checkAllLaser->Checked = false;
				 check04LX->Checked = check04LX->Checked? true: false;
			 }
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (check30LX->Checked && this->serialport30LX->IsOpen)
				 {
					 char* cmd = Laser1_30LX->MDMS_Command(Cmd_30LX);
					 TransCmd(this->serialport30LX, cmd, Laser1_30LX->Command_Length());

				 }
				 if (check04LX->Checked && this->serialport04LX->IsOpen)
				 {
					 char* cmd = Laser2_04LX->MDMS_Command( Cmd_04LX );
					 TransCmd(this->serialport04LX, cmd, Laser2_04LX->Command_Length());
				 }
				 this->gbxSetup->Enabled = false;

			 }
	private: System::Void btnStop_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (check30LX->Checked&& this->serialport30LX->IsOpen)
				 {
					 char* cmd = Laser1_30LX->QT_Command();
					 this->TransCmd( this->serialport30LX, cmd, Laser1_30LX->Command_Length());
				 }
				 if (check04LX->Checked&& this->serialport04LX->IsOpen)
				 {
					 char* cmd = Laser2_04LX->QT_Command();
					 this->TransCmd( this->serialport04LX, cmd, Laser2_04LX->Command_Length());
				 }
				 this->gbxSetup->Enabled = true;
			 }
	private: System::Void DisplayCommand(const tsLaserCommand* Cmd)
			 {
				 double tmpResolution = (cboxLaserList->SelectedIndex==0)?Laser1_30LX->minResolution:
					 Laser2_04LX->minResolution;

				 if (this->cboxCmdType->SelectedIndex == 0)
				 {
					 this->txtStartStep->Text = Convert::ToString( (double) Cmd->Start *tmpResolution*180.0/M_PI);
					 this->txtEndStep->Text   = Convert::ToString( (double) Cmd->End *tmpResolution*180.0/M_PI );
					 this->txtCluster->Text   = Convert::ToString( (double) Cmd->Cluster *tmpResolution*180.0/M_PI  );
				 } 
				 else
				 {
					 this->txtStartStep->Text = Convert::ToString( Cmd->Start);
					 this->txtEndStep->Text   = Convert::ToString( Cmd->End);
					 this->txtCluster->Text   = Convert::ToString( Cmd->Cluster);
				 }

				 this->cboxInterval->SelectedIndex = Cmd->Interval;

				 if (Cmd->NumOfScans == 0)
				 {
					 this->checkContinuous->Checked  = true;
					 this->updownNumOfScans->Enabled = false;
				 } 
				 else
				 {
					 this->checkContinuous->Checked  = false;
					 this->updownNumOfScans->Enabled = true;
					 this->updownNumOfScans->Value   = Cmd->NumOfScans;
				 }

				 lab30LX_Info->Text= "30LX: ["+ Convert::ToString(Laser1_30LX->Info->LiftBorder*180.0/M_PI) +
					 "," + Convert::ToString(Laser1_30LX->Info->RightBorder*180.0/M_PI)+
					 "] ["+ Convert::ToString(Laser1_30LX->Info->Resolution*180.0/M_PI)+
					 "] ["+ Convert::ToString(Laser1_30LX->Info->Number) + "]";

				 lab04LX_Info->Text= "04LX: ["+ Convert::ToString(Laser2_04LX->Info->LiftBorder*180.0/M_PI) +
					 "," + Convert::ToString(Laser2_04LX->Info->RightBorder*180.0/M_PI)+
					 "] ["+ Convert::ToString(Laser2_04LX->Info->Resolution*180.0/M_PI)+
					 "] ["+ Convert::ToString(Laser2_04LX->Info->Number) + "]";

			 }
	private: System::Void cboxCmdType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if ( this->cboxLaserList->SelectedIndex == 0 )
				 {
					 DisplayCommand(this->Cmd_30LX);
				 }
				 else
				 {
					 DisplayCommand(this->Cmd_04LX);
				 }

			 }
	private: System::Void cboxLaserList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (this->cboxLaserList->SelectedIndex == 0)
				 {
					 this->hsbarStartStep->Maximum = Laser1_30LX->maxStep;
					 this->hsbarEndStep->Maximum   = Laser1_30LX->maxStep;

					 this->hsbarStartStep->Value = this->Cmd_30LX->Start;
					 this->hsbarEndStep->Value   = this->Cmd_30LX->End;
					 this->hsbarCluster->Value   = this->Cmd_30LX->Cluster;

					 this->updownNumOfScans->Value = this->Cmd_30LX->NumOfScans;

					 DisplayCommand(Cmd_30LX);
				 } 
				 else
				 {

					 this->hsbarStartStep->Maximum = Laser2_04LX->maxStep;
					 this->hsbarEndStep->Maximum   = Laser2_04LX->maxStep;

					 this->hsbarStartStep->Value = this->Cmd_04LX->Start;
					 this->hsbarEndStep->Value   = this->Cmd_04LX->End;
					 this->hsbarCluster->Value   = this->Cmd_04LX->Cluster;

					 this->updownNumOfScans->Value = this->Cmd_04LX->NumOfScans;
					 DisplayCommand(Cmd_04LX);
				 }

			 }
	private: System::Void AdjustLaserCommand(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) 
			 {
				 if ( this->cboxLaserList->SelectedIndex == 0 )
				 {
					 this->Cmd_30LX->Start   = this->hsbarStartStep->Value;
					 this->Cmd_30LX->End     = this->hsbarEndStep->Value;
					 this->Cmd_30LX->Cluster = this->hsbarCluster->Value;
					 Laser1_30LX->LaserSetup(Cmd_30LX);
					 DisplayCommand(this->Cmd_30LX);
				 } 
				 else
				 {
					 this->Cmd_04LX->Start   = this->hsbarStartStep->Value;
					 this->Cmd_04LX->End     = this->hsbarEndStep->Value;
					 this->Cmd_04LX->Cluster = this->hsbarCluster->Value;
					 Laser2_04LX->LaserSetup(Cmd_04LX);
					 DisplayCommand(this->Cmd_04LX);
				 }
			 }
	private: System::Void checkContinuous_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (this->checkContinuous->Checked)
				 {
					 this->updownNumOfScans->Enabled = false;
					 if ( this->cboxLaserList->SelectedIndex == 0 )
						 this->Cmd_30LX->NumOfScans = 0;
					 else
						 this->Cmd_04LX->NumOfScans = 0;
				 } 
				 else
				 {
					 this->updownNumOfScans->Enabled = true;
					 if ( this->cboxLaserList->SelectedIndex == 0 )
						 this->Cmd_30LX->NumOfScans = Convert::ToInt32(this->updownNumOfScans->Value);
					 else
						 this->Cmd_04LX->NumOfScans = Convert::ToInt32(this->updownNumOfScans->Value);
				 }
			 }
	private: System::Void updownNumOfScans_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if ( this->cboxLaserList->SelectedIndex == 0 )
					 this->Cmd_30LX->NumOfScans = Convert::ToInt32(this->updownNumOfScans->Value);
				 else
					 this->Cmd_04LX->NumOfScans = Convert::ToInt32(this->updownNumOfScans->Value);

			 }
	private: System::Void cboxInterval_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if ( this->cboxLaserList->SelectedIndex == 0 )
					 this->Cmd_30LX->Interval = Convert::ToInt32(this->cboxInterval->Text);
				 else
					 this->Cmd_04LX->Interval = Convert::ToInt32(this->cboxInterval->Text);

			 }
			 ///////////////////////////////////////////////////////////////////////////////////////////
			 //						RS232 部分 begin
			 ///////////////////////////////////////////////////////////////////////////////////////////
			 //---------------------------------------------------------------------------
			 //---------- [自訂] 顯示16進位的除錯訊息
			 //---------------------------------------------------------------------------
	private:  String^ ArrayBuffer2Hex( array<unsigned char,1>^ arraybuf)
			  {
				  String^ str;
				  for(int i=0 ; i<arraybuf->Length ; i++)
					  str=String::Format( str + "0x" + "{0:X}" + " ", arraybuf[i]);
				  return str;
			  }
			  //---------------------------------------------------------------------------
			  //---------- [自訂] 儲存RS232參數資料 (.ini)
			  //---------------------------------------------------------------------------
	private: System::Void SaveRS232infoFile(void)
			 {
				 String^ sTemp = "";
				 IO::StreamWriter^ SW;
				 try
				 {
					 SW = gcnew IO::StreamWriter( StrFilePath, false, System::Text::Encoding::GetEncoding( "Big5" ) );
					 sTemp = "[30LX RS232]";
					 SW->WriteLine(sTemp);
					 sTemp = "ComPort = " + this->cbox30LXPortList->Text;
					 SW->WriteLine(sTemp);	
					 sTemp = "BudRate = " + this->cbox30LXBaudRate->Text;
					 SW->WriteLine(sTemp);	

					 sTemp = "[04LX RS232]";
					 SW->WriteLine(sTemp);
					 sTemp = "ComPort = " + this->cbox04LXPortList->Text;
					 SW->WriteLine(sTemp);	
					 sTemp = "BudRate = " + this->cbox04LXBaudRate->Text;
					 SW->WriteLine(sTemp);	

					 SW->Close();
					 delete SW;
				 }
				 catch(Exception^)
				 {
				 }
			 }
			 //---------------------------------------------------------------------------
			 //---------- [自訂] 讀取RS232參數資料 (.ini)
			 //---------------------------------------------------------------------------
	public: System::Void LoadRS232infoFile(void)
			{

				String^ sTemp = "";
				IO::StreamReader^ SR;
				array<wchar_t> ^delimiter={' '};//以空格做分割
				array<String^> ^spilt;
				try
				{
					if( IO::File::Exists( StrFilePath ) )
					{
						SR = gcnew IO::StreamReader( StrFilePath, System::Text::Encoding::GetEncoding( "Big5" ) );

						sTemp = SR->ReadLine();//[30LX RS232]
						sTemp = SR->ReadLine();//ComPort = ?
						spilt = sTemp->Split(delimiter);

						this->cbox30LXPortList->Items->Clear();
						this->cbox30LXPortList->Items->Add("Un-Enable");
						this->cbox30LXPortList->Items->Add(spilt[2]);
						this->cbox30LXPortList->Text = spilt[2];

						sTemp = SR->ReadLine();//BaudRate = ?
						spilt = sTemp->Split(delimiter);

						this->cbox30LXBaudRate->Text = spilt[2];

						sTemp = SR->ReadLine();//[04LX RS232]
						sTemp = SR->ReadLine();//ComPort = ?
						spilt = sTemp->Split(delimiter);

						this->cbox04LXPortList->Items->Clear();
						this->cbox04LXPortList->Items->Add("Un-Enable");
						this->cbox04LXPortList->Items->Add(spilt[2]);
						this->cbox04LXPortList->Text = spilt[2];

						sTemp = SR->ReadLine();//BaudRate = ?
						spilt = sTemp->Split(delimiter);

						this->cbox04LXBaudRate->Text = spilt[2];
					}
					SR->Close();
					delete SR;
				}
				catch(Exception^)
				{
				}
			}
			//---------------------------------------------------------------------------
			//---------- [自訂] 初始RS232裝置的 com port選擇框
			//---------------------------------------------------------------------------
	private: System::Void InitComboBoxComDevice(System::IO::Ports::SerialPort^  portDevice, ComboBox^  cboxDevice )
			 {	
				 // 讀取與電腦連接之ComPort
				 array<String^>^ tmpPortList = nullptr;

				 cboxDevice->Items->Clear();
				 cboxDevice->Items->Add("Un-Enable");
				 try
				 {			
					 tmpPortList = portDevice->GetPortNames();
				 }
				 catch (Win32Exception^ ex)
				 {
					 Console::WriteLine(ex->Message);
				 }
				 progressbarSearch->Maximum = tmpPortList->Length;
				 progressbarSearch->Value   = 0;

				 //找 ComPort
				 for each(String^ port in tmpPortList)  
				 {		
					 progressbarSearch->Value++;
					 cboxDevice->Items->Add(port);
				 }
			 }
			 //---------------------------------------------------------------------------
			 //---------- [自訂] 開啟RS232裝置
			 //---------------------------------------------------------------------------
	private: System::Void OpenComDevice(System::IO::Ports::SerialPort^  portDevice, ComboBox^  cboxDevice, Label^  DeviceState)
			 {
				 this->lbox_Info->Items->Add("[Msg] RS232 Opening!!!");

				 portDevice->PortName = cboxDevice->Text;
				 try
				 {
					 portDevice->Open();

					 DeviceState->Text = "RS232 Connect";
					 DeviceState->BackColor = System::Drawing::Color::Yellow;
					 SaveRS232infoFile();
				 }
				 catch(Exception^ )
				 {
					 this->lbox_Info->Items->Add("[Msg] * RS232 Open Failure!!!");

					 portDevice->Close();	
					 DeviceState->Text = "RS232 Disconnect";
					 DeviceState->BackColor = System::Drawing::Color::Red;
				 }
			 }
			 //---------------------------------------------------------------------------
			 //---------- [自訂] 關閉RS232裝置
			 //---------------------------------------------------------------------------
	private: System::Void CloseComDevice(System::IO::Ports::SerialPort^  portDevice, Label^  DeviceState)
			 {
				 this->lbox_Info->Items->Add("[Msg] RS232 Closed!!!");

				 portDevice->Close();
				 DeviceState->Text = "RS232 Disconnect";
				 DeviceState->BackColor = System::Drawing::Color::Red;
				 //this->stxtLaserStatus->BackColor = System::Drawing::Color::Red;
			 }
			 //---------------------------------------------------------------------------
			 //---------- [自訂] 傳送封包
			 //---------------------------------------------------------------------------
	public: System::Void TransCmd(System::IO::Ports::SerialPort^  portDevice, char* cmd, int cmd_Length)
			{
				array<unsigned char>^ SendCommand = gcnew array<unsigned char> (cmd_Length);

				Marshal::Copy((IntPtr)cmd,SendCommand, 0, cmd_Length);

				try
				{		
					portDevice->Write(SendCommand,0,SendCommand->Length);
					if (this->checkSendData->Checked)
					{
						this->lbox_Info->Items->Add( "[T](" + Convert::ToString(cmd_Length) + ") => " + System::Text::Encoding::ASCII->GetString(SendCommand) );
					}	 
				}
				catch(Exception^ e)
				{
					this->lbox_Info->Items->Add("\r\n[Err] * RS232 Trans Error(" + e + ")");
				}
				this->lbox_Info->SetSelected(this->lbox_Info->Items->Count-1,true);

			}
			//---------------------------------------------------------------------------
			//---------- [事件] 按下 搜尋RS232裝置
			//---------------------------------------------------------------------------
	private: System::Void btnSearch_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 InitComboBoxComDevice(this->serialport30LX, this->cbox30LXPortList );
				 InitComboBoxComDevice(this->serialport04LX, this->cbox04LXPortList );
			 }
			 //---------------------------------------------------------------------------
			 //---------- [事件] 選擇 RS232裝置的com port
			 //---------------------------------------------------------------------------
	private: System::Void cbox30LXPortList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( !this->serialport30LX->IsOpen )
				 {
					 this->OpenComDevice(this->serialport30LX, this->cbox30LXPortList, this->lab30LXConnectState);
				 }
				 else
				 {
					 this->CloseComDevice(this->serialport30LX, this->lab30LXConnectState);
					 this->OpenComDevice(this->serialport30LX, this->cbox30LXPortList, this->lab30LXConnectState);
				 }
			 }
			 //---------------------------------------------------------------------------
			 //---------- [事件] 選擇 RS232裝置的com port
			 //---------------------------------------------------------------------------
	private: System::Void cbox04LXPortList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if( !this->serialport04LX->IsOpen )
				 {
					 this->OpenComDevice(this->serialport04LX, this->cbox04LXPortList, this->lab04LXConnectState);
				 }
				 else
				 {
					 this->CloseComDevice(this->serialport04LX, this->lab04LXConnectState);
					 this->OpenComDevice(this->serialport04LX, this->cbox04LXPortList, this->lab04LXConnectState);
				 }
			 }
			 //---------------------------------------------------------------------------
			 //---------- [事件] 偵測 RS232發生錯誤
			 //---------------------------------------------------------------------------
	private: System::Void serialport30LX_ErrorReceived(System::Object^  sender, System::IO::Ports::SerialErrorReceivedEventArgs^  e) 
			 {
				 this->lbox_Info->Items->Add("[Err][30LX] * RS232 Error(" + e + ")");
				 this->CloseComDevice(this->serialport30LX, this->lab30LXConnectState);	
			 }
			 //---------------------------------------------------------------------------
			 //---------- [事件] 偵測 RS232發生錯誤
			 //---------------------------------------------------------------------------
	private: System::Void serialport04LX_ErrorReceived(System::Object^  sender, System::IO::Ports::SerialErrorReceivedEventArgs^  e) 
			 {
				 this->lbox_Info->Items->Add("[Err][04LX] * RS232 Error(" + e + ")");
				 this->CloseComDevice(this->serialport04LX, this->lab04LXConnectState);
			 }
			 //---------------------------------------------------------------------------
			 //---------- [事件] 30LX接收 RS232回傳資料
			 //---------------------------------------------------------------------------
	private: System::Void serialport30LX_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) 
			 {

				 int PkgLength = serialport30LX->BytesToRead;
				 array<unsigned char>^ ReceverBuffer = gcnew array<unsigned char> ( PkgLength );
				 try
				 {
					 this->serialport30LX->Read(ReceverBuffer, 0, PkgLength);

					 unsigned char *ucPkg = new unsigned char[PkgLength];
					 Marshal::Copy( ReceverBuffer, 0, (IntPtr)ucPkg, PkgLength);

					 Form::CheckForIllegalCrossThreadCalls = false;

					 const char *Str;
					 if( !(Laser1_30LX->FlagBusy) )
					 {
						 Str =  Laser1_30LX->Analyze( ucPkg ,PkgLength );
						 this->lab30LXConnectState->BackColor = (strcmp(Str, "OK MDMS"))? Color::Yellow: Color::Lime;
					 }

					 //---- 畫掃描線
					 DrawScanLine();

					 if (this->checkReceiveData->Checked)
					 {
						 this->lbox_Info->Items->Add( "[Msg] Pkg Length「" +  PkgLength + "」" );
						 this->lbox_Info->Items->Add(this->ArrayBuffer2Hex(ReceverBuffer));
					 }
					 delete[] ucPkg;
				 }
				 catch(Exception^)
				 {

				 }
			 }
			 //---------------------------------------------------------------------------
			 //---------- [事件] 04LX接收 RS232回傳資料
			 //---------------------------------------------------------------------------
	private: System::Void serialport04LX_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) 
			 {
				 int PkgLength = serialport04LX->BytesToRead;
				 array<unsigned char>^ ReceverBuffer = gcnew array<unsigned char> ( PkgLength );
				 try
				 {
					 this->serialport04LX->Read(ReceverBuffer, 0, PkgLength);

					 unsigned char *ucPkg = new unsigned char[PkgLength];
					 Marshal::Copy( ReceverBuffer, 0, (IntPtr)ucPkg, PkgLength);

					 Form::CheckForIllegalCrossThreadCalls = false;

					 const char *Str;
					 if( !(Laser2_04LX->FlagBusy) )
					 {
						 Str =  Laser2_04LX->Analyze( ucPkg ,PkgLength );
						 this->lab04LXConnectState->BackColor = (strcmp(Str, "OK MDMS"))? Color::Yellow: Color::Lime;
					 }

					 //---- 畫掃描線
					 DrawScanLine();

					 if (this->checkReceiveData->Checked)
					 {
						 this->lbox_Info->Items->Add( "[Msg] Pkg Length「" +  PkgLength + "」" );
						 this->lbox_Info->Items->Add(this->ArrayBuffer2Hex(ReceverBuffer));
					 }
					 delete[] ucPkg;
				 }
				 catch(Exception^)
				 {

				 }

			 }
			 //---------------------------------------------------------------------------
			 //---------- [自訂] 繪製掃瞄線
			 //---------------------------------------------------------------------------
	private: System::Void DrawScanLine( void )
			 {
				 if (Laser1_30LX->Info->FlagRenew||Laser2_04LX->Info->FlagRenew)
				 {
					 this->pboxLaserInfo->Refresh();
					 Draw = this->pboxLaserInfo->CreateGraphics();
				 }

				 Pen^ penLaser = gcnew Pen( Color::Red, 1 );
				 penLaser->LineJoin = Drawing::Drawing2D::LineJoin::Bevel;

				 double ScanLineLength, ScanLineAngle;
				 if (Laser1_30LX->Info->FlagRenew && this->checkShow30LX->Checked)
				 {
					 array<Drawing::Point> ^Points1 = gcnew array<Drawing::Point> (Laser1_30LX->Info->Number);
					 for(int i = 0 ;i < Laser1_30LX->Info->Number ; i++ )
					 {
						 ScanLineLength = (double)( Laser1_30LX->Info->Data[i]/ScanLineScale )* def_LaserScale;
						 ScanLineAngle  = (double)( Laser1_30LX->Info->Angle[i] + M_PI_2);

						 Points1[i].X = xCenter + ScanLineLength*Math::Cos(ScanLineAngle);
						 Points1[i].Y = yCenter - ScanLineLength*Math::Sin(ScanLineAngle);
					 }
					 Draw->DrawLines( penLaser ,Points1);
				 }

				 if (Laser2_04LX->Info->FlagRenew && this->checkShow04LX->Checked)
				 {
					 array<Drawing::Point> ^Points2 = gcnew array<Drawing::Point> (Laser2_04LX->Info->Number);
					 for(int i = 0 ;i < Laser2_04LX->Info->Number ; i++ )
					 {
						 ScanLineLength = (double)( Laser2_04LX->Info->Data[i]/ScanLineScale )* def_LaserScale;
						 ScanLineAngle  = (double)( Laser2_04LX->Info->Angle[i] + M_PI_2);

						 Points2[i].X = xCenter + ScanLineLength*Math::Cos(ScanLineAngle);
						 Points2[i].Y = yCenter - ScanLineLength*Math::Sin(ScanLineAngle);
					 }
					 penLaser->Color = Color::LimeGreen;
					 Draw->DrawLines( penLaser ,Points2);
				 }
			 }
	private: System::Void trackbarScale_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 ScanLineScale = this->trackbarScale->Value;

				 DrawScanLine();

				 int D1 =  this->trackbarScale->Value * 12.5;
				 int D2 =  this->trackbarScale->Value * 20;
				 if( D1 > 100 )
				 {
					 this->lab_DisL1->Text = Convert::ToString( (float)D1/100.0 ) + "m";
					 this->lab_DisL2->Text = Convert::ToString( (float)D2/100.0 ) + "m";
					 this->lab_DisR1->Text = Convert::ToString( (float)D1/100.0 ) + "m";
					 this->lab_DisR2->Text = Convert::ToString( (float)D2/100.0 ) + "m";
				 }else
				 {
					 this->lab_DisL1->Text = Convert::ToString( D1 ) + "cm";
					 this->lab_DisL2->Text = Convert::ToString( D2 ) + "cm";
					 this->lab_DisR1->Text = Convert::ToString( D1 ) + "cm";
					 this->lab_DisR2->Text = Convert::ToString( D2 ) + "cm";
				 }
				 this->labScale->Text = "Scale: " + Convert::ToString(this->trackbarScale->Value / 10.0);
			 }


	};
}
