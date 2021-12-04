void menuSelct1() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Time/Date");
  lcd.setCursor(0, 1);
  lcd.print(" GPS Info");
  lcd.setCursor(0, 2);
  lcd.print(" Nouveau Trajet");
  lcd.setCursor(0, 3);
  lcd.print(" Arreter Trajet");
}

void menuSelct2() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Time/Date");
  lcd.setCursor(0, 1);
  lcd.print(">GPS Info");
  lcd.setCursor(0, 2);
  lcd.print(" Nouveau Trajet");
  lcd.setCursor(0, 3);
  lcd.print(" Arreter Trajet");
}

void menuSelct3() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Time/Date");
  lcd.setCursor(0, 1);
  lcd.print(" GPS Info");
  lcd.setCursor(0, 2);
  lcd.print(">Nouveau Trajet");
  lcd.setCursor(0, 3);
  lcd.print(" Arreter Trajet");
}

void menuSelct4() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Time/Date");
  lcd.setCursor(0, 1);
  lcd.print(" GPS Info");
  lcd.setCursor(0, 2);
  lcd.print(" Nouveau Trajet");
  lcd.setCursor(0, 3);
  lcd.print(">Arreter Trajet");
}

void menuSelct5() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Effacer Trajet");
  lcd.setCursor(0, 1);
  lcd.print(" Redemarrer");
  lcd.setCursor(0, 2);
  lcd.print(" Verrouiller");
  lcd.setCursor(0, 3);
  lcd.print(" Distance");
}

void menuSelct6() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Effacer Trajet");
  lcd.setCursor(0, 1);
  lcd.print(">Redemarrer");
  lcd.setCursor(0, 2);
  lcd.print(" Verrouiller");
  lcd.setCursor(0, 3);
  lcd.print(" Distance");
}

void menuSelct7() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Effacer Trajet");
  lcd.setCursor(0, 1);
  lcd.print(" Redemarrer");
  lcd.setCursor(0, 2);
  lcd.print(">Verrouiller");
  lcd.setCursor(0, 3);
  lcd.print(" Distance");
}

void menuSelct8() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Effacer Trajet");
  lcd.setCursor(0, 1);
  lcd.print(" Redemarrer");
  lcd.setCursor(0, 2);
  lcd.print(" Verrouiller");
  lcd.setCursor(0, 3);
  lcd.print(">Distance");
}

void menuSelct9() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">Changer code");
  lcd.setCursor(0, 1);
  lcd.print(" Changer heure");
  lcd.setCursor(0, 2);
  if (trajet == 2) {
    lcd.print(" Pause trajet");
  } else if (trajet == 4) {
    lcd.print(" Reprendre trajet");
  } else if (trajet == 0) {
    lcd.print(" Pas de trajet");
  }
  lcd.setCursor(0, 3);
  lcd.print(" ");
}

void menuSelct10() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Changer code");
  lcd.setCursor(0, 1);
  lcd.print(">Changer heure");
  lcd.setCursor(0, 2);
  if (trajet == 2) {
    lcd.print(" Pause trajet");
  } else if (trajet == 4) {
    lcd.print(" Reprendre trajet");
  } else if (trajet == 0) {
    lcd.print(" Pas de trajet");
  }
  lcd.setCursor(0, 3);
  lcd.print(" ");
}

void menuSelct11() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Changer code");
  lcd.setCursor(0, 1);
  lcd.print(" Changer heure");
  lcd.setCursor(0, 2);
  if (trajet == 2) {
    lcd.print(">Pause trajet");
  } else if (trajet == 4) {
    lcd.print(">Reprendre trajet");
  } else if (trajet == 0) {
    lcd.print(">Pas de trajet");
  }
  lcd.setCursor(0, 3);
  lcd.print(" ");
}
