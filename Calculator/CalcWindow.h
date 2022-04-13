#pragma once
#include "wx/wx.h"
#include <string>

class CalcWindow : public wxFrame
{
public:
	int mFieldWidth =4;
	int mFieldHeight = 5;

	float mNumberOne = 0;
	float mNumberTwo = 0;

	int xOffset = 7;
	int yOffset = 110;

	wxButton** btn;
	wxButton* btnClear;
	int* mField = nullptr;
	bool mFirstClick = true;

	wxString temp;
	wxString fin1;
	wxString fin2;

	wxTextCtrl *mNumDisplay;
	wxTextCtrl *mPrevCalcDisplay;

	std::string btnNums =  "B741%H8520D963=~/*-+";
public:
	CalcWindow();
	~CalcWindow();
	void OnButtonClick(wxCommandEvent& evt);
	//void OnEnterKeyPress(wxKeyEvent& evt);

	//void FindNumsToCalculate(std::string _operand);
	//std::string Calculate(wxString _txt);
	bool CheckIfContainsOperand(wxString _txt);

	void SetTextBoxText(wxString _text);

	wxDECLARE_EVENT_TABLE();
};

