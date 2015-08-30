#pragma once
class CasinoBank
{
public:
	CasinoBank();


	void initCB(float bank);

	float BankPrint() { return _Bank; };
	~CasinoBank();

private:
	float _Bank;
};

