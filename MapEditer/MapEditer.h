#pragma once

#include "../Database.h"
#include <math.h>
#include <vector>
using namespace std;

struct asNode
{
	int x;
	int y;
	int f;
	int g;
	int h;
	int Weight;
	int clild_node;
	int close_node;
	int firther_x;
	int firther_y;
};

typedef vector <asNode> Vint;

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
	/// MapEditer 的摘要
	/// </summary>
	public ref class MapEditer : public System::Windows::Forms::Form
	{
	public:
		MapEditer(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			Map_Node = new asNode*[60];
			for(int x=0;x<60;x++) Map_Node[x] = new asNode[60];
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MapEditer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Map_Save;

	private: System::Windows::Forms::PictureBox^  Map_Ed;
	private: System::Windows::Forms::HScrollBar^  Light_HSB;
	private: System::Windows::Forms::Label^  Light_Box;
	private: System::Windows::Forms::CheckBox^  Thick_check;
	private: System::Windows::Forms::Button^  Map_Reset;
	private: System::Windows::Forms::Label^  Map_lab;
	private: System::Windows::Forms::Button^  Map_base;
	private: System::Windows::Forms::RadioButton^  BT_Start;
	private: System::Windows::Forms::RadioButton^  BT_End;
	private: System::Windows::Forms::Button^  BT_Search;
	private: System::Windows::Forms::Button^  Map_Expansion;
	
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		Bitmap^ mBMP;
		Graphics^ mGraphic;

		Bitmap^ mBMP_Map;
		Graphics^ mGraphic_Map;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->Map_Save = (gcnew System::Windows::Forms::Button());
			this->Map_Ed = (gcnew System::Windows::Forms::PictureBox());
			this->Light_HSB = (gcnew System::Windows::Forms::HScrollBar());
			this->Light_Box = (gcnew System::Windows::Forms::Label());
			this->Thick_check = (gcnew System::Windows::Forms::CheckBox());
			this->Map_Reset = (gcnew System::Windows::Forms::Button());
			this->Map_lab = (gcnew System::Windows::Forms::Label());
			this->Map_base = (gcnew System::Windows::Forms::Button());
			this->BT_Start = (gcnew System::Windows::Forms::RadioButton());
			this->BT_End = (gcnew System::Windows::Forms::RadioButton());
			this->BT_Search = (gcnew System::Windows::Forms::Button());
			this->Map_Expansion = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Map_Ed))->BeginInit();
			this->SuspendLayout();
			// 
			// Map_Save
			// 
			this->Map_Save->Location = System::Drawing::Point(274, -1);
			this->Map_Save->Name = L"Map_Save";
			this->Map_Save->Size = System::Drawing::Size(40, 20);
			this->Map_Save->TabIndex = 0;
			this->Map_Save->Text = L"Save";
			this->Map_Save->UseVisualStyleBackColor = true;
			this->Map_Save->Click += gcnew System::EventHandler(this, &MapEditer::Map_Save_Click);
			// 
			// Map_Ed
			// 
			this->Map_Ed->BackColor = System::Drawing::Color::White;
			this->Map_Ed->Cursor = System::Windows::Forms::Cursors::Cross;
			this->Map_Ed->Location = System::Drawing::Point(3, 21);
			this->Map_Ed->Margin = System::Windows::Forms::Padding(1);
			this->Map_Ed->Name = L"Map_Ed";
			this->Map_Ed->Size = System::Drawing::Size(601, 601);
			this->Map_Ed->TabIndex = 1;
			this->Map_Ed->TabStop = false;
			this->Map_Ed->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MapEditer::Map_Ed_MouseDown);
			this->Map_Ed->MouseLeave += gcnew System::EventHandler(this, &MapEditer::Map_Ed_MouseLeave);
			this->Map_Ed->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MapEditer::Map_Ed_MouseMove);
			this->Map_Ed->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MapEditer::Map_Ed_MouseUp);
			// 
			// Light_HSB
			// 
			this->Light_HSB->Location = System::Drawing::Point(145, 0);
			this->Light_HSB->Maximum = 264;
			this->Light_HSB->Name = L"Light_HSB";
			this->Light_HSB->Size = System::Drawing::Size(80, 19);
			this->Light_HSB->TabIndex = 3;
			this->Light_HSB->Value = 255;
			this->Light_HSB->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MapEditer::Light_HSB_Scroll);
			// 
			// Light_Box
			// 
			this->Light_Box->AutoSize = true;
			this->Light_Box->Location = System::Drawing::Point(77, 4);
			this->Light_Box->Name = L"Light_Box";
			this->Light_Box->Size = System::Drawing::Size(64, 12);
			this->Light_Box->TabIndex = 4;
			this->Light_Box->Text = L"Weights 255";
			// 
			// Thick_check
			// 
			this->Thick_check->AutoSize = true;
			this->Thick_check->Location = System::Drawing::Point(3, 3);
			this->Thick_check->Name = L"Thick_check";
			this->Thick_check->Size = System::Drawing::Size(71, 16);
			this->Thick_check->TabIndex = 5;
			this->Thick_check->Text = L"Thick pen";
			this->Thick_check->UseVisualStyleBackColor = true;
			// 
			// Map_Reset
			// 
			this->Map_Reset->Location = System::Drawing::Point(228, -1);
			this->Map_Reset->Name = L"Map_Reset";
			this->Map_Reset->Size = System::Drawing::Size(40, 20);
			this->Map_Reset->TabIndex = 6;
			this->Map_Reset->Text = L"Reset";
			this->Map_Reset->UseVisualStyleBackColor = true;
			this->Map_Reset->Click += gcnew System::EventHandler(this, &MapEditer::Map_Reset_Click);
			// 
			// Map_lab
			// 
			this->Map_lab->AutoSize = true;
			this->Map_lab->BackColor = System::Drawing::Color::Transparent;
			this->Map_lab->Location = System::Drawing::Point(10, 24);
			this->Map_lab->Name = L"Map_lab";
			this->Map_lab->Size = System::Drawing::Size(20, 12);
			this->Map_lab->TabIndex = 7;
			this->Map_lab->Text = L"0,0";
			this->Map_lab->Visible = false;
			// 
			// Map_base
			// 
			this->Map_base->Location = System::Drawing::Point(393, -1);
			this->Map_base->Name = L"Map_base";
			this->Map_base->Size = System::Drawing::Size(64, 20);
			this->Map_base->TabIndex = 8;
			this->Map_base->Text = L"Load_Map";
			this->Map_base->UseVisualStyleBackColor = true;
			this->Map_base->Click += gcnew System::EventHandler(this, &MapEditer::Map_base_Click);
			// 
			// BT_Start
			// 
			this->BT_Start->AutoCheck = false;
			this->BT_Start->AutoSize = true;
			this->BT_Start->Location = System::Drawing::Point(465, 1);
			this->BT_Start->Name = L"BT_Start";
			this->BT_Start->Size = System::Drawing::Size(43, 16);
			this->BT_Start->TabIndex = 9;
			this->BT_Start->Text = L"First";
			this->BT_Start->UseVisualStyleBackColor = true;
			this->BT_Start->Click += gcnew System::EventHandler(this, &MapEditer::BT_Start_Click);
			// 
			// BT_End
			// 
			this->BT_End->AutoCheck = false;
			this->BT_End->AutoSize = true;
			this->BT_End->Location = System::Drawing::Point(512, 1);
			this->BT_End->Name = L"BT_End";
			this->BT_End->Size = System::Drawing::Size(42, 16);
			this->BT_End->TabIndex = 10;
			this->BT_End->Text = L"End";
			this->BT_End->UseVisualStyleBackColor = true;
			this->BT_End->Click += gcnew System::EventHandler(this, &MapEditer::BT_End_Click);
			// 
			// BT_Search
			// 
			this->BT_Search->Location = System::Drawing::Point(560, -1);
			this->BT_Search->Name = L"BT_Search";
			this->BT_Search->Size = System::Drawing::Size(43, 20);
			this->BT_Search->TabIndex = 11;
			this->BT_Search->Text = L"Plan";
			this->BT_Search->UseVisualStyleBackColor = true;
			this->BT_Search->Click += gcnew System::EventHandler(this, &MapEditer::BT_Search_Click);
			// 
			// Map_Expansion
			// 
			this->Map_Expansion->Location = System::Drawing::Point(320, -1);
			this->Map_Expansion->Name = L"Map_Expansion";
			this->Map_Expansion->Size = System::Drawing::Size(65, 20);
			this->Map_Expansion->TabIndex = 12;
			this->Map_Expansion->Text = L"Expansion";
			this->Map_Expansion->UseVisualStyleBackColor = true;
			this->Map_Expansion->Click += gcnew System::EventHandler(this, &MapEditer::Map_Expansion_Click);
			// 
			// MapEditer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(609, 626);
			this->Controls->Add(this->Map_Expansion);
			this->Controls->Add(this->BT_Search);
			this->Controls->Add(this->BT_End);
			this->Controls->Add(this->BT_Start);
			this->Controls->Add(this->Map_base);
			this->Controls->Add(this->Map_lab);
			this->Controls->Add(this->Map_Reset);
			this->Controls->Add(this->Thick_check);
			this->Controls->Add(this->Light_Box);
			this->Controls->Add(this->Light_HSB);
			this->Controls->Add(this->Map_Save);
			this->Controls->Add(this->Map_Ed);
			this->Name = L"MapEditer";
			this->Text = L"MapEditer";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MapEditer::MapEditer_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MapEditer::MapEditer_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Map_Ed))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	int mos_click;
	int light;
	int mos_x;
	int mos_y;
	static int start_x=-1,start_y=-1,start_r,start_g,start_b;
	static int end_x=-1,end_y=-1,end_r,end_g,end_b;
	static int gray_num=0;
	asNode **Map_Node;
	int end_node_x;
	int end_node_y;
	int st_node_x;
	int st_node_y;

	private: System::Void MapEditer_Load(System::Object^  sender, System::EventArgs^  e) {
				 mos_click=0;
				 light = Light_HSB->Value;
				 Load_Map();
				 drawbase();
				 //Editer_witer();
			 }

