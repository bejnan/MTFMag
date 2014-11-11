#include "objects_builder.h"

namespace control
{
	ObjectsBuilder::ObjectsBuilder(Base::Configuration configuration) : build_config(configuration) { };

	void ObjectsBuilder::Build()
	{

	}

	AnalisysRunner ObjectsBuilder::getAnalisysRunner()
	{
		return AnalisysRunner();
	}
}


