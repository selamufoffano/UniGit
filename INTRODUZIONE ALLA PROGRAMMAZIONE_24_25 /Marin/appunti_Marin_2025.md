
# Marin: 11.02.2025
### Tipo di dato: 
un insieme di valori a cui viene assegnato un certo valeore e si eseguono delle operazioni
### Dato primitivo: 
### Dato non nativo: 
### Narrowing
che cosa si intende per narrowing 
    char x = `a`;
    char x = 27;
come cpp risolve ? 
    char x {`a};    
    char x {27};  // 
### Cos'è un oggetto in cpp?:
un ogetto in cpp è una qualsiasi aree di memoria a cui viene assegnato un tipo, prende il nome di varibile quando l'oggetto prende nome. 
Esistono oggetti senza nome? (Si,la Malloc in C)

### Bool
bool a;
a = (5>3); // Verrà restituito un valore diverso da zero, quindi è TRUE;

Possiamo anche scrivere:
int x;
x = (5>3); // Verrà restituito un valore diverso da zero, quindi è TRUE;

### Reference
in cpp possiamo scrivere anche come: 
```cpp
int a;
int& b=a; // a è un nome alternativo di b
          // una volta fatto il Refrence non si potrà più modificare, 
          // non si può spostare il Reference a differenza dei puntatori.

// sono dello stesso tipo, quindi modificando la varibaile "a", 
// viene modificato anche il valore della variabile "b"

int k;
b = 12;
```

# 13_02_25
# I cicli For, While & Do-While
### Quali sono gli usi preferenziali dei cicli:
##### - For: 
##### - Whiile:
##### - Do-While:
Il ciclo più potente che abbiamo  in cpp è il ciclo While, bisogna però essere certi delle condizioni di fine ciclo.
Cos'è un linguaggio di Turing completo: Fucked Brain

```c
int a, b;
scanf("%d", &a);
scanf("%d", &b);
While(while){
    if(a>b){
        a=a-b;
    }else{
        b=b-a;
    }
}
printf("%d", a);

// possiamo scrivere lo stesso codice con il ciclo For
for(;a!=b;){} 

// Quali sono i casi in cui il codice non funziona?
/**
a = 0
b = 1
**/ 
// Questo algoritmo di Euclide calcola il (MCD)

```


# 18_02_25

#### LeftValue RightValue
Quando una varibiale è di tipo left o right value?

Differenza tra oggetto varibaile?
. Inizializzare?
. assegnare?

Tutte le varibili sono oggetti ma non viceversa?

Quanti oggetti ho in:
```cpp
int * a=(int) malloc 
// abbiamo due oggetti:
// int a, int malloc  
```

```cpp
int b;
a=6b;
*a=7;

// semantica di un assegnamento: controllo statico

// nel caso in cui abbia (b = b + 1;)

// *(a+1)      a+1
// value      rvalue
// 
```
Quali sono i modi di passaggio dei valori? cpp e c
1) copia/valore
    c: 
    cpp:

    ```cpp
            // parametri formali
    void foo(int a, double b, int* c){


    }
        // parametri effettivi, sono sempre Rightvalue. 
        // Nei parametri effettivi viene controllato dal compilatore che siano compatibili, quindi posso passare un IintNT su un Double
    foo(b, w+s, &c) // alla fine della chiamata della funzione foo, viene distrutta
    ```

2) reference/indirizzo 
    cpp
    ```cpp
    void foo(int a, double b, int* c) // il parametro formale è un aliasi dei paramtri effettivi.
                                      // dovrò dunque passare lo stesso tipo nei parametri formali
                                      // Non viene distrutto niente alla fine dell'esecuzione in quanto andrei a distruggere 
    ```
3) passaggio per nome

(passaggio per indirizzo vs passggio per indirizzo di copia, non sono la stessa cosa.)

#### Operazioni con puntatori:

```
       &
T* + K --> T*

* rvalue --> lvalue
&a + 7

double v[20];
v[8] => *(&v[0]+ 8) = 15.3
```
```
int* b = &a;
int** c = &b;

**c = 14;
 
 
```

malloc free --> stdlib (è possibile creare una variabile di nome malloc o free)
new delete --> nativo del linguaggio. 
Quando bisogna mettere il distruttore? ogni qual'ora nel costruttore viene invocato il (new)

```cpp
// in c:
int * p = (int*)malloc()

// cpp:
int* p = new int[20]

// c:
 free(p)

// cpp:
delete[] p;

```

#### Tipi di oggetti, oggetti si divido in tre categorie:
- globali:
    variabile dichiarata all'esterno di qualsiasi funzione.
- locali/automatici :
    muoiono quando si chiude il blocco dove sono dichiarati
- dinamici : 
    sono gestiti manualmente dal programmatore e sono terminati con il delete?



# 25_02_25
#### Esercizio:
```cpp
void fun2(double* p){
    p= new double [50];
}
int main(){
    double* myv;
    fun2(myv);
    for(int i = 0; i<50; i++){
        myv[i] = 0.0;
    }
    delete[] myv;
    return 0;
}
// in   questo programma ci sono errori logici;
// perchè va in segmantation faull / runtime-error??


// se vengono create due NEW devo eliminare due volte 




void fun2(double*& p){
    p= new double [50];
}
int main(){
    // double myv[50];
    double* myv;
    fun2(myv);
    for(int i = 0; i<50; i++){
        myv[i] = 0.0;
    }
    delete[] myv;
    return 0;
}

```


#### Vector cpp

int c, i vettori sono: 
```c
int v[50];
```

in cpp:
```cpp
int main(){
    std::vector<int> v; // <int> = instansazione di un template;
    // in questo caso la size del vettore è = a 0;
    // se volessi inizializzare un vettore con size = 50:
    std::vector<int> v[50];


    /////////////////////////////////////
    std::vector<int> v;
    v.push_back(22); // la size del vettore è = 1
    v.push_back(3); // possiamo far creascere all'infinito senza conoscere 
                    // la dimensione della memoria da allocare a priori 
                    // v[22, 3]
    v.pop_back(); // per rimuovere un elemento 
    // v[22]

    // un altro metodo per fare la pop è:
    v.at(0) = 3;


    /////////////////////////////
    std::vector<int> v;
    fun(int i=0; i<100; i++){
        v.push_bach(i+1);
    }
    fun(int i=0; i<v.size(); i++){
       cout<<v.at(i)<<endl;
    }


    // perchè usare foreach? 
    for (int& x:v){
        cout<<x<<endl;
    }

}
```

passaggio dei parametri con i vettori

```cpp
// passo by references --> vector<int> & v
// const reference --> const vector<int> & v
// passaggio per coppia  --> vector<inr> v 

// il const uso solo quando ho oggetti grandi
int fun(const vector<int>& v){ // passaggio per copia o per indirizzo? 
    int s = 0;
    for(int x: v){
        s= s+x;
    }
    return s;
}

// è un errore? -->  v.at(3)=s;


// funzione v.resize();
// ho un vettore di size = 10
// facendo una resize posso perdere o aggiungere;
// v[0,7,20,4,20,30,40,50,60,70]
// v.resize(7) --> v[0,7,20,4,20,30,40]
// v.resize(15) --> vv[0,7,20,4,20,30,40,50,60,70, 0, 0, 0, 0, 0]

// funzione distruttore di classe che cos'è? e a cosa serve?
```


# 27_02_25
Algoritmo d'ordinamento boobleSort

Invariante di ciclo:
- come funziona? 

Differenza "at" & "[]"
```cpp
/*
0 1 2 3 4
1 0 6 5 9

0] [1 6 5 9
0 1] [6 5 9
0 1 5] [6 9

dobbiamo considerare il vettore diviso in
due sezioni, |soglia|
*/
void buble(vector<int>& v){
    for(int soglia=0;soglia<v.size(); soglia++){
        // prenod l'elemento più piccolo
        // del range [soglia, size-1] e devo mettere
        // in posizione soglia
        for(int i=size-1;i>soglia.size(); i--){ 
            // come faccio a capire se soglia deve essere ">" 
            // e non ">="
            if(v[i]<v[i-1]){
                swap(v[i], v[i-1]);
            }
        }
    }
}

void swap(int a, int b){
    int c = a;
    a = b;
    b = c;
}


//////////////////////////
// size()-1
void buble(vector<int>& v){
    for(int soglia=0;soglia<v.size()-1; soglia++){
        // prenod l'elemento più piccolo
        // del range [soglia, size-1] e devo mettere
        // in posizione soglia
        for(int i=size-1;i>soglia.size(); i--){ 
            // come faccio a capire se soglia deve essere ">" 
            // e non ">="
            if(v[i]<v[i-1]){
                swap(v[i], v[i-1]);
            }
        }
    }
}

void swap(int a, int b){
    int c = a;
    a = b;
    b = c;
}

// come posso ottimizzare il bobleSort?
// nel caso in cui il vettore sia già ordinato
// come posso uscire dal senza usare il break

void buble(vector<int>& v){
    for(int soglia=0;soglia<v.size() -1 && check; soglia++){
        check = false;
        for(int i=size-1;i>soglia.size(); i--){ 
            if(v.at(i)<v.at(i-1)){
                swap(v[i], v[i-1]);
                check = true;
            }
        }
    }
}
// come posso farlo con il ciclo while ?

// C'è anche un'altro metodo per ottimizzare il bubleSort.
// controllo soglia che sia soglia...



```

#### String in cpp
```cpp
// link documentazione: https://cplusplus.com/reference/string/string/
#include <iostream>
#include <string>

int main(){
    std::string s; // stringa vuota
    s="hello world";
    std::cin>>s;
    // che tipo di errore è possibile avere con le stringe e la
    // memoria? standard Buffer

    std::string s2;
    std::cin>>s2;
    // a differenza di c in cpp è possibile fare il confronto
    // anche la somma, > o <

    // il tipo stringa non è nativo di cpp e quindi è necessario 
    // importare attravero la libreria. 
    // in cpp è possibile inventarsi il tipo e configurare come gli 
    // operatori devono comportarsi
    if(s1==s2){}
    s + s2;
    s < s2;
    s = s2 + "Prova";

    s.size(); 
    s.length(); 
    s.resize();

    s[2] = 'a'; 
    s.at(2) = 'b';

    // come posso fare UPPERCASE di una stringa?
    for(charr& c:s){ 
        // ATTENZIONE!!!!!!, Il prof la conversione di un digit 
        // la volue solo così
        if(c>='a' && c<='z'){
            c = c - 'a' + 'A';
        }
    }
    int a = 'x' *  9;
    char t = '8';
    int v = t-'o'; // in V va a finire il valore 8;
    char k = 8;
}

```

# 04_03_25

#### Ricorsione:
Il codice ricorsivo tende ad essere meno performante di un codice riterativo.

Esistono problemi che possono essere risolti riterativamente e non ricorsivamente, e viceversa? 
No. Ogni programma può essere risolto in entrambi i modi, tuttavia solo se c'è una struttra di dati di tipo stack

Ci sono problemi che non si possono risolvere con la ricorsione / ritarazione? si.. 3° Anno. 


Cos'è una funzione ricorsiva?: Una funzione che richiama se stessa. 


#### Problema della torre di Anode
Quali sono i casi base? Quando sono in grado di solvere senza dover richiamare l'algoritmo ricorsivo. 
Tutti i casi per i quali l'algorimto ricorsivo non funziona sono considerati casi base

```cpp
void anode(int dis, int from, int to, int su){

    if(dis > 1){

    }else{

    }
}

anode(5, 1, 3, 2);
```

#### Problema di Manathan
```cpp
__________(3,3)
|__|__|__|
|__|__|__|
|__|__|__|
(0,0)

// risoluzione con la ricorsione

// risoluzione con l'iterazione 


// Es. in quanti modi posso costruireuna torre alta n di mattoncini
// senza mai mettere due mattonicni rossi consecutivi?

/*
appoggiato mattoncino rosso: il successivo deve esssere per forza blue 
appoggiato mattonicno blue: 
*/

```


# 6_03_25

```cpp
    // esempio del gioco Anoid
    int mattoni (){
        if(){
            if(){

            }else{

            }
        } else {
            return -1; // Zero fattoriale = 1; 
        }
    }
```

#### Ricerca binaria
Ha lo scopo di ricercare all'interno di un vettore con assunzione che il vettore sia ordinato. (Possono esserci due o più elementi uguali)

```cpp
    // posso dividere il vettore in due e verificare se il numero cercato è > o <
    void binary(){

        return 0;
    }

```


#### Tipo strutturato in C

```c
struct Person(){
    char name[20];
    int eta;
}
 Person p;
 p.eta = 20;
 string(p.nome, "Andrea");

 Persona p2;
 p2 = p;

////////////////////



struct Person2(){
    char * nome;
    int eta;
}
 Person2 p, q;
 p.nome = new char[20];
 string (Person2.nome, "Andrea");
 
 q=p;
 string(q.name, "pippo");

 cout<<p.name;


 // che cos'è la shallow copy VS deepcopy
 // Per default è sempre Shallow copy

 Person* punt = new Person;
 punt -> eta = 48;
 (*punt). et = 48;
 p = *punt;

```
```cpp

struct Persona {
    string nome;
    int eta;
    void Presentati(){
        cout<< "Mi chiamo" << nome;
        cout <<"Ho"<<eta<<"Anna";
    }
}
Persona p1, p2;
p1. nome = "Andre";
p1. eta = 40;
p2. nome = "Marco";
p2. eta = 30;

p1.presentati();
p2.presentati();

```
```cpp
// Qualis sono i modificatori di visibilità
// Private (Protected = Private sono in questo corso)
// Public
class Persona { 
    // Quali sono le differenze tra struct e class (cpp)
    // è la politica di visibilità di deafult
    /*
    Struct in (c), dafault() =
    Class in (cpp), dafult() = 
    */
    private string nome;
    public int eta;
    void Presentati(){
        cout<< "Mi chiamo" << nome;
        cout <<"Ho"<<eta<<"Anna";
    }
    void setIdentita(string n, int e){
        nome = n;
        eta = e;
    }
}
////////////////////
class Persona { 
    private string nome;
    public int eta;
    void Presentati() const{ // non modifica lo stato della clsse. 
        cout<< "Mi chiamo" << nome;
        cout <<"Ho"<<eta<<"Anna";
    }
    void setIdentita(string n, int e){
        nome = n;
        eta = e;
    }
}
```


# 13_03_25
#### Overloading che cos'è?
#### Costrutto di deafult?
#### Oggetti globali che cosa sono?
- automatica 
- dinamica 
- globale

#### Ordine dei distruttori
1. Dinamico
2. automatic
3. globali 

le variabili gloabili sono le prime a nascere e le ultime a morire


Il costruttore di dafult a che cosa server? per la retrocompatibilità con c, tra le variabili stract 


#### const come suffisso (parametro di un metodo)
Il const come suffisso del meto permette si che non venga alterato su quel parametro

```cpp
void mystring::print() const {
    std::cout<<ps<<std::endl;
}
```

```cpp
// passo per const refernce
void fool(const mystring& s) {
    std::cout<<ps<<std::endl;
    char p[] = "Prova";
    s.set(p);
    s.print();
}
```

#### Che cos'è copy constructor e qual'è la sua firma?
```cpp
mystring::mystring (const mystring& copy){
    std::cout<<"copy constructor"<<endl;
    size = copy.size;
    ps = new char[size];
    int i;
    for (i=0;copy.ps[i]!='\0'; i++){
        ps[i] = copy.ps[i];
    }
    ps[i] = '\0';
} 
```

Differenza shallow copy vs Deep copy?


# 18/03/25
#### Quando viene chiamato copy constructr? elencare tutti i casi
1. Passaggio per copia
2. inizializzazione 
```cpp
    string s =k; // copy construct. Non è un assegnamento ma un inizializzazione
    string s{k}; 
    string s(k);
```
#### Che cos'è un garbadge in una memoria? 
un dato che è presente nella memoria ma che non è raggiungibile in nussun modo

#### Quali sono i metodi di assegnamento?
right value temporaneo ad un left value

#### Qual'è la differenza tra un copy costructor e un assegnamento?
##### Quando vengono chiamati? 
- In modmenti diversi. Uno esiste già mentre l'altro non esiste ancora

```cpp
// COPY CONSTRUCTOR

mystring::mystring(char* s) {
    int ls = 0;
    while (s[ls]!='\0')
        ls++;

    ps = new mystring[ls+1];
    size = ls +1:

    for (int i=0; i<=ls; i++)
        ps[i] = s[i];

    std::cout<<"Costruttore con parametro char*"<<std::endl;
}

// copy x assegnamento
myString k; // costruttore di dafault
k = foo();

```
L'operatore di assegnamento deve distruggire, senza creare garbadge, e fare la copy.
La differenza sta che il copy costruct fa la copia subito mentre il copy per assegnamento deve prima distruggere la memoria allocata dal costruttore di dafult (con la delate)

Il copy costructor rispetto ad un'assegnamento è più performante dato che non deve fare prima una delete e successivamente fare una new ...

#### Quali sono i tre casi in cui il distruttore viene chiamato in casi di assegnamento?

```cpp
mystring a, b;

a = b; // come avviene l'(=)

class mystring {
    public:


    void():
}
```
Quando faccio un assegnamento (a=b) non faccio altro che chiamare un metodo

```cpp
void mystring::default =(){
    delete ps;
    ps = new char[source.size];
    size = source.size;
    for(int i =0; i<size; i++){
        ps[i]=source.ps[i];
    }
}

int main(){
    string a("hello");
    string b("ciao");

    //Qual'è il caso in cui il codice ci da errore
    a = a; // con l'aauto assegnmento verrbbe prima chiamato il distruttore e quindi una copia di un qualcosa vuoto
    // Non va in segmentationfault. 

    // come si può evitare che a destra e a sinistra ci siano uguali e quindi che si distruggano

    // controllo l'indirizzo di memoria in cui e allocato source e verifico qual'è il mio indirizzo di memoria


    if(this != &source) // protezione dall'auto assegnamento (a=b), quando il left value è uguale al right value // non serve fare ciò se faccio la copia x const refernce
    if(*this != source) // che cosa cambia?

    // Quali sono le differnza? nel primo caso confronto se i due indirizzi siano uguali, mentre nel secondo caso guardo se sono lo stesso oggetto
}
```


# 20_03_2025
#### Che cos'è moveSemantic?
l'assegnamento in c e c++ avviene da destra verso sinistra
```cpp
a=b=7; // prima viene assegnato b=7; poi a=b;

const mystring& mystring::operando (const mystring& s){
    if(this != &s){

    }
    return *this;
}
const mystring& mystring::operando =(const char* x){
}
x="hello world"; // posso farlo in cpp
// in C:
char str[] = "hello";
str = "Hello world";  // non posso farlo 

mystring x, y, z;
z.set("");
x=y=z;
x.=(y.=(z));
```

x=y+z;
x=x+z;

```cpp
        //const mi garantisce la immutabilità di z;     // grantisce immutabilità di y
mystring mystring::operator+(const reference mystring& z) const{
    // ps è un costruttore
    mystring reselat(size+s.size()-1);
    int j=0;
    while(ps[j]!= '\0'){
        result.sp[j]=ps[j];
        j++;
    }

    int i =0;
    while(s[i]!='\0'){
        retrun.ps[j+i]=s.ps[i];
        i++;
    }
    result.ps[i+j]='\0';
    return result;
}
passare
x+y+z  --> (x.operator+(y)).operator+(z)


// posso rendere mystring più efficiente con una const refence?
mystring& mystring::operator+(const reference mystring& z) const{}
// NO
// non posso mai ritornare una refernce come result
// perchè result è una varibaile locale che viene distrutta al termine
```
#### Memory safe?
#### Memory leaks?

#### Liste in C++
lista elementi di tipo T
- lista vuota:
- un elemento di tipo T seguiti da una lista di elementi di tipo T
```c
struct cell(){
    int info;
    cell* next;
};
typedef cell* pcell;


class list {
    public:
        list();
        listint(const listint& l);
        - list();
        void pre(int m);
        void (int n);
        int& at(int n);
        print()
    private:
    pcell head;
};

list int::lsit(){
    head=nullprt;
}

listint::listint(const linstint& l){
    
}
```