///////////////////////////重新載入地圖///////////////////////////////////
	void Load_Map(){
		FileInfo^ fg = gcnew FileInfo("2013sksmap.bmp");

		FileStream^ fs = fg->OpenRead();

		mBMP_Map = gcnew Bitmap(fs);

		fs->Close();
	}
	
//正規化
	int Map_normal(int num){
		if(num<1)return 1;
		if(num>591) return 591;
		return num;
	}
//收尋地圖顏色
	void find_map(){
		for(int i=0;i<600;i+=10){
			for(int j=0;j<600;j+=10){
				find_Box(i,j);
			}
		}
		Map_Ed->Image = mBMP;
	}
	void find_Box(int x,int y){
		int draw_x,draw_y;
		int draw_w = 9;
		int check = 0;
		int i,j;
		SolidBrush^ blackBrush = gcnew SolidBrush( Color::FromArgb(0,0,0) );

		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				if(mBMP_Map->GetPixel(x+i,y+j).R == 255 & mBMP_Map->GetPixel(x+i,y+j).G == 255 & mBMP_Map->GetPixel(x+i,y+j).B == 255){
					draw_x = ((x+i)/10)*10+1;
					draw_y = ((y+j)/10)*10+1;
					mGraphic->FillRectangle(blackBrush,draw_x,draw_y,draw_w,draw_w);
					check = 1;
					break;
				}
			}
			if (check==1)	break;
		}
	}

