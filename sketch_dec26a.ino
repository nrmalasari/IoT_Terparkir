// #include <Arduino.h>
// #include <WiFi.h>
// #include <ESP32Servo.h>
// #include <Firebase_ESP_Client.h>

// #define SSID "AndroidAP5076" // Nama Wi-Fi
// #define PASSWORD "LULUSSTIS" // Passwoard Wi-Fi
// #define API_KEY "AIzaSyB3MdwRKupCRnQn4qFJPmu3UWVcCmp18rc" // API Key Firebase
// #define DATABASE_URL "https://proyekterparkir-4cf71-default-rtdb.firebaseio.com/" // URL Database Firebase

// // Pin untuk sensor ultrasonik
// #define TRIG_PIN1 15    // Gedung 1
// #define ECHO_PIN1 2    // Gedung 1
// #define TRIG_PIN2 4   // Gedung 1
// #define ECHO_PIN2 16  // Gedung 1
// #define TRIG_PIN3 17  // Gedung 1
// #define ECHO_PIN3 5   // Gedung 1
// #define TRIG_PIN4 18  // Gedung 1
// #define ECHO_PIN4 19  // Gedung 1
// #define TRIG_PIN5 22  // Gedung 2
// #define ECHO_PIN5 23  // Gedung 2
// #define TRIG_PIN6 13  // Gedung 2
// #define ECHO_PIN6 12  // Gedung 2
// #define TRIG_PIN7 14  // Gedung 2
// #define ECHO_PIN7 27  // Gedung 2
// #define TRIG_PIN8 26  // Gedung 2
// #define ECHO_PIN8 25  // Gedung 2
// #define TRIG_PIN9 33  // Gedung 3
// #define ECHO_PIN9 32  // Gedung 3
// #define TRIG_PIN10 35 // Gedung 3
// #define ECHO_PIN10 34 // Gedung 3

// // Pin untuk kontrol servo
// #define SERVO_PIN 23

// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// void setup() {
//   Serial.begin(115200);

//   // Konfigurasi pin sensor ultrasonik
//   pinMode(TRIG_PIN1, OUTPUT); pinMode(ECHO_PIN1, INPUT);
//   pinMode(TRIG_PIN2, OUTPUT); pinMode(ECHO_PIN2, INPUT);
//   pinMode(TRIG_PIN3, OUTPUT); pinMode(ECHO_PIN3, INPUT);
//   pinMode(TRIG_PIN4, OUTPUT); pinMode(ECHO_PIN4, INPUT);
//   pinMode(TRIG_PIN5, OUTPUT); pinMode(ECHO_PIN5, INPUT);
//   pinMode(TRIG_PIN6, OUTPUT); pinMode(ECHO_PIN6, INPUT);
//   pinMode(TRIG_PIN7, OUTPUT); pinMode(ECHO_PIN7, INPUT);
//   pinMode(TRIG_PIN8, OUTPUT); pinMode(ECHO_PIN8, INPUT);
//   pinMode(TRIG_PIN9, OUTPUT); pinMode(ECHO_PIN9, INPUT);
//   pinMode(TRIG_PIN10, OUTPUT); pinMode(ECHO_PIN10, INPUT);


//   // // Inisialisasi servo
//   gateServo.attach(SERVO_PIN);
//   gateServo.write(0); // Pastikan palang awalnya tertutup

//   // Koneksi Wi-Fi
//   Serial.println("Memulai koneksi Wi-Fi...");
//   WiFi.begin(SSID, PASSWORD);
//   while (WiFi.status() != WL_CONNECTED) {
//     Serial.print("Menghubungkan ...");
//     delay(300);
//   }
//   Serial.print("Terhubung ke Wi-Fi dengan IP: ");
//   Serial.println(WiFi.localIP());

//   // Konfigurasi Firebase
//   config.api_key = API_KEY;
//   config.database_url = DATABASE_URL;
//   Serial.println("Menghubungkan ke Firebase...");
//   if (Firebase.signUp(&config, &auth, "", "")) {
//     Serial.println("SignUp berhasil");
//   } else {
//     Serial.printf("Error SignUp: %s\n", config.signer.signupError.message.c_str());
//   }
//   Firebase.begin(&config, &auth);
//   Serial.println("Firebase dimulai.");
// }

// float getDistance(int trigPin, int echoPin) {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);
//   long duration = pulseIn(echoPin, HIGH);
//   float distance = duration * 0.0343 / 2;
//   return distance;
// }

