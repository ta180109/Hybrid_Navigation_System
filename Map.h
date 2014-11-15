#pragma once

#include <math.h>
#include "Database.h"

// double* LivingRM_Table = gcnew double [4];  //可全域的辦法
namespace SKS_VC2013 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Xml;
	using namespace System::IO;
	/// <summary>
	/// Map 的摘要
	/// </summary>
	public ref class Map : public System::Windows::Forms::Form
	{
	public:
		Map(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			
		}
	private: System::Windows::Forms::Label^  Sim_X;
	public: 
	private: System::Windows::Forms::Label^  Sim_Y;
	private: System::Windows::Forms::Label^  Sim_Sita;
	private: System::Windows::Forms::CheckBox^  Re_Movement;
	private: System::Windows::Forms::ComboBox^  Furniture_Box;
	private: System::Windows::Forms::ComboBox^  Ang_CB;
	private: System::Windows::Forms::Button^  Map_Save;
	private: System::Windows::Forms::ComboBox^  Spa_CB;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckBox^  Re_Position;
	private: System::Windows::Forms::ListBox^  SimLaserShow;
	private: System::Windows::Forms::GroupBox^  groupBox2;






	private: System::Windows::Forms::Timer^  timer1;
	public: 
		


	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Map()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  drawMap;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  Laser_box;

	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		Bitmap^ mBMP;
		Bitmap^ mBMP_base;
		Graphics^ mGraphic;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Map::typeid));
			this->drawMap = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Spa_CB = (gcnew System::Windows::Forms::ComboBox());
			this->Ang_CB = (gcnew System::Windows::Forms::ComboBox());
			this->Laser_box = (gcnew System::Windows::Forms::CheckBox());
			this->Re_Movement = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Sim_X = (gcnew System::Windows::Forms::Label());
			this->Sim_Y = (gcnew System::Windows::Forms::Label());
			this->Sim_Sita = (gcnew System::Windows::Forms::Label());
			this->Furniture_Box = (gcnew System::Windows::Forms::ComboBox());
			this->Map_Save = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Re_Position = (gcnew System::Windows::Forms::CheckBox());
			this->SimLaserShow = (gcnew System::Windows::Forms::ListBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->drawMap))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// drawMap
			// 
			this->drawMap->ErrorImage = nullptr;
			this->drawMap->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"drawMap.Image")));
			this->drawMap->Location = System::Drawing::Point(2, 52);
			this->drawMap->Name = L"drawMap";
			this->drawMap->Size = System::Drawing::Size(600, 600);
			this->drawMap->TabIndex = 0;
			this->drawMap->TabStop = false;
			this->drawMap->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Map::drawMap_MouseDown);
			this->drawMap->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Map::drawMap_MouseMove);
			this->drawMap->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Map::drawMap_MouseUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(77, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 12);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Angle";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(163, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 12);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Spacing";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Spa_CB);
			this->groupBox1->Controls->Add(this->Ang_CB);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->Laser_box);
			this->groupBox1->Location = System::Drawing::Point(173, -1);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(250, 47);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"S_Laser";
			// 
			// Spa_CB
			// 
			this->Spa_CB->FormattingEnabled = true;
			this->Spa_CB->Location = System::Drawing::Point(208, 20);
			this->Spa_CB->Name = L"Spa_CB";
			this->Spa_CB->Size = System::Drawing::Size(42, 20);
			this->Spa_CB->TabIndex = 8;
			this->Spa_CB->Text = L"10";
			this->Spa_CB->SelectedIndexChanged += gcnew System::EventHandler(this, &Map::Spa_CB_SelectedIndexChanged);
			// 
			// Ang_CB
			// 
			this->Ang_CB->FormattingEnabled = true;
			this->Ang_CB->Location = System::Drawing::Point(116, 21);
			this->Ang_CB->Name = L"Ang_CB";
			this->Ang_CB->Size = System::Drawing::Size(41, 20);
			this->Ang_CB->TabIndex = 11;
			this->Ang_CB->Text = L"180";
			this->Ang_CB->SelectedIndexChanged += gcnew System::EventHandler(this, &Map::Ang_CB_SelectedIndexChanged);
			// 
			// Laser_box
			// 
			this->Laser_box->AutoSize = true;
			this->Laser_box->Location = System::Drawing::Point(2, 21);
			this->Laser_box->Name = L"Laser_box";
			this->Laser_box->Size = System::Drawing::Size(76, 16);
			this->Laser_box->TabIndex = 10;
			this->Laser_box->TabStop = false;
			this->Laser_box->Text = L"Map_Laser";
			this->Laser_box->UseVisualStyleBackColor = true;
			// 
			// Re_Movement
			// 
			this->Re_Movement->AutoSize = true;
			this->Re_Movement->Location = System::Drawing::Point(6, 14);
			this->Re_Movement->Name = L"Re_Movement";
			this->Re_Movement->Size = System::Drawing::Size(74, 16);
			this->Re_Movement->TabIndex = 5;
			this->Re_Movement->Text = L"Movement";
			this->Re_Movement->UseVisualStyleBackColor = true;
			this->Re_Movement->CheckedChanged += gcnew System::EventHandler(this, &Map::Re_Movement_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Map::timer1_Tick);
			// 
			// Sim_X
			// 
			this->Sim_X->AutoSize = true;
			this->Sim_X->Location = System::Drawing::Point(86, 15);
			this->Sim_X->Name = L"Sim_X";
			this->Sim_X->Size = System::Drawing::Size(25, 12);
			this->Sim_X->TabIndex = 2;
			this->Sim_X->Text = L"X：";
			// 
			// Sim_Y
			// 
			this->Sim_Y->AutoSize = true;
			this->Sim_Y->Location = System::Drawing::Point(86, 32);
			this->Sim_Y->Name = L"Sim_Y";
			this->Sim_Y->Size = System::Drawing::Size(25, 12);
			this->Sim_Y->TabIndex = 3;
			this->Sim_Y->Text = L"Y：";
			// 
			// Sim_Sita
			// 
			this->Sim_Sita->AutoSize = true;
			this->Sim_Sita->Location = System::Drawing::Point(139, 15);
			this->Sim_Sita->Name = L"Sim_Sita";
			this->Sim_Sita->Size = System::Drawing::Size(34, 12);
			this->Sim_Sita->TabIndex = 4;
			this->Sim_Sita->Text = L"Sita：";
			// 
			// Furniture_Box
			// 
			this->Furniture_Box->FormattingEnabled = true;
			this->Furniture_Box->Items->AddRange(gcnew cli::array< System::Object^  >(13) {L"None", L"LivingRM_Sofa", L"LivingRM_Table", 
				L"LivingRM_Cabinet", L"DiningRM_Table", L"DiningRM_Chair", L"Library_Desk", L"Library_Chair", L"Library_Cabinet", L"BedRM_Bed", 
				L"Trashcan", L"ChargeArea", L"EndArea"});
			this->Furniture_Box->Location = System::Drawing::Point(53, 18);
			this->Furniture_Box->Name = L"Furniture_Box";
			this->Furniture_Box->Size = System::Drawing::Size(116, 20);
			this->Furniture_Box->TabIndex = 6;
			this->Furniture_Box->Text = L"None";
			// 
			// Map_Save
			// 
			this->Map_Save->Location = System::Drawing::Point(2, 2);
			this->Map_Save->Name = L"Map_Save";
			this->Map_Save->Size = System::Drawing::Size(45, 37);
			this->Map_Save->TabIndex = 7;
			this->Map_Save->Text = L"Save";
			this->Map_Save->UseVisualStyleBackColor = true;
			this->Map_Save->Click += gcnew System::EventHandler(this, &Map::Map_Save_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(54, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 12);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Setting Furniture";
			// 
			// Re_Position
			// 
			this->Re_Position->AutoSize = true;
			this->Re_Position->Location = System::Drawing::Point(6, 28);
			this->Re_Position->Name = L"Re_Position";
			this->Re_Position->Size = System::Drawing::Size(61, 16);
			this->Re_Position->TabIndex = 9;
			this->Re_Position->Text = L"Position";
			this->Re_Position->UseVisualStyleBackColor = true;
			this->Re_Position->CheckedChanged += gcnew System::EventHandler(this, &Map::Re_Position_CheckedChanged);
			// 
			// SimLaserShow
			// 
			this->SimLaserShow->FormattingEnabled = true;
			this->SimLaserShow->ItemHeight = 12;
			this->SimLaserShow->Location = System::Drawing::Point(608, 52);
			this->SimLaserShow->Name = L"SimLaserShow";
			this->SimLaserShow->Size = System::Drawing::Size(259, 592);
			this->SimLaserShow->TabIndex = 10;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Re_Movement);
			this->groupBox2->Controls->Add(this->Re_Position);
			this->groupBox2->Controls->Add(this->Sim_Y);
			this->groupBox2->Controls->Add(this->Sim_X);
			this->groupBox2->Controls->Add(this->Sim_Sita);
			this->groupBox2->Location = System::Drawing::Point(429, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(219, 44);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"R_Robot Status";
			// 
			// Map
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(902, 662);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->SimLaserShow);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Map_Save);
			this->Controls->Add(this->Furniture_Box);
			this->Controls->Add(this->drawMap);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Map";
			this->Text = L"Map";
			this->Load += gcnew System::EventHandler(this, &Map::Map_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->drawMap))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//***************參數宣告*******************//
	double Rec_Angle;
	double Rec_Length;
	int mos_click;
	int mos_x,mos_y;