//////////////////////////////////////////////////////////////////////////
	void drawbase(){
		mBMP = gcnew Bitmap(601,601);
		mGraphic = Graphics::FromImage(mBMP);

		SolidBrush^ whiteBrush = gcnew SolidBrush( Color::FromArgb( 255,255,255 ) );
		mGraphic->FillRectangle(whiteBrush,0,0,600,600);
		find_map();
		drawLine();

		Map_Ed->Image = mBMP;
	}
/////畫線格
	void drawLine(){
		Pen^ linePen = gcnew Pen(Color::DarkGreen, 1);
		for(int i=0 ; i<601; i+=10){
			mGraphic->DrawLine(linePen,i,0,i,600);
		}
		for(int i=0 ; i<601; i+=10){
			mGraphic->DrawLine(linePen,0,i,600,i);
		}
		mGraphic->DrawLine(linePen,600,0,600,600);
	}
/////填滿格子
	void drawBox(){
		int draw_x,draw_y;
		int draw_w = 9;

		draw_x = (mos_x/10)*10+1;
		draw_y = (mos_y/10)*10+1;

		SolidBrush^ WeightBrush = gcnew SolidBrush( Color::FromArgb( 255-light,255-light,255-light ) );
		SolidBrush^ GreenBrush = gcnew SolidBrush( Color::FromArgb( 0,255,0 ) );
		SolidBrush^ BlueBrush = gcnew SolidBrush( Color::FromArgb( 0,0,255 ) );

		SolidBrush^ startBrush = gcnew SolidBrush( Color::FromArgb( start_r,start_g,start_b ) );
		SolidBrush^ endBrush = gcnew SolidBrush( Color::FromArgb( end_r,end_g,end_b ) );

		if(BT_Start->Checked){
			if(draw_x!=start_x || draw_y!=start_y){
				start_r = mBMP->GetPixel(draw_x,draw_y).R;
				start_g = mBMP->GetPixel(draw_x,draw_y).G;
				start_b = mBMP->GetPixel(draw_x,draw_y).B;
				if(start_x!=-1 && start_y!=-1){
					mGraphic->FillRectangle(startBrush,start_x,start_y,draw_w,draw_w);
				}
				mGraphic->FillRectangle(GreenBrush,draw_x,draw_y,draw_w,draw_w);
				if(end_x>0 && end_y>0)
					mGraphic->FillRectangle(BlueBrush,end_x,end_y,draw_w,draw_w);
				start_x = draw_x;
				start_y = draw_y;
			}
		}else if(BT_End->Checked){
			if(draw_x!=end_x || draw_y!=end_y){
				end_r = mBMP->GetPixel(draw_x,draw_y).R;
				end_g = mBMP->GetPixel(draw_x,draw_y).G;
				end_b = mBMP->GetPixel(draw_x,draw_y).B;
				if(end_x!=-1 && end_y!=-1){
					mGraphic->FillRectangle(endBrush,end_x,end_y,draw_w,draw_w);
				}
				mGraphic->FillRectangle(BlueBrush,draw_x,draw_y,draw_w,draw_w);
				if(start_x>0 && start_y>0)
					mGraphic->FillRectangle(GreenBrush,start_x,start_y,draw_w,draw_w);
				end_x = draw_x;
				end_y = draw_y;
			}
		}else if(Thick_check->Checked){
			for(int i=-10;i<=10;i+=10){
				for(int j=-10;j<=10;j+=10){
					mGraphic->FillRectangle(WeightBrush,draw_x+i,draw_y+j,draw_w,draw_w);
				}
			}
		}else{
			mGraphic->FillRectangle(WeightBrush,draw_x,draw_y,draw_w,draw_w);
		}

		Map_Ed->Image = mBMP;
	}
	void drawExpansion(int num){
		int gray_x,gray_y;
		int draw_w = 9;
		int gray_light;
		int find_light;
		if(num==0){
			gray_light=127;
			find_light=0;
		}else if(num==1){
			gray_light=191;
			find_light=127;
		}else gray_light=255;

		SolidBrush^ GrayBrush = gcnew SolidBrush( Color::FromArgb(gray_light,gray_light,gray_light) );
		
		for(int x=1;x<600;x+=10){
			for(int y=1;y<600;y+=10){
				if(num==0 || num==1){
					if (mBMP->GetPixel(x,y).R == find_light && mBMP->GetPixel(x,y).G == find_light && mBMP->GetPixel(x,y).B == find_light){
						for(int a=-10;a<=10;a+=10){		//做灰階
							for(int b=-10;b<=10;b+=10){
								gray_x = Map_normal(x+a);
								gray_y = Map_normal(y+b);
								if(mBMP->GetPixel(gray_x,gray_y).R == 255 && mBMP->GetPixel(gray_x,gray_y).G == 255 && mBMP->GetPixel(gray_x,gray_y).B == 255)
									mGraphic->FillRectangle(GrayBrush,gray_x,gray_y,draw_w,draw_w);
							}
						}
					}
				}else{
					if (mBMP->GetPixel(x,y).R != 0 && mBMP->GetPixel(x,y).G != 0 && mBMP->GetPixel(x,y).B != 0){
						mGraphic->FillRectangle(GrayBrush,x,y,draw_w,draw_w);
					}
				}
			}
		}
		Map_Ed->Image = mBMP;
	}
