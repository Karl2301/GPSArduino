/*
      Module / Arduino mega
   LCD:
       VCC       5v
       SCL       SCL
       SDA       SDA

   SD:
       VCC       5v
       MISO      50
       MOSI      51
       SCK       52
       CS        53

   IR:
       VCC       5v
       Signal    5

   RGB:
       V         5v
       B         11
       R         10
       G         9

   GPS:
       TX        RX3
       RX        TX3
       VCC       3.3v
*/

#include <TinyGPS++.h>
#include <TimeLib.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>                        // bibliothèque bus SPI
#include <SD.h>
#include <DHT.h>
#include <IRremote.h>
#include "variable.h"
#include <stdint.h>
#include <ArduinoJson.h>

#define MaxMenu 11
#define GPSECHO  false
#define delayled 100
#define brocheDeBranchementDHT 2   // La ligne de communication du DHT22 sera donc branchée sur la pin 2 de l'Arduino
#define typeDeDHT DHT11

LiquidCrystal_I2C lcd(0x27, 20, 4);
IRrecv receiver(5);
decode_results results;
TinyGPSPlus gps;
File myFile;
DHT dht(brocheDeBranchementDHT, typeDeDHT);
void(* resetFunc) (void) = 0;
void setup()
{
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 1);
  lcd.print("GPS Tracker V5");

  Serial.begin(115200);
  Serial.println("Adafruit GPS library basic parsing test!");
  //init les led rgb
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, HIGH);

  //init gps
  Serial3.begin(9600);

  // Initialisation du DHT22;
  dht.begin();

  //init IR
  receiver.enableIRIn();
  receiver.blink13(true);

  //init Json

  // Test if parsing succeeds.

  // Fetch values.
  //
  // Most of the time, you can rely on the implicit casts.
  // In other case, you can do doc["time"].as<long>();
  //on vérifie si la carte SD est bien la`
  if (!SD.begin(53)) {
    lcd.clear();
    Serial.println(F("SD absente ou HS. stop."));
    lcd.setCursor(2, 1);
    lcd.print("SD absente ou HS");
    digitalWrite(bluePin, HIGH);
    digitalWrite(greenPin, HIGH);
    int i = 16;
    while(i != 0) {
      digitalWrite(redPin, LOW);
      delay(500);
      digitalWrite(redPin, HIGH);
      i --;
      lcd.setCursor(2, 3);
      lcd.print("restart dans "); if(i<10) { lcd.print("0"); }lcd.print(i); lcd.print("s");
      delay(500);
    }
    resetFunc();
  }
  bleu();

  //on lit et stocke le mot de passe dans le fichier /p/code.txt

  String codegps;
  File codegpsfile = SD.open("p/code.txt");
  if (codegpsfile) {
    while (codegpsfile.available()) {
      codegps = codegpsfile.readStringUntil('\n');
      codeverif = codegps;
      Serial.print("Code: "); Serial.println(codeverif);
    }
    codegpsfile.close();
  }
  //String codegps = SD.open("p/code.txt", FILE_READ).readStringUntil('\r');
  //codeverif = codegps;
  String heureutc;
  File heureutcfile = SD.open("p/heure.txt");
  if (heureutcfile) {
    while (heureutcfile.available()) {
      heureutc = heureutcfile.readStringUntil('\n');
      nbrheure = heureutc.toInt();
      Serial.print("Heure UTC: "); Serial.println(nbrheure);
    }
    heureutcfile.close();
  }

  String trajetencour;
  File trajetencourfile = SD.open("p/t/tjtcour.txt");
  if (trajetencourfile) {
    while (trajetencourfile.available()) {
      trajetencour = trajetencourfile.readStringUntil('\n').toInt();
      Serial.print("trajet en cour: "); Serial.println(trajetencour);
    }
    trajetencourfile.close();
  }
  //String heureutc = SD.open("p/heure.txt", FILE_READ).readStringUntil('\r').close();
  //nbrheure = heureutc.toInt();

  File lonDestifile = SD.open("p/d/lon.txt");
  if (lonDestifile) {
    while (lonDestifile.available()) {
      lonDesti = lonDestifile.readStringUntil('\n');
      Serial.print("Longitude: "); Serial.println(lonDesti);
    }
    lonDestifile.close();
  } else {
    Serial.println("Pas de données de longitude");
  }

  File latDestifile = SD.open("p/d/lat.txt");
  if (latDestifile) {
    while (latDestifile.available()) {
      latDesti = latDestifile.readStringUntil('\n');
      Serial.print("Latitude: "); Serial.println(latDesti);
    }
    latDestifile.close();
  } else {
    Serial.println("Pas de données de latitude");
  }


  //lonDesti = SD.open("p/d/lon.txt", FILE_READ).readStringUntil('\r');

  //latDesti = SD.open("p/d/lat.txt", FILE_READ).readStringUntil('\r');

  //String trajetencour = SD.open("p/t/tjtcour.txt", FILE_READ).readStringUntil('\r');

  if (trajetencour != 0) {
    trajet = 2;
    nameFile = trajetencour;
    File datafile = SD.open("/trajet/kmlfile/" + nameFile + "/data.txt");
    if (datafile) {
      while (datafile.available()) {
        String Data = datafile.readStringUntil('\n');
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, Data);
        JsonObject obj = doc.as<JsonObject>();
        String Maxsatstr;
        String MaxAltstr;
        String MaxSpeedstr;
        Maxsatstr = obj["SatMax"].as<String>();
        MaxSpeedstr = obj["SpeedMax"].as<String>();
        MaxAltstr = obj["AltMax"].as<String>();
        MaxSat = Maxsatstr.toInt();
        MaxAlt = MaxAltstr.toInt();
        MaxSpeed =  MaxSpeedstr.toInt();
        Serial.print("MaxSat: "); Serial.println(MaxSat);
        Serial.print("MaxAlt: "); Serial.println(MaxAlt);
        Serial.print("MaxSpeed: "); Serial.println(MaxSpeed);
      }
      datafile.close();
    } else {
      Serial.println("Pas de Data de trajet");
    }

    File CompteTempsfile = SD.open("/trajet/kmlfile/" + nameFile + "/time.txt");
  if (CompteTempsfile) {
    while (CompteTempsfile.available()) {
     String compteTempsstr = CompteTempsfile.readStringUntil('\n');
     compteTemps = compteTempsstr.toInt();
      Serial.print("Compte temps: "); Serial.println(compteTemps);
    }
    CompteTempsfile.close();
  } else {
    Serial.println("Pas de données de temps de trajet");
  }
  
    menurestarttrajet();
    Serial.println("Trajet redémarré");
  } else {
    Serial.println("Pas de trajet repris");
  }

  //on compte le nombre de fichier dans la carte sd
  Serial.println(codegps);
  nbFichiers = compteNbFichiers();
  Serial.print(nbFichiers);  Serial.println(F(" fichiers à la racine"));
  Serial.print(nbFichiers); Serial.print(F("\t"));
  Serial.println(affiFichier(nbFichiers));
  Serial.println(F("\n+ = fichier suivant, - = fichier précédent"));
  noFichier = nbFichiers; // n° de fichier dans la liste, on part du dernier
  if (++noFichier > nbFichiers) {
    noFichier--;
  }
  nomFichier = affiFichier(noFichier);  // affichage nom fichier indexé par noFichier > 0
  Serial.print(noFichier); Serial.print(F("\t"));
  Serial.println(nomFichier);
  /*
    //                         0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
    String tablenewtel[19] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};
    int decalecatam = 5;
    Serial.println("Debut de lecture");
    delay(100);
      if (tablenewtel[decalecatam] == "0") {
        //on ecrit les information ici
        String decalecatamstr = String(decalecatam);
        tablenewtel[decalecatam] = decalecatamstr;
      } else {
        //si la case est deja remplit, on passe au suivant
        decalecatam = decalecatam + 1;
      }
      if (decalecatam == 19) {
        tablefinish = 1;
      }

    int t = 0;
    while(t < 19) {
      Serial.println(tablenewtel[t]);
      t ++;
    }
  */
  /*while (numtel == 1) {
    multiTel();
  }
*/
  lcd.clear();
  if (code == 0) {
    entercodezero();
    IRCODE();
  } else if (code == 1) {
    rafmenu();
  }

}

