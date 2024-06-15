# This file intentionally left blank
# Keyboard matrix uses shift-registers read via SPI
CUSTOM_MATRIX = lite
SRC += matrix.c
# QUANTUM_LIB_SRC += spi_master.c
SPI_DRIVER_REQUIRED = yes
SERIAL_DRIVER = vendor
# OLED_ENABLE = yes
# WPM_ENABLE = yes

# AUDIO_ENABLE = yes
# AUDIO_DRIVER = pwm_hardware