// void loop() {

//   if (Firebase.RTDB.getInt(&fbdo, "/email")){
//     palangterbuka = fbdo.intData();
//   }else {
//     Serial.print("tidak menemukan data");
//     Serial.print(fbdo.errorReason());
//   }

//   if (palangterbuka == 1){
//     gateServo.write(90);
//   }else{
//     gateServo.write(0);
//   }

//     // Membaca jarak dari setiap sensor
//   float distance1 = getDistance(TRIG_PIN1, ECHO_PIN1);
//   float distance2 = getDistance(TRIG_PIN2, ECHO_PIN2);
//   float distance3 = getDistance(TRIG_PIN3, ECHO_PIN3);
//   float distance4 = getDistance(TRIG_PIN4, ECHO_PIN4);
//   float distance5 = getDistance(TRIG_PIN5, ECHO_PIN5);
//   float distance6 = getDistance(TRIG_PIN6, ECHO_PIN6);
//   float distance7 = getDistance(TRIG_PIN7, ECHO_PIN7);
//   float distance8 = getDistance(TRIG_PIN8, ECHO_PIN8);
//   float distance9 = getDistance(TRIG_PIN9, ECHO_PIN9);
//   float distance10 = getDistance(TRIG_PIN10, ECHO_PIN10);

//   // Menampilkan jarak di Serial Monitor
//   Serial.printf("Jarak Sensor 1: %.2f cm\n", distance1);
//   Serial.printf("Jarak Sensor 2: %.2f cm\n", distance2);
//   Serial.printf("Jarak Sensor 3: %.2f cm\n", distance3);
//   Serial.printf("Jarak Sensor 4: %.2f cm\n", distance4);
//   Serial.printf("Jarak Sensor 5: %.2f cm\n", distance5);
//   Serial.printf("Jarak Sensor 6: %.2f cm\n", distance6);
//   Serial.printf("Jarak Sensor 7: %.2f cm\n", distance7);
//   Serial.printf("Jarak Sensor 8: %.2f cm\n", distance8);
//   Serial.printf("Jarak Sensor 9: %.2f cm\n", distance9);
//   Serial.printf("Jarak Sensor 10: %.2f cm\n", distance10);

//   // Cek hasil sensor dan tampilkan status di Serial Monitor
//   String status1 = (distance1 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
//   String status2 = (distance2 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
//   String status3 = (distance3 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
//   String status4 = (distance4 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
//   String status5 = (distance5 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
//   String status6 = (distance6 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
//   String status7 = (distance7 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
//   String status8 = (distance8 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
//   String status9 = (distance9 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
//   String status10 = (distance10 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";

//   Serial.println("Status Parkiran:");
//   Serial.printf("Sensor 1: %s\n", status1.c_str());
//   Serial.printf("Sensor 2: %s\n", status2.c_str());
//   Serial.printf("Sensor 3: %s\n", status3.c_str());
//   Serial.printf("Sensor 4: %s\n", status4.c_str());
//   Serial.printf("Sensor 5: %s\n", status5.c_str());
//   Serial.printf("Sensor 6: %s\n", status6.c_str());
//   Serial.printf("Sensor 7: %s\n", status7.c_str());
//   Serial.printf("Sensor 8: %s\n", status8.c_str());
//   Serial.printf("Sensor 9: %s\n", status9.c_str());
//   Serial.printf("Sensor 10: %s\n", status10.c_str());

//  // Kirim data ke Firebase
// if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR1/NAMA:G1-F1-1/STATUS", status1)) {
//   Serial.println("Status Sensor 1 berhasil dikirim ke Firebase");
// } else {
//   Serial.print("Gagal mengirim status Sensor 1 ke Firebase: ");
//   Serial.println(fbdo.errorReason());
// }

// if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR2/NAMA:G1-F1-2/STATUS", status2)) {
//   Serial.println("Status Sensor 2 berhasil dikirim ke Firebase");
// } else {
//   Serial.print("Gagal mengirim status Sensor 2 ke Firebase: ");
//   Serial.println(fbdo.errorReason());
// }

// if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR3/NAMA:G1-F2-1/STATUS", status3)) {
//   Serial.println("Status Sensor 3 berhasil dikirim ke Firebase");
// } else {
//   Serial.print("Gagal mengirim status Sensor 3 ke Firebase: ");
//   Serial.println(fbdo.errorReason());
// }

