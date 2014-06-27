#include <stdlib.h>
#include <stdio.h>


void error () {
	printf("Nespravny vstup.\n");
	exit(1);
}

int main ( void ) {
	int n1;
	int n2;
	int * polA;
	int * polB;
	int * polC;
	int i=0, j=0;
	int sizeA, sizeB, sizeC;

	
	

	printf("Zadejte stupen polynomu A:\n");
	if (scanf("%d", &n1) !=1 || (n1 < 0)){ 
			error();
	}
	sizeA  = n1 + 1;
	polA=(int *) malloc ((sizeA) * sizeof(int));
	printf("Zadejte koeficienty polynomu A:\n");
			for (i=0; i<sizeA; i++){
				if	(scanf("%d", &polA[i]) !=1 ){
				 	error ();
			}	}
		
	printf("Zadejte stupen polynomu B:\n");
	if (scanf("%d", &n2) !=1 || (n2 < 0)) {
				error();
	}
	sizeB = n2 + 1;
	polB=(int *) malloc ((sizeB) * sizeof(int));
	printf("Zadejte koeficienty polynomu B:\n");
			for (j=0; j<sizeB; j++){
				if	(scanf("%d", &polB[j]) !=1){
					error();
				} 
			}
	if ((n1==0) && (n2==0) && (polA[0] ==0) && (polB[0] ==0)){
	printf("0\n");
	return 0;
	}
	sizeC = n1+n2+1;
	
	// the array to store coeffecients of the result polynom polC
    polC = (int*) malloc ( sizeC * sizeof(int) );
	if (polC == NULL) // memory was not allocated for some reason - not programs fault.
		exit (1);
	
	

	for (i=0; i<sizeC; i++) polC[i] = 0; // to set all values of array to zero 

	if (sizeA >= sizeB) {
		for (i = 0; i < sizeA ; i++) {
			for (j = 0; j < sizeB; j++)
				polC[i+j] +=  polA[i]*polB[j];
   		}
	}else {
		for (i = 0; i < sizeB ; i++) {
			for (j = 0; j < sizeA; j++)
				polC[i+j] +=  polB[i]*polA[j];
   		}
	 }
//	printf("pole%d\n",polC[0]);
	if (sizeC==1){
	printf("%d\n",polC[0]);
	return 0;
	}
	

	/* PRINTING OUT THE FINAL RESULT */
	for (i=0; i<sizeC-2; i++) {
		if (polC[i]!=1 && polC[i]!=-1 && polC[i]!=0)
			printf("%dx<sup>%d</sup>", polC[i],(sizeC-1-i));
		else if (polC[i] == 1) 
			printf("x<sup>%d</sup>",(sizeC-1-i));
		else if (polC[i] == -1) 
			printf("-x<sup>%d</sup>",(sizeC-1-i));
		if ((polC[i+1] > 0) && polB[0]!=0 && polA[0]!=0)
			printf("+");
	
	}
	
	if (polC[sizeC-2] !=1 && polC[sizeC-2] !=-1 && polC[sizeC-2] !=0)	
		printf("%dx", polC[sizeC-2]);
	else if (polC[sizeC-2] == -1)
			printf("-x");
	else if (polC[sizeC-2] == 1)
			printf("x");

	if (polC[sizeC-1] > 0)
		printf("+%d\n", polC[sizeC-1]);
	
	if (polC[sizeC-1] < 0)	
		printf("%d", polC[sizeC-1]);
	printf("\n");
	
	
/*	for (i=0;i<sizeC;i++){	
	printf("k=%d ", polC[i]);
	}*/
	free(polA);
	free(polB);	
	free(polC);

return 0;
}
