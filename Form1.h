#pragma once

//!  The main interface.

#include <math.h>
#include "Map.h"
#include "Database.h"

#include "TLaserForm.h"
#include "Furniture/Furniture.h"
#include "MapEditer/MapEditer.h"

#include "Core/VelocityControl/TVelocityControl.h"
#include "Core/NavigationSystem/NavigationSystem.h"
#include "Core/Motion/TMotion.h"

namespace SKS_VC2013 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace System::Text;

	using namespace System::Xml;
	using namespace System::IO;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}
	
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 




	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>

		String^ MSG_Str;
		delegate void SetTextDelegate();

		//!Socket
		Socket^ ClientSocket;	/**< Client Socket. */
		static int Client_already = 0;	/**< Client Check. */

		//! File.
		String^ fileName;

		//! Paint.
		Bitmap^ mBMP;
		Graphics^ mGraphic;

		//! View Form.
		Map^ mMap;

		//! Set Form.
		Furniture^ mFurniture;
		MapEditer^ mMapEditer;
		TLaserForm^ mLaserForm;

		TNavigationSystem *NewNavigationSystem;

		

	private: System::Windows::Forms::ListBox^  MSG_list;
	private: System::Windows::Forms::Button^  Up_sd;
	private: System::Windows::Forms::Button^  Left_sd;
	private: System::Windows::Forms::Button^  Right_sd;
	private: System::Windows::Forms::Button^  Down_sd;
	private: System::Windows::Forms::PictureBox^  drawPB;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  View_set;
	private: System::Windows::Forms::ToolStripMenuItem^  MapToolStripMenuItem;

	private: System::Windows::Forms::HScrollBar^  Speed_Bar;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  Speed_lab;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  R_b;
	private: System::Windows::Forms::Button^  L_b;
	private: System::Windows::Forms::CheckBox^  Ctrl_check;

	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::ToolStripMenuItem^  laserToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Setup_set;
	private: System::Windows::Forms::ToolStripMenuItem^  furnitureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mapEditerToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  Auto_check;

	private: System::Windows::Forms::ToolStripMenuItem^  mapToolStripMenuItem1;
	private: System::Windows::Forms::Button^  Btn_SysStart;
	private: System::Windows::Forms::Button^  btn_SysStop;
	private: System::Windows::Forms::ToolStripMenuItem^  lasertestToolStripMenuItem;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->MSG_list = (gcnew System::Windows::Forms::ListBox());
			this->Up_sd = (gcnew System::Windows::Forms::Button());
			this->Left_sd = (gcnew System::Windows::Forms::Button());
			this->Right_sd = (gcnew System::Windows::Forms::Button());
			this->Down_sd = (gcnew System::Windows::Forms::Button());
			this->drawPB = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Setup_set = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->furnitureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mapEditerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mapToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lasertestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->View_set = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->laserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Speed_Bar = (gcnew System::Windows::Forms::HScrollBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Speed_lab = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Auto_check = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Ctrl_check = (gcnew System::Windows::Forms::CheckBox());
			this->R_b = (gcnew System::Windows::Forms::Button());
			this->L_b = (gcnew System::Windows::Forms::Button());
			this->Btn_SysStart = (gcnew System::Windows::Forms::Button());
			this->btn_SysStop = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->drawPB))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// MSG_list
			// 
			this->MSG_list->FormattingEnabled = true;
			this->MSG_list->HorizontalScrollbar = true;
			this->MSG_list->ItemHeight = 12;
			this->MSG_list->Location = System::Drawing::Point(12, 401);
			this->MSG_list->Name = L"MSG_list";
			this->MSG_list->ScrollAlwaysVisible = true;
			this->MSG_list->Size = System::Drawing::Size(220, 148);
			this->MSG_list->TabIndex = 8;
			// 
			// Up_sd
			// 
			this->Up_sd->BackColor = System::Drawing::Color::Transparent;
			this->Up_sd->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Up_sd->Location = System::Drawing::Point(80, 215);
			this->Up_sd->Name = L"Up_sd";
			this->Up_sd->Size = System::Drawing::Size(50, 50);
			this->Up_sd->TabIndex = 11;
			this->Up_sd->Text = L"↑";
			this->Up_sd->UseVisualStyleBackColor = false;
			this->Up_sd->Click += gcnew System::EventHandler(this, &Form1::Up_sd_Click);
			// 
			// Left_sd
			// 
			this->Left_sd->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Left_sd->Location = System::Drawing::Point(30, 265);
			this->Left_sd->Name = L"Left_sd";
			this->Left_sd->Size = System::Drawing::Size(50, 50);
			this->Left_sd->TabIndex = 12;
			this->Left_sd->Text = L"←";
			this->Left_sd->UseVisualStyleBackColor = true;
			this->Left_sd->Click += gcnew System::EventHandler(this, &Form1::Left_sd_Click);
			// 
			// Right_sd
			// 
			this->Right_sd->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Right_sd->Location = System::Drawing::Point(130, 265);
			this->Right_sd->Name = L"Right_sd";
			this->Right_sd->Size = System::Drawing::Size(50, 50);
			this->Right_sd->TabIndex = 13;
			this->Right_sd->Text = L"→";
			this->Right_sd->UseVisualStyleBackColor = true;
			this->Right_sd->Click += gcnew System::EventHandler(this, &Form1::Right_sd_Click);
			// 
			// Down_sd
			// 
			this->Down_sd->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Down_sd->Location = System::Drawing::Point(80, 265);
			this->Down_sd->Name = L"Down_sd";
			this->Down_sd->Size = System::Drawing::Size(50, 50);
			this->Down_sd->TabIndex = 14;
			this->Down_sd->Text = L"↓";
			this->Down_sd->UseVisualStyleBackColor = true;
			this->Down_sd->Click += gcnew System::EventHandler(this, &Form1::Down_sd_Click);
			// 
			// drawPB
			// 
			this->drawPB->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"drawPB.Image")));
			this->drawPB->Location = System::Drawing::Point(32, 66);
			this->drawPB->Name = L"drawPB";
			this->drawPB->Size = System::Drawing::Size(144, 149);
			this->drawPB->TabIndex = 15;
			this->drawPB->TabStop = false;
			this->drawPB->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::drawPB_MouseDown);
			this->drawPB->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::drawPB_MouseMove);
			this->drawPB->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::drawPB_MouseUp);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::DarkGray;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->Setup_set, this->View_set});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(246, 24);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Setup_set
			// 
			this->Setup_set->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->furnitureToolStripMenuItem, 
				this->mapEditerToolStripMenuItem, this->mapToolStripMenuItem1, this->lasertestToolStripMenuItem});
			this->Setup_set->Name = L"Setup_set";
			this->Setup_set->Size = System::Drawing::Size(53, 20);
			this->Setup_set->Text = L"Setup";
			// 
			// furnitureToolStripMenuItem
			// 
			this->furnitureToolStripMenuItem->Name = L"furnitureToolStripMenuItem";
			this->furnitureToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->furnitureToolStripMenuItem->Text = L"Furniture";
			this->furnitureToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::furnitureToolStripMenuItem_Click);
			// 
			// mapEditerToolStripMenuItem
			// 
			this->mapEditerToolStripMenuItem->Name = L"mapEditerToolStripMenuItem";
			this->mapEditerToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->mapEditerToolStripMenuItem->Text = L"MapEditer";
			this->mapEditerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mapEditerToolStripMenuItem_Click);
			// 
			// mapToolStripMenuItem1
			// 
			this->mapToolStripMenuItem1->Name = L"mapToolStripMenuItem1";
			this->mapToolStripMenuItem1->Size = System::Drawing::Size(138, 22);
			this->mapToolStripMenuItem1->Text = L"Map";
			this->mapToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::mapToolStripMenuItem1_Click);
			// 
			// lasertestToolStripMenuItem
			// 
			this->lasertestToolStripMenuItem->Name = L"lasertestToolStripMenuItem";
			this->lasertestToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->lasertestToolStripMenuItem->Text = L"LaserSetup";
			this->lasertestToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::lasertestToolStripMenuItem_Click);
			// 
			// View_set
			// 
			this->View_set->Name = L"View_set";
			this->View_set->Size = System::Drawing::Size(12, 20);
			// 
			// MapToolStripMenuItem
			// 
			this->MapToolStripMenuItem->Name = L"MapToolStripMenuItem";
			this->MapToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// laserToolStripMenuItem
			// 
			this->laserToolStripMenuItem->Name = L"laserToolStripMenuItem";
			this->laserToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// Speed_Bar
			// 
			this->Speed_Bar->Location = System::Drawing::Point(8, 29);
			this->Speed_Bar->Maximum = 409;
			this->Speed_Bar->Minimum = 100;
			this->Speed_Bar->Name = L"Speed_Bar";
			this->Speed_Bar->Size = System::Drawing::Size(80, 17);
			this->Speed_Bar->TabIndex = 17;
			this->Speed_Bar->Value = 100;
			this->Speed_Bar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::Speed_Bar_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(9, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 12);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Speed";
			// 
			// Speed_lab
			// 
			this->Speed_lab->AutoSize = true;
			this->Speed_lab->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Speed_lab->Location = System::Drawing::Point(52, 13);
			this->Speed_lab->Name = L"Speed_lab";
			this->Speed_lab->Size = System::Drawing::Size(23, 12);
			this->Speed_lab->TabIndex = 19;
			this->Speed_lab->Text = L"100";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::DimGray;
			this->groupBox1->Controls->Add(this->Auto_check);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->Ctrl_check);
			this->groupBox1->Controls->Add(this->drawPB);
			this->groupBox1->Controls->Add(this->Up_sd);
			this->groupBox1->Controls->Add(this->Right_sd);
			this->groupBox1->Controls->Add(this->Down_sd);
			this->groupBox1->Controls->Add(this->Left_sd);
			this->groupBox1->Controls->Add(this->R_b);
			this->groupBox1->Controls->Add(this->L_b);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->groupBox1->Location = System::Drawing::Point(12, 75);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(220, 320);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			// 
			// Auto_check
			// 
			this->Auto_check->AutoSize = true;
			this->Auto_check->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Auto_check->Location = System::Drawing::Point(7, 29);
			this->Auto_check->Name = L"Auto_check";
			this->Auto_check->Size = System::Drawing::Size(98, 16);
			this->Auto_check->TabIndex = 29;
			this->Auto_check->Text = L"Auto_Simulator";
			this->Auto_check->UseVisualStyleBackColor = true;
			this->Auto_check->CheckedChanged += gcnew System::EventHandler(this, &Form1::Auto_check_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Speed_Bar);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->Speed_lab);
			this->groupBox2->Location = System::Drawing::Point(119, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(93, 54);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			// 
			// Ctrl_check
			// 
			this->Ctrl_check->AutoSize = true;
			this->Ctrl_check->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->Ctrl_check->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Ctrl_check->Location = System::Drawing::Point(7, 13);
			this->Ctrl_check->Name = L"Ctrl_check";
			this->Ctrl_check->Size = System::Drawing::Size(93, 16);
			this->Ctrl_check->TabIndex = 23;
			this->Ctrl_check->Text = L"Ctrl_Simulator";
			this->Ctrl_check->UseVisualStyleBackColor = true;
			this->Ctrl_check->CheckedChanged += gcnew System::EventHandler(this, &Form1::Ctrl_check_CheckedChanged);
			// 
			// R_b
			// 
			this->R_b->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->R_b->Location = System::Drawing::Point(130, 215);
			this->R_b->Name = L"R_b";
			this->R_b->Size = System::Drawing::Size(50, 50);
			this->R_b->TabIndex = 11;
			this->R_b->Text = L"R";
			this->R_b->UseVisualStyleBackColor = true;
			this->R_b->Click += gcnew System::EventHandler(this, &Form1::R_b_Click);
			// 
			// L_b
			// 
			this->L_b->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->L_b->Location = System::Drawing::Point(30, 215);
			this->L_b->Name = L"L_b";
			this->L_b->Size = System::Drawing::Size(50, 50);
			this->L_b->TabIndex = 11;
			this->L_b->Text = L"L";
			this->L_b->UseVisualStyleBackColor = true;
			this->L_b->Click += gcnew System::EventHandler(this, &Form1::L_b_Click);
			// 
			// Btn_SysStart
			// 
			this->Btn_SysStart->BackColor = System::Drawing::SystemColors::Control;
			this->Btn_SysStart->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Btn_SysStart->ForeColor = System::Drawing::Color::LimeGreen;
			this->Btn_SysStart->Location = System::Drawing::Point(12, 27);
			this->Btn_SysStart->Name = L"Btn_SysStart";
			this->Btn_SysStart->Size = System::Drawing::Size(110, 45);
			this->Btn_SysStart->TabIndex = 21;
			this->Btn_SysStart->Text = L"START";
			this->Btn_SysStart->UseVisualStyleBackColor = false;
			this->Btn_SysStart->Click += gcnew System::EventHandler(this, &Form1::Btn_SysStart_Click);
			// 
			// btn_SysStop
			// 
			this->btn_SysStop->BackColor = System::Drawing::SystemColors::Control;
			this->btn_SysStop->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_SysStop->ForeColor = System::Drawing::Color::Red;
			this->btn_SysStop->Location = System::Drawing::Point(122, 27);
			this->btn_SysStop->Name = L"btn_SysStop";
			this->btn_SysStop->Size = System::Drawing::Size(110, 45);
			this->btn_SysStop->TabIndex = 22;
			this->btn_SysStop->Text = L"STOP";
			this->btn_SysStop->UseVisualStyleBackColor = false;
			this->btn_SysStop->Click += gcnew System::EventHandler(this, &Form1::btn_SysStop_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Gray;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(246, 563);
			this->Controls->Add(this->btn_SysStop);
			this->Controls->Add(this->Btn_SysStart);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->MSG_list);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"MainFrom";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->drawPB))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		
