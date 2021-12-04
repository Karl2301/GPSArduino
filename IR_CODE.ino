void IRCODE() {
  if (receiver.decode(&results)) { // decode the received signal and store it in results
    switch (results.value) { // compare the value to the following cases
      case 0xFFE01F:
        Serial.println("VOL-");
        if (comptenumcode > 0) {
          comptenumcode = comptenumcode - 1;
        }
        break ;
      case 0xFF6897:
        Serial.println("0");
        if (comptenumcode == 0) {
          numcodeun = 0;
          comptenumcode = 1;
        } else if (comptenumcode == 1) {
          numcodedeux = 0;
          comptenumcode = 2;
        } else if (comptenumcode == 2) {
          numcodetrois = 0;
          comptenumcode = 3;
        } else if (comptenumcode == 3) {
          numcodequatre = 0;
          comptenumcode = 4;
        } else if (comptenumcode == 4) {
          numcodecinq = 0;
          comptenumcode = 5;
        } else if (comptenumcode == 5) {
          numcodesix = 0;
          comptenumcode = 6;
        }
        break ;
      case 0xFF30CF:
        Serial.println("1");
        if (comptenumcode == 0) {
          numcodeun = 1;
          comptenumcode = 1;
        } else if (comptenumcode == 1) {
          numcodedeux = 1;
          comptenumcode = 2;
        } else if (comptenumcode == 2) {
          numcodetrois = 1;
          comptenumcode = 3;
        } else if (comptenumcode == 3) {
          numcodequatre = 1;
          comptenumcode = 4;
        } else if (comptenumcode == 4) {
          numcodecinq = 1;
          comptenumcode = 5;
        } else if (comptenumcode == 5) {
          numcodesix = 1;
          comptenumcode = 6;
        }
        break ;
      case 0xFF18E7:
        Serial.println("2");
        if (comptenumcode == 0) {
          numcodeun = 2;
          comptenumcode = 1;
        } else if (comptenumcode == 1) {
          numcodedeux = 2;
          comptenumcode = 2;
        } else if (comptenumcode == 2) {
          numcodetrois = 2;
          comptenumcode = 3;
        } else if (comptenumcode == 3) {
          numcodequatre = 2;
          comptenumcode = 4;
        } else if (comptenumcode == 4) {
          numcodecinq = 2;
          comptenumcode = 5;
        } else if (comptenumcode == 5) {
          numcodesix = 2;
          comptenumcode = 6;
        }
        break ;
      case 0xFF7A85:
        Serial.println("3") ;
        if (comptenumcode == 0) {
          numcodeun = 3;
          comptenumcode = 1;
        } else if (comptenumcode == 1) {
          numcodedeux = 3;
          comptenumcode = 2;
        } else if (comptenumcode == 2) {
          numcodetrois = 3;
          comptenumcode = 3;
        } else if (comptenumcode == 3) {
          numcodequatre = 3;
          comptenumcode = 4;
        } else if (comptenumcode == 4) {
          numcodecinq = 3;
          comptenumcode = 5;
        } else if (comptenumcode == 5) {
          numcodesix = 3;
          comptenumcode = 6;
        }
        break ;
      case 0xFF10EF:
        Serial.println("4") ;
        if (comptenumcode == 0) {
          numcodeun = 4;
          comptenumcode = 1;
        } else if (comptenumcode == 1) {
          numcodedeux = 4;
          comptenumcode = 2;
        } else if (comptenumcode == 2) {
          numcodetrois = 4;
          comptenumcode = 3;
        } else if (comptenumcode == 3) {
          numcodequatre = 4;
          comptenumcode = 4;
        } else if (comptenumcode == 4) {
          numcodecinq = 4;
          comptenumcode = 5;
        } else if (comptenumcode == 5) {
          numcodesix = 4;
          comptenumcode = 6;
        }
        break ;
      case  0xFF38C7 :
        Serial.println("5") ;
        if (comptenumcode == 0) {
          numcodeun = 5;
          comptenumcode = 1;
        } else if (comptenumcode == 1) {
          numcodedeux = 5;
          comptenumcode = 2;
        } else if (comptenumcode == 2) {
          numcodetrois = 5;
          comptenumcode = 3;
        } else if (comptenumcode == 3) {
          numcodequatre = 5;
          comptenumcode = 4;
        } else if (comptenumcode == 4) {
          numcodecinq = 5;
          comptenumcode = 5;
        } else if (comptenumcode == 5) {
          numcodesix = 5;
          comptenumcode = 6;
        }
        break ;
      case  0xFF5AA5 :
        Serial.println("6") ;
        if (comptenumcode == 0) {
          numcodeun = 6;
          comptenumcode = 1;
        } else if (comptenumcode == 1) {
          numcodedeux = 6;
          comptenumcode = 2;
        } else if (comptenumcode == 2) {
          numcodetrois = 6;
          comptenumcode = 3;
        } else if (comptenumcode == 3) {
          numcodequatre = 6;
          comptenumcode = 4;
        } else if (comptenumcode == 4) {
          numcodecinq = 6;
          comptenumcode = 5;
        } else if (comptenumcode == 5) {
          numcodesix = 6;
          comptenumcode = 6;
        }
        break ;
      case  0xFF42BD :
        Serial.println("7") ;
        if (comptenumcode == 0) {
          numcodeun = 7;
          comptenumcode = 1;
        } else if (comptenumcode == 1) {
          numcodedeux = 7;
          comptenumcode = 2;
        } else if (comptenumcode == 2) {
          numcodetrois = 7;
          comptenumcode = 3;
        } else if (comptenumcode == 3) {
          numcodequatre = 7;
          comptenumcode = 4;
        } else if (comptenumcode == 4) {
          numcodecinq = 7;
          comptenumcode = 5;
        } else if (comptenumcode == 5) {
          numcodesix = 7;
          comptenumcode = 6;
        }
        break ;
      case  0xFF4AB5 :
        Serial.println("8") ;
        if (comptenumcode == 0) {
          numcodeun = 8;
          comptenumcode = 1;
        } else if (comptenumcode == 1) {
          numcodedeux = 8;
          comptenumcode = 2;
        } else if (comptenumcode == 2) {
          numcodetrois = 8;
          comptenumcode = 3;
        } else if (comptenumcode == 3) {
          numcodequatre = 8;
          comptenumcode = 4;
        } else if (comptenumcode == 4) {
          numcodecinq = 8;
          comptenumcode = 5;
        } else if (comptenumcode == 5) {
          numcodesix = 8;
          comptenumcode = 6;
        }
        break;
      case  0xFF52AD :
        Serial.println("9") ;
        if (comptenumcode == 0) {
          numcodeun = 9;
          comptenumcode = 1;
        } else if (comptenumcode == 1) {
          numcodedeux = 9;
          comptenumcode = 2;
        } else if (comptenumcode == 2) {
          numcodetrois = 9;
          comptenumcode = 3;
        } else if (comptenumcode == 3) {
          numcodequatre = 9;
          comptenumcode = 4;
        } else if (comptenumcode == 4) {
          numcodecinq = 9;
          comptenumcode = 5;
        } else if (comptenumcode == 5) {
          numcodesix = 9;
          comptenumcode = 6;
        }
        break;
    }
    key_value = results.value ; // stocke la valeur sous la forme key_value
    receiver.resume(); // réinitialise le récepteur pour le code suivant
  }
  if (comptenumcode == 0) {
    entercodezero();
  } else if (comptenumcode == 1) {
    entercodeun();
  } else if (comptenumcode == 2) {
    entercodedeux();
  } else if (comptenumcode == 3) {
    entercodetrois();
  } else if (comptenumcode == 4) {
    entercodequatre();
  } else if (comptenumcode == 5) {
    entercodecinq();
  } else if (comptenumcode == 6) {
    entercodesix();
  }

  if (comptenumcode == 6) {
    Serial.print(numcodeun);
    Serial.print(numcodedeux);
    Serial.print(numcodetrois);
    Serial.print(numcodequatre);
    Serial.print(numcodecinq);
    Serial.println(numcodesix);
    Code.replace("A", (String)numcodeun);
    Code.replace("B", (String)numcodedeux);
    Code.replace("C", (String)numcodetrois);
    Code.replace("D", (String)numcodequatre);
    Code.replace("E", (String)numcodecinq);
    Code.replace("F", (String)numcodesix);
    comptenumcode = 0;
    Serial.println(Code);

    if (Code == codeverif) {
      vert();
      lcd.clear();
      rafmenu();
      code = 1;
    } else {
      rouge();
      code = 0;
      comptenumcode = 0;
      Code = "ABCDEF";
    }
  }

}
