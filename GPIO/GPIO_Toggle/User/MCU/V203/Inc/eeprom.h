/*
 * bootloader.h
 *
 *  Created on: Mar. 25, 2020
 *      Author: Alka
 */
#include "main.h"

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_




void save_flash_nolib(uint8_t *data, int length, uint32_t add);
void read_flash_bin(uint8_t*  data , uint32_t add , int out_buff_len);

#endif /* INC_BOOTLOADER_H_ */