#pragma endregion

//! First Load Code.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 NewNavigationSystem = new TNavigationSystem();

				 drawPB->Width  = Radar_Width;
				 drawPB->Height = Radar_Height;

				 Radar_Basic(RaderCenter_x , RaderCenter_y);
				 

				 Read_Object();
			 }

//! Connection Set.
/**<Client Code. */
/*
	void waitAcceptSocket(){
		while(true)
		{
			int byteNum=0;
			array<unsigned char> ^recvBytes = gcnew array<unsigned char>(74460);

			FileInfo^ fg = gcnew FileInfo( "Back_Status.xml" );

			while(true)
			{
				if(ClientSocket->Connected){
					Client_already = 1;
				}else{
					Client_already = 0;
					Client_set->Text = "Set";
				}

				try{
					byteNum =ClientSocket->Receive(recvBytes,recvBytes->Length,static_cast<SocketFlags>(0)); /**< Wait Message. *//*
				}
				catch (SocketException^){
					ClientSocket->Close();
					timer3->Stop();
					Client_set->Text = "Set";
				}
				
				//!Receive area.
				if(byteNum==0) break;
				Encoding ^encoder= Encoding::UTF8;

				if (fg->Exists)	fg->Delete();

				FileStream^ MSG_back = fg->Create();

				String ^recvstring =encoder->GetString(recvBytes,0,byteNum);

				array<Byte> ^ss = gcnew array<Byte>(byteNum);
				int i;

				for(i=0; i < byteNum ; i++) ss[i] = recvBytes[i];

				array<Byte>^info = ss ;
				MSG_back->Write( ss, 0, ss->Length );

				MSG_back->Close();

				Read_Status();
			}
			ClientSocket->Close();
			System::Diagnostics::Debug::WriteLine("Form1::waitAcceptSocket");
		}
	}
//!Client Set.
	void establishSendSocket(){
		try{
			IPAddress ^hostAddr = IPAddress::Parse(IP_box->Text);

			IPEndPoint ^host = gcnew IPEndPoint(hostAddr, System::Convert::ToInt32(Client_box->Text));
			ClientSocket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

			ClientSocket->Connect(host);
			System::Diagnostics::Debug::WriteLine("successfully't connect to echo server");
		}catch(SocketException^){}
	}
	private: System::Void Client_set_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (Client_set->Text == "Close"){
					 ClientSocket->Close();
					 timer3->Stop();
					 Client_set->Text = "Set";
				 }else{
					 establishSendSocket();
					 backgroundWorker2->RunWorkerAsync();
					 timer3->Start();
				 }
			 }
	private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				 waitAcceptSocket();
			 }
*/


