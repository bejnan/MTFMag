#pragma once

#include "../analisys_runner.h"
#include "../../headers/data_managment.h"

namespace control
{

class ObjectsBuilder
{
public :

	ObjectsBuilder(Base::Configuration configuration);
	void Build();
	AnalisysRunner getAnalisysRunner();

private :

	Base::Configuration build_config;
};


} // namespace control
