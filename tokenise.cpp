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
	vector<string> tokens;
	if(csvFile.is_open()) {
		cout << "File is open" << "\n";
		cout << "Read line start" << "\n";
		while(getline(csvFile, line)){
			tokens = tokenise(line, ',');
			if(tokens.size() != 5) {
				cout << "Bad line" << endl;
				continue;
			}
			double price = stod(tokens[3]);
			double amount = stod(tokens[4]);
			cout << "Price %f" << price << endl;
			cout << "Amount %f" << amount << endl;
//			for(string& t : tokens) {
//				cout << t << endl;
//			}
		}
		
		csvFile.close();
	} else {
		cout << "File could not open" << endl;
	}
	return 0;
}