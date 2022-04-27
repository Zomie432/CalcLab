#include "../Calculator/ButtonFactory.h"
#include "../Calculator/ButtonFactory.cpp"

ButtonFactory* btn;

bool NumberButtonTest(int id)
{
	wxButton* temp = btn->CreateNumberButton(nullptr, id, "");
	int tId = temp->GetId();
	delete temp;
	return tId == id;
}

bool AddButtonTest(int id)
{
	wxButton* temp = btn->CreateAddButton(nullptr, id);
	int tId = temp->GetId();
	delete temp;
	return tId == id;
}

bool MinusButtonTest(int id)
{
	wxButton* temp = btn->CreateMinusButton(nullptr, id);
	int tId = temp->GetId();
	delete temp;
	return tId == id;
}

bool MultiplyButtonTest(int id)
{
	wxButton* temp = btn->CreateMultiplyButton(nullptr, id);
	int tId = temp->GetId();
	delete temp;
	return tId == id;
}

bool DivideButtonTest(int id)
{
	wxButton* temp = btn->CreateDivideButton(nullptr, id);
	int tId = temp->GetId();
	delete temp;
	return tId == id;
}

bool ModButtonTest(int id)
{
	wxButton* temp = btn->CreateModButton(nullptr, id);
	int tId = temp->GetId();
	delete temp;
	return tId == id;
}

bool DecimalButtonTest(int id)
{
	wxButton* temp = btn->CreateDecimalButton(nullptr, id);
	int tId = temp->GetId();
	delete temp;
	return tId == id;
}

bool HexButtonTest(int id)
{
	wxButton* temp = btn->CreateHexButton(nullptr, id);
	int tId = temp->GetId();
	delete temp;
	return tId == id;
}

bool BinaryButtonTest(int id)
{
	wxButton* temp = btn->CreateBinaryButton(nullptr, id);
	int tId = temp->GetId();
	delete temp;
	return tId == id;
}

bool EqualsButtonTest(int id)
{
	wxButton* temp = btn->CreateEqualsButton(nullptr, id);
	int tId = temp->GetId();
	delete temp;
	return tId == id;
}
