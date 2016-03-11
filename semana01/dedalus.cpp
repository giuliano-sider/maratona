#include <cstdio>

using namespace std;


int main() {
	
	int n, m, readthisint, budget, dedalus_card, diff_budget, estouro;
	int dedalus_total_extra, runningtotal_round;
	//vector<int> current_round;

	while( scanf("%i ", &n) == 1 ) { // while not EOF

		scanf("%i ", &m);
		dedalus_total_extra = 0;
		for(int i = 0; i < m; i++) { //for each round
			
			scanf("%i ", &budget);
			scanf("%i ", &dedalus_card);

			runningtotal_round = dedalus_card;

			for(int j = 0; j < n - 1; j++) {
				scanf("%i ", &readthisint);
				runningtotal_round += readthisint;
				//current_round.push_back(readthis);
			}

			diff_budget = budget - runningtotal_round;
			estouro = -diff_budget;

			if(dedalus_card == 1){
				if(diff_budget >= 9999) {
					dedalus_total_extra += 9999;
				}
				else if(diff_budget >= 999){
					dedalus_total_extra += 999;
				}
				else if(diff_budget >= 99){
					dedalus_total_extra += 99;
				}
				else if(diff_budget >= 9){
					dedalus_total_extra += 9;
				}
			}
			else if(dedalus_card == 10){
				if(diff_budget >= 9990) {
					dedalus_total_extra += 9990;
				}
				else if(diff_budget >= 990){
					dedalus_total_extra += 990;
				}
				else if(diff_budget >= 90){
					dedalus_total_extra += 90;
				}
				
				if(estouro > 0){
					if(estouro <= 9){
						dedalus_total_extra += 1;
					}
				}
			}
			else if(dedalus_card == 100){
				if(diff_budget >= 9900) {
					dedalus_total_extra += 9900;
				}
				else if(diff_budget >= 900){
					dedalus_total_extra += 900;
				}

				if(estouro > 0){
					if(estouro <= 90) {
						dedalus_total_extra += 10;
					}
					else if(estouro <= 99){
						dedalus_total_extra += 1;
					}
				}
			}
			else if(dedalus_card == 1000){
				if(diff_budget >= 9000) {
					dedalus_total_extra += 9000;
				}

				if(estouro > 0){
					if(estouro <= 900) {
						dedalus_total_extra += 100;
					}
					else if(estouro <= 990){
						dedalus_total_extra += 10;
					}
					else if(estouro <= 999){
						dedalus_total_extra += 1;
					}
				}
			}
			else if(dedalus_card == 10000){
				if(estouro > 0){
					if(estouro <= 9000){
						dedalus_total_extra += 1000;
					}
					else if(estouro <= 900) {
						dedalus_total_extra += 100;
					}
					else if(estouro <= 990){
						dedalus_total_extra += 10;
					}
					else if(estouro <= 999){
						dedalus_total_extra += 1;
					}
				}
			}
			







			/*if(diff_budget > 0) { // case of success, can we do better
				if( diff_budget >= 10000) {
					dedalus_total_extra += 10000 - dedalus_card;
				
				}						
				else if( diff_budget >= 1000) {
					if(dedalus_card < 1000)
						dedalus_total_extra += 1000 - dedalus_card;
				}
				else if( diff_budget >= 100) {
					if(dedalus_card < 100)
						dedalus_total_extra += 100 - dedalus_card;
				}
				else if( diff_budget >= 10) {
					if(dedalus_card < 10)
						dedalus_total_extra += 10 - dedalus_card;
						
				}
				else if( diff_budget >= 1) {
					if(dedalus_card < 1)
						dedalus_total_extra += 1 - dedalus_card;
						
				}
			}
			else if(diff_budget < 0) { // case of failure: pare back.
				int estouro = -diff_budget;
				if(dedalus_card == 10000) {
					if(estouro <= 9000) {
						dedalus_total_extra += 1000;
					}
					else if(estouro <= 9900) {
						dedalus_total_extra += 100;
					}
					else if(estouro <= 9990) {
						dedalus_total_extra += 10;
					}
					else if(estouro <= 9999) {
						dedalus_total_extra += 1;
					}
				}
				else if(dedalus_card == 1000) {
					if(estouro <= 9900) {
						dedalus_total_extra += 100;
					}
					else if(estouro <= 9990) {
						dedalus_total_extra += 10;
					}
					else if(estouro <= 9999) {
						dedalus_total_extra += 1;
					}
				}
				else if(dedalus_card == 100) {
					if(estouro <= 9990) {
						dedalus_total_extra += 10;
					}
					else if(estouro <= 9999) {
						dedalus_total_extra += 1;
					}
				}
				else if(dedalus_card == 10) {
					if(estouro <= 9999) {
						dedalus_total_extra += 1;
					}
				}
				else if(dedalus_card == 1) {
					// nothing to do
				}
			}
		}*/
		} // end for loop for round
		printf("%i\n", dedalus_total_extra);



	} // EOF reached.

	return 0;
}