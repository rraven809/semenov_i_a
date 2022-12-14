#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <chrono>

std::pair<double, double> first(std::stringstream& strm) {
	std::vector<int> inp(200001);
	auto start = std::chrono::system_clock::now();
	int n = 0;
	strm >> n;
	std::vector<int> as(200001, -1);
	for (int i = 0; i < n; i += 1) {
		int idx = 0;
		strm >> inp[i];
	}
	auto end = std::chrono::system_clock::now();
	auto t_inp = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	start = std::chrono::system_clock::now();
	for (int i = 0; i < n; i += 1) {
		as[inp[i]] = n - i - 1;
	}
	strm << std::distance(as.begin(),
		std::max_element(as.begin(), as.end()));
	end = std::chrono::system_clock::now();
	auto t_out = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	return std::make_pair(t_inp, t_out);
}