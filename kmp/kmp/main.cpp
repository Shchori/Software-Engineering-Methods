#include <cstdio>
#include <string>
#include<iostream>

using namespace std;


string soundex(string sound_word);
void kmp(string text, string word);
void BruteForce_heb(string text, string word);

int main(int _argc, char* argv[]) {
	cout << "ex1\n";
	cout << "q1.\n";
	string s1 = "brave abrasive abracadabra candelabra", s2 = "abracadabra",
		s3 = "aaaaaaa", s4 = "aabd",
		s5 = "abcdefg", s6 = "xab",
		s7 = "abababa", s8 = "abc",
		s9 = "a string searching example consisting of sample text", s10 = "sting";
	kmp(s1, s2);
	kmp(s3, s4);
	kmp(s5, s6);
	kmp(s7, s8);
	kmp(s9, s10);
	kmp("every day im walking down the street", "down");
	cout << "\n\n\nq2\n";
	BruteForce_heb("אמא שלי את אמא", "אמא");
	BruteForce_heb("בואי תני לי יד ונלך", "תני");
	cout << "\n\n\n\nq3.\n";
		string s[] = { "levi" , "levy"  ,"levine" , "loweb"  ,"lovi",
		"cohen" , "choen" ,"kohen" , "kahana" ,"khan" ,"cownn"
		,"green" , "grin" , "grune" , "grown" ,"geringen" };
		for (int i = 0; i < 16; ++i) {
			cout << "\n	soundex res :	" << soundex(s[i]) << "	-" <<s[i];
		}
	return 0;
}

void kmp(string text, string word) {
	int pattern[256];
	cout << word << "\n" << text << "\n kmp result: \n";
	int k = -1;
	pattern[0] = k;
	for (int i = 1; i < word.length(); ++i) {
		while (k >= 0 && word[k + 1] != word[i])
		{
			k = pattern[k];
		}
		if (word[i] == word[k + 1]) {
			++k;
		}
		pattern[i] = k;
	}
	k = -1;
	for (int i = 0; i <= text.length(); ++i) {
		while (k >= 0 && word[k + 1] != text[i])
		{
			cout << "change start point from " << i - k << " to " << i - pattern[k] << " \n";
			k = pattern[k];
		}
		if (text[i] == word[k + 1]) {
			++k;
		}
		if (k == word.length() - 1) {
			cout << "found match :" << i - k + 1 << "\n";
			k = pattern[k];
		}

	}
	return;
}


void BruteForce_heb(string text, string word) {
	cout << " Brute Force result: \n";
	for (int i = 0; i < text.length() - word.length() + 1; ++i) {
		for (int j = 0; j < word.length() && text[i + j] == word[j]; j++)
		{
			if (j == word.length()-1) {
				cout << "found match :" << i+1 << "\n";
			}
		}

	}
	return;
}



string soundex(string sound_word) {
		int soundex[256] = { 0 };
		for (int i = 1; i < sound_word.length(); i++)
		{
			char c = sound_word[i];
			if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'H' || c == 'h' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u' || c == 'w' || c == 'W' || c == 'Y' || c == 'y') {
				soundex[i] = 0;
			}
			else if (c == 'B' || c == 'b' || c == 'F' || c == 'f' || c == 'P' || c == 'p' || c == 'V' || c == 'v') {
				soundex[i] = 1;
			}
			else if (c == 'C' || c == 'c' || c == 'G' || c == 'g' || c == 'j' || c == 'J' || c == 'K' || c == 'k' || c == 'Q' || c == 'q' || c == 'S' || c == 's' || c == 'X' || c == 'x' || c == 'z' || c == 'Z') {
				soundex[i] = 2;
			}
			else if (c == 'D' || c == 'T' || c == 'd' || c == 't') {
				soundex[i] = 3;
			}
			else if (c == 'L' || c == 'l') {
				soundex[i] = 4;
			}
			else if (c == 'M' || c == 'N' || c == 'n' || c == 'm') {
				soundex[i] = 5;
			}
			else if (c == 'R' || c == 'r') {
				soundex[i] = 6;
			}
		}
		int result[3] = { 0 };
		int i = 1;

		while (i<sound_word.length() && soundex[i] == 0) {
			++i;
		}
		result[0] = soundex[i];
		while (i<sound_word.length() && (soundex[i] == 0 || soundex[i] == result[0])) {
			++i;
		}
		result[1] = soundex[i];
		while (i<sound_word.length() && (soundex[i] == 0 || soundex[i] == result[1])) {
			++i;
		}
		result[2] = soundex[i];
		char str[4] = {0};

		sprintf_s(str, "%d%d%d", result[0], result[1], result[2]);
		string r;
		r.push_back(sound_word[0]);
		r+=str;
		return r;
}
