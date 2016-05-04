#include <iostream>
#include <string>

using namespace std;

int sub_string(char* pattern, char* subject)
{
	int n = strlen(subject);
	int m = strlen(pattern);

	for (int i = n-1; i >=m-1; i--) {
		int j = 0;
		cout << "1: " << subject[i - j] << ", 2: " << pattern[m - j - 1] << endl;
		while (j < m && subject[i - j] == pattern[m-j-1]) {
			j++;
		}

		if (j == m) return i;
	}
	return -1;
}


int main() {
	cout << "result: " << sub_string("blbl","df blbl") << endl;
}