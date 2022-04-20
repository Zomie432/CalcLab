#pragma once
#include "ButtonFactory.h"
#include "CalcProcessor.h"
#include <string>
#include <sstream>

class CalcWindow : public wxFrame
{
private:
	CalcProcessor* mProcessor = &CalcProcessor::getInstance();

public:
	float mNumberOne = 0;
	float mNumberTwo = 0;

	int xOffset = 7;
	int yOffset = 110;

	wxString mStoredNum;

	std::ostringstream hexStream;
	std::string hexRes;

	bool bIsBorH = false;

	//button
	wxButton** btnNumbers;
	wxButton* btnClear;
	wxButton* btnAdd;
	wxButton* btnMinus;
	wxButton* btnMultiply;
	wxButton* btnDivide;
	wxButton* btnMod;
	wxButton* btnHex;
	wxButton* btnDecimal;
	wxButton* btnBinary;
	wxButton* btnNegate;
	wxButton* btnEquals;

	wxString fin1;
	wxString fin2;

	wxTextCtrl* mNumDisplay;
	wxTextCtrl* mPrevCalcDisplay;

	ButtonFactory mBtnFactory;
public:
	CalcWindow();
	~CalcWindow();
	void OnButtonClick(wxCommandEvent& evt);

	void FindNumsToCalculate(std::string _operand);
	wxString Calculate(wxString _txt);

	void SetTextBoxText(wxString _text);

	wxDECLARE_EVENT_TABLE();
};