// if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR4/NAMA:G1-F2-2/STATUS", status4)) {
//   Serial.println("Status Sensor 4 berhasil dikirim ke Firebase");
// } else {
//   Serial.print("Gagal mengirim status Sensor 4 ke Firebase: ");
//   Serial.println(fbdo.errorReason());
// }

// if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR5/NAMA:G2-F1-1/STATUS", status5)) {
//   Serial.println("Status Sensor 5 berhasil dikirim ke Firebase");
// } else {
//   Serial.print("Gagal mengirim status Sensor 5 ke Firebase: ");
//   Serial.println(fbdo.errorReason());
// }

// if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR6/NAMA:G2-F1-2/STATUS", status6)) {
//   Serial.println("Status Sensor 6 berhasil dikirim ke Firebase");
// } else {
//   Serial.print("Gagal mengirim status Sensor 6 ke Firebase: ");
//   Serial.println(fbdo.errorReason());
// }

// if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR7/NAMA:G2-F2-1/STATUS", status7)) {
//   Serial.println("Status Sensor 7 berhasil dikirim ke Firebase");
// } else {
//   Serial.print("Gagal mengirim status Sensor 7 ke Firebase: ");
//   Serial.println(fbdo.errorReason());
// }

// if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR8/NAMA:G2-F2-2/STATUS", status8)) {
//   Serial.println("Status Sensor 8 berhasil dikirim ke Firebase");
// } else {
//   Serial.print("Gagal mengirim status Sensor 8 ke Firebase: ");
//   Serial.println(fbdo.errorReason());
// }

// if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR9/NAMA:G3-F1-1/STATUS", status9)) {
//   Serial.println("Status Sensor 9 berhasil dikirim ke Firebase");
// } else {
//   Serial.print("Gagal mengirim status Sensor 9 ke Firebase: ");
//   Serial.println(fbdo.errorReason());
// }

// if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR10/NAMA:G3-F1-2/STATUS", status10)) {
//   Serial.println("Status Sensor 10 berhasil dikirim ke Firebase");
// } else {
//   Serial.print("Gagal mengirim status Sensor 10 ke Firebase: ");
//   Serial.println(fbdo.errorReason());
// }


//   delay(100); // Tunggu sebelum membaca ulang
// }


// KODE BAGUS
#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>
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
#define TRIG_PIN4 18
#define ECHO_PIN4 19
#define TRIG_PIN5 22
#define ECHO_PIN5 23
#define TRIG_PIN6 13
#define ECHO_PIN6 12
#define TRIG_PIN7 14
#define ECHO_PIN7 27
#define TRIG_PIN8 26
#define ECHO_PIN8 25
#define TRIG_PIN9 33
#define ECHO_PIN9 32


#define SERVO_PIN 21
#define SERVO_PIN2 35

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

Servo gateServo; // Deklarasi objek servo
Servo gateServo2; // Deklarasi objek servo
int palangterbuka = 0; // Deklarasi variabel untuk status palang
int palangtutup = 0; // Deklarasi variabel untuk status palang


