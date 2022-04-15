#include "ButtonFactory.h"

wxButton* ButtonFactory::CreateButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	wxFont mFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxButton* temp = new wxButton(parent, id, label, pos, size);
	temp->SetBackgroundColour(wxColor(16, 16, 16));
	temp->SetForegroundColour(wxColor(255, 255, 255));
	temp->SetFont(mFont);
	return temp;
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "+", pos, size);
}

wxButton* ButtonFactory::CreateMinusButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "-", pos, size);
}

wxButton* ButtonFactory::CreateMultiplyButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "*", pos, size);
}

wxButton* ButtonFactory::CreateDivideButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "/", pos, size);
}

wxButton* ButtonFactory::CreateModButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "%", pos, size);
}

wxButton* ButtonFactory::CreateHexButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "H", pos, size);
}

wxButton* ButtonFactory::CreateDecimalButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "D", pos, size);
}

wxButton* ButtonFactory::CreateBinaryButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "B", pos, size);
}

wxButton* ButtonFactory::CreateNegateButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "~", pos, size);
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "=", pos, size);
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, "Clear", pos, size);
}

wxButton* ButtonFactory::CreateNumberButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return CreateButton(parent, id, label, pos, size);
}
