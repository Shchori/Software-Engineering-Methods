#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	char c;
	string word, text;
	cout << "please enter your text:\n";
	//cin >> text;
	//cout << "please enter your word:\n";
	//cin >> word;
	//cout << "please chose algoritm\n";
	//cin >> c;
	text = "asdasdsadsadsadsadsadsadsadasdsasdsa";
	word = "asdsasd";
	int textSize= text.size(), 
		wordSize=word.size();
	if (c == '1') {
		//int *kmpR = new int[wordSize];
		int kmpR[10];
		int k = -1;
		kmpR[0] = k;
		for (int i = 1; i < wordSize; i++) {
			while (k > -1 && word[k + 1] != word[i])
				k = kmpR[k];
			if (word[i] == word[k + 1])
				k++;
			kmpR[i] = k;
		}
		k = -1;
		for (int i = 0; i < textSize; i++) {
			while ((k > -1) && (word[k + 1] != text[i])) {
				if (kmpR[k] != -1)cout << "offset :" << k - k - kmpR[k] << "\n";
				k = kmpR[k];
			}
			if (text[i] == word[k + 1])
				k++;
			if (k == textSize - 1) {
				cout << "found match :" << k - i << "\n";
				k = kmpR[k];
			}
		}
		free(kmpR);
	}
	if (c == '2') {
		for (int i = 0; i < textSize-wordSize; i++)
		{
			for (int j= 0;  j < wordSize&&text[i+j] == word[j] ;  j++)
			{
				cout << "found match :" <<  i - j << "\n";
			}
		}
	}
	return 0;
}