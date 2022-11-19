# Herda as configurações do emulador (produto sdk_phone_x86_64)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)

# Sobrescreve algumas variáveis com os dados do novo produto
PRODUCT_NAME := devhome_smartdoor
PRODUCT_DEVICE := smartdoor
PRODUCT_BRAND := SmartdoorBrand
PRODUCT_MODEL := SmartdoorModel

# Copia o arquivo devhome.txt para o /system/etc da imagem do Android
PRODUCT_COPY_FILES += \
    device/devhome/smartdoor/devhome.txt:system/etc/devhome.txt \
    device/devhome/smartdoor/smartdoor.rc:vendor/etc/init/smartdoor.rc \
    device/devhome/smartdoor/bootanimation.zip:product/media/bootanimation.zip

PRODUCT_SYSTEM_PROPERTIES += \
    ro.devhome.name=smartdoordevHome/SmartDoor

PRODUCT_PRODUCT_PROPERTIES += \
    ro.product.devhome.version=1.0

PRODUCT_VENDOR_PROPERTIES += \
    ro.vendor.devhome.hardware=ModelB

# Seta o diretório de overlays
PRODUCT_PACKAGE_OVERLAYS = device/devhome/smartdoor/overlay

PRODUCT_PACKAGES += \
    nano \
    sl \
    smartdoor_client \
    smartdoor_service_client \
    SmartdoorTestApp


BOARD_SEPOLICY_DIRS += device/devhome/smartdoor/sepolicy

# Smartdoor AIDL Interface
PRODUCT_PACKAGES += devhome.smartdoor

# Smartdoor Binder Service
PRODUCT_PACKAGES += devhome.smartdoor-service

# Device Framework Matrix (Declara que o nosso produto SmartDoor precisa do serviço smartdoor)
DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE := device/devhome/smartdoor/device_framework_matrix.xml

# Manager
PRODUCT_PACKAGES += devhome.smartdoormanager

# Cliente de Linha de Comando para o Serviço Smartdoor
PRODUCT_PACKAGES += smartdoor_service_client

# App Privilegiado de Teste do Serviço Smartdoor
PRODUCT_PACKAGES += SmartdoorTestApp

