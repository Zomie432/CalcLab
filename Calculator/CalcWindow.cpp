#include "CalcWindow.h"

wxBEGIN_EVENT_TABLE(CalcWindow, wxFrame)
wxEND_EVENT_TABLE()

enum btnID {
    zero, one, two, three, four, five,
    six, seven, eight, nine, equals,
    negative, add, subtract, multiply, divide,
    mod, hex, decimal, binary, clear
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

    btnNumbers = new wxButton * [10];

    for (int i = 0, x = 0, y = 0; i < 10; i++)
    {
        x++;
        if (i == 1) x++;
        if (x % 3 == 0) {
            x = 0;
            y++;
        }
        btnNumbers[i] = mBtnFactory.CreateNumberButton(this, 10000 + i, std::to_string(i), wxPoint(x * 82 + xOffset, y * 60 + yOffset), wxSize(75, 55));
        btnNumbers[i]->SetFont(btnFont);
        btnNumbers[i]->SetBackgroundColour(wxColor(48, 48, 48));
        btnNumbers[i]->SetForegroundColour(wxColor(255, 255, 255));
        btnNumbers[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
            &CalcWindow::OnButtonClick, this);
    }

    btnEquals = mBtnFactory.CreateEqualsButton(this, 10010, wxPoint(0 * 82 + xOffset, 0 * 60 + yOffset), wxSize(75, 55));
    btnEquals->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

    btnNegate = mBtnFactory.CreateNegateButton(this, 10011, wxPoint(2 * 82 + xOffset, 0 * 60 + yOffset), wxSize(75, 55));
    btnNegate->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

    btnAdd = mBtnFactory.CreateAddButton(this, 10012, wxPoint(3 * 82 + xOffset, 0 * 60 + yOffset), wxSize(75, 55));
    btnAdd->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

    btnMinus = mBtnFactory.CreateMinusButton(this, 10013, wxPoint(3 * 82 + xOffset, 1 * 60 + yOffset), wxSize(75, 55));
    btnMinus->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

    btnMultiply = mBtnFactory.CreateMultiplyButton(this, 10014, wxPoint(3 * 82 + xOffset, 2 * 60 + yOffset), wxSize(75, 55));
    btnMultiply->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

    btnDivide = mBtnFactory.CreateDivideButton(this, 10015, wxPoint(3 * 82 + xOffset, 3 * 60 + yOffset), wxSize(75, 55));
    btnDivide->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

    btnMod = mBtnFactory.CreateModButton(this, 10016, wxPoint(0 * 82 + xOffset, 4 * 60 + yOffset), wxSize(75, 55));
    btnMod->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

    btnHex = mBtnFactory.CreateHexButton(this, 10017, wxPoint(1 * 82 + xOffset, 4 * 60 + yOffset), wxSize(75, 55));
    btnHex->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

    btnDecimal = mBtnFactory.CreateDecimalButton(this, 10018, wxPoint(2 * 82 + xOffset, 4 * 60 + yOffset), wxSize(75, 55));
    btnDecimal->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

    btnBinary = mBtnFactory.CreateBinaryButton(this, 10019, wxPoint(3 * 82 + xOffset, 4 * 60 + yOffset), wxSize(75, 55));
    btnBinary->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);

    btnClear = mBtnFactory.CreateClearButton(this, 10020, wxPoint(7, 412), wxSize(320, 55));
    btnClear->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalcWindow::OnButtonClick, this);
}

CalcWindow::~CalcWindow() {
    delete[] btnNumbers;
    delete btnClear;
    delete btnAdd;
    delete btnMinus;
    delete btnMultiply;
    delete btnDivide;
    delete btnMod;
    delete btnHex;
    delete btnDecimal;
    delete btnBinary;
    delete btnNegate;
    delete btnEquals;

    delete mNumDisplay;
    delete mPrevCalcDisplay;
}

