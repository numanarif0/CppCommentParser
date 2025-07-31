#!/bin/bash

# Herhangi bir komut başarısız olursa betiği durdur.
set -e

# Betiğin çalıştığı dizini projenin ana dizini olarak ayarla.
cd "$(dirname "$0")"

echo "🚀 Derleme ve çalıştırma süreci başlıyor..."

# 1. Eski 'build' dizinini temizle ve yeniden oluştur.
if [ -d "build" ]; then
    echo "🧹 Eski 'build' dizini temizleniyor..."
    rm -rf build
fi
echo "🛠️ Yeni 'build' dizini oluşturuluyor..."
mkdir build

# 2. 'build' dizinine geç.
cd build

# 3. CMake ile proje yapılandırmasını yap.
echo "⚙️ CMake ile proje yapılandırılıyor (Ninja)..."
cmake -G "Ninja" ..

# 4. Ninja ile projeyi derle.
echo "🏗️ Ninja ile proje derleniyor..."
ninja

# 5. Oluşturulan uygulamayı çalıştır.
echo "▶️  Uygulama çalıştırılıyor: ./cmtParser.exe"
echo "------------------------------------------"
./cmtParser.exe
echo "------------------------------------------"

echo "✅ Süreç başarıyla tamamlandı!"