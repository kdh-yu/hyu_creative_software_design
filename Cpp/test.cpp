#include <experimental/filesystem>
#include <iostream>
namespace fs = std::experimental::filesystem;

int main() {
	fs::path p = "./";
	std::cerr << fs::absolute(p);
}