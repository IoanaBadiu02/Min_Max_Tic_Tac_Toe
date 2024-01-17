# Min_Max_Tic_Tac_Toe

Jocul de X și 0 folosind algoritmul Min-Max

Despre ”X și 0”
Prezentul proiect reprezintă clasicul joc de ”X și 0” folosind algoritmul Min-Max. Jocul de gândire relativ simplu este constituit dintr-o tabelă cu 3 linii, respectiv 3 coloane. Fiecare rundă, unul dintre jucători marchează o căsuță cu premisa ca jucătorul care reușește primul să marcheze 3 căsute adiacente pe orizontală, verticală sau diagonală caștigă jocul.
Despre Min-Max
Min-Max este un algoritm decisional folosit de obicei în jocurile cu 2 jucători unde targhetul este de a găsi mutarea cea mai optimală, asumând că oponentul folosește deasemenea mutări optimale.

Caracteristici cheie:
1.	Recursivitatea- Funcția ”minmax” este recursivă și explorează toate mișcările posibile din tree-ul jocului, evaluand fiecare nod frunză.
2.	Maximalizarea și Minimizarea jucătorilor – Algoritmul alternează intre maximalizarea si minimizarea șanselor jucatorilor. 
3.	Scorul- Nodurilor frunză le sunt asignate scoruri bazate fie pe câștig, pierdere sau egalitate. Scorurile sunt după propagate în părțile superioare ale tree-ului pentru a determina cea mai bună mișcare.

Observații:
Deși Min-Max are un efecet positiv în găsirea mișcării optimale în cazul tree-urilor de mărimi mici, acest algoritm poate devenii costisitor când avem tree-uri foarte mari. 
De aceea în cazul jocului ”X și 0” unde avem un tree de dimensiuni reduse, algoritmul Min-Max este o alegere optima.
