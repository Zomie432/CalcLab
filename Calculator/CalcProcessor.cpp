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
