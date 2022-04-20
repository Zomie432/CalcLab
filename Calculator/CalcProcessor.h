#pragma once

class CalcProcessor
{
private:
	CalcProcessor() {}
	~CalcProcessor() {}

public:
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
};

