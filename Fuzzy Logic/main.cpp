#include <iostream>

#include "Expression.h"
#include "AggMax.h"
#include "AggPlus.h"
#include "AndMin.h"
#include "AndMult.h"
#include "NotMinus.h"
#include "OrMax.h"
#include "OrPlus.h"
#include "ThenMin.h"
#include "ThenMult.h"
#include "IsTriangle.h"
#include "ValueModel.h"

#include "CogDefuzz.h"
#include "SugenoDefuzz.h"
#include "SugenoConclusion.h"
#include "SugenoThen.h"

#include "FuzzyFactory.h"

void testUnaryOperators()
{
	core::ValueModel<float> v1(1);
	core::ValueModel<float> v2(3);
	core::ValueModel<float> v3(5);
	core::ValueModel<float> v4(7);


	fuzzy::IsTriangle<float> isTriangle(0, 5, 10);
	core::ValueModel<float> isTriangleValueMin = isTriangle.Evaluate(&v1);
	core::ValueModel<float> isTriangleValueMax = isTriangle.Evaluate(&v4);
	std::cout << std::endl << "Result of triangle operation on " << v1.Evaluate() << " equals " << isTriangle.Evaluate(&v1) << std::endl;
	std::cout << std::endl << "Result of triangle operation on " << v4.Evaluate() << " equals " << isTriangle.Evaluate(&v4) << std::endl;

	core::UnaryExpressionModel<float> unary(&isTriangle, &v1);
	std::cout << std::endl << "Result of triangle operation on " << v1.Evaluate() << " equals " << unary.Evaluate() << std::endl;
}

void testBinaryOperators()
{
	core::ValueModel<int> v1(1);
	core::ValueModel<int> v2(2);

	fuzzy::AggMax<int> aggMax;
	core::ValueModel<int> aggMaxValue = aggMax.Evaluate(&v1, &v2);
	std::cout << std::endl << "Greater in " << v1.Evaluate() << " and " << v2.Evaluate() << " equals " << aggMax.Evaluate(&v1, &v2) << std::endl;

	fuzzy::AggPlus<int> aggPlus;
	core::ValueModel<int> aggPlusValue = aggPlus.Evaluate(&v1, &v2);
	std::cout << std::endl << "Sum of " << v1.Evaluate() << " and " << v2.Evaluate() << " equals " << aggPlus.Evaluate(&v1, &v2) << std::endl;

	fuzzy::AndMin<int> andMin;
	core::ValueModel<int> andMinValue = andMin.Evaluate(&v1, &v2);
	std::cout << std::endl << "Lesser in " << v1.Evaluate() << " and " << v2.Evaluate() << " equals " << andMin.Evaluate(&v1, &v2) << std::endl;

	fuzzy::AndMult<int> andMult;
	core::ValueModel<int> andMultValue = andMult.Evaluate(&v1, &v2);
	std::cout << std::endl << "Product of " << v1.Evaluate() << " and " << v2.Evaluate() << " equals " << andMult.Evaluate(&v1, &v2) << std::endl;

	fuzzy::NotMinus<int> notMinus;
	core::ValueModel<int> notMinusValue = notMinus.Evaluate(&v1);
	std::cout << std::endl << "Result of minus operation on " << v1.Evaluate() << " equals " << notMinus.Evaluate(&v1) << std::endl;

	fuzzy::OrMax<int> orMax;
	core::ValueModel<int> orMaxValue = orMax.Evaluate(&v1, &v2);
	std::cout << std::endl << "Greater in " << v1.Evaluate() << " and " << v2.Evaluate() << " equals " << orMax.Evaluate(&v1, &v2) << std::endl;

	fuzzy::OrPlus<int> orPlus;
	core::ValueModel<int> orPlusValue = orPlus.Evaluate(&v1, &v2);
	std::cout << std::endl << "Sum of " << v1.Evaluate() << " and " << v2.Evaluate() << " equals " << orPlus.Evaluate(&v1, &v2) << std::endl;

	fuzzy::ThenMin<int> thenMin;
	core::ValueModel<int> thenMinValue = thenMin.Evaluate(&v1, &v2);
	std::cout << std::endl << "Lesser in " << v1.Evaluate() << " and " << v2.Evaluate() << " equals " << thenMin.Evaluate(&v1, &v2) << std::endl;

	fuzzy::ThenMult<int> thenMult;
	core::ValueModel<int> thenMultValue = thenMult.Evaluate(&v1, &v2);
	std::cout << std::endl << "Product of " << v1.Evaluate() << " and " << v2.Evaluate() << " equals " << thenMult.Evaluate(&v1, &v2) << std::endl;

	core::BinaryExpressionModel<int> binary(&andMult, &v1, &v2);
	std::cout << std::endl << "Product of " << v1.Evaluate() << " and " << v2.Evaluate() << " equals " << binary.Evaluate() << std::endl;
}

void testDefuzz();

