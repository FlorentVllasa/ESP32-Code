# ESP32/MPU-9250

### Beschreibung
Dieses Projekt dient dazu die Sensordaten des MPU-9250 zu einem Socketserver zu senden. Der Server muss dann diese Daten herausfiltern und sie nutzen.

### Voraussetzungen

    * VSCode
    * Extension: PlatformIO
    * ESP32 und MPU-9250 Hardware

### Pin Layout

ESP32 | MPU9250
------ | ------
3V3  | VCC 
GND  | GND
G32  | SDA
G33  | SCL

### Verwendung

#### Vorbereitende Maßnahmen
Bevor das Projekt kompiliert und ausgeführt wird, sollte man seine eigenen WLAN Daten eingeben, je nachdem in welchem Netzwerk man sich befindet. Dies kann in der Datei wifi_con.cpp erfolgen. Danach sollten in der data_client.cpp die Ziel IP-Adresse und Ziel Port angepasst werden.

#### Praktisches Starten
Im linken Navigations Menü von VSCode auf das PlatformIO Symbol klicken. Danach ganz oben links auf "Build" klicken. Der Kompiliervorgang startet. Wenn dies erflogreich war, wäre der nächste Schritt auf "Upload" zu klicken direkt unterhalb von "Build". Wenn nach dem ESP32 gesucht wird sollte man die BOOT-Taste des ESPs gedrückt halten damit der Flashvorgang starten kann.

### Abschließende Worte
Im Projekt befindet sich eine zweite Library mit anderen Möglichkeiten der Datenmanipulation falls interesse besteht damit zu experimentieren.