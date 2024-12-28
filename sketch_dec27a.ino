// KODE BAGUS
#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>

#define SSID "AndroidAP5076"
#define PASSWORD "LULUSSTIS"
#define API_KEY "AIzaSyB3MdwRKupCRnQn4qFJPmu3UWVcCmp18rc"
#define DATABASE_URL "https://proyekterparkir-4cf71-default-rtdb.firebaseio.com/"

#define TRIG_PIN1 15
#define ECHO_PIN1 2
#define TRIG_PIN2 4
#define ECHO_PIN2 16
#define TRIG_PIN3 17
#define ECHO_PIN3 5

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN1, OUTPUT); pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT); pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIG_PIN3, OUTPUT); pinMode(ECHO_PIN3, INPUT);

  Serial.println("Memulai koneksi Wi-Fi...");
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Menghubungkan ...");
    delay(300);
  }
  Serial.print("Terhubung ke Wi-Fi dengan IP: ");
  Serial.println(WiFi.localIP());

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Serial.println("Menghubungkan ke Firebase...");
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("SignUp berhasil");
  } else {
    Serial.printf("Error SignUp: %s\n", config.signer.signupError.message.c_str());
  }
  Firebase.begin(&config, &auth);
  Serial.println("Firebase dimulai.");
}

float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;
  return distance;
}

void loop() {
  
   // Membaca jarak dari setiap sensor
  float distance1 = getDistance(TRIG_PIN1, ECHO_PIN1);
  float distance2 = getDistance(TRIG_PIN2, ECHO_PIN2);
  float distance3 = getDistance(TRIG_PIN3, ECHO_PIN3);

  // Menampilkan jarak di Serial Monitor
  Serial.printf("Jarak Sensor 10: %.2f cm\n", distance1);
  Serial.printf("Jarak Sensor 11: %.2f cm\n", distance2);
  Serial.printf("Jarak Sensor 12: %.2f cm\n", distance3);
  
  

  // Cek hasil sensor dan tampilkan status di Serial Monitor
  String status10 = (distance1 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
  String status11 = (distance2 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
  String status12 = (distance3 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";


  Serial.println("Status Parkiran:");
  Serial.printf("Sensor 10: %s\n", status1.c_str());
  Serial.printf("Sensor 11: %s\n", status2.c_str());
  Serial.printf("Sensor 12: %s\n", status3.c_str());

 // Kirim data ke Firebase
if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR1/NAMA:G3-F1-2/STATUS", status10)) {
  Serial.println("Status Sensor 10 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 10 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR2/NAMA:G3-F2-1/STATUS", status11)) {
  Serial.println("Status Sensor 11 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 11 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR3/NAMA:G3-F2-2/STATUS", status12)) {
  Serial.println("Status Sensor 12 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 12 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

  delay(100); // Tunggu sebelum membaca ulang
}
