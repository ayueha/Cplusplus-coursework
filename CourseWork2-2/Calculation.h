#pragma once
#include <string>
using namespace std;
class Calculation
{
public:
	Calculation();
	~Calculation();
	double addition(double InputFormer, double InputLatter);
	double substraction(double InputFormer, double InputLatter);
	double multiplication(double InputFormer, double InputLatter);
	double assignment(double InputFormer, double InputLatter);
	double comparison(double InputFormer, double InputLatter);
	double power(double InputFormer, double InputLatter);  //std::pow ‚ð—˜—p
	//transposing

private:
	double InputFormer;
	double InputLatter;
};

