#pragma once
#include "wx/wx.h"
#include "CalcWindow.h"

class CalcApp : public wxApp
{
private:
	CalcWindow* calcWindow = nullptr;
public:
	CalcApp();
	~CalcApp();

	virtual bool OnInit();
};