//******************************************//
private: System::Void Map_Load(System::Object^  sender, System::EventArgs^  e) {
				 drawMap->Width  = Map_Width;
				 drawMap->Height = Map_Height;

				 int num;
				 for(num=0;num<=270;num++) Ang_CB->Items->Add(num);
				 for(num=10;num<=20;num++) Spa_CB->Items->Add(num);
				

				 D_Robot->X_tar = D_Robot->X + D_Robot->R/2;
				 D_Robot->Y_tar = D_Robot->Y;
				 D_Robot->Angle = atan2(D_Robot->Y_tar - D_Robot->Y,D_Robot->X_tar - D_Robot->X)*PI/180;

				 D_Robot->Wheel = 10*PI;
				 D_Range->Angle = 180;
				 D_Range->Spa = 10;
				 
				 drawRobot();

				 timer1->Start();
			 }
///////////////////////機器人繪製區///////////////////////////////////////
public: void drawRobot(){
				 mBMP  = gcnew Bitmap("SKS_2013MAP.bmp"); //背景和框繪製區
				 mGraphic   = Graphics::FromImage(mBMP);

				 Read_Object();
				 double wheel_dis = D_Robot->Wheel*cos(30*PI/180);
				 
				 if(D_Order->X !=0 || D_Order->Y !=0 || D_Order->Radian !=0){
					 Rec_Angle = atan2(D_Order->X,D_Order->Y)*180/PI;			//前進的向量角度
					 Rec_Length = sqrt(pow(D_Order->X,2)+pow(D_Order->Y,2));  	//前進的向量長度
					 Rec_Length = Rec_Length/60;
					 if(D_Order->Radian != 0){
						 D_Robot->Angle = D_Robot->Angle - (D_Order->Radian*180/PI)/100;			//自轉
						 if(D_Robot->Angle < -180) D_Robot->Angle = D_Robot->Angle + 360;
						 else if(D_Robot->Angle > 180) D_Robot->Angle = D_Robot->Angle - 360;
					 }else{
						 D_Robot->X = D_Robot->X + (Rec_Length*wheel_dis*cos((D_Robot->Angle-Rec_Angle)*PI/180))/100;
						 D_Robot->Y = D_Robot->Y - (Rec_Length*wheel_dis*sin((D_Robot->Angle-Rec_Angle)*PI/180))/100;
					 }
				 }
				 //writeSimulator();

				 double r = (D_Robot->R/2);

				 D_Robot->X_tar = D_Robot->X + r*cos(D_Robot->Angle*PI/180);
				 D_Robot->Y_tar = D_Robot->Y - r*sin(D_Robot->Angle*PI/180);

				 Pen^ bluePen = gcnew Pen(Color::Blue, 3);
				 SolidBrush^ HotPinkBrush = gcnew SolidBrush( Color::HotPink );
				 
				 mGraphic->FillPie(HotPinkBrush,(int)D_Robot->X -r ,(int)D_Robot->Y -r ,(int) D_Robot->R ,(int)D_Robot->R,(int) 0,(int) 360 );
				 mGraphic->DrawLine(bluePen,(int)D_Robot->X,(int)D_Robot->Y , (int)D_Robot->X_tar , (int)D_Robot->Y_tar);
				 
				 if(Laser_box->Checked)
					 scanning();

// 				 for(int i=0;i<Map_Width;i++){
// 					 for(int j=0;j<Map_Height;j++){
// 						 if(mBMP->GetPixel(i,j) == Color::White){
// 							 mBMP->SetPixel(i,j,Color::Black);
// 						 }else if(mBMP->GetPixel(i,j) == Color::Black){
// 							 mBMP->SetPixel(i,j,Color::White);
// 						 }
// 					 }
// 				 }
				 drawMap->Image = mBMP;
			 }
