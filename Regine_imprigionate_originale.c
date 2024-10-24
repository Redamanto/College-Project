#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

// Definisco i vari "tasti" che il giocatore potrà premere
#define INVIO '\r'
#define USCITA '\e'
#define SCELTA2 'r'
#define SPAZIO ' '

// Struttura che contiene gli elementi caratteristici delle carte.
typedef struct card{ 
  char *valore;    
  char *seme;  
} Card;

// Variabili globali
Card campo[3][4]={{{"",""},{"",""},{"",""},{"",""}},
				  {{"",""},{"",""},{"",""},{"",""}},
				  {{"",""},{"",""},{"",""},{"",""}}};
char *valori[52] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
char *semi[4]={"\3", "\4", "\5", "\6"}; 												//array bidimensionale per stringhe di semi

void changefont(){
HANDLE hStdOut= GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_FONT_INFOEX cfie;
ZeroMemory (&cfie, sizeof (cfie));
cfie.cbSize = sizeof (cfie);
lstrcpyW(cfie.FaceName,L"Terminal");
SetCurrentConsoleFontEx(hStdOut, 0, &cfie);;
}

void gotoxy(int x, int y){
	COORD CursorPos={x,y};
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, CursorPos);
}
void selector(unsigned short color){						// Funzione che imposta i colori della console

	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,color);
}
void regole(){												// Funzione che visualizza le regole

	int i;
	printf("\n\n\n");
	system("color ea");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	for(i=0; i<20000000;i++)
	{
	}
	printf("\t\t\t\t\t\t\t±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
		for(i=0; i<20000000;i++)
		{
		}
	printf("\t\t\t\t\t\t\t±±±                                                         ±±±\n");
	    for(i=0; i<20000000;i++)
		{
		}
		printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
		for(i=0; i<20000000;i++)
		{
	    }
    printf("\t\t\t\t\t\t\t±±                  ");
	selector(FOREGROUND_RED|FOREGROUND_INTENSITY);                         
    printf("!!!! SCOPO DEL GIOCO !!!!");
    selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("                ±±\n");
    	
		for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±  Spostare tutte le carte nelle pile di base e di riserva. ±±\n");
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    	for(i=0; i<20000000;i++)
		{
	}
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE);
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}                         
    printf("\t\t\t\t\t\t\t±±                      ");
	selector(FOREGROUND_RED|FOREGROUND_INTENSITY);                                        
    printf("!!!! REGOLE !!!!");
    selector(FOREGROUND_GREEN|FOREGROUND_BLUE);
    printf("                     ±±\n");
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    	for(i=0; i<10000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±± ****** Per le 8 pile di base (in alto e in basso) ******  ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    printf("\t\t\t\t\t\t\t±± ");
    selector(FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("->");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE);    
	printf(" Le pile superiori vengono costruite per seme in ordine ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±    discendente dal cinque all'asso. Sull'asso si mette il ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±    re.                                                    ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±± ");
    selector(FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("->");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE);
	printf(" Le pile inferiori vengono costruite per seme in ordine ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±    ascendente dal sei al fante.                           ±±\n");
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±± ********* Per le 4 pile di riserva (al centro) *********  ±±\n");
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±± ");
    selector(FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("->");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE);
	printf(" Qui si mettono le regine.                              ±±\n");
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±  *********** Mazzo da cui si pescano le carte *********** ±±\n");
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n"); 
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±± ");
    selector(FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("->");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE);
	printf(" Le carte dal mazzo vengono prese una alla volta.       ±±\n");
    for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±± ");
    selector(FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("->");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE);
	printf(" Sono ammesse 2 ridistribuzioni, dopodiche' game over.  ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    for(i=0; i<20000000;i++)
		{
		}
    selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("\t\t\t\t\t\t\t±± ********************* Carte pescate ********************* ±±\n");
    	for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±± ");
    selector(FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("->");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf(" E' possibile spostare solo la carta superiore.         ±±\n");
    selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("\t\t\t\t\t\t\t±±                                                           ±±\n");
    for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±±                                                         ±±±\n");
    for(i=0; i<20000000;i++)
		{
		}
    printf("\t\t\t\t\t\t\t±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
}
void menu(Card deck[]){ 									// Visualizza l'intro con il menù. È una semplice stampa

	int i;
    system("CLS");
	printf("\n");
	selector(FOREGROUND_RED|FOREGROUND_BLUE);
printf("\t\t\t     ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ\n");
selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);                                                                                                                                                                                      


Beep (330,100);Sleep(100);
printf("\t\t\t     ######  ######  ####  # #    # ######     # #    # #####  #####  #  ####  #  ####  #    #   ##  ##### ###### \n"); 
 Beep (330,100);Sleep(300);
 printf("\t\t\t     #     # #      #    # # ##   # #          # ##  ## #    # #    # # #    # # #    # ##   #  #  #   #   #      \n");
 Beep (330,100);Sleep(300);
 printf("\t\t\t     ######  #####  #      # # #  # #####      # # ## # #    # #    # # #      # #    # # #  # #    #  #   #####  \n");	
 Beep (262,100);Sleep(100);
 printf("\t\t\t     #   #   #      #  ### # #  # # #          # #    # #####  #####  # #  ### # #    # #  # # ######  #   #      \n");
 Beep (330,100);Sleep(300);
 printf("\t\t\t     #    #  #      #    # # #   ## #          # #    # #      #   #  # #    # # #    # #   ## #    #  #   #       \n");	  
 Beep (392,100);Sleep(700);
 printf("\t\t\t     #     # ######  ####  # #    # ######     # #    # #      #    # #  ####  #  ####  #    # #    #  #   ###### \n");
 selector(FOREGROUND_RED|FOREGROUND_BLUE);
printf("\t\t\t     ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ\n");    
 Beep (196,100);                                                                                                                                                                                                                                                                                                                      
	printf("\n\n");
	for(i=0; i<200000000;i++)
		{
		}
    selector(FOREGROUND_RED);
	printf("\t\t\t\t\t\t\t\x1b[1m                        \3");
	selector(FOREGROUND_GREEN);
	printf("  \4");
	selector(FOREGROUND_BLUE);
	printf("  \5");
	selector(FOREGROUND_RED|FOREGROUND_BLUE);
	printf("  \6\n\n");
	selector(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\t\t\t\t\t\t\t\t\tÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n");
	printf("\t\t\t\t\t\t\t\t\tº");
	selector(FOREGROUND_GREEN|FOREGROUND_RED);
	printf("\x1b[1m     MENU PRINCIPALE");
	selector(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("     º\n");
    printf("\t\t\t\t\t\t\t\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n");
    selector(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\t\t\t\t\t\t\t\t\tÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n");
	printf("\t\t\t\t\t\t\t\t\tº                         º\n");
	printf("\t\t\t\t\t\t\t\t\tº");
	selector(FOREGROUND_GREEN|FOREGROUND_RED);
	printf("\x1b[1m    - NUOVA PARTITA");
	selector(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("      º");
	selector(FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
	printf("\t\x1b[1m(INVIO)\n");
	selector(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\t\t\t\t\t\t\t\t\tº                         º\n");
	printf("\t\t\t\t\t\t\t\t\tº");
	selector(FOREGROUND_GREEN|FOREGROUND_RED);
	printf("\x1b[1m    - REGOLE");
	selector(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("             º");
	selector(FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
	printf("\t\x1b[1m(R)\n");
	selector(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("\t\t\t\t\t\t\t\t\tº                         º\n");
	printf("\t\t\t\t\t\t\t\t\tº");
	selector(FOREGROUND_GREEN|FOREGROUND_RED);
	printf("\x1b[1m    - ESCI  ");
	selector(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("             º");
	selector(FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
	printf("\t\x1b[1m(ESC)\n");
	selector(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	printf("\t\t\t\t\t\t\t\t\tº                         º\n");
	printf("\t\t\t\t\t\t\t\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n\n\n\n");
	selector(FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
	selector(BACKGROUND_GREEN);
	switch(getch())
	{
	
		case(INVIO):
			system("CLS");
			inizializzo(deck);
			shuffle(deck);
			selector(BACKGROUND_GREEN);
			selector(BACKGROUND_GREEN);
			gioco(deck);
		break;           
		case(SCELTA2):
			system("CLS");	
			regole();
			getch();
			menu(deck);
			system("CLS");
		break;
		case(USCITA):
			selector(BACKGROUND_BLUE);
			system("CLS");
			return;
		default:
			 selector(FOREGROUND_RED|FOREGROUND_BLUE);
            menu(deck);
	}
}
void visualizza_campo(){
	int i,j;
	selector(BACKGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
	gotoxy(50,19);
	printf("\t       [ 1 ]\t       [ 2 ]\t       [ 3 ]\t       [ 4 ]\n");
	selector(FOREGROUND_RED|BACKGROUND_GREEN);
	gotoxy(54,21);
	printf("   ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
	gotoxy(54,22);
	printf("   ³                                                             ³");
	gotoxy(54,23);
	printf("   ³                                                             ³");
	gotoxy(54,24);
	printf("   ³                                                             ³");
	gotoxy(54,25);
	printf("   ³                                                             ³");
	gotoxy(54,26);
	printf("   ³                                                             ³");
	gotoxy(54,27);
	printf("   ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
	gotoxy(54,28);
	printf("   ³                                                             ³");
	gotoxy(54,29);
	printf("   ³                                                             ³");
	gotoxy(54,30);
	printf("   ³                                                             ³");
	gotoxy(54,31);
	printf("   ³                                                             ³");
	gotoxy(54,32);
	printf("   ³                                                             ³");
	gotoxy(54,33);
	printf("   ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
	gotoxy(54,34);
	printf("   ³                                                             ³");
	gotoxy(54,35);
	printf("   ³                                                             ³");
	gotoxy(54,36);
	printf("   ³                                                             ³");
	gotoxy(54,37);
	printf("   ³                                                             ³");
	gotoxy(54,38);
	printf("   ³                                                             ³");
	gotoxy(54,39);
	printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	gotoxy(50,20);
	for(i=0;i<3;i++){
		selector(BACKGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
		printf("\t\t\t\t\t\t\t\n\n\n\n\t\t\t\t\t       [ %i ]",i+1);
		selector(BACKGROUND_GREEN);
		for(j=0;j<4;j++){
			if(campo[i][j].valore!="0")
			{
			selector(FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			printf("\t\t%s %s",campo[i][j].valore,campo[i][j].seme);
			selector(BACKGROUND_GREEN);
		    }
			else
			printf("\t");
			if(j==3)
			printf("\n\n");
		}
    }
}
void inizializzo(Card deck[]){								// Inizializzazione del deck di carta
  int i;
  for(i=0;i<52;i++)
  {
    deck[i].valore = valori[i%13];
    deck[i].seme=semi[i%4];
  }
}
void shuffle(Card deck[]){									// Uso lo pseudo shuffle di carte per l'array
  int swapper = 0; // indice delle carte da mischiare
  int i; // contatore
  Card temp = {"", ""}; // variabile temporanea
  srand(time(NULL)); // impostare i valori random con il tempo attuale
  for(i=0;i<52;i++){
    swapper = rand() % 52; //genero uno pseudo numero da 0 a 51
    temp = deck[i]; //swap con la corrente carta con lo swapper
    deck[i] = deck[swapper];
    deck[swapper] = temp;
  }
}
void stampa_scelte(){										//Stampa i comandi nel menú in-game
selector(BACKGROUND_INTENSITY);
	printf("                                                                 Û                                                                                                                                ");
    printf("                                       Û                                                                                                                                                                                                                                                                              ");
	selector(FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY);
	printf("\n    --->");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|BACKGROUND_INTENSITY);
	printf(" Premere");
	selector(BACKGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED);
	printf(" SPAZIO"); 
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|BACKGROUND_INTENSITY);
	printf(" per spostare la carta");
    selector(BACKGROUND_INTENSITY);
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                           ");
	selector(FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY);
	printf("\n    --->");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|BACKGROUND_INTENSITY);
	printf(" Premere");
	selector(BACKGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);
	printf(" INVIO");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|BACKGROUND_INTENSITY);
	printf(" per pescare una carta                                                                                                                                                                                                                                                                                                                                                                                                                                                                            ");
	selector(FOREGROUND_BLUE|BACKGROUND_INTENSITY);
	printf("\n    --->");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|BACKGROUND_INTENSITY);
	printf(" Premere");
	selector(BACKGROUND_INTENSITY);
	printf(" ESC");
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|BACKGROUND_INTENSITY);
	printf(" per uscire dall'azione o dalla partita                                                                                                                                     ");
	printf("                                                                                                                                                ");                    
	printf("\n                                                                                                                                                                        ");
	selector(BACKGROUND_GREEN);
	printf("ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n\n\t");
	gotoxy(75,2);	  
	selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED);
    printf("\3 \4 \5 \6 CARTA PESCATA \3 \4 \5 \6");
    selector(BACKGROUND_INTENSITY);
    gotoxy(65,7);
    printf("Û");
    gotoxy(65,10);
    printf("Û");
    gotoxy(65,11);
    printf("Û");
    gotoxy(65,8);
    printf("Û");
    gotoxy(65,9);
    printf("Û");
    gotoxy(65,6);
    printf("Û                                                                                                        ");
    gotoxy(65,4);
    printf("Û");
    gotoxy(65,3);
    printf("Û                                 ");
    gotoxy(65,2);
    printf("Û");
    gotoxy(65,5);
    printf("Û");
    gotoxy(65,8);
    printf("Û");
    gotoxy(65,9);
    printf("Û");
    gotoxy(113,7);
    printf("Û");
    gotoxy(113,6);
    printf("Û");
    gotoxy(113,5);
    printf("Û");
    gotoxy(113,8);
    printf("Û");
    gotoxy(113,5);
    printf("Û");
    gotoxy(113,4);
    printf("Û");
    gotoxy(113,3);
    printf("Û");
    gotoxy(113,2);
    printf("Û");
    gotoxy(113,1);
    printf("Û");
    gotoxy(113,9);
    printf("Û");
    gotoxy(113,0);
    printf("Û");
    gotoxy(113,11);
    printf("Û");
    gotoxy(113,10);
    printf("Û");
    gotoxy(167,0);
    printf("Û");
    gotoxy(167,1);
    printf("Û");
    gotoxy(167,2);
    printf("Û");
    gotoxy(167,3);
    printf("Û");
    gotoxy(167,4);
    printf("Û");
    gotoxy(167,5);
    printf("Û");
    gotoxy(167,6);
    printf("Û");
    gotoxy(167,7);
    printf("Û");
    gotoxy(167,8);
    printf("Û");
    gotoxy(167,9);
    printf("Û");
    gotoxy(167,10);
    printf("Û");
    gotoxy(167,11);
    printf("Û");
}
void clear(){												//Funzione che rimuove le carte dal campo
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++){
    campo[i][j].valore = "";
    campo[i][j].seme="";
  }
}
void gioco(Card deck[]){ 									//Funzione con la quale si pesca una carta dal mazzo e gestisce il gioco
	int i, j, N_CARTE,c_rimosse=0,tmp=0;
	stampa_scelte();
	selector(BACKGROUND_GREEN);
	visualizza_campo();
	selector(BACKGROUND_GREEN);
	for(j=0;j<3;j++){
		N_CARTE=52-c_rimosse;
		for(i=51;i>=0;--i){
        	switch(getch()){
				case(USCITA): //questo case permette all'utente di uscire dalla partita e ritornare al menù principale
					selector(BACKGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
					gotoxy(50,49);
		            printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
		            gotoxy(50,50);
		            printf("º                                                                        º");
		            gotoxy(50,51);
		            printf("º                                                                        º");
		            gotoxy(50,52);
		            printf("º                                                                        º");
		            gotoxy(50,53);  
		            printf("º          ");
		            selector(BACKGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
		            printf("Premi di nuovo ESC per confermare e tornare al menu'");
		            selector(BACKGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
		            printf("          º ");
		            gotoxy(50,54);
		            printf("º                                                                        º");
		            gotoxy(50,55);
  	                printf("º                                                                        º");
		            gotoxy(50,56);
		            printf("º                                                                        º");
		            gotoxy(50,57);
                    printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
        			if (getch()==USCITA){  //L'if serve per conferare ulteriormente l'usita da parte dell'utente
        				selector(BACKGROUND_GREEN);
                        gotoxy(60,58);
        				clear();
        				selector(FOREGROUND_RED|FOREGROUND_BLUE);
        				menu(deck);
        				return;
        			}
					else{
						i++;
						system("CLS");
						stampa_scelte();
						selector(BACKGROUND_GREEN);
						visualizza_campo();
						selector(BACKGROUND_GREEN);
						break;
					}

				case(INVIO):	//permette all'utente di premere invio per pescare una carta per volta dal mazzo, a quest'ultima ritornerà il valore dell'indice i aggiornato
					selector(BACKGROUND_GREEN);			
					i=pesca(deck, i);		
					selector(BACKGROUND_GREEN);			
					gotoxy(130,4);		
					selector(BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
					printf("Carte rimanenti: ");
					selector(BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|FOREGROUND_BLUE);
					printf("%i",--N_CARTE);
					gotoxy(130,6);	
					selector(BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
					printf("INDICE: ");
					selector(BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|FOREGROUND_BLUE);
					printf("%i",i);		
					selector(BACKGROUND_GREEN);	
					break;
				case(SPAZIO):  //permette di spostare la carta chiamando la funzione "check"che effettuerà tutti i controlli  necessari per verificare la validità della mossa
					tmp=check(deck,++i);
					if(tmp==1){
						c_rimosse++;
					if(c_rimosse==52){
						vittoria();
						return;
					}
					if(i>=52){
						i=0;
						j--;
						N_CARTE=0;
						}	
						while(strncmp(deck[i].valore,"0",1)==0 && i<51)
							i++;
	
						if(i!=51 && i!=0)
							N_CARTE++;
						i++; //senza questa riga i viene incrementato di 1 e poi decrementato nel for stampando la carta successiva invece di quella precedente
					}
					else{ //condizione per stampare la carta corrente se sbaglio mossa
						i++;
						N_CARTE++;
					}
				break;	
				
						
				default:	//incrementa l'indice i
					i++;
					break;
			}
		}
	}
      		if(j>2){
				sconfitta();
				menu(deck);
			}
}
int pesca(Card deck[], int i){
	system("CLS");
	selector(BACKGROUND_GREEN);
	stampa_scelte();
	selector(BACKGROUND_GREEN);
	visualizza_campo();  			
	if(strncmp(deck[i].valore,"0",1)!=0){
		gotoxy(88,5);
		selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
		printf(" %s %s", deck[i].valore, deck[i].seme);
	}
	else{
		while(strncmp(deck[i].valore,"0",1)==0)
			i--;
		if(i<0)
		return 0;
        selector(BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
        gotoxy(88,5);
		printf(" %s %s", deck[i].valore, deck[i].seme);
	    }
	    return i;
}
int check(Card deck[], int i){								//Funzione che controlla la validitá delle mosse
 
	int x,y;
	if(i>51)
		i=0;
		selector(BACKGROUND_GREEN);
		gotoxy(65,49);
		printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
		gotoxy(65,50);
		printf("º                                º");
		gotoxy(65,51);
		printf("º                                º");
		gotoxy(65,52);
		printf("º                                º");
		gotoxy(65,53);
		printf("º                                º");
		gotoxy(65,54);
		printf("º                                º");
		gotoxy(65,55);
		printf("º                                º");
		gotoxy(65,56);
		printf("º                                º");
		gotoxy(65,57);
        printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
		selector(BACKGROUND_INTENSITY);
		gotoxy(67,50);
		selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
		printf(" Hai selezionato la carta: %s %s ",deck[i].valore,deck[i].seme);
		gotoxy(67,52);
		selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
		printf("Inserisci la riga: ");
   		scanf("%i",&x);
   		gotoxy(67,54);
   		selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_BLUE);
   		printf("Inserisci la colonna: ");
   		scanf("%i",&y);
	   		
  	if(x<1 || x>3 || y<1 || y>4){              
			gotoxy(67,56);
			selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED);
			printf("COORDINATA ERRATA!\n");
			selector(BACKGROUND_GREEN);
  				return 0;
  	}
  	x--;
  	y--;
  			
	//Controllo per la carta '5'
	if(deck[i].valore=="5"){
		if(campo[x][y].valore=="" && x==0){						//controllo per verificare l'assegnamento
			campo[x][y].valore=deck[i].valore;					//assegna al campo la carta
			campo[x][y].seme=deck[i].seme;			//copia il seme della carta scoperta nel campo
			deck[i].valore="0";	
			gotoxy(60,30);								//rimuove la carta posizionata
			Beep(300,100);
			return 1;
		}else
			gotoxy(67,56);
			selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED);
			printf("MOSSA ILLECITA!\n");
			selector(BACKGROUND_GREEN);
			return 0;
	}
	//Controllo per la carta 'Q'
	if(deck[i].valore=="Q"){
		if(campo[x][y].valore=="" && x==1){						//controllo per verificare l'assegnamento
			campo[x][y].valore=deck[i].valore;					//assegna al campo la carta
			campo[x][y].seme=deck[i].seme;			//copia il seme della carta scoperta nel campo
			deck[i].valore="0";									//rimuove la carta posizionata
			Beep(300,100);
			selector(BACKGROUND_GREEN);
			return 1;
		}else
			gotoxy(67,56);
			selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED);
			printf("MOSSA ILLECITA!\n");
			selector(BACKGROUND_GREEN);
			return 0;
	}
	//Controllo per la carta '6'
	if(deck[i].valore=="6"){
		if(campo[x][y].valore=="" && x==2){						//controllo per verificare l'assegnamento
			campo[x][y].valore=deck[i].valore;					//assegna al campo la carta
			campo[x][y].seme=deck[i].seme;			//copia il seme della carta scoperta nel campo
			deck[i].valore="0";									//rimuove la carta posizionata
			Beep(200,100);
			selector(BACKGROUND_GREEN);
			return 1;
		}else
			gotoxy(67,56);
			selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED);
			printf("MOSSA ILLECITA!\n");
			selector(BACKGROUND_GREEN);
			return 0;
	}
	//Controllo per le carte '4','3','2' e '1'		
	if(atoi(deck[i].valore)>0 && atoi(deck[i].valore)<5){							 								//controllo del valore della carta trasformata in intero
		if((atoi(campo[x][y].valore)-1)==atoi(deck[i].valore)  && strncmp(campo[x][y].seme,deck[i].seme,1)==0){		//controllo per spostare la carta, atoi converte stringhe in interi
			campo[x][y].valore=deck[i].valore;										  								//sposta la carta (solo il valore, il seme rimarra sempre lo stesso)
			deck[i].valore="0";
			Beep(200,100);
			selector(BACKGROUND_GREEN);
			return 1;
		}else
			gotoxy(67,56);
			selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED);
			printf("MOSSA ILLECITA!\n");
			selector(BACKGROUND_GREEN);
			return 0;
	}
	//Controllo per le carte '7','8','9' e '10'
	if(atoi(deck[i].valore)>6 && atoi(deck[i].valore)<11){							 								//controllo del valore della carta trasformata in intero con atoi
		if((atoi(campo[x][y].valore)+1)==atoi(deck[i].valore)  && strncmp(campo[x][y].seme,deck[i].seme,1)==0){		//controllo per spostare la carta, atoi converte stringhe in interi
			campo[x][y].valore=deck[i].valore;										 								//sposta la carta (solo il valore, il seme rimarra sempre lo stesso)
			deck[i].valore="0";
			Beep(200,100);
			selector(BACKGROUND_GREEN);
			return 1;																		   
		}else
			gotoxy(67,56);
			selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED);
			printf("MOSSA ILLECITA!\n");
			selector(BACKGROUND_GREEN);
			return 0;
	}		
	//Controllo per la carta 'J'
	if(deck[i].valore=="J"){
		if(campo[x][y].valore=="10" && strncmp(campo[x][y].seme,deck[i].seme,1)==0){		//controllo per verificare l'assegnamento
			campo[x][y].valore=deck[i].valore;												//assegna al campo la carta
			deck[i].valore="0";																//rimuove la carta
			Beep(200,100);
			selector(BACKGROUND_GREEN);
			return 1;
		}else
			gotoxy(67,56);
			selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED);
			printf("MOSSA ILLECITA!\n");
			selector(BACKGROUND_GREEN);
			return 0;
	}		
	//Controllo per la carta 'K'
	if(deck[i].valore=="K"){
		if(campo[x][y].valore=="1" && strncmp(campo[x][y].seme,deck[i].seme,1)==0){			//controllo per verificare l'assegnamento
			campo[x][y].valore=deck[i].valore;												//assegna al campo la carta
			deck[i].valore="0";																//rimuove la carta
			Beep(200,100);
			selector(BACKGROUND_GREEN);
			return 1;
		}else
			gotoxy(67,56);
			selector(BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED);
			printf("MOSSA ILLECITA!\n");
			selector(BACKGROUND_GREEN);
			return 0;						 
	}
}
void vittoria(){
    system("CLS");
    system("color F2");	
	Beep (196,100);Sleep(125);
	Beep (262,100);Sleep(125);
 	Beep (330,100);Sleep(125);	
 	gotoxy(47,20);
printf(" ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ\n\n");
 	Beep (392,100);Sleep(125);
	Beep (523,100);Sleep(125);
	Beep (660,100);Sleep(125);
	selector(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY);  
printf("\t\t\t\t\t\t##     ## #### ######## ########  #######  ########  ####    ###     ####\n");
	Beep (784,100);Sleep(575);
printf("\t\t\t\t\t\t##     ##  ##     ##       ##    ##     ## ##     ##  ##    ## ##    ####\n");
	Beep (660,100);Sleep(575);
printf("\t\t\t\t\t\t##     ##  ##     ##       ##    ##     ## ##     ##  ##   ##   ##   ####\n");
 	Beep (207,100);Sleep(125);
	Beep (262,100);Sleep(125);
 	Beep (311,100);Sleep(125);
printf("\t\t\t\t\t\t##     ##  ##     ##       ##    ##     ## ########   ##  ##     ##   ##\n");
	Beep (415,100);Sleep(125);
	Beep (523,100);Sleep(125);
	Beep (622,100);Sleep(125);
printf("\t\t\t\t\t\t ##   ##   ##     ##       ##    ##     ## ##   ##    ##  #########      \n");
	Beep (830,100);Sleep(575);
printf("\t\t\t\t\t\t  ## ##    ##     ##       ##    ##     ## ##    ##   ##  ##     ##  ####\n");
	Beep (622,100);Sleep(575);
printf("\t\t\t\t\t\t   ###    ####    ##       ##     #######  ##     ## #### ##     ##  ####\n");
	Beep (233,100);Sleep(125);
	Beep (294,100);Sleep(125);
	Beep (349,100);Sleep(125);
	selector(FOREGROUND_RED|FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
printf("\n\t\t\t\t\t\tÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ\n");
	Beep (466,100);Sleep(125);
	Beep (587,100);Sleep(125);
	Beep (698,100);Sleep(125);
	Beep (932,100);Sleep(575);
	Beep (932,100);Sleep(125);
	Beep (932,100);Sleep(125);
	Beep (932,100);Sleep(125);
	Beep (1046,675);
	selector(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	return;
}
void sconfitta(){
	system("CLS");
    clear();
    system("color 0f");
    selector(FOREGROUND_RED);
	gotoxy(45,20);
	printf("#        #      #      #########        #########  ######### #########   ########   ##########");
	Sleep(200);
	gotoxy(45,21);
	printf("#        #     # #         #            #        # #         #        # #          #          #");
	Sleep(200);
	gotoxy(45,22);
	printf("#        #     # #         #            #        # #         #        # #          #          #");
	Sleep(200);
	gotoxy(45,23);
	printf("#        #    #   #        #            #        # #         #        # #          #          #");
	Sleep(200);
	gotoxy(45,24);
	printf("#        #    #   #        #            #      ##  #         #    ####   ##        #          #");
	Sleep(200);
	gotoxy(45,25);
	printf("##########   #     #       #            #######    ######### #   #         ##      #          #");
	Sleep(200);
	gotoxy(45,26);
	printf("#        #   #######       #            #          #         #    #          ##    #          #");
	Sleep(200);
	gotoxy(45,27);
	printf("#        #  #       #      #            #          #         #     #           ##  #          #");
	Sleep(200);
	gotoxy(45,28);
	printf("#        #  #       #      #            #          #         #      #            # #          #");
	Sleep(200);
	gotoxy(45,29);
	printf("#        # #         #     #            #          #         #       #           # #          #");
	Sleep(200);
	gotoxy(45,30);
	printf("#        # #         # #########        #          ######### #        # #########   ##########");	
	Sleep(200);			
    getch();
	selector(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

int main (){
  changefont();
  //Imposta, grazie all'header file "Windows.h, il fullscreen in automatico della console
  system("mode con COLS=700");
  ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
  SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
  
  Card deck[52] ={"",""}; //dichiaro l'array nel main mazzo di 52 carte
  menu(deck);	
  return 0;
}
