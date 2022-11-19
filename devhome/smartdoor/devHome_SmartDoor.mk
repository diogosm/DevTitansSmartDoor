# Herda as configurações do emulador (produto sdk_phone_x86_64)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)

# Sobrescreve algumas variáveis com os dados do novo produto
PRODUCT_NAME := devHome_SmartDoor
PRODUCT_DEVICE := SmartDoor
PRODUCT_BRAND := SmartDoorBrand
PRODUCT_MODEL := SmartDoorModel

# Copia o arquivo devhome.txt para o /system/etc da imagem do Android
PRODUCT_COPY_FILES += \
    device/devhome/smartDoor/devhome.txt:system/etc/devhome.txt \
    device/devhome/smartDoor/smartdoor.rc:vendor/etc/init/smartdoor.rc \
    device/devhome/smartDoor/bootanimation.zip:product/media/bootanimation.zip

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
    smartdoor_client


BOARD_SEPOLICY_DIRS += device/devhome/smartdoor/sepolicy

# Smartlamp AIDL Interface
PRODUCT_PACKAGES += devhome.smartdoor

# Smartlamp Binder Service
PRODUCT_PACKAGES += devhome.smartdoor-service

# Device Framework Matrix (Declara que o nosso produto SmartDoor precisa do serviço smartdoor)
DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE := device/devhome/smartdoor/device_framework_matrix.xml

# Manager
PRODUCT_PACKAGES += devhome.smartdoormanager

# Cliente de Linha de Comando para o Serviço Smartlamp
PRODUCT_PACKAGES += smartdoor_service_client

# App Privilegiado de Teste do Serviço Smartlamp
PRODUCT_PACKAGES += SmartdoorTestApp

