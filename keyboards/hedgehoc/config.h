#define I2C_DRIVER I2CD0

#define I2C1_SCL_PIN GP1
#define I2C1_SDA_PIN GP0

#define OLED_DISPLAY_32X128

#define MASTER_LEFT
#define SPLIT_USB_TIMEOUT 2000
#define USB_VBUS_PIN GP19


#ifdef OLED_ENABLE
#   define OLED_FONT_H "keyboards/hedgehoc/glcdfont.c"
#endif

#define COMBO_SHOULD_TRIGGER
