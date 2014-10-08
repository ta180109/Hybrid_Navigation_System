#include <string>
#include "Database.h"
// 預設建構函式
using namespace System::Xml;
using namespace System::IO;


data1 *D_Robot = new data1();

data2 *D_Order = new data2();

data3 *D_Touch = new data3();

data4 *D_mos = new data4();

data5 *D_Vector = new data5();

data6 *D_Time = new data6();

data7 *D_Range = new data7();

data8 *D_Furniture = new data8();

Laser_information *R_Laser = new Laser_information[73];

data9 *R_Position = new data9();

data10 *R_Robot = new data10();

Database *D_Database = new Database();

void Robot_Request(System::String^ Re_Node){
	XmlDocument^ doc = gcnew XmlDocument();
	doc->Load("Robot_Request.xml");
	XmlNode^ Manual = doc->SelectSingleNode("/Request"); //選擇節點

	int have_t=0;

	for(int i =0 ;i < Manual->ChildNodes->Count;i++){
		XmlNode^ node = Manual->ChildNodes[i];
		XmlElement^ element=(XmlElement^)node;

		if(element->Name == Re_Node){
			have_t = 1;
		}
	}
	if(have_t==0){
		XmlElement^ Distance = doc->CreateElement(Re_Node);
		Manual->AppendChild(Distance);
	}else{
		Manual->RemoveChild(Manual->SelectSingleNode(Re_Node));
	}
	doc->Save("Robot_Request.xml");
}