void CalcWindow::OnButtonClick(wxCommandEvent& evt) {
    wxString txt = mNumDisplay->GetLabelText();
    if ((txt == "0" && (evt.GetId() - 10000) < 10) || txt == "ERROR") {
        mNumDisplay->SetLabelText("");
    }
    switch (btnID(evt.GetId() - 10000))
    {
    case binary:
        break;
    case seven:
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "7");
        break;
    case four:
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "4");
        break;
    case one:
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "1");
        break;
    case mod:
        CalcWindow::SetTextBoxText(CalcWindow::Calculate(txt));
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "%");
        break;
    case hex:
        break;
    case eight:
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "8");
        break;
    case five:
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "5");
        break;
    case two:
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "2");
        break;
    case zero:
        if (mNumDisplay->GetLabelText() != "0") {
            CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "0");
        }
        break;
    case decimal:
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + ".");
        break;
    case nine:
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "9");
        break;
    case six:
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "6");
        break;
    case three:
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "3");
        break;
    case equals:
        mNumDisplay->SetLabelText(CalcWindow::Calculate(txt));
        break;
    case negative:
        break;
    case divide:
        CalcWindow::SetTextBoxText(CalcWindow::Calculate(txt));
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "/");
        break;
    case multiply:
        CalcWindow::SetTextBoxText(CalcWindow::Calculate(txt));
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "*");
        break;
    case subtract:
        CalcWindow::SetTextBoxText(CalcWindow::Calculate(txt));
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "-");
        break;
    case add:
        CalcWindow::SetTextBoxText(CalcWindow::Calculate(txt));
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "+");
        break;
    case clear:
        CalcWindow::SetTextBoxText("0");
        mPrevCalcDisplay->SetLabelText("");
        break;
    default:
        break;
    }
    evt.Skip();
}

void CalcWindow::FindNumsToCalculate(std::string _operand) {
    int i;
    wxString temp = mNumDisplay->GetLabelText();
    i = temp.Find(_operand);
    fin1 = temp.SubString(0, i - 1);
    mNumberOne = wxAtof(fin1);
    fin2 = temp.SubString(i + 1, temp.length());
    mNumberTwo = wxAtof(fin2);
}

wxString CalcWindow::Calculate(wxString _txt) {
    if (_txt.Contains("+")) {
        CalcWindow::FindNumsToCalculate("+");
        float temp = mNumberOne + mNumberTwo;
        mPrevCalcDisplay->SetLabelText(_txt + "=");
        if (temp == (int)temp) {
            return std::to_string((int)temp);
        }
        else return std::to_string(temp);
    }
    else if (_txt.Contains("-")) {
        CalcWindow::FindNumsToCalculate("-");
        float temp = mNumberOne - mNumberTwo;
        mPrevCalcDisplay->SetLabelText(_txt + "=");
        if (temp == (int)temp) {
            return std::to_string((int)temp);
        }
        else return std::to_string(temp);
    }
    else if (_txt.Contains("/")) {
        CalcWindow::FindNumsToCalculate("/");
        if (mNumberTwo == 0 || mNumberOne == 0) {
            return "ERROR";
        }
        else {
            float temp = mNumberOne / mNumberTwo;
            mPrevCalcDisplay->SetLabelText(_txt + "=");
            if (temp == (int)temp) {
                return std::to_string((int)temp);
            }
            else return std::to_string(temp);
        }
    }
    else if (_txt.Contains("*")) {
        CalcWindow::FindNumsToCalculate("*");
        float temp = mNumberOne * mNumberTwo;
        mPrevCalcDisplay->SetLabelText(_txt + "=");
        if (temp == (int)temp) {
            return std::to_string((int)temp);
        }
        else return std::to_string(temp);
    }
    else if (_txt.Contains("%")) {
        CalcWindow::FindNumsToCalculate("%");
        int temp = (int)mNumberOne % (int)mNumberTwo;
        mPrevCalcDisplay->SetLabelText(_txt + "=");
        return std::to_string(temp);
    }
    else return _txt;
}

void CalcWindow::SetTextBoxText(wxString _text) {
    mNumDisplay->SetLabelText(_text);
}