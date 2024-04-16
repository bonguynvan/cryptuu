#include "string"
#include "vector"
#include "iostream"
#include "fstream"

using namespace std;
vector<string> tokenise(string csvLine, char separator) {
	vector<string> tokens;
	int start, end;
	string token;
	
	start = csvLine.find_first_not_of(separator, 0);
	do {
		end = csvLine.find_first_of(separator, start);
		if(start == csvLine.length() || start == end) break;
		if(end >= 0) {
			token = csvLine.substr(start, end - start);
		} else {
			token = csvLine.substr(start, csvLine.length() - start);
		}
		start = end+1;
		tokens.push_back(token);
	} while (end != string::npos);
	
	return tokens;
}

int main() {
//	vector<string> tokens;
//	string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
//	tokens = tokenise(s, ',');
//	for(string& t : tokens) {
//		cout << t << "\n";
//	}
	string line;
	ifstream csvFile{"20200317.csv"};
	if(csvFile.is_open()) {
		cout << "File is open" << "\n";
		cout << "Read line " << "\n";
		getline(csvFile, line);
		cout << line << endl;
		csvFile.close();
	} else {
		cout << "File could not open" << endl;
	}
	return 0;
}