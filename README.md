TODO
------------------
1. inicializacni sekvence (napr. hbrdisable, poweron, pinvalVBAT2EN 1, pinvalVBAT3EN 1)
------------------
2. testy

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

4 predelat testy ADIN na sudý a lichý
