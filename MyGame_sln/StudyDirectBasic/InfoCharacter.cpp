#include "InfoCharacter.h"



InfoCharacter::InfoCharacter()
{
}


InfoCharacter::~InfoCharacter()
{
	free(lstAladdin);
	lstAladdin = nullptr;
}

void InfoCharacter::ReadInfo()
{
	ReadAladdin();
}
void InfoCharacter::ReadAladdin()
{
	fstream f;
	f.open("InfoAladdin.txt", ios::in);
	if (!f)
	{
		exit(1);
	}
	// viet ma doc file tai day
	string data;
	// đọc số trạng thái
	getline(f, data);
	lstAladdin = new ListFrame[atoi(data.c_str())];
	for (int i = 0; i < atoi(data.c_str()); i++)
	{
		// đọc số frame trong 1 trạng thái
		string number_frame;
		getline(f, number_frame);
		lstAladdin[i].frame = new Frame[atoi(number_frame.c_str())];
		lstAladdin[i].number = atoi(number_frame.c_str());
		for (int j = 0; j < atoi(number_frame.c_str()); j++)
		{
			string frame_info;
			// đọc từng số liệu
			// ghi vào frame
			// thứ tự là x,y,w,h,pl,pt,time;
			f >> frame_info;
			lstAladdin[i].frame[j].x = 2 * atoi(frame_info.c_str());
			f >> frame_info;
			lstAladdin[i].frame[j].y = 2 * atoi(frame_info.c_str());
			f >> frame_info;
			lstAladdin[i].frame[j].width = 2 * atoi(frame_info.c_str());
			f >> frame_info;
			lstAladdin[i].frame[j].height = 2 * atoi(frame_info.c_str());
			f >> frame_info;
			lstAladdin[i].frame[j].padding.left = 2 * atoi(frame_info.c_str());
			f >> frame_info;
			lstAladdin[i].frame[j].padding.top = 2 * atoi(frame_info.c_str());
			f >> frame_info;
			lstAladdin[i].frame[j].TimeDelay = atoi(frame_info.c_str());	

		}
	}
	f.close();
}
ListFrame* InfoCharacter::GetListAladdin()
{
	return lstAladdin;
}
