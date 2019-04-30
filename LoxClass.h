#pragma once
#include "LoxCallable.h"
#include "LoxFunction.h"
#include <string>

class LoxClass : LoxCallable
{
public:
	LoxClass(std::string name, const std::map<std::string, std::shared_ptr<LoxFunction>>& methods)
		: m_name(name),
		  m_methods(methods)
	{}
	virtual ~LoxClass() {}

	std::string ToString()
	{
		return m_name;
	}

	std::shared_ptr<void> Call(const std::shared_ptr<Interpreter>& interpreter, std::vector<std::shared_ptr<Token>> args) override;

	const int GetArity() const override { return 0; };

	std::shared_ptr<LoxFunction> FindMethod(std::string name);

private:
	std::string m_name;
	std::map<std::string, std::shared_ptr<LoxFunction>> m_methods;
};