//!Ladar Drawing.
	void Radar_Basic(double x , double y){
		Pen^ blackPen = gcnew Pen(Color::Black, 3);

		mBMP  = gcnew Bitmap(Radar_Width, Radar_Height); //背景和框繪製區
		mGraphic   = Graphics::FromImage(mBMP);
		mBMP  = gcnew Bitmap("Radar.png");
		mGraphic   = Graphics::FromImage(mBMP);
		drawPoint(x,y);
		mGraphic->DrawLine(blackPen , (int)RaderCenter_x , (int)RaderCenter_y , (int)x , (int)y);

	}
/**<Red Point. */
	private: void drawPoint(double x , double y){
				 SolidBrush^ PointBrush = gcnew SolidBrush( Color::Red );
				 mGraphic->FillPie(PointBrush,(int)x-3 ,(int)y-3 ,(int)7 ,(int)7,(int) 0,(int) 359 );
				 drawPB->Image = mBMP;
			 }
/**<ArcInt. */
	private: void DrawArcInt(double length,double ang){
				 Pen^ blackPen = gcnew Pen( Color::Black,3 );		/**<Black Pen. */
				 SolidBrush^ skyblueBrush = gcnew SolidBrush( Color::SkyBlue );

				 double x = RaderCenter_x-length;
				 double y = RaderCenter_y-length;
				 double width = length+length;
				 double height = length+length;

				 double startAngle = 270;

				 while(ang>180)ang = ang - 360;
				 while(ang<-180)ang = ang + 360;
				 double sweepAngle = ang;
				 if(width>0 && height>0){
					 mGraphic->FillPie(skyblueBrush,(int)x,(int)y,(int) width,(int)height,(int) startAngle,(int) sweepAngle );
					 mGraphic->DrawArc(blackPen,(int)x,(int)y,(int) width,(int)height,(int) startAngle,(int) sweepAngle );
				 }

				 drawPB->Image = mBMP;
			 }

