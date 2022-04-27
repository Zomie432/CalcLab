#pragma once
#include <list>
#include "IBaseCommand.h"
#include <string>
#include <sstream>

class CalcProcessor
{
private:
	std::list<IBaseCommand*> mCommands;

	IBaseCommand* mLastCommand = nullptr;

	CalcProcessor() {}

public:
	void AddCommand(IBaseCommand* _command, float _num);
	float ExecuteCommands();

	static CalcProcessor& getInstance() {
		static CalcProcessor calcProcessor;
		return calcProcessor;
	}

public:
	float ProcessAdd(float num1, float num2);
	float ProcessMinus(float num1, float num2);
	float ProcessMultiply(float num1, float num2);
	float ProcessDivide(float num1, float num2);
	float ProcessMod(float num1, float num2);
	std::string ProcessBinary(long long num);
	std::string ProcessHex(int num1);
};

