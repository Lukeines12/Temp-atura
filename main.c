#include <stdio.h>
#include <stdlib.h>     // rand() e srand()
#include <time.h>       // time()
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

int t = 10;

void app_main(void)
{
  gpio_set_direction(2,GPIO_MODE_OUTPUT);

    // Inicializa a semente do gerador
    srand((unsigned int) time(NULL));

    vTaskDelay(1000 / portTICK_PERIOD_MS);

   for(t=5; t>=0; t--)
  {
    printf("%d\n",t);
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }


     while (50)
    {
        // Intervalo desejado
        int min = 0;
        int max = 10;

        // Fórmula para intervalo personalizado
        int numero = (rand() % (max - min + 1)) + min;
        printf("Número aleatório entre 0 e 100: %d\n", numero);
        if (numero>7)  gpio_set_level(2,1);
        if (numero<5)  gpio_set_level(2,0);
        vTaskDelay(pdMS_TO_TICKS(3000));

        
    }
}
