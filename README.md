# Akıllı Bitki Sulama Sistemi

Bu proje, toprak nem sensörü kullanarak bitkilerin otomatik sulanmasını sağlayan basit bir Arduino tabanlı akıllı sulama sistemidir. Bitkinin toprağı belirlenen nem seviyesinin altına düştüğünde, sistem su pompasını aktif ederek sulama işlemini gerçekleştirir.

---

## İçindekiler

- [Proje Hakkında](#proje-hakkında)
- [Kullanılan Malzemeler](#kullanılan-malzemeler)
- [Bağlantı Şeması](#bağlantı-şeması)
- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Kodun Açıklaması](#kodun-açıklaması)
- [Geliştirme ve İyileştirmeler](#geliştirme-ve-iyileştirmeler)

---

## Proje Hakkında

Bu sistem, toprak nem sensöründen gelen verileri okuyarak toprağın nem seviyesini ölçer. Nem seviyesi belirlenen eşik değerinin altındaysa, sulama pompası çalıştırılır. Böylece bitki sürekli olarak optimum nem seviyesinde tutulur.

---

## Kullanılan Malzemeler

- Arduino Uno (veya uyumlu başka bir Arduino kartı)  
- Toprak Nem Sensörü  
- Su Pompası (veya röle modülü ile kontrol edilen pompa)  
- 16x2 LCD Ekran (opsiyonel, nem değerlerini göstermek için)  
- Bağlantı kabloları  
- Güç kaynağı  

---

## Bağlantı Şeması

- Toprak Nem Sensörünün veri pini Arduino'nun A0 analog girişine bağlanır.  
- Pompa, Arduino'nun dijital çıkış pinlerinden birine bağlanır (örn. D8) ve genellikle bir röle modülü ile kontrol edilir.  
- LCD ekranın bağlantısı için I2C modülü varsa SDA ve SCL pinleri kullanılır (A4 ve A5 pinleri Arduino Uno için).
  
<img width="454" height="252" alt="şemaa" src="https://github.com/user-attachments/assets/a188745a-9b1b-4400-80f2-4f5bf92fb21c" />

---

## Kurulum

1. Arduino IDE'yi bilgisayarınıza indirin ve yükleyin.  
2. `bitki_sulama.ino` dosyasını Arduino IDE ile açın.  
3. Bağlantıları yukarıdaki şemaya göre yapın.  
4. Kodda, nem seviyesi eşik değerini ihtiyacınıza göre ayarlayın (`soilMoistureThreshold`).  
5. Arduino'yu bilgisayara bağlayın ve kodu yükleyin.  

---

## Kullanım

- Sistem çalıştığında, toprak nem sensöründen aldığı değeri düzenli olarak okuyacak.  
- Nem seviyesi eşik değerinin altındaysa pompa aktif olacak ve bitki sulanacak.  
- Eşik değer üzerindeyse pompa kapalı kalacak.  
- LCD ekran kullanılıyorsa nem değeri ekranda gösterilecektir.  

---

## Kodun Açıklaması

- `soilMoistureSensorPin`: Nem sensörünün bağlı olduğu analog pin.  
- `pumpPin`: Pompanın kontrol edildiği dijital pin.  
- `soilMoistureThreshold`: Nem sensörü değerinin pompanın açılması için gerekli eşik değeri.  
- `setup()` fonksiyonunda pinler ayarlanır ve LCD başlatılır.  
- `loop()` fonksiyonunda sensör değeri okunur, eşik ile karşılaştırılır ve pompa kontrol edilir.  

---

## Geliştirme ve İyileştirmeler

- WiFi modülü eklenerek verilerin uzaktan izlenmesi.  
- Nem verilerinin grafiksel olarak kaydedilmesi.  
- Güneş enerjisiyle çalışan güç kaynağı entegrasyonu.  
- Daha hassas sulama için zamanlama algoritmaları eklenmesi.  

---


