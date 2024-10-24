“REGINE IMPRIGIONATE”
ANNO ACCADEMICO 2019/2020

“Descrizione del gioco”
Lo scopo di questo solitario consiste nello spostare tutte le carte del mazzo in 8 pile di base (cioè le pile disposte in alto e in basso alle regine imprigionate) e 4 pile di riserva (sono disposte al centro delle pile di base).    
“Regole”
- Le pile superiori vengono costruite per seme in ordine decrescente dal 5 all’asso (sull’asso si mette il re).                                                                                                           - Le pile inferiori vengono costruite sempre per seme ma in ordine crescente dal 6 al fante.                                                                                                                            – Per le 4 pile di riserva (al centro) si inseriscono solo le regine.                                                      
 – Le carte dal mazzo vengono essere prese una alla volta.                                                                                                            – Sono ammesse solo 2 ridistribuzioni.                                                                               –Delle carte pescate è possibile  spostare solo la carta superiore.
“Descrizione generale del programma”
Nel codice sono state inserite 4 librerie:
- #include <stdio.h>   è l'header file della libreria standard del C che contiene definizioni di macro, costanti e dichiarazioni di funzioni e tipi usati per le varie operazioni di input/output.
- #include <stdlib.h>  è l'header file che dichiara funzioni e costanti di utilità generale: allocazione della memoria, controllo dei processi, e altre funzioni generali comprendenti anche i tipi di dato.
- #include <Windows.h>  header file che contiene le dichiarazioni per le api di windows.
- #include <time.h>  header file che fornisce un accesso standard alle funzioni che gestiscono il tempo, noi lo abbiamo usato per il cronometro.

Sono stati definiti i tasti per l’interazione tra utente e tastiera tramite delle define:
#define INVIO '\r'
#define USCITA '\e'
#define SCELTA2 'r'
#define SPAZIO ' '
Queste “#define” sono state inserite in uno switch con 3 opzioni di scelta. 

Cliccando “INVIO” comparirà il campo da gioco, cliccando “R” verranno mostrate le regole e cliccando su “ESC” il gioco si chiuderà.
Le carte sono state definite attraverso una struct che aggrega in questo caso due puntatori a char, uno indica il valore e l’altro il seme della carta.

Abbiamo dichiarato due array di puntatori a char globali  che contengono le carte e i semi in modo tale da essere viste sia dal main che dalle altre funzioni del codice, esse permetteranno la creazione delle carte all’interno delle funzioni “Inizializzo” e “shuffle”.

“DESCRIZIONE DELLE SINGOLE FUNZIONI”

-int main():
Nel main sono state inserite due chiamate di funzioni (changefont e gioco) e delle api di Windows, le quali possono essere utilizzate tramite la libreria Windows.h, per impostare lo schermo interno in automatico.
Funzioni richiamate
-changefont()
-menu(deck)
Parametri formali
Nessun parametro formale.
Parametri locali
-Card deck[52] è un array di struct che contiene le informazioni sulle carte nel mazzo.
Tipo di ritorno
Valore di ritorno=0.

-void menu (Card deck[ ]):
Descrizione della funzione
Questa funzione visualizza il menù di gioco iniziale. All’interno di questa funzione è presente uno Switch con tre Case (più il default):
1) case(INVIO), tramite questo case viene inizializzato e mischiato il mazzo e viene caricata una nuova partita;
2)case(SCELTA2), tramite questo case vengono visualizzate le regole;
3)case(USCITA), tramite questo case si esce dal gioco;
4)default, viene ricaricato il menù iniziale;
Essa è il fulcro del solitario poiché è una macro funzione (situata all’interno del main) che richiama a se tutte le altre funzioni del programma.
Parametri formali
-Card deck[ ] , questo parametro viene passato dalla funzione menù per poi essere passato da altre funzioni che gestiscono il gioco.
Parametri locali
-int i , è usata nei cicli for per gestire la grafica dell’intro e del menù di gioco.
Tipo di ritorno
Nessun ritorno.

-void visualizza campo():
Descrizione della funzione
Questa funzione permette di stampare il campo da gioco e la sua grafica tramite due cicli “For” annidati (il campo da gioco è una matrice dinamica dichiarata come variabile globale).
Funzioni richiamate
Nessuna funzione richiamata.
Parametri formali
Nessun parametro formale in quanto per la visualizzazione del campo usa variabili globali(Card campo[ ][ ]).
Parametri locali
-int i, j  , sono variabili di servizio usate nel ciclo for annidato. L’indice “i” gestisce il for per le righe, mentre l’indice “j” gestisce il for per le colonne.
Tipo di ritorno
Nessun valore di ritorno.








Diagramma di flusso della funzione visualizza campo():

-void regole():
Descrizione della funzione
Questa funzione contiene la descrizione del regolamento e la sua grafica.
Descrizione dei parametri formali
-Nessun parametro formale.
Variabili locali
-int i: è una variabile di servizio che serve come contatore nei cicli for.
Tipo di ritorno
Nessun ritorno.

-void inizializzo():
Descrizione della funzione
Inizializza il mazzo di carte tramite un ciclo for che ha indice uguale al numero di carte nel mazzo (52).
Parametri formali
-Card deck[ ] 
Parametri locali
-int i è l’indice che rappresenta le 52 carte del mazzo.
Tipo di ritorno
Nessun valore di ritorno.

-void shuffle():
Descrizione della funzione
Esegue un mescolamento totalmente casuale.
Parametri formali
-Card deck[ ]
Parametri locali
-int swapper ,  rappresenta l’indice delle carte da mescolare.
-int i , è il contatore del ciclo for che gestisce il mescolamento del mazzo.
-card temp , viene usata come variabile temporanea.
Tipo di ritorno
Nessun valore di ritorno.
Diagramma di flusso della funzione shuffle():


