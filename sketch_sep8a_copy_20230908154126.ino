#define BLYNK_TEMPLATE_ID "TMPL354MWzFI6";
#define BLYNK_TEMPLATE_NAME "DHT IoT Sensor";
#define BLYNK_AUTH_TOKEN "Zvu-eJ4oDFOtS0kbcmqwv5BmfqoivaoE";
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4
#define DHTTYPE DHT11

char auth[] = "Zvu-eJ4oDFOtS0kbcmqwv5BmfqoivaoE";
char ssid[] = "Vani";
char pass[] = "vani2304";

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  Serial.println("DHT Test Successfull!");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk Connected Successfully");
  dht.begin();

}

void loop() {
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  float f = dht.readTemperature(true);
  if(isnan(humid) || isnan(temp) || isnan(f))
  {
    Serial.println("Sensor humid error");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(humid);
  Serial.println(" %");
  Serial.print("Temperature");
  Serial.print(temp);
  Serial.println(" degrees celsius.");
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, humid);
  delay(1000);

}
