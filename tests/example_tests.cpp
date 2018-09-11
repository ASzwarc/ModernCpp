#include <gmock/gmock.h>
#include <vector>
#include <string>
#include <algorithm>

/*

class Logger { public:    virtual ~Logger() {};    virtual void log(std::string msg) = 0; };


int fun(Logger& logger, int* arr, size_t size) {
	int result = 0;  if (nullptr == arr)    logger.log("Null pointer error!");  else if (0 == size)    logger.log("Empty table error");  else if (size < 2)    logger.log("Array to small error");  else { int* it1 = arr;    int* it2 = arr + 1;    for (; it2 != arr + size; ++it1, ++it2) { int r = *it1 + *it2;      *it1 = r;      result += r; }    *it1 = 0;    logger.log("Result is " + std::to_string(result)); }
	return result;
}

class LoggerMock : public Logger
{
public:
	MOCK_METHOD1(log, void(std::string));
};

TEST(funTest, jdkjdfkj)
{
	LoggerMock logger;

	EXPECT_CALL(logger, log("Null pointer error!"));

	fun(logger, 0, 0);
}

TEST(funTest, jdkjdfkjss)
{
	::testing::StrictMock<LoggerMock> logger;

	EXPECT_CALL(logger, log("Empty table error"));

	int a;

	fun(logger, &a, 0);
}
*/

/*
struct XMock {
	MOCK_METHOD0(fun, int());
};

struct Fix : ::testing::Test {
	std::vector<int> numbers;
	size_t idx;
	Fix() : idx(0) {}

	int giveNext() {
		return numbers[idx++ % numbers.size()];
	}
};

TEST_F(Fix, testing)
{
	numbers = { 1,2,3,4,5,6,7,8,9 };
	XMock x;
	EXPECT_CALL(x, fun())
		.Times(numbers.size())
		.WillRepeatedly(Invoke(this, &Fix::giveNext));

	ASSERT_THAT(x.fun(), 1);
	ASSERT_THAT(x.fun(), 2);
	ASSERT_THAT(x.fun(), 3);

}
*/


using namespace ::testing;

std::vector<std::string> split(std::string line, char c = ',')
{
	std::vector<std::string> row;

	size_t pos = 0, a = 0;

	do {
		pos = line.find(c, a);
		row.push_back(line.substr(a, pos - a));
		a = pos + 1;
	} while (pos != std::string::npos);

	return row;
}

std::vector<std::vector<std::string>> parseCSV(std::string input)
{
	std::vector<std::vector<std::string>> output;
	if (input.empty()) return output;

	size_t input_offset = 0, input_pos = 0;

	std::vector<std::string> lines = split(input, '\n');
	for (size_t i = 0; i < lines.size(); ++i)
		output.push_back(split(lines[i]));

	return output;
}

struct TestData
{
	std::string scenario;
	std::string input;
	std::vector<std::vector<std::string>> expected;
};

std::ostream& operator<<(std::ostream& out, const TestData& d)
{
	return out << d.scenario << " :: " << d.input;
}

TestData cases[] = { 
	{ "empty string" ,       "1" ,{} },
	{ "one element",       "a",{ { "a" } } },
	{ "two elements in one line",     "a,b",{ { "a", "b" } } },
	{ "three elements",   "1a,b,c",{ { "a", "b", "c" } } },
	{ "two lines" ,   "a\nb" ,{ { "a" },{ "b" } } },
	{ "three lines" ,"a\nb\nc" , { { "a" },{ "b" }, {"c"} } },
};

struct CSVTestsFixture : TestWithParam<TestData>
{
};

TEST_P(CSVTestsFixture, parametrized) {
	auto result = parseCSV(GetParam().input);

	EXPECT_THAT(result, Eq(GetParam().expected)) << "Scenario: " << GetParam().scenario;
}


std::string param_name_generator(const ::testing::TestParamInfo<TestData>& info)
{
	// Note: test names must be non-empty, unique, and may only contain ASCII
	// alphanumeric characters or underscore.
	std::ostringstream msg;
	std::string scenario = info.param.scenario;
	std::replace(scenario.begin(), scenario.end(), ' ', '_');
	msg << info.index << "_" << scenario;
	return msg.str();
}

INSTANTIATE_TEST_CASE_P(PositiveCSVScenarios, CSVTestsFixture, ValuesIn(cases), param_name_generator);








/*
struct Fixture : TestWithParam<vector<int>>
{
	void SetUp() { auto p = GetParam(); }
};

TEST_P(Fixture, parametrized) { }

vector<int> cases[] = { {},{ 1, 2 } };

INSTANTIATE_TEST_CASE_P(ReturnSizeScenarios, Fixture, ValuesIn(cases));
*/



/*

std::vector<int> thresholding(std::vector<int> input, int threshold)
{
	std::vector<int> output;
	return output;
}

using namespace ::testing;

TEST(ThresholdingTests, Empty)
{
	std::vector<int> input;
	std::vector<int> expected;

	std::vector<int> result = thresholding(input, 4);

	ASSERT_THAT(result, Eq(expected));
}

template <typename T, size_t size>
std::vector<T> CArray(const T (&a)[size])
{
	return std::vector<T>(a, a + size);
}

TEST(ThresholdingTests, one_element_below_threshold)
{
	int input[] = { 0 };
	int expected[] = { 0 };

	std::vector<int> result = thresholding(CArray(input), 4);

	ASSERT_THAT(result, Eq(CArray(expected)));
}
*/