// 		void writeSimulator(){
// 			if(Re_Movement->Checked || Re_Position->Checked){
// 				if(R_Position->x!=0 || R_Position->y!=0 || R_Position->ang!=0){
// 					D_Robot->X = R_Position->x;
// 					D_Robot->Y = Map_Height - R_Position->y;
// 					D_Robot->Angle = R_Position->ang;
// 				}
// 				try{
// 					XmlDocument^ doc = gcnew XmlDocument();
// 					doc->Load("Robot_Simulator.xml");
// 					XmlNode^ Manual = doc->SelectSingleNode("/Simulator/Sim_Position");
// 					XmlElement^ element=(XmlElement^)Manual;
// 
// 					element->SetAttribute("x",System::Convert::ToString(D_Robot->X));
// 					element->SetAttribute("y",System::Convert::ToString(Map_Height-D_Robot->Y));
// 					element->SetAttribute("sita",System::Convert::ToString(D_Robot->Angle));
// 
// 					doc->Save("Robot_Simulator.xml");
// 				}catch (IOException^){
// 				}
// 			}
// 		}
/////////////////////////家具繪製區///////////////////////////////////////
void Read_Object(){
		drawObject(D_Furniture->M_LivingRM.Sofa,0);
		drawObject(D_Furniture->M_LivingRM.Table,1);
		drawObject(D_Furniture->M_LivingRM.Cabinet,2);
		drawObject(D_Furniture->M_DiningRM.Table,3);
		drawObject(D_Furniture->M_DiningRM.Chair,4);
		drawObject(D_Furniture->M_Library.Desk,5);
		drawObject(D_Furniture->M_Library.Chair,6);
		drawObject(D_Furniture->M_Library.Cabinet,7);
		drawObject(D_Furniture->M_BedRM.Bed,8);
		drawObject(D_Furniture->M_DiningRM.door,9);
		drawObject(D_Furniture->M_BedRM.door,10);
		//drawObject(D_Furniture->M_ChargeArea,11);
		//drawObject(D_Furniture->M_EndArea,12);
		drawObject(D_Furniture->M_Trashcan,13);
		mBMP_base = mBMP;
	}
