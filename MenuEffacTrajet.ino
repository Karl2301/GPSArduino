void compterfichier() {
  nbFichiers = compteNbFichiers();
  Serial.print(nbFichiers);  Serial.println(F(" fichiers à la racine"));
  Serial.print(nbFichiers); Serial.print(F("\t"));
  Serial.println(affiFichier(nbFichiers));
  Serial.println(F("\n+ = fichier suivant, - = fichier précédent"));
  noFichier = nbFichiers; // n° de fichier dans la liste, on part du dernier
}

void menueffafichplus() {
  if (++noFichier > nbFichiers) {
    noFichier--;
  }
  nomFichier = affiFichier(noFichier);  // affichage nom fichier indexé par noFichier > 0
  Serial.print(noFichier); Serial.print(F("\t"));
  Serial.println(nomFichier);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Effacer ce trajet?");
  lcd.setCursor(0, 1);
  lcd.print("Traj n: "); lcd.print(noFichier);
  lcd.setCursor(0, 2);
  lcd.print("Nom du trajet: ");
  lcd.setCursor(0, 3);
  lcd.print(nomFichier);
  if(octetFile > 1000) {
    octetFile = octetFile / 1000;
    if(octetFile > 1000) {
      octetFile = octetFile / 1000;
      lcd.setCursor(15, 3);
      lcd.print((int)octetFile); lcd.print("GB");
      //calcule en GB
    }else {
      lcd.setCursor(15, 3);
      lcd.print((int)octetFile); lcd.print("KB");
      //calcule et KB
    }
  }else {
    //calcule en octect
    lcd.setCursor(16, 3);
    lcd.print((int)octetFile); lcd.print("o");
  }
}

void menueffafichmoins() {
  if (--noFichier < 1) {
    noFichier = 1;
  }
  Serial.print(noFichier); Serial.print(F("\t"));
  nomFichier = affiFichier(noFichier);  // affichage nom fichier indexé par noFichier > 0
  Serial.println(nomFichier);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Effacer ce trajet?");
  lcd.setCursor(0, 1);
  lcd.print("Traj n: "); lcd.print(noFichier);
  lcd.setCursor(0, 2);
  lcd.print("Nom du trajet: ");
  lcd.setCursor(0, 3);
  lcd.print(nomFichier);
  if(octetFile > 1000) {
    octetFile = octetFile / 1000;
    if(octetFile > 1000) {
      octetFile = octetFile / 1000;
      lcd.setCursor(15, 3);
      lcd.print((int)octetFile); lcd.print("GB");
      //calcule en GB
    }else {
      lcd.setCursor(15, 3);
      lcd.print((int)octetFile); lcd.print("KB");
      //calcule et KB
    }
  }else {
    //calcule en octect
    lcd.setCursor(16, 3);
    lcd.print((int)octetFile); lcd.print("o");
  }
}

void menueffafich() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Effacer ce trajet?");
  lcd.setCursor(0, 1);
  lcd.print("Traj n: "); lcd.print(noFichier);
  lcd.setCursor(0, 2);
  lcd.print("Nom du trajet: ");
  lcd.setCursor(0, 3);
  lcd.print(nomFichier);
  if(octetFile > 1000) {
    octetFile = octetFile / 1000;
    if(octetFile > 1000) {
      octetFile = octetFile / 1000;
      lcd.setCursor(15, 3);
      lcd.print((int)octetFile); lcd.print("GB");
      //calcule en GB
    }else {
      lcd.setCursor(15, 3);
      lcd.print((int)octetFile); lcd.print("KB");
      //calcule et KB
    }
  }else {
    //calcule en octect
    lcd.setCursor(16, 3);
    lcd.print((int)octetFile); lcd.print("o");
  }
}

void menuenofich() {
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print("Pas de fichier");
  lcd.setCursor(2, 2);
  lcd.print("sur la carte SD");
}
