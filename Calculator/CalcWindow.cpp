#include "CalcWindow.h"
#include <bitset>

wxBEGIN_EVENT_TABLE(CalcWindow, wxFrame)
wxEND_EVENT_TABLE()

enum btnID {
    zero, one, two, three, four, five,
    six, seven, eight, nine, equals, negative,
    add, subtract, multiply, divide, mod,
    hex, decimal, binary, clear
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
    if (bIsBorH == true) {
        CalcWindow::SetTextBoxText(mStoredNum);
        bIsBorH = false;
    }

    if (evt.GetId() - 10000 >= btnID::hex) {
        if (evt.GetId() - 10000 == btnID::binary) {
            int txtInt = wxAtoi(mNumDisplay->GetLabelText());
            //mNumDisplay->SetLabelText(CalcWindow::Calculate(txt));
            mStoredNum = mNumDisplay->GetLabelText();
            CalcWindow::SetTextBoxText(std::bitset<8>(txtInt).to_string());
            bIsBorH = true;
        }
        if (evt.GetId() - 10000 == btnID::hex) {

        }

        if (evt.GetId() - 10000 == btnID::decimal) {
            CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + ".");
        }

        if (evt.GetId() - 10000 == btnID::clear) {
            CalcWindow::SetTextBoxText("0");
            mPrevCalcDisplay->Clear();
            mNumStr.Clear();
        }
    }

    //negative
    if (evt.GetId() - 10000 == btnID::negative) {
        CalcWindow::SetTextBoxText("-" + mNumDisplay->GetLabelText());
    }

    //0
    if (evt.GetId() - 10000 == btnID::zero) {
        if (mNumDisplay->GetLabelText() != "0") {
            CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "0");
            mNumStr.append("0");
        }
    }
    //num other then 0
    else if (evt.GetId() - 10000 <= btnID::nine) {
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + std::to_string(btnID(evt.GetId() - 10000)));
        mNumStr.append(std::to_string(btnID(evt.GetId() - 10000)));
    }

    //operands
    if (evt.GetId() - 10000 == btnID::add) {
        AddCommand* command = new AddCommand();
        command->mPrevNum = wxAtof(mNumStr);
        mNumStr.Clear();
        mProcessor->AddCommand(command, command->mPrevNum);
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "+");
    }
    else if (evt.GetId() - 10000 == btnID::subtract) {
        SubtractCommand* command = new SubtractCommand();
        command->mPrevNum = wxAtof(mNumStr);
        mNumStr.Clear();
        mProcessor->AddCommand(command, command->mPrevNum);
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "-");
    }
    else if (evt.GetId() - 10000 == btnID::multiply) {
        MultiplyCommand* command = new MultiplyCommand();
        command->mPrevNum = wxAtof(mNumStr);
        mNumStr.Clear();
        mProcessor->AddCommand(command, command->mPrevNum);
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "*");
    }
    else if (evt.GetId() - 10000 == btnID::divide) {
        DivideCommand* command = new DivideCommand();
        command->mPrevNum = wxAtof(mNumStr);
        mNumStr.Clear();
        mProcessor->AddCommand(command, command->mPrevNum);
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "/");
    }
    else if (evt.GetId() - 10000 == btnID::mod) {
        ModCommand* command = new ModCommand();
        command->mPrevNum = wxAtof(mNumStr);
        mNumStr.Clear();
        mProcessor->AddCommand(command, command->mPrevNum);
        CalcWindow::SetTextBoxText(mNumDisplay->GetLabelText() + "%");
    }
    else if (evt.GetId() - 10000 == btnID::equals)
    {
        mProcessor->AddCommand(new EqualsCommand(), wxAtof(mNumStr));
        mNumStr.Clear();
        CalcWindow::SetTextBoxText(std::to_string(mProcessor->ExecuteCommands()));
        if (wxAtoi(mNumDisplay->GetLabelText()) == wxAtof(mNumDisplay->GetLabelText())) {
            int tempSum = wxAtoi(mNumDisplay->GetLabelText());
            mNumDisplay->SetLabelText(std::to_string(tempSum));
        }
    }
    evt.Skip();
}

void CalcWindow::SetTextBoxText(wxString _text) {
    mNumDisplay->SetLabelText(_text);
}