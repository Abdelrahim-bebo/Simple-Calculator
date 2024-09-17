/* 
 * File:   application.h
 * Author: Abdelrahim Bebo
 *
 * Created on September 17, 2024, 2:07 AM
 */

#include "application.h"

uint8 value = 0 ;
uint8 num1_digit1,num2_digit1;
uint8 num1_digit2,num2_digit2;
uint8 operator;
uint8 assignment_operator;
uint8 off;
sint32 result;
sint32 str[];
std_returntype ret = E_NOT_OK;

int main() { 
    application_initialize();
		
    while(1){
       ret = lcd_8bit_send_command(&lcd_2 , _LCD_CURSOR_OFF_DISPLAY_ON);
        do{
        num1_digit1 = 0;
        ret = keypad_get_value(&key_pad , &num1_digit1);
        
        }while(num1_digit1 == 0);
        __delay_ms(250);
        ret = lcd_8bit_send_char_data_pos(&lcd_2,1,1,num1_digit1);
        __delay_ms(250);
        do{
        ret = keypad_get_value(&key_pad , &num1_digit2);
        
        }while(num1_digit2 == 0);
        __delay_ms(250);
        ret = lcd_8bit_send_char_data_pos(&lcd_2,1,2,num1_digit2);
        __delay_ms(250);
         do{
        
        ret = keypad_get_value(&key_pad , &operator);
        
        }while(operator == 0);
        __delay_ms(250);
        ret = lcd_8bit_send_char_data_pos(&lcd_2,1,4,operator);
        __delay_ms(250);
         do{
        ret = keypad_get_value(&key_pad , &num2_digit1);
        }while(num2_digit1 == 0);
        __delay_ms(250);
        ret = lcd_8bit_send_char_data_pos(&lcd_2,1,6,num2_digit1);
        __delay_ms(250);
        do{
        ret = keypad_get_value(&key_pad , &num2_digit2);
        }while(num2_digit2 == 0);
        __delay_ms(250);
        ret = lcd_8bit_send_char_data_pos(&lcd_2,1,7,num2_digit2);
        __delay_ms(250);
        do{
        ret = keypad_get_value(&key_pad , &assignment_operator);
        }while(assignment_operator == 0);
        __delay_ms(250);
        ret = lcd_8bit_send_char_data_pos(&lcd_2,1,9,assignment_operator);
        switch(operator){
            case '+' :
                Add_operation();
                break;
            case '-' :
                Sub_operation();
                break;
            case '*' :
                Mult_operation();
                break;
            case '/' :
                Div_operation();
                break;
            default :
                break;

        }
         do{
        ret = keypad_get_value(&key_pad , &off);
        }while(off == 0);
        __delay_ms(250);
        lcd_8bit_send_command(&lcd_2,_LCD_CLEAR);
            num1_digit1 =0;
            num1_digit2 =0;
            num2_digit1 =0;
            num2_digit2 =0;
            operator =0;
            assignment_operator =0;
            off =0;
    }
    return (EXIT_SUCCESS);
}

void application_initialize(void){
    std_returntype ret = E_NOT_OK;
     ret = lcd_8bit_initialize(&lcd_2);
     ret = keypad_initialize(&key_pad);
}

void Add_operation(void){
    uint8 num1,num2;
    num1= (num1_digit2-48)+10*(num1_digit1-48);
    num2 = (num2_digit2-48)+10*(num2_digit1-48);
   result = num1 + num2;  
   ret = convert_int_to_string(result , str);
   ret = lcd_8bit_send_string_pos(&lcd_2,1,11,str);
}

void Sub_operation(void){
    uint8 num1,num2;
    num1= (num1_digit2-48)+10*(num1_digit1-48);
    num2 = (num2_digit2-48)+10*(num2_digit1-48);
   result = num1 - num2;  
   ret = convert_int_to_string(result , str);
   ret = lcd_8bit_send_string_pos(&lcd_2,1,11,str);
}

void Mult_operation(void){
    uint8 num1,num2;
    num1= (num1_digit2-48)+10*(num1_digit1-48);
    num2 = (num2_digit2-48)+10*(num2_digit1-48);
    result = num1 * num2;  
   ret = convert_int_to_string(result , str);
   ret = lcd_8bit_send_string_pos(&lcd_2,1,11,str);
}

void Div_operation(void){
    uint8 num1,num2;
    num1= (num1_digit2-48)+10*(num1_digit1-48);
    num2 = (num2_digit2-48)+10*(num2_digit1-48);
    result = num1 / num2;  
   ret = convert_int_to_string(result , str);
   ret = lcd_8bit_send_string_pos(&lcd_2,1,11,str);
}


