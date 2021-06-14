#pragma once
class CasinoBank
{
public:

	CasinoBank();

	void initCB(double bank);

	double holeBank() { return _Bank; };

	void setzeBankKonto(double bank);

	void entferneBankKonto(double nbank);

	~CasinoBank();

private:

	double _Bank{};
};

