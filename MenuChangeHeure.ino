void heureUTC() {
  if (nbrheure == waitheure) {
    ;
  }else {
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
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Changer l'heure: ");
    lcd.setCursor(0, 1);
    if (nbrheure < 0) {
      lcd.print("UTC "); lcd.print(nbrheure);
    } else {
      lcd.print("UTC +"); lcd.print(nbrheure);
    }
    lcd.setCursor(0, 2);
    lcd.print(Time);
    waitheure = nbrheure;
  }
}