void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN1, OUTPUT); pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT); pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIG_PIN3, OUTPUT); pinMode(ECHO_PIN3, INPUT);
  pinMode(TRIG_PIN4, OUTPUT); pinMode(ECHO_PIN4, INPUT);
  pinMode(TRIG_PIN5, OUTPUT); pinMode(ECHO_PIN5, INPUT);
  pinMode(TRIG_PIN6, OUTPUT); pinMode(ECHO_PIN6, INPUT);
  pinMode(TRIG_PIN7, OUTPUT); pinMode(ECHO_PIN7, INPUT);
  pinMode(TRIG_PIN8, OUTPUT); pinMode(ECHO_PIN8, INPUT);
  pinMode(TRIG_PIN9, OUTPUT); pinMode(ECHO_PIN9, INPUT);

  gateServo.attach(SERVO_PIN);
  gateServo.write(0);
  gateServo2.attach(SERVO_PIN2);
  gateServo2.write(0);

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
  if (Firebase.RTDB.getInt(&fbdo, "/email")) {
    palangterbuka = fbdo.intData();
  } else {
    Serial.print("tidak menemukan data: ");
    Serial.println(fbdo.errorReason());
  }

  if (palangterbuka == 1) {
    gateServo.write(90);
  } else {
    gateServo.write(0);
  }

  if (Firebase.RTDB.getInt(&fbdo, "/palang_status")) {
    palangtutup = fbdo.intData();
  } else {
    Serial.print("tidak menemukan data: ");
    Serial.println(fbdo.errorReason());
  }

  if (palangtutup == 1) {
    gateServo2.write(90);
  } else {
    gateServo2.write(0);
  }

  
   // Membaca jarak dari setiap sensor
  float distance1 = getDistance(TRIG_PIN1, ECHO_PIN1);
  float distance2 = getDistance(TRIG_PIN2, ECHO_PIN2);
  float distance3 = getDistance(TRIG_PIN3, ECHO_PIN3);
  float distance4 = getDistance(TRIG_PIN4, ECHO_PIN4);
  float distance5 = getDistance(TRIG_PIN5, ECHO_PIN5);
  float distance6 = getDistance(TRIG_PIN6, ECHO_PIN6);
  float distance7 = getDistance(TRIG_PIN7, ECHO_PIN7);
  float distance8 = getDistance(TRIG_PIN8, ECHO_PIN8);
  float distance9 = getDistance(TRIG_PIN9, ECHO_PIN9);
  

  // Menampilkan jarak di Serial Monitor
  Serial.printf("Jarak Sensor 1: %.2f cm\n", distance1);
  Serial.printf("Jarak Sensor 2: %.2f cm\n", distance2);
  Serial.printf("Jarak Sensor 3: %.2f cm\n", distance3);
  Serial.printf("Jarak Sensor 4: %.2f cm\n", distance4);
  Serial.printf("Jarak Sensor 5: %.2f cm\n", distance5);
  Serial.printf("Jarak Sensor 6: %.2f cm\n", distance6);
  Serial.printf("Jarak Sensor 7: %.2f cm\n", distance7);
  Serial.printf("Jarak Sensor 8: %.2f cm\n", distance8);
  Serial.printf("Jarak Sensor 9: %.2f cm\n", distance9);
  

  // Cek hasil sensor dan tampilkan status di Serial Monitor
  String status1 = (distance1 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
  String status2 = (distance2 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
  String status3 = (distance3 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
  String status4 = (distance4 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
  String status5 = (distance5 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
  String status6 = (distance6 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
  String status7 = (distance7 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
  String status8 = (distance8 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";
  String status9 = (distance9 <= 5) ? "Parkiran Terisi" : "Parkiran Kosong";

  Serial.println("Status Parkiran:");
  Serial.printf("Sensor 1: %s\n", status1.c_str());
  Serial.printf("Sensor 2: %s\n", status2.c_str());
  Serial.printf("Sensor 3: %s\n", status3.c_str());
  Serial.printf("Sensor 4: %s\n", status4.c_str());
  Serial.printf("Sensor 5: %s\n", status5.c_str());
  Serial.printf("Sensor 6: %s\n", status6.c_str());
  Serial.printf("Sensor 7: %s\n", status7.c_str());
  Serial.printf("Sensor 8: %s\n", status8.c_str());
  Serial.printf("Sensor 9: %s\n", status9.c_str());

 // Kirim data ke Firebase
if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR1/NAMA:G1-F1-1/STATUS", status1)) {
  Serial.println("Status Sensor 1 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 1 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR2/NAMA:G1-F1-2/STATUS", status2)) {
  Serial.println("Status Sensor 2 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 2 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR3/NAMA:G1-F2-1/STATUS", status3)) {
  Serial.println("Status Sensor 3 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 3 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR4/NAMA:G1-F2-2/STATUS", status4)) {
  Serial.println("Status Sensor 4 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 4 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR5/NAMA:G2-F1-1/STATUS", status5)) {
  Serial.println("Status Sensor 5 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 5 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR6/NAMA:G2-F1-2/STATUS", status6)) {
  Serial.println("Status Sensor 6 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 6 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR7/NAMA:G2-F2-1/STATUS", status7)) {
  Serial.println("Status Sensor 7 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 7 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR8/NAMA:G2-F2-2/STATUS", status8)) {
  Serial.println("Status Sensor 8 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 8 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

if (Firebase.RTDB.setString(&fbdo, "/DATA_SENSOR/SENSOR9/NAMA:G3-F1-1/STATUS", status9)) {
  Serial.println("Status Sensor 9 berhasil dikirim ke Firebase");
} else {
  Serial.print("Gagal mengirim status Sensor 9 ke Firebase: ");
  Serial.println(fbdo.errorReason());
}

  delay(100); // Tunggu sebelum membaca ulang
}
