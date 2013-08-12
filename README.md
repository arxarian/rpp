TODO
------------------
1. inicializacni sekvence (napr. hbrdisable)
------------------
2. testy

2 DIN0-7 (programmable)
-----------------------

  DIN piny nezapojené

  • Nastavit pull-up, active, zkontrolovat, že ctu 0
  • Nastavit pull-down, active, zkontrolovat, že ctu 0

  DIN piny zapojit na DOUT0-7

  • nastavit tri-state, pull-down, otestovat, že výstup z Hum karty se objeví na DIN vstupu


3 DIN8-15 (switch-to-ground)
----------------------------

  DIN nezapojené

  • nastavit pull-up, active, otestovat, že ctu 0
  • nastavit pull-up, tri-state, otestovat, že ctu 1

  DIN zapojené na DA0-3

  • nastavovat napetí 0, 3, 5, 8, 10 V a otestovat že rozhodovací úroven je 4V
  * nastavit volitelnou rozhodovací úroven na 2, 6 V a testovat DIN vstupy pro
    privedená napetí 1, 3, 5 V nebo 3, 5, 7 V a otestovat že
    volitelná rozhodovací úroven je brána v potaz


7 HOUT1-6 (10A)
------------

  NEZAPOJENÉ VÝSTUPY

  • zapnout, pockat 10 ms, vypnout, pockat 10 ms, zapnout, vždy hodí chybu (príkaz houtfail)
  • nastavit krátkou periodu PWM (2 us), také hodí chybu (alternativa)

  PRIPOJIT ZÁTEŽ (do 100 Ohm)

  • vypnout na 50 ms a pokusit se znovu zapnout, nemel by házet chybu. Zkontrolovat príkazem houtfail. Pripojit paralelne
    testovací desku a kontrolovat PWM pomocí dolnofrekvencních filtru