uint32_t timerdecoder = millis();
uint32_t timergps = millis();
uint32_t connectiongps = millis();
uint32_t timerdht = millis();

void loop()                     // run over and over again
{
  if (code == 1) {
    IR();
    //on récupère les info du gps
    while (Serial3.available() > 0)
      if (gps.encode(Serial3.read()))
        if (millis() > 5000 && gps.charsProcessed() < 10)
        {
          Serial.println(F("No GPS detected: check wiring."));
        }

    if (millis() - timerdht > 2000) {  //oute les 1secondes on fait une action
      float tauxHumidite = dht.readHumidity();              // Lecture du taux d'humidité (en %)
      float temperatureEnCelsius = dht.readTemperature();   // Lecture de la température, exprimée en degrés Celsius
      if (!isnan(tauxHumidite) || !isnan(temperatureEnCelsius)) {
        timerdht = millis(); // reset the timer

        // Vérification si données bien reçues

        // Calcul de la température ressentie
        float temperatureRessentieEnCelsius = dht.computeHeatIndex(temperatureEnCelsius, tauxHumidite, false); // Le "false" est là pour dire qu'on travaille en °C, et non en °F

        // Affichage des valeurs
        Serial.print("Humidité = "); Serial.print(tauxHumidite); Serial.println(" %");
        Serial.print("Température = "); Serial.print(temperatureEnCelsius); Serial.println(" °C");
        Serial.print("Température ressentie = "); Serial.print(temperatureRessentieEnCelsius); Serial.println(" °C");
        Serial.println();
        t = temperatureEnCelsius;
        h = tauxHumidite;
        tr = temperatureRessentieEnCelsius;
      }
    }

    if (gps.satellites.value() > 3) {
      if (gps.satellites.value() <= 4) { //on afficher une petite bar en haut a droit de l'ecrans
        satconnection = 1;
        lcd.createChar(1, oconnection);
        lcd.setCursor(19, 0);
        lcd.write(1);
      } else if (gps.satellites.value() >= 5 && gps.satellites.value() <= 7) { //on afficher deux petites bars en haut a droit de l'ecrans
        satconnection = 2;
        lcd.createChar(2, ooconnection);
        lcd.setCursor(19, 0);
        lcd.write(2);
      } else if (gps.satellites.value() >= 8) { //on afficher trois petites bars en haut a droit de l'ecrans
        satconnection = 3;
        lcd.createChar(1, oooconnection);
        lcd.setCursor(19, 0);
        lcd.write(1);
      }
    } else {
      satconnection = 0;
      lcd.createChar(4, noconnection);
      lcd.setCursor(19, 0);
      lcd.write(4);
    }
    if (millis() - timerdecoder > 1000) {  //oute les 1secondes on fait une action

      timerdecoder = millis(); // reset the timer
      //on remet l'UTC correctement
      Minute = gps.time.minute();
      Second = gps.time.second();
      Hour   = gps.time.hour();
      Day    = gps.date.day();
      Month  = gps.date.month();
      Year   = gps.date.year();
      setTime(Hour, Minute, Second, Day, Month, Year);
      adjustTime(nbrheure * 3600);
      Time[12] = second() / 10 + '0';
      Time[13] = second() % 10 + '0';
      Time[9]  = minute() / 10 + '0';
      Time[10] = minute() % 10 + '0';
      Time[6]  = hour()   / 10 + '0';
      Time[7]  = hour()   % 10 + '0';
      Date[14] = (year()  / 10) % 10 + '0';
      Date[15] =  year()  % 10 + '0';
      Date[9]  =  month() / 10 + '0';
      Date[10] =  month() % 10 + '0';
      Date[6]  =  day()   / 10 + '0';
      Date[7]  =  day()   % 10 + '0';

      TRAJET[0] = day()   / 10 + '0';
      TRAJET[1] = day()   % 10 + '0';
      TRAJET[2] = month() / 10 + '0';
      TRAJET[3] = month() % 10 + '0';
      TRAJET[4] = hour()   / 10 + '0';
      TRAJET[5] = hour()   % 10 + '0';
      TRAJET[6] = minute() / 10 + '0';
      TRAJET[7] = minute() % 10 + '0';
      print_wday(weekday());

      Serial.print(" ");
      Serial.print(Time); //on affiche l'heure
      Serial.print(" ");
      Serial.print(Date);//on affiche la date
      Serial.print(" Trajet name: ");
      Serial.print(TRAJET);//on affiche la date
      Serial.println();
      if (gps.satellites.value() > 3) {   //si le GPS est connecter aux satelites
        if (gps.location.lat() != 0 && gps.location.lng() != 0) {
          Serial.print("Location: ");
          Serial.print(gps.location.lat(), 15); //on affiche la latitude
          Serial.print(", ");
          Serial.println(gps.location.lng(), 15);  // et la longitude
          latNOW = gps.location.lat();
          lonNOW = gps.location.lng();
          if (gps.satellites.value() > MaxSat) {
            MaxSat = gps.satellites.value();
          }
          if (gps.altitude.meters() > MaxAlt) {
            MaxAlt = gps.altitude.meters();
          }
          if (gps.speed.kmph() > MaxSpeed) {
            MaxSpeed = gps.speed.kmph();
          }
          //on afficher les autre données dans le Serial
          Serial.print("latNOW: "); Serial.println(latNOW, 15);
          Serial.print("latNOW: "); Serial.println(lonNOW, 15);
          Serial.print("Speed: "); Serial.println(gps.speed.kmph());
          Serial.print("Angle: "); Serial.println(gps.course.deg());
          Serial.print("Altitude: "); Serial.println(gps.altitude.meters());
          Serial.print("Satellites: "); Serial.println(gps.satellites.value());
          Serial.print("Satellites Max: "); Serial.println(MaxSat);
          //on afficher la distance parcourue chaque secondes
          float distancecalc = 0.0;
          if (calculeladistance == 1) {
            distancecalc = calcule_distance( latNOW, lonNOW, oldlatnow, oldlonnow);
            distanceparcouru = distanceparcouru + distancecalc;
          }
          calculeladistance = 1;
          oldlatnow = latNOW;
          oldlonnow = lonNOW;
          if (trajet == 1) { //on démarre le fichier
            start_file();
            trajet = 2;
          }
          if (trajet == 2) { //on écrit les coordonée sur la carte SD
            write_sd_card();
          }
        }
      }
      Serial.println(" ");

      // on gère les menu
      if (menuselector != 0) {
        if (menuselector == 1) {
          menutimedate1();
        } else if (menuselector == 2) {
          if (infogps == 1) {
            menuinfogps1();
          } else if (infogps == 2) {
            menuinfogps2();
          } else if (infogps == 3) {
            menuinfogps3();
          }
        } else if (menuselector == 8) {
          menudistance1();
        }
      }
    }
  } else {
    IRCODE();
  }
}

void print_wday(byte wday)
{
  switch (wday)
  {

    case 1:  Serial.print("Dimanche"); jour = "Dimanche";  break;
    case 2:  Serial.print("Lundi"); jour = "Lundi";  break;
    case 3:  Serial.print("Mardi"); jour = "Mardi";  break;
    case 4:  Serial.print("Mercredi"); jour = "Mercredi";  break;
    case 5:  Serial.print("Jeudi"); jour = "Jeudi";  break;
    case 6:  Serial.print("Vendredi"); jour = "Vendredi";  break;
    default: Serial.print("Samedi"); jour = "Samedi";

  }

}