void testMamdani()
{
	//operators
	fuzzy::NotMinus<float> opNot;
	fuzzy::AndMin<float> opAnd;
	fuzzy::OrMax<float> opOr;
	fuzzy::ThenMin<float> opThen;
	fuzzy::AggPlus<float> opAgg;
	fuzzy::CogDefuzz<float> opDefuzz;

	//fuzzy expression factory
	fuzzy::FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);

	//membership function
	//service
	fuzzy::IsTriangle<float> poor(-5, 0, 5);
	fuzzy::IsTriangle<float> good(0, 5, 10);
	fuzzy::IsTriangle<float> excellent(5, 10, 15);
	//food
	fuzzy::IsTriangle<float> rancid(-5, 0, 5);
	fuzzy::IsTriangle<float> delicious(5, 10, 15);
	//tips
	fuzzy::IsTriangle<float> cheap(0, 5, 10);
	fuzzy::IsTriangle<float> average(10, 15, 20);
	fuzzy::IsTriangle<float> generous(20, 25, 30);

	//values
	core::ValueModel<float> service(0);
	core::ValueModel<float> food(0);
	core::ValueModel<float> tips(0);

	core::Expression<float> *r =
		f.NewAgg(
			f.NewAgg(
				f.NewThen(
					f.NewOr(
						f.NewIs(&poor, &service),
						f.NewIs(&rancid, &food)
					),
					f.NewIs(&cheap, &tips)
				),
				f.NewThen(
					f.NewIs(&good, &service),
					f.NewIs(&average, &tips)
				)
			),
			f.NewThen(
				f.NewOr(
					f.NewIs(&excellent, &service),
					f.NewIs(&delicious, &food)
				),
				f.NewIs(&generous, &tips)
			)
		);


	core::Expression<float> *system = f.NewDefuzz(&tips, r, 0, 25, 1);


	float ser, foo;
	std::cout << std::endl << "Mamdani Defuzzification" << std::endl;
	std::cout << "Enter value of service : ";
	std::cin >> ser;
	service.SetValue(ser);
	std::cout << "Enter value of food : ";
	std::cin >> foo;
	food.SetValue(foo);
	std::cout << "Tip calculated using Mamdani defuzzificatoin = " << system->Evaluate() << "%" << std::endl;
	std::cout << "End of Defuzzification" << std::endl << std::endl;

	testDefuzz();

}

void testSugenoDefuzz()
{
	//Operators
	fuzzy::NotMinus<float> opNot;
	fuzzy::AndMin<float> opAnd;
	fuzzy::OrMax<float> opOr;
	fuzzy::SugenoThen<float> opThen;
	fuzzy::AggMax<float> opAgg;
	fuzzy::SugenoDefuzz<float> opSugDefuzz;

	std::vector<float> coef;
	coef.push_back(1);
	coef.push_back(1);
	coef.push_back(1);
	fuzzy::SugenoConclusion<float> opConclusion(&coef);

	//Fuzzy Expression Factory
	fuzzy::FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opSugDefuzz, &opConclusion);

	//Membership functions
	// Service
	fuzzy::IsTriangle<float> poor(-5, 0, 5);
	fuzzy::IsTriangle<float> good(0, 5, 10);
	fuzzy::IsTriangle<float> excellent(5, 10, 15);
	
	// Food
	fuzzy::IsTriangle<float> rancid(-5, 0, 5);
	fuzzy::IsTriangle<float> delicious(5, 10, 15);
	
	//Values
	core::ValueModel<float> service(0);
	core::ValueModel<float> food(0);

	//Output : These variable will store the result of SugenoConclusion (zi)
	std::vector<const core::Expression<float>*> SC_service_food;
	SC_service_food.push_back(&service);
	SC_service_food.push_back(&food);

	std::vector<const core::Expression<float>*> SC_service;
	SC_service.push_back(&service);

	//Rules
	std::vector<const core::Expression<float>*> rules;

	rules.push_back(
		f.NewThen(
			f.NewOr(
				f.NewIs(&poor, &service),
				f.NewIs(&rancid, &food)
			),
			f.NewNConclusion(&SC_service_food)
		)
	);

	rules.push_back(
		f.NewThen(
			f.NewIs(&good, &service),
			f.NewNConclusion(&SC_service)
		)
	);

	rules.push_back(
		f.NewThen(
			f.NewOr(
				f.NewIs(&excellent, &service),
				f.NewIs(&delicious, &food)
			),
			f.NewNConclusion(&SC_service_food)
		)
	);

	//Defuzzification
	core::Expression<float> *system = f.NewSugeno(&rules);

	//Apply input
	float ser, foo;
	std::cout << std::endl << "Sugeno Defuzzification" << std::endl;
	std::cout << "Enter value of service : ";
	std::cin >> ser;
	service.SetValue(ser);
	std::cout << "Enter value of food : ";
	std::cin >> foo;
	food.SetValue(foo);
	std::cout << "Tip calculated using Sugeno defuzzificatoin = " << system->Evaluate() << "%" << std::endl;
	std::cout << "End of Defuzzification" << std::endl << std::endl;

	testDefuzz();
}

void testDefuzz()
{
	unsigned select;
	std::cout << "Choose method of defuzzification: " << std::endl;
	std::cout << "1 for Mamdani" << std::endl;
	std::cout << "2 for Sugeno" << std::endl;
	std::cout << "> ";
	std::cin >> select;

	if (select == 1)
		testMamdani();
	else if (select == 2)
		testSugenoDefuzz();
	else
		testDefuzz();

}


int main() 
{
	
	testDefuzz();

	std::cin.ignore();

	return 0;
}