#include "CalcWindow.h"

wxBEGIN_EVENT_TABLE(CalcWindow, wxFrame)
wxEND_EVENT_TABLE()

enum btnID {
	binary, seven, four, one, mod, 
	hex, eight, five, two, zero,
	decimal, nine, six, three, equals,
	negative, divide, multiply, subtract, add,
	clear
};

CalcWindow::CalcWindow() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(400, 200), wxSize(350, 510))
{
	this->SetBackgroundColour(wxColor(32, 32, 32));
	wxFont numFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxFont btnFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxFont preCalcFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	mNumDisplay = new wxTextCtrl(this, wxID_ANY, "0", wxPoint(5, 35), wxSize(325, 70), wxTE_RIGHT | wxBORDER_NONE);
	mNumDisplay->SetFont(numFont);
	mNumDisplay->SetForegroundColour(wxColor(255, 255, 255));
	mNumDisplay->SetBackgroundColour(wxColor(32, 32, 32));

	mPrevCalcDisplay = new wxTextCtrl(this, wxID_ANY, "", wxPoint(5, 10), wxSize(325, 25), wxTE_RIGHT | wxBORDER_NONE);
	mPrevCalcDisplay->SetFont(preCalcFont);
	mPrevCalcDisplay->SetForegroundColour(wxColor(100, 100, 100));
	mPrevCalcDisplay->SetBackgroundColour(wxColor(32, 32, 32));

	btn = new wxButton * [mFieldWidth * mFieldHeight];
	btnClear = new wxButton(this, 10020, "Clear", wxPoint(7, 412), wxSize(320, 55));
	btnClear->SetBackgroundColour(wxColor(16, 16, 16));
	btnClear->SetForegroundColour(wxColor(255, 255, 255));
	btnClear->SetFont(btnFont);
	btnClear->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

	mField = new int[mFieldWidth * mFieldHeight];
	
	for (int x = 0, i = 0; x < mFieldWidth; x++)
	{
		for (int y = 0; y < mFieldHeight; y++)
		{
			btn[y * mFieldWidth + x] = new wxButton(this, 10000+i, btnNums[i], 
				wxPoint(x*82 + xOffset, y*60 + yOffset), wxSize(75, 55));
			btn[y * mFieldWidth + x]->SetFont(btnFont);
			btn[y * mFieldWidth + x]->SetBackgroundColour(wxColor(16, 16, 16));
			btn[y * mFieldWidth + x]->SetForegroundColour(wxColor(255, 255, 255));
			btn[y * mFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
				&CalcWindow::OnButtonClick, this);
			i++;
		}
	}
}

CalcWindow::~CalcWindow() {
	delete[] btn;
	delete btnClear;
}

void CalcWindow::OnButtonClick(wxCommandEvent& evt) {
	
}


bool CalcWindow::CheckIfContainsOperand(wxString _txt) {
	if (_txt.Contains("+") || _txt.Contains("-") || _txt.Contains("/") || _txt.Contains("*")) {
		return true;
	}
	return false;
}

void CalcWindow::SetTextBoxText(wxString _text) {
	mNumDisplay->SetLabelText(_text);
}