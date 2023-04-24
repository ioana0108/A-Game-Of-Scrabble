MAIN:

	- am declarat o variabila corespunzatoare
tablei de joc, si o variabila (date_de_intrare)
in care am citit la fiecare task input-ul corespunzator.


	- am citit in matricea date_intrare
prima linie din input (in care se specifica numarul
taskului)

	- am verificat ce este pe prima linie si
in functie de numarul gasit am apelat functia
corespunzatoare task-ului primit.





TASK 0:

	- am parcurs matricea si am introdus 
caracterul '.' pe toate pozitiile.




Functia asaza_pe_tabla():

	- primeste ca parametri matricea, cuvantul de
introdus si coordonatele pentru a insera cuvantul in 
matricea de cuvinte.





TASK 1:

	- am citit atatea linii cate indica numarul
de cuvinte primit

	- am extras "cuvintele" primite folosind
functia strtok(), determinand, astfel, coordonatele
(lin, col, dir) si cuvantul de introdus in matrice

	- in functie de coordonatele extrase am 
introdus cuvintele in matrice pe pozitiile 
specificate in input, apeland functia asaza_in_matrice()





TASK 2:

	- am citit atatea linii cate indica numarul
de cuvinte primit

	- am extras "cuvintele" primite folosind
functia strtok(), determinand, astfel, coordonatele
(lin, col, dir) si cuvantele ale caror scor 
trebuie calculat.

	- am parcurs literele fiecarui cuvant
si am adunat in variabilele SCOR_PLAYER1 si
SCOR_PLAYER2 scorurile corespunzatoare literelor.

	- am determinat carui jucator ii revin
punctele, in functie de paritatea contorului 
folosit in parcurgerea cuvintelor. (pentru i
par, punctajul se aduna la scorul Player-ului 1 si,
respectiv, pentru i impar, la scorul Player-ului 2.



Functia scorcuv():

	- calculeaza scorul unui cuvant cu tot
cu bonusuri

	- am declarat si initializat vectorul de 
bonusuri cu valorile din cerinta

	- am parcurs literele cuvantului si am 
adunat scorul fiecarei litere la scorul final


	- am luat variabilele bonus_1 si bonus_2

	- am verificat prima conditie de bonus
folosind functia strstr()

	- daca indeplinea conditia ca primul
subsir sa se regaseasca in cuvantul caruia i se 
calculeaza scorul, atunci se poate trece la a
verifica daca literele cuvantului se suprapun
cu acele casute din tabla de bonusuri marcate cu
"1".

	- am retinut in variabila bonus_1 de cate
ori o litera din cuvant se suprapune cu o casuta 
de bonus "1", ca in final sa pot dubla scorul
cuvantului (calculat initial adunand scorul fiecarei
lietere) de bonus_1 ori - daca este cazul

	- am verificat a doua conditie de bonus
folosind functia strstr() (desi strcmp() s-ar fi
potrivit in cazul asta)

	- daca indeplinea conditia ca al doilea
subsir sa se regaseasca in finalul cuvantului
caruia i se calculeaza scorul, atunci se poate 
trece la a verifica daca literele cuvantului se 
suprapun cu acele casute din tabla de bonusuri 
marcate cu "2".

	- am retinut in variabila bonus_1 de cate
ori o litera din cuvant se suprapune cu o casuta 
de bonus "2", ca in final sa pot tripla scorul
cuvantului (calculat initial adunand scorul fiecarei
lietere) de bonus_1 ori - daca este cazul





TASK 3:

	- am citit in matricea date_intrare
primele doua linii din input ce contin cele 2
subsiruri

	- am extras subsirurile folosind functia 
strtok()	

	- am procedat ca la task-ul anterior,
doar ca pentru a calcula scorul cu tot cu
bonusuri al fiecarui Player am apelat functia
scorcuv() avand ca parametri cuvantul,
coordonatele cuvantului si cele 2 subsiruri.





TASK 4:

	- am citit datele de intrare

	- am luat o matrice cuv_jucate[][] in care am 
retinut cuvintele deja jucate (cele primite in input)

	- am parcurs cele 100 de cuvinte din vectorul de
cuvinte (words[][]) pentru a gasi primul cuvant care se 
potriveste

	- am verificat intai daca respectivul cuvant nu a
mai fost jucat; in caz contrar se trecea la urmatorul
cuvant fara a mai fi verificate si celelalte conditii

	- am verificat daca prima litera din cuvant exista
deja pe tabla si, apoi, daca avea loc sa fie inserat pe
tabla la pozitia respectiva (am verificat daca putea fi
inserat atat pe linie, cat si pe coloana)

	- odata ce un astfel de cuvant e gasit, variabila
logica "gasit" primeste valoarea 1 iar cautarea se incheie.





Functia gaseste_cuv():

	- in plus fata de task-ul 4, in aceasta functie
am verificat ca urmatorul cuvant sa aiba si cel mai mare
scor posibil. Astfel ca am avut nevoie de 2 variabile:
"maxim" - care memoreaza scorul maxim pe care il poate 
avea cuvantul curent (inserandu-l pe diferite pozitii pe
tabla) si "SCOR_MAX" - care memoreaza scorul maxim posibil
obtinut cu un cuvant din lista.

	- la fiecare pas am comparat scorul retinut in
variabila "maxim" cu valoarea lui "SCOR_MAX" si, daca era
mai mare, SCOR_MAX primea valoarea lui "maxim". Totodata,
am retinut cuvantul si coordonatele cuvantului curent cu 
cel mai mare scor pana la acel moment.

	- la fiecare pas (cand se trece la un cuvant nou)
maxim devine 0 pentru a calcula scorul maxim al cuvantului 
curent si a-l compara cu scorul maxim obtinut de un cuvant
pana atunci, care e retinut in SCOR_MAX

	- la finalul functiei am apelat functia
asaza_pe_tabla(), avand ca parametri cuvantul al carui
scor e retinut in SCOR_MAX si coordonatele sale.





TASK 5:

	- am citit datele de intrare

	- am calculat scorurile Player-ilor apeland 
functia scorcuv()

	- am apelat functia gaseste_cuv() avand drept
parametri matricea, numarul de cuvinte din input, 
matricea in care am retinut cuvintele jucate, cele 2 
subsiruri si o variabila in care va prelua valoarea lui 
SCOR_MAX

	- am adunat scorul cuvantului gasit la scorul
lui Player 2 si am verificat daca este mai mare sau egal
cu scorul lui Player 1. Daca da, atunci se putea afisa 
matricea, altfel era afisat mesajul "Fail!".





TASK 6:

	- am procedat ca in task-ul 5, cu exceptia faptului
ca functia gaseste_cuv trebuia apelat la fiecare dintre cei
nrcuv pasi, adica pentru fiecare cuvant citit din input.

	- totodata, am retinut la fiecare pas si cuvintele 
jucate de Player 2, nu numai cele ale lui Player 1

	- in final am afisat matricea si am verificat care 
dintre jucatori a castigat comparand scorurile.





