-void clear():
Descrizione della funzione
Rimuove le carte dal campo da gioco, facendo tornare tutti i valori del campo a “NULL”.
Parametri formali
Nessun parametro formale.
Parametri locali
-int i, j , sono variabili di servizio dei cicli for. L’indice “i” gestisce il for per le righe e l’indice “j” il for per le colonne. 
Tipo di ritorno
Nessun valore di ritorno.












-void gioco(Card deck[ ]):
Descrizione della funzione
Questa funzione gestisce l’intero gioco tramite uno switch con tre case (e il default):
1) case(USCITA), esce dalla partita e torna al menù iniziale, è presente una “If” per confermare la scelta;
2) case(INVIO), chiama la funzione “pesca” per pescare una carta, quest’ultima ritornerà il valore dell’indice i aggiornato;
3) case(SPAZIO), permette di spostare la carta chiamando la funzione “check”che effettuerà tutti i controlli  necessari per verificare la validità della mossa;
4) default, incrementa l’indice “i”
All’interno di questa funzione sono presenti le condizioni di vittoria e sconfitta.
Funzioni richiamate
-stampa_scelte()
-visualizza_campo()
Parametri formali
-Card deck[ ]
Parametri locali
-int i, j
-int N_CARTE  , contiene il numero totale di carte
-C_RIMOSSE=0 ,  questa variabile inizializzata a 0 indica il numero di carte rimosse dal campo.
-tmp=0 , è la variabile temporanea.
Tipo di ritorno
Nessun valore di ritorno.




-void stampa_scelte():
Descrizione della funzione
Questa funzione stampa su schermo, mentre è in corso la partita, una semplice illustrazione dei comandi di gioco, la carta pescata e il numero di carte presenti nel mazzo.


 




-int check (Card deck [ ], int i):
Descrizione della funzione
La funzione controlla la validità delle mosse che effettua l’utente, e se l’utente dovesse compiere un’azione illecita comparirà il messaggio di errore. Se il controllo per la validità della mossa dovesse andare a buon fine il valore della carta diventerà “0”.
Parametri formali
-Card deck [ ]
-int i , questo indice viene passato dalla funzione gioco() e indica la posizione della carta  all’interno del mazzo che si vuole spostare.
Parametri locali
-int x, y rappresentano le coordinate cartesiane del campo da gioco. Le carte verranno spostate tramite coordinate x, y date in input dall’utente. 
Tipo di ritorno
Verrà ritornato il valore 1 se la carta viene effettivamente spostata (inserita nel campo). Verrà ritornato il valore 0, per un qualsiasi motivo, se la carta non verrà spostata. 







Diagramma di flusso della funzione check(Card deck[ ]):

-void pesca():
Descrizione della funzione
Questa funzione permette di pescare le carte dal mazzo. Sono presenti dei controlli per verificare se la carta è stata rimossa (se rimossa il suo valore è “0”), se è stata rimossa, tramite un ciclo “While”, l’indice “i” viene decrementato fino a che non viene trovata una carta che ha un valore diverso da “0”.
Parametri formali
-Card deck [ ]
-int i (questo indice viene passato dalla funzione gioco() e indica la posizione della carta  all’interno del mazzo che si vuole spostare).
Parametri locali
Nessun parametro locale.
Tipo di ritorno
La funzione ritornerà il valore aggiornato dell’indice alla funzione “gioco”.








Diagramma di flusso della funzione pesca():






-void changefont():
Descrizione della funzione
Tramite questa funzione si possono impostare i caratteri raster.


 -void gotoxy ():
Descrizione della funzione
Permette di stampare del testo alle coordinate x, y.


-void selector():
Descrizione della funzione
Permette di modificare il colore del testo della console.


-void vittoria():
Descrizione della funzione
La chiamata di questa funzione avviene all’interno della funzione “gioco”. Quest’ultima viene chiamata quando le 52 carte del mazzo sono state posizionate nel campo e, viene visualizzato il messaggio vittoria insieme ad una simpatica suoneria data dalla combinazione di vari “Beep” e “Sleep”.

 



-void sconfitta():
Descrizione della funzione
La chiamata di questa funzione avviene all’interno della funzione “gioco”. Quest’ultima viene chiamata quando, eseguiti le due ridistribuzioni previste dal regolamento, il giocatore pesca tutte le carte del mazzo e non può effettuare nessuna mossa valida. 
Contiene un semplice messaggio di sconfitta.
Parametri formali
Nessun parametro formale
Parametri locali
Nessun parametro locale
Tipo di ritorno
Nessun valore di ritorno

-void system_time():
Questa funzione permette di calcolare la durata della partita. La funzione time restituisce i secondi trascorsi tra EPOCH (01/01/1970) e l’istante della chiamata alla funzione stessa. A questo punto tramite localtime i secondi vengono passi alla struct tm che li converte in ore, minuti e secondi
Parametri formali
-int t (Può assumere valore “0” oppure “1”. Viene passato lo “0” quando si comincia la partita e “1” quando, per un qualsiasi motivo, la partita viene conclusa. Quando viene passato il valore ”1” vengono effettuati dei calcoli per determinare la durata della partita).
Parametri locali
- Static int tmp1;
Variabile temporanea che contiene l’orario nel momento in cui viene avviata la partita. Dichiarato con l’attributo “Static” per non perdere il valore all’interno della variabile stessa in quanto è necessario per il calcolo della durata della partita.
- int tmp2;
Variabile temporanea che contiene l’orario nel momento in cui viene conclusa la partita per un qualsiasi motivo. 
Tipo di ritorno
Nessun valore di ritorno.
