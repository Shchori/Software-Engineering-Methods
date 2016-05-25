// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

function sub_string(int pattern, int subject)
{
	int n = strlen(subject);
	Int m = strlen(pattern);

	for (int i = 0; i < n - m; i++) {
		int j = 0;
		while (j < m && subject[i + j] == pattern[j]) {
			j++;
		}
		if (j == m) return i;
	}
	return -1;
}


int main()
{

    return 0;
}

