# This file intentionally left blank
# Keyboard matrix uses shift-registers read via SPI
CUSTOM_MATRIX = lite
SRC += matrix.c
# QUANTUM_LIB_SRC += spi_master.c
SPI_DRIVER_REQUIRED = yes

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
