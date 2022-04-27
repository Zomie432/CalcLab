#include "CalcProcessor.h"

void CalcProcessor::AddCommand(IBaseCommand* _command, float _num)
{
	if (mLastCommand != nullptr) {
		mLastCommand->mCurrNum = _num;
	}
	mCommands.push_back(_command);
	mLastCommand = _command;
}

float CalcProcessor::ExecuteCommands()
{
	float num = 0;

	for (std::list<IBaseCommand*>::iterator it = mCommands.begin(); it != mCommands.end();)
	{
		(*it)->Execute();
		num = (*it)->mPrevNum;
		it++;

		if (it != mCommands.end()) {
			(*it)->mPrevNum = num;
		}
		else {
			mCommands.clear();
			mLastCommand = nullptr;
		}
	}
	return num;
}


float CalcProcessor::ProcessAdd(float num1, float num2)
{
	return num1 + num2;
}

float CalcProcessor::ProcessMinus(float num1, float num2)
{
	return num1 - num2;
}

float CalcProcessor::ProcessMultiply(float num1, float num2)
{
	return num1 * num2;
}

float CalcProcessor::ProcessDivide(float num1, float num2)
{
	return num1 / num2;
}

float CalcProcessor::ProcessMod(float num1, float num2)
{
	return (int)num1 % (int)num2;
}

std::string CalcProcessor::ProcessBinary(long long num)
{
	std::string text = "";
	for (int i = 0; i < 12; i++)
	{
		if (num % 2 == 0) {
			text = "0" + text;
		}
		else {
			text = "1" + text;
		}
		num /= 2;
	}
	return text;
}

std::string CalcProcessor::ProcessHex(int num)
{
	std::stringstream text;
	if (num < 0) {
		text << "-";
		num *= -1;
	}
	text << "0x" << std::hex << num;
	std::string result = text.str();
	return result;
	
}
