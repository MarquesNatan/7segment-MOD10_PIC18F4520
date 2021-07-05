/*============================================================================*/
#include "display_7_seg_map.h"
/*============================================================================*/
// Fun��o para configura��o do PORTB como sa�da
void Display_Config(void){
    
    OUTPUT_DISPLAY_CONFIG(DISPLAY_PORT) = 0x00000000; // PORTB = 0x00000000
}

/*============================================================================*/
// Configura��o para atualizar os dados do display
uint8_t display_show(display_7_seg_t *displayShow)
{
    
    // Verifica qual a posi��o atual, se n�o for a ultima mostra no display
    if(displayShow->characters_vector_pos < characters_vector_length - 1){
        
        DISPLAY_SHOW_PORT(DISPLAY_PORT) = displayShow->characters_vector[displayShow->characters_vector_pos];
        displayShow->characters_vector_pos++;
        
      }else { // Caso seja a ultima posi��o mostra no display e zera o contador
        
        DISPLAY_SHOW_PORT(DISPLAY_PORT) = displayShow->characters_vector[characters_vector_length - 1];
        displayShow->characters_vector_pos = 0x00;
        
      }   
    
    
    return displayShow->characters_vector_pos;
}
/*============================================================================*/