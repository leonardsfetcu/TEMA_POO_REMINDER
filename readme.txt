--------------README REMINDER---------------------


In implementarea claselor am tinut cont de faptul ca atat Sedinta cat si Apelul reprezinta o Nota.
Astfel, clasa CNota am implementat-o drept o clasa abstracta cu metode virtuale pure de afisare a continutului
 display(), de stocare a continutului intr-un fisier printToFile(), dar si de comparare a doua Note, iar CApel si CSedinta
mostenesc clasa de baza, CNota.
Destructorul clasei abstracte CNota este unul virtual pentru a putea sa eliberez memoria corect.

In clasa CReminder am utilizat un container de tip "list" care retine pointeri de tip CNota*, pointeri ce pot indica
atat spre o zona de memorie unde este alocata o Sedinta, cat si spre o zona de memorie a unui Apel.

Metodele CReminder::addApel si CReminder::addSedinta se folosesc de functia de verificare checkRecord(CNota*), diferentierea
pointerului CNota* dat ca parametru intre un Apel sau o Sedinta se realizeaza pe baza operatorului == implementat la nivelul fiecarei clase de tip nota (CApel, CSedinta, CNota) prin metoda "Double Dispatch". Astfel, identificarea corecta a tipului de zona de memorie catre care pointerul dat ca parametru functiei de verificare se face automat, prin mecanismele de functii virtuale, pe baza "v-table".

Extinderea functionalitatii Reminderului la un SmartReminder am realizat-o mostenind CReminder in CSmartReminder si implementand functiile addSedinta si setWorkInterval. Metoda addSedinta utilizeaza functia de verificare mostenita, checkRecord pentru a determina intervalul de desfasurare al unei Sedinte.