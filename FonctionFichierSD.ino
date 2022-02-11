void start_file() {
  SD.mkdir("/trajet/kmlfile/" + nameFile + "/");
  String chemin = "/trajet/kmlfile/" + nameFile + "/" + nameFile + ".kml";
  myFile = SD.open(chemin, FILE_WRITE);
  myFile.println("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
  myFile.println("<kml xmlns=\"http://www.opengis.net/kml/2.2\">");
  myFile.println("<Document>");
  myFile.println("<name>GPS Route</name>");
  myFile.println("<Placemark>");
  myFile.println("<name>" + nameFile + " GPS Route</name>");
  myFile.println("<LineString>");
  myFile.println("<coordinates>");
  myFile.close();
  SD.remove("p/t/tjtcour.txt");

  File mySave = SD.open("/trajet/nomfich/" + nameFile + ".txt", FILE_WRITE);
  mySave.print(nameFile);
  mySave.close();

  File myFileFolder = SD.open("p/t/tjtcour.txt", FILE_WRITE);
  myFileFolder.print(nameFile);
  myFileFolder.close();
  //{"SatMax":"12","AltMax":"80","SpeedMax":"130"}
  Serial.println("démarrage du trajet");
}

void write_sd_card() {
  compteTemps = compteTemps + 1;
  String chemin = "/trajet/kmlfile/" + nameFile + "/" + nameFile + ".kml";
  myFile = SD.open(chemin, FILE_WRITE);
  myFile.print(gps.location.lng(), 6);
  myFile.print(",");
  myFile.print(gps.location.lat(), 6);
  myFile.print(",");
  myFile.println(gps.altitude.meters());
  myFile.close();

  SD.remove("/trajet/kmlfile/" + nameFile + "/data.txt");
  File myData = SD.open("/trajet/kmlfile/" + nameFile + "/data.txt", FILE_WRITE);
  String Jsonformat = "{\"SatMax\":\"" + String(MaxSat) + "\",\"AltMax\":\"" + String(MaxAlt) + "\",\"SpeedMax\":\"" + String(MaxSpeed) + "\", \"TempsTrajet\":\"" + String(compteTemps) + "\"}";
  myData.print(Jsonformat);
  myData.close();

  File myLog = SD.open("/trajet/kmlfile/" + nameFile + "/log.txt", FILE_WRITE);
  myLog.print(Time);
  myLog.print(" - ");
  myLog.print(Date);
  myLog.print(": Sat: ");
  myLog.print(gps.satellites.value());
  myLog.print(" , Sat Max: ");
  myLog.print(MaxSat);
  myLog.print(" , Vitesse: ");
  myLog.print(gps.speed.kmph());
  myLog.print("k/h , Vitesse Max: ");
  myLog.print(MaxSpeed);
  myLog.print("k/h , Altitude: ");
  myLog.print(gps.altitude.meters());
  myLog.print("m , Altitude Max: ");
  myLog.print(MaxAlt);
  myLog.print("m , Angle: ");
  myLog.print(gps.course.deg());
  myLog.print("deg , dist. Parcourue: ");
  myLog.print(distanceparcouru, 3);
  myLog.print("km , Humidité: ");
  myLog.print(h);
  myLog.print("% , Temperature: ");
  myLog.print(t);
  myLog.print("°C , Latitude: ");
  myLog.print(gps.location.lat(), 8);
  myLog.print(" , Longitude: ");
  myLog.println(gps.location.lng(), 8);
  myLog.close();
  Serial.println("écriture sur la carte sd");
}

void finish_file() {
  String chemin = "/trajet/kmlfile/" + nameFile + "/" + nameFile + ".kml";
  myFile = SD.open(chemin, FILE_WRITE);
  myFile.println("</coordinates>");
  myFile.println("</LineString>");
  myFile.println("<Style>");
  myFile.println("<LineStyle>");
  myFile.println("<color>##F1C40F</color>");
  myFile.println("<width>5</width>");
  myFile.println("</LineStyle>");
  myFile.println("</Style>");
  myFile.println("</Placemark>");
  myFile.println("</Document>");
  myFile.print("</kml>");
  myFile.close();
  trajet = 0;
  SD.remove("p/t/tjtcour.txt");
  SD.remove("/trajet/kmlfile/" + nameFile + "/time.txt");
  SD.remove("/trajet/kmlfile/" + nameFile + "/data.txt");
  File mySave = SD.open("p/t/tjtcour.txt", FILE_WRITE);
  mySave.print("");
  mySave.close();

  secondeTrajet = compteTemps % 60;
  minuteTrajet = (compteTemps / 60) % 60;
  heureTrajet = (compteTemps / (60 * 60));

  Serial.print("Le trajet a duré "); Serial.print(heureTrajet); Serial.print(" heure(s), "); Serial.print(minuteTrajet); Serial.print(" minute(s), "); Serial.print(secondeTrajet); Serial.println("seconde(s)");

File myDebrif = SD.open("/trajet/kmlfile/" + nameFile + "/recap.txt", FILE_WRITE);
  myDebrif.print("Vitesse Maximum : ");
  myDebrif.println(MaxSpeed);
  myDebrif.print("Altitude Maximum : ");
  myDebrif.println(MaxAlt);
  myDebrif.print("Satellite Maximum : ");
  myDebrif.println(MaxSat);
  myDebrif.print("Angle : ");
  myDebrif.println(gps.course.deg());
  myDebrif.print("Distance parcourue : ");
  myDebrif.println(distanceparcouru, 3);
  myDebrif.print("Temp de trajet : ");
  myDebrif.print("Le trajet a duré "); myDebrif.print(heureTrajet); myDebrif.print(" heure(s), "); myDebrif.print(minuteTrajet); myDebrif.print(" minute(s), "); myDebrif.print(secondeTrajet); myDebrif.println("seconde(s)");
  myDebrif.close();
  Serial.println("fin du trajet");
}
