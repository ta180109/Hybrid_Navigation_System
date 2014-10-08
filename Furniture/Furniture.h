#pragma once

#include "../Database.h"

namespace SKS_VC2013 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Xml;
	/// <summary>
	/// Furniture 的摘要
	/// </summary>
	public ref class Furniture : public System::Windows::Forms::Form
	{
	public:
		Furniture(void)
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
		~Furniture()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  Liv_Sofa1;
	protected: 

	private: System::Windows::Forms::TextBox^  Liv_Sofa2;
	private: System::Windows::Forms::TextBox^  Liv_Sofa3;
	private: System::Windows::Forms::TextBox^  Liv_Sofa4;
	private: System::Windows::Forms::TextBox^  Liv_Sofa5;
	protected: 

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  Liv_Table5;
	private: System::Windows::Forms::TextBox^  Liv_Table4;
	private: System::Windows::Forms::TextBox^  Liv_Table3;
	private: System::Windows::Forms::TextBox^  Liv_Table2;
	private: System::Windows::Forms::TextBox^  Liv_Table1;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  Liv_Cabinet5;
	private: System::Windows::Forms::TextBox^  Liv_Cabinet4;
	private: System::Windows::Forms::TextBox^  Liv_Cabinet3;
	private: System::Windows::Forms::TextBox^  Liv_Cabinet2;
	private: System::Windows::Forms::TextBox^  Liv_Cabinet1;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  Din_Table5;
	private: System::Windows::Forms::TextBox^  Din_Table4;
	private: System::Windows::Forms::TextBox^  Din_Table3;
	private: System::Windows::Forms::TextBox^  Din_Table2;
	private: System::Windows::Forms::TextBox^  Din_Table1;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  Din_Chair5;
	private: System::Windows::Forms::TextBox^  Din_Chair4;
	private: System::Windows::Forms::TextBox^  Din_Chair3;
	private: System::Windows::Forms::TextBox^  Din_Chair2;
	private: System::Windows::Forms::TextBox^  Din_Chair1;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  Lib_Desk5;
	private: System::Windows::Forms::TextBox^  Lib_Desk4;
	private: System::Windows::Forms::TextBox^  Lib_Desk3;
	private: System::Windows::Forms::TextBox^  Lib_Desk2;
	private: System::Windows::Forms::TextBox^  Lib_Desk1;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  Lib_Chair5;
	private: System::Windows::Forms::TextBox^  Lib_Chair4;
	private: System::Windows::Forms::TextBox^  Lib_Chair3;
	private: System::Windows::Forms::TextBox^  Lib_Chair2;
	private: System::Windows::Forms::TextBox^  Lib_Chair1;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  Lib_Cabinet5;
	private: System::Windows::Forms::TextBox^  Lib_Cabinet4;
	private: System::Windows::Forms::TextBox^  Lib_Cabinet3;
	private: System::Windows::Forms::TextBox^  Lib_Cabinet2;
	private: System::Windows::Forms::TextBox^  Lib_Cabinet1;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  Bed5;
	private: System::Windows::Forms::TextBox^  Bed4;
	private: System::Windows::Forms::TextBox^  Bed3;
	private: System::Windows::Forms::TextBox^  Bed2;
	private: System::Windows::Forms::TextBox^  Bed1;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  Din_door5;
	private: System::Windows::Forms::TextBox^  Din_door4;
	private: System::Windows::Forms::TextBox^  Din_door3;
	private: System::Windows::Forms::TextBox^  Din_door2;
	private: System::Windows::Forms::TextBox^  Din_door1;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  Bed_door5;
	private: System::Windows::Forms::TextBox^  Bed_door4;
	private: System::Windows::Forms::TextBox^  Bed_door3;
	private: System::Windows::Forms::TextBox^  Bed_door2;
	private: System::Windows::Forms::TextBox^  Bed_door1;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  ChargeArea5;
	private: System::Windows::Forms::TextBox^  ChargeArea4;
	private: System::Windows::Forms::TextBox^  ChargeArea3;
	private: System::Windows::Forms::TextBox^  ChargeArea2;
	private: System::Windows::Forms::TextBox^  ChargeArea1;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  EndArea5;
	private: System::Windows::Forms::TextBox^  EndArea4;
	private: System::Windows::Forms::TextBox^  EndArea3;
	private: System::Windows::Forms::TextBox^  EndArea2;
	private: System::Windows::Forms::TextBox^  EndArea1;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Button^  Save_set;

	private: System::Windows::Forms::Button^  Reset_set;
private: System::Windows::Forms::TextBox^  Trashcan1;
private: System::Windows::Forms::TextBox^  Trashcan2;
private: System::Windows::Forms::TextBox^  Trashcan3;
private: System::Windows::Forms::TextBox^  Trashcan4;
private: System::Windows::Forms::TextBox^  Trashcan5;
private: System::Windows::Forms::Label^  label19;

	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->Liv_Sofa1 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Sofa2 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Sofa3 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Sofa4 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Sofa5 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Liv_Table5 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Table4 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Table3 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Table2 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Table1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Liv_Cabinet5 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Cabinet4 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Cabinet3 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Cabinet2 = (gcnew System::Windows::Forms::TextBox());
			this->Liv_Cabinet1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Din_Table5 = (gcnew System::Windows::Forms::TextBox());
			this->Din_Table4 = (gcnew System::Windows::Forms::TextBox());
			this->Din_Table3 = (gcnew System::Windows::Forms::TextBox());
			this->Din_Table2 = (gcnew System::Windows::Forms::TextBox());
			this->Din_Table1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Din_Chair5 = (gcnew System::Windows::Forms::TextBox());
			this->Din_Chair4 = (gcnew System::Windows::Forms::TextBox());
			this->Din_Chair3 = (gcnew System::Windows::Forms::TextBox());
			this->Din_Chair2 = (gcnew System::Windows::Forms::TextBox());
			this->Din_Chair1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Lib_Desk5 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Desk4 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Desk3 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Desk2 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Desk1 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Lib_Chair5 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Chair4 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Chair3 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Chair2 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Chair1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Lib_Cabinet5 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Cabinet4 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Cabinet3 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Cabinet2 = (gcnew System::Windows::Forms::TextBox());
			this->Lib_Cabinet1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->Bed5 = (gcnew System::Windows::Forms::TextBox());
			this->Bed4 = (gcnew System::Windows::Forms::TextBox());
			this->Bed3 = (gcnew System::Windows::Forms::TextBox());
			this->Bed2 = (gcnew System::Windows::Forms::TextBox());
			this->Bed1 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Din_door5 = (gcnew System::Windows::Forms::TextBox());
			this->Din_door4 = (gcnew System::Windows::Forms::TextBox());
			this->Din_door3 = (gcnew System::Windows::Forms::TextBox());
			this->Din_door2 = (gcnew System::Windows::Forms::TextBox());
			this->Din_door1 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->Bed_door5 = (gcnew System::Windows::Forms::TextBox());
			this->Bed_door4 = (gcnew System::Windows::Forms::TextBox());
			this->Bed_door3 = (gcnew System::Windows::Forms::TextBox());
			this->Bed_door2 = (gcnew System::Windows::Forms::TextBox());
			this->Bed_door1 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->ChargeArea5 = (gcnew System::Windows::Forms::TextBox());
			this->ChargeArea4 = (gcnew System::Windows::Forms::TextBox());
			this->ChargeArea3 = (gcnew System::Windows::Forms::TextBox());
			this->ChargeArea2 = (gcnew System::Windows::Forms::TextBox());
			this->ChargeArea1 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->EndArea5 = (gcnew System::Windows::Forms::TextBox());
			this->EndArea4 = (gcnew System::Windows::Forms::TextBox());
			this->EndArea3 = (gcnew System::Windows::Forms::TextBox());
			this->EndArea2 = (gcnew System::Windows::Forms::TextBox());
			this->EndArea1 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->Trashcan1 = (gcnew System::Windows::Forms::TextBox());
			this->Trashcan2 = (gcnew System::Windows::Forms::TextBox());
			this->Trashcan3 = (gcnew System::Windows::Forms::TextBox());
			this->Trashcan4 = (gcnew System::Windows::Forms::TextBox());
			this->Trashcan5 = (gcnew System::Windows::Forms::TextBox());
			this->Save_set = (gcnew System::Windows::Forms::Button());
			this->Reset_set = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Liv_Sofa1
			// 
			this->Liv_Sofa1->Location = System::Drawing::Point(3, 3);
			this->Liv_Sofa1->Name = L"Liv_Sofa1";
			this->Liv_Sofa1->Size = System::Drawing::Size(50, 22);
			this->Liv_Sofa1->TabIndex = 0;
			this->Liv_Sofa1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Sofa2
			// 
			this->Liv_Sofa2->Location = System::Drawing::Point(59, 3);
			this->Liv_Sofa2->Name = L"Liv_Sofa2";
			this->Liv_Sofa2->Size = System::Drawing::Size(50, 22);
			this->Liv_Sofa2->TabIndex = 1;
			this->Liv_Sofa2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Sofa3
			// 
			this->Liv_Sofa3->Location = System::Drawing::Point(115, 3);
			this->Liv_Sofa3->Name = L"Liv_Sofa3";
			this->Liv_Sofa3->Size = System::Drawing::Size(50, 22);
			this->Liv_Sofa3->TabIndex = 2;
			this->Liv_Sofa3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Sofa4
			// 
			this->Liv_Sofa4->Location = System::Drawing::Point(171, 3);
			this->Liv_Sofa4->Name = L"Liv_Sofa4";
			this->Liv_Sofa4->Size = System::Drawing::Size(50, 22);
			this->Liv_Sofa4->TabIndex = 3;
			this->Liv_Sofa4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Sofa5
			// 
			this->Liv_Sofa5->Location = System::Drawing::Point(227, 3);
			this->Liv_Sofa5->Name = L"Liv_Sofa5";
			this->Liv_Sofa5->Size = System::Drawing::Size(50, 22);
			this->Liv_Sofa5->TabIndex = 4;
			this->Liv_Sofa5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 12);
			this->label1->TabIndex = 5;
			this->label1->Text = L"LivingRM_Sofa";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 12);
			this->label2->TabIndex = 11;
			this->label2->Text = L"LivingRM_Table";
			// 
			// Liv_Table5
			// 
			this->Liv_Table5->Location = System::Drawing::Point(227, 31);
			this->Liv_Table5->Name = L"Liv_Table5";
			this->Liv_Table5->Size = System::Drawing::Size(50, 22);
			this->Liv_Table5->TabIndex = 10;
			this->Liv_Table5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Table4
			// 
			this->Liv_Table4->Location = System::Drawing::Point(171, 31);
			this->Liv_Table4->Name = L"Liv_Table4";
			this->Liv_Table4->Size = System::Drawing::Size(50, 22);
			this->Liv_Table4->TabIndex = 9;
			this->Liv_Table4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Table3
			// 
			this->Liv_Table3->Location = System::Drawing::Point(115, 31);
			this->Liv_Table3->Name = L"Liv_Table3";
			this->Liv_Table3->Size = System::Drawing::Size(50, 22);
			this->Liv_Table3->TabIndex = 8;
			this->Liv_Table3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Table2
			// 
			this->Liv_Table2->Location = System::Drawing::Point(59, 31);
			this->Liv_Table2->Name = L"Liv_Table2";
			this->Liv_Table2->Size = System::Drawing::Size(50, 22);
			this->Liv_Table2->TabIndex = 7;
			this->Liv_Table2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Table1
			// 
			this->Liv_Table1->Location = System::Drawing::Point(3, 31);
			this->Liv_Table1->Name = L"Liv_Table1";
			this->Liv_Table1->Size = System::Drawing::Size(50, 22);
			this->Liv_Table1->TabIndex = 6;
			this->Liv_Table1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 12);
			this->label3->TabIndex = 17;
			this->label3->Text = L"LivingRM_Cabinet";
			// 
			// Liv_Cabinet5
			// 
			this->Liv_Cabinet5->Location = System::Drawing::Point(227, 59);
			this->Liv_Cabinet5->Name = L"Liv_Cabinet5";
			this->Liv_Cabinet5->Size = System::Drawing::Size(50, 22);
			this->Liv_Cabinet5->TabIndex = 16;
			this->Liv_Cabinet5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Cabinet4
			// 
			this->Liv_Cabinet4->Location = System::Drawing::Point(171, 59);
			this->Liv_Cabinet4->Name = L"Liv_Cabinet4";
			this->Liv_Cabinet4->Size = System::Drawing::Size(50, 22);
			this->Liv_Cabinet4->TabIndex = 15;
			this->Liv_Cabinet4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Cabinet3
			// 
			this->Liv_Cabinet3->Location = System::Drawing::Point(115, 59);
			this->Liv_Cabinet3->Name = L"Liv_Cabinet3";
			this->Liv_Cabinet3->Size = System::Drawing::Size(50, 22);
			this->Liv_Cabinet3->TabIndex = 14;
			this->Liv_Cabinet3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Cabinet2
			// 
			this->Liv_Cabinet2->Location = System::Drawing::Point(59, 59);
			this->Liv_Cabinet2->Name = L"Liv_Cabinet2";
			this->Liv_Cabinet2->Size = System::Drawing::Size(50, 22);
			this->Liv_Cabinet2->TabIndex = 13;
			this->Liv_Cabinet2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Liv_Cabinet1
			// 
			this->Liv_Cabinet1->Location = System::Drawing::Point(3, 59);
			this->Liv_Cabinet1->Name = L"Liv_Cabinet1";
			this->Liv_Cabinet1->Size = System::Drawing::Size(50, 22);
			this->Liv_Cabinet1->TabIndex = 12;
			this->Liv_Cabinet1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 119);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 12);
			this->label4->TabIndex = 23;
			this->label4->Text = L"DiningRM_Table";
			// 
			// Din_Table5
			// 
			this->Din_Table5->Location = System::Drawing::Point(227, 87);
			this->Din_Table5->Name = L"Din_Table5";
			this->Din_Table5->Size = System::Drawing::Size(50, 22);
			this->Din_Table5->TabIndex = 22;
			this->Din_Table5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_Table4
			// 
			this->Din_Table4->Location = System::Drawing::Point(171, 87);
			this->Din_Table4->Name = L"Din_Table4";
			this->Din_Table4->Size = System::Drawing::Size(50, 22);
			this->Din_Table4->TabIndex = 21;
			this->Din_Table4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_Table3
			// 
			this->Din_Table3->Location = System::Drawing::Point(115, 87);
			this->Din_Table3->Name = L"Din_Table3";
			this->Din_Table3->Size = System::Drawing::Size(50, 22);
			this->Din_Table3->TabIndex = 20;
			this->Din_Table3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_Table2
			// 
			this->Din_Table2->Location = System::Drawing::Point(59, 87);
			this->Din_Table2->Name = L"Din_Table2";
			this->Din_Table2->Size = System::Drawing::Size(50, 22);
			this->Din_Table2->TabIndex = 19;
			this->Din_Table2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_Table1
			// 
			this->Din_Table1->Location = System::Drawing::Point(3, 87);
			this->Din_Table1->Name = L"Din_Table1";
			this->Din_Table1->Size = System::Drawing::Size(50, 22);
			this->Din_Table1->TabIndex = 18;
			this->Din_Table1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 147);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 12);
			this->label5->TabIndex = 29;
			this->label5->Text = L"DiningRM_Chair";
			// 
			// Din_Chair5
			// 
			this->Din_Chair5->Location = System::Drawing::Point(227, 115);
			this->Din_Chair5->Name = L"Din_Chair5";
			this->Din_Chair5->Size = System::Drawing::Size(50, 22);
			this->Din_Chair5->TabIndex = 28;
			this->Din_Chair5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_Chair4
			// 
			this->Din_Chair4->Location = System::Drawing::Point(171, 115);
			this->Din_Chair4->Name = L"Din_Chair4";
			this->Din_Chair4->Size = System::Drawing::Size(50, 22);
			this->Din_Chair4->TabIndex = 27;
			this->Din_Chair4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_Chair3
			// 
			this->Din_Chair3->Location = System::Drawing::Point(115, 115);
			this->Din_Chair3->Name = L"Din_Chair3";
			this->Din_Chair3->Size = System::Drawing::Size(50, 22);
			this->Din_Chair3->TabIndex = 26;
			this->Din_Chair3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_Chair2
			// 
			this->Din_Chair2->Location = System::Drawing::Point(59, 115);
			this->Din_Chair2->Name = L"Din_Chair2";
			this->Din_Chair2->Size = System::Drawing::Size(50, 22);
			this->Din_Chair2->TabIndex = 25;
			this->Din_Chair2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_Chair1
			// 
			this->Din_Chair1->Location = System::Drawing::Point(3, 115);
			this->Din_Chair1->Name = L"Din_Chair1";
			this->Din_Chair1->Size = System::Drawing::Size(50, 22);
			this->Din_Chair1->TabIndex = 24;
			this->Din_Chair1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 175);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(69, 12);
			this->label6->TabIndex = 35;
			this->label6->Text = L"Library_Desk";
			// 
			// Lib_Desk5
			// 
			this->Lib_Desk5->Location = System::Drawing::Point(227, 143);
			this->Lib_Desk5->Name = L"Lib_Desk5";
			this->Lib_Desk5->Size = System::Drawing::Size(50, 22);
			this->Lib_Desk5->TabIndex = 34;
			this->Lib_Desk5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Desk4
			// 
			this->Lib_Desk4->Location = System::Drawing::Point(171, 143);
			this->Lib_Desk4->Name = L"Lib_Desk4";
			this->Lib_Desk4->Size = System::Drawing::Size(50, 22);
			this->Lib_Desk4->TabIndex = 33;
			this->Lib_Desk4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Desk3
			// 
			this->Lib_Desk3->Location = System::Drawing::Point(115, 143);
			this->Lib_Desk3->Name = L"Lib_Desk3";
			this->Lib_Desk3->Size = System::Drawing::Size(50, 22);
			this->Lib_Desk3->TabIndex = 32;
			this->Lib_Desk3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Desk2
			// 
			this->Lib_Desk2->Location = System::Drawing::Point(59, 143);
			this->Lib_Desk2->Name = L"Lib_Desk2";
			this->Lib_Desk2->Size = System::Drawing::Size(50, 22);
			this->Lib_Desk2->TabIndex = 31;
			this->Lib_Desk2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Desk1
			// 
			this->Lib_Desk1->Location = System::Drawing::Point(3, 143);
			this->Lib_Desk1->Name = L"Lib_Desk1";
			this->Lib_Desk1->Size = System::Drawing::Size(50, 22);
			this->Lib_Desk1->TabIndex = 30;
			this->Lib_Desk1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 203);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 12);
			this->label7->TabIndex = 41;
			this->label7->Text = L"Library_Chair";
			// 
			// Lib_Chair5
			// 
			this->Lib_Chair5->Location = System::Drawing::Point(227, 171);
			this->Lib_Chair5->Name = L"Lib_Chair5";
			this->Lib_Chair5->Size = System::Drawing::Size(50, 22);
			this->Lib_Chair5->TabIndex = 40;
			this->Lib_Chair5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Chair4
			// 
			this->Lib_Chair4->Location = System::Drawing::Point(171, 171);
			this->Lib_Chair4->Name = L"Lib_Chair4";
			this->Lib_Chair4->Size = System::Drawing::Size(50, 22);
			this->Lib_Chair4->TabIndex = 39;
			this->Lib_Chair4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Chair3
			// 
			this->Lib_Chair3->Location = System::Drawing::Point(115, 171);
			this->Lib_Chair3->Name = L"Lib_Chair3";
			this->Lib_Chair3->Size = System::Drawing::Size(50, 22);
			this->Lib_Chair3->TabIndex = 38;
			this->Lib_Chair3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Chair2
			// 
			this->Lib_Chair2->Location = System::Drawing::Point(59, 171);
			this->Lib_Chair2->Name = L"Lib_Chair2";
			this->Lib_Chair2->Size = System::Drawing::Size(50, 22);
			this->Lib_Chair2->TabIndex = 37;
			this->Lib_Chair2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Chair1
			// 
			this->Lib_Chair1->Location = System::Drawing::Point(3, 171);
			this->Lib_Chair1->Name = L"Lib_Chair1";
			this->Lib_Chair1->Size = System::Drawing::Size(50, 22);
			this->Lib_Chair1->TabIndex = 36;
			this->Lib_Chair1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 231);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(82, 12);
			this->label8->TabIndex = 47;
			this->label8->Text = L"Library_Cabinet";
			// 
			// Lib_Cabinet5
			// 
			this->Lib_Cabinet5->Location = System::Drawing::Point(227, 199);
			this->Lib_Cabinet5->Name = L"Lib_Cabinet5";
			this->Lib_Cabinet5->Size = System::Drawing::Size(50, 22);
			this->Lib_Cabinet5->TabIndex = 46;
			this->Lib_Cabinet5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Cabinet4
			// 
			this->Lib_Cabinet4->Location = System::Drawing::Point(171, 199);
			this->Lib_Cabinet4->Name = L"Lib_Cabinet4";
			this->Lib_Cabinet4->Size = System::Drawing::Size(50, 22);
			this->Lib_Cabinet4->TabIndex = 45;
			this->Lib_Cabinet4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Cabinet3
			// 
			this->Lib_Cabinet3->Location = System::Drawing::Point(115, 199);
			this->Lib_Cabinet3->Name = L"Lib_Cabinet3";
			this->Lib_Cabinet3->Size = System::Drawing::Size(50, 22);
			this->Lib_Cabinet3->TabIndex = 44;
			this->Lib_Cabinet3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Cabinet2
			// 
			this->Lib_Cabinet2->Location = System::Drawing::Point(59, 199);
			this->Lib_Cabinet2->Name = L"Lib_Cabinet2";
			this->Lib_Cabinet2->Size = System::Drawing::Size(50, 22);
			this->Lib_Cabinet2->TabIndex = 43;
			this->Lib_Cabinet2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Lib_Cabinet1
			// 
			this->Lib_Cabinet1->Location = System::Drawing::Point(3, 199);
			this->Lib_Cabinet1->Name = L"Lib_Cabinet1";
			this->Lib_Cabinet1->Size = System::Drawing::Size(50, 22);
			this->Lib_Cabinet1->TabIndex = 42;
			this->Lib_Cabinet1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 259);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(67, 12);
			this->label9->TabIndex = 53;
			this->label9->Text = L"BedRM_Bed";
			// 
			// Bed5
			// 
			this->Bed5->Location = System::Drawing::Point(227, 227);
			this->Bed5->Name = L"Bed5";
			this->Bed5->Size = System::Drawing::Size(50, 22);
			this->Bed5->TabIndex = 52;
			this->Bed5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Bed4
			// 
			this->Bed4->Location = System::Drawing::Point(171, 227);
			this->Bed4->Name = L"Bed4";
			this->Bed4->Size = System::Drawing::Size(50, 22);
			this->Bed4->TabIndex = 51;
			this->Bed4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Bed3
			// 
			this->Bed3->Location = System::Drawing::Point(115, 227);
			this->Bed3->Name = L"Bed3";
			this->Bed3->Size = System::Drawing::Size(50, 22);
			this->Bed3->TabIndex = 50;
			this->Bed3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Bed2
			// 
			this->Bed2->Location = System::Drawing::Point(59, 227);
			this->Bed2->Name = L"Bed2";
			this->Bed2->Size = System::Drawing::Size(50, 22);
			this->Bed2->TabIndex = 49;
			this->Bed2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Bed1
			// 
			this->Bed1->Location = System::Drawing::Point(3, 227);
			this->Bed1->Name = L"Bed1";
			this->Bed1->Size = System::Drawing::Size(50, 22);
			this->Bed1->TabIndex = 48;
			this->Bed1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 287);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(83, 12);
			this->label10->TabIndex = 59;
			this->label10->Text = L"DiningRM_door";
			// 
			// Din_door5
			// 
			this->Din_door5->Location = System::Drawing::Point(227, 255);
			this->Din_door5->Name = L"Din_door5";
			this->Din_door5->Size = System::Drawing::Size(50, 22);
			this->Din_door5->TabIndex = 58;
			this->Din_door5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_door4
			// 
			this->Din_door4->Location = System::Drawing::Point(171, 255);
			this->Din_door4->Name = L"Din_door4";
			this->Din_door4->Size = System::Drawing::Size(50, 22);
			this->Din_door4->TabIndex = 57;
			this->Din_door4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_door3
			// 
			this->Din_door3->Location = System::Drawing::Point(115, 255);
			this->Din_door3->Name = L"Din_door3";
			this->Din_door3->Size = System::Drawing::Size(50, 22);
			this->Din_door3->TabIndex = 56;
			this->Din_door3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_door2
			// 
			this->Din_door2->Location = System::Drawing::Point(59, 255);
			this->Din_door2->Name = L"Din_door2";
			this->Din_door2->Size = System::Drawing::Size(50, 22);
			this->Din_door2->TabIndex = 55;
			this->Din_door2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Din_door1
			// 
			this->Din_door1->Location = System::Drawing::Point(3, 255);
			this->Din_door1->Name = L"Din_door1";
			this->Din_door1->Size = System::Drawing::Size(50, 22);
			this->Din_door1->TabIndex = 54;
			this->Din_door1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 315);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(70, 12);
			this->label11->TabIndex = 65;
			this->label11->Text = L"BedRM_door";
			// 
			// Bed_door5
			// 
			this->Bed_door5->Location = System::Drawing::Point(227, 283);
			this->Bed_door5->Name = L"Bed_door5";
			this->Bed_door5->Size = System::Drawing::Size(50, 22);
			this->Bed_door5->TabIndex = 64;
			this->Bed_door5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Bed_door4
			// 
			this->Bed_door4->Location = System::Drawing::Point(171, 283);
			this->Bed_door4->Name = L"Bed_door4";
			this->Bed_door4->Size = System::Drawing::Size(50, 22);
			this->Bed_door4->TabIndex = 63;
			this->Bed_door4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Bed_door3
			// 
			this->Bed_door3->Location = System::Drawing::Point(115, 283);
			this->Bed_door3->Name = L"Bed_door3";
			this->Bed_door3->Size = System::Drawing::Size(50, 22);
			this->Bed_door3->TabIndex = 62;
			this->Bed_door3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Bed_door2
			// 
			this->Bed_door2->Location = System::Drawing::Point(59, 283);
			this->Bed_door2->Name = L"Bed_door2";
			this->Bed_door2->Size = System::Drawing::Size(50, 22);
			this->Bed_door2->TabIndex = 61;
			this->Bed_door2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Bed_door1
			// 
			this->Bed_door1->Location = System::Drawing::Point(3, 283);
			this->Bed_door1->Name = L"Bed_door1";
			this->Bed_door1->Size = System::Drawing::Size(50, 22);
			this->Bed_door1->TabIndex = 60;
			this->Bed_door1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 343);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(61, 12);
			this->label12->TabIndex = 71;
			this->label12->Text = L"ChargeArea";
			// 
			// ChargeArea5
			// 
			this->ChargeArea5->Location = System::Drawing::Point(227, 311);
			this->ChargeArea5->Name = L"ChargeArea5";
			this->ChargeArea5->Size = System::Drawing::Size(50, 22);
			this->ChargeArea5->TabIndex = 70;
			this->ChargeArea5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ChargeArea4
			// 
			this->ChargeArea4->Location = System::Drawing::Point(171, 311);
			this->ChargeArea4->Name = L"ChargeArea4";
			this->ChargeArea4->Size = System::Drawing::Size(50, 22);
			this->ChargeArea4->TabIndex = 69;
			this->ChargeArea4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ChargeArea3
			// 
			this->ChargeArea3->Location = System::Drawing::Point(115, 311);
			this->ChargeArea3->Name = L"ChargeArea3";
			this->ChargeArea3->Size = System::Drawing::Size(50, 22);
			this->ChargeArea3->TabIndex = 68;
			this->ChargeArea3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ChargeArea2
			// 
			this->ChargeArea2->Location = System::Drawing::Point(59, 311);
			this->ChargeArea2->Name = L"ChargeArea2";
			this->ChargeArea2->Size = System::Drawing::Size(50, 22);
			this->ChargeArea2->TabIndex = 67;
			this->ChargeArea2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ChargeArea1
			// 
			this->ChargeArea1->Location = System::Drawing::Point(3, 311);
			this->ChargeArea1->Name = L"ChargeArea1";
			this->ChargeArea1->Size = System::Drawing::Size(50, 22);
			this->ChargeArea1->TabIndex = 66;
			this->ChargeArea1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 371);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(46, 12);
			this->label13->TabIndex = 77;
			this->label13->Text = L"EndArea";
			// 
			// EndArea5
			// 
			this->EndArea5->Location = System::Drawing::Point(227, 339);
			this->EndArea5->Name = L"EndArea5";
			this->EndArea5->Size = System::Drawing::Size(50, 22);
			this->EndArea5->TabIndex = 76;
			this->EndArea5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// EndArea4
			// 
			this->EndArea4->Location = System::Drawing::Point(171, 339);
			this->EndArea4->Name = L"EndArea4";
			this->EndArea4->Size = System::Drawing::Size(50, 22);
			this->EndArea4->TabIndex = 75;
			this->EndArea4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// EndArea3
			// 
			this->EndArea3->Location = System::Drawing::Point(115, 339);
			this->EndArea3->Name = L"EndArea3";
			this->EndArea3->Size = System::Drawing::Size(50, 22);
			this->EndArea3->TabIndex = 74;
			this->EndArea3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// EndArea2
			// 
			this->EndArea2->Location = System::Drawing::Point(59, 339);
			this->EndArea2->Name = L"EndArea2";
			this->EndArea2->Size = System::Drawing::Size(50, 22);
			this->EndArea2->TabIndex = 73;
			this->EndArea2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// EndArea1
			// 
			this->EndArea1->Location = System::Drawing::Point(3, 339);
			this->EndArea1->Name = L"EndArea1";
			this->EndArea1->Size = System::Drawing::Size(50, 22);
			this->EndArea1->TabIndex = 72;
			this->EndArea1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label14->Location = System::Drawing::Point(123, 7);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(20, 16);
			this->label14->TabIndex = 78;
			this->label14->Text = L"X";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label15->Location = System::Drawing::Point(177, 7);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(20, 16);
			this->label15->TabIndex = 79;
			this->label15->Text = L"Y";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label16->Location = System::Drawing::Point(220, 7);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(51, 16);
			this->label16->TabIndex = 80;
			this->label16->Text = L"Width";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label17->Location = System::Drawing::Point(273, 7);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(56, 16);
			this->label17->TabIndex = 81;
			this->label17->Text = L"Height";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label18->Location = System::Drawing::Point(332, 7);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(51, 16);
			this->label18->TabIndex = 82;
			this->label18->Text = L"Angle";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->Liv_Sofa1);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Sofa2);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Sofa3);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Sofa4);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Sofa5);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Table1);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Table2);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Table3);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Table4);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Table5);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Cabinet1);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Cabinet2);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Cabinet3);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Cabinet4);
			this->flowLayoutPanel1->Controls->Add(this->Liv_Cabinet5);
			this->flowLayoutPanel1->Controls->Add(this->Din_Table1);
			this->flowLayoutPanel1->Controls->Add(this->Din_Table2);
			this->flowLayoutPanel1->Controls->Add(this->Din_Table3);
			this->flowLayoutPanel1->Controls->Add(this->Din_Table4);
			this->flowLayoutPanel1->Controls->Add(this->Din_Table5);
			this->flowLayoutPanel1->Controls->Add(this->Din_Chair1);
			this->flowLayoutPanel1->Controls->Add(this->Din_Chair2);
			this->flowLayoutPanel1->Controls->Add(this->Din_Chair3);
			this->flowLayoutPanel1->Controls->Add(this->Din_Chair4);
			this->flowLayoutPanel1->Controls->Add(this->Din_Chair5);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Desk1);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Desk2);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Desk3);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Desk4);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Desk5);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Chair1);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Chair2);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Chair3);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Chair4);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Chair5);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Cabinet1);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Cabinet2);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Cabinet3);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Cabinet4);
			this->flowLayoutPanel1->Controls->Add(this->Lib_Cabinet5);
			this->flowLayoutPanel1->Controls->Add(this->Bed1);
			this->flowLayoutPanel1->Controls->Add(this->Bed2);
			this->flowLayoutPanel1->Controls->Add(this->Bed3);
			this->flowLayoutPanel1->Controls->Add(this->Bed4);
			this->flowLayoutPanel1->Controls->Add(this->Bed5);
			this->flowLayoutPanel1->Controls->Add(this->Din_door1);
			this->flowLayoutPanel1->Controls->Add(this->Din_door2);
			this->flowLayoutPanel1->Controls->Add(this->Din_door3);
			this->flowLayoutPanel1->Controls->Add(this->Din_door4);
			this->flowLayoutPanel1->Controls->Add(this->Din_door5);
			this->flowLayoutPanel1->Controls->Add(this->Bed_door1);
			this->flowLayoutPanel1->Controls->Add(this->Bed_door2);
			this->flowLayoutPanel1->Controls->Add(this->Bed_door3);
			this->flowLayoutPanel1->Controls->Add(this->Bed_door4);
			this->flowLayoutPanel1->Controls->Add(this->Bed_door5);
			this->flowLayoutPanel1->Controls->Add(this->ChargeArea1);
			this->flowLayoutPanel1->Controls->Add(this->ChargeArea2);
			this->flowLayoutPanel1->Controls->Add(this->ChargeArea3);
			this->flowLayoutPanel1->Controls->Add(this->ChargeArea4);
			this->flowLayoutPanel1->Controls->Add(this->ChargeArea5);
			this->flowLayoutPanel1->Controls->Add(this->EndArea1);
			this->flowLayoutPanel1->Controls->Add(this->EndArea2);
			this->flowLayoutPanel1->Controls->Add(this->EndArea3);
			this->flowLayoutPanel1->Controls->Add(this->EndArea4);
			this->flowLayoutPanel1->Controls->Add(this->EndArea5);
			this->flowLayoutPanel1->Controls->Add(this->Trashcan1);
			this->flowLayoutPanel1->Controls->Add(this->Trashcan2);
			this->flowLayoutPanel1->Controls->Add(this->Trashcan3);
			this->flowLayoutPanel1->Controls->Add(this->Trashcan4);
			this->flowLayoutPanel1->Controls->Add(this->Trashcan5);
			this->flowLayoutPanel1->Location = System::Drawing::Point(105, 29);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(280, 395);
			this->flowLayoutPanel1->TabIndex = 83;
			// 
			// Trashcan1
			// 
			this->Trashcan1->Location = System::Drawing::Point(3, 367);
			this->Trashcan1->Name = L"Trashcan1";
			this->Trashcan1->Size = System::Drawing::Size(50, 22);
			this->Trashcan1->TabIndex = 77;
			this->Trashcan1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Trashcan2
			// 
			this->Trashcan2->Location = System::Drawing::Point(59, 367);
			this->Trashcan2->Name = L"Trashcan2";
			this->Trashcan2->Size = System::Drawing::Size(50, 22);
			this->Trashcan2->TabIndex = 87;
			this->Trashcan2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Trashcan3
			// 
			this->Trashcan3->Location = System::Drawing::Point(115, 367);
			this->Trashcan3->Name = L"Trashcan3";
			this->Trashcan3->Size = System::Drawing::Size(50, 22);
			this->Trashcan3->TabIndex = 88;
			this->Trashcan3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Trashcan4
			// 
			this->Trashcan4->Location = System::Drawing::Point(171, 367);
			this->Trashcan4->Name = L"Trashcan4";
			this->Trashcan4->Size = System::Drawing::Size(50, 22);
			this->Trashcan4->TabIndex = 89;
			this->Trashcan4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Trashcan5
			// 
			this->Trashcan5->Location = System::Drawing::Point(227, 367);
			this->Trashcan5->Name = L"Trashcan5";
			this->Trashcan5->Size = System::Drawing::Size(50, 22);
			this->Trashcan5->TabIndex = 90;
			this->Trashcan5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Save_set
			// 
			this->Save_set->Location = System::Drawing::Point(6, 5);
			this->Save_set->Name = L"Save_set";
			this->Save_set->Size = System::Drawing::Size(44, 23);
			this->Save_set->TabIndex = 84;
			this->Save_set->Text = L"Save";
			this->Save_set->UseVisualStyleBackColor = true;
			this->Save_set->Click += gcnew System::EventHandler(this, &Furniture::Save_set_Click);
			// 
			// Reset_set
			// 
			this->Reset_set->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Reset_set->Location = System::Drawing::Point(56, 5);
			this->Reset_set->Name = L"Reset_set";
			this->Reset_set->Size = System::Drawing::Size(44, 23);
			this->Reset_set->TabIndex = 85;
			this->Reset_set->Text = L"Reset";
			this->Reset_set->UseVisualStyleBackColor = true;
			this->Reset_set->Click += gcnew System::EventHandler(this, &Furniture::Reset_set_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 399);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(47, 12);
			this->label19->TabIndex = 86;
			this->label19->Text = L"Trashcan";
			// 
			// Furniture
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(395, 427);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->Reset_set);
			this->Controls->Add(this->Save_set);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Furniture";
			this->Text = L"Furniture";
			this->Load += gcnew System::EventHandler(this, &Furniture::Furniture_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Furniture_Load(System::Object^  sender, System::EventArgs^  e) {
			 viewObject();
		 }
	void viewObject(){
		Liv_Sofa1->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Sofa.x);
		Liv_Sofa2->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Sofa.y);
		Liv_Sofa3->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Sofa.Width);
		Liv_Sofa4->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Sofa.Height);
		Liv_Sofa5->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Sofa.Angle);

		Liv_Table1->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Table.x);
		Liv_Table2->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Table.y);
		Liv_Table3->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Table.Width);
		Liv_Table4->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Table.Height);
		Liv_Table5->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Table.Angle);

		Liv_Cabinet1->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Cabinet.x);
		Liv_Cabinet2->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Cabinet.y);
		Liv_Cabinet3->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Cabinet.Width);
		Liv_Cabinet4->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Cabinet.Height);
		Liv_Cabinet5->Text = System::Convert::ToString(D_Furniture->M_LivingRM.Cabinet.Angle);

		Din_Table1->Text = System::Convert::ToString(D_Furniture->M_DiningRM.Table.x);
		Din_Table2->Text = System::Convert::ToString(D_Furniture->M_DiningRM.Table.y);
		Din_Table3->Text = System::Convert::ToString(D_Furniture->M_DiningRM.Table.Width);
		Din_Table4->Text = System::Convert::ToString(D_Furniture->M_DiningRM.Table.Height);
		Din_Table5->Text = System::Convert::ToString(D_Furniture->M_DiningRM.Table.Angle);

		Din_Chair1->Text = System::Convert::ToString(D_Furniture->M_DiningRM.Chair.x);
		Din_Chair2->Text = System::Convert::ToString(D_Furniture->M_DiningRM.Chair.y);
		Din_Chair3->Text = System::Convert::ToString(D_Furniture->M_DiningRM.Chair.Width);
		Din_Chair4->Text = System::Convert::ToString(D_Furniture->M_DiningRM.Chair.Height);
		Din_Chair5->Text = System::Convert::ToString(D_Furniture->M_DiningRM.Chair.Angle);

		Lib_Desk1->Text = System::Convert::ToString(D_Furniture->M_Library.Desk.x);
		Lib_Desk2->Text = System::Convert::ToString(D_Furniture->M_Library.Desk.y);
		Lib_Desk3->Text = System::Convert::ToString(D_Furniture->M_Library.Desk.Width);
		Lib_Desk4->Text = System::Convert::ToString(D_Furniture->M_Library.Desk.Height);
		Lib_Desk5->Text = System::Convert::ToString(D_Furniture->M_Library.Desk.Angle);

		Lib_Chair1->Text = System::Convert::ToString(D_Furniture->M_Library.Chair.x);
		Lib_Chair2->Text = System::Convert::ToString(D_Furniture->M_Library.Chair.y);
		Lib_Chair3->Text = System::Convert::ToString(D_Furniture->M_Library.Chair.Width);
		Lib_Chair4->Text = System::Convert::ToString(D_Furniture->M_Library.Chair.Height);
		Lib_Chair5->Text = System::Convert::ToString(D_Furniture->M_Library.Chair.Angle);

		Lib_Cabinet1->Text = System::Convert::ToString(D_Furniture->M_Library.Cabinet.x);
		Lib_Cabinet2->Text = System::Convert::ToString(D_Furniture->M_Library.Cabinet.y);
		Lib_Cabinet3->Text = System::Convert::ToString(D_Furniture->M_Library.Cabinet.Width);
		Lib_Cabinet4->Text = System::Convert::ToString(D_Furniture->M_Library.Cabinet.Height);
		Lib_Cabinet5->Text = System::Convert::ToString(D_Furniture->M_Library.Cabinet.Angle);

		Bed1->Text = System::Convert::ToString(D_Furniture->M_BedRM.Bed.x);
		Bed2->Text = System::Convert::ToString(D_Furniture->M_BedRM.Bed.y);
		Bed3->Text = System::Convert::ToString(D_Furniture->M_BedRM.Bed.Width);
		Bed4->Text = System::Convert::ToString(D_Furniture->M_BedRM.Bed.Height);
		Bed5->Text = System::Convert::ToString(D_Furniture->M_BedRM.Bed.Angle);

		Din_door1->Text = System::Convert::ToString(D_Furniture->M_DiningRM.door.x);
		Din_door2->Text = System::Convert::ToString(D_Furniture->M_DiningRM.door.y);
		Din_door3->Text = System::Convert::ToString(D_Furniture->M_DiningRM.door.Width);
		Din_door4->Text = System::Convert::ToString(D_Furniture->M_DiningRM.door.Height);
		Din_door5->Text = System::Convert::ToString(D_Furniture->M_DiningRM.door.Angle);

		Bed_door1->Text = System::Convert::ToString(D_Furniture->M_BedRM.door.x);
		Bed_door2->Text = System::Convert::ToString(D_Furniture->M_BedRM.door.y);
		Bed_door3->Text = System::Convert::ToString(D_Furniture->M_BedRM.door.Width);
		Bed_door4->Text = System::Convert::ToString(D_Furniture->M_BedRM.door.Height);
		Bed_door5->Text = System::Convert::ToString(D_Furniture->M_BedRM.door.Angle);

		Trashcan1->Text = System::Convert::ToString(D_Furniture->M_Trashcan.x);
		Trashcan2->Text = System::Convert::ToString(D_Furniture->M_Trashcan.y);
		Trashcan3->Text = System::Convert::ToString(D_Furniture->M_Trashcan.Width);
		Trashcan4->Text = System::Convert::ToString(D_Furniture->M_Trashcan.Height);
		Trashcan5->Text = System::Convert::ToString(D_Furniture->M_Trashcan.Angle);

		ChargeArea1->Text = System::Convert::ToString(D_Furniture->M_ChargeArea.x);
		ChargeArea2->Text = System::Convert::ToString(D_Furniture->M_ChargeArea.y);
		ChargeArea3->Text = System::Convert::ToString(D_Furniture->M_ChargeArea.Width);
		ChargeArea4->Text = System::Convert::ToString(D_Furniture->M_ChargeArea.Height);
		ChargeArea5->Text = System::Convert::ToString(D_Furniture->M_ChargeArea.Angle);

		EndArea1->Text = System::Convert::ToString(D_Furniture->M_EndArea.x); 
		EndArea2->Text = System::Convert::ToString(D_Furniture->M_EndArea.y);
		EndArea3->Text = System::Convert::ToString(D_Furniture->M_EndArea.Width);
		EndArea4->Text = System::Convert::ToString(D_Furniture->M_EndArea.Height);
		EndArea5->Text = System::Convert::ToString(D_Furniture->M_EndArea.Angle);
	}

	void witerObject(){
		XmlDocument^ doc = gcnew XmlDocument();
		doc->Load("Furniture_set.xml");
		XmlNode^ Manual = doc->SelectSingleNode("/Config/DirectionObject"); //選擇節點

		for(int i =0 ;i < Manual->ChildNodes->Count;i++){
			XmlNode^ node = Manual->ChildNodes[i];
			XmlElement^ element=(XmlElement^)node;
			if(element->Name == "LivingRM_Sofa"){
				element->SetAttribute("x",Liv_Sofa1->Text);
				element->SetAttribute("y",Liv_Sofa2->Text);
				element->SetAttribute("Width",Liv_Sofa3->Text);
				element->SetAttribute("Height",Liv_Sofa4->Text);
				element->SetAttribute("Angle",Liv_Sofa5->Text);
			}else if(element->Name == "LivingRM_Table"){
				element->SetAttribute("x",Liv_Table1->Text);
				element->SetAttribute("y",Liv_Table2->Text);
				element->SetAttribute("Width",Liv_Table3->Text);
				element->SetAttribute("Height",Liv_Table4->Text);
				element->SetAttribute("Angle",Liv_Table5->Text);
			}else if(element->Name == "LivingRM_Cabinet"){
				element->SetAttribute("x",Liv_Cabinet1->Text);
				element->SetAttribute("y",Liv_Cabinet2->Text);
				element->SetAttribute("Width",Liv_Cabinet3->Text);
				element->SetAttribute("Height",Liv_Cabinet4->Text);
				element->SetAttribute("Angle",Liv_Cabinet5->Text);
			}else if(element->Name == "DiningRM_Table"){
				element->SetAttribute("x",Din_Table1->Text);
				element->SetAttribute("y",Din_Table2->Text);
				element->SetAttribute("Width",Din_Table3->Text);
				element->SetAttribute("Height",Din_Table4->Text);
				element->SetAttribute("Angle",Din_Table5->Text);
			}else if(element->Name == "DiningRM_Chair"){
				element->SetAttribute("x",Din_Chair1->Text);
				element->SetAttribute("y",Din_Chair2->Text);
				element->SetAttribute("Width",Din_Chair3->Text);
				element->SetAttribute("Height",Din_Chair4->Text);
				element->SetAttribute("Angle",Din_Chair5->Text);
			}else if(element->Name == "Library_Desk"){
				element->SetAttribute("x",Lib_Desk1->Text);
				element->SetAttribute("y",Lib_Desk2->Text);
				element->SetAttribute("Width",Lib_Desk3->Text);
				element->SetAttribute("Height",Lib_Desk4->Text);
				element->SetAttribute("Angle",Lib_Desk5->Text);
			}else if(element->Name == "Library_Chair"){
				element->SetAttribute("x",Lib_Chair1->Text);
				element->SetAttribute("y",Lib_Chair2->Text);
				element->SetAttribute("Width",Lib_Chair3->Text);
				element->SetAttribute("Height",Lib_Chair4->Text);
				element->SetAttribute("Angle",Lib_Chair5->Text);
			}else if(element->Name == "Library_Cabinet"){
				element->SetAttribute("x",Lib_Cabinet1->Text);
				element->SetAttribute("y",Lib_Cabinet2->Text);
				element->SetAttribute("Width",Lib_Cabinet3->Text);
				element->SetAttribute("Height",Lib_Cabinet4->Text);
				element->SetAttribute("Angle",Lib_Cabinet5->Text);
			}else if(element->Name == "BedRM_Bed"){
				element->SetAttribute("x",Bed1->Text);
				element->SetAttribute("y",Bed2->Text);
				element->SetAttribute("Width",Bed3->Text);
				element->SetAttribute("Height",Bed4->Text);
				element->SetAttribute("Angle",Bed5->Text);
			}else if(element->Name == "DiningRM_door"){
				element->SetAttribute("x",Din_door1->Text);
				element->SetAttribute("y",Din_door2->Text);
				element->SetAttribute("Width",Din_door3->Text);
				element->SetAttribute("Height",Din_door4->Text);
				element->SetAttribute("Angle",Din_door5->Text);
			}else if(element->Name == "BedRM_door"){
				element->SetAttribute("x",Bed_door1->Text);
				element->SetAttribute("y",Bed_door2->Text);
				element->SetAttribute("Width",Bed_door3->Text);
				element->SetAttribute("Height",Bed_door4->Text);
				element->SetAttribute("Angle",Bed_door5->Text);
			}else if(element->Name == "Trashcan"){
				element->SetAttribute("x",Trashcan1->Text);
				element->SetAttribute("y",Trashcan2->Text);
				element->SetAttribute("Width",Trashcan3->Text);
				element->SetAttribute("Height",Trashcan4->Text);
				element->SetAttribute("Angle",Trashcan5->Text);
			}else if(element->Name == "ChargeArea"){
				element->SetAttribute("x",ChargeArea1->Text);
				element->SetAttribute("y",ChargeArea2->Text);
				element->SetAttribute("Width",ChargeArea3->Text);
				element->SetAttribute("Height",ChargeArea4->Text);
				element->SetAttribute("Angle",ChargeArea5->Text);
			}else if(element->Name == "EndArea"){
				element->SetAttribute("x",EndArea1->Text);
				element->SetAttribute("y",EndArea2->Text);
				element->SetAttribute("Width",EndArea3->Text);
				element->SetAttribute("Height",EndArea4->Text);
				element->SetAttribute("Angle",EndArea5->Text);
			}
		}
		doc->Save("Furniture_set.xml");
	}

	void ChangeObject(){
		D_Furniture->M_LivingRM.Sofa.x = System::Convert::ToDouble(Liv_Sofa1->Text);
		D_Furniture->M_LivingRM.Sofa.y = System::Convert::ToDouble(Liv_Sofa2->Text);
		D_Furniture->M_LivingRM.Sofa.Width = System::Convert::ToDouble(Liv_Sofa3->Text);
		D_Furniture->M_LivingRM.Sofa.Height = System::Convert::ToDouble(Liv_Sofa4->Text);
		D_Furniture->M_LivingRM.Sofa.Angle = System::Convert::ToDouble(Liv_Sofa5->Text);

		D_Furniture->M_LivingRM.Table.x = System::Convert::ToDouble(Liv_Table1->Text);
		D_Furniture->M_LivingRM.Table.y = System::Convert::ToDouble(Liv_Table2->Text);
		D_Furniture->M_LivingRM.Table.Width = System::Convert::ToDouble(Liv_Table3->Text);
		D_Furniture->M_LivingRM.Table.Height = System::Convert::ToDouble(Liv_Table4->Text);
		D_Furniture->M_LivingRM.Table.Angle = System::Convert::ToDouble(Liv_Table5->Text);

		D_Furniture->M_LivingRM.Cabinet.x = System::Convert::ToDouble(Liv_Cabinet1->Text);
		D_Furniture->M_LivingRM.Cabinet.y = System::Convert::ToDouble(Liv_Cabinet2->Text);
		D_Furniture->M_LivingRM.Cabinet.Width = System::Convert::ToDouble(Liv_Cabinet3->Text);
		D_Furniture->M_LivingRM.Cabinet.Height = System::Convert::ToDouble(Liv_Cabinet4->Text);
		D_Furniture->M_LivingRM.Cabinet.Angle = System::Convert::ToDouble(Liv_Cabinet5->Text);

		D_Furniture->M_DiningRM.Table.x = System::Convert::ToDouble(Din_Table1->Text);
		D_Furniture->M_DiningRM.Table.y = System::Convert::ToDouble(Din_Table2->Text);
		D_Furniture->M_DiningRM.Table.Width = System::Convert::ToDouble(Din_Table3->Text);
		D_Furniture->M_DiningRM.Table.Height = System::Convert::ToDouble(Din_Table4->Text);
		D_Furniture->M_DiningRM.Table.Angle = System::Convert::ToDouble(Din_Table5->Text);

		D_Furniture->M_DiningRM.Chair.x = System::Convert::ToDouble(Din_Chair1->Text);
		D_Furniture->M_DiningRM.Chair.y = System::Convert::ToDouble(Din_Chair2->Text);
		D_Furniture->M_DiningRM.Chair.Width = System::Convert::ToDouble(Din_Chair3->Text);
		D_Furniture->M_DiningRM.Chair.Height = System::Convert::ToDouble(Din_Chair4->Text);
		D_Furniture->M_DiningRM.Chair.Angle = System::Convert::ToDouble(Din_Chair5->Text);

		D_Furniture->M_Library.Desk.x = System::Convert::ToDouble(Lib_Desk1->Text);
		D_Furniture->M_Library.Desk.y = System::Convert::ToDouble(Lib_Desk2->Text);
		D_Furniture->M_Library.Desk.Width = System::Convert::ToDouble(Lib_Desk3->Text);
		D_Furniture->M_Library.Desk.Height = System::Convert::ToDouble(Lib_Desk4->Text);
		D_Furniture->M_Library.Desk.Angle = System::Convert::ToDouble(Lib_Desk5->Text);

		D_Furniture->M_Library.Chair.x = System::Convert::ToDouble(Lib_Chair1->Text);
		D_Furniture->M_Library.Chair.y = System::Convert::ToDouble(Lib_Chair2->Text);
		D_Furniture->M_Library.Chair.Width = System::Convert::ToDouble(Lib_Chair3->Text);
		D_Furniture->M_Library.Chair.Height = System::Convert::ToDouble(Lib_Chair4->Text);
		D_Furniture->M_Library.Chair.Angle = System::Convert::ToDouble(Lib_Chair5->Text);

		D_Furniture->M_Library.Cabinet.x = System::Convert::ToDouble(Lib_Cabinet1->Text);
		D_Furniture->M_Library.Cabinet.y = System::Convert::ToDouble(Lib_Cabinet2->Text);
		D_Furniture->M_Library.Cabinet.Width = System::Convert::ToDouble(Lib_Cabinet3->Text);
		D_Furniture->M_Library.Cabinet.Height = System::Convert::ToDouble(Lib_Cabinet4->Text);
		D_Furniture->M_Library.Cabinet.Angle = System::Convert::ToDouble(Lib_Cabinet5->Text);

		D_Furniture->M_BedRM.Bed.x = System::Convert::ToDouble(Bed1->Text);
		D_Furniture->M_BedRM.Bed.y = System::Convert::ToDouble(Bed2->Text);
		D_Furniture->M_BedRM.Bed.Width = System::Convert::ToDouble(Bed3->Text);
		D_Furniture->M_BedRM.Bed.Height = System::Convert::ToDouble(Bed4->Text);
		D_Furniture->M_BedRM.Bed.Angle = System::Convert::ToDouble(Bed5->Text);

		D_Furniture->M_DiningRM.door.x = System::Convert::ToDouble(Din_door1->Text);
		D_Furniture->M_DiningRM.door.y = System::Convert::ToDouble(Din_door2->Text);
		D_Furniture->M_DiningRM.door.Width = System::Convert::ToDouble(Din_door3->Text);
		D_Furniture->M_DiningRM.door.Height = System::Convert::ToDouble(Din_door4->Text);
		D_Furniture->M_DiningRM.door.Angle = System::Convert::ToDouble(Din_door5->Text);

		D_Furniture->M_BedRM.door.x = System::Convert::ToDouble(Bed_door1->Text);
		D_Furniture->M_BedRM.door.y = System::Convert::ToDouble(Bed_door2->Text);
		D_Furniture->M_BedRM.door.Width = System::Convert::ToDouble(Bed_door3->Text);
		D_Furniture->M_BedRM.door.Height = System::Convert::ToDouble(Bed_door4->Text);
		D_Furniture->M_BedRM.door.Angle = System::Convert::ToDouble(Bed_door5->Text);

		D_Furniture->M_ChargeArea.x = System::Convert::ToDouble(ChargeArea1->Text);
		D_Furniture->M_ChargeArea.y = System::Convert::ToDouble(ChargeArea2->Text);
		D_Furniture->M_ChargeArea.Width = System::Convert::ToDouble(ChargeArea3->Text);
		D_Furniture->M_ChargeArea.Height = System::Convert::ToDouble(ChargeArea4->Text);
		D_Furniture->M_ChargeArea.Angle = System::Convert::ToDouble(ChargeArea5->Text);

		D_Furniture->M_EndArea.x = System::Convert::ToDouble(EndArea1->Text); 
		D_Furniture->M_EndArea.y = System::Convert::ToDouble(EndArea2->Text);
		D_Furniture->M_EndArea.Width = System::Convert::ToDouble(EndArea3->Text);
		D_Furniture->M_EndArea.Height = System::Convert::ToDouble(EndArea4->Text);
		D_Furniture->M_EndArea.Angle = System::Convert::ToDouble(EndArea5->Text);
	}

private: System::Void Save_set_Click(System::Object^  sender, System::EventArgs^  e) {
			 ChangeObject();
			 witerObject();
		 }
private: System::Void Reset_set_Click(System::Object^  sender, System::EventArgs^  e) {
			 viewObject();
		 }
};
}