/////////////////////////存入ＸＭＬ文件///////////////////////////////////
	void Map_Array(int x,int *Weighs){
		for(int y=0;y<60;y++){
			if(mBMP->GetPixel((x*10)+5,600-((y*10)+5)).R == mBMP->GetPixel((x*10)+5,600-((y*10)+5)).B && mBMP->GetPixel((x*10)+5,600-((y*10)+5)).R == mBMP->GetPixel((x*10)+5,600-((y*10)+5)).G)
				*(Weighs+y) = 255-mBMP->GetPixel((x*10)+5,600-((y*10)+5)).R;
			else
				*(Weighs+y) = 0;
		}
	}
	void Editer_witer(){
		int Map_Weights[60][60];

		for(int x=0;x<60;x++){
			Map_Array(x,Map_Weights[x]);
		}

		XmlDocument^ doc = gcnew XmlDocument();
		doc->Load("Robot_Config.xml");
		XmlNode^ Manual = doc->SelectSingleNode("/Config/GridMap"); //選擇節點
		Manual->RemoveAll();
		XmlElement^ element = (XmlElement^) Manual;
		XmlElement^ Grid_value;
		
		for(int x=0;x<60;x++){
			Grid_value = doc->CreateElement("value");
			for(int y=0;y<60;y++){
				Grid_value->SetAttribute("x"+System::Convert::ToString(x)+"y"+System::Convert::ToString(y),System::Convert::ToString(Map_Weights[x][y]));
				element->AppendChild(Grid_value);
			}
		}

		doc->Save("Robot_Config.xml");
	}

