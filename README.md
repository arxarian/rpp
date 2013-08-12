TODO
------------------
1. inicializacni sekvence (napr. hbrdisable)
------------------
2. testy

2 DIN0-7 (programmable)
-----------------------

  DIN piny nezapojen�

  � Nastavit pull-up, active, zkontrolovat, �e ctu 0
  � Nastavit pull-down, active, zkontrolovat, �e ctu 0

  DIN piny zapojit na DOUT0-7

  � nastavit tri-state, pull-down, otestovat, �e v�stup z Hum karty se objev� na DIN vstupu


3 DIN8-15 (switch-to-ground)
----------------------------

  DIN nezapojen�

  � nastavit pull-up, active, otestovat, �e ctu 0
  � nastavit pull-up, tri-state, otestovat, �e ctu 1

  DIN zapojen� na DA0-3

  � nastavovat napet� 0, 3, 5, 8, 10 V a otestovat �e rozhodovac� �roven je 4V
  * nastavit volitelnou rozhodovac� �roven na 2, 6 V a testovat DIN vstupy pro
    priveden� napet� 1, 3, 5 V nebo 3, 5, 7 V a otestovat �e
    voliteln� rozhodovac� �roven je br�na v potaz


7 HOUT1-6 (10A)
------------

  NEZAPOJEN� V�STUPY

  � zapnout, pockat 10 ms, vypnout, pockat 10 ms, zapnout, v�dy hod� chybu (pr�kaz houtfail)
  � nastavit kr�tkou periodu PWM (2 us), tak� hod� chybu (alternativa)

  PRIPOJIT Z�TE� (do 100 Ohm)

  � vypnout na 50 ms a pokusit se znovu zapnout, nemel by h�zet chybu. Zkontrolovat pr�kazem houtfail. Pripojit paralelne
    testovac� desku a kontrolovat PWM pomoc� dolnofrekvencn�ch filtru