void drawObject(Furniture_site object,int num){
		Pen^ whitePen = gcnew Pen( Color::White,object.Width );
		Pen^ blcakPen = gcnew Pen( Color::Black,object.Width );
		Pen^ redPen = gcnew Pen( Color::Red,object.Width );
		Pen^ yellowPen = gcnew Pen( Color::Yellow,object.Width );
		double x_sin,y_cos;
		int i,temp;
		int a_x,a_y,b_x,b_y;
		int _w;

		a_x = object.x + (object.Width/2);
		a_y = object.y;
		x_sin = sin(object.Angle*PI/180);
		y_cos = cos(object.Angle*PI/180);
		b_x = a_x + object.Height*x_sin;
		b_y = a_y + object.Height*y_cos;
		temp = (object.Width>object.Height)? object.Height : object.Width;
		if(num == 11)	mGraphic->DrawLine(yellowPen , (int)a_x , (int)a_y , (int)b_x , (int)b_y);
		else if(num == 12)	mGraphic->DrawLine(redPen , (int)a_x , (int)a_y , (int)b_x , (int)b_y);
		else if(num == 13){
			SolidBrush^ TrashcanBrush = gcnew SolidBrush( Color::Black);
			mGraphic->FillPie(TrashcanBrush,(int)object.x ,(int)object.y ,(int)object.Width ,(int)object.Height,(int) 0,(int) 360 );
		}else{
			mGraphic->DrawLine(blcakPen , (int)a_x , (int)a_y , (int)b_x , (int)b_y);
			_w = (((int)object.Angle%90 )==0) ?object.Width :object.Width+2;
			if(num == 0){
				_w = (((int)object.Angle%90 )==0) ?55 :55+3;
				Pen^ WhitePen = gcnew Pen( Color::White,_w );
				mGraphic->DrawLine(WhitePen , (int)(a_x+12.5*y_cos + 15*x_sin) , (int)(a_y -12.5*x_sin + 15*y_cos) , (int)(b_x+12.5*y_cos - 15*x_sin) , (int)(b_y-12.5*x_sin - 15*y_cos));
			}else if(num == 3){
				Pen^ WhitePen = gcnew Pen( Color::White,_w );
				Pen^ WhitePen2 = gcnew Pen( Color::White,object.Width-20 );
				mGraphic->DrawLine(WhitePen , (int)(a_x + 10*x_sin) , (int)(a_y + 10*y_cos) , (int)(b_x - 10*x_sin) , (int)(b_y - 10*y_cos));
				mGraphic->DrawLine(WhitePen2 , (int)(a_x - 5*x_sin) , (int)(a_y - 5*y_cos) , (int)(b_x + 5*x_sin) , (int)(b_y + 5*y_cos));
			}else if(num == 5){
				Pen^ whitePen = gcnew Pen( Color::White,_w );
				mGraphic->DrawLine(whitePen , (int)(a_x + 3*x_sin) , (int)(a_y + 3*y_cos) , (int)(b_x - 30*x_sin) , (int)(b_y - 30*y_cos));
			}
		}
	}