/////////////////////////讀取ＸＭＬ文件///////////////////////////////////
	void Editer_read(){
		XmlDocument^ doc = gcnew XmlDocument();
		doc->Load("Robot_Config.xml");
		int base_Weight;
		XmlNode^ Manual = doc->SelectSingleNode("/Config/GridMap"); //選擇節點
		XmlElement^ element = (XmlElement^) Manual;
		for(int x=0;x<Manual->ChildNodes->Count;x++){
			XmlNode^ Grid_value;
			Grid_value = element->ChildNodes[x];
			XmlElement^ a = (XmlElement^) Grid_value;
			for(int y=0;y<a->Attributes->Count;y++){
				base_Weight = System::Convert::ToDouble(a->Attributes[y]->Value);
				drawmap(base_Weight,x,y);
			}
		}
	}
//畫出讀入的數值
	void drawmap(int w,int x,int y){
		int M_x,M_y;
		int draw_w = 9;

		Map_Node[x][y].Weight=w;

		SolidBrush^ WeightBrush = gcnew SolidBrush( Color::FromArgb(255- w,255-w,255-w ) );
		M_x = x*10+1;
		M_y = 591-(y*10);
		mGraphic->FillRectangle(WeightBrush,M_x,M_y,draw_w,draw_w);
		
		Map_Ed->Image = mBMP;
	}


private: System::Void Map_Ed_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 int x,y;
				 mos_x = e->X;
				 mos_y = e->Y;
				 if(mos_click==1){
					 drawBox();
				 }
				 Map_lab->Location.X = mos_x;
				 Map_lab->Location.Y = mos_y;

				 x = (mos_x/10)*10+5;
				 y = (mos_y/10)*10+5;

				 if(x<0)x=0;
				 if(x>595)x=595;
				 if(y<0)y=0;
				 if(y>595)y=595;

				 Map_lab->Visible = true;
				 Map_lab->Text = System::Convert::ToString(x)+"," + System::Convert::ToString(600-y);
			 }
