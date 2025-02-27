#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::string filename;
	std::string s1;
	std::string s2;

	// Check and get arguments
	if (argc != 4) {
		std::cerr << "Error: invalid arguments.\n" <<
		"./ex04 filename target_string replacement_string" << std::endl;
		return 1;
	} else {
		filename = argv[1];
		s1 = argv[2];
		s2 = argv[3];
	}
	if (s1.empty() || s2.empty()) {
		std::cerr << "Error: empty string/s as arguments." << std::endl;
		return 1;
	}

	// Open input file
	std::ifstream inputFile(filename);
	if (!inputFile) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	// Create output file
	std::ofstream outputFile(filename + ".replace");
	if (!outputFile) {
		std::cerr << "Error: could not create file." << std::endl;
		inputFile.close();
		return 1;
	}

	// Cycle though input file and replace s1 with s2 using append and positions of s1
	std::string line;
	bool firstLine = true;
	while (std::getline(inputFile, line))
	{
		std::string newLine;
		if (!firstLine) newLine.append("\n");
		size_t pos = 0;
		while (pos < line.size())
		{
			size_t occurence = line.find(s1, pos);
			if (occurence != std::string::npos) {
				newLine.append(line, pos, occurence - pos);
				newLine.append(s2);
				pos = occurence + s1.size();
			} else {
				newLine.append(line, pos, line.size() - pos);
				break;
			}
		}
		outputFile << newLine;
		firstLine = false;
	}

	// Close files
	inputFile.close();
	outputFile.close();
	return 0;
}
