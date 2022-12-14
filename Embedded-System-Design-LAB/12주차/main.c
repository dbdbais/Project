#include "stm32f10x.h"
#include "core_cm3.h"
#include "misc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_adc.h"
#include "lcd.h"

int color[12] = 
{WHITE,CYAN,BLUE,RED,MAGENTA,LGRAY,GREEN,YELLOW,BROWN,BRRED,GRAY};

volatile uint32_t ADC_Value[1];

void RCC_Configure(void){
    // ADC port clock Enable
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    // DMA clock Enable
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
}

void GPIO_Configure(void){
    GPIO_InitTypeDef  GPIO_InitStructure;
  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void DMA_Configure(void){
    DMA_InitTypeDef DMA_Instructure;
    
    DMA_DeInit(DMA1_Channel1);
    DMA_Instructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
    DMA_Instructure.DMA_MemoryBaseAddr = (uint32_t)&ADC_Value[0];
    DMA_Instructure.DMA_Mode = DMA_Mode_Circular;
    DMA_Instructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_Instructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_Instructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
    DMA_Instructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_Instructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
    DMA_Instructure.DMA_Priority = DMA_Priority_VeryHigh; 
    DMA_Instructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Instructure.DMA_BufferSize = 1;
    
    DMA_Init(DMA1_Channel1, &DMA_Instructure);
    DMA_Cmd(DMA1_Channel1, ENABLE);
}

void ADC_Configure(void){
    ADC_InitTypeDef  ADC_InitStructure;
    
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_Mode =  ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; 
    
    ADC_Init(ADC1, &ADC_InitStructure);
    
    ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_239Cycles5);
    ADC_DMACmd(ADC1, ENABLE);
    ADC_Cmd(ADC1, ENABLE);
    ADC_ResetCalibration(ADC1);
    while(ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1);
    while(ADC_GetCalibrationStatus(ADC1));
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

void delay(){
  int i;
  for(i = 0; i < 10000000; i++){}
}

int main() {
  SystemInit();
  RCC_Configure();
  GPIO_Configure();
  ADC_Configure();
  DMA_Configure();
  
  //LCD ------------------------------------

  LCD_Init();

  while(1){
    if(ADC_Value[0] >= 1000){
      LCD_Clear(WHITE);
      LCD_ShowNum(0, 60, ADC_Value[0], 4, BLACK, WHITE);
    }
    else{
      LCD_Clear(GRAY);
      LCD_ShowNum(0, 60, ADC_Value[0], 4, WHITE, GRAY);
    }
    delay();
  }
}