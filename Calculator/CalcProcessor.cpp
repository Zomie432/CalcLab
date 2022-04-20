#include "CalcProcessor.h"

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
