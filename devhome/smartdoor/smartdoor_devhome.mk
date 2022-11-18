# Herda as configurações do emulador (produto sdk_phone_x86_64)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)

# Sobrescreve algumas variáveis com os dados do novo produto
PRODUCT_NAME := smartdoor_devhome
PRODUCT_DEVICE := devhome
PRODUCT_BRAND := DevhomeBrand
PRODUCT_MODEL := DevhomeModel

# Copia o arquivo devtitans.txt para o /system/etc da imagem do Android
PRODUCT_COPY_FILES += \
    device/devhome/SmartDoor/devhome.txt:system/etc/devhome.txt \
    device/devhome/SmartDoor/devhome:vendor/etc/init/smartdoor.rc \
    device/devhome/SmartDoor/bootanimation.zip:product/media/bootanimation.zip

PRODUCT_SYSTEM_PROPERTIES += \
    ro.devhome.name=SmartDoor

PRODUCT_PRODUCT_PROPERTIES += \
    ro.product.devhome.version=1.0

PRODUCT_VENDOR_PROPERTIES += \
    ro.vendor.devhome.hardware=ModelB
# Seta o diretório de overlays
PRODUCT_PACKAGE_OVERLAYS = device/devHome/SmartDoor/overlay

PRODUCT_PACKAGES += \
    UniversalMediaPlayer \
    hello_c \
    nano \
    sl \
    smartdoor_client


BOARD_SEPOLICY_DIRS += device/devHome/SmartDoor/sepolicy

# Smartdoor AIDL Interface
PRODUCT_PACKAGES += devHome.smartdoor

# Smartdoor Binder Service
PRODUCT_PACKAGES += devHome.smartdoor-service

# Device Framework Matrix (Declara que o nosso produto Kraken precisa do serviço smartlamp)
DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE := device/devHome/SmartDoor/device_framework_matrix.xml

# Manager
PRODUCT_PACKAGES += devHome.smartdoormanager

# Cliente de Linha de Comando para o Serviço Smartdoor
PRODUCT_PACKAGES += smartdoor_service_client

# App Privilegiado de Teste do Serviço Smartdoor
PRODUCT_PACKAGES += SmartdoorTestApp