void DrawTurnPoint(){
		SolidBrush^ TurnpointColor = gcnew SolidBrush( Color::Orange );
		Pen^ RedPen = gcnew Pen( Color::Red,2 );
		TCoordinate Tmp;
		for(int i = 0;i < D_Database->TurnPoint.size(); i++){
			mGraphic->FillPie(TurnpointColor,(int)D_Database->TurnPoint[i].x-5 , (Map_Height - (int)D_Database->TurnPoint[i].y)-5 ,10 ,10,(int) 0,(int) 360 );
			if(i==0){
				Tmp.x = 30;
				Tmp.y = Map_Height-270;
			}else{
				Tmp.x = (int)D_Database->TurnPoint[i-1].x;
				Tmp.y = Map_Height-(int)D_Database->TurnPoint[i-1].y;
			}
			mGraphic->DrawLine(RedPen , (int)D_Database->TurnPoint[i].x ,  (Map_Height - (int)D_Database->TurnPoint[i].y) , Tmp.x , Tmp.y);
		}
		drawMap->Image = mBMP;
	}


	private: void scanning(){

				 int num =  D_Range->Angle/D_Range->Spa + 1;
				 array<double> ^Laser_dis = gcnew array<double>(num); 
	

				 double fmap_x,fmap_y;
				 double map_x,map_y;
				 int Ra=2;
				 double tar;
				 double f_tar;
				 Pen^ orangePen = gcnew Pen(Color::OrangeRed, 1);
				 int i=0;
				 f_tar = (D_Robot->Angle + D_Range->Angle/2) * PI / 180;
				 tar = (D_Robot->Angle - D_Range->Angle/2) * PI / 180;

				 while(tar<=f_tar){
					 map_x = D_Robot->X + (D_Robot->R/2)*cos(tar);
					 map_y = D_Robot->Y - (D_Robot->R/2)*sin(tar);
					 fmap_x = map_x;
					 fmap_y = map_y;

					 while(fmap_x <= Map_Width){
						 map_x = map_x + Ra*cos(tar);
						 map_y = map_y - Ra*sin(tar);
						 if(map_x>Map_Width-1) map_x=Map_Width-1;
						 if(map_y>Map_Height-1) map_y=Map_Height-1;
						 
						 if(mBMP->GetPixel(map_x,map_y).R == 0 & mBMP->GetPixel(map_x,map_y).G == 0 & mBMP->GetPixel(map_x,map_y).B == 0) break;
					 }
					 if(Laser_box->Checked)
						 mGraphic->DrawLine(orangePen , (int)fmap_x , (int)fmap_y , (int)map_x , (int)map_y);
					 
					 Sim_Laser[i].Distance = sqrt(pow(map_y-fmap_y,2)+pow(map_x-fmap_x,2));
					 
					 i++;
					 tar = tar + (D_Range->Spa*PI/180);
				 }
				 
				 for(int k = i; k--; k>0)
					 this->SimLaserShow->Items->Add("Linenum " + k + " : " + Sim_Laser[k].Distance );
					 
				 

				 drawMap->Image = mBMP;
			 }
