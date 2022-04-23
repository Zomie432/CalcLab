#pragma once

class IBaseCommand
{
public:
	float mCurrNum;
	float mPrevNum;

	virtual void Execute() = 0;
};

class AddCommand : public IBaseCommand {
public:
	AddCommand() {}
	void Execute() {
		mPrevNum += mCurrNum;
	}
};

class SubtractCommand : public IBaseCommand {
public:
	SubtractCommand() {}
	void Execute() {
		mPrevNum -= mCurrNum;
	}
};

class MultiplyCommand : public IBaseCommand {
public:
	MultiplyCommand() {}
	void Execute() {
		mPrevNum *= mCurrNum;
	}
};

class DivideCommand : public IBaseCommand {
public:
	DivideCommand() {}
	void Execute() {
		mPrevNum /= mCurrNum;
	}
};

class ModCommand : public IBaseCommand {
public:
	ModCommand() {}
	void Execute() {
		mPrevNum = (int)(mCurrNum) % (int)(mPrevNum);
	}
};

class EqualsCommand : public IBaseCommand {
public:
	EqualsCommand() {}
	void Execute() {

	}
};