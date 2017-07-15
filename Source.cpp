#include <stdio.h>
int main(void)
{
	int s[100][100] = { 0 };
	int i, j, i_max;
	int ookii;
	//ƒtƒ@ƒCƒ‹
	FILE *fp;
	if (fopen_s(&fp, "input.txt", "r") == NULL) {
		fscanf_s(fp, "%d", &i_max);
		for (i = 0; i < i_max; i++) {
			for (j = 0; j < i+ 1; j++)
				fscanf_s(fp, "%d", &s[i][j]);
		}
		fclose(fp);
	}

	for (i = i_max - 1; i >= 0; i--) {
		for (j = 0; j < i + 1 ; j++) {
			if (s[i + 1][j] >= s[i + 1][j + 1]) {
				ookii = s[i + 1][j];
			} else {
				ookii = s[i + 1][j + 1];
			}
			s[i][j] += ookii;
		}
	}
	printf("most=%d\n", s[0][0]);
}
