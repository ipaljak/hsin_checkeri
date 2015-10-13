Opis izgleda checkera:

Checker prima 3 argumenta:

- ime datoteke u kojoj se nalazi ulazni test podatak
- ime datoteke u kojoj se nalazi sluzbeni izlaz
- ime datoteke u kojoj se nalazi natjecateljevo rjesenje

Checker vraca broj razlicit od 0 ako se dogodila neka greska, npr. checker nije upsio otvoriti datoteku u kojoj se nalazi ulazni test podataci. Inace checker vraca 0 (cak i ako je natjecateljevo rjesenje krivo).

Checker u prvi red standardnog izlaza ispisuje broj izmedju 0 i 1 koji oznacava kolki dio test primjera je natjecatelj osvojio, npr. ako prvi tocan red ispisa nosi 30% bodova na test primjeru, a drugi red ispisa 70% te ako je natjecatelju tocan samo prvi red, onda checker ispisuje 0.3. (u vecini zadataka ce checker ispisivati samo 0 ili 1).

U drugi red standardnog izlaza checker ispisuje poruku (preporucam da ispisujemo tu poruku na engleskom, cisto da smo odma univerzalni).
