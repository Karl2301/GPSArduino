void IR() {
  if (receiver.decode(&results)) { // decode the received signal and store it in results
    switch (results.value) { // compare the value to the following cases
      case 0xFFA25D: // if the value is equal to 0xFD00FF
        if (blacklight == 1) {
          Serial.println("CH-"); // print "POWER" in the Serial Monitor
          if (menuselector == 0) {
            menu --;
            rafmenu();
          } else if (menuselector == 2) {
            infogps --;
          } else if (menuselector == 3) {
            trajet = 0;
          } else if (menuselector == 6) {
            menuparam = 1;
          } else if (menuselector == 5) {
            if (nbFichiers == 0) {
              menuenofich();
            } else {
              menueffafichmoins();
            }
          } else if (menuselector == 8) {
            if (distancechoix == 2) {
              distancechoix = distancechoix - 1;
              menudistance1();
            } else {
              menudistance1();
            }
          } else if (menuselector == 10) {
            nbrheure --;
            if (nbrheure > 12) {
              nbrheure = 12;
            } else if (nbrheure < -12) {
              nbrheure = -12;
            }
            heureUTC();
            SD.remove("/p/heure.txt");
            delay(500);
            myFile = SD.open("/p/heure.txt", FILE_WRITE);
            myFile.print(nbrheure);
            myFile.close();
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break;
      case 0xFF629D:
        if (blacklight == 1) {
          Serial.println("CH");
          if (menuselector == 0) {
            if (menu == 1) {
              menuselector = 1;
            } else if (menu == 2) {
              menuselector = 2;
            } else if (menu == 3) {
              if (trajet == 0) {
                trajet = 1;
                nameFile = (String)TRAJET;
                Serial.println(nameFile);
                SD.remove("p/t/tjtcour.txt");
                delay(500);
                myFile = SD.open("p/t/tjtcour.txt", FILE_WRITE);
                myFile.print(nameFile);
                myFile.close();
                menudemtrajet();
                menuselector = 0;
                infogps = 1;
                menuparam = 1;
                effafich = 0;
                rafmenu();
              } else {
                menuyestrajet();
                menuselector = 0;
                infogps = 1;
                menuparam = 1;
                effafich = 0;
                rafmenu();
              }

            } else if (menu == 4) {
              if (trajet == 2) {
                menuarrtrajet();
                menuselector = 4;
                trajet = 0;
                finish_file();
                nameFile = "";
                menuselector = 0;
                infogps = 1;
                menuparam = 1;
                effafich = 0;
                ligne = 0;
                rafmenu();
              } else {
                menunotrajet();
                menuselector = 0;
                infogps = 1;
                menuparam = 1;
                effafich = 0;
                rafmenu();
              }
            } else if (menu == 5) {
              menuselector = 5;
              if (nbFichiers == 0) {
                menuenofich();
              } else {
                menueffafich();
              }
            } else if (menu == 6) {
              if (trajet != 2) {
                resetFunc();
              }
            } else if (menu == 7) {
              if (trajet != 2) {
                code = 0;
                comptenumcode = 0;
                Code = "ABCDEF";
                menu = 1;
                menuselector = 0;
              }
            } else if (menu == 8) {
              nbrdecharlat = 0;
              nbrpointlat = 0;
              menuselector = 8;
            } else if (menu == 9) {
              menuselector = 9;
              comptenumcode = 0;
              NCode = "ABCDEF";
            } else if (menu == 10) {
              menuselector = 10;
              heureUTC();
            } else if (menu == 11) {
              if (trajet == 2) {
                trajet = 4;
                menuSelct11();
              } else if (trajet == 4) {
                trajet = 2;
                menuSelct11();
              }
            }
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break;
      case 0xFFE21D:
        Serial.println("CH+");
        if (blacklight == 1) {
          lcd.clear();
          if (menuselector == 0) {
            menu ++;
            rafmenu();
          } else if (menuselector == 2) {
            infogps ++;
          } else if (menuselector == 6) {
            menuparam = 2;
          } else if (menuselector == 5) {
            if (nbFichiers == 0) {
              menuenofich();
            } else {
              menueffafichplus();
            }
          } else if (menuselector == 8) {
            if (distancechoix == 1) {
              distancechoix = distancechoix + 1;
              menudistance1();
            } else {
              menudistance1();
            }
          } else if (menuselector == 10) {
            nbrheure ++;
            if (nbrheure > 12) {
              nbrheure = 12;
            } else if (nbrheure < -12) {
              nbrheure = -12;
            }
            heureUTC();
            SD.remove("/p/heure.txt");
            delay(500);
            myFile = SD.open("/p/heure.txt", FILE_WRITE);
            myFile.print(nbrheure);
            myFile.close();
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break;
      case 0xFF22DD:
        if (blacklight == 1) {
          Serial.println("|<<");
          if (menuselector != 0) {
            menuselector = 0;
            infogps = 1;
            menuparam = 1;
            rafmenu();
            effafich = 0;
            menuselectorlcd = 0;
            menuselectortrajet = 0;
            menuparametre = 0;

          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break;
      case 0xFFC23D:
        if (blacklight == 1) {
          Serial.println(">||");
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFF02FD:
        if (blacklight == 1) {
          Serial.println(">>|");
          if (menuselector == 8) {
            if (distancechoix == 1) {
              latDesti = "";
              StrlatDesti = "";
              nbrpointlat = 0;
              menudistance1();
              SD.remove("/p/d/lat.txt");
              delay(200);
              myFile = SD.open("/p/distance/lat.txt", FILE_WRITE);
              myFile.print("");
              myFile.close();
            } else if (distancechoix == 2) {
              lonDesti = "";
              StrlonDesti = "";
              menudistance1();
              nbrpointlon = 0;
              SD.remove("/p/d/lon.txt");
              delay(200);
              myFile = SD.open("/p/distance/lon.txt", FILE_WRITE);
              myFile.print("");
              myFile.close();
            }
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFFA857:
        if (blacklight == 1) {
          Serial.println("VOL+");
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFFE01F:
        if (blacklight == 1) {
          Serial.println("VOL-");
          if (menuselector == 8) {
            if (nbrpointlat == 0) {
              if (distancechoix == 1) {
                StrlatDesti = StrlatDesti + "-";
                Serial.println(StrlatDesti);
                latDesti = StrlatDesti;
                menudistance1();
                printlatdistance();
              }
            } else if (nbrpointlon == 0) {
              if (distancechoix == 2) {
                StrlonDesti = StrlonDesti + "-";
                Serial.println(StrlonDesti);
                lonDesti = StrlonDesti;
                menudistance1();
                printlondistance();
              }
            }
          } else if (menuselector == 9) {
            if (comptenumcode > 0) {
              comptenumcode = comptenumcode - 1;
            }
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFF906F:
        if (blacklight == 1) {
          Serial.println("EQ");
          if (menuselector == 5 && nbFichiers != 0) {
            String removefile = "/trajet/" + nomFichier;
            SD.remove(removefile);
            nbFichiers = nbFichiers - 1;
            compterfichier();
            lcd.clear();
            lcd.setCursor(1, 1);
            lcd.print("veuillez patienter");
            delay(1000);
            if (nbFichiers == 0) {
              menuenofich();
            } else {
              menueffafich();
            }
          } else if (menuselector == 8) {
            if (nbrpointlat == 0) {
              if (distancechoix == 1) {
                StrlatDesti = StrlatDesti + ".";
                Serial.println(StrlatDesti);
                latDesti = StrlatDesti;
                nbrpointlat = nbrpointlat + 1;
                menudistance1();
                printlatdistance();
              }
            } else if (nbrpointlon == 0) {
              if (distancechoix == 2) {
                StrlonDesti = StrlonDesti + ".";
                Serial.println(StrlonDesti);
                lonDesti = StrlonDesti;
                nbrpointlon = nbrpointlon + 1;
                menudistance1();
                printlondistance();
              }
            }
          } else if (menuselector != 5) {
            lcd.noBacklight();
            blacklight = 0;
            delay(100);
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFF6897:
        if (blacklight == 1) {
          Serial.println("0");
          if (menuselector == 8) {
            if (distancechoix == 1) {
              StrlatDesti = StrlatDesti + "0";
              latDesti = StrlatDesti;
              if (nbrpointlat == 1) {
                nbrdecharlat ++;
              }
              menudistance1();
              printlatdistance();
              Serial.println(latDesti);
            } else if (distancechoix == 2) {
              StrlonDesti = StrlonDesti + "0";
              lonDesti = StrlonDesti;
              if (nbrpointlon == 1) {
                nbrdecharlon ++;
              }
              menudistance1();
              printlondistance();
              Serial.println(lonDesti);
            }
          } else if (menuselector == 9) {
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
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFF9867:
        if (blacklight == 1) {
          Serial.println("100+");
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFFB04F:
        if (blacklight == 1) {
          Serial.println("200+");
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFF30CF:
        if (blacklight == 1) {
          Serial.println("1");
          if (menuselector == 8) {
            if (distancechoix == 1) {
              StrlatDesti = StrlatDesti + "1";
              latDesti = StrlatDesti;
              if (nbrpointlat == 1) {
                nbrdecharlat ++;
              }
              menudistance1();
              printlatdistance();
              Serial.println(latDesti);
            } else if (distancechoix == 2) {
              StrlonDesti = StrlonDesti + "1";
              lonDesti = StrlonDesti;
              if (nbrpointlon == 1) {
                nbrdecharlon ++;
              }
              menudistance1();
              printlondistance();
              Serial.println(lonDesti);
            }
          } else if (menuselector == 9) {
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
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFF18E7:
        if (blacklight == 1) {
          Serial.println("2");
          if (menuselector == 8) {
            if (distancechoix == 1) {
              StrlatDesti = StrlatDesti + "2";
              latDesti = StrlatDesti;
              if (nbrpointlat == 1) {
                nbrdecharlat ++;
              }
              menudistance1();
              printlatdistance();
              Serial.println(latDesti);
            } else if (distancechoix == 2) {
              StrlonDesti = StrlonDesti + "2";
              lonDesti = StrlonDesti;
              if (nbrpointlon == 1) {
                nbrdecharlon ++;
              }
              menudistance1();
              printlondistance();
              Serial.println(lonDesti);
            }
          } else if (menuselector == 9) {
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
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFF7A85:
        if (blacklight == 1) {
          Serial.println( "3" ) ;
          if (menuselector == 8) {
            if (distancechoix == 1) {
              StrlatDesti = StrlatDesti + "3";
              latDesti = StrlatDesti;
              if (nbrpointlat == 1) {
                nbrdecharlat ++;
              }
              menudistance1();
              printlatdistance();
              Serial.println(latDesti);
            } else if (distancechoix == 2) {
              StrlonDesti = StrlonDesti + "3";
              lonDesti = StrlonDesti;
              if (nbrpointlon == 1) {
                nbrdecharlon ++;
              }
              menudistance1();
              printlondistance();
              Serial.println(lonDesti);
            }
          } else if (menuselector == 9) {
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
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case 0xFF10EF:
        if (blacklight == 1) {
          Serial.println( "4" ) ;
          if (menuselector == 8) {
            if (distancechoix == 1) {
              StrlatDesti = StrlatDesti + "4";
              latDesti = StrlatDesti;
              if (nbrpointlat == 1) {
                nbrdecharlat ++;
              }
              menudistance1();
              printlatdistance();
              Serial.println(latDesti);
            } else if (distancechoix == 2) {
              StrlonDesti = StrlonDesti + "4";
              lonDesti = StrlonDesti;
              if (nbrpointlon == 1) {
                nbrdecharlon ++;
              }
              menudistance1();
              printlondistance();
              Serial.println(lonDesti);
            }
          } else if (menuselector == 9) {
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
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case  0xFF38C7 :
        if (blacklight == 1) {
          Serial.println( "5" ) ;
          if (menuselector == 8) {
            if (distancechoix == 1) {
              StrlatDesti = StrlatDesti + "5";
              latDesti = StrlatDesti;
              if (nbrpointlat == 1) {
                nbrdecharlat ++;
              }
              menudistance1();
              printlatdistance();
              Serial.println(latDesti);
            } else if (distancechoix == 2) {
              StrlonDesti = StrlonDesti + "5";
              lonDesti = StrlonDesti;
              if (nbrpointlon == 1) {
                nbrdecharlon ++;
              }
              menudistance1();
              printlondistance();
              Serial.println(lonDesti);
            }
          } else if (menuselector == 9) {
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
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case  0xFF5AA5 :
        if (blacklight == 1) {
          Serial.println( "6" ) ;
          if (menuselector == 8) {
            if (distancechoix == 1) {
              StrlatDesti = StrlatDesti + "6";
              latDesti = StrlatDesti;
              if (nbrpointlat == 1) {
                nbrdecharlat ++;
              }
              menudistance1();
              printlatdistance();
              Serial.println(lonDesti);
            } else if (distancechoix == 2) {
              StrlonDesti = StrlonDesti + "6";
              lonDesti = StrlonDesti;
              if (nbrpointlon == 1) {
                nbrdecharlon ++;
              }
              menudistance1();
              printlondistance();
              Serial.println(lonDesti);
            }
          } else if (menuselector == 9) {
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
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case  0xFF42BD :
        if (blacklight == 1) {
          Serial.println( "7" ) ;
          if (menuselector == 8) {
            if (distancechoix == 1) {
              StrlatDesti = StrlatDesti + "7";
              latDesti = StrlatDesti;
              if (nbrpointlat == 1) {
                nbrdecharlat ++;
              }
              menudistance1();
              printlatdistance();
              Serial.println(latDesti);
            } else if (distancechoix == 2) {
              StrlonDesti = StrlonDesti + "7";
              lonDesti = StrlonDesti;
              if (nbrpointlon == 1) {
                nbrdecharlon ++;
              }
              menudistance1();
              printlondistance();
              Serial.println(lonDesti);
            }
          } else if (menuselector == 9) {
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
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break ;
      case  0xFF4AB5 :
        if (blacklight == 1) {
          Serial.println( "8" ) ;
          if (menuselector == 8) {
            if (distancechoix == 1) {
              StrlatDesti = StrlatDesti + "8";
              latDesti = StrlatDesti;
              if (nbrpointlat == 1) {
                nbrdecharlat ++;
              }
              menudistance1();
              printlatdistance();
              Serial.println(latDesti);
            } else if (distancechoix == 2) {
              StrlonDesti = StrlonDesti + "8";
              lonDesti = StrlonDesti;
              if (nbrpointlon == 1) {
                nbrdecharlon ++;
              }
              menudistance1();
              printlondistance();
              Serial.println(lonDesti);
            }
          } else if (menuselector == 9) {
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
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break;
      case  0xFF52AD :
        if (blacklight == 1) {
          Serial.println( "9" ) ;
          if (menuselector == 8) {
            if (distancechoix == 1) {
              StrlatDesti = StrlatDesti + "9";
              latDesti = StrlatDesti;
              if (nbrpointlat == 1) {
                nbrdecharlat ++;
              }
              menudistance1();
              printlatdistance();
              Serial.println(latDesti);
            } else if (distancechoix == 2) {
              StrlonDesti = StrlonDesti + "9";
              lonDesti = StrlonDesti;
              if (nbrpointlon == 1) {
                nbrdecharlon ++;
              }
              menudistance1();
              printlondistance();
              Serial.println(lonDesti);
            }
          } else if (menuselector == 9) {
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
          }
        } else {
          blacklight = 1;
          lcd.backlight();
        }
        break;
    }
    receiver.resume(); // réinitialise le récepteur pour le code suivant
  }
  if (menuselector == 9) {
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
  }

  if (comptenumcode == 6) {
    Serial.print(numcodeun);
    Serial.print(numcodedeux);
    Serial.print(numcodetrois);
    Serial.print(numcodequatre);
    Serial.print(numcodecinq);
    Serial.println(numcodesix);
    NCode.replace("A", (String)numcodeun);
    NCode.replace("B", (String)numcodedeux);
    NCode.replace("C", (String)numcodetrois);
    NCode.replace("D", (String)numcodequatre);
    NCode.replace("E", (String)numcodecinq);
    NCode.replace("F", (String)numcodesix);
    comptenumcode = 0;
    Serial.println(NCode);
    SD.remove("/p/code.txt");
    Serial.println("Fichier code.txt effacé");
    delay(100);
    myFile = SD.open("/p/code.txt", FILE_WRITE);
    if (myFile) {
      Serial.println("réécriture du fichier code.txt");
      codeverif = NCode;
      myFile.print(NCode);
      myFile.close();
    }
    Serial.println("ok");
    vert();
    lcd.clear();
    code = 1;
    menuselector = 0;
    infogps = 1;
    menuparam = 1;
    effafich = 0;
    menuselectorlcd = 0;
    menuselectortrajet = 0;
    menuparametre = 0;
    rafmenu();
  }
}
