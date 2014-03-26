/* automaton
 * (c) 2014 Justin Gottula
 * The source code of this project is distributed under the terms of the
 * simplified BSD license. See the LICENSE file for details.
 */


#ifndef AUTOMATON_DEV_CAN_MCP2515_H
#define AUTOMATON_DEV_CAN_MCP2515_H


#include "std.h"


enum {
	MCP_REG_TEC      = 0b00011100,
	MCP_REG_REC      = 0b00011101,
	
	MCP_REG_CNF3     = 0b00101000,
	MCP_REG_CNF2     = 0b00101001,
	MCP_REG_CNF1     = 0b00101010,
	MCP_REG_CANINTE  = 0b00101011,
	MCP_REG_CANINTF  = 0b00101100,
	MCP_REG_EFLG     = 0b00101101,
	
	MCP_REG_TXB0CTRL = 0b00110000,
	MCP_REG_TXB0SIDH = 0b00110001,
	MCP_REG_TXB0SIDL = 0b00110010,
	MCP_REG_TXB0DLC  = 0b00110101,
	MCP_REG_TXB0D0   = 0b00110110,
	MCP_REG_TXB0D1   = 0b00110111,
	MCP_REG_TXB0D2   = 0b00111000,
	MCP_REG_TXB0D3   = 0b00111001,
	MCP_REG_TXB0D4   = 0b00111010,
	MCP_REG_TXB0D5   = 0b00111011,
	MCP_REG_TXB0D6   = 0b00111100,
	MCP_REG_TXB0D7   = 0b00111101,
	
	MCP_REG_RXB0CTRL = 0b01100000,
	MCP_REG_RXB0SIDH = 0b01100001,
	MCP_REG_RXB0SIDL = 0b01100010,
	MCP_REG_RXB0EID8 = 0b01100011,
	MCP_REG_RXB0EID0 = 0b01100100,
	MCP_REG_RXB0DLC  = 0b01100101,
	MCP_REG_RXB0D0   = 0b01100110,
	MCP_REG_RXB0D1   = 0b01100111,
	MCP_REG_RXB0D2   = 0b01101000,
	MCP_REG_RXB0D3   = 0b01101001,
	MCP_REG_RXB0D4   = 0b01101010,
	MCP_REG_RXB0D5   = 0b01101011,
	MCP_REG_RXB0D6   = 0b01101100,
	MCP_REG_RXB0D7   = 0b01101101,
	
	MCP_REG_RXB1CTRL = 0b01110000,
	MCP_REG_RXB1SIDH = 0b01110001,
	MCP_REG_RXB1SIDL = 0b01110010,
	MCP_REG_RXB1EID8 = 0b01110011,
	MCP_REG_RXB1EID0 = 0b01110100,
	MCP_REG_RXB1DLC  = 0b01110101,
	MCP_REG_RXB1D0   = 0b01110110,
	MCP_REG_RXB1D1   = 0b01110111,
	MCP_REG_RXB1D2   = 0b01111000,
	MCP_REG_RXB1D3   = 0b01111001,
	MCP_REG_RXB1D4   = 0b01111010,
	MCP_REG_RXB1D5   = 0b01111011,
	MCP_REG_RXB1D6   = 0b01111100,
	MCP_REG_RXB1D7   = 0b01111101,
	
	MCP_REG_CANSTAT  = 0b11111110,
	MCP_REG_CANCTRL  = 0b11111111,
	
	MCP_CANINTF_MERRF = (1 << 7),
	MCP_CANINTF_WAKIF = (1 << 6),
	MCP_CANINTF_ERRIF = (1 << 5),
	MCP_CANINTF_TX2IF = (1 << 4),
	MCP_CANINTF_TX1IF = (1 << 3),
	MCP_CANINTF_TX0IF = (1 << 2),
	MCP_CANINTF_RX1IF = (1 << 1),
	MCP_CANINTF_RX0IF = (1 << 0),
};


void mcp2515_init(void);

void mcp2515_setup_bit_timings(uint8_t sjw, uint8_t brp, uint8_t prop,
	uint8_t ps1, uint8_t ps2);

void mcp2515_mode(uint8_t mode);

void mcp2515_cmd_reset(void);

uint8_t mcp2515_cmd_status(void);
uint8_t mcp2515_cmd_rx_status(void);

void mcp2515_cmd_rts(uint8_t mask);

uint8_t mcp2515_cmd_read(uint8_t addr);
void mcp2515_cmd_write(uint8_t addr, uint8_t data);
void mcp2515_cmd_modify(uint8_t addr, uint8_t mask, uint8_t data);

void mcp2515_cmd_read_many(uint8_t addr, uint8_t len, uint8_t data[static len]);
void mcp2515_cmd_write_many(uint8_t addr, uint8_t len,
	const uint8_t data[static len]);

void mcp2515_cmd_read_rx_buf(uint8_t start, uint8_t len,
	uint8_t data[static len]);
void mcp2515_cmd_load_tx_buf(uint8_t start, uint8_t len,
	const uint8_t data[static len]);


#endif