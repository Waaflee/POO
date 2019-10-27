#include "../include/FileParser.hpp"
using namespace std;

FileParser::FileParser(std::string filename) {
  string line;
  ifstream inputFile(filename);
  while (getline(inputFile, line)) {
    vector<string> results;
    split(line, ", ", results);
    lines.push_back(results);
  }
  inputFile.close();
}
FileParser::~FileParser(){};

void FileParser::split(std::string str, std::string splitBy,
                       std::vector<std::string> &tokens) {
  tokens.push_back(str);
  size_t splitAt;
  size_t splitLen = splitBy.size();
  std::string frag;
  while (true) {
    frag = tokens.back();
    splitAt = frag.find(splitBy);
    if (splitAt == std::string::npos) {
      break;
    }
    tokens.back() = frag.substr(0, splitAt);
    tokens.push_back(
        frag.substr(splitAt + splitLen, frag.size() - (splitAt + splitLen)));
  }
}
