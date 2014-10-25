
#include "../headers/data_managment.h"
#include "../headers/controller.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

using namespace Base;

// Method building standard configurations
void BuildAndRun() {
  Base::Configuration configuration;

  configuration.SetElementPrototype(SimpleElement::GetPrototype());

  configuration.SetDataInputMethod(Configuration::DataProvider::FileDataInput);
  configuration.SetDataInputFile("test_input.txt");
  configuration.SetDataOutputMethod(
      Configuration::DataOutput::CSVConsoleDataOutput);
  configuration.SetJudgeFreePositionRange(2);
  configuration.SetJudgeSmallPenaltyPositionRange(2);
  configuration.SetLearnTurns(10);
  configuration.SetRunTurns(10);

  configuration.AddAlgorithm(Algorithms::TreeRoot::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::RandomTreeRoot::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::MoveToFront::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::MTFMatrix::AlgorithmName());

  Base::ResultCollectorBuilder result_builder;

  result_builder.SetConfig(configuration);

  shared_ptr<Base::ResultCollector> result_collector = result_builder
      .GenerateResultCollector();

  result_collector->Run();

  Database::GetInstance().ClearDatabase();
}

BOOST_AUTO_TEST_SUITE(ResultCollectorTest)

//Tests if standard configuration is loaded and run's propertly
BOOST_AUTO_TEST_CASE(ResultCollectionBuild) {
  BOOST_CHECK_NO_THROW(BuildAndRun());
}

BOOST_AUTO_TEST_SUITE_END()
