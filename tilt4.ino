const int tiltDigitalPin = 2; // Tilt sensörünün dijital çıkış pini
const int tiltAnalogPin = A0;  // Tilt sensörünün analog çıkış pini

void setup() {
  // Seri iletişimi 9600 baud hızında başlat
  Serial.begin(9600);

  // Tilt sensörünün dijital çıkış pinini giriş olarak ayarla
  pinMode(tiltDigitalPin, INPUT);
}

void loop() {
  // Tilt sensörünün dijital çıkış durumunu oku
  int tiltDigitalState = digitalRead(tiltDigitalPin);

  // Tilt sensörünün analog çıkış değerini oku
  int tiltAnalogValue = analogRead(tiltAnalogPin);

  // Analog değeri 0-180 derecelik eğim aralığına dönüştür
  float tiltAngle = map(tiltAnalogValue, 0, 1023, 0, 180);

  // Sensörün durumunu belirle
  String tiltStatus;
  if (tiltDigitalState == HIGH) {
    tiltStatus = "Dik"; // Sensör dik konumda
  } else {
    tiltStatus = "Yatay veya Eğik"; // Sensör yatay veya eğik konumda
  }

  // Seri monitöre tilt bilgilerini yazdır
  Serial.print("Tilt Dijital Durumu: ");
  Serial.println(tiltDigitalState);
  Serial.print("Tilt Analog Değeri: ");
  Serial.println(tiltAnalogValue);
  Serial.print("Tilt Açısı: ");
  Serial.println(tiltAngle, 1); // Ondalık basamak sayısını 1 olarak ayarla
  Serial.print("Tilt Durumu: ");
  Serial.println(tiltStatus);

  // Kısa bir gecikme
  delay(300); // Gecikme süresi (milisaniye cinsinden)
}
