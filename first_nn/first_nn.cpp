
#include <iostream>

class IWysylka {
public:
	virtual void wyslij() = 0;
	virtual ~IWysylka() = default;
};

class WysylkaLux : public IWysylka
{
public:
	void wyslij() override
	{
		std::cout << "Wysylka Lux" << std::endl;
	}
	virtual ~WysylkaLux()
	{
		std::cout << " Destruktor dla Wysylka Lux" << std::endl;
	}
};

class WysylkaStandard : public IWysylka
{
public:
	void wyslij() override
	{
		std::cout << "Wysylka Standardowa" << std::endl;
	}
	virtual ~WysylkaStandard()
	{
		std::cout << "Destruktor dla Wysylka Standardowa" << std::endl;
	}
};

class Listonosz
{
public:
	IWysylka* wysylka;
	Listonosz(IWysylka* wysylka)
	{
		this->wysylka = wysylka;
	}

	void wyslij()
	{
		wysylka->wyslij();
	}
};

int main()
{
	auto wysylka = new WysylkaLux;
	auto ptr = std::unique_ptr<WysylkaLux>{ wysylka };
	Listonosz listonosz(wysylka);
	listonosz.wyslij();
}

