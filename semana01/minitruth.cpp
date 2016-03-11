#include <iostream>
#include <cstring>

#define MAX2(a,b) ((a) > (b) ? (a) : (b) )
#define MAX3(a,b,c) ( MAX2( (a), MAX2((b), (c)) ) )

using namespace std;

int main() {
	
	int diag, up, left;
	char *utterance = (char *) malloc(sizeof(char) * 100001);
	char *censored_utterance = (char *) malloc(sizeof(char) * 100001);

	scanf("%100000[^\n] %100000[^\n]", utterance, censored_utterance);
	int m = strlen(utterance), n = strlen(censored_utterance);

	int **lcs_mat = (int **) malloc(sizeof(int*) * (m+1) );
	for(int i = 0; i <= m; i++) {
		lcs_mat[i] = (int *) malloc(sizeof(int) * (n+1) );
	}
	for(int i = 0; i <= m; i++) {
		lcs_mat[i][0] = 0;
	}
	for(int i = 0; i <= n; i++) {
		lcs_mat[0][i] = 0;
	}

	//debug
	//printf("m=%i\nn=%i\nUtterance:\n%s\nCensored utterance:\n%s\n", m, n, utterance, censored_utterance);

	utterance -= 1;
	censored_utterance -= 1; // index array at 1 for convenience.

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			diag = utterance[i] == censored_utterance[j] ? 1 + lcs_mat[i-1][j-1] : 0;
			up = lcs_mat[i-1][j];
			left = lcs_mat[i][j-1];
			lcs_mat[i][j] = MAX3(diag,up,left);
		}
	}

	if( lcs_mat[m][n] == n) { //now obtain answer (deletions)
		int i = m, j = n;
		while(i > 0 && j > 0) {
			if( (lcs_mat[i][j] != 1 + lcs_mat[i-1][j-1]) || (utterance[i] != censored_utterance[j]) ) {
				if(utterance[i] != ' ') {
					utterance[i] = '_';
				}

				i--; // we cant miss any of string2, must go up. 
			}
			else {
				//utterance[i] = censored_utterance[j];
				i--;
				j--; // go diagonally
			}
		}
		while(i > 0) {
			utterance[i] = '_';
			i--;
		}
		for(int i = 0; i < m; i++) {
			if(utterance[i] == '_'){
				int j = i;
			while(utterance[i] != ' ' && utterance[i] != '\0')
				while(utterance[i] == '_')
					i++;
				if(utterance[i] != ' ' && utterance[i] != '\0'){
					char temp = utterance[i];
					utterance[i] = utterance[j];
					utterance[j] = temp;
					j++;
				}
			}
		}
		
		printf("%s\n", utterance+1); // we indexed the array at 1 for convenience;
	}
	else {
		printf("I HAVE FAILED\n");
	}

	//debug
	/*for(int ii = 0; ii <= m; ii++) {
		for(int jj = 0; jj <= n; jj++) {
			printf("%i ", lcs_mat[ii][jj]);
		}
		putchar('\n');
	}*/

	utterance += 1;
	censored_utterance += 1; // array indexed at 0 again.

	for(int i = 0; i <= m; i++) {
		free(lcs_mat[i]);
	}
	free(lcs_mat);

	free(utterance);
	free(censored_utterance);

	return 0;
}