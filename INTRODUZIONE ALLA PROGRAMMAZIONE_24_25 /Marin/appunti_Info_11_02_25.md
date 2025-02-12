
# Marin: 11.02.2025
### Tipo di dato: 
un insieme di valori a cui viene assegnato un certo valeore e si eseguono delle operazioni
### Dato primitivo: 
### Dato non nativo: 
### Narrowing
che cosa si intende per narrowing 
    char x = `a`;
    char x = 27;
come c++ risolve ? 
    char x {`a};
    char x {27};  // 
### Cos'è un oggetto in C++?:
un ogetto in c++ è una qualsiasi aree di memoria a cui viene assegnato un tipo, prende il nome di varibile quando l'oggetto prende nome. 
Esistono oggetti senza nome? (Si,la Malloc in C)

### Bool
bool a;
a = (5>3); // Verrà restituito un valore diverso da zero, quindi è TRUE;

Possiamo anche scrivere:
int x;
x = (5>3); // Verrà restituito un valore diverso da zero, quindi è TRUE;

### Reference
in C++ possiamo scrivere anche come: 
```c++
int a;
int& b=a; // a è un nome alternativo di b
          // una volta fatto il Refrence non si potrà più modificare, 
          // non si può spostare il Reference a differenza dei puntatori.

// sono dello stesso tipo, quindi modificando la varibaile "a", 
// viene modificato anche il valore della variabile "b"

int k;
b = 12;
```