/**
	Xml Area.
*/
//!Read Furniture Xml.
		void Read_Object(){
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Furniture_set.xml");
			XmlNode^ Manual = doc->SelectSingleNode("/Config/DirectionObject");

			for(int i =0 ;i < Manual->ChildNodes->Count;i++){
				XmlNode^ node = Manual->ChildNodes[i];
				XmlElement^ element=(XmlElement^)node;
				if(element->Name =="LivingRM_Sofa"){
					D_Furniture->M_LivingRM.Sofa.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_LivingRM.Sofa.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_LivingRM.Sofa.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_LivingRM.Sofa.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_LivingRM.Sofa.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="LivingRM_Table"){
					D_Furniture->M_LivingRM.Table.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_LivingRM.Table.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_LivingRM.Table.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_LivingRM.Table.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_LivingRM.Table.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="LivingRM_Cabinet"){
					D_Furniture->M_LivingRM.Cabinet.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_LivingRM.Cabinet.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_LivingRM.Cabinet.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_LivingRM.Cabinet.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_LivingRM.Cabinet.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="DiningRM_Table"){
					D_Furniture->M_DiningRM.Table.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_DiningRM.Table.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_DiningRM.Table.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_DiningRM.Table.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_DiningRM.Table.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="DiningRM_Chair"){
					D_Furniture->M_DiningRM.Chair.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_DiningRM.Chair.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_DiningRM.Chair.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_DiningRM.Chair.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_DiningRM.Chair.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="Library_Desk"){
					D_Furniture->M_Library.Desk.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_Library.Desk.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_Library.Desk.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_Library.Desk.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_Library.Desk.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="Library_Chair"){
					D_Furniture->M_Library.Chair.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_Library.Chair.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_Library.Chair.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_Library.Chair.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_Library.Chair.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="Library_Cabinet"){
					D_Furniture->M_Library.Cabinet.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_Library.Cabinet.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_Library.Cabinet.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_Library.Cabinet.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_Library.Cabinet.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="BedRM_Bed"){
					D_Furniture->M_BedRM.Bed.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_BedRM.Bed.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_BedRM.Bed.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_BedRM.Bed.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_BedRM.Bed.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="DiningRM_door"){
					D_Furniture->M_DiningRM.door.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_DiningRM.door.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_DiningRM.door.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_DiningRM.door.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_DiningRM.door.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="BedRM_door"){
					D_Furniture->M_BedRM.door.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_BedRM.door.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_BedRM.door.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_BedRM.door.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_BedRM.door.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="Trashcan"){
					D_Furniture->M_Trashcan.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_Trashcan.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_Trashcan.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_Trashcan.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_Trashcan.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="ChargeArea"){
					D_Furniture->M_ChargeArea.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_ChargeArea.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_ChargeArea.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_ChargeArea.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_ChargeArea.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}else if(element->Name =="EndArea"){
					D_Furniture->M_EndArea.x = System::Convert::ToDouble(element->GetAttribute("x"));
					D_Furniture->M_EndArea.y = System::Convert::ToDouble(element->GetAttribute("y"));
					D_Furniture->M_EndArea.Width = System::Convert::ToDouble(element->GetAttribute("Width"));
					D_Furniture->M_EndArea.Height = System::Convert::ToDouble(element->GetAttribute("Height"));
					D_Furniture->M_EndArea.Angle = System::Convert::ToDouble(element->GetAttribute("Angle"));
				}
			}
		}