//障礙物判定
private: int Obst(int x , int y){		
			 int a = 0;
			 int i=0;
			 double f_x,f_y;
			 while(i<360){
				f_x = D_Robot->X + (D_Robot->R/2) * cos(i*PI/180);
				f_y = D_Robot->Y - (D_Robot->R/2) * sin(i*PI/180);
				i+=5;
				if(f_x > 0 && f_x< Map_Width && f_y > 0 && f_y < Map_Height){
					if(mBMP->GetPixel(f_x,f_y).R == 255 & mBMP->GetPixel(f_x,f_y).G == 255 & mBMP->GetPixel(f_x,f_y).B == 255)  a=1;
				}
				
			 }
			 return a;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 drawRobot();
			 DrawTurnPoint();
			 Sim_X->Text = "X：" + System::Convert::ToString((int)R_Robot->X);
			 Sim_Y->Text = "Y：" +System::Convert::ToString((int)R_Robot->Y);
			 Sim_Sita->Text = "Sita：" +System::Convert::ToString((int)R_Robot->Radian);
		 }

private: System::Void drawMap_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 mos_click = 1;
			 mos_x = e->X;
			 mos_y = e->Y;
			 TouchObject(e);
		 }
private: System::Void drawMap_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 mos_click = 0;
		 }
private: System::Void drawMap_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 mos_x = e->X;
			 mos_y = e->Y;
			 if (mos_click==1){
				 TouchObject(e);
			 }
		 }
void TouchObject(System::Windows::Forms::MouseEventArgs^  e){
		if(Furniture_Box->SelectedText == "LivingRM_Sofa"){
			ChangeObject(D_Furniture->M_LivingRM.Sofa,e);
		}else if (Furniture_Box->SelectedText == "LivingRM_Table"){
			ChangeObject(D_Furniture->M_LivingRM.Table,e);
		}else if (Furniture_Box->SelectedText == "LivingRM_Cabinet"){
			ChangeObject(D_Furniture->M_LivingRM.Cabinet,e);
		}else if (Furniture_Box->SelectedText == "DiningRM_Table"){
			ChangeObject(D_Furniture->M_DiningRM.Table,e);
		}else if (Furniture_Box->SelectedText == "DiningRM_Chair"){
			ChangeObject(D_Furniture->M_DiningRM.Chair,e);
		}else if (Furniture_Box->SelectedText == "Library_Desk"){
			ChangeObject(D_Furniture->M_Library.Desk,e);
		}else if (Furniture_Box->SelectedText == "Library_Chair"){
			ChangeObject(D_Furniture->M_Library.Chair,e);
		}else if (Furniture_Box->SelectedText == "Library_Cabinet"){
			ChangeObject(D_Furniture->M_Library.Cabinet,e);
		}else if (Furniture_Box->SelectedText == "BedRM_Bed"){
			ChangeObject(D_Furniture->M_BedRM.Bed,e);
		}else if (Furniture_Box->SelectedText == "Trashcan"){
				ChangeObject(D_Furniture->M_Trashcan,e);
// 			}else if (Furniture_Box->SelectedText == "ChargeArea"){
// 				ChangeObject(D_Furniture->M_ChargeArea,e);
// 			}else if (Furniture_Box->SelectedText == "EndArea"){
// 				ChangeObject(D_Furniture->M_EndArea,e);
		}
	}
void ChangeObject(Furniture_site &object , System::Windows::Forms::MouseEventArgs^  e){
		int ang;
		ang = object.Angle;
		if(e->Button == System::Windows::Forms::MouseButtons::Right){
			object.Angle =(ang<270) ?ang+90 :ang-270;
		}else{
			object.x = mos_x;
			object.y = mos_y;
		}
	}

private: System::Void Map_Save_Click(System::Object^  sender, System::EventArgs^  e) {
			 mBMP  = gcnew Bitmap("SKS_2013MAP.bmp"); //background and border draw
			 mGraphic   = Graphics::FromImage(mBMP);
			 Read_Object();
			 if(mBMP_base != nullptr)
			 mBMP_base->Save("2013sksmap.bmp");
		}
private: System::Void Ang_CB_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 D_Range->Angle = System::Convert::ToInt32(Ang_CB->Text);
		 }
private: System::Void Spa_CB_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 D_Range->Spa = System::Convert::ToInt32(Spa_CB->Text);
		 }
private: System::Void Re_Position_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 Robot_Request("Position");
		 }
private: System::Void Re_Movement_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 Robot_Request("Movement");
		 }
};
}