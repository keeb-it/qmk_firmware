// Copyright 2020-2023 numToStr (@numToStr)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "wait.h"
#include "spi_master.h"
// #include "split_common/split_util.h"

#if defined(CONSOLE_ENABLE)
#    include "print.h"
#endif

#define ROWS_PER_HAND (MATRIX_ROWS / 2)

static const uint16_t col_values_left[MATRIX_COLS] = MATRIX_COLS_LEFT;
static const uint16_t col_values_right[MATRIX_COLS] = MATRIX_COLS_RIGHT;
static const pin_t    row_pins[ROWS_PER_HAND]   = MATRIX_ROW_PINS;

static const int    msize = ROWS_PER_HAND * sizeof(matrix_row_t);
static matrix_row_t prev_matrix[ROWS_PER_HAND];

static inline uint8_t read_rows(void) {
    uint8_t r = readPin(row_pins[0]);

    for (uint8_t row = 1; row < ROWS_PER_HAND; row++) {
        r |= (readPin(row_pins[row]) << row);
    }
    return r;
}

static inline void shift_out(uint16_t value) {
    uint8_t message[2] = {(value >> 8) & 0xFF, (uint8_t)(value & 0xFF)};

    writePinLow(SPI_LATCH_PIN);
    spi_transmit(message, 2);
    writePinHigh(SPI_LATCH_PIN);
    // NOTE:
    // Using `matrix_io_delay` instead of `matrix_output_select_delay` because of double keypress bug.
    // Read more at https://discord.com/channels/440868230475677696/1202661103662792714
    matrix_io_delay();
    // matrix_output_select_delay();
}

static inline void select_col(uint8_t col) {
    if (is_keyboard_left()) {
        shift_out(col_values_left[col]);
    } else {
        shift_out(col_values_right[col]);
    }
}

void matrix_init_custom(void) {
#if defined(CONSOLE_ENABLE)
    wait_ms(3000);
#endif
    for (uint8_t row = 0; row < ROWS_PER_HAND; row++) {
        setPinInputLow(row_pins[row]);
    }
    matrix_io_delay();
    spi_init();
    matrix_io_delay();

    setPinOutput(SPI_LATCH_PIN);
    spi_start(SPI_LATCH_PIN, SPI_lsbFirst, SPI_MODE, SPI_DIVISOR);
    matrix_io_delay();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    memset(current_matrix, 0, msize);

    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        select_col(col);

        uint8_t rows = read_rows();
        for (uint8_t row = 0; row < ROWS_PER_HAND; row++) {
            current_matrix[row] |= (((rows & (1 << row)) ? 1 : 0) << col);
        }
    }
    bool changed = (memcmp(current_matrix, prev_matrix, msize) != 0);
    memcpy(prev_matrix, current_matrix, msize);
    return changed;
}
