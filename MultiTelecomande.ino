void multiTel() {
  String numfiletelopen = String("/p/json") + numfiletel + ".txt";
  String input = SD.open(numfiletelopen, FILE_READ).readStringUntil('\n'); Serial.print("Json: "); Serial.println(input);
  delay(100);
  DynamicJsonDocument doc(1024);

  // You can use a String as your JSON input.
  // WARNING: the string in the input  will be duplicated in the JsonDocument.
  deserializeJson(doc, input);
  JsonObject obj = doc.as<JsonObject>();

  String chmoins = obj["ch-"];
  chmoins = obj["ch-"].as<String>();
  String chplus = obj["ch+"];
  chplus = obj["ch+"].as<String>();
  String ch = obj["ch"];
  ch = obj["ch"].as<String>();
  String arriere = obj["arriere"];
  arriere = obj["arriere"].as<String>();
  String avant = obj["avant"];
  avant = obj["avant"].as<String>();
  String plus = obj["plus"];
  plus = obj["plus"].as<String>();
  String moins = obj["moins"];
  moins = obj["moins"].as<String>();
  String eq = obj["eq"];
  eq = obj["eq"].as<String>();
  String lecture = obj["pause"];
  lecture = obj["pause"].as<String>();
  String zero = obj["zero"];
  zero = obj["zero"].as<String>();
  String un = obj["un"];
  un = obj["un"].as<String>();
  String deux = obj["deux"];
  deux = obj["deux"].as<String>();
  String trois = obj["trois"];
  trois = obj["trois"].as<String>();
  String quatre = obj["quatre"];
  quatre = obj["quatre"].as<String>();
  String cinq = obj["cinq"];
  cinq = obj["cinq"].as<String>();
  String six = obj["six"];
  six = obj["six"].as<String>();
  String sept = obj["sept"];
  sept = obj["sept"].as<String>();
  String huit = obj["huit"];
  huit = obj["huit"].as<String>();
  String neuf = obj["neuf"];
  neuf = obj["neuf"].as<String>();

  Serial.println("chmoins : "); Serial.println(chmoins);
  Serial.println("chplus : "); Serial.println(chplus);
  Serial.println("ch : "); Serial.println(ch);
  Serial.println("arriere : "); Serial.println(arriere);
  Serial.println("avant : "); Serial.println(avant);
  Serial.println("plus : "); Serial.println(plus);
  Serial.println("moins : "); Serial.println(moins);
  Serial.println("lecture : "); Serial.println(lecture);
  Serial.println("eq : "); Serial.println(eq);
  Serial.println("zero : "); Serial.println(zero);
  Serial.println("un : "); Serial.println(un);
  Serial.println("deux : "); Serial.println(deux);
  Serial.println("trois : "); Serial.println(trois);
  Serial.println("quatre : "); Serial.println(quatre);
  Serial.println("cinq : "); Serial.println(cinq);
  Serial.println("six : "); Serial.println(six);
  Serial.println("sept : "); Serial.println(sept);
  Serial.println("huit : "); Serial.println(huit);
  Serial.println("neuf : "); Serial.println(neuf);

  IRdatatel += chmoins + " " + chplus + " " + ch + " " + arriere + " " + avant + " " + plus + " " + moins + " " + lecture + " " + eq + " " + zero + " " + un + " " + deux + " " + trois + " " + quatre + " " + cinq + " " + six + " " + sept + " " + huit + " " + neuf + " ";
  Serial.print("IRdattel: "); Serial.println(IRdatatel);
  String numfileexists = String("/p/json") + (numfiletel + 1) + ".txt";
  if (SD.exists(numfileexists)) {
    numfiletel = numfiletel + 1;
    Serial.println("Le fichier : "); Serial.print(numfileexists); Serial.println(" existes, lecture de ce fichier ...");
  } else {
    numtel = 0;
    Serial.println("Le fichier : "); Serial.print(numfileexists); Serial.println(" n'existes, abandon.");
  }
}

