#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct data {
	char datum[20];
	char usname[20];
	char imeknj[20];
	char mno[20];
	long int cost;

}a1,a2;


//char datum[20];
//char usname[20];
//char imeknj[20];
//char mno[20];
//long int cost;


void upis() {
	FILE *file;
	char dat[100];
	char usn[20];
	char imek[20];
	char mn[20];
	long int co;

	printf("\n Unesite datum(dd/mm/yyyy): ");
	scanf("%s", &dat);
	printf("Unesi ime kupca :");
	scanf("%s", &usn);
	printf("Unesi sifru knjige :");
	scanf("%s", &mn);
	printf("Unesi naziv knjige :");
	scanf("%s", &imek);
	printf("Unesi cenu knjige :");
	scanf("%ld", &co);

	file = fopen("Podaci.txt", "a");
	fprintf_s(file, "\n%s %s %s %s %ld\n", dat, usn, mn, imek, co);
	printf("\n	   Uspesno upisivanje!");
	fclose(file);
}
	//pretraga po datumu

void prikazi(char da[]){


		FILE *file;
		int rez;
		file = fopen("podaci.txt", "r");

		while (fscanf(file, "\n%s %s %s %s %ld\n", a1.datum, a1.usname, a1.mno, a1.imeknj, &a2.cost) != EOF) {

			rez = strcmp(a1.datum, da);
			if (rez == 0) {

				printf("\n\n Ime kupca = %s", a1.usname);
				printf("\n Sifra knjige = %s", a1.mno);
				printf("\n Naziv knjige = %s", a1.imeknj);
				printf("\n Cena knjige = %ld RSD", a2.cost);


			}
		}
		fclose(file);
	}

void delay(int j) {
	int i, k;
	for (i = 0; i < j; i++) {
		k = i;
	}

}
void main() {
	FILE *file;
	system("color 4");
	char pass[20], passw[20] = "A123acd";
	int i = 0;
	printf("\n\n\t\tUnesite password za login:");
	scanf("%s", pass);
	if (strcmp(pass, passw) == 0) {
		printf("\n\nUneli ste ispravan password\nUcitavanje");
		for (i = 0; i <= 6; i++) {
			delay(100000000);
				printf(".");

		}
		system("cls");

	}
	else {
		main();
	}
	
	system("color 2");
	char ch;
	char im[20];
	do {
		system("cls");  //clear screen

		printf("\t -----Prodavnica Knjiga-----\n");
		printf("\n Pritisni 1 za otvaranje novog rekorda");
		printf("\n Pritisni 2 za prikaz knjiga po datumu");
		printf("\n Pritisni 3 za izlaz");
		printf("\n Pritisni 4 za brisanje svih podataka");

		printf("\n\n Unesi tvoj izbor :");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:upis();
			break;

		case 2:printf("\n Unesi datum(dd/mm/yyyy) :");
			scanf("%s", &im);
			prikazi(im);
			break;

		case 3:exit(0);
		case 4:
			file = fopen("podaci.txt", "w");
			system("cls");
			main();
		default:printf("\n Greska\n");
			system("pause");
			exit(0);
		}
		_getch();
	} 
	while (ch != 0);



}

	