private: System::Void Map_Ed_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 mos_click = 1;
				 mos_x = e->X;
				 mos_y = e->Y;
				 if(BT_Start->Checked || BT_End->Checked){
					Editer_read();
				 }
				 drawBox();
			 }
private: System::Void Map_Ed_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 mos_click = 0;
			 }
private: System::Void Light_HSB_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
				 Light_Box->Text = "Weights " + System::Convert::ToString(Light_HSB->Value);
				 light = Light_HSB->Value;
			 }
private: System::Void Map_Save_Click(System::Object^  sender, System::EventArgs^  e) {
			 Editer_witer();
		 }
private: System::Void Map_Reset_Click(System::Object^  sender, System::EventArgs^  e) {
			 Editer_read();
			 start_x=-1;
			 start_y=-1;
			 end_x=-1;
			 end_y=-1;

		 }
private: System::Void Map_Ed_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 Map_lab->Visible = false;
		 }
private: System::Void MapEditer_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 this->Hide();
			 e->Cancel = true;
		 }
private: System::Void Map_base_Click(System::Object^  sender, System::EventArgs^  e) {
			 Load_Map();
			 drawbase();
		 }
private: System::Void BT_Start_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(BT_Start->Checked){
				 BT_Start->Checked = false;
			 }else{
				 BT_Start->Checked = true;
				 BT_End->Checked = false;
			 }
		 }
private: System::Void BT_End_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(BT_End->Checked){
				 BT_End->Checked = false;
			 }else{
				 BT_End->Checked = true;
				 BT_Start->Checked = false;
			 }
		 }
