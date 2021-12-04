void start_file() {
  myFile = SD.open("/trajet/" + nameFile + ".kml", FILE_WRITE);
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
  File mySave = SD.open("p/t/tjtcour.txt", FILE_WRITE);
  mySave.print(nameFile);
  mySave.close();
}

void write_sd_card() {
  myFile = SD.open("/trajet/" + nameFile + ".kml", FILE_WRITE);
  myFile.print(gps.location.lng(), 6);
  myFile.print(",");
  myFile.print(gps.location.lat(), 6);
  myFile.print(",");
  myFile.println(gps.altitude.meters());
  myFile.close();
}

void finish_file() {
  myFile = SD.open("/trajet/" + nameFile + ".kml", FILE_WRITE);
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
  File mySave = SD.open("p/t/tjtcour.txt", FILE_WRITE);
  mySave.print("");
  mySave.close();
}
