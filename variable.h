byte oooconnection[] = {
  B00000,
  B00001,
  B00101,
  B00101,
  B10101,
  B10101,
  B00000,
  B00000
};

byte ooconnection[] = {
  B00000,
  B00000,
  B00100,
  B00100,
  B10100,
  B10100,
  B00000,
  B00000
};

byte oconnection[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B10000,
  B00000,
  B00000,
  B00000
};

byte noconnection[] = {
  B00000,
  B10001,
  B01010,
  B00100,
  B01010,
  B10001,
  B00000,
  B00000
};

byte tiretdehaut[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

static const int RXPin = 4, TXPin = 5;
static const uint32_t GPSBaud = 9600;

const int redPin = 10;
const int greenPin = 9;
const int bluePin = 11;
String codeverif = "";
String nomFichier;
const int chipSelect = 53;
char Time[]   = "Time: 00:00:00";
char Date[]   = "Date: 00-00-2000";
char TRAJET[] = "00000000";
String Code  = "ABCDEF";
String NCode  = "ABCDEF";
byte last_second, Second, Minute, Hour, Day, Month;
int Year;
uint16_t nbFichiers = 0;    // nombre de fichiers sur la carte SD
uint16_t noFichier; // le fichier en cours
int RECV_PIN = 5;
int menu = 1;
int onglet = 6;
int menuselector = 0;
unsigned long key_value = 0;
String jour;
int infogps = 1;
int menuparam = 1;
int effafich = 0;
int trajet = 0;
String nameFile;
int choixlcd = 1;
int menuselectorlcd = 0;
int menuselectortrajet = 0;
int blacklight = 1;
int menuparametre = 0;
int ligne = 0;
int satconnection = 0;
int numcodeun = 0;
int numcodedeux = 0;
int numcodetrois = 0;
int numcodequatre = 0;
int numcodecinq = 0;
int numcodesix = 0;
int comptenumcode = 0;
int code = 1;
int nbrdecharlat = 0;
int nbrpointlat = 0;
int nbrpointlon = 0;
int nbrdecharlon = 0;
unsigned long octetFile;
float oldlatnow  = 0.0;
float oldlonnow  = 0.0;
float latNOW = 0;
float lonNOW = 0;
String latDesti = "";
String lonDesti = "";
String StrlonDesti = "";
String StrlatDesti = "";
float distance = 0.0;
int distancechoix = 1;
int calculeladistance = 0;
float distanceparcouru = 0.0;
int nbrheure;
int MaxSat = 0;
int MaxSpeed = 0;
int MaxAlt = 0;
float h;
float t;
float tr;
int waitheure;
String IRdatatel = "";
int numtel = 1;
int numfiletel = 1;
int numtelenter = 1;
int nouvtel = 0;
int tablefinish = 0;
int compteTemps = 0;
int secondeTrajet = 0;
int minuteTrajet = 0;
int heureTrajet = 0;
int jourTrajet = 0;
