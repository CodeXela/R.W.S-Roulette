#pragma once
class CasinoBank
{
public:

	CasinoBank();

	void initCB(float bank);

	float holeBank() { return _Bank; };

	void setzeBankKonto(float bank);

	void entferneBankKonto(float nbank);

	~CasinoBank();

private:

	float _Bank;
};