//!Read Callback Status Xml.
public:	void Read_Status(){
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Back_Status.xml");
			XmlNode^ Manual = doc->SelectSingleNode("/Status");
			if(Manual!=nullptr){
				for(int i=0;i < Manual->ChildNodes->Count;i++){
					XmlNode^ Manual2 = Manual->ChildNodes[i];
					XmlElement^ element=(XmlElement^)Manual2;
					if(element->Name == "Movement"){
						R_Robot->X= System::Convert::ToDouble(element->GetAttribute("x"));
						R_Robot->Y= System::Convert::ToDouble(element->GetAttribute("y"));
						R_Robot->Radian= System::Convert::ToDouble(element->GetAttribute("sita"));
					}else if (element->Name == "Laser"){
						for(int i=0;i<element->ChildNodes->Count;i++){
							XmlNode^ b = element->ChildNodes[i];
							XmlElement^ a = (XmlElement^) b;

							Real_Laser[i].Angle = 90-(2.5*i);	//! 90 to -90.
							Real_Laser[i].Distance = System::Convert::ToDouble(a->GetAttribute("d")) / 10;	//! mm to cm.
						}
					}else if(element->Name == "Position"){
						R_Position->x= System::Convert::ToDouble(element->GetAttribute("x"));
						R_Position->y= System::Convert::ToDouble(element->GetAttribute("y"));
						R_Position->ang= System::Convert::ToDouble(element->GetAttribute("sita"))*180/PI; //! Radian to Angle
					}else if(element->Name == "Camera_Angle"){
						R_Robot->Camera_Angle = System::Convert::ToDouble(element->GetAttribute("ang"));
					}
				}
			}
		}

