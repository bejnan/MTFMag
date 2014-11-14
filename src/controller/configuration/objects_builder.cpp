#include "objects_builder.h"

using namespace Base;

namespace control {
ObjectsBuilder::ObjectsBuilder(Base::Configuration configuration) :
		build_config(configuration) {
}
;

void ObjectsBuilder::Build() {

}

AnalysisRunner ObjectsBuilder::getAnalysisRunner() {
	return AnalysisRunner();
}

shared_ptr<DataProvider> ObjectsBuilder::GenerateDataProvider(string file_path) {

	switch (build_config.GetDataInputMethod()) {

	case Configuration::DataProvider::ConsoleDataInput:
		return shared_ptr<DataProvider>();

	case Configuration::DataProvider::FileDataInput:
		return std::make_shared<FileDataProvider>(file_path);

	default:
		return shared_ptr<DataProvider>();
	}
}

shared_ptr<DataOutput> ObjectsBuilder::GenerateDataOutput(string file_path) {

	switch (build_config.GetDataOutputMethod()) {

	case Configuration::DataOutput::CSVConsoleDataOutput:
		return std::make_shared<CsvDataOutput>();

	case Configuration::DataOutput::CSVFileDataOoutput:
		return std::make_shared<CsvFileDataOutput>(file_path);

	default:
		return shared_ptr<DataOutput>();
	}
}

shared_ptr<DataCollector> ObjectsBuilder::GenerateDataCollector(shared_ptr<DataProvider> data_provider,
		shared_ptr<DataOutput> data_output) {
	return std::make_shared<DataCollector>(data_provider, data_output);
}

shared_ptr<Tools::Judge> ObjectsBuilder::GenerateJudge(int free_position_range, int small_penalty_range) {

	switch (build_config.GetJudgeSelection()) {
	case Configuration::JudgeSelection::Tester: {
		return std::make_shared<Tools::Tester>(free_position_range, small_penalty_range);
		break;
	}
	default:
		return shared_ptr<Tools::Judge>();
	}
}

shared_ptr<JudgeCollector> ObjectsBuilder::GenerateJudgeCollector(shared_ptr<Tools::Judge> judge_ptr) {
	shared_ptr<JudgeCollector> judge_collector_ptr = std::make_shared<JudgeCollector>(judge_ptr);
	vector<shared_ptr<Algorithms::Algorithm> > available_algorithms = build_config.algorithm();

	for (auto algorithm : available_algorithms) {
		judge_collector_ptr->AddAlgorithm(algorithm);
	}
	return judge_collector_ptr;
}
}

