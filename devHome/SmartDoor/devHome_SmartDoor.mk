# Herda as configurações do emulador (produto sdk_phone_x86_64)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)

# Sobrescreve algumas variáveis com os dados do novo produto
PRODUCT_NAME := devHome_SmartDoor
PRODUCT_DEVICE := SmartDoor
PRODUCT_BRAND := SmartDoorBrand
PRODUCT_MODEL := SmartDoorModel