//! Change to Unit.
		double ChangetoUnit(double Sit){
			double Unit_Sit;
			if(Sit > Rader_Radius){	Unit_Sit = 1;}
			else if(Sit < -1*Rader_Radius){	Unit_Sit = -1;}
			else{	Unit_Sit = Sit / Rader_Radius;}

			return Unit_Sit;
		}
//!Read Command Xml.
public:	void Write_Robot(){
			double Unit_x,Unit_y;

			Unit_x = ChangetoUnit(D_Touch->X);
			Unit_y = ChangetoUnit(D_Touch->Y);
		
			if(D_mos->Right == 0){
				D_Touch->Radian = 0;
			}else{
				Unit_x = 0;
				Unit_y = 0;
			}

			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Robot_Command.xml");
			XmlNode^ Manual = doc->SelectSingleNode("/Command/ManualDirection"); //!Choose Node.

			int Sim_t=0;

			for(int i =0 ;i < Manual->ChildNodes->Count;i++){
				XmlNode^ node = Manual->ChildNodes[i];
				XmlElement^ element=(XmlElement^)node;
				if(element->Name == "Vector"){
					element->SetAttribute("x",System::Convert::ToString(Unit_x * Speed_Bar->Value));
					element->SetAttribute("y",System::Convert::ToString(Unit_y * Speed_Bar->Value));
				}else if(element->Name == "Rotate"){
					element->SetAttribute("w",System::Convert::ToString(D_Touch->Radian));
				}else if(element->Name == "Camera"){
					element->SetAttribute("ang",System::Convert::ToString(D_Order->Camera));
				}else if(element->Name == "TakeBall"){
					element->SetAttribute("ballFlag",System::Convert::ToString(D_Order->TakeBall));
				}else if(element->Name == "Sim_flag"){
					Sim_t = 1;
				}
			}

			if(Auto_check->Checked){
				if(Sim_t==0){
					XmlElement^ Distance = doc->CreateElement("Sim_flag");
					Manual->AppendChild(Distance);
				}
			}else{
				if(Sim_t==1)	Manual->RemoveChild(Manual->SelectSingleNode("Sim_flag"));
			}


			doc->Save("Robot_Command.xml");
			if(Ctrl_check->Checked){
				D_Order->X = Unit_x * Speed_Bar->Value;
				D_Order->Y = Unit_y * Speed_Bar->Value;
				D_Order->Radian = D_Touch->Radian;
				if (mMap != nullptr){
					mMap->drawRobot();
				}
			}
		}
