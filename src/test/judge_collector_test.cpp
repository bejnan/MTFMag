
#include "../headers/tools.h"
#include "../headers/algorithms.h"
#include "../headers/data_managment.h"

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

BOOST_AUTO_TEST_SUITE_END()

