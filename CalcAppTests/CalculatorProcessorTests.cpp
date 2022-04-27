#include "../Calculator/CalcProcessor.h"
#include "../Calculator/CalcProcessor.cpp"

CalcProcessor* processor = &CalcProcessor::getInstance();

bool AddTest(int num1, int num2) {
	float temp = processor->ProcessAdd(num1, num2);
	float sum = num1 + num2;
	return temp == sum;
}

bool MinusTest(int num1, int num2) {
	float temp = processor->ProcessMinus(num1, num2);
	float sum = num1 - num2;
	return temp == sum;
}

bool MultiplyTest(int num1, int num2) {
	float temp = processor->ProcessMultiply(num1, num2);
	float sum = num1 * num2;
	return temp == sum;
}

bool DivideTest(int num1, int num2) {
	float temp = processor->ProcessDivide(num1, num2);
	float sum = num1 / num2;
	return temp == sum;
}

bool ModTest(int num1, int num2) {
	int temp = processor->ProcessMod(num1, num2);
	int sum = num1 % num2;
	return temp == sum;
}

bool BinaryTest22(int num) {
	std::string temp = processor->ProcessBinary(num);
	return "000000010110" == temp;
}

bool BinaryTest35(int num) {
	std::string temp = processor->ProcessBinary(num);
	return "000000100011" == temp;
}

bool BinaryTest122(int num) {
	std::string temp = processor->ProcessBinary(num);
	return "000001111010" == temp;
}

bool HexTest12(int num) {
	std::string temp = processor->ProcessHex(num);
	return "0xC" == temp;
}

bool HexTest20(int num) {
	std::string temp = processor->ProcessHex(num);
	return "0x14" == temp;
}