public:	void Read_Robot(){
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Robot_Command.xml");
			XmlNode^ Manual = doc->SelectSingleNode("/Command/ManualDirection");

			for(int i =0 ;i < Manual->ChildNodes->Count;i++){
				XmlNode^ node = Manual->ChildNodes[i];

				XmlElement^ element=(XmlElement^)node;
				if(element->Name == "Vector"){
					D_Vector->X= System::Convert::ToDouble(element->GetAttribute("x"));
					D_Vector->Y= System::Convert::ToDouble(element->GetAttribute("y"));
				}else if(element->Name == "Rotate"){
					D_Vector->Radian= System::Convert::ToDouble(element->GetAttribute("w"));
				}
			}
		}

//! Control and Send.
/*public:	void send(){
			if(Ctrl_check->Checked && Client_already && ClientSocket->Connected){
				fileName = "Robot_Command.xml";
				ClientSocket->SendFile(fileName);
			}
		
			MSG_list->Items->Add( "Robot"+ "\r\n");
			MSG_list->Items->Add( "user_x : " + (int)D_Vector->X + "\r\n");
			MSG_list->Items->Add( "user_y : " + (int)D_Vector->Y + "\r\n");
			MSG_list->Items->Add( "user_tar : " + (int)D_Vector->Radian + "\r\n");
			MSG_list->Items->Add( "user_Came : " + (int)D_Order->Camera + "\r\n");
			MSG_list->Items->Add( "user_TakeBall : " + (int)D_Order->TakeBall + "\r\n");

			MSG_list->SelectedIndex = MSG_list->Items->Count-1;   //跟隨卷軸往下
			//MSG_list->TopIndex = MSG_list->Items->Count-1;		//跟隨卷軸往下(2)
		}
*/
	private: System::Void Down_sd_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = 0;
			 D_Touch->Y = Rader_Radius/-10;
			 D_Touch->Radian = 0;
			 D_mos->Right = 0;
			 Write_Robot();
			 Read_Robot();
			 //send();
		 }
	private: System::Void Up_sd_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = 0;
			 D_Touch->Y = Rader_Radius/10;
			 D_Touch->Radian = 0;
			 D_mos->Right = 0;
			 Write_Robot();
			 Read_Robot();
			 //send();
		 }
	private: System::Void Left_sd_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = Rader_Radius/-10;
			 D_Touch->Y = 0;
			 D_Touch->Radian = 0;
			 D_mos->Right = 0;
			 Write_Robot();
			 Read_Robot();
			 //send();
		 }
	private: System::Void Right_sd_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = Rader_Radius/10;
			 D_Touch->Y = 0;
			 D_Touch->Radian = 0;
			 D_mos->Right = 0;
			 Write_Robot();
			 Read_Robot();
			 //send();
		 }
	private: System::Void R_b_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = 0;
			 D_Touch->Y = 0;
			 D_Touch->Radian = 10*PI/180;
			 D_mos->Right = 1;
			 Write_Robot();
			 Read_Robot();
			 //send();
		 }
	private: System::Void L_b_Click(System::Object^  sender, System::EventArgs^  e) {
			 D_Touch->X = 0;
			 D_Touch->Y = 0;
			 D_Touch->Radian = -10*PI/180;
			 D_mos->Right = 1;
			 Write_Robot();
			 Read_Robot();
			 //send();
		 }
	void drawPB_mos(System::Windows::Forms::MouseEventArgs^  e){
		D_mos->X = e->X;
		D_mos->Y = e->Y;
		D_mos->Right = 0;

		D_Touch->X = D_mos->X - RaderCenter_x;
		D_Touch->Y = RaderCenter_y - D_mos->Y;
		D_Touch->Length = sqrt(pow(D_Touch->X,2)+pow(D_Touch->Y,2));
		D_Touch->Radian = atan2(D_Touch->X,D_Touch->Y);			//弧度
		D_Touch->Angle = D_Touch->Radian*180/PI;				//角度

		if(D_mos->Touch == 0){
			Radar_Basic(RaderCenter_x , RaderCenter_y);
		}else if(D_mos->Touch == 1){
			if(D_Touch->Length < Rader_Radius){
				Radar_Basic(D_mos->X , D_mos->Y);

				if(e->Button == System::Windows::Forms::MouseButtons::Right){
					DrawArcInt(D_Touch->Length,D_Touch->Angle);
					D_mos->Right = 1;
				}
			}else{
				double x_Bor;		//雷達邊界x
				double y_Bor;		//雷達邊界y

				x_Bor = RaderCenter_x + Rader_Radius*sin(D_Touch->Radian);
				y_Bor = RaderCenter_y - Rader_Radius*cos(D_Touch->Radian);

				Radar_Basic(x_Bor , y_Bor);

				D_Touch->X = x_Bor - RaderCenter_x;
				D_Touch->Y = RaderCenter_y - y_Bor;

				double Radian_Bor = atan2(D_Touch->X , D_Touch->Y);			//弧度
				double Angle = Radian_Bor*180/PI;				//角度

				if(e->Button == System::Windows::Forms::MouseButtons::Right){
					DrawArcInt(Rader_Radius,Angle);
					D_Touch->Radian = Radian_Bor;
					D_mos->Right = 1;
				}
			}
			Write_Robot();

			//send();
		}
	}
	private: System::Void drawPB_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(D_mos->Touch == 0)	 Radar_Basic(RaderCenter_x , RaderCenter_y);
			 else if(D_mos->Touch == 1)  drawPB_mos(e);
		 }
	private: System::Void drawPB_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 D_mos->Touch = 1;									//確認滑鼠按下
			 drawPB_mos(e);
		 }
	private: System::Void drawPB_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 D_mos->Touch = 0;
			 D_mos->Right = 0;
			 D_Touch->X = 0;
			 D_Touch->Y = 0;
			 D_Touch->Radian = 0;
			 Write_Robot();
			 Read_Robot();
			 //send();
		 }
	private: System::Void Speed_Bar_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
			 Speed_lab->Text = System::Convert::ToString(Speed_Bar->Value);
		 }

