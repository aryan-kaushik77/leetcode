#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b) {
	int lenA = (int)strlen(a);
	int lenB = (int)strlen(b);
	int maxLen = lenA > lenB ? lenA : lenB;

	char *result = (char *)malloc((size_t)maxLen + 2);
	if (result == NULL) {
		return NULL;
	}

	int indexA = lenA - 1;
	int indexB = lenB - 1;
	int indexR = maxLen + 1;
	int carry = 0;

	result[indexR] = '\0';
	indexR--;

	while (indexA >= 0 || indexB >= 0 || carry != 0) {
		int sum = carry;

		if (indexA >= 0) {
			sum += a[indexA] - '0';         // Convert char to int by subtracting '0'
			indexA--;
		}

		if (indexB >= 0) {
			sum += b[indexB] - '0';         // Convert char to int by subtracting '0'
			indexB--;
		}

		result[indexR] = (char)('0' + (sum % 2));  // Convert int to char by adding '0'
		carry = sum / 2;
		indexR--;
	}

	if (indexR + 1 > 0) {       // If there are leading zeros, shift the result to the left
		int start = indexR + 1;
		int write = 0;

		while (result[start] != '\0') {
			result[write] = result[start];
			start++;
			write++;
		}
		result[write] = '\0';
	}

	return result;
}
