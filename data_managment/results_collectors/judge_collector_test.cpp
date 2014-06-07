#include "data_collector.h"
#include "../data_providers.h"
#include "../data_outputs.h"
#include "judge_collector.h"

#include "../../headers/tools.h"
#include "../../headers/exceptions.h"
#include "../../headers/algorithms.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>

using std::shared_ptr;

BOOST_AUTO_TEST_SUITE(JudgeCollector)

//Test of adding element to JudgeCollector
BOOST_AUTO_TEST_CASE(AddAlgorithm) {
  //initialization
  Tools::Judge* new_judge = new Tools::Tester(20, 20);
  shared_ptr<Tools::Judge> judge_ptr(new_judge);
  Base::JudgeCollector judge_collector(judge_ptr);

  Algorithms::Algorithm* new_algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(new_algorithm);

  Base::DataProvider::DataInputLine test_input(1, 1, 1, 0);

  //test
  judge_collector.AddAlgorithm(algorithm_ptr);

  judge_collector.AnalyseNotification(test_input);

  BOOST_CHECK_EQUAL(Base::Database::GetInstance().QueryAlgorithmNames().front(),
                    algorithm_ptr->GetAlgorithmName());

  Base::Database::GetInstance().ClearDatabase();
}

BOOST_AUTO_TEST_CASE(AnalyseNotificationAndGetResult) {
  //initialization
  Tools::Judge* new_judge = new Tools::Tester(2, 2);
  shared_ptr<Tools::Judge> judge_ptr(new_judge);
  Base::JudgeCollector judge_collector(judge_ptr);

  Algorithms::Algorithm* new_algorithm = new Algorithms::MoveToFront(
      Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(new_algorithm);

  // test
  judge_collector.AddAlgorithm(algorithm_ptr);
  Base::DataProvider::DataInputLine* new_test_input;
  shared_ptr<Base::DataProvider::DataInputLine> test_input_ptr;
  vector<shared_ptr<Base::DataProvider::DataInputLine> > test_input_ptr_store;

  for (int i = 1; i < 5; i++) {
    new_test_input = new Base::DataProvider::DataInputLine(1, 1, 10, i);
    test_input_ptr.reset(new_test_input);
    judge_collector.AnalyseNotification(*test_input_ptr);
    test_input_ptr_store.push_back(test_input_ptr);
  }

  Base::Result result = judge_collector.GetResult(10)->front();

  BOOST_CHECK_EQUAL(result.GetOverallPenalty(), 3);
}

BOOST_AUTO_TEST_SUITE_END()