// ===========================From part==========================

private: System::Void mapToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 mMap = gcnew Map();
			 mMap->Show();
		 }

private: System::Void furnitureToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 mFurniture = gcnew Furniture();
			 mFurniture->Show();
		 }

private: System::Void mapEditerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(mMapEditer==nullptr){
				 mMapEditer = gcnew MapEditer();
			 }
			 mMapEditer->Show();
		 }
private: System::Void lasertestToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 mLaserForm = gcnew TLaserForm();
			 mLaserForm->Show();
		 }
/*
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 if(Client_already){
					 if (Auto_check->Checked && ClientSocket->Connected){
						 fileName = "Robot_Command.xml";
						 ClientSocket->SendFile(fileName);
						 if(ClientSocket->Connected){
							 fileName = "Robot_Simulator.xml";
							 ClientSocket->SendFile(fileName);
						 }
						 D_Order->X = R_Robot->X;
						 D_Order->Y = R_Robot->Y;
						 D_Order->Radian = R_Robot->Radian;
					 }
					 Client_set->Text = "Close";
				 }
			 }catch(SocketException^){}
		 }
*/
private: System::Void Auto_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 Write_Robot();
			 if(Ctrl_check->Checked){
				 Ctrl_check->Checked = false;
			 }
		 }
private: System::Void Ctrl_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(Auto_check->Checked){
				 Auto_check->Checked = false;
			 }
		 }

private: System::Void btn_SysStop_Click(System::Object^  sender, System::EventArgs^  e) {
			 //motor stop command

		 }
private: System::Void Btn_SysStart_Click(System::Object^  sender, System::EventArgs^  e) {
			 //give end position
			 D_Database->EndPosition.x = D_Furniture->M_EndArea.x;
			 D_Database->EndPosition.y = D_Furniture->M_EndArea.y;

			 //start algorithm
			 NewNavigationSystem->NavigationSystem_Main();
		 }
};
}

