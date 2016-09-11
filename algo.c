 #include <stdio.h>

void aglo1(int t[], int n){
	int max = t[0],
		indiceD = 0,
		indiceF = 0,
		indiceCourrantD = 0,
		indiceCourrantF = 0;

	while (indiceCourrantD < n ){
		while (indiceCourrantF < n){
			int maxTmp = 0;
			for (int i = indiceCourrantD; i < indiceCourrantF + 1; ++i) {
				maxTmp += t[i];
			}
			printf(" max tmp = %d\n", maxTmp);
			if (maxTmp > max){
				max = maxTmp;
				indiceD = indiceCourrantD;
				indiceF = indiceCourrantF;
			}
			indiceCourrantF++;
		}
		indiceCourrantF = indiceCourrantD +1;
		indiceCourrantD++;
	}
	printf("Tronçon [%d-%d] max = %d \n",indiceD,indiceF, max );

}

void aglo2(int t[], int n){
	int max = t[0],
		indiceD = 0,
		indiceF = 0,
		indiceCourrantD = 0,
		indiceCourrantF = 0;

	while (indiceCourrantD < n ){
		int tmp = 0;
		while (indiceCourrantF < n){
			int maxTmp = tmp + t[indiceCourrantF];
			printf(" max tmp = %d\n", maxTmp);
			if (maxTmp > max){
				max = maxTmp;
				indiceD = indiceCourrantD;
				indiceF = indiceCourrantF;
			}
			tmp = maxTmp;
			indiceCourrantF++;
		}

		indiceCourrantF = indiceCourrantD +1;
		indiceCourrantD++;
	}
	printf("Tronçon [%d-%d] max = %d \n",indiceD,indiceF, max );
}

void aglo3(int t[], int n){	
	
}

int main()
{
	int tab[4] = {1,5,-6,5};
	for (int i = 0; i < 4; ++i){
		printf("%d - ", tab[i]);
	}
	printf("\n");
	// aglo1(tab,4);
	aglo2(tab,4);
}