/////////////////////////////Ａ＿Ｓｔａｒ/////////////////////////////////
	void draw_road(int x, int y){
		int road_x;
		int road_y;

		road_x = (Map_Node[x][y].firther_x*10)+1;
		road_y = ((59-Map_Node[x][y].firther_y)*10)+1;
		
		SolidBrush^ RedBrush = gcnew SolidBrush( Color::FromArgb( 255,0,0 ) );
		int draw_w = 9;
		if(Map_Node[x][y].clild_node==1){
			if (road_x!=(st_node_x*10+1) || road_y!=((59-st_node_y)*10+1))
			{
				mGraphic->FillRectangle(RedBrush,road_x,road_y,draw_w,draw_w);
			}
		}
		if(Map_Node[Map_Node[x][y].firther_x][Map_Node[x][y].firther_y].clild_node==1){
			draw_road(Map_Node[x][y].firther_x,Map_Node[x][y].firther_y);
		}
		Map_Ed->Image = mBMP;

	}
	void a_star(Vint &OpenNode,int ch_x,int ch_y){
		Map_Node[ch_x][ch_y].close_node=1;
		int f_x,f_y;
		int num=0;
		int cost;
		
		for(int x=-1;x<2;x++){
			for(int y=-1;y<2;y++){
				f_x = ch_x+x;
				f_y = ch_y+y;
				if(f_x<0)f_x=0;
				else if(f_x>59)f_x=59;
				if(f_y<0)f_y=0;
				else if(f_y>59)f_y=59;

				cost =(num%2==0)?14 :10;

				if(Map_Node[f_x][f_y].Weight!=255 && Map_Node[f_x][f_y].close_node==0){
					if(Map_Node[f_x][f_y].clild_node==0){
						Map_Node[f_x][f_y].clild_node = 1;
						Map_Node[f_x][f_y].firther_x = ch_x;
						Map_Node[f_x][f_y].firther_y = ch_y;
						Map_Node[f_x][f_y].h = (((f_x>end_node_x)?f_x-end_node_x :end_node_x-f_x) + ((f_y>end_node_y)?f_y-end_node_y :end_node_y-f_y))*10;
						Map_Node[f_x][f_y].g = Map_Node[ch_x][ch_y].g + cost;
						Map_Node[f_x][f_y].f = Map_Node[f_x][f_y].g + Map_Node[f_x][f_y].h + Map_Node[f_x][f_y].Weight;

						if (OpenNode.empty()){
							OpenNode.push_back(Map_Node[f_x][f_y]);
						}else{
							if(OpenNode.size()>90) OpenNode.erase(OpenNode.begin());
							for(int i=0 ; i<OpenNode.size() ;i++){
								if (Map_Node[f_x][f_y].f>OpenNode[i].f){
									OpenNode.insert( OpenNode.begin()+i,Map_Node[f_x][f_y]);
									break;
								}
								if(i==(OpenNode.size()-1)){
									if (Map_Node[f_x][f_y].f <= OpenNode[i].f){
										OpenNode.insert( OpenNode.end(),Map_Node[f_x][f_y]);
									}
									break;
								}
							}
						}
					}else if(Map_Node[f_x][f_y].clild_node==1){
						if(Map_Node[f_x][f_y].f > (Map_Node[f_x][f_y].h + Map_Node[ch_x][ch_y].g + cost + Map_Node[f_x][f_y].Weight)){
							Map_Node[f_x][f_y].g = Map_Node[ch_x][ch_y].g + cost;
							Map_Node[f_x][f_y].f = Map_Node[f_x][f_y].g + Map_Node[f_x][f_y].h + Map_Node[f_x][f_y].Weight;
							Map_Node[f_x][f_y].firther_x = ch_x;
							Map_Node[f_x][f_y].firther_y = ch_y;

							for(int i=0 ; i<OpenNode.size() ;i++){
								if (OpenNode[i].x == f_x && OpenNode[i].y == f_y){
									OpenNode.erase(OpenNode.begin()+i);
								}
							}
							for(int i=0 ; i<OpenNode.size() ;i++){
								if (Map_Node[f_x][f_y].f>OpenNode[i].f){
									OpenNode.insert( OpenNode.begin()+i,Map_Node[f_x][f_y]);
									break;
								}
								if(i==(OpenNode.size()-1)){
									if (Map_Node[f_x][f_y].f <= OpenNode[i].f){
										OpenNode.insert( OpenNode.end(),Map_Node[f_x][f_y]);
									}
									break;
								}
							}
						}
					}
				}
				num++;
			}
		}
	}
		 
private: System::Void BT_Search_Click(System::Object^  sender, System::EventArgs^  e) {
			 Vint OpenNode;
			
			 for(int x=0;x<60;x++){
				 for (int y=0;y<60;y++)
				 {
					 Map_Node[x][y].x = x;
					 Map_Node[x][y].y = y;
					 Map_Node[x][y].f=0;
					 Map_Node[x][y].g=0;
					 Map_Node[x][y].h=0;
					 Map_Node[x][y].clild_node=0;
					 Map_Node[x][y].close_node=0;
					 Map_Node[x][y].firther_x=0;
					 Map_Node[x][y].firther_y=0;
				 }
			 }
			 st_node_x = start_x/10;
			 st_node_y = (600-start_y)/10;
			 end_node_x = end_x/10;
			 end_node_y = (600-end_y)/10;
			 Map_Node[st_node_x][st_node_y].g = 0;

			 a_star(OpenNode,st_node_x,st_node_y);

			 int ch_x;
			 int ch_y;
			 while (true){
				 if(OpenNode.empty()) break;
				 ch_x = OpenNode[OpenNode.size()-1].x;
				 ch_y = OpenNode[OpenNode.size()-1].y;
				 if(ch_x == end_node_x && ch_y==end_node_y){
					 draw_road(ch_x,ch_y);
					 break;
				 }
				 OpenNode.pop_back();
				 a_star(OpenNode,ch_x,ch_y);
			 }
		 }
private: System::Void Map_Expansion_Click(System::Object^  sender, System::EventArgs^  e) {
			 drawExpansion(gray_num);
			 if(gray_num<2)gray_num++;
			 else gray_num=0;
		 }
};
}
