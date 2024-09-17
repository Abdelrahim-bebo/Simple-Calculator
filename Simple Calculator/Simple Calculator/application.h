/* 
 * File:   application.h
 * Author: Abdelrahim Bebo
 *
 * Created on September 17, 2024, 2:07 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/*Section : MACRO DECLARATIONS*/
#define _XTAL_FREQ 8000000
typedef unsigned char   uint8_t;


/*Section : INCLUDES*/
#include "ECU_layer/LCD/ecu_lcd.h"
#include "ECU_layer/keypad/ecu_key_pad.h"
#include "Mcal_layer/GPIO/hal_gpio.h"
/*Section : MACRO FUNCTIONS DECLARATIONS*/

/*Section : DATATYPES DECLARATIONS*/

keypad_t key_pad = {
    .keypad_column_pins[0].port = PORTD_INDEX,
    .keypad_column_pins[0].pin = PIN4,
    .keypad_column_pins[0].direction = INPUT,
    .keypad_column_pins[0].logic = LOW,
    
    .keypad_column_pins[1].port = PORTD_INDEX,
    .keypad_column_pins[1].pin = PIN5,
    .keypad_column_pins[1].direction = INPUT,
    .keypad_column_pins[1].logic = LOW,
    
    .keypad_column_pins[2].port = PORTD_INDEX,
    .keypad_column_pins[2].pin = PIN6,
    .keypad_column_pins[2].direction = INPUT,
    .keypad_column_pins[2].logic = LOW,
    
    .keypad_column_pins[3].port = PORTD_INDEX,
    .keypad_column_pins[3].pin = PIN7,
    .keypad_column_pins[3].direction = INPUT,
    .keypad_column_pins[3].logic = LOW,
    
    .keypad_row_pins[0].port = PORTD_INDEX,
    .keypad_row_pins[0].pin = PIN0,
    .keypad_row_pins[0].direction = OUTPUT,
    .keypad_row_pins[0].logic = LOW,
    
    .keypad_row_pins[1].port = PORTD_INDEX,
    .keypad_row_pins[1].pin = PIN1,
    .keypad_row_pins[1].direction = OUTPUT,
    .keypad_row_pins[1].logic = LOW,
    
    .keypad_row_pins[2].port = PORTD_INDEX,
    .keypad_row_pins[2].pin = PIN2,
    .keypad_row_pins[2].direction = OUTPUT,
    .keypad_row_pins[2].logic = LOW,
    
    .keypad_row_pins[3].port = PORTD_INDEX,
    .keypad_row_pins[3].pin = PIN3,
    .keypad_row_pins[3].direction = OUTPUT,
    .keypad_row_pins[3].logic = LOW
};


lcd_8bit_t lcd_2 ={
    .lcd_rs.port=PORTB_INDEX,
    .lcd_rs.pin=PIN0,
    .lcd_rs.direction=OUTPUT,
    .lcd_rs.logic=LOW,
    .lcd_en.port=PORTB_INDEX,
    .lcd_en.pin=PIN1,
    .lcd_en.direction=OUTPUT,
    .lcd_en.logic=LOW,
    .lcd_data[0].port=PORTC_INDEX,
    .lcd_data[0].pin=PIN0,
    .lcd_data[0].direction=OUTPUT,
    .lcd_data[0].logic=LOW,
    .lcd_data[1].port=PORTC_INDEX,
    .lcd_data[1].pin=PIN1,
    .lcd_data[1].direction=OUTPUT,
    .lcd_data[1].logic=LOW,
    .lcd_data[2].port=PORTC_INDEX,
    .lcd_data[2].pin=PIN2,
    .lcd_data[2].direction=OUTPUT,
    .lcd_data[2].logic=LOW,
    .lcd_data[3].port=PORTC_INDEX,
    .lcd_data[3].pin=PIN3,
    .lcd_data[3].direction=OUTPUT,
    .lcd_data[3].logic=LOW,
    .lcd_data[4].port=PORTC_INDEX,
    .lcd_data[4].pin=PIN4,
    .lcd_data[4].direction=OUTPUT,
    .lcd_data[4].logic=LOW,
    .lcd_data[5].port=PORTC_INDEX,
    .lcd_data[5].pin=PIN5,
    .lcd_data[5].direction=OUTPUT,
    .lcd_data[5].logic=LOW,
    .lcd_data[6].port=PORTC_INDEX,
    .lcd_data[6].pin=PIN6,
    .lcd_data[6].direction=OUTPUT,
    .lcd_data[6].logic=LOW,
    .lcd_data[7].port=PORTC_INDEX,
    .lcd_data[7].pin=PIN7,
    .lcd_data[7].direction=OUTPUT,
    .lcd_data[7].logic=LOW
};


/*Section : FUNCTIONS DECLARATIONS*/
void application_initialize (void);
void Add_operation(void);
void Sub_operation(void);
void Mult_operation(void);
void Div_operation(void);

#endif	/* APPLICATION_H */