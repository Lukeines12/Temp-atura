#include <stdio.h>
#include <stdlib.h>     // rand() e srand()
#include <time.h>       // time()
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


void app_main(void)
{
  gpio_set_direction (2,GPIO_MODE_OUTPUT);
    // Inicializa a semente do gerador
    srand((unsigned int) time(NULL));

    while (1)
    {
        // Intervalo desejado
        int min = 0;
        int max = 100;
        int t > 40;

        // Fórmula para intervalo personalizado
        int numero = (rand() % (max - min + 1)) + min;

        printf("Temperatura: %d°\n", numero);
        if (numero>=40) printf ("Ta quentinho \n");
         if (numero<=39) printf("Cabo o frio \n");
         if (numero>=40) gpio_set_level (2,1);
         if (numero<=39) gpio_set_level (2,0);

         int t (numero>=40) = (t++);

         while (t > 0) {
printf("Contagem Regressiva: %d\n", t);
    t--; //resultado = resultado -1

    if (t < 0) gpio_set_level (2,1);
    if (t == 0) printf ("Explodiu \n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