void numeroenter() {
  String newch, newchmoins, newchplus, newarriere, newavant, newpause, newplus, newmoins, neweq, newzero, newun, newdeux, newtrois, newquatre, newcinq, newsix, newsept, newhuit, newneuf;
  if (numtelenter == 1) {
    menutelch();
  } else if (numtelenter == 2) {
    menutelchmoins();
    newch = tablenewtel[0];
  } else if (numtelenter == 3) {
    menutelchplus();
    newchmoins = tablenewtel[1];
  } else if (numtelenter == 4) {
    menutelarriere();
    newchplus = tablenewtel[2];
  } else if (numtelenter == 5) {
    menutelavant();
    newarriere = tablenewtel[3];
  } else if (numtelenter == 6) {
    menutelpause();
    newavant = tablenewtel[4];
  } else if (numtelenter == 7) {
    menutelmoins();
    newpause = tablenewtel[5];
  } else if (numtelenter == 8) {
    menutelplus();
    newmoins = tablenewtel[6];
  } else if (numtelenter == 9) {
    menuteleq();
    newplus = tablenewtel[7];
  } else if (numtelenter == 10) {
    menutelzero();
    neweq = tablenewtel[8];
  } else if (numtelenter == 11) {
    menutelun();
    newzero = tablenewtel[9];
  } else if (numtelenter == 12) {
    menuteldeux();
    newun = tablenewtel[10];
  } else if (numtelenter == 13) {
    menuteltrois();
    newdeux = tablenewtel[11];
  } else if (numtelenter == 14) {
    menutelquatre();
    newtrois = tablenewtel[12];
  } else if (numtelenter == 15) {
    menutelcinq();
    newquatre = tablenewtel[13];
  } else if (numtelenter == 16) {
    menutelsix();
    newcinq = tablenewtel[14];
  } else if (numtelenter == 17) {
    menutelsept();
    newsix = tablenewtel[15];
  } else if (numtelenter == 18) {
    menutelhuit();
    newsept = tablenewtel[16];
  } else if (numtelenter == 19) {
    menutelneuf();
    newhuit = tablenewtel[17];
  } else if (numtelenter == 20) {
    newneuf = tablenewtel[18];
    numfiletel = 0;
    int numtelsave = 0;
    String numfileexists = "";
    while (numtelsave == 0) {
      numfileexists = String("/p/json") + (numfiletel + 1) + ".txt";
      if (SD.exists(numfileexists)) {
        numfiletel = numfiletel + 1;
        Serial.println("Le fichier : "); Serial.print(numfileexists); Serial.println(" existes, lecture de ce fichier ...");
      } else {
        numtelsave = 1;
        Serial.println("Le fichier : "); Serial.print(numfileexists); Serial.println(" n'existes pas, abandon.");
      }
    }
   /* myFile = SD.open("/p/examplejson.txt", FILE_READ);
    if (myFile) {
      while (myFile.available()) {
        String example = myFile.readStringUntil('\r');
        example = example.replace("AAA", newchmoins);
        example = example.replace("BBB", newchplus);
        example = example.replace("CCC", newch);
        example = example.replace("DDD", newarriere);
        example = example.replace("EEE", newavant);
        example = example.replace("FFF", newpause);
        example = example.replace("GGG", newmoins);
        example = example.replace("HHH", newplus);
        example = example.replace("III", neweq);
        example = example.replace("JJJ", newzero);
        example = example.replace("KKK", newun);
        example = example.replace("LLL", newdeux);
        example = example.replace("MMM", newtrois);
        example = example.replace("NNN", newquatre);
        example = example.replace("OOO", newcinq);
        example = example.replace("PPP", newsix);
        example = example.replace("QQQ", newsept);
        example = example.replace("RRR", newhuit);
        example = example.replace("SSS", newneuf);
      }
      myFile.close();
    }
    */
    delay(1000);
    menuselector = 0;
    decalecatam = 0;
    numtelenter = 0;
    nouvtel = 0;
    rafmenu();
  }
}

void menutelch() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: ch ( OK )");
}

void menutelchmoins() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: Bas ");
}

void menutelchplus() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: Haut");
}

void menutelarriere() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche:");
  lcd.setCursor(0, 3);
  lcd.print("retour en arriere");
}

void menutelavant() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(01, 2);
  lcd.print("touche: avant");
}

void menutelpause() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: pause");
  lcd.setCursor(0, 2);
  lcd.print("( pause / lecture )");
}

void menutelmoins() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: moins (-)");
}

void menutelplus() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: plus (+)");
}

void menuteleq() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: eq");
}

void menutelzero() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: 0");
}

void menutelun() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: 1");
}

void menuteldeux() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: 2");
}

void menuteltrois() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: 3");
}

void menutelquatre() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: 4");
}

void menutelcinq() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: 5");
}

void menutelsix() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: 6");
}

void menutelsept() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: 7");
}

void menutelhuit() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: 8");
}

void menutelneuf() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Appuyer sur la ");
  lcd.setCursor(0, 2);
  lcd.print("touche: 9");
}

void menutelfinish() {
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print("Configuration ");
  lcd.setCursor(5, 2);
  lcd.print("terminee");
}
